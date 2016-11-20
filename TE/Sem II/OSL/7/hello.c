/*
                Assigment 7
                Kernel Space Programming
Name - Samkitkumar H. Jain
Date of Performance : 09/03/16

KERN_INFO
Informational messages. Many drivers print information about the hardware they find at startup time at this level.
*/
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Samkitkumar Jain");
MODULE_DESCRIPTION("A Simple Hello World Program!!!");

static int __init hello_init(void)
{
	printk(KERN_INFO "Hello World!\n");
	return 0;
}

static void __exit hello_cleanup(void)
{
	printk(KERN_INFO "Good Bye.\n");
}

module_init(hello_init);
module_exit(hello_cleanup);
