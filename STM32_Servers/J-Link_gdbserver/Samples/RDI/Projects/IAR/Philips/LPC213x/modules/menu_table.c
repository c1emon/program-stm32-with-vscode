/*************************************************************************
 *
 *    Used with ICCARM and AARM.
 *
 *    (c) Copyright IAR Systems 2003
 *
 *    File name   : main.c
 *    Description : Define main module
 *
 *    History :
 *    1. Data        : Feb 10, 2005
 *       Author      : Stanimir Bonev
 *       Description : Create
 *
 *    $Revision: 1.1 $
 **************************************************************************/
#include "menu.h"
#include <user_func.h>

/**********************************************************************************
 *                              Action section
 **********************************************************************************/
/*
  Menu Action structure
  Pos1 EventType
  Pos2 MenuIndex
  Pos3 Menu Time out (0 - time out is disable)
  Pos4 Pointer to String (Variable String)
  Pos5 Pointer to User Function (UserFunc(MEMU_STING_DEF * pVarArg,MEMU_IND_DEF * MenuIndex))
*/

/* Arg formate */
const MEMU_STING_DEF ArgFormate [] = "                \2                \2";

/* Welcom */
const MENU_ACTION_SHAIN_DEF MenuActionEventChain0 [] =
{
  {MENU_TICK_EVENT,MENU_TIME_AND_DATA_SHOW,MENU_SCREEN_SAVER_DLY,(MEMU_STING_DEF *)ArgFormate,GetTimeAndData,NULL},
  {0,0,MENU_TIME_OUT_NOT_UPADATE,(MEMU_STING_DEF *)ArgFormate,NULL,NULL},
};

/* Clock and Data setup */
const MENU_ACTION_SHAIN_DEF MenuActionEventChain1 [] =
{
  {MENU_TICK_EVENT,MENU_TIME_AND_DATA_SHOW,MENU_SCREEN_SAVER_DLY,(MEMU_STING_DEF *)ArgFormate,GetTimeAndData,NULL},
  {MENU_EVENT_B1_SHORT_PRESS,MENU_RETURN,MENU_TO_DLY,NULL,NULL,NULL},
  {MENU_EVENT_B2_SHORT_PRESS,MENU_CLOCK_SET_RETURN,MENU_TO_DLY,NULL,NULL,NULL},
  {0,0,MENU_TIME_OUT_NOT_UPADATE,NULL,NULL,NULL},
};

/* Illumination setup */
const MENU_ACTION_SHAIN_DEF MenuActionEventChain2 [] =
{
  {MENU_TICK_EVENT,MENU_TIME_AND_DATA_SHOW,MENU_SCREEN_SAVER_DLY,(MEMU_STING_DEF *)ArgFormate,GetTimeAndData,NULL},
  {MENU_EVENT_B1_SHORT_PRESS,MENU_CLOCK_AND_DATA_SET,MENU_TO_DLY,NULL,NULL,NULL},
  {MENU_EVENT_B2_SHORT_PRESS,MENU_ILLUM_MODE_CHANGE,MENU_TO_DLY,NULL,IlluminationShow,IlluminationModeCursorOn},
  {0,0,MENU_TIME_OUT_NOT_UPADATE,NULL,NULL,NULL},
};

/* Adc measure */
const MENU_ACTION_SHAIN_DEF MenuActionEventChain4 [] =
{
  {MENU_TICK_EVENT,MENU_TIME_AND_DATA_SHOW,MENU_SCREEN_SAVER_DLY,(MEMU_STING_DEF *)ArgFormate,GetTimeAndData},
  {MENU_EVENT_B1_SHORT_PRESS,MENU_ILLUMINATION_SET,MENU_TO_DLY,NULL,IlluminationShow,NULL},
  {MENU_EVENT_B2_SHORT_PRESS,0,MENU_TO_DLY,NULL,NULL,NULL},
  {MENU_EVENT_ADC_CONV,0,MENU_TIME_OUT_NOT_UPADATE,NULL,ADC_Measure,NULL},
  {0,0,MENU_TIME_OUT_NOT_UPADATE,NULL,NULL,NULL},
};

/* Returm to Time and Data show */
const MENU_ACTION_SHAIN_DEF MenuActionEventChain5 [] =
{
  {MENU_TICK_EVENT,MENU_TIME_AND_DATA_SHOW,MENU_SCREEN_SAVER_DLY,(MEMU_STING_DEF *)ArgFormate,GetTimeAndData,NULL},
  {MENU_EVENT_B1_SHORT_PRESS,MENU_ADC_MEASURE,MENU_TO_DLY,NULL,NULL,NULL},
  {MENU_EVENT_B2_SHORT_PRESS,MENU_TIME_AND_DATA_SHOW,MENU_SCREEN_SAVER_DLY,(MEMU_STING_DEF *)ArgFormate,GetTimeAndData,NULL},
  {0,0,MENU_TIME_OUT_NOT_UPADATE,NULL,NULL,NULL},
};

