# MiniShell

## 1-Functions authorized

| Functions | Lib | Prototype (linux) | Description |
| --- | --- | -------- | ---|
| `Malloc` | <stdlib.h> | void *malloc(size_t size); | Allocates **size** bytes and returns a pointer to the allocated memory ([heap](https://gribblelab.org/CBootCamp/7_Memory_Stack_vs_Heap.html)). [check the [man](https://man7.org/linux/man-pages/man3/malloc.3.html)] |
| `Free` | <stdlib.h> | void free(void *ptr);      | Frees the memory space pointed to by **ptr**, which must have been returned by a previous call to **malloc()**. [check the [man](https://man7.org/linux/man-pages/man1/free.1.html)]|
| `Write` | <unistd.h> |  ssize_t write(int fd, const void *buf, size_t count); | Writes up to count bytes from the buffer starting at buf to the file referred to by the file descriptor [fd](https://en.wikipedia.org/wiki/File_descriptor). [check the [man](https://www.man7.org/linux/man-pages/man2/write.2.html)] |
| `Open` | <sys/types.h> <sys/stat.h> <fcntl.h> | int open(const char *pathname, int flags); | Opens the file specified by **pathname**. [check the [man](https://man7.org/linux/man-pages/man2/open.2.html) and check about the [flags](https://stackoverflow.com/questions/53807679/whats-the-connection-between-flags-and-mode-in-open-file-function-in-c)] |
| `Read` | <unistd.h> | ssize_t read(int fd, void *buf, size_t count); | Read up to count bytes from file descriptor [fd](https://en.wikipedia.org/wiki/File_descriptor) into the buffer starting at **buf**. [check the [man](https://man7.org/linux/man-pages/man2/read.2.html)] |
| `Close` | <unistd.h> |  int close(int fd); | Closes a [file descriptor](https://en.wikipedia.org/wiki/File_descriptor), so that it no longer refers to any file and may be reused. [check the [man](https://man7.org/linux/man-pages/man2/close.2.html)] |
| `Fork` | <sys/types.h> <unistd.h> | pid_t fork(void); | Creates a new [process](https://en.wikipedia.org/wiki/Process_(computing)#:~:text=In%20computing%2C%20a%20process%20is,execution%20that%20execute%20instructions%20concurrently.) by duplicating the calling [process](https://en.wikipedia.org/wiki/Process_(computing)#:~:text=In%20computing%2C%20a%20process%20is,execution%20that%20execute%20instructions%20concurrently.).  The new [process](https://en.wikipedia.org/wiki/Process_(computing)#:~:text=In%20computing%2C%20a%20process%20is,execution%20that%20execute%20instructions%20concurrently.) is referred to as the [child process](https://www.tutorialspoint.com/process-vs-parent-process-vs-child-process).  The calling [process]() is referred to as the [parent process](https://www.tutorialspoint.com/process-vs-parent-process-vs-child-process). ![diagram1](https://linuxhint.com/wp-content/uploads/2019/07/1-8.png)![diagram2](https://media.geeksforgeeks.org/wp-content/uploads/fork-and-wait.png)[check the [man](https://www.man7.org/linux/man-pages/man2/fork.2.html) and check more [details](https://www.geeksforgeeks.org/fork-system-call/) or the source of the [first diagram](https://linuxhint.com/fork_linux_system_call_c/) and the [second diagram](https://www.geeksforgeeks.org/fork-execute-processes-bottom-using-wait/)]|
| `Wait` | <sys/types.h> <sys/wait.h> | pid_t wait(int *wstatus); | [check the [man](https://man7.org/linux/man-pages/man2/wait.2.html)]|
| `Waitpid` | <sys/types.h> <sys/wait.h> | pid_t waitpid(pid_t pid, int *wstatus, int options); | [check the [man](https://man7.org/linux/man-pages/man2/wait.2.html)]|
| `Wait3` | <sys/types.h> <sys/time.h> <sys/resource.h> <sys/wait.h> | pid_t wait3(int *wstatus, int options, struct rusage *rusage); | [check the [man](https://man7.org/linux/man-pages/man2/wait4.2.html)]|
| `Wait4` | <sys/types.h> <sys/time.h> <sys/resource.h> <sys/wait.h> | pid_t wait4(pid_t pid, int *wstatus, int options, struct rusage *rusage); | [check the [man](https://man7.org/linux/man-pages/man2/wait4.2.html)]|


## 2-Definition

| Words | Definition |
| --- | --- |
| *Process* | A process is a program in execution. Process is not as same as program code but a lot more than it. A process is an 'active' entity as opposed to program which is considered to be a 'passive' entity. Attributes held by process include hardware state, memory, CPU etc. Basically a program in execution. [Check the [first source](https://www.quora.com/What-is-the-difference-between-a-built-in-function-and-a-user-defined-function) and the [second source](https://en.wikipedia.org/wiki/Process_(computing)) and the [third source](https://www.tutorialspoint.com/operating_system/os_processes.htm) or the [fourth source](https://www.studytonight.com/operating-system/operating-system-processes)]|
| *Child Process* | A child process is a process created by a parent process in operating system using a fork() system call. A child process may also be called a subprocess or a subtask. A child process is created as its parent process's copy and inherits most of its attributes. [Check the [source](https://www.quora.com/What-is-the-difference-between-a-built-in-function-and-a-user-defined-function)] |
| *Parent Process* | All the processes in operating system are created when a process executes the fork() system call except the startup process. Parent process is one that creates a child process. A parent process may have multiple child processes but a child process only one parent process. ![diagram1](https://www.tutorialspoint.com/assets/questions/media/12675/Parent%20and%20Child%20Process.PNG) [Check the [source](https://www.quora.com/What-is-the-difference-between-a-built-in-function-and-a-user-defined-function)] |

## 3-Questions and sources

| Questions we can ask ourselves for this project | Link |
| --- | --- |
| *What is the difference between a built-in function and a user defined function?* | [click on me](https://www.quora.com/What-is-the-difference-between-a-built-in-function-and-a-user-defined-function) |





sources:

Signal :

- https://www.tutorialspoint.com/c_standard_library/c_function_signal.htm
