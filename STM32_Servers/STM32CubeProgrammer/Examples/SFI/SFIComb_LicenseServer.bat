	@echo off
	TITLE SFI_SMI_INSTALL_INTERFACE
    rem ======SFI use case======
	set /A FwId=112
	set /A ModId=456
	set user="ProgHouse1"
	set SFIimg="sfi"
	set SMIimg="smi"
	set SFILicensePath=ServerlicenseSFIComb.bin
	set SMILicensePath=ServerlicenseSMI.bin
	set ImgPath=ServerdataComb.sfi
	rem ======User config======
	set portName="COM5"
	set certif=test_certificate.bin
	set Vbl=bootloader_version.bin
	set ServerCertifPath=TUNCWD0075.crt
	rem set /A combined=0
	set /A GetImg=1
	echo ------------------------------------------------------
	echo         Welcome to SFI/SMI install Interface 
	echo ------------------------------------------------------
	echo time now is %time%
	if %FwId%=='' goto :End
	if %user%=='' goto :End
	if %img%=='' goto :End


	
	if %GetImg%==1 goto :GetImg
	else goto :GetCertificate

	:GetImg
	echo Requesting encrypted image with ID %FwId% for user %user%
	"../Tools/curl.exe" -o %ImgPath% --cacert %ServerCertifPath% https://tuncwd0075:8090/fw/%SFIimg%/%FwId%/get/image?user=%user% 
	
	:GetCertificate
	echo Requesting Chip Certificate from connected device...
	"bin/STM32_Programmer_CLI.exe" -c port=%portName% -gc %certif% -log
	
	:GetSFILicense
	echo Requesting License for encrypted SFI image with ID %FwId% for user %user%
	"../Tools/curl.exe" -X POST --form dev_certificate_file=@%certif% --form dev_bootloader_file=@%Vbl%  -o %SFILicensePath% --cacert %ServerCertifPath% https://tuncwd0075:8090/fw/%SFIimg%/%FwId%/get/license?user=%user%

	:GetSMILicense
	echo Requesting License for encrypted SMI module with ID %ModId% for user %user%
	"../Tools/curl.exe" -X POST --form dev_certificate_file=@%certif% --form dev_bootloader_file=@%Vbl%  -o %SMILicensePath% --cacert %ServerCertifPath% https://tuncwd0075:8090/fw/%SMIimg%/%ModId%/get/license?user=%user%

	:Install
	 "bin/STM32_Programmer_CLI.exe" -c port=%portName% noinit=1 br=115200 -%img%  protocol=static "%ImgPath%" "%SFILicensePath%" "%SMILicensePath%" -log

	goto :End

	:End
	echo ---------------------------------
	echo Processing request Finished
	rem secho time now is %time%
	pause