/* Time and Data show */
const MENU_ACTION_SHAIN_DEF MenuActionEventChain6 [] =
{
  {MENU_TICK_EVENT,MENU_SCREENSAVER_SHOW,1,NULL,ScreenSaverInit,NULL},
  {MENU_EVENT_B1_SHORT_PRESS,MENU_ADC_MEASURE,MENU_TO_DLY,NULL,ADC_Init,NULL},
  {MENU_EVENT_TIME_UPDATE,0,MENU_TIME_OUT_NOT_UPADATE,NULL,GetTimeAndData,NULL},
  {0,0,MENU_TIME_OUT_NOT_UPADATE,NULL,NULL,NULL},
};

/* Screen saver show */
const MENU_ACTION_SHAIN_DEF MenuActionEventChain7 [] =
{
  {MENU_TICK_EVENT,MENU_SCREENSAVER_SHOW,1,NULL,ScreenSaver,NULL},
  {MENU_EVENT_LOW_POWER,MENU_SLEEP_SHOW,1,NULL,NULL},
  {MENU_EVENT_B1_SHORT_PRESS,MENU_TIME_AND_DATA_SHOW,MENU_SCREEN_SAVER_DLY,(MEMU_STING_DEF *)ArgFormate,GetTimeAndData,NULL},
  {MENU_EVENT_B2_SHORT_PRESS,MENU_TIME_AND_DATA_SHOW,MENU_SCREEN_SAVER_DLY,(MEMU_STING_DEF *)ArgFormate,GetTimeAndData,NULL},
  {0,0,MENU_TIME_OUT_NOT_UPADATE,NULL,NULL,NULL},
};

/* Low power show */
const MENU_ACTION_SHAIN_DEF MenuActionEventChain8 [] =
{
  {MENU_TICK_EVENT,MENU_SLEEP_SHOW,1,NULL,NULL,NULL},
  {0,MENU_TIME_AND_DATA_SHOW,MENU_SCREEN_SAVER_DLY,(MEMU_STING_DEF *)ArgFormate,GetTimeAndData,NULL},
};


/* Return from Clock and Data setup */
const MENU_ACTION_SHAIN_DEF MenuActionEventChain9 [] =
{
  {MENU_TICK_EVENT,MENU_TIME_AND_DATA_SHOW,MENU_SCREEN_SAVER_DLY,(MEMU_STING_DEF *)ArgFormate,GetTimeAndData,NULL},
  {MENU_EVENT_B2_SHORT_PRESS,MENU_CLOCK_AND_DATA_SET,MENU_TO_DLY,NULL,NULL,NULL},
  {0,0,MENU_TIME_OUT_NOT_UPADATE,NULL,NULL,NULL},
};

/* Illumination setup change mode*/
const MENU_ACTION_SHAIN_DEF MenuActionEventChain10 [] =
{
  {MENU_TICK_EVENT,MENU_TIME_AND_DATA_SHOW,MENU_SCREEN_SAVER_DLY,(MEMU_STING_DEF *)ArgFormate,GetTimeAndData,CursorOff},
  {MENU_EVENT_B1_SHORT_PRESS,0,MENU_TO_DLY,NULL,IlluminationNextMode,IlluminationModeCursorOn},
  {MENU_EVENT_B2_SHORT_PRESS,MENU_ILLUMINATION_SET,MENU_TO_DLY,NULL,IlluminationShow,CursorOff},
  {0,0,MENU_TIME_OUT_NOT_UPADATE,NULL,NULL,NULL},
};

/*
  Action chain adrress table
*/
const MENU_ACTION_SHAIN_DEF * const MenuActionChainAdd [MENU_MAX_INDEX] =
{
  MenuActionEventChain0,
  MenuActionEventChain1,
  MenuActionEventChain2,
  MenuActionEventChain4,
  MenuActionEventChain5,
  MenuActionEventChain6,
  MenuActionEventChain7,
  MenuActionEventChain8,
  MenuActionEventChain9,
  MenuActionEventChain10,
};

/**********************************************************************************
 *                              Visual section
 **********************************************************************************/

/* -- Menu 0 -- */
/* Line 1 */
const MEMU_STING_DEF MenuText01 [] = "  IAR Embedded  ";
/* Line 2 */
const MEMU_STING_DEF MenuText02 [] = " Workbench-ARM  ";

