#### pipe

## OPERATION INVOLVED IN PIPE ARE 


- create the pipe 
- write the data into the pipe
- read data from the pipe

<mark>pipe()<mark> and <mark>pipe2()<mark> are used to create the pipe

### Description
pipe creates a pipe a unidirection data channel that can be used for INERT PROCESS COMMUNICATION, The array pipefd is used to return two file descriptor refering to the end of the pipe.

```bash
man pipe
```

## SYNOPSIS

```c
#include<unistd.h>

int pipe(int pipefd[2]);
```
## return value 

- on sucess  ->  0
- on failure -> -1


## LIMITATION OF PIPE
- Using pipe only related process can communicate(i.e child and parent process)
- There is no name is pipe system


Always the pipefd[0] is for the read of the pipe
Always the pipefd[1] is for the write of the pipe
The pipe is created in the kernal space 
