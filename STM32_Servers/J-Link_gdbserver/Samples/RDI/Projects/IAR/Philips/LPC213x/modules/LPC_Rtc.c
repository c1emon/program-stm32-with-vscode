/*************************************************************************
 *
 *    Used with ICCARM and AARM.
 *
 *    (c) Copyright IAR Systems 2003
 *
 *    File name   : LPC_Rtc.c
 *    Description : Define API for RTI
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

#include "LPC_Rtc.h"

/*************************************************************************
 * Function Name: IsLeapYear
 * Parameters: unsigned short Year
 *
 * Return: bool 
 *
 * Description: Judge whether the specifying year is leap year. 
 *  
 *************************************************************************/
static bool IsLeapYear (unsigned short year)
{
  if (!(year%4) && (year%100) || !(year%400))
    return true;
  return false;
}

/*************************************************************************
 * Function Name: GetDOY
 * Parameters:  unsigned short Year
 *	  	unsigned char month
 *		unsigned char day
 *
 * Return: int 
 *
 * Description: Get the day of year according to the date
 *  
 *************************************************************************/
static int GetDOY (unsigned short year, unsigned char month, unsigned char day)
{
int DOY=0, i;

  for(i=1; i<month; i++)
    DOY+=RTC_MonthVal[i];

  if (month>2)
    if (IsLeapYear(year))
      DOY++;

  return (DOY+day);	
}

/*************************************************************************
 * Function Name: GetDOW
 * Parameters:  unsigned short Year
 *		unsigned char month
 *		unsigned char day
 *
 * Return: int -- (0~6)
 *
 * Description: Get the day of week according to the date.
 *
 * NOTE: Year is not smaller than RTC_YEARMIN (1901).
 *  
 *************************************************************************/
static int GetDOW (unsigned short year, unsigned char month, char day)
{
int i, DOW=0;

  for (i = RTC_BASEYEAR, DOW = 0; i < year; i++)
  {
    DOW +=365;
    if  (IsLeapYear(i))
      DOW++;
  }

  DOW +=  GetDOY (year, month, day) - 1;
  DOW = (DOW + RTC_BASEDOW) % 7;

  return DOW;	
}

/*************************************************************************
 * Function Name: IsValidDay
 * Parameters:  unsigned short Year
 *		unsigned char month
 *	        unsigned char day
 *
 * Return: 
 *		false -- not valid day
 *		true -- valid day
 *
 * Description: Check if the specify day is valid
 *
 * NOTE: Year is not smaller than RTC_YEARMIN (1901).
 *  
 *************************************************************************/
static bool IsValidDay (unsigned short year, unsigned char month, unsigned char day)
{
  /* Valid Judge */
  if (year < RTC_YEARMIN || year > RTC_YEARMAX ||day <1)
    return false;

  switch(month)
  {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    if (day>31)
      return false;
    else
      break;
  case 4:
  case 6:
  case 9:
  case 11:
    if (day>30)
      return false;
    else
      break;
  case 2:
    if (IsLeapYear(year))
      if (day>29)
        return false;
      else
        break;
    else
      if (day>28)
        return false;
      else
        break;
  default:
    return false;
  }

  return true;
}

/*************************************************************************
 * Function Name: RTC_Enable
 * Parameters: void
 * Return: void 
 *
 * Description: Enable RTC, let RTC run.
 *  
 *************************************************************************/
void RTC_Enable(void)
{
  CCR_bit.CLKEN = true;
  return ;
}

/*************************************************************************
 * Function Name: RTC_Disable
 * Parameters: void
 * Return: void 
 *
 * Description: Disable RTC, let RTC stop.
 *  
 *************************************************************************/
void RTC_Disable(void)
{
  CCR_bit.CLKEN = false;
  return ;
}

/*************************************************************************
 * Function Name: RTC_Init
 * Parameters: void
 *
 * Return: int 
 *             	0: sucess
 *		1: fail
 *
 * Description: Initialize RTC, configure prescaler, CIIR and AMR register
 *  
 *************************************************************************/
int RTC_Init(LPC_BOOL BackComp)
{
unsigned long PreInt;

  RTC_Disable();
  if (BackComp)
  {
  // initialize prescaler of RTC
  PreInt = (int)( SYS_GetFpclk() / RTC_CountPerSec ) - 1;
  if (PreInt <= 0)
    return 1;
	
  PREINT = PreInt;
  PREFRAC = SYS_GetFpclk() - (PreInt + 1) * RTC_CountPerSec;
  }
  else
  {
    /* 32kHz watch quarc */
    CCR_bit.CLKSRC = 1;
  }
  /* test disable and reset*/
  CCR_bit.CTCRST = CCR_bit.CTTEST = 0;
  // initialize interrupt mask register of RTC
  AMR=0;
  CIIR_bit.IMSEC = 1;

  // clear all interrupt of RTC
  ILR=0x3;
	
  // initialize Date and Time
  if (RTC_SetDateTime(&RTC_InitDateTime))
    return 1;

//  RTC_Enable();
  return 0;
}

