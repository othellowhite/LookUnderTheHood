#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/timer.h>
#include <linux/jiffies.h>
 
static void mykmod_timer_handler(unsigned long data);
static unsigned long onesec;
static unsigned long tick;
 
DEFINE_TIMER(mytimer, mykmod_timer_handler, 0, 0);
 

static void
mykmod_timer_handler(unsigned long data)
{
        //unsigned long j = jiffies;
        //pr_info("mykmod timer %u jiffies\n", (unsigned)j);
 	pr_info("%u seconds elapsed\n", (unsigned)tick++);

        mod_timer(&mytimer, jiffies + onesec);
}
 
 
static int mykmod_init(void)
{
        //unsigned long j = jiffies;
 
        onesec = msecs_to_jiffies(1000 * 1);
	
	tick = 0;
 
        //pr_info("mykmod loaded %u/%u jiffies before\n", (unsigned)j, (unsigned)onesec);
 
        mod_timer(&mytimer, jiffies + onesec);
 
        //pr_info("mykmod loaded %u jiffies after \n", (unsigned)j);
 
	printk(KERN_INFO "Hello, World!\n");

        return 0;
}
 
static void mykmod_exit(void)
{
        del_timer(&mytimer);
        pr_info("mykmod exit\n");
	printk(KERN_INFO "Goodbye\n");
}
 
module_init(mykmod_init);
module_exit(mykmod_exit);
 
MODULE_DESCRIPTION("mykmod");
MODULE_LICENSE("GPL");