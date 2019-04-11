/**
  ******************************************************************************
  * @file    Loader_Src.c
  * @author  MCD Tools Team
  * @date    October-2015
  * @brief   This file defines the operations of the external loader for
  *          N25Q256A QSPI memory of STM32L476G-EVAL.
  ******************************************************************************
  */

#include "Loader_Src.h"


/* Private variables ---------------------------------------------------------*/
QSPI_HandleTypeDef              QSPIHandle;
QSPI_CommandTypeDef             sCommand;
__IO uint8_t                    StatusMatch;


/**
  * @brief  System initialization.
  * @param  None
  * @retval  1      : Operation succeeded
  * @retval  0      : Operation failed
  */
int Init (void)
{ 
  QSPI_MemoryMappedTypeDef sMemMappedCfg;

  HAL_Init();

  SystemClock_Config(); 
  
  QSPIHandle.Instance = QUADSPI;
  QSPIHandle.Init.ClockPrescaler     = 0;
  QSPIHandle.Init.FifoThreshold      = 4;
  QSPIHandle.Init.SampleShifting     = QSPI_SAMPLE_SHIFTING_NONE;
  QSPIHandle.Init.FlashSize          = QSPI_FLASH_SIZE;
  QSPIHandle.Init.ChipSelectHighTime = QSPI_CS_HIGH_TIME_1_CYCLE;
  QSPIHandle.Init.ClockMode          = QSPI_CLOCK_MODE_0;
  QSPIHandle.State = HAL_QSPI_STATE_RESET;
  HAL_QSPI_Init(&QSPIHandle);

  ResetMemory(&QSPIHandle);
  
  QSPI_WriteEnable(&QSPIHandle); 
  
  /* Set data length */
  QSPIHandle.Instance->DLR = 0;  
  QSPIHandle.Instance->FCR = 0x1F;
  
  sCommand.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
  sCommand.AddressSize       = QSPI_ADDRESS_32_BITS;
  sCommand.AddressMode       = QSPI_ADDRESS_NONE;
  sCommand.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  sCommand.AlternateBytesSize= QSPI_ALTERNATE_BYTES_8_BITS;
  sCommand.DataMode          = QSPI_DATA_NONE;
  sCommand.DdrMode           = QSPI_DDR_MODE_DISABLE;
  sCommand.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
  sCommand.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;
  sCommand.DummyCycles       = 0;
  sCommand.Instruction       = 0xB7;
  QSPIHandle.State           = HAL_QSPI_STATE_READY;
  HAL_QSPI_Command(&QSPIHandle, &sCommand, 0x10); 

  /* Configure Volatile Configuration register (with new dummy cycles) */
  QSPIHandle.State = HAL_QSPI_STATE_READY;
  QSPI_DummyCyclesCfg(&QSPIHandle); 
  
  sCommand.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
  sCommand.AddressSize       = QSPI_ADDRESS_32_BITS;
  sCommand.AddressMode       = QSPI_ADDRESS_4_LINES;
  sCommand.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  sCommand.AlternateBytesSize= QSPI_ALTERNATE_BYTES_8_BITS;
  sCommand.DataMode          = QSPI_DATA_4_LINES;
  sCommand.DdrMode           = QSPI_DDR_MODE_DISABLE;
  sCommand.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
  sCommand.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;
  sCommand.DummyCycles       = DUMMY_CLOCK_CYCLES_READ_QUAD;
  sCommand.Instruction       = QUAD_INOUT_FAST_READ_CMD;
  sMemMappedCfg.TimeOutActivation = QSPI_TIMEOUT_COUNTER_DISABLE;
  QSPIHandle.State           = HAL_QSPI_STATE_READY;
  HAL_QSPI_MemoryMapped(&QSPIHandle, &sCommand, &sMemMappedCfg);
  
  return 1;
}


/**
  * @brief   Program memory.
  * @param   Address: page address
  * @param   Size   : size of data
  * @param   buffer : pointer to data buffer
  * @retval  1      : Operation succeeded
  * @retval  0      : Operation failed
  */
