#ifndef  __USER_FUNC_H
#define  __USER_FUNC_H

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
 *    $Revision: 1.2 $
 **************************************************************************/

#include <includes.h>
#define BUTT_EVENT_1    1
#define BUTT_EVENT_2    2
#define BUTT_FLAG_1     0x10
#define BUTT_FLAG_2     0x20
#define BUTT_DEB        2    /* 20ms */

#define LIGHT_ON        1
#define LIGHT_OFF       0

#define LIGHT_SLOW      1
#define LIGHT_FAST      0

#define LIGHT_OFF_VALUE 0
#define LIGHT_ON_VALUE  0x3FF

void GetTimeAndData (MEMU_STING_DEF * pVarArg,MEMU_IND_DEF * MenuIndex, MEMU_TIME_OUT_DEF * MenuTO);

void ScreenSaverInit (MEMU_STING_DEF * pVarArg,MEMU_IND_DEF * MenuIndex, MEMU_TIME_OUT_DEF * MenuTO);
void ScreenSaver (MEMU_STING_DEF * pVarArg,MEMU_IND_DEF * MenuIndex, MEMU_TIME_OUT_DEF * MenuTO);

void SysTimeUpdate (void);
void Alarm (void);

LPC_INT8U GetButtonsEvent (void);
void ButtonsInit (void);

void SetSysTickFlag (void* arg);

void LightCntr (LPC_BOOL Slow,LPC_BOOL On);
void LightInit(void);

void ADC_Init (MEMU_STING_DEF * pVarArg,MEMU_IND_DEF * MenuIndex, MEMU_TIME_OUT_DEF * MenuTO);
void ADC_Measure (MEMU_STING_DEF * pVarArg,MEMU_IND_DEF * MenuIndex, MEMU_TIME_OUT_DEF * MenuTO);

void IlluminationShow (MEMU_STING_DEF * pVarArg,MEMU_IND_DEF * MenuIndex, MEMU_TIME_OUT_DEF * MenuTO);
void IlluminationModeCursorOn (MEMU_STING_DEF * pVarArg,MEMU_IND_DEF * MenuIndex, MEMU_TIME_OUT_DEF * MenuTO);
void IlluminationNextMode (MEMU_STING_DEF * pVarArg,MEMU_IND_DEF * MenuIndex, MEMU_TIME_OUT_DEF * MenuTO);

void CursorOff (MEMU_STING_DEF * pVarArg,MEMU_IND_DEF * MenuIndex, MEMU_TIME_OUT_DEF * MenuTO);

extern volatile int TickSysFlag;
extern int SysTimeUpdateFlag;
extern int SysAlarmFlag;

extern int TimeFormat;
extern int DataFormat;

extern int LightMode;

#endif  /* __USER_FUNC_H */
