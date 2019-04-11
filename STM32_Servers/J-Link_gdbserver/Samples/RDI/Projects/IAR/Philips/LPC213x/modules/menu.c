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
//#include "user_func.h"
#include "includes.h"
#include "menu_table.c"

typedef struct
{
  MENU_EVENT_TYPE_DEF * Push;
  MENU_EVENT_TYPE_DEF * Pop;
  MENU_EVENT_TYPE_DEF EventStackBuffer [MENU_EVENT_STACK_SIZE]; /* Hold enevts */
} EVENT_STACK_DEF;

#define   MENU_EVET_STACK_EMPTY       (LPC_BOOL)0    /* Event stack is empty */
#define   MENU_EVET_STACK_DATA_VALID  (LPC_BOOL)1    /* Event stack data valid */

EVENT_STACK_DEF EventStack;
const MENU_VISUAL_DEF *const * LanguageBaseAdd;
MEMU_IND_DEF MenuInd;
MEMU_TIME_OUT_DEF MenuTO;

/*************************************************************************
 * Function Name: MenuStackInit
 * Parameters: None
 * Return: none
 * Description: Initialize menu event stack structure
 *
 *************************************************************************/
void MenuStackInit ()
{
  EventStack.Push = EventStack.Pop = EventStack.EventStackBuffer;
}

/*************************************************************************
 * Function Name: MenuShow
 * Parameters: MEMU_STING_DEF *pVarData
 * Return: MENU_ERROR_CODE_DEF
 *         MENU_OK	           0: sucess
 *	   MENU_LANG_ERROR         1: fail not valid language
 *         MENU_IND_ERROR          2: fail not valid menu index
 *         MENU_SHOW_OUT_OF_VISUAL 4: fail String out of visual space
 *         MENU_SHOW_ERROR         5: fail Error into LCD driver module
 * Description: Show current visual chain to LCD
 *
 *************************************************************************/
MENU_ERROR_CODE_DEF MenuShow (MEMU_STING_DEF *pVarData)
{
MENU_VISUAL_DEF * pData = (MENU_VISUAL_DEF *)*(LanguageBaseAdd+MenuInd);
MEMU_STING_DEF DataStr[MENU_MAX_STR_LENG];
MEMU_STING_DEF * pDataHold = NULL;
MEMU_STING_DEF * pDestData;
const MEMU_STING_DEF * pSourceData;
LPC_INT8U Result = MENU_OK;
  if (MenuInd > MENU_MAX_INDEX-1)
  {
    return MENU_IND_ERROR;
  }
  else if (pVarData == NULL)
  {
    return (MENU_ERROR_CODE_DEF) Result;
  }
  else
  {
    while (pData->MenuText) {
      pSourceData = pData->MenuText;
      pDestData = DataStr;
      while(*pSourceData || (pDataHold != NULL))
      {
        switch (*pSourceData)
        {
        case END_OF_STR:
          pVarData = (char *)++pSourceData;
          pSourceData = pDataHold;
          pDataHold = NULL;
          break;
        case VARIABLE_DATA:
          if((pVarData != NULL) && (*pVarData))
          {
            pDataHold = (char *)++pSourceData;
            pSourceData = pVarData;
          }
          else
          {
            pVarData = NULL;
          }
          break;
        case END_OF_VAR_DATA:
          if(pDataHold != NULL)
          {
            pVarData = (char *)++pSourceData;
            pSourceData = pDataHold;
            pDataHold = NULL;
          }
          else
          {
            ++pSourceData;
          }
          break;
        default:
          if((pDestData - DataStr) >= MENU_MAX_STR_LENG-1) break;
          *pDestData = *pSourceData;
          ++pDestData;++pSourceData;
          break;
        }
      }
      *pDestData = 0;
      Result = HD44780_StrShow(pData->X,pData->Y,(LPC_INT8S const *)DataStr);
      switch (Result)
      {
      case HD44780_BUSY_TO_ERROR:
      case HD44780_ERROR:
        return MENU_SHOW_ERROR;
      case HD44780_OUT_OF_VISUAL:
        Result = MENU_SHOW_OUT_OF_VISUAL;
      }
      ++pData;
    }
  }
  return (MENU_ERROR_CODE_DEF) Result;
}

