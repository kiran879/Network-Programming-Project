#include"../headers.h"
#include "declarations.h"
int createInfra()
{
	int ret;
	struct sockaddr_in serverSock;

#ifdef DEBUG
	printf("FILE:%s->%s:Begins\n",__FILE__,__func__);
#endif
	//creating socket
	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(sfd==-1)
	{
		perror("socket");
		exit(EXIT_FAILURE);
	}
#ifdef DEBUG
	printf("Server Socket created successfully\n");
#endif
	//creating semaphore
	ret=sem_init(&psemID,0,1);
	if(ret==-1)
	{
		perror("sem_init");
		close(sfd);
		exit(EXIT_FAILURE);
	}
#ifdef DEBUG
	printf("Posix semaphore is created successfully\n");
#endif
	//naming the socket
	serverSock.sin_family = AF_INET;
	serverSock.sin_port = htons(5555);
	serverSock.sin_addr.s_addr = INADDR_ANY;
	ret = bind(sfd,(struct sockaddr*)&serverSock,(socklen_t)sizeof(struct sockaddr_in));
	if(ret == -1)
	{
		perror("bind");
		close(sfd);
		exit(EXIT_FAILURE);
	}
	//creating socket listen queue
	ret = listen(sfd,5);
	if(ret == -1)
	{
		perror("listen");
		close(sfd);
		exit(EXIT_FAILURE);
	}
#ifdef DEBUG
	printf("Sucess! bind and listen\n");
#endif

#ifdef DEBUG
	printf("FILE:%s->%s:End\n",__FILE__,__func__);
#endif
	return 0;
}
