#include "../headers.h"
#include "declarations.h"
void* client_handler(void *arg)
{
	int ret,len,l_sfd;
	struct sockaddr_in clientSock;
	char buff[50];
#ifdef DEBUG
	printf("FILE:%s->%s:Begins\n",__FILE__,__func__);
#endif
	printf("sfd:%d\n",sfd);
	len = sizeof(clientSock);
	l_sfd = accept(sfd,(struct sockaddr*)&clientSock,&len);
	if(l_sfd == -1)
	{
		perror("accept");
		close(sfd);
		exit(EXIT_FAILURE);
	}
	sem_post(&psemID);//releasing the sempahore lock
	ret = read(l_sfd,buff,50);
	if(ret == -1)
	{
		perror("read");
		close(sfd);
		exit(EXIT_FAILURE);
	}
	printf("request from client:%s\n",buff);

#ifdef DEBUG
	printf("FILE:%s->%s:End\n",__FILE__,__func__);
#endif
	return 0;
}
