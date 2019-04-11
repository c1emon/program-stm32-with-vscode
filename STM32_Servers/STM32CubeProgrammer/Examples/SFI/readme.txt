/**
  @page STM32Programmer SFI Install example
 
  @verbatim
  ******************************************************************************
  * @file    stm32_programmer_package_v0.4.0/Examples/SFI/readme.txt
  * @author  MCD Tools Team
  * @version V0.4.0
  * @date    05-June-2017 
  * @brief   Description of the STM32Programmer SFI Install example.
  ******************************************************************************
  *
  * Copyright (c) 2016 STMicroelectronics International N.V. All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 2. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 3. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  @endverbatim

@par Example Description

This folder contains batch files that show how to program an SFI file.

@par Directory contents
    - stm32_programmer_package_v0.4.0/Examples/SFI/data.sfi    		        	SFI file
    - stm32_programmer_package_v0.4.0/Examples/SFI/data_combined.sfi        	Combined SFI-SMI file
    - stm32_programmer_package_v0.4.0/Examples/SFI/bootloader_version.bin		Bootloader version file
    - stm32_programmer_package_v0.4.0/Examples/SFI/TUNCWD0075.crt				Server certificate file
    - stm32_programmer_package_v0.4.0/Examples/SFI/SFI_LicenseServer.bat        Batch file to perform SFI install from license server
    - stm32_programmer_package_v0.4.0/Examples/SFI/SFIComb_LicenseServer.bat    Batch file to perform combined SFI-SMI image install from license server
	
@par How to use it ?
Before performing an SFI install be sure that :
 - No PCROPed zone is active, otherwise destroy this PCROPed area using STLink Utility (v4.0.5.2 or newer)
 - The security bit in option bytes is enabled.

In order to program an SFI file from the existent example, you should execute the batch file "SFI_LicenseServer.bat".
The batch file use relative paths to locate Programming tool executable file and input files. Any changes in these 
paths need to be applied in the batch files.

After programming SFI file, in order to perform a functionnal test open an uart terminal then do a hardware reset you should see printf packets on uart terminal.

In batch file in folder example please update the UART port name according to the one on the used test machine
 
 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
