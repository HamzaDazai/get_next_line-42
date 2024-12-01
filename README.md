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

## 🏆 Bonus Objectives
- Ensure smooth operation with multiple simultaneous file descriptors.
- Achieve efficient memory handling and performance.

---

## 📂 Submission and Evaluation
1. Upload your project to the assigned Git repository.
2. Verify file naming and adherence to the Norm.
3. Ensure proper memory management and absence of leaks.
4. Test your project rigorously:
   - Vary buffer and line sizes.
   - Use diverse test cases (e.g., standard input, regular files).

---

## 🤔 FAQ

1. **What happens at EOF?**
   - The function returns `NULL` when no more lines are available.

2. **What about binary files?**
   - Undefined behavior for binary files, but logical handling is optional.

3. **What buffer size is ideal?**
   - Test with various sizes; the function should work for all valid buffer values.

4. **Can I use `libft`?**
   - No, external libraries are not allowed.

---

## 📝 Author
Add your name, GitHub profile, or other relevant details here.

---

Let me know if you'd like any changes or additions!
