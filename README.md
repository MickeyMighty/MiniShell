# MiniShell

## 1-Functions authorized

| Functions | Lib | Prototype (linux) | Description |
| --- | --- | --- | ---|
| `malloc` | <stdlib.h> | void *malloc(size_t size); | Allocates **size** bytes and returns a pointer to the allocated memory ([heap](https://gribblelab.org/CBootCamp/7_Memory_Stack_vs_Heap.html)). [check the [man](https://man7.org/linux/man-pages/man3/malloc.3.html)] |
| `free` | <stdlib.h> | void free(void *ptr);      | Frees the memory space pointed to by **ptr**, which must have been returned by a previous call to **malloc()**. [check the [man](https://man7.org/linux/man-pages/man1/free.1.html)]|
| `write` | <unistd.h> |  ssize_t write(int fd, const void *buf, size_t count); | Writes up to count bytes from the buffer starting at buf to the file referred to by the file descriptor [fd](https://en.wikipedia.org/wiki/File_descriptor). [check the [man](https://www.man7.org/linux/man-pages/man2/write.2.html)] |
| `open` | <sys/types.h> <sys/stat.h> <fcntl.h> | int open(const char *pathname, int flags); | Opens the file specified by **pathname**. [check the [man](https://man7.org/linux/man-pages/man2/open.2.html) and check about the [flags](https://stackoverflow.com/questions/53807679/whats-the-connection-between-flags-and-mode-in-open-file-function-in-c)] |
| `read` | <unistd.h> | ssize_t read(int fd, void *buf, size_t count); | Read up to count bytes from file descriptor [fd](https://en.wikipedia.org/wiki/File_descriptor) into the buffer starting at **buf**. [check the [man](https://man7.org/linux/man-pages/man2/read.2.html)] |
| `close` | <unistd.h> |  int close(int fd); | Closes a [file descriptor](https://en.wikipedia.org/wiki/File_descriptor), so that it no longer refers to any file and may be reused. [check the [man](https://man7.org/linux/man-pages/man2/close.2.html)] |
| `fork` | <sys/types.h> <unistd.h> | pid_t fork(void); | Creates a new process by duplicating the calling process. The new process is referred to as the child process. The calling process is referred to as the Parent process. ![diagram1](https://linuxhint.com/wp-content/uploads/2019/07/1-8.png)![diagram2](https://media.geeksforgeeks.org/wp-content/uploads/fork-and-wait.png)[check the [man](https://www.man7.org/linux/man-pages/man2/fork.2.html) and check more [details](https://www.geeksforgeeks.org/fork-system-call/) or the source of the [first diagram](https://linuxhint.com/fork_linux_system_call_c/) and the [second diagram](https://www.geeksforgeeks.org/fork-execute-processes-bottom-using-wait/)]|
| `wait` | <sys/types.h> <sys/wait.h> | pid_t wait(int *wstatus); | Blocks the calling process until one of its child processes exits or a signal is received. After child process terminates, parent continues its execution after wait system call instruction. The wait function can block the caller until a child process terminates.![diagram2](https://media.geeksforgeeks.org/wp-content/uploads/Wait_system_call_in_c.jpg)[check the [man](https://man7.org/linux/man-pages/man2/wait.2.html) and the source of the [diagram](https://www.geeksforgeeks.org/wait-system-call-c/)]|
| `waitpid` | <sys/types.h> <sys/wait.h> | pid_t waitpid(pid_t pid, int *wstatus, int options); | Whereas waitpid has an option that prevents it from blocking. Suspends execution of the calling process until a child specified by pid argument has changed state. The waitpid function doesn't wait for the child that terminates first, it has a number of options that control which process it waits for. [check the [man](https://man7.org/linux/man-pages/man2/wait.2.html)]|
| `wait3` | <sys/types.h> <sys/time.h> <sys/resource.h> <sys/wait.h> | pid_t wait3(int *wstatus, int options, struct rusage *rusage); | The difference between wait and wait3 or waitpid and wait4 is that wait3 and wait4 accept an additional argument. This is the struct rusage, that returns a summary of the system resources used by the child process. [check the [man](https://man7.org/linux/man-pages/man2/wait4.2.html)]|
| `wait4` | <sys/types.h> <sys/time.h> <sys/resource.h> <sys/wait.h> | pid_t wait4(pid_t pid, int *wstatus, int options, struct rusage *rusage); | The wait3() and wait4() system call performs the similar task to waitpid(). The core difference between them(i.e waitpid() and wait3() ,wait4()), is in terms of the resources usage information about the terminated child in the structure pointed to by the rusage argument. The information includes CPU time used by the process and memory-management statistics. [check the [man](https://man7.org/linux/man-pages/man2/wait4.2.html)]|
| `signal` | <signal.h> |  typedef void (*sighandler_t)(int); sighandler_t signal(int signum, sighandler_t handler); | Is an event which is generated to notify a process or thread that some important situation has arrived. When a process or thread has received a signal, the process or thread will stop what its doing and take some action. Signal may be useful for inter-process communication. ![diagram1](https://indradhanush.github.io/images/shell-part-3/signals.jpg) [check the [man](https://man7.org/linux/man-pages/man2/signal.2.html) and check the source of the [diagram](https://indradhanush.github.io/blog/writing-a-unix-shell-part-3/)]|
| `kill` | <sys/types.h> <signal.h> |  int kill(pid_t pid, int sig); | [check the [man](https://man7.org/linux/man-pages/man2/kill.2.html)]|
| `exit` | <unistd.h> | void _exit(int status); | [check the [man](https://man7.org/linux/man-pages/man2/exit.2.html)]|
| `getcwd` | <unistd.h> | char *getcwd(char *buf, size_t size); | [check the [man](https://man7.org/linux/man-pages/man3/getcwd.3.html)]|
| `chdir` | <unistd.h> | int chdir(const char *path); | [check the [man](https://man7.org/linux/man-pages/man2/chdir.2.html)]|
| `stat` | <sys/types.h> <sys/stat.h> <unistd.h> | int stat(const char *pathname, struct stat *statbuf); | [check the [man](https://man7.org/linux/man-pages/man2/stat.2.html)]|
| `lstat` | <sys/types.h> <sys/stat.h> <unistd.h> | int lstat(const char *pathname, struct stat *statbuf); | [check the [man](https://man7.org/linux/man-pages/man2/stat.2.html)]|
| `fstat` | <sys/types.h> <sys/stat.h> <unistd.h> |  int fstat(int fd, struct stat *statbuf); | [check the [man](https://man7.org/linux/man-pages/man2/stat.2.html)]|
| `execve` | <unistd.h> | int execve(const char *pathname, char *const argv[], char *const envp[]); | [check the [man](https://man7.org/linux/man-pages/man2/execve.2.html)]|
| `dup` | <unistd.h> | int dup(int oldfd); | [check the [man](https://man7.org/linux/man-pages/man2/dup.2.html)]|
| `dup2` | <unistd.h> | int dup2(int oldfd, int newfd); | [check the [man](https://man7.org/linux/man-pages/man2/dup.2.html)]|
| `pipe` | <unistd.h> | int pipe(int pipefd); | [check the [man](https://man7.org/linux/man-pages/man2/pipe.2.html)]|
| `opendir` | <sys/types.h> <dirent.h> | DIR *opendir(const char *name); | [check the [man](https://man7.org/linux/man-pages/man3/opendir.3.html)]|
| `closedir` | <dirent.h> | int closedir(DIR *dirp); | [check the [man](https://man7.org/linux/man-pages/man3/closedir.3p.html)]|
| `strerror` | <string.h> | char *strerror(int errnum); | [check the [man](https://man7.org/linux/man-pages/man3/strerror.3.html)]|
| `errno` | <errno.h> | ~nothing~ | [check the [man](https://man7.org/linux/man-pages/man3/errno.3.html)]|


## 2-Definition

| Words | Definition |
| --- | --- |
| *Process* | A process is a program in execution. Process is not as same as program code but a lot more than it. A process is an 'active' entity as opposed to program which is considered to be a 'passive' entity. Attributes held by process include hardware state, memory, CPU etc. Basically a program in execution. [Check the [first source](https://www.quora.com/What-is-the-difference-between-a-built-in-function-and-a-user-defined-function) and the [second source](https://en.wikipedia.org/wiki/Process_(computing)) and the [third source](https://www.tutorialspoint.com/operating_system/os_processes.htm) or the [fourth source](https://www.studytonight.com/operating-system/operating-system-processes)]|
| *Child Process* | A child process is a process created by a parent process in operating system using a fork() system call. A child process may also be called a subprocess or a subtask. A child process is created as its parent process's copy and inherits most of its attributes. [Check the [source](https://www.quora.com/What-is-the-difference-between-a-built-in-function-and-a-user-defined-function)] |
| *Parent Process* | All the processes in operating system are created when a process executes the fork() system call except the startup process. Parent process is one that creates a child process. A parent process may have multiple child processes but a child process only one parent process. ![diagram1](https://www.tutorialspoint.com/assets/questions/media/12675/Parent%20and%20Child%20Process.PNG) [Check the [source](https://www.quora.com/What-is-the-difference-between-a-built-in-function-and-a-user-defined-function)] |
| *i.e.* | Is the abbreviation for the Latin phrase id est, meaning “that is.” This abbreviation is used when you want to specify something mentioned previously; it can be used interchangeably with “specifically” or “namely”. [Check the [source](https://www.aje.com/arc/editing-tip-using-eg-and-ie/#:~:text=i.e.%20is%20the%20abbreviation%20for,the%20Summer%20Olympics%20three%20times.%E2%80%9D)]

## 3-Questions and sources

| Questions we can ask ourselves for this project | Link |
| --- | --- |
| *What is the Shell syntax ?* | [click on me](https://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html)|
| *Where i can start ?* | [click on me](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf)|
| *What is the difference between a built-in function and a user defined function ?* | [click on me](https://www.quora.com/What-is-the-difference-between-a-built-in-function-and-a-user-defined-function) |
| *What is the difference between wait, waitpid, wait3, wait4 ?* | [click on me](https://www.quora.com/Linux-What-is-the-difference-between-%E2%80%9Cwait%E2%80%9D-%E2%80%9Cwait3%E2%80%9D-and-%E2%80%9Cwait4%E2%80%B3-System-Call) and [click on me](https://programmer.help/blogs/linux-kernel-learning-notes-4-wait-waitpid-wait3-and-wait4.html)|
| *What are signals?* | [click on me](https://indradhanush.github.io/blog/writing-a-unix-shell-part-3/) and [click on me](https://www.geeksforgeeks.org/signals-c-language/) and [click one me](https://www.tutorialspoint.com/c_standard_library/c_function_signal.htm)|
