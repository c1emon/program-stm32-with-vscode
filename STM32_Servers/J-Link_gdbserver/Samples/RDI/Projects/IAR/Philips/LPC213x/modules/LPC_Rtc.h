#ifndef __LPC_RTC_H
#define __LPC_RTC_H

/*************************************************************************
 *
 *    Used with ICCARM and AARM.
 *
 *    (c) Copyright IAR Systems 2003
 *
 *    File name   : LPC_Rtc.h
 *    Description : Define RTI structure and relative micro
 *
 *    History :
 *    1. Data        : August 10, 2004
 *       Author      : Shawn Zhang
 *       Description : Create
 *
 *    2. Data        : Oct 12, 2004 
 *       Author      : Stanimir Bonev
 *       Description: Modify the interface of some functions  
 *
 *    $Revision: 1.1 $
 **************************************************************************/

#include "includes.h"

#define RTC_CountPerSec     32768

#define RTC_YEARMIN         1901
#define RTC_YEARMAX         2099

// 1901.1.1 DOW = 2
#define RTC_BASEYEAR        1901
#define RTC_BASEMONTH       1
#define RTC_BASEDAY         1
#define RTC_BASEDOW         2

/* RTC Interrupt location register bit descriptions */
#define ILR_CIF_BIT         0
#define ILR_ALF_BIT         1

/* RTC Clock control register bit descriptions */
#define CCR_CLKEN_BIT       0
#define CCR_CTCRST_BIT      1

/* RTC Increment Interrupt Type */
#define IncIntType_SEC	    0x1
#define IncIntType_MIN	    0x2
#define IncIntType_HOUR	    0x4
#define IncIntType_DAY	    0x8
#define IncIntType_MON	    0x40
#define IncIntType_YEAR	    0x80
#define IncIntType_DOW	    0x10
#define IncIntType_DOY	    0x20

/* RTC Alarm Interrupt Type */
#define AlarmIntType_SEC    0x1
#define AlarmIntType_MIN    0x2
#define AlarmIntType_HOUR   0x4
#define AlarmIntType_DAY    0x8
#define AlarmIntType_MON    0x40
#define AlarmIntType_YEAR   0x80
#define AlarmIntType_DOW    0x10
#define AlarmIntType_DOY    0x20

 /* RTC interrupt type */
#define RTCIncrementInt	    0x1
#define RTCAlarmInt	    0x2
#define RTCALLInt	    0x3

typedef struct {
	unsigned short year;  // year value
	unsigned char month;  // month value
	unsigned char day;    // day value

	/* the below member is used in get-operation */
	unsigned char DOW;    // Day of week
	unsigned char DOY;    // Day of year
} LPC_Rtc_Date_t;

typedef struct {
	unsigned char hour;   // hour value
	unsigned char minute; // minute value
	unsigned char second; // second value
} LPC_Rtc_Time_t;

typedef struct {
	unsigned short year;  // year value
	unsigned char month;  // month value
	unsigned char day;    // day value

	unsigned char hour;   // hour value
	unsigned char minute; // minute value
	unsigned char second; // second value

	/* the below member is used in get-operation */
	unsigned char DOW;    // Day of week
	unsigned char DOY;    // Day of year
} LPC_Rtc_DateTime_t;

static LPC_Rtc_DateTime_t RTC_InitDateTime = {2005, 2, 14, 12, 0, 0};
static char *RTC_DOWTbl[] = {
	"Sunday ",
	"Monday ",
	"Tuesday ",
	"Wednesday ",
	"Thursday ",
	"Friday ",
	"Saturday "
};

static char *RTC_MonthTbl[] = {
	"",
	"January ",
	"February ",
	"Match ",
	"April ",
	"May ",
	"June ",
	"July ",
	"August ",
	"September ",
	"October ",
	"November ",
	"December "
};

static int RTC_MonthVal[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


/* Declare functions */
void RTC_Enable(void);
void RTC_Disable(void);

int RTC_Init(LPC_BOOL OldComp);

int RTC_SetDate (LPC_Rtc_Date_t *pDate);
int RTC_SetTime (LPC_Rtc_Time_t *pTime);
int RTC_SetDateTime (LPC_Rtc_DateTime_t *pDateTime);

int RTC_GetDate (LPC_Rtc_Date_t *pDate);
int RTC_GetTime (LPC_Rtc_Time_t *pTime);
int RTC_GetDateTime (LPC_Rtc_DateTime_t *pDateTime);

void RTC_SetIncInt (unsigned char IncIntType);
void RTC_DisableIncInt(void);

void RTC_SetAlarmInt (unsigned char AlarmIntType);
void RTC_DisableAlarmInt(void);
int RTC_SetAlarmDateTime (LPC_Rtc_DateTime_t *pDateTime);

int RTC_ClearInt(unsigned long IntType);
unsigned long RTC_CheckIntType(void);

void RTC_ISR (void);

void FormatDate (int Type, LPC_Rtc_Date_t *pDate, char *s);
void FormatTime (int Type, LPC_Rtc_Time_t *pTime, char *s);
void FormatDateTime (int Type, LPC_Rtc_DateTime_t *pDateTime, char *s);

extern void SysTimeUpdate (void);
extern void Alarm (void);


#endif  // __LPC_RTC_H
