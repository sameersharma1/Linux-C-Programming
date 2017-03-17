#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/types.h>
#include<linux/version.h>
#include<linux/kdev_t.h>
#include<linux/device.h>
#include<linux/cdev.h>

static dev_t first = MKDEV(350,0);
static int major;

static int my_open(struct inode *i, struct file *f)
{
	printk(KERN_ALERT "Driver Open():\n");
	return 0;
}

static int my_release(struct inode *i, struct file *f)
{
	printk(KERN_ALERT "Driver Release():\n");
	return 0;
}

static ssize_t my_read(struct file *f, char __user *buf, size_t len, loff_t *off)
{
	printk(KERN_ALERT "My Read():\n");
	return 0;
}

static ssize_t my_write(struct file *f, const char __user *buf,size_t len, loff_t *off)
{
	printk(KERN_ALERT "My Write():\n");
	return len;
}

static struct file_operations my_fops={
	.owner= THIS_MODULE,
	.open = my_open,
	.read= my_read,
	.write = my_write,
	.release= my_release
};

static int ofcd4_init(void)
{
	printk(KERN_ALERT "ofcd 4 : This is ofcd 4 init module\n");
	major=register_chrdev(MAJOR(first),"sameer",&my_fops);
	return 0;
}

static void ofcd4_exit(void)
{
	unregister_chrdev(major,"sameer");
	printk(KERN_ALERT "ofcd 3 : This is ofcd 4 exit module\n");
}

module_init(ofcd4_init);
module_exit(ofcd4_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sameer Sharma");
MODULE_DESCRIPTION("This is ofcd4 kernel module");
