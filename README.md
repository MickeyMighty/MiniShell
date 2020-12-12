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
| `kill` | <sys/types.h> <signal.h> |  int kill(pid_t pid, int sig); | Send a signal to a process or a group of processes specified by pid. The kill command is used to terminate processes without having to log out or reboot (i.e., restart) the computer. **Each process you start is usually completed within a few seconds. Sometimes a background process or a process without a controlling terminal hangs up and you will need to destroy this process by killing it.** <br/> [check the [man](https://man7.org/linux/man-pages/man2/kill.2.html) and the [first source](https://aljensencprogramming.wordpress.com/2014/05/15/the-kill-function-in-c/) and the [second source](http://www.linfo.org/kill.html)]|
| `exit` | <unistd.h> | void _exit(int status); | Terminates the calling process immediately. Any open file descriptors belonging to the process are closed and any children of the process are inherited by process 1, init, and the process parent is sent a SIGCHLD signal. Do not mix **exit** and **Exit** which are not the same thing. We are talking here about the **exit** function. [check the [man](https://man7.org/linux/man-pages/man2/exit.2.html)]|
| `getcwd` | <unistd.h> | char *getcwd(char *buf, size_t size); |  Gets the path name of the current working directory. If a buffer is specified, the path name is placed in that buffer, and the address of the buffer is returned. Otherwise, getcwd() allocates space for the path name and returns a pointer to that buffer. In that instance, the user is responsible for deleting the storage when it is no longer needed by calling free() with the pointer returned by getcwd(). Copies an absolute pathname of the current working directory to the array pointed to by buf, which is of length **size**.[check the [man](https://man7.org/linux/man-pages/man3/getcwd.3.html)]|
| `chdir` | <unistd.h> | int chdir(const char *path); | Used to change the current working directory. On some systems, this command is used as an alias for the shell command [cd](https://en.wikipedia.org/wiki/Cd_(command)). chdir changes the current working directory of the calling process to the directory specified in path.[check the [man](https://man7.org/linux/man-pages/man2/chdir.2.html) and the example and the [source](https://www.geeksforgeeks.org/chdir-in-c-language-with-examples/)]|
| `stat` | <sys/types.h> <sys/stat.h> <unistd.h> | int stat(const char *pathname, struct stat *statbuf); | Return information about a file. No permissions are required on the file itself, but in the case of stat() execute (search) permission is required on all of the directories in path that lead to the file. [check the [man](https://man7.org/linux/man-pages/man2/stat.2.html)]|
| `lstat` | <sys/types.h> <sys/stat.h> <unistd.h> | int lstat(const char *pathname, struct stat *statbuf); | Gets status information about a specified file and places it in the area of memory pointed to by buf. If the named file is a symbolic link, lstat() returns information about the symbolic link itself. [check the [man](https://man7.org/linux/man-pages/man2/stat.2.html) and the [source](https://www.ibm.com/support/knowledgecenter/ssw_ibm_i_74/apis/lstat.htm)]|
| `fstat` | <sys/types.h> <sys/stat.h> <unistd.h> |  int fstat(int fd, struct stat *statbuf); | Shall obtain information about an open file associated with the file descriptor fildes, and shall write it to the area pointed to by buf. It informs the file size by filling in the struct passed as an argument. [check the [man](https://man7.org/linux/man-pages/man2/stat.2.html) and the [source](https://stackoverflow.com/questions/20999255/get-the-status-of-a-specific-pid) and this [link](https://stackoverflow.com/questions/28288775/how-do-you-properly-use-the-fstat-function-and-what-are-its-limits) for help]|
| `execve` | <unistd.h> | int execve(const char *filename, char *const argv[], char *const envp[]); | Executes the program pointed to by **filename**. **filename** must be either a binary executable, or a script starting with a line of the form "#! interpreter *[arg]*". In the latter case, the interpreter must be a valid pathname for an executable which is not itself a script, which will be invoked as interpreter *[arg]* **filename**. Execve() executes the program referred to by pathname. This causes the program that is currently being run by the calling process to be replaced with a new program, with newly initialized stack, heap, and (initialized and uninitialized) data segments. ![diagram](https://i.ytimg.com/vi/9fCmr__VVmQ/maxresdefault.jpg)[check the [man](https://man7.org/linux/man-pages/man2/execve.2.html) and the source of the [diagram](https://www.softprayog.in/programming/creating-processes-with-fork-and-exec-in-linux) and the [source](https://stackoverflow.com/questions/10068327/what-does-execve-do)]|
| `dup` | <unistd.h> | int dup(int oldfd); | The dup() (short for "duplicate") system call creates a copy of a file descriptor. It uses the lowest-numbered unused descriptor for the new descriptor. <br/<br/> [check the [man](https://man7.org/linux/man-pages/man2/dup.2.html) and the [source](https://www.geeksforgeeks.org/dup-dup2-linux-system-call/#:~:text=The%20dup()%20system%20call,descriptor%20for%20the%20new%20descriptor.&text=They%20both%20refer%20to%20the,offset%20and%20file%20status%20flags.)]|
| `dup2` | <unistd.h> | int dup2(int oldfd, int newfd); | `dup2` doesn't switch the file descriptors, it makes them equivalent. When you have part of a program that reads or write from the standard file descriptors. For example, suppose that somefunc() reads from standard input, but you want it to read from a different file from where the rest of the program is getting its standard input. The difference between dup and `dup2` is that `dup` assigns the lowest available file descriptor number, while `dup2 lets you choose the file descriptor number that will be assigned and atomically closes and replaces it if it's already taken. <br/> [check the [man](https://man7.org/linux/man-pages/man2/dup.2.html) and the [first source](https://stackoverflow.com/questions/24538470/what-does-dup2-do-in-c) and the [second source](https://www.geeksforgeeks.org/piping-in-unix-or-linux/)]|
| `pipe` | <unistd.h> | int pipe(int pipefd); | A pipe is a form of redirection (transfer of standard output to some other destination) that is used in Linux and other Unix-like operating systems to send the output of one command/program/process to another command/program/process for further processing. The Unix/Linux systems allow stdout of a command to be connected to stdin of another command. You can make it do so by using the pipe character. ![pipe](https://charbase.com/images/glyph/10072)  <br/> pipe() creates a pipe, a unidirectional data channel that can be used for interprocess communication. The array pipefd is used to return two file descriptors referring to the ends of the pipe. pipefd[0] refers to the read end of the pipe. pipefd[1] refers to the write end of the pipe. Data written to the write end of the pipe is buffered by the kernel until it is read from the read end of the pipe. ![diagram](https://bash.cyberciti.biz/uploads/bashwiki/d/d0/Shell-pipes.png) [check the [man](https://man7.org/linux/man-pages/man2/pipe.2.html) and the source of the [diagram](https://bash.cyberciti.biz/guide/Pipes) and the [first source](https://stackoverflow.com/questions/11454343/pipe-output-to-bash-function#:~:text=To%20answer%20your%20actual%20question,function%2C%20standard%20input%20is%20ignored.) and the [second source](https://www.testingdocs.com/piping-in-linux-operating-system/)]|
| `opendir` | <sys/types.h> <dirent.h> | DIR *opendir(const char *name); | Opens a directory stream corresponding to the directory name, and returns a pointer to the directory stream. The stream is positioned at the first entry in the directory.[check the [man](https://man7.org/linux/man-pages/man3/opendir.3.html) and the [source](https://stackoverflow.com/questions/3554120/open-directory-using-c)]|
| `closedir` | <dirent.h> | int closedir(DIR *dirp); | Closes the directory stream associated with dirp. A successful call to closedir() also closes the underlying file descriptor associated with dirp. The directory stream descriptor dirp is not available after this call. <br/> [check the [man](https://man7.org/linux/man-pages/man3/closedir.3p.html)]|
| `strerror` | <string.h> | char *strerror(int errnum); | Returns a pointer to a string that describes the error code passed in the argument errnum, possibly using the LC_MESSAGES part of the current locale to select the appropriate language. No other library function, including 'perror(3)', will modify this string. <br/> [check the [man](https://man7.org/linux/man-pages/man3/strerror.3.html) and the [source](https://www.geeksforgeeks.org/error-handling-c-programs/)]|
| `errno` | <errno.h> | ~nothing~ | When a function is called in C, a variable named as errno is automatically assigned a code (value) which can be used to identify the type of error that has been encountered. <br/> [check the [man](https://man7.org/linux/man-pages/man3/errno.3.html) and the [first source](https://www.geeksforgeeks.org/error-handling-c-programs/#:~:text=Global%20Variable%20errno%3A%20When%20a,error%20that%20has%20been%20encountered.) and the [second source](https://en.wikipedia.org/wiki/Errno.h)]|


## 2-Definition

| Words | Definition |
| --- | --- |
| *Process* | A process is a program in execution. Process is not as same as program code but a lot more than it. A process is an 'active' entity as opposed to program which is considered to be a 'passive' entity. Attributes held by process include hardware state, memory, CPU etc. Basically a program in execution. [Check the [first source](https://www.quora.com/What-is-the-difference-between-a-built-in-function-and-a-user-defined-function) and the [second source](https://en.wikipedia.org/wiki/Process_(computing)) and the [third source](https://www.tutorialspoint.com/operating_system/os_processes.htm) or the [fourth source](https://www.studytonight.com/operating-system/operating-system-processes)]|
| *Child Process* | A child process is a process created by a parent process in operating system using a fork() system call. A child process may also be called a subprocess or a subtask. A child process is created as its parent process's copy and inherits most of its attributes. [Check the [source](https://www.quora.com/What-is-the-difference-between-a-built-in-function-and-a-user-defined-function)] |
| *Parent Process* | All the processes in operating system are created when a process executes the fork() system call except the startup process. Parent process is one that creates a child process. A parent process may have multiple child processes but a child process only one parent process. ![diagram1](https://www.tutorialspoint.com/assets/questions/media/12675/Parent%20and%20Child%20Process.PNG) <br/> [Check the [source](https://www.quora.com/What-is-the-difference-between-a-built-in-function-and-a-user-defined-function)] |
| *i.e.* | Is the abbreviation for the Latin phrase id est, meaning “that is.” This abbreviation is used when you want to specify something mentioned previously; it can be used interchangeably with “specifically” or “namely”. Or  IE is a common acronym for Microsoft Internet Explorer. See our Microsoft Internet Explorer definition for additional information. [Check the [source](https://www.aje.com/arc/editing-tip-using-eg-and-ie/#:~:text=i.e.%20is%20the%20abbreviation%20for,the%20Summer%20Olympics%20three%20times.%E2%80%9D)]
| *pid* | Is the abbreviation for process [ID](https://en.wiktionary.org/wiki/id.#:~:text=Acronym%20of%20identity%20document.,Abbreviation%20of%20identification.) (PID). Every process on the system has a unique process ID number, known as the pid. This is simply an integer. You can get the pid for a process via the getpid system call. ![diagram](https://www.csimn.com/CSI_images/info/PIDforDummies_pid_controller1.png)[Check the [source](https://www.aje.com/arc/editing-tip-using-eg-and-ie/#:~:text=i.e.%20is%20the%20abbreviation%20for,the%20Summer%20Olympics%20three%20times.%E2%80%9D) and the source of the [diagram](https://www.csimn.com/CSI_pages/PIDforDummies.html)]
| *PATH* | Is an environmental variable in Linux and other Unix-like operating systems that tells the shell which directories to search for executable files (i.e., ready-to-run programs) in response to commands issued by a user. A path is a unique location to a file or a folder in a file system of an OS.A path to a file is a combination of / and alpha-numeric characters. ![diagram](https://media.geeksforgeeks.org/wp-content/uploads/absolutePathNames.jpg) <br/> [Check the [first source](http://www.linfo.org/path_env_var.html#:~:text=PATH%20is%20an%20environmental%20variable,commands%20issued%20by%20a%20user.) and the [second source](https://medium.com/@jalendport/what-exactly-is-your-shell-path-2f076f02deb4) and the source of the [diagram](https://www.geeksforgeeks.org/absolute-relative-pathnames-unix/)]|
| *buf* | (Output) A pointer to the area to which the information should be written. Buf means buffer, C uses a buffer to output or input variables. The buffer stores the variable that is supposed to be taken in (input) or sent out (output) of the program. A buffer needs to be cleared before the next input is taken in. [Check the [source](https://www.educative.io/edpresso/what-is-a-buffer-in-c)]|
| *env* | Env(Environment) is used to either print environment variables. It is also used to run a utility or command in a custom environment. In practice, env has another common use. It is often used by shell scripts to launch the correct interpreter. In this usage, the environment is typically not changed. Env is a shell command for Unix and Unix-like operating systems. It is used to either print a list of environment variables or run another utility in an altered environment without having to modify the currently existing environment. [Check the [first source](https://docs.oracle.com/cd/E19120-01/open.solaris/819-2379/userconcept-26/index.html) and [second source](https://unix.stackexchange.com/questions/103467/what-is-env-command-doing) and [example](https://www.geeksforgeeks.org/env-command-in-linux-with-examples/)]|


## 3-Questions and sources

| Questions we can ask ourselves for this project | Link |
| --- | --- |
| *What is the Shell syntax ?* | [click on me](https://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html)|
| *Where i can start ?* | [click on me](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf) and [click on me](https://indradhanush.github.io/blog/writing-a-unix-shell-part-1/)|
| *What is the difference between a built-in function and a user defined function ?* | [click on me](https://www.quora.com/What-is-the-difference-between-a-built-in-function-and-a-user-defined-function) |
| *What is the difference between wait, waitpid, wait3, wait4 ?* | [click on me](https://www.quora.com/Linux-What-is-the-difference-between-%E2%80%9Cwait%E2%80%9D-%E2%80%9Cwait3%E2%80%9D-and-%E2%80%9Cwait4%E2%80%B3-System-Call) and [click on me](https://programmer.help/blogs/linux-kernel-learning-notes-4-wait-waitpid-wait3-and-wait4.html)|
| *What are signals ?* | [click on me](https://indradhanush.github.io/blog/writing-a-unix-shell-part-3/) and [click on me](https://www.geeksforgeeks.org/signals-c-language/) and [click one me](https://www.tutorialspoint.com/c_standard_library/c_function_signal.htm)|
| *Why we need to kill a process ?* | [click on me](https://docstore.mik.ua/orelly/networking/puis/appc_04.htm) and [click one me](https://www.bsd.org/unixhelp.ed.ac.uk/shell/jobz5.html) and [click one me](https://www.ibm.com/support/knowledgecenter/ssw_ibm_i_74/apis/sigkill.htm)|
| *What is difference between file descriptor and fildes ?* | [click on me](https://stackoverflow.com/questions/13614040/what-is-difference-between-file-descriptor-and-fildes)|
| *What is difference between a relative PATH and a absolute PATH ?* | [click on me](https://stackoverflow.com/questions/3915040/bash-fish-command-to-print-absolute-path-to-a-file#:~:text=A%20relative%20path%20is%20a,interpreted%20starting%20from%20another%20directory.&text=Hence%20an%20absolute%20path%20is,may%20not%20contain%20symbolic%20links.) and [click on me](https://www.geeksforgeeks.org/absolute-relative-pathnames-unix/)|
| *What is difference between dup and dup2 ?* | [click on me](https://stackoverflow.com/questions/4171126/what-do-the-dup-and-dup2-systems-really-do#:~:text=The%20difference%20between%20dup%20and,it%20if%20it's%20already%20taken.)|
| *How to get the current directory in a C program ?* | [click on me](https://stackoverflow.com/questions/298510/how-to-get-the-current-directory-in-a-c-program)|
| *Some bonus source (in french)* | [click on me](http://paysdu42.fr/?page=minishell.c) and [click on me](https://segfault42.github.io/posts/minishell/)|


## 4-Project

**Structure**
```\Minishell - </pid>```