KeepInCompilation int Write (uint32_t Address, uint32_t Size, uint8_t* buffer)
{	
  uint32_t NumOfPage = 0, NumOfSingle = 0, Addr = 0, count = 0, temp = 0;
  uint32_t   QSPI_DataNum = 0;
  
  Addr = Address % QSPI_PAGE_SIZE;
  count = QSPI_PAGE_SIZE - Addr;
  NumOfPage =  Size / QSPI_PAGE_SIZE;
  NumOfSingle = Size % QSPI_PAGE_SIZE;

  if (Addr == 0) /*!< Address is QSPI_PAGESIZE aligned  */
  {
    if (NumOfPage == 0) /*!< NumByteToWrite < QSPI_PAGESIZE */
    {
      QSPI_DataNum = Size;      
      QSPI_WritePage(Address, QSPI_DataNum, buffer);
    }
    else /*!< Size > QSPI_PAGESIZE */
    {
      while (NumOfPage--)
      {
        QSPI_DataNum = QSPI_PAGE_SIZE;
        QSPI_WritePage(Address, QSPI_DataNum, buffer);
        Address +=  QSPI_PAGE_SIZE;
        buffer += QSPI_PAGE_SIZE;
      }
      
      QSPI_DataNum = NumOfSingle;
      QSPI_WritePage(Address, QSPI_DataNum, buffer);
    }
  }
  else /*!< Address is not QSPI_PAGESIZE aligned  */
  {
    if (NumOfPage == 0) /*!< Size < QSPI_PAGESIZE */
    {
      if (NumOfSingle > count) /*!< (Size + Address) > QSPI_PAGESIZE */
      {
        temp = NumOfSingle - count;
        QSPI_DataNum = count;
        QSPI_WritePage(Address, QSPI_DataNum, buffer);
        Address +=  count;
        buffer += count;
        
        QSPI_DataNum = temp;
        QSPI_WritePage(Address, QSPI_DataNum, buffer);
      }
      else
      {
        QSPI_DataNum = Size; 
        QSPI_WritePage(Address, QSPI_DataNum, buffer);
      }
    }
    else /*!< Size > QSPI_PAGESIZE */
    {
      Size -= count;
      NumOfPage =  Size / QSPI_PAGE_SIZE;
      NumOfSingle = Size % QSPI_PAGE_SIZE;

      QSPI_DataNum = count;
        
      QSPI_WritePage(Address, QSPI_DataNum, buffer);
      Address +=  count;
      buffer += count;

      while (NumOfPage--)
      {
        QSPI_DataNum = QSPI_PAGE_SIZE;
        
        QSPI_WritePage(Address, QSPI_DataNum, buffer);
        Address +=  QSPI_PAGE_SIZE;
        buffer += QSPI_PAGE_SIZE;
      }

      if (NumOfSingle != 0)
      {
        QSPI_DataNum = NumOfSingle;
        
        QSPI_WritePage(Address, QSPI_DataNum, buffer);
      }
    }
  }

  return 1;
}


/**
  * @brief   Sector erase.
  * @param   EraseStartAddress :  erase start address
  * @param   EraseEndAddress   :  erase end address
  * @retval  None
  */
KeepInCompilation int SectorErase (uint32_t EraseStartAddress ,uint32_t EraseEndAddress)
{
  uint32_t BlockAddr;
  EraseStartAddress = EraseStartAddress -  EraseStartAddress % 0x10000;
	
  while (EraseEndAddress>=EraseStartAddress)
  {
    BlockAddr = EraseStartAddress & 0x0FFFFFFF;
    QUADSPI_EraseSector(BlockAddr);
    EraseStartAddress += 0x10000;
  }
  
  return 1;	
}


/**
  * Description :
  * Calculates checksum value of the memory zone
  * Inputs    :
  *      StartAddress  : Flash start address
  *      Size          : Size (in WORD)  
  *      InitVal       : Initial CRC value
  * outputs   :
  *     R0             : Checksum value
  * Note: Optional for all types of device
  */
