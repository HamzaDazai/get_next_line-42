Here's a detailed README file for the "Get Next Line" project based on the provided PDF:

---

# Get Next Line

## 📜 Project Overview
The **Get Next Line** project aims to implement a function that reads a line from a file descriptor, making it easier to work with files in C. This project introduces the use of static variables, a crucial concept in C programming.

---

## 🚀 Functionality

### **Mandatory Part**
- Function: `char *get_next_line(int fd);`
- **Purpose**: Reads a line from a given file descriptor (`fd`).
- **Key Features**:
  - Handles standard input and file descriptors.
  - Returns the read line including the newline character (`\n`), except at EOF where no newline exists.
  - Ensures memory safety with proper allocations and deallocations.
  - Adapts to varying buffer sizes (`BUFFER_SIZE`), tested with compiler flags.

### **Bonus Part**
- Manages multiple file descriptors simultaneously.
- Implements the function with only one static variable.

---

## 🛠️ Implementation Details

### **Mandatory Files**
1. `get_next_line.c`: Core function implementation.
2. `get_next_line_utils.c`: Helper functions for the main logic.
3. `get_next_line.h`: Header file containing function prototypes.

### **Bonus Files**
1. `get_next_line_bonus.c`
2. `get_next_line_utils_bonus.c`
3. `get_next_line_bonus.h`

### **External Functions Used**
- `read`
- `malloc`
- `free`

### **Forbidden Functions**
- `lseek`
- Global variables
- Your personal `libft` library

---

## 📋 Compilation and Usage

### **Compilation**
Use the provided `Makefile` with the following rules:
- `make`: Compiles the mandatory files.
- `make bonus`: Compiles the bonus version of the project.
- `make clean/fclean`: Cleans up object files and binary outputs.
- `make re`: Cleans and recompiles the project.

Example compilation:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o get_next_line
```

### **Execution**
```bash
./get_next_line <file>
```

---

## 💡 Key Concepts

### **Static Variables**
- Maintain their value across multiple calls to the function.
- Essential for tracking progress when reading files line-by-line.

### **Buffer Size**
- Defined using the `-D BUFFER_SIZE=n` flag during compilation.
- Test the function with varying buffer sizes (e.g., 1, 42, 9999).

### **File Descriptors**
- Handle regular files, standard input, or other streams efficiently.
- Ensure the function adapts to different file descriptor behaviors.

---

## 🏆 Bonus Part (Detailed)

The bonus section is designed to enhance the functionality of `get_next_line` by introducing advanced features. Let’s break down each requirement with practical examples and in-depth reasoning.

---

### 1. **Using Only One Static Variable**
- **Static Variable**:
  - A static variable retains its value between function calls and is shared across all calls to that function.
  - In this bonus, you must manage all required state (e.g., leftover data from previous reads) using just one static variable. 
  - This means no global variables, arrays, or multiple static variables to track separate states.
  
- **Why It Matters**:
  - The constraint forces you to design your code efficiently. You need to manage memory dynamically, handle edge cases, and ensure the state is preserved correctly for each file descriptor.

- **Implementation Hints**:
  - Store a pointer in the static variable to dynamically allocated memory for managing leftover or partial data after each read.
  - Be mindful of freeing and reallocating memory when switching contexts.

---

### 2. **Managing Multiple File Descriptors (FDs)**
- **What Does It Mean?**:
  - Normally, `get_next_line()` handles only one file descriptor at a time, so it tracks state (e.g., the last read position) for just that FD.
  - With this bonus, the function must handle **multiple FDs simultaneously** without interference.

- **Example**:
  Suppose you’re reading three files:
  ```c
  char *line1 = get_next_line(fd3); // Reads line 1 from fd 3
  char *line2 = get_next_line(fd4); // Reads line 1 from fd 4
  char *line3 = get_next_line(fd5); // Reads line 1 from fd 5
  char *line4 = get_next_line(fd3); // Reads line 2 from fd 3
  ```
  - `fd3`, `fd4`, and `fd5` must maintain independent reading positions.
  - The function must remember the leftover content for **each FD** across calls.
---

### 3. **Organizing Bonus Files**
- To keep the mandatory and bonus parts separate, create:
  - **`get_next_line_bonus.c`**:
    - Contains the `get_next_line()` implementation with bonus features.
  - **`get_next_line_bonus.h`**:
    - Contains function prototypes and any additional structures for managing FDs.
  - **`get_next_line_utils_bonus.c`**:
    - Utility functions shared by the bonus implementation (e.g., memory handling, linked list management).
- **Reason for Separation**:
  - Clear distinction between mandatory and bonus functionality.
  - Bonus features will only be evaluated if the mandatory part works perfectly.

---

### 4. **Common Challenges & Solutions**

#### **Handling Dynamic Memory**
- When you dynamically allocate memory (e.g., for leftover buffers), ensure you properly free it when:
  1. The file descriptor is closed.
  2. An error occurs.
  3. The end of the file (EOF) is reached.

#### **Edge Cases to Test**
- **Single FD**:
  - Reading a file with varying buffer sizes (`BUFFER_SIZE=1`, `BUFFER_SIZE=10000`).
- **Multiple FDs**:
  - Switching between FDs in random order, ensuring no cross-contamination of data.
- **Empty or Short Files**:
  - Test with empty files or files shorter than the buffer size.
- **Error Handling**:
  - Test invalid FDs, closed FDs, and unexpected conditions.

---

### 5. **Compiling and Running the Bonus**
- Your Makefile should include a rule for the bonus:
  ```Makefile
  bonus:
      cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c \
      get_next_line_utils_bonus.c -o get_next_line_bonus
  ```
- Example usage:
  ```bash
  make bonus
  ./get_next_line_bonus <input_file>
  ```

---

### 6. **Key Insights**
- Think of each FD as having its own "workspace" for storing leftover data. Your code must manage these workspaces dynamically and efficiently.
- Managing multiple FDs introduces complexity but is a rewarding exercise in resource management and data structures.
- Proper testing is critical to ensure robustness across diverse scenarios.

---

Would you like a specific example of code or further clarification?

## 🤔 FAQ

1. **What happens at EOF?**
   - The function returns `NULL` when no more lines are available.

2. **What about binary files?**
   - Undefined behavior for binary files, but logical handling is optional.

3. **What buffer size is ideal?**
   - Test with various sizes; the function should work for all valid buffer values.

4. **Can I use `libft`?**
   - No, external libraries are not allowed.
