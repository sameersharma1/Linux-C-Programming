#include<linux/kernel.h>
#include<linux/module.h>

static int __init hello_init(void)
{
	printk(KERN_ALERT "Hi This is init module\n");
	
	return 0;
}

static void __exit hello_exit(void)
{
	printk(KERN_ALERT "Hi This is exit module\n");
}
module_init(hello_init);
module_exit(hello_exit);
