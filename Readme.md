# Pipex

## For this task we must create a program name pipex who will behave like de | "pipe" command from bash.
    here are the shell commands we are allowed to use:
    ◦ access:
          access() checks whether the calling process can access the file pathname.  If pathname is a symbolic link, it is dereferenced.
    ◦ open:
          The open() system call opens the file specified by pathname.  If the specified file does not exist, it may optionally (if O_CREAT is specified in flags) be created by open().
    ◦ unlink:
          Call the unlink function to remove the specified FILE.
    ◦ close:
          ´close()  closes  a file descriptor, so that it no longer refers to any file and may be reused.  Any record locks (see fcntl(2)) held on the file it was associated with, and owned by the process, are re‐moved (regardless of the file descriptor that was used to obtain the lock).´
    ◦ read
    ◦ write
    ◦ malloc
    ◦ waitpid
    ◦ wait
    ◦ free
    ◦ pipe
    ◦ dup
    ◦ dup2
    ◦ execve
    ◦ fork
    ◦ perror
    ◦ strerror
    ◦ exit
