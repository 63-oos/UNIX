#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main(){
int fd[2],cnt = 0;
if(pipe(fd)<0){
perror("pipe");
return 0;
}
printf("fd[0] = %d fd[1] = %d\n",fd[0],fd[1]);
if(fork()==0){
char a[20];
printf("child is writing to the pipe:  \n");
scanf("%s",a);
write(fd[1],a,strlen(a)+1);
}
else{
char b[20];
printf("parent is reaind from the pipe...\n");
read(fd[0],b,sizeof(b));
printf("%s",b);
}
}
