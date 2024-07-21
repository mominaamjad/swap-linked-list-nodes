<a id="readme-top"></a>

<div align="center">

  <h1>Swap Linked List Nodes</h1>

  <p align="center">
   code to execute swapping of any two nodes
    <br />

  </p>
</div>

# About

This menu-driven C++ program implements a singly linked list with the functionality to swap any two nodes, add nodes at the end, and delete nodes from the end.

## Features

- **Insert Value at End**: Adds a new node with the given value at the end of the list.
- **Delete Value from End**: Deletes the node at the end of the list.
- **Swap Nodes**: Swaps the mth node from the start with the nth node from the end.
- **Display Values**: Displays all the values in the list.

## Code Overview

- **node**: A structure representing a node in the linked list.
  ```cpp
  struct node {
      int id;
      node* next = NULL;
  };
- **LinkedList**: A class containing methods to manipulate the linked list.

* `insertEnd(int x)`: Inserts a node at the end of the list.
* `deleteEnd()`: Deletes the node at the end of the list.
* `swapNodes(int m, int n)`: Swaps the mth node from the start with the nth node from the end.
* `display()`: Displays all nodes in the list.

