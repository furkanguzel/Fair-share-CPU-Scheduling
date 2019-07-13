#include <linux/unistd.h> // trap table
#include <linux/types.h> // pid_t değişkeni
#include <errno.h>
extern int errno;
_syscall3(int,cprocessinf,struct prcdata *,data,int,option,int,nicev);
struct prcdata
{
	long prio;
	long weight;
	pid_t pid;
	pid_t pidparent;
	int processcount;
};