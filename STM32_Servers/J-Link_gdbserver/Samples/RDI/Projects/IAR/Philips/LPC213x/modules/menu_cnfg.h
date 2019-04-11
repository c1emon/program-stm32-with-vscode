#ifndef  __MENU_CONFIG_H
#define  __MENU_CONFIG_H

/*************************************************************************
 *
 *    Used with ICCARM and AARM.
 *
 *    (c) Copyright IAR Systems 2003
 *
 *    File name   : config.h
 *    Description : Define common defenition
 *
 *    History :
 *    1. Data        : Feb 10, 2005
 *       Author      : Stanimir Bonev
 *       Description : Create
 *
 *    $Revision: 1.1 $
 **************************************************************************/

#include "includes.h"

/* USER Menu Index definition */
typedef enum
{
  MENU_WELCOME_SHOW = 0,    /*0 Welcome */
  MENU_CLOCK_AND_DATA_SET,  /*1 Clock and data setting */
  MENU_ILLUMINATION_SET,    /*2 Illumination set */
  MENU_ADC_MEASURE,         /*3 ADC measuge */
  MENU_RETURN,              /*4 Return to main */
  MENU_TIME_AND_DATA_SHOW,  /*5 Data and chock show */
  MENU_SCREENSAVER_SHOW,    /*6 ScreanSaver show */
  MENU_SLEEP_SHOW,          /*7 Low power (sleep) show */
  MENU_CLOCK_SET_RETURN,    /*8 Clock and data set return to menu */
  MENU_ILLUM_MODE_CHANGE,   /*9 Illumination set return to menu */
  MENU_LAST_IND             /* Last menu index */
} MENU_IND_NAME_DEF;

/* USER Event definition */
typedef enum
{
  /* 0 is reserv for internal using */
  MENU_TICK_EVENT = 1,  /* SYS TICK */
  MENU_EVENT_B1_SHORT_PRESS,
  MENU_EVENT_B2_SHORT_PRESS,
  MENU_EVENT_TIME_UPDATE,
  MENU_EVENT_LOW_POWER,
  MENU_EVENT_ADC_CONV,
} MENU_EVENT_NAME_DEF;

/* User Language definition */
typedef enum
{
  MENU_ENGLISH_LANG = 0,  /*0 English language */
} MENU_LANGUAGE_NAME_DEF;

/* Menu time out definition */
#define MENU_WELCOM_DLY         3 *TICK_PER_SECOND    /* 3 sec */
#define MENU_SCREEN_SAVER_DLY   5*TICK_PER_SECOND     /* 10 sec */
#define MENU_TO_DLY             10*TICK_PER_SECOND    /* 10 sec */
#define MENU_LOW_POWER_DLY      20*TICK_PER_SECOND    /* 20 sec */

/* Common menu definictions */
#define MENU_EVENT_STACK_SIZE 5

#define MENU_LANGUAGE_NUMBER  1

#define MENU_MAX_INDEX        MENU_LAST_IND

#define MENU_MAX_EVENT_NUBER  256

#define MENU_MAX_STR_LENG     40

#define MENU_MAX_VISIBILITY_X 16
#define MENU_MAX_VISIBILITY_Y 2

#define MEMU_MAX_TIME_OUT     1000

/* Menu Events type def */
#if MENU_MAX_EVENT_NUBER < 256
#define MENU_EVENT_TYPE_DEF LPC_INT8U
#elif MENU_MAX_EVENT_NUBER < 65536
#define MENU_EVENT_TYPE_DEF LPC_INT16U
#elif MENU_LANGUAGE_NUMBER < 0x100000000
#define MENU_EVENT_TYPE_DEF LPC_INT32U
#else
#error "MENU_MAX_EVENT_NUBER is to large number > 32bit!!!"
#endif

/* Menu Language type def */
#if MENU_LANGUAGE_NUMBER < 256
#define MENU_LANG_TYPE_DEF LPC_INT8U
#elif MENU_LANGUAGE_NUMBER < 65536
#define MENU_LANG_TYPE_DEF LPC_INT16U
#elif MENU_LANGUAGE_NUMBER < 0x100000000
#define MENU_LANG_TYPE_DEF LPC_INT32U
#else
#error "MENU_LANGUAGE_NUMBER is to large number > 32bit!!!"
#endif

/* Menu Index type def */
#if MENU_MAX_INDEX < 256
#define MEMU_IND_DEF LPC_INT8U
#elif MENU_MAX_INDEX < 65536
#define MEMU_IND_DEF LPC_INT16U
#elif MENU_MAX_INDEX < 0x100000000
#define MEMU_IND_DEF LPC_INT32U
#else
#error "MENU_MAX_INDEX is to large number > 32bit!!!"
#endif

/* XY coourdinate type def */
#if ((MENU_MAX_VISIBILITY_X < 256) && (MENU_MAX_VISIBILITY_Y < 256))
#define MEMU_XY_DEF LPC_INT8U
#elif ((MENU_MAX_VISIBILITY_X < 65536) && (MENU_MAX_VISIBILITY_Y < 65536))
#define MEMU_XY_DEF LPC_INT16U
#elif ((MENU_MAX_VISIBILITY_X < 0x100000000) && (MENU_MAX_VISIBILITY_Y < 0x100000000))
#define MEMU_XY_DEF LPC_INT32U
#else
#error "X or Y is to large number > 32bit!!!"
#endif

/* time out type def */
#if MEMU_MAX_TIME_OUT < 255
#define MEMU_TIME_OUT_DEF LPC_INT8U
#define MENU_TIME_OUT_NOT_UPADATE 255
#elif MEMU_MAX_TIME_OUT < 65535
#define MEMU_TIME_OUT_DEF LPC_INT16U
#define MENU_TIME_OUT_NOT_UPADATE 65535
#elif MEMU_MAX_TIME_OUT < 0xFFFFFFFF
#define MEMU_TIME_OUT_DEF LPC_INT32U
#define MENU_TIME_OUT_NOT_UPADATE 0xFFFFFFFF
#else
#error "Menu Time out is to large number > 32bit!!!"
#endif

#endif  /* __MENU_CONFIG_H */
