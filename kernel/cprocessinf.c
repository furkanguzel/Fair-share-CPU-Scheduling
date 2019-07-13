#include <linux/cprocessinf.h>
asmlinkage int sys_cprocessinf(struct prcdata *data,int option,int nicev){
	if(option==200){		//System call parametresine göre işlem yapılacak
		cli();				//Interruptlar kapatılıyor
		struct prcdata kernel_data; 	//kernel spacedeki structure tanımlanıyor
		int flag = copy_from_user(&kernel_data,data,sizeof(struct prcdata)); 		//user spacedeki alan kernel space'e kopyalanıyor
		if(flag == 0){					//User spacedeki alanın kopyalandığını test etmek için flag değeri
			kernel_data.prio = 20 - current->nice;									//
			kernel_data.weight = kernel_data.prio + current->counter;				//	
			kernel_data.pid = current->pid;											//Structuredaki gerekli alanlar dolduruluyor
			kernel_data.pidparent = current->p_pptr->pid;							//
			kernel_data.processcount = atomic_read(&current->user>processes);		//
			copy_to_user(data,&kernel_data,sizeof(struct prcdata));					//Kernel spacede doldurulan alan tekrar user space'e kopyalanıyor
			sti();			//Interruptlar tekrar açılıyor
			return 0;
		}
		else {					//User spacedeki alan kopyalanamazsa system call -1 döndürüyor
			sti();
			return -1;
		}
	}
	else {
		current->nice = nicev;  	//Process nice value fonksiyon parametresiyle değiştiriliyor
		return 0;
	}
}