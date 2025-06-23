# Problem Statement: Playlist Manager

## Objective:
Design and implement a Playlist Manager application in C++ that allows a user to manage and interact with a music playlist. Students will apply object-oriented programming, dynamic memory management, and linear data structures (linked list, stack, and queue) to build this system from scratch.

## Problem Description:
Students are tasked with building a console-based music playlist manager. The application should allow users to:
- Add songs to a playlist (no duplicates)  
- Delete a song by title  
- Skip to the next or previous song in the playlist  
- Backtrack to the most recently played song  
- Queue songs to play next  
- Play song  
- View the current song and the full playlist  

*(A template with function stubs and a main program, Input and Output text files are provided to help guide students as they implement the Playlist Manager lab.)*

This lab helps students apply key programming concepts in a practical, engaging way by building a playlist system using object-oriented programming (OOP) and linear data structures.

---

### 1. Object-Oriented Programming (OOP):
Students create two main classes: `Song` and `PlaylistManager`. The `Song` class represents a track with a title and links to the previous and next songs in the list. The `PlaylistManager` class controls the playlist—adding, deleting, and playing songs—while keeping its data members private to enforce encapsulation.

### 2. Dynamic Memory and Pointers:
Students dynamically allocate memory for songs using `new` and must manage that memory carefully using `delete`. They work with raw pointers (`Song*`) to navigate and manipulate the linked list, reinforcing pointer skills and safe memory handling.

### 3. Doubly Linked List:
The playlist itself is a doubly linked list. Students practice common operations like inserting songs at the end, deleting songs from any position, and traversing forward and backward through the list. This builds a strong foundation in non-contiguous memory structures and pointer-based navigation.

### 4. Stack (LIFO Behavior):
A C++ stack is used to keep track of recently played songs. When a song is skipped, it's pushed onto the stack. Students use `stack.top()` and `stack.pop()` to implement a backtracking feature—demonstrating how LIFO behavior supports "undo" actions.

### 5. Queue (FIFO Behavior):
A queue stores upcoming songs. Songs are added to the back and played from the front, modeling first-in, first-out behavior. This mirrors real-world scenarios like playlist ordering or job scheduling.

---

The Playlist Manager lab gives students a fun and practical way to learn important programming skills. By building a simple music player, students get to practice how to use classes, work with pointers, and manage memory in C++. They also learn how stacks, queues, and linked lists work by using them in a real-world setting. This project helps make abstract ideas more concrete and gives students the confidence to build more complex programs in the future.

---

## Question:
**When a user chooses to delete the current song from the playlist, explain in detail how you would safely handle this deletion, considering that the current song could be located at the head, tail, or middle of the doubly linked list.**

In your explanation, describe:
- How you would update the pointers (prev and next) of neighboring songs to maintain the integrity of the linked list.  
- How you would update the current pointer to ensure the playlist continues smoothly (e.g., moving to the next or previous song).  
- How you would remove or update any references to the deleted song in the recently played stack and upcoming queue to avoid dangling pointers or invalid memory access.  
- The steps needed to safely deallocate the deleted song’s memory and avoid memory leaks.
