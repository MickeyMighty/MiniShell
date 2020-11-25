# MiniShell

| Functions | Lib | Prototype (linux) | Description |
| --- | --- | --- | --- |
| `Malloc` | <stdlib.h> | void *malloc(size_t size); | Allocates **size** bytes and returns a pointer to the allocated memory ([heap](https://gribblelab.org/CBootCamp/7_Memory_Stack_vs_Heap.html)). [check the [man](https://man7.org/linux/man-pages/man3/malloc.3.html)] |
| `Free` | <stdlib.h> | void free(void *ptr);      | Frees the memory space pointed to by **ptr**, which must have been returned by a previous call to **malloc()**. [check the [man](https://man7.org/linux/man-pages/man1/free.1.html)]|
| `Write` | <unistd.h> |  ssize_t write(int fd, const void *buf, size_t count); | Writes up to count bytes from the buffer starting at buf to the file referred to by the file descriptor [fd](https://en.wikipedia.org/wiki/File_descriptor). [check the [man](https://www.man7.org/linux/man-pages/man2/write.2.html)] |
| `Open` | <sys/types.h> <sys/stat.h> <fcntl.h> | int open(const char *pathname, int flags); | opens the file specified by **pathname**. [check the [man](https://man7.org/linux/man-pages/man2/open.2.html)]
|

sources:

Signal :

- https://www.tutorialspoint.com/c_standard_library/c_function_signal.htm
