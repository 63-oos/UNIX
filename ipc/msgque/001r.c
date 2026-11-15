/*
 * message queue
 * message reader
 * 
 *
 * msgtype>0- receive the first message having the particular type 
 * msgtype=0- receive the first message in the queue
 * msgtype<0- receive the message with the lowest tyoe less than less than or eqaul to absolute value of msgtype
 *
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/msg.h>
struct msgbuf
{
	long mtype;
	char mtext[20];
};
int main()
{
	int msgid;
	struct msgbuf v;
	msgid = msgget(5,IPC_CREAT|0644);
	if(msgid<0)
	{
		perror("msgget");
		return 0;
	}

	printf("msgid=>%d\n",msgid);

	if(msgrcv(msgid,&v,sizeof(v.mtext),0,0)==-1)//msgrcv(msgid,&message,size,msgtype,flags)
	{
		perror("msgrcv");
		return 0;
	}
	printf("msg type : %ld\n",v.mtype);
	printf("msg = %s\n",v.mtext);
}
