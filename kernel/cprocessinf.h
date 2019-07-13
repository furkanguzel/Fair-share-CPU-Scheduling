#ifndef __LINUX_CPROCESSINF_H
#define __LINUX_CPROCESSINF_H
#include <linux/linkage.h>
#include <linux/types.h> // pid_t değişkeni
#include <linux/sched.h> // task_struct
#include <asm/current.h> // currrent pointer
#include <asm/uaccess.h> // copy_to-from_user system call
struct prcdata
{
	long prio;
	long weight;
	pid_t pid;
	pid_t pidparent;
	int processcount;
};
#endif