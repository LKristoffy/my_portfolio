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





class Item {
public:
    std::string str;
    int num;
};



struct Node{
    //mutex for each node
    std::mutex m;
    // part which will store data
    Item item;
    // pointer to the previous node
    struct Node *prev;
    // pointer to the next node
    struct Node *next;

};

typedef Node *NodePtr;

struct empty_queue : std::exception {
    const char* what() const noexcept override {
        return "Queue is empty";
    }
};


class LockingQueue {
private:
    NodePtr head;
    NodePtr tail;
    int size;
    std::condition_variable condition;
    bool reversed = false;
    std::mutex head_mutex;

public:

    LockingQueue() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    bool isEmpty(){
        return head == nullptr;
    }

    void reverse(){
        std::unique_lock<std::mutex> lock(head_mutex);
        reversed = false;
        lock.unlock();
        condition.notify_all();
        if (isEmpty()) {
            throw empty_queue();
        } else {
            
            int sum = 0;
            NodePtr prevPtr = head;
            

            if (prevPtr->next == nullptr){
                std::unique_lock<std::mutex> prev_lk(prevPtr->m);
                std::cout<<"Sum: " << prevPtr->item.num << std::endl;
                std::unique_lock<std::mutex> lock(head_mutex);
                reversed=true;
                lock.unlock();
                condition.notify_all();
                return;
            }
            std::unique_lock<std::mutex> prev_lk(prevPtr->m, std::defer_lock);
            NodePtr currPtr = prevPtr->next;
            std::unique_lock<std::mutex> curr_lk(currPtr->m, std::defer_lock);
            std::lock(prev_lk, curr_lk);

            NodePtr tempPtr = NULL;
            
            while(currPtr != nullptr){
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

            std::unique_lock<std::mutex> lock(head_mutex);

            sum+=prevPtr->item.num;
            tempPtr = prevPtr->prev;
            prevPtr->prev = prevPtr->next;
            prevPtr->next = tempPtr;
            head = tempPtr->prev;
            std::cout<<"Sum: " << sum << std::endl;

            
            reversed=true;
            
            condition.notify_all();


        }

    }

    Item pop_front(){
        Item item;
        if (isEmpty()) {
            throw empty_queue();
        } else {
            size -= 1;
            std::unique_lock<std::mutex> lock_lhs(head->m, std::defer_lock);
            std::unique_lock<std::mutex> lock_rhs((head->next)->m, std::defer_lock);
            std::lock(lock_lhs, lock_rhs);
            NodePtr nextPtr = head->next;
            if (nextPtr->next != nullptr) {
                nextPtr->prev = nullptr;
            }
            item = head->item;
            // remove head
            delete head;
            // make nextptr head 
            head = nextPtr;
        }

        return item;
    }


    void push_back(Item newItem){
        size+=1;
        NodePtr node = new Node;
        node->item = newItem;
        node->next = nullptr;
        if (isEmpty()) {
            head = node;
            tail = node;
        } else {
            std::unique_lock<std::mutex> lock(tail->m);
            tail->next = node;
            node->prev = tail;
            tail = node;
        }

    }

    void remove(int pos){
        if (isEmpty()){
            throw empty_queue();
        } else {

            std::unique_lock<std::mutex> lock(head_mutex);
            condition.wait(lock, [this]{return reversed;});
            

            size-=1;
            NodePtr prevPtr = head;
            

            if (prevPtr->next==nullptr){
                std::unique_lock<std::mutex> prev_lk(prevPtr->m);
                head=nullptr;
                tail=nullptr;
                prev_lk.unlock();
                delete prevPtr;
                return;
            }

            std::unique_lock<std::mutex> prev_lk(prevPtr->m, std::defer_lock);
            NodePtr nodePtr = prevPtr->next;
            std::unique_lock<std::mutex> node_lk(nodePtr->m, std::defer_lock);
            std::lock(prev_lk, node_lk);
            for (int i = 0; i < pos-1 && prevPtr != nullptr; i++){
                prevPtr = nodePtr;
                if (nodePtr->next!=nullptr) {
                    nodePtr = nodePtr->next;
                    prev_lk.swap(node_lk);
                    node_lk = std::unique_lock<std::mutex>(nodePtr->m);
                }

            }
            
            if (nodePtr->next == nullptr){
                prevPtr->next = nullptr;
            } else {
                NodePtr nextPtr = nodePtr->next;
                std::unique_lock<std::mutex> next_lk(nextPtr->m);
                prevPtr->next = nodePtr->next;
                nextPtr->prev = nodePtr->prev;
  
                
            }


            
            delete nodePtr;

            


        }
    }
    

    void remove_random() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(0, size - 1);
        int random_index = dist(gen);
        remove(random_index);
    }

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

void remove_random_items(LockingQueue& queue) {
    while(!queue.isEmpty()) {
        queue.remove_random();
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}

void print_queue(LockingQueue& queue) {
    while(!queue.isEmpty()) {
        queue.print();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

void reverse_queue(LockingQueue& queue) {
    while(!queue.isEmpty()) {
        queue.reverse();
        std::this_thread::sleep_for(std::chrono::microseconds(100));
    }
}


int main() {
    LockingQueue queue;


    // Populate the queue with items
    populate_queue(queue,55);

    std::thread t1(reverse_queue, std::ref(queue));
    std::thread t2(print_queue, std::ref(queue));
    std::thread t3(remove_random_items, std::ref(queue));


    t1.join();
    t2.join();
    t3.join();
    
 

    return 0;
}