/*************************************************************************
 * Function Name: RTC_SetDate
 * Parameters: LPC_Rtc_Date_t *pDate
 * Return: int 
 *             	0: sucess
 *		1: fail
 * Description: Set your specifying date
 *  
 *************************************************************************/
int RTC_SetDate (LPC_Rtc_Date_t *pDate)
{
  // Valid Judge
  if (IsValidDay(pDate->year, pDate->month, pDate->day) == false)
    return 1;

  // Calulate DOW, DOY
  pDate->DOY = GetDOY(pDate->year, pDate->month, pDate->day);
  pDate->DOW = GetDOW(pDate->year, pDate->month, pDate->day);

  DOM=pDate->day;
  MONTH=pDate->month;
  YEAR=pDate->year;
  DOW=pDate->DOW;
  DOY=pDate->DOY;

  return 0;
}

/*************************************************************************
 * Function Name: RTC_SetTime
 * Parameters: LPC_Rtc_Time_t *pTime
 * Return: int 
 *             	0: sucess
 *		1: fail
 * Description: Set your specifying time
 *  
 *************************************************************************/
int RTC_SetTime (LPC_Rtc_Time_t *pTime)
{
  // Valid Judge
  if ( pTime->hour > 23 || pTime->minute > 59 || pTime->second > 59)
    return 1;

  HOUR = pTime->hour;
  MIN = pTime->minute;
  SEC = pTime->second;

  return 0;
}

/*************************************************************************
 * Function Name: RTC_SetDateTime
 * Parameters: LPC_Rtc_DateTime_t *pDateTime
 * Return: int 
 *             	0: sucess
 *		1: fail
 * Description: Set your specifying date and time
 *  
 *************************************************************************/
int RTC_SetDateTime (LPC_Rtc_DateTime_t *pDateTime)
{
  // Valid Judge
  if (IsValidDay(pDateTime->year, pDateTime->month, pDateTime->day) == false)
    return 1;

  if ( pDateTime->hour > 23 || pDateTime->minute > 59 ||pDateTime->second > 59)
    return 1;

  // Calulate DOW, DOY
  pDateTime->DOY = GetDOY(pDateTime->year, pDateTime->month, pDateTime->day);
  pDateTime->DOW = GetDOW(pDateTime->year, pDateTime->month, pDateTime->day);
	
  DOM=pDateTime->day;
  MONTH=pDateTime->month;
  YEAR=pDateTime->year;
  DOW=pDateTime->DOW;
  DOY=pDateTime->DOY;

  HOUR = pDateTime->hour;
  MIN = pDateTime->minute;
  SEC = pDateTime->second;

  return 0;
}

/*************************************************************************
 * Function Name: RTC_GetDate
 * Parameters: LPC_Rtc_Date_t *pDate
 * Return: int 
 *             	0: sucess
 *		1: fail
 * Description: Get the current date
 *  
 *************************************************************************/
int RTC_GetDate (LPC_Rtc_Date_t *pDate)
{

  pDate->day = DOM;
  pDate->month = MONTH;
  pDate->year = YEAR;

  pDate->DOW = DOW;
  pDate->DOY = DOY;

  return 0;
}

/*************************************************************************
 * Function Name: RTC_GetTime
 * Parameters: LPC_Rtc_Time_t *pTime
 * Return: int 
 *             	0: sucess
 *		1: fail
 * Description: Set the current time
 *  
 *************************************************************************/
int RTC_GetTime (LPC_Rtc_Time_t *pTime)
{

  pTime->hour = HOUR;
  pTime->minute = MIN;
  pTime->second = SEC;

  return 0;
}

/*************************************************************************
 * Function Name: RTC_GetDateTime
 * Parameters: LPC_Rtc_DateTime_t *pDateTime
 * Return: int 
 *             	0: sucess
 *		1: fail
 * Description: Get the current date and time
 *  
 *************************************************************************/
int RTC_GetDateTime (LPC_Rtc_DateTime_t *pDateTime)
{

  pDateTime->day = DOM;
  pDateTime->month = MONTH;
  pDateTime->year = YEAR;

  pDateTime->hour = HOUR;
  pDateTime->minute = MIN;
  pDateTime->second = SEC;

  pDateTime->DOW = DOW;
  pDateTime->DOY = DOY;

  return 0;
}