uint32_t CheckSum(uint32_t StartAddress, uint32_t Size, uint32_t InitVal)
{
  uint8_t missalignementAddress = StartAddress%4;
  uint8_t missalignementSize = Size ;
  int cnt;
  uint32_t Val;
	
  StartAddress-=StartAddress%4;
  Size += (Size%4==0)?0:4-(Size%4);
  
  for(cnt=0; cnt<Size ; cnt+=4)
  {
    Val = *(uint32_t*)StartAddress;
    if(missalignementAddress)
    {
      switch (missalignementAddress)
      {
        case 1:
          InitVal += (uint8_t) (Val>>8 & 0xff);
          InitVal += (uint8_t) (Val>>16 & 0xff);
          InitVal += (uint8_t) (Val>>24 & 0xff);
          missalignementAddress-=1;
          break;
        case 2:
          InitVal += (uint8_t) (Val>>16 & 0xff);
          InitVal += (uint8_t) (Val>>24 & 0xff);
          missalignementAddress-=2;
          break;
        case 3:   
          InitVal += (uint8_t) (Val>>24 & 0xff);
          missalignementAddress-=3;
          break;
      }  
    }
    else if((Size-missalignementSize)%4 && (Size-cnt) <=4)
    {
      switch (Size-missalignementSize)
      {
        case 1:
          InitVal += (uint8_t) Val;
          InitVal += (uint8_t) (Val>>8 & 0xff);
          InitVal += (uint8_t) (Val>>16 & 0xff);
          missalignementSize-=1;
          break;
        case 2:
          InitVal += (uint8_t) Val;
          InitVal += (uint8_t) (Val>>8 & 0xff);
          missalignementSize-=2;
          break;
        case 3:   
          InitVal += (uint8_t) Val;
          missalignementSize-=3;
          break;
      } 
    }
    else
    {
      InitVal += (uint8_t) Val;
      InitVal += (uint8_t) (Val>>8 & 0xff);
      InitVal += (uint8_t) (Val>>16 & 0xff);
      InitVal += (uint8_t) (Val>>24 & 0xff);
    }
    StartAddress+=4;
  }
  
  return (InitVal);
}


/**
  * Description :
  * Verify flash memory with RAM buffer and calculates checksum value of
  * the programmed memory
  * Inputs    :
  *      FlashAddr     : Flash address
  *      RAMBufferAddr : RAM buffer address
  *      Size          : Size (in WORD)  
  *      InitVal       : Initial CRC value
  * outputs   :
  *     R0             : Operation failed (address of failure)
  *     R1             : Checksum value
  * Note: Optional for all types of device
  */
KeepInCompilation uint64_t Verify (uint32_t MemoryAddr, uint32_t RAMBufferAddr, uint32_t Size, uint32_t missalignement)
{
  uint32_t VerifiedData = 0, InitVal = 0;
  uint64_t checksum;
  Size*=4;
  QSPI_MemoryMappedTypeDef sMemMappedCfg;
  QSPIHandle.Init.ClockPrescaler     = 0;
  QSPIHandle.Init.FifoThreshold      = 4;
  QSPIHandle.Init.SampleShifting     = QSPI_SAMPLE_SHIFTING_NONE;
  QSPIHandle.Init.FlashSize          = 0x1F;
  QSPIHandle.Init.ChipSelectHighTime = QSPI_CS_HIGH_TIME_1_CYCLE;
  QSPIHandle.Init.ClockMode          = QSPI_CLOCK_MODE_0;  
  
  /* Configure Volatile Configuration register (with new dummy cycles) */
  QSPIHandle.State = HAL_QSPI_STATE_READY;
  QSPI_DummyCyclesCfg(&QSPIHandle); 
  
  sCommand.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
  sCommand.AddressSize       = QSPI_ADDRESS_32_BITS;
  sCommand.AddressMode       = QSPI_ADDRESS_4_LINES;
  sCommand.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  sCommand.AlternateBytesSize= QSPI_ALTERNATE_BYTES_8_BITS;
  sCommand.DataMode          = QSPI_DATA_4_LINES;
  sCommand.DdrMode           = QSPI_DDR_MODE_DISABLE;
  sCommand.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
  sCommand.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;
  sCommand.DummyCycles       = DUMMY_CLOCK_CYCLES_READ_QUAD;
  sCommand.Instruction       = QUAD_INOUT_FAST_READ_CMD;

  sMemMappedCfg.TimeOutActivation = QSPI_TIMEOUT_COUNTER_DISABLE; 
  QSPIHandle.State = HAL_QSPI_STATE_READY;
  HAL_QSPI_MemoryMapped(&QSPIHandle, &sCommand, &sMemMappedCfg);
  checksum = CheckSum((uint32_t)MemoryAddr + (missalignement & 0xf), Size - ((missalignement >> 16) & 0xF), InitVal);
  while (Size>VerifiedData)
  {
    if ( *(uint8_t*)MemoryAddr++ != *((uint8_t*)RAMBufferAddr + VerifiedData))
      return ((checksum<<32) + (MemoryAddr + VerifiedData));  
   
    VerifiedData++;  
  }
        
  return (checksum<<32);
}

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follows :
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 80000000
  *            HCLK(Hz)                       = 80000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 1
  *            APB2 Prescaler                 = 1
  *            HSE Frequency(Hz)              = 8000000
  *            PLL_M                          = 1
  *            PLL_N                          = 20
  *            PLL_P                          = 7
  *            PLL_Q                          = 4
  *            PLL_R                          = 2
  *            Flash Latency(WS)              = 4
  * @param  None
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};

  /* Enable HSE Oscillator and activate PLL with HSE as source   */
  /* (Default MSI Oscillator enabled at system reset remains ON) */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 20;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLP = 7;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4);
}


