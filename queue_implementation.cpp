#include <iostream>
#include <chrono>
#include <iomanip>

// Node class for doubly linked list
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    // Constructor
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

// Queue implementation using Doubly Linked List
class Queue {
private:
    Node* front;  // Points to the front of the queue (dequeue from here)
    Node* rear;   // Points to the rear of the queue (enqueue here)
    int size;     // Track the size of the queue

public:
    // Constructor - Create an empty queue
    // Time Complexity: O(1)
    Queue() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    // Destructor - Free all allocated memory
    // Time Complexity: O(n) where n is the number of elements in the queue
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Check if queue is empty
    // Time Complexity: O(1)
    bool isEmpty() {
        return front == nullptr;
    }

    // Get current size of queue
    // Time Complexity: O(1)
    int getSize() {
        return size;
    }

    // Display all elements in the queue from front to rear
    // Time Complexity: O(n) where n is the number of elements in the queue
    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }

        std::cout << "Queue elements: ";
        Node* current = front;
        while (current != nullptr) {
            std::cout << current->data;
            if (current->next != nullptr) {
                std::cout << " <- ";
            }
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Insert an element at the rear of the queue (enqueue operation)
    // Time Complexity: O(1)
    void enqueue(int value) {
        Node* newNode = new Node(value);

        // If queue is empty, the new node becomes both front and rear
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            // Add the new node at the rear
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        size++;
    }

    // Remove an element from the front of the queue (dequeue operation)
    // Time Complexity: O(1)
    int dequeue() {
        if (isEmpty()) {
            std::cout << "Error: Queue underflow" << std::endl;
            return -1; // Return a sentinel value to indicate error
        }

        Node* temp = front;
        int value = temp->data;

        // If there's only one node in the queue
        if (front == rear) {
            front = nullptr;
            rear = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
        }

        delete temp;
        size--;
        return value;
    }

    // Search for a value in the queue
    // Time Complexity: O(n) where n is the number of elements in the queue
    bool search(int value) {
        Node* current = front;
        int position = 0;

        while (current != nullptr) {
            if (current->data == value) {
                std::cout << "Element " << value << " found at position " << position << std::endl;
                return true;
            }
            current = current->next;
            position++;
        }

        std::cout << "Element " << value << " not found in the queue" << std::endl;
        return false;
    }

    // Sort the queue in ascending order using bubble sort
    // Time Complexity: O(n²) where n is the number of elements in the queue
    void sort() {
        if (isEmpty() || size == 1) {
            return;  // Already sorted
        }

        bool swapped;
        Node* current;
        Node* last = nullptr;

        do {
            swapped = false;
            current = front;

            while (current->next != last) {
                if (current->data > current->next->data) {
                    // Swap data values (not the nodes themselves)
                    int temp = current->data;
                    current->data = current->next->data;
                    current->next->data = temp;
                    swapped = true;
                }
                current = current->next;
            }
            last = current;
        } while (swapped);
    }

    // Merge another queue into this one
    // Time Complexity: O(m) where m is the size of the other queue
    void merge(Queue& otherQueue) {
        if (otherQueue.isEmpty()) {
            return;  // Nothing to merge
        }

        // If this queue is empty, just copy the other queue
        if (isEmpty()) {
            Node* current = otherQueue.front;
            while (current != nullptr) {
                enqueue(current->data);
                current = current->next;
            }
        } else {
            // Connect the rear of this queue to the front of the other queue
            Node* current = otherQueue.front;
            while (current != nullptr) {
                enqueue(current->data);
                current = current->next;
            }
        }

        // Clear the other queue
        while (!otherQueue.isEmpty()) {
            otherQueue.dequeue();
        }
    }
};

// Utility function to measure execution time of a function
template<typename Func>
double measureTime(Func func) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> duration = end - start;
    return duration.count();
}

int main() {
    std::cout << "Queue Implementation using Doubly Linked List" << std::endl;
    std::cout << "=============================================" << std::endl;

    Queue q1;

    // Test enqueue operation
    std::cout << "\n1. Enqueue Operation:" << std::endl;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    q1.display();

    // Test dequeue operation
    std::cout << "\n2. Dequeue Operation:" << std::endl;
    std::cout << "Dequeued element: " << q1.dequeue() << std::endl;
    q1.display();
    std::cout << "Dequeued element: " << q1.dequeue() << std::endl;
    q1.display();

    // Test search operation
    std::cout << "\n3. Search Operation:" << std::endl;
    q1.search(30);  // Existing element
    q1.search(10);  // Removed element

    // Test sort operation
    std::cout << "\n4. Sort Operation:" << std::endl;
    std::cout << "Before sorting: ";
    q1.display();
    
    q1.sort();
    
    std::cout << "After sorting: ";
    q1.display();

    // Test merge operation
    std::cout << "\n5. Merge Operation:" << std::endl;
    Queue q2;
    q2.enqueue(5);
    q2.enqueue(15);
    q2.enqueue(25);
    
    std::cout << "First queue: ";
    q1.display();
    std::cout << "Second queue: ";
    q2.display();
    
    q1.merge(q2);
    
    std::cout << "After merging: ";
    q1.display();
    std::cout << "Second queue after merging: ";
    q2.display();

    // Time complexity analysis
    std::cout << "\n6. Time Complexity Analysis:" << std::endl;
    std::cout << std::setw(30) << std::left << "Operation" 
              << std::setw(20) << "Execution Time (μs)" 
              << "Theoretical Complexity" << std::endl;
    std::cout << std::string(70, '-') << std::endl;

    // Test enqueue (O(1))
    Queue testQueue;
    double enqueueTime = measureTime([&testQueue]() {
        testQueue.enqueue(100);
    });
    std::cout << std::setw(30) << std::left << "Enqueue" 
              << std::setw(20) << enqueueTime 
              << "O(1)" << std::endl;

    // Test dequeue (O(1))
    double dequeueTime = measureTime([&testQueue]() {
        testQueue.dequeue();
    });
    std::cout << std::setw(30) << std::left << "Dequeue" 
              << std::setw(20) << dequeueTime 
              << "O(1)" << std::endl;

    // Test search (O(n))
    Queue searchQueue;
    for (int i = 0; i < 1000; i++) {
        searchQueue.enqueue(i);
    }
    double searchTime = measureTime([&searchQueue]() {
        searchQueue.search(999); // Worst case
    });
    std::cout << std::setw(30) << std::left << "Search (1000 elements)" 
              << std::setw(20) << searchTime 
              << "O(n)" << std::endl;

    // Test sort (O(n²))
    Queue sortQueue;
    for (int i = 1000; i > 0; i--) {
        sortQueue.enqueue(i);
    }
    double sortTime = measureTime([&sortQueue]() {
        sortQueue.sort();
    });
    std::cout << std::setw(30) << std::left << "Sort (1000 elements)" 
              << std::setw(20) << sortTime 
              << "O(n²)" << std::endl;

    // Test merge (O(m))
    Queue mergeQueue1;
    Queue mergeQueue2;
    for (int i = 0; i < 1000; i++) {
        mergeQueue2.enqueue(i);
    }
    double mergeTime = measureTime([&mergeQueue1, &mergeQueue2]() {
        mergeQueue1.merge(mergeQueue2);
    });
    std::cout << std::setw(30) << std::left << "Merge (1000 elements)" 
              << std::setw(20) << mergeTime 
              << "O(m)" << std::endl;
    
    return 0;
}
