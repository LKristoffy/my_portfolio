# 🧵 Thread-Safe Queue in C++ with Concurrency Features

An experimental project implementing a thread-safe queue in C++, showcasing multithreading, synchronization, and concurrent operations like reversing, printing, and removing elements from the queue.

## 📋 Table of Contents

- [Introduction](#-introduction)
- [Features](#-features)
- [Setup Instructions](#-setup-instructions)
- [Implementation Details](#-implementation-details)
- [Usage](#-usage)
- [Future Enhancements](#-future-enhancements)
- [License](#-license)

## 📖 Introduction

This project demonstrates the principles of thread-safe programming in C++ using a custom `LockingQueue` class. The implementation includes synchronization mechanisms to ensure data integrity across multiple threads. Threads perform various operations, such as reversing the queue, printing its contents, and removing random elements, all while maintaining thread safety.

## ✨ Features

- **Thread-Safe Queue:**
  - Implements a queue with synchronized operations using `std::mutex` and `std::unique_lock`.
- **Concurrency:**
  - Multiple threads perform operations on the queue simultaneously without data races.
- **Random Item Removal:**
  - Demonstrates the removal of random elements in a safe manner.
- **Queue Reversal:**
  - Implements a thread-safe method to reverse the order of elements in the queue.
- **Thread Synchronization:**
  - Uses condition variables to handle thread notifications and ensure smooth operation.

## ⚙️ Setup Instructions

### Prerequisites

- C++11 or later
- GCC or any modern C++ compiler

### Compilation

1. Clone the repository or download the source file `concurrency_experiment.cc`.
2. Open a terminal and navigate to the directory containing the file.
3. Compile the program using the following command:

   ```bash
   g++ -Wall --std=c++11 concurrency_experiment.cc -o concurrency_experiment```
   
### Execution

Run the compiled program with:


`./concurrency_experiment`

## 💻 Implementation Details

1. **`LockingQueue` Class**:

- A custom thread-safe queue that supports operations such as:
  - Adding elements (`push_back`)
  - Removing random elements (`remove_random`)
  - Printing queue contents (`print`)
  - Reversing the queue (`reverse`)
- Utilizes `std::mutex` for mutual exclusion and `std::condition_variable` for thread synchronization.
  
2. **Multithreading**:

- Three threads perform the following tasks concurrently:
  - Reverse the queue.
  - Print queue contents.
  - Remove random elements.
3. **Exception Handling**:

- Robust exception handling for queue operations.
4. **Random Number Generation**:

- Uses `std::random_device` and `std::mt19937` for generating random values.
## 🚀 Usage
- On execution, the program:
  - Populates the queue with 55 random items.
  - Spawns three threads to manipulate the queue concurrently.
  - Logs operations to the console for observation.
Example output:

```
Queue Contents: [Item1, Item2, ..., Item55]
Reversing queue...
Randomly removing an item...
Queue Contents: [Item54, Item53, ..., Item1]
```

## 🛠️ Future Enhancements

1. **Performance Optimization**:
Implement a lock-free queue using atomic operations for improved concurrency.
2. **Custom Thread Pools**:
Use thread pools for better thread management and scalability.
3. **Advanced Operations**:
Add support for priority-based queue operations.
4. **Testing Framework**:
Integrate unit testing for verifying queue operations.
## 📄 License
This project is licensed under the MIT License. See the LICENSE file for more details.






