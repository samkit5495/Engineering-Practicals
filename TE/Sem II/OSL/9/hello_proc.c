/*
                Assigment 9
                File System
Name - Samkitkumar H. Jain
Date of Performance : 12/03/16

Implementing a file system in a Linux OS.

*/
#include<linux/module.h>
#include<linux/proc_fs.h>
#include<linux/seq_file.h>

static int hello_proc_show(struct seq_file *m,void *v)
{
	seq_printf(m,"Hello World!!!\n");
//	#include<linux/seq_file.h>
	return 0;
}

static int hello_proc_open(struct inode *inode,struct file *file)
{
	return single_open(file,hello_proc_show,NULL);
//	return single_open(struct file *,int (*) (struct seq_file *,void*),void *);
//	#include<linux/seq_file.h>
}

static const struct file_operations hello_proc_fops={
	.owner=THIS_MODULE,
	.open=hello_proc_open,
	.read=seq_read,
	.llseek=seq_lseek,
	.release=single_release,
};

static int __init hello_proc_init(void)
{
	proc_create("hello_proc",0,NULL,&hello_proc_fops);
//	proc_create(const char *name,umode_t mode,struct proc_dir_entry *parent,const struct file_operations *proc_fops);
//	#include<linux/proc_fs.h>
	return 0;
}

static void __exit hello_proc_exit(void)
{
	remove_proc_entry("hello_proc",NULL);
//	remove_proc_entry(const char *name,struct proc_dir_entry *parent)
//	#include<linux/proc_fs.h>
}

MODULE_LICENSE("GPL");
module_init(hello_proc_init);
module_exit(hello_proc_exit);