/**
  * @brief  This function send a Write Enable command.
  * @param  hqspi: QSPI handle
  * @retval None
  */
void QSPI_WriteEnable(QSPI_HandleTypeDef *hqspi)
{
  QSPI_CommandTypeDef     sCommand;
  QSPI_AutoPollingTypeDef sConfig;

  /* Enable write operations ------------------------------------------ */
  sCommand.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
  sCommand.Instruction       = WRITE_ENABLE_CMD;
  sCommand.AddressMode       = QSPI_ADDRESS_NONE;
  sCommand.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  sCommand.DataMode          = QSPI_DATA_NONE;
  sCommand.DummyCycles       = 0;
  sCommand.DdrMode           = QSPI_DDR_MODE_DISABLE;
  sCommand.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
  sCommand.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;
  QSPIHandle.State           = HAL_QSPI_STATE_READY;
  HAL_QSPI_Command(&QSPIHandle, &sCommand, HAL_QPSI_TIMEOUT_DEFAULT_VALUE);
  
  /* Configure automatic polling mode to wait for write enabling ---- */  
  sConfig.Match           = 0x02;
  sConfig.Mask            = 0x02;
  sConfig.MatchMode       = QSPI_MATCH_MODE_AND;
  sConfig.StatusBytesSize = 1;
  sConfig.Interval        = 0x10;
  sConfig.AutomaticStop   = QSPI_AUTOMATIC_STOP_ENABLE;

  sCommand.Instruction    = READ_STATUS_REG_CMD;
  sCommand.DataMode       = QSPI_DATA_1_LINE;
  QSPIHandle.State        = HAL_QSPI_STATE_READY;
  HAL_QSPI_AutoPolling(&QSPIHandle, &sCommand, &sConfig, HAL_QPSI_TIMEOUT_DEFAULT_VALUE);
}


/**
  * @brief   Wait until timeout.
  * @param   hqspi  : QSPI handle
  * @param   Flag   : QSPI flag
  * @param   State  : state of the flag
  * @param   Timeout: wait timeout
  * @retval  1      : Operation succeeded
  * @retval  0      : Operation failed
  */
HAL_StatusTypeDef QSPI_WaitFlagStateUntilTimeout(QSPI_HandleTypeDef *hqspi, uint32_t Flag, FlagStatus State, uint32_t Timeout)
{
  uint32_t tickstart = HAL_GetTick();
  
  /* Wait until flag is in expected state */    
  
  while((FlagStatus)(__HAL_QSPI_GET_FLAG(hqspi, Flag)) != State)
  {
    /* Check for the Timeout */
    if (Timeout != HAL_MAX_DELAY)
    {
      if((Timeout == 0) || ((HAL_GetTick() - tickstart) > Timeout))
      {
        hqspi->State     = HAL_QSPI_STATE_ERROR;
        hqspi->ErrorCode |= HAL_QSPI_ERROR_TIMEOUT;
        
        return HAL_TIMEOUT;
      }
    }
  }
  return HAL_OK;
}