/*************************************************************************
 * Function Name: RTC_SetInctInt
 * Parameters: unsigned char IncIntType
 * Return: void 
 *
 * Description: Set increment interrupt type
 *  
 *************************************************************************/
void RTC_SetIncInt (unsigned char IncIntType)
{
  CIIR = IncIntType & 0xFF;
  return;
}

/*************************************************************************
 * Function Name: RTC_DisableIncInt
 * Parameters: void
 * Return: void 
 *
 * Description: Disable RTC increment interrupt.
 *  
 *************************************************************************/
void RTC_DisableIncInt(void)
{
  CIIR = 0;
  return ;
}

/*************************************************************************
 * Function Name: RTC_SetAlarmtInt
 * Parameters: unsigned char AlarmIntType
 * Return: void 
 *
 * Description: Set alarm interrupt type
 *  
 *************************************************************************/
void RTC_SetAlarmInt (unsigned char AlarmIntType)
{
  AMR = ~AlarmIntType & 0xFF;
  return;
}

/*************************************************************************
 * Function Name: RTC_DisableAlarmInt
 * Parameters: void
 * Return: void 
 *
 * Description: Disable RTC alarm interrupt.
 *  
 *************************************************************************/
void RTC_DisableAlarmInt(void)
{
  AMR = 0xFF;
}

/*************************************************************************
 * Function Name: RTC_SetAlarmDateTime
 * Parameters: LPC_Rtc_DateTime_t *pDateTime
 * Return: int 
 *             	0: sucess
 *		1: fail
 * Description: Set your specifying alarm date and time
 *  
 *************************************************************************/
int RTC_SetAlarmDateTime (LPC_Rtc_DateTime_t *pDateTime)
{
  // Valid Judge
  if (IsValidDay(pDateTime->year, pDateTime->month, pDateTime->day) == false)
    return 1;

  if ( pDateTime->hour > 23 || pDateTime->minute > 59 ||pDateTime->second > 59)
    return 1;

  // Calulate DOW, DOY
  pDateTime->DOY = GetDOY(pDateTime->year, pDateTime->month, pDateTime->day);
  pDateTime->DOW = GetDOW(pDateTime->year, pDateTime->month, pDateTime->day);

  ALDOM=pDateTime->day;
  ALMON=pDateTime->month;
  ALYEAR=pDateTime->year;
  ALDOW=pDateTime->DOW;
  ALDOY=pDateTime->DOY;

  ALHOUR = pDateTime->hour;
  ALMIN = pDateTime->minute;
  ALSEC = pDateTime->second;

  return 0;
}

/*************************************************************************
 * Function Name: RTC_ClearInt
 * Parameters: unsigned long IntType
 * Return: int 
 *             	0: sucess
 *		1: fail
 *
 * Description: Clear RTC interrupt.
 *  
 *************************************************************************/
int RTC_ClearInt(unsigned long IntType)
{
  if (IntType<1 || IntType>3)
    return 1;

  ILR = (IntType & 0x3);
  return 0;
}

/*************************************************************************
 * Function Name: RTC_CheckIntType
 * Parameters: void
 * Return:  unsigned long
 *	    RTCIncrementInt(1) | RTCAlarmInt(2)
 *
 * Description: Get RTC interrupt Type.
 *  
 *************************************************************************/
unsigned long RTC_CheckIntType(void)
{
  return (ILR & 0x3);
}

/*************************************************************************
 * Function Name: RTC_ISR
 * Parameters:  void
 * Return: void
 *
 * Description: Rtc interrupt subroutine
 *  
 *************************************************************************/
void RTC_ISR (void)
{
int IntStatus;

  IntStatus = RTC_CheckIntType() & 0x3;
  RTC_ClearInt(IntStatus);
	
  if (IntStatus & RTCIncrementInt)	// Increment Interrupt
  {
    SysTimeUpdate();
  }

  if (IntStatus & RTCAlarmInt)	        // Alarm Interrupt
  {
    Alarm();
  }
  VICVectAddr = 0;
}


/*************************************************************************
 * Function Name: FormatDate
 * Parameters: int Type
 *			LPC_Rtc_Date_t *pDate
 *			char *s
 *
 * Return: void 
 *
 * Description: Format the current date into an ASCII string according to the Type.
 *		Type = 1, "YYYY-MM-DD" (11 chars)
 *		Type = 2, "DOW Month DD, YYYY" (30 chars)
 *  
 *************************************************************************/
