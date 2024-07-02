#include <iostream>
#include <string>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <exception>
#include <memory>
#include <ctime>
#include <chrono>
#include <random>


// a C++ experiment to play with cocurrence, mutexes, flags
// could be improved with threads waiting less

// Class representing an item in the queue
class Item {
public:
    // Data will consist of a string and number
    std::string str;
    int num;
};



struct Node{
    // Mutex for each node
    std::mutex m;
    // Class which will store data
    Item item;
    // Pointer to the previous node
    struct Node *prev;
    // Pointer to the next node
    struct Node *next;

};

// Alias for a pointer to a Node
typedef Node *NodePtr; 


// Exception to be thrown when the queue is empty
struct empty_queue : std::exception {
    const char* what() const noexcept override {
        return "Queue is empty";
    }
};

// Class for a thread-safe doubly linked list
class LockingQueue {
private:
    NodePtr head; // Pointer to the head of the list
    NodePtr tail; // Pointer to the tail of the list
    int size; // Size of the list
    std::condition_variable condition; // Condition variable for synchronization
    bool reversed = false; // Flag indicating if the list is reversed
    std::mutex head_mutex; // Mutex for the head of the list

public:
    // Constructor to initialize an empty list
    LockingQueue() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // Check if the list is empty
    bool isEmpty(){
        return head == nullptr;
    }

    // Reverse the order of the list
    void reverse(){
        std::unique_lock<std::mutex> lock(head_mutex); // Lock head mutex
        reversed = false; // Set reverse flag to false
        lock.unlock(); // Unlock
        condition.notify_all(); //Notify other threads
        if (isEmpty()) {
            //Nothing to reverse
            throw empty_queue();
        } else {
            

            int sum = 0;
            NodePtr prevPtr = head; //Start at head
            
            // If there is only one node
            if (prevPtr->next == nullptr){
                std::unique_lock<std::mutex> prev_lk(prevPtr->m);
                std::cout<<"Sum: " << prevPtr->item.num << std::endl;
                std::unique_lock<std::mutex> lock(head_mutex);
                reversed=true; // Flag says reversed complete
                lock.unlock();
                condition.notify_all();
                return;
            }

            // lock in hand-over-hand fashion
            std::unique_lock<std::mutex> prev_lk(prevPtr->m, std::defer_lock);
            NodePtr currPtr = prevPtr->next;
            std::unique_lock<std::mutex> curr_lk(currPtr->m, std::defer_lock);
            std::lock(prev_lk, curr_lk);

            NodePtr tempPtr = NULL;
            
            while(currPtr != nullptr){
                // Complete reversing with hand-over-hand, taking sum as we go
                sum+=prevPtr->item.num;
                tempPtr = prevPtr->prev;
                prevPtr->prev = prevPtr->next;
                prevPtr->next = tempPtr;
                prevPtr = prevPtr->prev;
                currPtr = prevPtr->next;
                prev_lk.swap(curr_lk);
                if (currPtr != nullptr) {
                    curr_lk = std::unique_lock<std::mutex>(currPtr->m);
                }
                
            }

            // Reached end of list
            std::unique_lock<std::mutex> lock(head_mutex);

            sum+=prevPtr->item.num;
            tempPtr = prevPtr->prev;
            prevPtr->prev = prevPtr->next;
            prevPtr->next = tempPtr;
            head = tempPtr->prev;
            std::cout<<"Sum: " << sum << std::endl;

            // Set reversed flag to true and notify all
            reversed=true;
            
            condition.notify_all();


        }

    }
    
    // Remove and return the front item of the list
    Item pop_front(){
        Item item;
        if (isEmpty()) {
            //Nothing to pop
            throw empty_queue();
        } else {
            // Lock head
            size -= 1;
            std::unique_lock<std::mutex> lock_lhs(head->m, std::defer_lock);
            std::unique_lock<std::mutex> lock_rhs((head->next)->m, std::defer_lock);
            std::lock(lock_lhs, lock_rhs);

            // Change pointers
            NodePtr nextPtr = head->next;
            if (nextPtr->next != nullptr) {
                nextPtr->prev = nullptr;
            }
            item = head->item;
            // Remove head
            delete head;
            // Make nextptr head 
            head = nextPtr;
        }

        // Return popped data
        return item;
    }

    // Add a new item to the end of the list
    void push_back(Item newItem){
        size+=1;
        //Create node
        NodePtr node = new Node;
        // Set data and next pointer
        node->item = newItem;
        node->next = nullptr;
        if (isEmpty()) {
            // If list empty, node is head and tail
            head = node;
            tail = node;
        } else {
            // Else set tail and new node pointing at each other and make new node tail
            std::unique_lock<std::mutex> lock(tail->m);
            tail->next = node;
            node->prev = tail;
            tail = node;
        }

    }

