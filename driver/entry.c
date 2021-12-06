/*===================================================================
 * Copyright(c) AVerMedia TECHNOLOGIES, Inc. 2017
 * All rights reserved
 * =================================================================
 * entry.c
 *
 *  Created on: Apr 15, 2017
 *      Author: 
 *      Version:
 * =================================================================
 */
 
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/version.h>
#include <linux/pci.h>
#include "aver_version.h"
#include "board.h"

//#define DRIVER_VER "1.0.0026"
//int board_init(void);
//void board_exit(void);

char *no_signal_pic = NULL;
module_param(no_signal_pic, charp, 0444);
MODULE_PARM_DESC(no_signal_pic, "Loading this bitmap file and display it when the input is no signal");

//char *out_of_range_pic = NULL;
//module_param(out_of_range_pic, charp, 0444);
//MODULE_PARM_DESC(out_of_range_pic, "Loading this bitmap file and display it when the content is out of range");

char *copy_protetion_pic = NULL;
module_param(copy_protetion_pic, charp, 0444);
MODULE_PARM_DESC(copy_protetion_pic, "Loading this bitmap file and display it when the content was protected");

static int __init aver_init(void)
{
    int ret=0;

    ret = board_init();
    return ret;
}

static void __exit aver_fini(void)
{
	board_exit();
}

module_init(aver_init);
module_exit(aver_fini);

MODULE_VERSION(DRIVER_VER);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Driver for gc573 capture card" " v" DRIVER_VER);
MODULE_AUTHOR("AVerMedia Tech. Inc.");


static struct pci_device_id aver_ids[  ] = {
    { PCI_DEVICE(0x1461, 0x0054) },
    { 0, },
};

MODULE_DEVICE_TABLE(pci, aver_ids);

