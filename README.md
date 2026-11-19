*This project has been created as part of the 42 curriculum by `tait-si`.*

# Get Next Line

## Description

**Get Next Line (GNL)** is a project from the 42 curriculum written in C. Its goal is to create a function that reads a file or input from a file descriptor one line at a time.

The main objective is to understand how file descriptors work, how to read data using the `read()` function, and how to manage memory dynamically in C.

The function returns one line at each call, including the newline character (`\n`) when it exists. When there is nothing left to read, or an error occurs, it returns `NULL`.

One of the main challenges of this project is preserving the remaining characters between function calls. This is achieved using a static variable.

### Function Prototype

```c
char *get_next_line(int fd);
```

### Main Concepts

- File descriptors and how they identify open files.
- Reading data using `read()`.
- Static variables and their lifetime.
- Dynamic memory allocation using `malloc()`.
- String manipulation and memory management.
- Handling different file descriptors.
- Managing EOF (End Of File) and reading errors.

## Algorithm Explanation

The algorithm is based on reading a file in small chunks using a buffer, while keeping the unread characters for the next function call.

### 1. Static Variable

A static variable is used to preserve the remaining data between calls to `get_next_line()`.

Unlike a normal local variable, a static variable keeps its value after the function finishes executing.

This is important because the function must remember the characters that were read but do not belong to the current line.

### 2. Reading the File

The `read()` function reads a specific number of bytes from the file descriptor into a buffer.

The number of bytes read depends on `BUFFER_SIZE`.

Reading continues until:
- A newline character (`\n`) is found.
- The end of the file is reached.
- An error occurs.

### 3. Extracting the Line

Once a newline is found, the function extracts the characters from the beginning of the stored data up to and including the newline.

If the file ends without a newline, the remaining characters are returned as the final line.

### 4. Preserving Remaining Data

After extracting the current line, the characters that come after the newline are saved.

They will be used during the next call to `get_next_line()`.

### 5. Returning the Result

The function returns the extracted line.

When the end of the file is reached and no characters remain, it returns `NULL`.

### Algorithm Summary

1. Check whether the file descriptor is valid.
2. Read data into a buffer.
3. Append the buffer content to the previously stored data.
4. Continue reading until a newline or EOF is reached.
5. Extract the current line.
6. Preserve the remaining characters for the next call.
7. Return the line.

## Instructions

### Compilation

Clone the repository:

```bash
git clone git@vogsphere.1337.ma:vogsphere/intra-uuid-545a2929-ebe5-45d1-ab8e-69970e1d01ef-7782187-tait-si
cd intra-uuid-545a2929-ebe5-45d1-ab8e-69970e1d01ef-7782187-tait-si
```

Compile the project with:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
get_next_line.c get_next_line_utils.c main.c
```

Replace `42` with another positive buffer size to test different reading conditions.

### Execution

Run the compiled program:

```bash
./a.out
```

The `main.c` file can be used to test the function with different files and file descriptors.

**Note:** The `main.c` file is for testing purposes. It is not part of the mandatory Get Next Line submission.

## Resources

The following resources were consulted during the project to understand file descriptors, file handling, operating system concepts, and the Get Next Line algorithm.

### Articles and Documentation

- [Stack Overflow - Why are open(2) and close(2) split across different headers?](https://stackoverflow.com/questions/76456541/why-are-open2-and-close2-split-across-different-headers)
- [CodeQuoi - Handling a File by Its Descriptor in C](https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/)
- [Stack Overflow - What are file descriptors? Explained in simple terms](https://stackoverflow.com/questions/5256599/what-are-file-descriptors-explained-in-simple-terms)
- [GeeksforGeeks - Inode vs Vnode](https://www.geeksforgeeks.org/operating-systems/inode-vs-vnode/)
- [TechTarget - TCP (Transmission Control Protocol)](https://www.techtarget.com/searchnetworking/definition/TCP)

### Video Tutorials

- [YouTube - File descriptors and file handling](https://www.youtube.com/watch?v=4s2MKuVYKV8&t=209s)
- [YouTube - Additional technical explanation](https://www.youtube.com/watch?v=8E9siq7apUU)
- [YouTube - Get Next Line explanation](https://www.youtube.com/watch?v=qsomkTmFQkA&t=268s)
- [YouTube - Get Next Line tutorial](https://www.youtube.com/watch?v=-Mt2FdJjVno&t=2s)
- [YouTube - Get Next Line tutorial](https://www.youtube.com/watch?v=aC47sz7n1wo&t=713s)

### AI Usage

AI tools were used as learning assistance throughout this project.

They helped me:
- Understand difficult parts of the code, especially the behavior and purpose of static variables.
- Break down complicated concepts into simpler explanations.
- Understand how different parts of the function work together.
- Explore cleaner and more understandable ways to approach certain parts of the code.
- Clarify concepts related to file descriptors, memory allocation, and reading files.

AI was used as a learning and explanatory tool, not as a replacement for writing and understanding the project. The implementation was completed independently.

## Learning Experience and Acknowledgments

This project was a challenging learning experience for me. I spent approximately two weeks working on Get Next Line because I wanted to understand what was happening behind the code instead of simply writing something that worked.

At one point, I was stuck on a particular part of the implementation. My peer **Wassim** helped me understand that part, and the following day I was able to complete the code.

I would especially like to thank **slasfar**, who played an important role in helping me debug issues in my Get Next Line implementation.

After completing the implementation, I moved on to understanding the theory behind it, especially file descriptors. I also wrote a separate `main()` program to experiment with and understand how `get_next_line(int fd)` behaves when reading files.

I would also like to thank the following peers from different promotions who helped me along the way:

- **itemsam**
- **zel-atma**
- **chel-bou**
- **momellou**
- **mhaddou**
- **waoukoud**

Their explanations, guidance, debugging help, and willingness to help made a difference during my learning process.

The project itself was completed independently. These peers were not project collaborators; they helped me understand concepts and overcome difficulties.

**This project taught me the importance of patience, research, experimentation, and understanding the logic behind the code rather than focusing only on the final result.**