void FormatDate (int Type, LPC_Rtc_Date_t *pDate, char *s)
{
unsigned short year;
unsigned char month, day, DOW;
char str[5];

  year = pDate->year;
  month = pDate->month;
  day = pDate->day;
  DOW = pDate->DOW;
//  DOY = pDate->DOY;
	
  switch(Type)
  {
  case 1:
    strcpy(s, "YYYY-MM-DD");
    s[0] = year / 1000 + '0';
    year = year % 1000;
    s[1] = year / 100 + '0';
    year = year % 100;
    s[2] = year / 10 + '0';
    s[3] = year % 10 + '0';
    s[5] = month / 10 + '0';
    s[6] = month % 10 + '0';
    s[8] = day / 10 + '0';
    s[9] = day % 10 + '0';
    break;
  case 2:
    strcpy(s, RTC_DOWTbl[DOW]);
    strcat(s, RTC_MonthTbl[month]);
    if (day < 10)
    {
      str[0] = day + '0';
      str[1] = 0;
    }
    else
    {
      	str[0] = day / 10 + '0';
        str[1] = day % 10 + '0';
        str[2] = 0;
    }
    strcat(s, str);
    strcat(s, ", ");
    sprintf(str,"%d",year);
    strcat(s, str);
    break;		
  default:
    strcpy(s,"?");
    break;
  }
}

/*************************************************************************
 * Function Name: FormatTime
 * Parameters: int Type
 *			LPC_Rtc_Time_t *pTime
 *			char *s
 *
 * Return: void 
 *
 * Description: Format the current time into an ASCII string according to the Type.
 *		Type = 1, "HH:MM:SS" (9 chars)
 *		Type = 2, "HH:MM:SS AM" (13 chars)
 *  
 *************************************************************************/
void FormatTime (int Type, LPC_Rtc_Time_t *pTime, char *s)
{
unsigned char hour, minute, second;

  hour = pTime->hour;
  minute = pTime->minute;
  second = pTime->second;
	
  switch(Type)
  {
  case 1:
    strcpy(s, "HH:MM:SS");
    s[0] = hour / 10 + '0';
    s[1] = hour % 10 + '0';
    s[3] = minute / 10 + '0';
    s[4] = minute % 10 + '0';
    s[6] = second / 10 + '0';
    s[7] = second % 10 + '0';
    break;
  case 2:
    strcpy(s, "HH:MM:SS AM");
    s[9] = (hour>=12) ? 'P' : 'A';
    if (hour>12)
      hour = hour -12;	
			
    s[0] = hour / 10 + '0';
    s[1] = hour % 10 + '0';
    s[3] = minute / 10 + '0';
    s[4] = minute % 10 + '0';
    s[6] = second / 10 + '0';
    s[7] = second % 10 + '0';
    break;
  default:
    strcpy(s,"?");
    break;		
  }
}

/*************************************************************************
 * Function Name: FormatDateTime
 * Parameters:  int Type
 *	        LPC_Rtc_DateTime_t *pDateTime
 *		char *s
 *
 * Return: void 
 *
 * Description: Format the current date and time into an ASCII string according to the Type.
 *		Type = 1, "YYYY-MM-DD HH:MM:SS" (18 chars)
 *  
 *************************************************************************/
void FormatDateTime (int Type, LPC_Rtc_DateTime_t *pDateTime, char *s)
{
unsigned short year;
unsigned char month, day;
unsigned char hour, minute, second;

  year = pDateTime->year;
  month = pDateTime->month;
  day = pDateTime->day;
//  DOW = pDateTime->DOW;
//  DOY = pDateTime->DOY;
	
  hour = pDateTime->hour;
  minute = pDateTime->minute;
  second = pDateTime->second;
	
  switch(Type)
  {
  case 1:
    strcpy(s, "YYYY-MM-DD HH:MM:SS");
    s[0] = year / 1000 + '0';
    year = year % 1000;
    s[1] = year / 100 + '0';
    year = year % 100;
    s[2] = year / 10 + '0';
    s[3] = year % 10 + '0';
    s[5] = month / 10 + '0';
    s[6] = month % 10 + '0';
    s[8] = day / 10 + '0';
    s[9] = day % 10 + '0';
		
    s[11] = hour / 10 + '0';
    s[12] = hour % 10 + '0';
    s[14] = minute / 10 + '0';
    s[15] = minute % 10 + '0';
    s[17] = second / 10 + '0';
    s[18] = second % 10 + '0';
    break;
  default:
    strcpy(s,"?");
    break;
  }
}