    // Remove a node at a given position
    void remove(int pos){
        if (isEmpty()){
            // Check if empty
            throw empty_queue();
        } else {
            
            // Lock head and check if list finished reversing
            std::unique_lock<std::mutex> lock(head_mutex);
            condition.wait(lock, [this]{return reversed;});
            
            //Update size and pointer
            size-=1;
            NodePtr prevPtr = head;
            
            // Check if only one node
            if (prevPtr->next==nullptr){
                // Lock and delete
                std::unique_lock<std::mutex> prev_lk(prevPtr->m);
                head=nullptr;
                tail=nullptr;
                prev_lk.unlock();
                delete prevPtr;
                return;
            }

            // Else lock hand-over-hand
            std::unique_lock<std::mutex> prev_lk(prevPtr->m, std::defer_lock);
            NodePtr nodePtr = prevPtr->next;
            std::unique_lock<std::mutex> node_lk(nodePtr->m, std::defer_lock);
            std::lock(prev_lk, node_lk);
            for (int i = 0; i < pos-1 && prevPtr != nullptr; i++){

                // Hand-over-hand traversal...
                prevPtr = nodePtr;
                if (nodePtr->next!=nullptr) {
                    nodePtr = nodePtr->next;
                    prev_lk.swap(node_lk);
                    node_lk = std::unique_lock<std::mutex>(nodePtr->m);
                }

            }
            
            // until at node and either at end or not
            if (nodePtr->next == nullptr){
                prevPtr->next = nullptr;
            } else {
                NodePtr nextPtr = nodePtr->next;
                std::unique_lock<std::mutex> next_lk(nextPtr->m);
                prevPtr->next = nodePtr->next;
                nextPtr->prev = nodePtr->prev;
  
                
            }


            // finally delete
            delete nodePtr;

            


        }
    }
    
    // Helper function to remove a random node from the list using remove method
    void remove_random() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(0, size - 1);
        int random_index = dist(gen);
        remove(random_index);
    }

    // Helper function to print the list contents
    void print(){
        if (isEmpty()){
            throw empty_queue();
        } else {
            std::unique_lock<std::mutex> lock(head_mutex);
            condition.wait(lock, [this]{return reversed;});
            
            NodePtr prevPtr = head;
            

            if (prevPtr->next == nullptr){
                std::unique_lock<std::mutex> prev_lk(prevPtr->m);
                std::cout << "CURRENT QUEUE:" << std::endl;
                std::cout << "0) " << prevPtr->item.str << " " << prevPtr->item.num << std::endl;
                std::cout << "" << std::endl;
                return;
            }

            std::unique_lock<std::mutex> prev_lk(prevPtr->m, std::defer_lock);
            NodePtr currPtr = prevPtr->next;
            std::unique_lock<std::mutex> curr_lk(currPtr->m, std::defer_lock);
            std::lock(prev_lk, curr_lk);

            std::cout << "CURRENT QUEUE:" << std::endl;
            std::cout <<"0) "<< prevPtr->item.str << " " << prevPtr->item.num << std::endl;
            
            for(int i=1; currPtr != nullptr; i++){
                
                std::cout << i << ") " << currPtr->item.str << " " << currPtr->item.num << std::endl;
                prevPtr = currPtr;
                currPtr = currPtr->next;
                prev_lk.swap(curr_lk);

                if (currPtr != nullptr) {
                    curr_lk = std::unique_lock<std::mutex>(currPtr->m);
                }
                
            }

            std::cout << "" << std::endl;
            
        }

        

    }


};

// Helper function to populate the queue with random items
void populate_queue(LockingQueue& queue, int num) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> char_dist('a', 'z');
    std::uniform_int_distribution<> num_dist(0, 255);

    for (int i = 0; i < num; ++i) {
        Item item;
        int str_len = std::uniform_int_distribution<>(2, 5)(gen);
        for (int j = 0; j < str_len; ++j) {
            item.str += char_dist(gen);
        }
        item.num = num_dist(gen);
        queue.push_back(item);
    }
}

// Helper function to remove random items from the queue
void remove_random_items(LockingQueue& queue) {
    while(!queue.isEmpty()) {
        queue.remove_random();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

// Helper function to print the queue
void print_queue(LockingQueue& queue) {
    while(!queue.isEmpty()) {
        queue.print();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

// Helper function to reverse the queue
void reverse_queue(LockingQueue& queue) {
    while(!queue.isEmpty()) {
        queue.reverse();
        std::this_thread::sleep_for(std::chrono::microseconds(100));
    }
}


int main() {
    // Initialise thread safe queue
    LockingQueue queue;


    // Populate the queue with items
    populate_queue(queue,55);

    // Create threads to reverse, print, and remove items from the queue
    std::thread t1(reverse_queue, std::ref(queue));
    std::thread t2(print_queue, std::ref(queue));
    std::thread t3(remove_random_items, std::ref(queue));

    // Wait for threads to finish
    t1.join();
    t2.join();
    t3.join();
    
 

    return 0;
}







