Below is the updated and cleaned-up version of the README.md based on the code you shared and its intended functionality.

---

# **get_next_line**

`get_next_line` is a C function that reads a file line-by-line, returning the next line with each call. This implementation handles dynamic memory allocation, works for any file descriptor, and supports varying buffer sizes.

---

## **Function Prototype**

```c
char *get_next_line(int fd);
```

---

## **How It Works**

1. **Reading the File:**  
   The function reads `BUFFER_SIZE` bytes at a time using the `read()` system call. The buffer size can be adjusted to optimize performance.

2. **Handling Incomplete Lines:**  
   A static variable `tmp` retains leftover data between function calls, ensuring lines split across multiple reads are reconstructed.

3. **Finding Line Breaks:**  
   The function detects line breaks (`\n`) to identify where a line ends.

4. **Returning a Line:**  
   Each call to `get_next_line` returns a complete line, including the newline character (`\n`). If the end of the file (EOF) is reached, the remaining text is returned. If no data remains, `NULL` is returned.

5. **Dynamic Memory Management:**  
   The function dynamically allocates and frees memory to handle lines of varying lengths efficiently.

---

## **Detailed Workflow**

### **Main Function: `get_next_line`**

1. **Initialization:**  
   - A static variable `tmp` is used to store leftover data between function calls.
   - Data is read into a temporary buffer `buff` of size `BUFFER_SIZE + 1`.

2. **Reading Data:**  
   - The `read()` function reads up to `BUFFER_SIZE` bytes from the file descriptor (`fd`).
   - If no newline is found in the current `tmp`, more data is read and appended.

3. **Line Extraction:**  
   - If a newline is found, the line is extracted using `ft_substr` and returned.
   - If the end of the file is reached and no newline exists, the remaining text is returned.

4. **Memory Cleanup:**  
   - Memory for `tmp` is freed when no more lines can be read.

---

### **Helper Functions**

#### **`check_newline`**

- Scans a string for the newline character (`\n`).
- Returns the index of the first occurrence or `-1` if not found.

#### **`func`**

- Extracts a line up to the first newline from `tmp`.
- Updates `tmp` to contain the remaining data after the line.

#### **`get_reminder`**

- Prepares the leftover data after a line has been extracted.
- Ensures `tmp` is updated correctly for the next call.

#### **`ft_strlen`**

- Calculates the length of a string up to the null terminator (`\0`).

#### **`ft_strjoin` and `ft_substr`**

- Utility functions for string manipulation:
  - `ft_strjoin`: Concatenates two strings.
  - `ft_substr`: Extracts a substring from a string.

---

## **Usage**

To use `get_next_line`:

1. Include the necessary header:
   ```c
   #include "get_next_line.h"
   ```
2. Compile the function with your project:
   ```bash
   gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c -o program
   ```
3. Call the function in your program:
   ```c
   int fd = open("example.txt", O_RDONLY);
   char *line;

   while ((line = get_next_line(fd)) != NULL)
   {
       printf("%s", line);
       free(line);
   }
   close(fd);
   ```

---

## **Return Value**

- A line read from the file, including the newline character (`\n`), if present.
- `NULL` if:
  - The end of the file is reached.
  - An error occurs during reading.

---

## **Edge Cases**

1. **Empty Files:**  
   - Returns `NULL` immediately.

2. **Files Without Newlines:**  
   - Returns the entire content in a single call, then `NULL`.

3. **Memory Management:**  
   - Allocated memory must be freed after use to avoid memory leaks.

4. **Multiple File Descriptors:**  
   - The function can handle multiple file descriptors simultaneously, as `tmp` is static per file descriptor.

---

## **Customization**

- **Buffer Size:**  
  - Modify `BUFFER_SIZE` to balance memory usage and performance. A larger buffer size reduces the number of `read()` calls but increases memory usage.

---

## **Error Handling**

- If `read()` fails, the function returns `NULL`.
- Invalid file descriptors or closed files result in `NULL`.

---

## **License**

This implementation is free to use, modify, and distribute. Attribution is appreciated but not required.

---

This README provides a clear and structured explanation of `get_next_line`, covering its functionality, implementation details, and usage.