/**
  * @brief   Write QSPI memory page.
  * @param   Address: page address
  * @param   Size   : size of data
  * @param   buffer : pointer to data buffer
  * @retval  None
  */
void QSPI_WritePage(uint32_t Address, uint32_t Size , uint8_t* buffer)
{ 
  if (Size == 0)
    return;
  /* Disable QSPI */
  uint32_t cr = QSPIHandle.Instance->CR;
  cr &=0xFFFFFFFE;
  WRITE_REG(QSPIHandle.Instance->CR, cr);
  
  /* Configure auto polling mode */
  WRITE_REG(QSPIHandle.Instance->CCR, 0x09003105);
  
  /* Clear SM flag */
  QSPIHandle.Instance->FCR = QSPI_FLAG_SM;
  
  /* Set address */
  WRITE_REG(QSPIHandle.Instance->AR, Address);
  
  /* Enable QSPI */
  QSPIHandle.Instance->CR |= 1; 
  
  /* Enable the write access to the NOR_FLASH */	
  QSPI_WriteEnable(&QSPIHandle);
  
  /* Set data length */
  WRITE_REG(QSPIHandle.Instance->DLR, (Size - 1));
  /* clear CR */
  WRITE_REG(QSPIHandle.Instance->CR, 0x00400001);
  /* Configure indirect write mode */
  WRITE_REG(QSPIHandle.Instance->CCR, 0x03003532);

  /* Send data */
  while(Size--)
  {
    if(QUADSPI_GetFlagStatus(QSPI_FLAG_FT))
      QUADSPI_SendData8(* buffer++);
  }
	
  Size = 0;

  /* Clear TC flag */
  QSPIHandle.Instance->FCR = QSPI_FLAG_TC; 
  /* Reset data length */
  QSPIHandle.Instance->DLR  = 0x00;
  /* Disable QSPI */
  QSPIHandle.Instance->CR |= 0x00400000;
  /* Disable QSPI */
  QSPIHandle.Instance->DLR  = 0x00;
  
  /* Configure automatic polling mode to wait for write enabling ---- */
  WRITE_REG(QSPIHandle.Instance->PSMKR, 0x01);
  WRITE_REG(QSPIHandle.Instance->PSMAR, 0x0);
  WRITE_REG(QSPIHandle.Instance->CCR, 0x09003105);
  
  while(QUADSPI_GetFlagStatus(QSPI_FLAG_SM)==RESET);
  /*  Clear SM flag */
  QSPIHandle.Instance->FCR = QSPI_FLAG_SM;
  while(QUADSPI_GetFlagStatus(QSPI_FLAG_BUSY)==SET);
}



/**
  * @brief   Erase sector.
  * @param   address :  sector address
  * @retval  1       : Operation succeeded
  * @retval  0       : Operation failed
  */
