/*
 * Copyright (C) 2013 Samsung Electronics
 * Hyungwon Hwang <human.hwang@samsung.com>
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#ifndef __CONFIG_ODROID_XU3_H
#define __CONFIG_ODROID_XU3_H

#include "exynos5420-common.h"
#include <configs/exynos5-common.h>

#undef CONFIG_ENV_IS_IN_SPI_FLASH

#define CONFIG_BOARD_COMMON

#define CONFIG_SYS_SDRAM_BASE		0x40000000
#define CONFIG_SYS_TEXT_BASE		0x43E00000

/* select serial console configuration */
#define CONFIG_SERIAL2			/* use SERIAL 2 */

#define TZPC_BASE_OFFSET		0x10000

#define CONFIG_NR_DRAM_BANKS	8
#define SDRAM_BANK_SIZE		(256UL << 20UL)	/* 256 MB */
/* Reserve the last 22 MiB for the secure firmware */
#define CONFIG_SYS_MEM_TOP_HIDE		(22UL << 20UL)
#define CONFIG_TZSW_RESERVED_DRAM_SIZE	CONFIG_SYS_MEM_TOP_HIDE

#define CONFIG_ENV_IS_IN_MMC

#undef CONFIG_ENV_SIZE
#undef CONFIG_ENV_OFFSET
#define CONFIG_ENV_SIZE			(SZ_1K * 16)
#define CONFIG_ENV_OFFSET		(SZ_1K * 3136) /* ~3 MiB offset */

#define CONFIG_SYS_INIT_SP_ADDR        (CONFIG_SYS_LOAD_ADDR - 0x1000000)

#define CONFIG_DEFAULT_CONSOLE		"console=ttySAC2,115200n8\0"

/* USB */
#define CONFIG_USB_EHCI
#define CONFIG_USB_EHCI_EXYNOS

/* DFU */
#define CONFIG_SYS_DFU_DATA_BUF_SIZE	SZ_32M
#define DFU_DEFAULT_POLL_TIMEOUT	300
#define DFU_MANIFEST_POLL_TIMEOUT       25000

/* THOR */
#define CONFIG_G_DNL_THOR_VENDOR_NUM	CONFIG_G_DNL_VENDOR_NUM
#define CONFIG_G_DNL_THOR_PRODUCT_NUM	0x685D
#define CONFIG_USB_FUNCTION_THOR
#define CONFIG_CMD_THOR_DOWNLOAD

/* UMS */
#define CONFIG_G_DNL_UMS_VENDOR_NUM	0x0525
#define CONFIG_G_DNL_UMS_PRODUCT_NUM	0xA4A5
#define CONFIG_USB_FUNCTION_MASS_STORAGE

/* FIXME: MUST BE REMOVED AFTER TMU IS TURNED ON */
#undef CONFIG_EXYNOS_TMU
#undef CONFIG_TMU_CMD_DTT

#define CONFIG_DFU_ALT_SYSTEM               \
	"uImage fat 0 1;"                   \
	"zImage fat 0 1;"                   \
	"Image.itb fat 0 1;"                \
	"uInitrd fat 0 1;"                  \
	"boot.scr fat 0 1;"                 \
	"boot.cmd fat 0 1;"                 \
	"exynos5422-odroidxu3.dtb fat 0 1;" \
	"exynos5422-odroidxu3-lite.dtb fat 0 1;" \
	"exynos5422-odroidxu4.dtb fat 0 1;" \
	"boot part 0 1;"                    \
	"root part 0 2\0"

#define CONFIG_DFU_ALT_BOOT_EMMC           \
	"u-boot raw 0x3e 0x800 mmcpart 1;" \
	"bl1 raw 0x0 0x1e mmcpart 1;"      \
	"bl2 raw 0x1e 0x1d mmcpart 1;"     \
	"tzsw raw 0x83e 0x200 mmcpart 1;"  \
	"params.bin raw 0x1880 0x20\0"

#define CONFIG_DFU_ALT_BOOT_SD   \
	"u-boot raw 0x3f 0x800;" \
	"bl1 raw 0x1 0x1e;"      \
	"bl2 raw 0x1f 0x1d;"     \
	"tzsw raw 0x83f 0x200;"  \
	"params.bin raw 0x1880 0x20\0"

/* Enable: board/samsung/common/misc.c to use set_dfu_alt_info() */
#define CONFIG_MISC_COMMON
#define CONFIG_MISC_INIT_R
#define CONFIG_SET_DFU_ALT_INFO
#define CONFIG_SET_DFU_ALT_BUF_LEN	(SZ_1K)

/* Set soc_rev, soc_id, board_rev, boardname, fdtfile */
#define CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG
#define CONFIG_ODROID_REV_AIN			9
#define CONFIG_REVISION_TAG
#define CONFIG_BOARD_TYPES

#undef CONFIG_SYS_BOARD
#define CONFIG_SYS_BOARD	"odroid"

/* Define new extra env settings, including DFU settings */
#undef CONFIG_EXTRA_ENV_SETTINGS
#define CONFIG_EXTRA_ENV_SETTINGS \
	EXYNOS_DEVICE_SETTINGS \
	EXYNOS_FDTFILE_SETTING \
	MEM_LAYOUT_ENV_SETTINGS \
	BOOTENV \
	"bootdelay=0\0" \
	"rootfstype=ext4\0" \
	"console=" CONFIG_DEFAULT_CONSOLE \
	"fdtfile=exynos5422-odroidxu3.dtb\0" \
	"boardname=odroidxu3\0" \
	"mmcbootdev=0\0" \
	"mmcrootdev=0\0" \
	"mmcbootpart=1\0" \
	"mmcrootpart=2\0" \
	"dfu_alt_system="CONFIG_DFU_ALT_SYSTEM \
	"dfu_alt_info=Autoset by THOR/DFU command run.\0"

#define CONFIG_CMD_INI
#endif	/* __CONFIG_H */