/*************************************************************************
 * Function Name: MenuInit
 * Parameters: MENU_LANG_TYPE_DEF Language,
 *             MEMU_IND_DEF MainMenuInd,
 *             MEMU_STING_DEF *pVarData,
 *             MEMU_TIME_OUT_DEF MenuTO_Init
 * Return: MENU_ERROR_CODE_DEF
 *         MENU_OK	           0: sucess
 *	   MENU_LANG_ERROR         1: fail not valid language
 *         MENU_IND_ERROR          2: fail not valid menu index
 *         MENU_SHOW_OUT_OF_VISUAL 4: fail String out of visual space
 *         MENU_SHOW_ERROR         5: fail Error into LCD driver module
 *         MENU_TO_ERROR           6: fail Menu tome out is to long
 * Description: Initialize Menu
 *
 *************************************************************************/
MENU_ERROR_CODE_DEF MenuInit (MENU_LANG_TYPE_DEF Language,
  MEMU_IND_DEF MainMenuInd, MEMU_STING_DEF *pVarData, MEMU_TIME_OUT_DEF MenuTO_Init)
{
  /* Init Menu Events stack */
  MenuStackInit();
  if (Language > MENU_LANGUAGE_NUMBER-1)
  {
    return MENU_LANG_ERROR;
  }
  LanguageBaseAdd = MenuLanguageBaseAddTable[Language];
  if (MainMenuInd > MENU_MAX_INDEX-1)
  {
    return MENU_IND_ERROR;
  }
  MenuInd = MainMenuInd;
  if (MenuTO_Init > MEMU_MAX_TIME_OUT)
  {
    return MENU_TO_ERROR;
  }
  MenuTO = MenuTO_Init;
  return MenuShow(pVarData);
}

/*************************************************************************
 * Function Name: MenuGetEvent
 * Parameters: MENU_EVENT_TYPE_DEF * MenuEvent
 * Return: LPC_BOOL
 *        MENU_EVET_STACK_EMPTY	      0: Event stack is empty not valid data
 *	  MENU_EVET_STACK_DATA_VALID  1: Event stack is not empty valid data
 * Description: Pop menu event from stack
 *
 *************************************************************************/
LPC_BOOL MenuGetEvent (MENU_EVENT_TYPE_DEF * MenuEvent)
{
  if (EventStack.Pop == EventStack.Push)
  {
    return MENU_EVET_STACK_EMPTY;
  }
  /* Function MenuSetEvent is reentrant */
  *MenuEvent = *EventStack.Pop;
  __disable_interrupt();
  if (++EventStack.Pop == EventStack.Push)
  {
    MenuStackInit();
  }
  __enable_interrupt();
  return MENU_EVET_STACK_DATA_VALID;
}

/*************************************************************************
 * Function Name: MenuSetEvent
 * Parameters: MENU_EVENT_TYPE_DEF MenuEvent
 * Return: MENU_ERROR_CODE_DEF
 *        MENU_OK	            0: Push Event to stack
 *	  MENU_EVET_STACK_OVERFLOW  3: Stack overflow
 * Description: Push menu event to stack
 *
 *************************************************************************/
MENU_ERROR_CODE_DEF MenuSetEvent (MENU_EVENT_TYPE_DEF MenuEvent)
{
  if (EventStack.Push == &EventStack.EventStackBuffer[MENU_EVENT_STACK_SIZE])
  {
    return MENU_EVET_STACK_OVERFLOW;
  }
  *EventStack.Push = MenuEvent;
  ++EventStack.Push;
  return MENU_OK;
}

/*************************************************************************
 * Function Name: Menu
 * Parameters: none
 * Return: MENU_ERROR_CODE_DEF
 *        MENU_OK	            0: Push Event to stack
 *	  MENU_EVET_STACK_OVERFLOW  3: Stack overflow
 * Description: Implenet menu function, pop menu event and determinate actions,
 * set new visual chain, call to User function ..
 *
 *************************************************************************/