/* -- Menu 1 -- */
/* Line 1 */
const MEMU_STING_DEF MenuText11 [] = "Clock and Date  ";
/* Line 2 */
const MEMU_STING_DEF MenuText12 [] = "setting         ";

/* -- Menu 2 -- */
/* Line 1 */
const MEMU_STING_DEF MenuText21 [] = "Illumination  ";
/* Line 2 */
const MEMU_STING_DEF MenuText22 [] = "setting\1";

/* -- Menu 3 -- */
/* Line 1 */
const MEMU_STING_DEF MenuText31 [] = "Communication   ";
/* Line 2 */
const MEMU_STING_DEF MenuText32 [] = "setting-COM\2   ";

/* -- Menu 4 -- */
/* Line 1 */
const MEMU_STING_DEF MenuText41 [] = "Adc measure    ";
/* Line 2 */
const MEMU_STING_DEF MenuText42 [] = "\1";

/* -- Menu 5 -- */
/* Line 1 */
const MEMU_STING_DEF MenuText51 [] = "Return to       ";
/* Line 2 */
const MEMU_STING_DEF MenuText52 [] = "previous menu   ";

/* -- Menu 6 -- */
/* Line 1 */
const MEMU_STING_DEF MenuText6 [] = "\1";

/*
  Menu chain data format
  Pos1 Pointer to String1 (Last elemet is NULL)
  Pos2 X1 coordinete
  Pos3 Y1 coordinete
  .
  .
  PosN-2 Pointer to StringN (Last elemet is NULL)
  PosN-1 XN coordinete
  PosN YN coordinete

  Menu meta language :
  0x00 - end of menu string
  0x01 - get variable data from (*pMenuVarArg)
  0x02 - return to const data
*/
const MENU_VISUAL_DEF MenuVisualLang1Chain0 [] =
{
  /* Line1 */
  {MenuText01,1,1},
  /* Line2 */
  {MenuText02,1,2},
  /* end of chain */
  {NULL,0,0},
};

const MENU_VISUAL_DEF MenuVisualLang1Chain1 [] =
{
  /* Line1 */
  {MenuText11,1,1},
  /* Line2 */
  {MenuText12,1,2},
  /* end of chain */
  {NULL,0,0},
};

const MENU_VISUAL_DEF MenuVisualLang1Chain2 [] =
{
  /* Line1 */
  {MenuText21,1,1},
  /* Line2 */
  {MenuText22,1,2},
  /* end of chain */
  {NULL,0,0},
};

const MENU_VISUAL_DEF MenuVisualLang1Chain3 [] =
{
  /* Line1 */
  {MenuText31,1,1},
  /* Line2 */
  {MenuText32,1,2},
  /* end of chain */
  {NULL,0,0},
};

const MENU_VISUAL_DEF MenuVisualLang1Chain4 [] =
{
  /* Line1 */
  {MenuText41,1,1},
  /* Line2 */
  {MenuText42,1,2},
  /* end of chain */
  {NULL,0,0},
};

const MENU_VISUAL_DEF MenuVisualLang1Chain5 [] =
{
  /* Line1 */
  {MenuText51,1,1},
  /* Line2 */
  {MenuText52,1,2},
  /* end of chain */
  {NULL,0,0},
};

const MENU_VISUAL_DEF MenuVisualLang1Chain6 [] =
{
  /* Line1 */
  {MenuText6,1,1},
  /* Line2 */
  {MenuText6,1,2},
  /* end of chain */
  {NULL,0,0},
};


/*
  Language1 vualisation chain adrress table
*/
const MENU_VISUAL_DEF * const MenuVisualLang1ChainAddTable [MENU_MAX_INDEX] =
{
  MenuVisualLang1Chain0, /* 0  */
  MenuVisualLang1Chain1, /* 1  */
  MenuVisualLang1Chain2, /* 2  */
  MenuVisualLang1Chain4, /* 3  */
  MenuVisualLang1Chain5, /* 4  */
  MenuVisualLang1Chain6, /* 5  */
  MenuVisualLang1Chain6, /* 6  */
  MenuVisualLang1Chain6, /* 7  */
  MenuVisualLang1Chain5, /* 8  */
  MenuVisualLang1Chain2, /* 9  */
};

/*
  Language table base adrress table
*/
const MENU_VISUAL_DEF * const * const MenuLanguageBaseAddTable [MENU_LANGUAGE_NUMBER] =
{
  MenuVisualLang1ChainAddTable,
};

