#include 	<linux/module.h>
#include 	<linux/kernel.h>
#include 	<linux/init.h>
#include 	<linux/fs.h>

#define DEVICE_NAME "gwj"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("GaoWenjing");
MODULE_DESCRIPTION("GWJ testing modules");
MODULE_VERSION("1.0");

static int Major;
static int m_open(struct inode *, struct file *);
static int m_release(struct inode *, struct file *);
static ssize_t m_read(struct file *, char __user *, size_t, loff_t *);
static ssize_t m_write(struct file *, const char __user *, size_t, loff_t *);

static struct file_operations m_opts = {
	read: m_read,
	write: m_write,
	open: m_open,
	release: m_release
};

static int m_open(struct inode *inode, struct file *file){
	return 0;
};
static int m_release(struct inode *inode, struct file *file){
	return 0;
};
static ssize_t m_read(struct file *file, char __user *buf, size_t lenght, loff_t *offset){
	return 0;
};
static ssize_t m_write(struct file *file, const char __user *buf, size_t lenght, loff_t *offset){
	return 0;
};
static int m_init(void){
	printk("Yello.\n");
	Major = register_chrdev(0, DEVICE_NAME, &m_opts);
	printk("Major number:%i", Major);
	return 0;
}

static void m_exit(void){
	unregister_chrdev(Major, DEVICE_NAME);
	printk(KERN_ALERT "Goodbye,cruel world.\n");
}

module_init(m_init);
module_exit(m_exit);

