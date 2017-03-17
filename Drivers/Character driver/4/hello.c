#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/version.h>
#include<linux/fs.h>
#include<linux/types.h>
#include<linux/kdev_t.h>

static dev_t first = MKDEV(450,0);

static int ofcd_init(void)
{
	printk(KERN_ALERT "This is init function ");

	if(register_chrdev_region(first,3,"sameer")<0)
	{
		return -1;
	}
	
	printk(KERN_ALERT "We have successfully registered our device with Major %d Minor %d\n",MAJOR(first),MINOR(first));
	
	return 0;
}

static void ofcd_exit(void)
{
	unregister_chrdev_region(first,3);

	printk(KERN_ALERT "This is exit module of ofcd driver\n");
}

module_init(ofcd_init);
module_exit(ofcd_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Our first character driver");
MODULE_AUTHOR("Sameer Sharma");