MENU_ERROR_CODE_DEF Menu ()
{
MENU_EVENT_TYPE_DEF MenuEvent;
MENU_ACTION_SHAIN_DEF * pMenuActionChain;
MEMU_STING_DEF DataStr[MENU_MAX_STR_LENG];
MEMU_STING_DEF * pDestData = DataStr;
const MEMU_STING_DEF * pSourceData;
LPC_BOOL ShowUpdate = FALSE;
MENU_ERROR_CODE_DEF Result = MENU_OK;
  if(MenuGetEvent(&MenuEvent) == MENU_EVET_STACK_DATA_VALID)
  {
    /* Menu time out implement */
    if (MenuEvent == MENU_TICK_EVENT)
    {
      if (MenuTO)
      {
        if(--MenuTO)
        {
          return Result;
        }
      }
      else
      {
        return Result;
      }
    }
    /* Menu action  time out implement */
    pMenuActionChain = (MENU_ACTION_SHAIN_DEF *)MenuActionChainAdd[MenuInd];
    while(pMenuActionChain->EventType)
    {
      if(pMenuActionChain->EventType != MenuEvent)
      {
        ++pMenuActionChain;
      }
      else
      {
        break;
      }
    }
    if (pMenuActionChain->MenuIndex)
    {
      if (MenuInd != pMenuActionChain->MenuIndex)
      {
        ShowUpdate = TRUE;
        MenuInd = pMenuActionChain->MenuIndex;
      }
    }
    if(pMenuActionChain->pVarArg != NULL)
    {
      ShowUpdate = TRUE;
      pSourceData = pMenuActionChain->pVarArg;
      while(*pSourceData)
      {
        *pDestData=*pSourceData;
        ++pSourceData;++pDestData;
      }
    }
    if (pMenuActionChain->MenuTO != MENU_TIME_OUT_NOT_UPADATE)
    {
      MenuTO = pMenuActionChain->MenuTO;
    }
    if(pMenuActionChain->UserFunc != NULL)
    {
      ShowUpdate = TRUE;
      pMenuActionChain->UserFunc(DataStr,&MenuInd,&MenuTO);
    }
    if (ShowUpdate)
    {
      Result = MenuShow(DataStr);
      if(pMenuActionChain->UserFunc1 != NULL)
      {
        pMenuActionChain->UserFunc1(DataStr,&MenuInd,&MenuTO);
      }
    }
  }
  return Result;
}

/*************************************************************************
 * Function Name: MenuGetInd
 * Parameters: none
 * Return: MENU_EVENT_TYPE_DEF
 *
 * Description: Return current menu index
 *
 *************************************************************************/
MENU_EVENT_TYPE_DEF MenuGetInd(void)
{
  return MenuInd;
}

/*************************************************************************
 * Function Name: MenuGetActionChain
 * Parameters: MEMU_IND_DEF MenuInd
 * Return: MENU_ACTION_SHAIN_DEF *
 *
 * Description: Return pointer to stucture of action chain
 *
 *************************************************************************/
MENU_ACTION_SHAIN_DEF * MenuGetActionChain(MEMU_IND_DEF MenuInd)
{
  if (MenuInd > MENU_MAX_INDEX-1)
  {
    return (void *)0;
  }
  return (MENU_ACTION_SHAIN_DEF *)MenuActionChainAdd[MenuInd];
}

/*************************************************************************
 * Function Name: MenuGetVisualChain
 * Parameters: MENU_LANG_TYPE_DEF Language,
 *             MEMU_IND_DEF MenuInd
 * Return: MENU_VISUAL_DEF *
 *
 * Description: Return pointer to stucture of visual chain
 *
 *************************************************************************/
MENU_VISUAL_DEF * MenuGetVisualChain(MENU_LANG_TYPE_DEF Language,MEMU_IND_DEF MenuInd)
{
  if ((MenuInd < MENU_MAX_INDEX) && (Language < MENU_LANGUAGE_NUMBER))
  {
    return (MENU_VISUAL_DEF *)(*MenuLanguageBaseAddTable[Language]+MenuInd);
  }
  return (MENU_VISUAL_DEF *)0;
}
