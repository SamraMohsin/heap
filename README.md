# MinHeap Implementation (C++)

## Overview

This project implements a *MinHeap* (a binary heap where the root node is the smallest element) in C++. A MinHeap is a complete binary tree where each parent node is less than or equal to its child nodes. It supports efficient insertion, deletion, and extraction of the minimum element.

This implementation includes the following operations:
- Insertion of a new key.
- Decreasing the value of a key.
- Extracting the minimum element.
- Deleting a key.
- Retrieving the minimum element.
- Heapify operation to maintain the heap property.

## Features

- *InsertKey(int k)*: Inserts a new key into the heap while maintaining the MinHeap property.
- *DecreaseKey(int i, int new_val)*: Decreases the value of a key at index i to new_val and re-adjusts the heap.
- *ExtractMin()*: Extracts and returns the minimum element (root) from the heap, adjusting the heap accordingly.
- *DeleteKey(int i)*: Deletes the key at index i by decreasing it to a very low value and then extracting it.
- *GetMin()*: Returns the minimum element (root) of the heap.
- *MinHeapify(int i)*: Ensures the heap property is maintained for the subtree rooted at index i.

## Requirements

- *Programming Language*: C++
- *Compiler*: GCC, Clang, Visual Studio, or any standard C++ compiler
- *Platform*: Cross-platform (Windows, Linux, MacOS)
- *Libraries*: Standard C++ libraries (No external libraries required)

## Installation

1. *Clone the Repository*

   Clone the repository to your local machine:

   ```bash
   git clone https://github.com/SamraMohsin/minheap-cpp.git 
