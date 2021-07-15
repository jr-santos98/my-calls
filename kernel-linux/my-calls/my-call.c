#include <linux/kernel.h>
#include <linux/syscalls.h>

/*
 * Add getuserweight() and setuserweight()
 */
int weights[65536] = {[0 ... 65535] = 10};
SYSCALL_DEFINE1(getuserweight, int, uid)
{
	printk("Entrou na função com o user %d\n", uid);
	printk("O usuário é uid: %d\n", current_uid().val);
	if(uid < -1 || uid > 65535)
		return  -EINVAL;
	if(uid == -1)
		uid = current_uid().val;
	return weights[uid];
}
SYSCALL_DEFINE2(setuserweight, int, uid, int, weight)
{
    printk("Entrou na função com o user %d\n", uid);
	printk("O usuário é uid: %d\n", current_uid().val);
	if(current_uid().val != 0)
		return -EACCES;
	if(uid < -1 || uid > 65535 || weight <= 0)
		return -EINVAL;
	if(uid == -1)
		uid = current_uid().val;
    printk("A prioridade do usuário foi para: %d\n", weight);
	weights[uid] = weight;
	return 0;
}