int QUADSPI_EraseSector(uint32_t address)
{
  QSPI_CommandTypeDef      sCommand;
  QSPI_AutoPollingTypeDef sConfig;
  
  /* Disable QSPI */
  uint32_t cr = QSPIHandle.Instance->CR;
  cr &=0xFFFFFFFE;
  WRITE_REG(QSPIHandle.Instance->CR, cr);
  
  /* Configure Auto polling mode */
  WRITE_REG(QSPIHandle.Instance->CCR, 0x09003105);

  /* Clear SM flag */
  QSPIHandle.Instance->FCR = QSPI_FLAG_SM;
  
  /* Set Address */
  WRITE_REG(QSPIHandle.Instance->AR, address);
  
  /* Enable QSPI */
  QSPIHandle.Instance->CR |= 1; 
  
  /* Enable Write */
  QSPI_WriteEnable(&QSPIHandle);

  sCommand.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
  sCommand.AddressSize       = QSPI_ADDRESS_32_BITS;
  sCommand.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  sCommand.DdrMode           = QSPI_DDR_MODE_DISABLE;
  sCommand.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
  sCommand.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;
  /* Erasing Sequence -------------------------------------------------- */
  sCommand.Instruction = SECTOR_ERASE_CMD;
  sCommand.AddressMode = QSPI_ADDRESS_1_LINE;
  sCommand.Address     = address;
  sCommand.DataMode    = QSPI_DATA_NONE;
  sCommand.DummyCycles = 0;
  QSPIHandle.State     = HAL_QSPI_STATE_READY;
  HAL_QSPI_Command(&QSPIHandle, &sCommand, 0x100);

  /* Configure Auto polling mode */
  WRITE_REG(QSPIHandle.Instance->CCR, 0x09003105);
  
  /* Clear CR */
  WRITE_REG(QSPIHandle.Instance->CR, 0x00400001);
  
  /* Reset data length to zero */
  QSPIHandle.Instance->DLR  = 0x00;
  
  /* Clear SM flag */
  QSPIHandle.Instance->FCR = QSPI_FLAG_SM;
  
  sConfig.Match           = 0x00;
  sConfig.Mask            = 0x01;
  sConfig.MatchMode       = QSPI_MATCH_MODE_AND;
  sConfig.AutomaticStop   = QSPI_AUTOMATIC_STOP_ENABLE;

  sCommand.Instruction    = READ_STATUS_REG_CMD;
  sCommand.DataMode       = QSPI_DATA_1_LINE; 
  QSPIHandle.State        = HAL_QSPI_STATE_READY;
  HAL_QSPI_AutoPolling(&QSPIHandle, &sCommand, &sConfig, HAL_QPSI_TIMEOUT_DEFAULT_VALUE);
  
  /* Reset data length */ 
  QSPIHandle.Instance->DLR  = 0x00;
  
  while(QUADSPI_GetFlagStatus(QSPI_FLAG_SM)==RESET);
  /* Clear SM flag */
  QSPIHandle.Instance->FCR = QSPI_FLAG_SM;  
  while(QUADSPI_GetFlagStatus(QSPI_FLAG_BUSY)==SET);
  
  return 1;
}



/**
  * @brief   Reset memory.
  * @param   hqspi : pointer to QSPI handle
  * @retval  None
  */
void ResetMemory(QSPI_HandleTypeDef *hqspi)
{
/* Reset memory config, Cmd in 1 line */
    /* Send RESET ENABLE command (0x66) to be able to reset the memory registers */
    while(QSPIHandle.Instance->SR & QSPI_FLAG_BUSY);  /* Wait for busy flag to be cleared */
    QSPIHandle.Instance->CCR = 0x2166;
    QSPIHandle.Instance->AR = 0;
    QSPIHandle.Instance->ABR = 0;
    QSPIHandle.Instance->DLR = 0;
    __DSB(); 
     
     /* Send RESET command (0x99) to reset the memory registers */
    while(QSPIHandle.Instance->SR & QSPI_FLAG_BUSY);  /* Wait for busy flag to be cleared */
    QSPIHandle.Instance->CCR = 0x2199;
    QSPIHandle.Instance->AR = 0;
    QSPIHandle.Instance->ABR = 0;
    QSPIHandle.Instance->DLR = 0;
    __DSB();

/* Reset memory config, Cmd in 2 lines*/
    /* Send RESET ENABLE command (0x66) to be able to reset the memory registers */
    while(QSPIHandle.Instance->SR & QSPI_FLAG_BUSY);  /* Wait for busy flag to be cleared */
    QSPIHandle.Instance->CCR = 0x2266;
    QSPIHandle.Instance->AR = 0;
    QSPIHandle.Instance->ABR = 0;
    QSPIHandle.Instance->DLR = 0;
    __DSB(); 
     
     /* Send RESET command (0x99) to reset the memory registers */
    while(QSPIHandle.Instance->SR & QSPI_FLAG_BUSY);  /* Wait for busy flag to be cleared */
    QSPIHandle.Instance->CCR = 0x2299;
    QSPIHandle.Instance->AR = 0;
    QSPIHandle.Instance->ABR = 0;
    QSPIHandle.Instance->DLR = 0;
    __DSB();
    
      /* Reset memory config, Cmd in 4 lines*/
    /* Send RESET ENABLE command (0x66) to be able to reset the memory registers */
    while(QSPIHandle.Instance->SR & QSPI_FLAG_BUSY);  /* Wait for busy flag to be cleared */
    QSPIHandle.Instance->CCR = 0x2366;
    QSPIHandle.Instance->AR = 0;
    QSPIHandle.Instance->ABR = 0;
    QSPIHandle.Instance->DLR = 0;
    __DSB(); 
     
     /* Send RESET command (0x99) to reset the memory registers */
    while(QSPIHandle.Instance->SR & QSPI_FLAG_BUSY);  /* Wait for busy flag to be cleared */
    QSPIHandle.Instance->CCR = 0x2399;
    QSPIHandle.Instance->AR = 0;
    QSPIHandle.Instance->ABR = 0;
    QSPIHandle.Instance->DLR = 0;
    __DSB();
}


