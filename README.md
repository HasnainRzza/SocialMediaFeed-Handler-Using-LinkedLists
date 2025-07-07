# C++ Post Feed Manager

This is a C++ console application that simulates a minimal social media Post Feed System. Each post has a unique ID, text content, and a timestamp. Users can add, view, edit, search, sort, and delete posts. The system maintains posts in a linked list and can display them in both ascending and descending order of timestamps.

---

## Features

- Add a new post with an auto-generated ID and timestamp
- Search posts by text content
- Edit a post by ID (automatically updates timestamp)
- Sort posts by timestamp (oldest to newest)
- Delete a post by ID
- Display posts in:
  - Chronological order (oldest to newest)
  - Reverse order (newest to oldest)

---

## Technologies Used

- C++
- Windows API (`Sleep()` for simulating delays)
- Standard Libraries: `<iostream>`, `<ctime>`, `<cstdlib>`, `<iomanip>`, `<windows.h>`

---

## Key Classes and Methods

### `Post`
A node representing each post in the feed:
- `ID`: Unique identifier
- `text`: Post content
- `TimeStamp`: UNIX timestamp
- `next`: Pointer to the next post

### `Feed`
Manages all posts using a linked list:
- `Add_Post(string)`: Adds a new post
- `search_post(string)`: Returns array of IDs for matching content
- `edit_post(int, string)`: Updates content and timestamp of a post
- `sort_feed()`: Sorts posts in ascending order by timestamp
- `display()`: Prints posts from oldest to newest
- `dec_display()`: Prints posts from newest to oldest
- `delete_a_post(int)`: Deletes a post with the specified ID

---

## Sample Usage

```cpp
list.Add_Post("Hello World");
list.Add_Post("This is a post about C++");
int* ids = list.search_post("C++");
list.edit_post(ids[0], "Updated post text");
list.sort_feed();
list.display();
list.delete_a_post(1234); // Replace with actual ID
```
## How to Run

- Use a C++ compiler that supports **C++11 or above**.
- This program uses `Sleep()` from `<windows.h>` — it is **Windows-only**.

### Compile and Run

```bash
g++ -o postfeed postfeed.cpp
./postfeed

Hello World - 1023 - 2025-07-07 10:34:01
This is a post about C++ - 1088 - 2025-07-07 10:34:02
```
