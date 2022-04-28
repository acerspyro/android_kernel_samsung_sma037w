// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (c) 2020 MediaTek Inc.
 */
#include <linux/kernel.h>
#include "cam_cal_list.h"
#include "eeprom_i2c_common_driver.h"
#include "eeprom_i2c_custom_driver.h"
#include "kd_imgsensor.h"
#include "eeprom_i2c_hi556_txd_driver.h"
#include "eeprom_i2c_gc5035_ly_driver.h"
#include "eeprom_i2c_gc02m1_cxt_driver.h"
#include "eeprom_i2c_ov02b10_ly_driver.h"
/* A03s code for SR-AL5625-01-332 by xuxianwei at 2021/05/07 start */
#include "eeprom_i2c_hi556_ofilm_driver.h"
#include "eeprom_i2c_gc5035_dd_driver.h"
/* A03s code for SR-AL5625-01-332 by xuxianwei at 2021/05/07 end */
/* A03s code for CAM-AL5625-01-247 by majunfeng at 2021/05/25 start */
#include "eeprom_i2c_gc5035_xl_driver.h"
/*A03s code for CAM-AL5625-01-247 by majunfeng at 2021/05/25 end */
/* A03s code for SR-AL5625-01-324 by wuwenjie at 2021/06/28 start */
#include "eeprom_i2c_gc02m1_jk_driver.h"
/* A03s code for SR-AL5625-01-324 by wuwenjie at 2021/06/28 end */
#define MAX_EEPROM_SIZE_16K 0x4000

struct stCAM_CAL_LIST_STRUCT g_camCalList[] = {
	/*Below is commom sensor */
	/* A03s code for CAM-AL5625-01-247 by lisizhou at 2021/04/28 start */
	{HI1336_TXD_SENSOR_ID, 0xA0, Common_read_region},
	{HI1336_HLT_SENSOR_ID, 0xA0, Common_read_region},
	{GC13053_LY_SENSOR_ID, 0xA0, Common_read_region},
	/* hs03s code for SR-AL5625-01-247 by majunfeng at 2021/06/07 start  */
	{S5K3L6_OFILM_SENSOR_ID, 0xA0, Common_read_region},
	{OV13B10_QT_SENSOR_ID, 0xA0, Common_read_region},
	{OV13B10_DD_SENSOR_ID, 0xA0, Common_read_region},
	{OV13B10_XL_SENSOR_ID, 0xA0, Common_read_region},
	/* hs03s code for SR-AL5625-01-247 by majunfeng at 2021/06/07 end  */
	/* A03s code for CAM-AL5625-01-247 by lisizhou at 2021/04/28 end */
/* A03s code for SR-AL5625-01-332 by xuxianwei at 2021/05/02 start */
	{HI556_TXD_SENSOR_ID, 0x50, hi556_txd_read_region},
/* A03s code for SR-AL5625-01-332 by xuxianwei at 2021/05/07 start */
	{HI556_OFILM_SENSOR_ID, 0x40, hi556_ofilm_read_region},
        {GC5035_DD_SENSOR_ID, 0x6e, gc5035_dd_read_region},
        {GC5035_LY_SENSOR_ID, 0x6e, gc5035_ly_read_region},
/* A03s code for SR-AL5625-01-332 by xuxianwei at 2021/05/07 end */

/* A03s code for SR-AL5625-01-332 by xuxianwei at 2021/05/02 end */
/* A03s code for SR-AL5625-01-324 by wuwenjie at 2021/05/06 start */
	{GC02M1_CXT_SENSOR_ID, 0x6E, gc02m1_cxt_read_region},
	{OV02B10_LY_SENSOR_ID, 0x7A, ov02b10_ly_read_region},
/* A03s code for SR-AL5625-01-324 by wuwenjie at 2021/04/06 end */
/* A03s code for SR-AL5625-01-324 by wuwenjie at 2021/06/28 start */
        {GC02M1_JK_SENSOR_ID, 0x6E, gc02m1_jk_read_region},
/* A03s code for SR-AL5625-01-324 by wuwenjie at 2021/06/28 end */
/* A03s code for CAM-AL5625-01-247 by majunfeng at 2021/05/25 start */
{GC5035_XL_SENSOR_ID, 0x6e, gc5035_xl_read_region},
/* A03s code for CAM-AL5625-01-247 by majunfeng at 2021/05/25 end */