/**
  * @brief   Send data.
  * @param   Data
  * @retval  None
  */
void QUADSPI_SendData8(uint8_t Data)
{
  uint32_t quadspibase = 0;

  quadspibase = (uint32_t)QSPIHandle.Instance; 
  quadspibase += 0x20;
  
  *(__IO uint8_t *) quadspibase = Data;
}


/**
  * @brief   Returns QSPI flag status.
  * @param   QUADSPI_FLAG : QSPI flag
  * @retval  FlagStatus
  */
FlagStatus QUADSPI_GetFlagStatus(uint32_t QUADSPI_FLAG)
{
  FlagStatus bitstatus = RESET;
  /* Check the parameters */
  assert_param(IS_QUADSPI_GET_FLAG(QUADSPI_FLAG));

  /* Check the status of the specified QUADSPI flag */
  if (QSPIHandle.Instance->SR & QUADSPI_FLAG)
  {
    /* QUADSPI_FLAG is set */
    bitstatus = SET;
  }
  else
  {
    /* QUADSPI_FLAG is reset */
    bitstatus = RESET;
  }
  /* Return the QUADSPI_FLAG status */
  return  bitstatus;
}


/**
  * @brief   configure dummy cycles.
  * @param   hqspi : pointer to QSPI handle
  * @retval  None
  */
void QSPI_DummyCyclesCfg(QSPI_HandleTypeDef *hqspi)
{
  QSPI_CommandTypeDef sCommand;
  uint8_t reg;

  /* Read Volatile Configuration register --------------------------- */
  sCommand.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
  sCommand.Instruction       = READ_VOL_CFG_REG_CMD;
  sCommand.AddressMode       = QSPI_ADDRESS_NONE;
  sCommand.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  sCommand.DataMode          = QSPI_DATA_1_LINE;
  sCommand.DummyCycles       = 0;
  sCommand.DdrMode           = QSPI_DDR_MODE_DISABLE;
  sCommand.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
  sCommand.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;
  sCommand.NbData            = 1;
  QSPIHandle.State           = HAL_QSPI_STATE_READY;
  HAL_QSPI_Command(&QSPIHandle, &sCommand, HAL_QPSI_TIMEOUT_DEFAULT_VALUE);

  HAL_QSPI_Receive(&QSPIHandle, &reg, HAL_QPSI_TIMEOUT_DEFAULT_VALUE);

  /* Enable write operations ---------------------------------------- */
  QSPI_WriteEnable(&QSPIHandle);

  /* Write Volatile Configuration register (with new dummy cycles) -- */  
  sCommand.Instruction = WRITE_VOL_CFG_REG_CMD;
  MODIFY_REG(reg, 0xF0, (DUMMY_CLOCK_CYCLES_READ_QUAD << POSITION_VAL(0xF0)));
  QSPIHandle.State = HAL_QSPI_STATE_READY;
  HAL_QSPI_Command(&QSPIHandle, &sCommand, HAL_QPSI_TIMEOUT_DEFAULT_VALUE);

  HAL_QSPI_Transmit(&QSPIHandle, &reg, HAL_QPSI_TIMEOUT_DEFAULT_VALUE);
}


void HAL_MspInit(void)
{
  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_MspInit could be implemented in the user file
   */
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
