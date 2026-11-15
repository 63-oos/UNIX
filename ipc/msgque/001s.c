/*
 * message queue
 * message sender 
 * 
 *
 *
 */
#include<stdio.h>
#include<string.h>
#include<sys/msg.h>
#include<stdlib.h>
struct msgbuf
{
	long mtype;
	char mtext[20];
};
int main(int argc,char**argv)
{
	if(argc!=3)
	{
		printf("./a.out <msgtype> <message>\n");
		return 0;
	}
	int msgid;
	struct msgbuf v;
	msgid = msgget(5,IPC_CREAT|0644);
	if(msgid<0)
	{
		perror("msgget");
		return 0;
	}
	printf("msgid =>%d\n",msgid);
	v.mtype = atoi(argv[1]);
	strcpy(v.mtext,argv[2]);
	if(msgsnd(msgid,&v,strlen(v.mtext)+1,0)==-1)//msgsnd(msgid,&message,size,)
	{
		perror("msgsnd");
		return 0;
	}
	printf("message sent sucessfully....\n");
	return 0;
}
