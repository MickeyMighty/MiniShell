# MiniShell

| Functions | Lib | Prototype (linux) | Description |
| --- | --- | --- | --- |
| `Malloc` | <stdlib.h> | void *malloc(size_t size); | Allocates **size** bytes and returns a pointer to the allocated memory ([heap](https://gribblelab.org/CBootCamp/7_Memory_Stack_vs_Heap.html)). |
| `Free` | <stdlib.h> | void free(void *ptr);      | Frees the memory space pointed to by **ptr**, which must have been returned by a previous call to **malloc()**.|
| `Write` | <unistd.h> |  ssize_t write(int fd, const void *buf, size_t count); | writes up to count bytes from the buffer starting at buf to the file referred to by the file descriptor [fd](https://en.wikipedia.org/wiki/File_descriptor) |
| `Open` |  

sources:

Signal :

- https://www.tutorialspoint.com/c_standard_library/c_function_signal.htm