	{IMX230_SENSOR_ID, 0xA0, Common_read_region},
	{S5K2T7SP_SENSOR_ID, 0xA4, Common_read_region},
	{IMX338_SENSOR_ID, 0xA0, Common_read_region},
	{S5K4E6_SENSOR_ID, 0xA8, Common_read_region},
	{IMX386_SENSOR_ID, 0xA0, Common_read_region},
	{S5K3M3_SENSOR_ID, 0xA0, Common_read_region},
	{S5K2L7_SENSOR_ID, 0xA0, Common_read_region},
	{IMX398_SENSOR_ID, 0xA0, Common_read_region},
	{IMX318_SENSOR_ID, 0xA0, Common_read_region},
	{OV8858_SENSOR_ID, 0xA8, Common_read_region},
	{IMX386_MONO_SENSOR_ID, 0xA0, Common_read_region},
	/*B+B*/
	{S5K2P7_SENSOR_ID, 0xA0, Common_read_region},
	{OV8856_SENSOR_ID, 0xA0, Common_read_region},
	/*61*/
	{IMX499_SENSOR_ID, 0xA0, Common_read_region},
	{S5K3L8_SENSOR_ID, 0xA0, Common_read_region},
	{S5K5E8YX_SENSOR_ID, 0xA2, Common_read_region},
	/*99*/
	{IMX258_SENSOR_ID, 0xA0, Common_read_region},
	{IMX258_MONO_SENSOR_ID, 0xA0, Common_read_region},
	/*97*/
	{OV23850_SENSOR_ID, 0xA0, Common_read_region},
	{OV23850_SENSOR_ID, 0xA8, Common_read_region},
	{S5K3M2_SENSOR_ID, 0xA0, Common_read_region},
	/*55*/
	{S5K2P8_SENSOR_ID, 0xA2, Common_read_region},
	{S5K2P8_SENSOR_ID, 0xA0, Common_read_region},
	{OV8858_SENSOR_ID, 0xA2, Common_read_region},
	/* Others */
	{S5K2X8_SENSOR_ID, 0xA0, Common_read_region},
	{IMX377_SENSOR_ID, 0xA0, Common_read_region},
	{IMX214_SENSOR_ID, 0xA0, Common_read_region},
	{IMX214_MONO_SENSOR_ID, 0xA0, Common_read_region},
	{IMX486_SENSOR_ID, 0xA8, Common_read_region},
	{OV12A10_SENSOR_ID, 0xA8, Common_read_region},
	{OV13855_SENSOR_ID, 0xA0, Common_read_region},
	{S5K3L8_SENSOR_ID, 0xA0, Common_read_region},
	{HI556_SENSOR_ID, 0x51, Common_read_region},
	{S5K5E8YX_SENSOR_ID, 0x5a, Common_read_region},
	{S5K5E8YXREAR2_SENSOR_ID, 0x5a, Common_read_region},
	{S5KGM2_SENSOR_ID, 0xB0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{S5K2P6_SENSOR_ID, 0xB0, Common_read_region, MAX_EEPROM_SIZE_16K},
	{GC5035_SENSOR_ID, 0x7E, Otp_read_region_GC5035,
		DEFAULT_MAX_EEPROM_SIZE_8K},
	{GC02M1_SENSOR_ID, 0xA4, Common_read_region},
	{GC02M1_SENSOR_ID1, 0x6E, Otp_read_region_GC02M1B,
		DEFAULT_MAX_EEPROM_SIZE_8K},
	{SR846_SENSOR_ID, 0x40, Otp_read_region_SR846,
		DEFAULT_MAX_EEPROM_SIZE_8K},
	/*  ADD before this line */
	{0, 0, 0}       /*end of list */
};

unsigned int cam_cal_get_sensor_list(
	struct stCAM_CAL_LIST_STRUCT **ppCamcalList)
{
	if (ppCamcalList == NULL)
		return 1;

	*ppCamcalList = &g_camCalList[0];
	return 0;
}

