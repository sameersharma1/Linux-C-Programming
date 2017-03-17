#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/types.h>
#include<linux/kdev_t.h>
#include<linux/version.h>

static dev_t first;

static int ofcd1_init(void)
{
	printk(KERN_ALERT "This is ofcd driver init function\n");

	if(alloc_chrdev_region(&first,0,3,"sameer")<0)
	{
		return -1;
	}

	printk(KERN_ALERT "We have successfully registered Major %d and Minor %d\n",MAJOR(first),MINOR(first));
	
	return 0;
}

static void ofcd1_exit(void)
{
	unregister_chrdev_region(first,3);
	
	printk(KERN_ALERT "This is ofcd driver exit function\n");
}

module_init(ofcd1_init);
module_exit(ofcd1_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sameer Sharma");
MODULE_DESCRIPTION("This is ofcd1 driver");
