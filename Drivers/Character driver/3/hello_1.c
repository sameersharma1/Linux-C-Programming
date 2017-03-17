#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>

static int hello_4_data = 10;

static int __init hello_4_init(void)
{
	printk(KERN_ALERT "This is hello 4 module init function and it's data is %d\n",hello_4_data);
	
	return 0;
}

static void __exit hello_4_exit(void)
{
	printk(KERN_ALERT "This is hello 4 module exit function and it's data is %d\n",hello_4_data);
}

module_init(hello_4_init);
module_exit(hello_4_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sameer Sharma");
MODULE_DESCRIPTION("This is hello world module.");
