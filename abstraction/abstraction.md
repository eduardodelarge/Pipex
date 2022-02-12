# Pipex

The abstraction here is quite straight forward, the pipe() works recieves inputs from the user and then create an output with the given commands.

The function pipe() recieves a single argument, which is and array with two integers and if everything works properly, the array will recieve two new file descriptors to be used for the pipeline. After creating a piipe, the process typically spawns a new process with fork().
