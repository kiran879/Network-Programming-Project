#include "../headers.h"
#include "declarations.h"
sem_t psemID;
int sfd;
int createInfra();
void* client_handler(void*);
int main()
{
	pthread_t c_thread;
	int ret;
#ifdef DEBUG
	printf("FILE:%s->%s:Begins\n",__FILE__,__func__);
#endif
	createInfra();//creates socket, socket listen queue, and P_semaphore
	while(1)
	{
		sem_wait(&psemID);//acquiring the semaphore lock
		ret = pthread_create(&c_thread,NULL,client_handler,0);
		if(ret)
		{
			printf("Error: thread creation failed with errno:%d\n",ret);
			exit(EXIT_FAILURE);
		}
		printf("pthread created successfully\n");
	}

#ifdef DEBUG
	printf("FILE:%s->%s:End\n",__FILE__,__func__);
#endif
	return 0;
}
