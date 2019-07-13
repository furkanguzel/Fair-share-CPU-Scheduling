#include <linux/cprocessinf.h>

main(){
	struct prcdata data;
	cprocessinf(&data,200,5);
	printf("Process priority: %li\n",data.prio);
	printf("Process weight: %li\n",data.weight);
	printf("Process ID: %d\n",data.pid);
	printf("Parent process ID: %d\n",data.pidparent);
	printf("Current user's process count: %d\n\n\n",data.processcount);
	cprocessinf(&data,100,13);
	cprocessinf(&data,200,9);
	printf("Process priority: %li\n",data.prio);
	printf("Process weight: %li\n",data.weight);
	printf("Process ID: %d\n",data.pid);
	printf("Parent process ID: %d\n",data.pidparent);
	printf("Current user's process count: %d\n",data.processcount);
	execl("/bin/ps","ps","aux",0);
}