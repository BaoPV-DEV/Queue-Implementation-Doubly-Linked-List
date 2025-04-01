# Queue Implementation using Doubly Linked List

This project implements a Queue data structure using a Doubly Linked List in C++. The implementation includes operations such as create, display, insertion (enqueue), deletion (dequeue), searching, sorting, and merging, along with time complexity analysis for each operation.

## Time Complexity Analysis

| Operation | Time Complexity | Explanation |
|-----------|-----------------|-------------|
| Create (Constructor) | O(1) | Initializing pointers and variables is constant time |
| Display | O(n) | We need to traverse all n elements in the queue to display them |
| Enqueue | O(1) | Adding an element at the rear is constant time because we maintain a rear pointer |
| Dequeue | O(1) | Removing an element from the front is constant time because we maintain a front pointer |
| Search | O(n) | In the worst case, we need to traverse all n elements to find the target element |
| Sort | O(n²) | Using bubble sort which has quadratic time complexity |
| Merge | O(m) | Where m is the size of the other queue, as we need to enqueue each element from the other queue |
| isEmpty | O(1) | Just checking if the front pointer is null takes constant time |
| getSize | O(1) | We maintain a size variable that we return in constant time |

## Features

1. **Create Queue**: Initialize an empty queue
2. **Enqueue Operation**: Add elements to the rear of the queue
3. **Dequeue Operation**: Remove elements from the front of the queue
4. **Display**: Show all elements in the queue
5. **Search**: Find an element in the queue and report its position
6. **Sort**: Sort the queue elements in ascending order
7. **Merge**: Combine two queues into one
8. **Edge Case Handling**: Proper handling of empty queues, single element queues, etc.

## Implementation Details

- **Node Structure**: Each node in the doubly linked list contains data, next pointer, and previous pointer
- **Queue Structure**: Maintains front and rear pointers for efficient operations
- **Memory Management**: Proper memory cleanup in the destructor
- **Error Handling**: Checks for queue underflow during dequeue operations

## Compilation and Execution

Compile the code with any standard C++ compiler:

```bash
g++ -o queue_implementation queue_implementation.cpp
./queue_implementation
