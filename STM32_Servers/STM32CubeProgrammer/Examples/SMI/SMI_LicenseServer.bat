	@echo off
	TITLE SFI_SMI_INSTALL_INTERFACE
    rem ======SMI use case======
	set /A FwId=666
	set user="Maker1"
	set img="smi"
	set LicensePath=ServerlicenseSMI.bin
	set ImgPath=Serverdata.smi
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
	"../Tools/curl.exe" -o %ImgPath% --cacert %ServerCertifPath% https://tuncwd0075:8090/fw/%img%/%FwId%/get/image?user=%user% 
	
	:GetCertificate
	echo Requesting Chip Certificate from connected device...
	"../../bin/STM32_Programmer_CLI.exe" -c port=%portName% -gc %certif% -log
	
	:GetLicense
	echo Requesting License for encrypted image with ID %FwId% for user %user%
	"../Tools/curl.exe" -X POST --form dev_certificate_file=@%certif% --form dev_bootloader_file=@%Vbl%  -o %LicensePath% --cacert %ServerCertifPath% https://tuncwd0075:8090/fw/%img%/%FwId%/get/license?user=%user%

	
	:Install
	"../../bin/STM32_Programmer_CLI.exe" -c port=%portName% noinit=1 br=115200 -%img%  protocol=static "%ImgPath%" "%LicensePath%" -log

	goto :End

	:End
	echo ---------------------------------
	echo Processing request Finished
	rem secho time now is %time%
	pause
