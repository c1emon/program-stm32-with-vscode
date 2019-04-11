# program-stm32-with-vscode
gcc+gdb+st-link+hal+vs-code

# VS CODE+GCC+GDB进行STM32(HAL)编程
## 1.环境配置
常用的stm32开发环境有以下几种：
1. KEIL+SPL(标准库)
2. IAR/ECILPS+SW4STM32
3. TrueStudio+HAL(HAL库)
4. arm-none-eabi-gcc+arm-none-eabi-gdb+编辑器+HAL(HAL库)

不仅kile IDE有破解限制、keil自带文本编辑器难以使用，还由于ST(意法半导体)官方强推HAL库和CubeMX等工具，本次选择第四种方式搭建开发环境。完全的开源方案，适合个人定制。
由于此方案涉及到编译相关，难度较大，请自行斟酌。

本机环境为WIN10 1809 64Bit。理论上linux系统配置更简单方便。需要软件VS CODE、MSYS2、gcc-arm-none-eabi-gcc和从True Studio内提取的ST-LINK_gdbserver(已上传至github仓库)。

---

1. 安装MSYS2。
因为需要使用make、rm等命令，所以安装msys2。我安装在C:\msys64目录下。更新msys2的源为国内源。打开msys的命令行运行pacman -Sy刷新源缓存。运行pacman -S make安装make工具(该处命令都属于Arch Linux系，自行查阅)。安装完毕后执行make -v应该可以输出make的版本信息。例如：
![image](https://github.com/cjw7360/program-stm32-with-vscode/raw/master/img_src2.png)
&emsp;&emsp;进入win10系统环境变量设置。在path中添加msys2可执行文件的路径。
![image](https://github.com/cjw7360/program-stm32-with-vscode/raw/master/img_src/1.png)

至此，msys2环境安装完毕。

---

2. arm-none-eabi-gcc安装
该编译器无需exe文件进行安装，去官网下载解压到合适路径即可。
推荐安装gcc-arm-none-eabi-7-2018-q2-update-win32，最新本gcc由于bug原因生成.hex文件时会报错。安装完成后将编译器路径(例如：C:\msys64\home\63143\gcc-arm-none-eabi-7-2018-q2-update-win32\bin)添加至系统path
![image](https://github.com/cjw7360/program-stm32-with-vscode/raw/master/img_src/3.png)

---

3. 安装vocode
官方vscode即可，自行安装arm、c\c++插件即可。vscode自动读取win10系统path。

---

4. 测试环境
重启后打开powershell。执行arm-none-eabi-gcc -v和make -v应有以下输出
![image](https://github.com/cjw7360/program-stm32-with-vscode/raw/master/img_src/4.png)
至此基础开发环境搭建完成。

---

---


## 2.HAL库生成和修改                                                                                   
1. 这里我使用STM32 CubeMX生成hal库，注意生成时选择生成Makefile类型的工程，并且在设置高级选项中勾选拷贝所有文件至工程目录。github库中将提供stm32f429的工程模板。

* 新建工程
在system core设置下选择使用外部晶振(HSE)

![image](https://github.com/cjw7360/program-stm32-with-vscode/raw/master/img_src/5.png)
其他外设自行选择。此处我选择初始化GPIO、TIM2和USART1。

* 配置系统时钟树
我的板子外置时钟为8Mhz，所以Input frequency配置为8Mhz。
其他可由Resolve Clock Issues自动配置。
![image](https://github.com/cjw7360/program-stm32-with-vscode/raw/master/img_src/6.png)

* 配置生成选项
此处Toolchain选择Makefile，其他名称路径可自定义，路径中不要包含中文。
![image](https://github.com/cjw7360/program-stm32-with-vscode/raw/master/img_src/7.png)
左侧Code Generator中选择Copy all used libraries into the project fioder，勾选Generate peripheral initiailzation as a pair of '.c/.h' files per peripheral。

![image](https://github.com/cjw7360/program-stm32-with-vscode/raw/master/img_src/8.png)

* 生成工程文件
点击GENERATE CODE生成。

----

2. 修改工程文件
* 串口1上启用printf函数
在keil中我们通过重写fputc函数、勾选启用microLib来重载输出流。而使用arm-gcc编译器需要重载__io_putchar函数并添加syscalls.c源文件。
首先在usart.c中包含stdio.h头文件，在下方用户代码区重写函数：
```
/* USER CODE BEGIN 1 */
// reload function of printf
int __io_putchar(int ch)
{
    HAL_UART_Transmit(&huart1, (uint8_t *)(&ch), 1, 0xffff);
    return ch;
}
/* USER CODE END 1 */
```
该函数是syscalls.c中定义的一个weak类型的函数，可以被重载。且会被该源文件内_write函数调用。生成的makefile工程不带有syscalls.c文件，可以使用cubemx生成Truestudio工程，从其中提取该文件，已经提取该文件。将该文件放入Core/Src目录下。因为使用makefile编译，所以还要将新增源文件添加至makefile源文件编译列表。
打开makefile文件，建议不要使用windows记事本打开，可以使用vscode或者notepad++。在大约38行处C_SOURCES处添加一行Core/Src/syscalls.c \。如图：

![image](https://github.com/cjw7360/program-stm32-with-vscode/raw/master/img_src/9.png)
为了让printf函数可以进行浮点输出，还需要在链接器中添加-u_printf_float选项。
![image](https://github.com/cjw7360/program-stm32-with-vscode/raw/master/img_src/10.png)

测试：
main函数片段：
```
/* Initialize all configured peripherals */
    MX_GPIO_Init();
    MX_USART1_UART_Init();
    MX_TIM2_Init();
/* USER CODE BEGIN 2 */
    printf("system boot success.\n");
    printf("testing int %d\n", 32);
    printf("testing float %f\n",3.1414926);
/* USER CODE END 2 */
```
执行结果：
![image](https://github.com/cjw7360/program-stm32-with-vscode/raw/master/img_src/11.png)

---

* 添加其他hal库外设源文件
方法参考syscalls.c的添加，头文件路径需要被包含在makefile的C_INCLUDE中，源文件需要被添加到C_SOURCES中。

---

* 启用DSP Lib
stm32f4系列有浮点处理单元，并且官方提供了dsp库。经测试直接包含math.h库来调用函数无法使用，需要使用arm_math.h库。对于有硬件浮点的cpu，对应头文件stm32f4xxxx.h中宏定义__FPU_PRESENT应为1U，表示具有硬件浮点。例如stm32f429中，在stm32f429xx.h中可找到如下字段：

![image](https://github.com/cjw7360/program-stm32-with-vscode/raw/master/img_src/12.png)
确认此处设置无误后，打开core_cm4.h文件(其他芯片自行选择对应核心文件)。我们使用gcc编译器，所以默认编译器标志宏定义为__GUNC__，约在151行处有判断是否启用硬件浮点的条件编译
```
#elif defined ( __GNUC__ )
#if defined (__VFP_FP__) && !defined(__SOFTFP__)
    #if (__FPU_PRESENT == 1U)
        //in vscode, here looks like will not be compile.But it will!I think it is vscode's bug!!!
        #define __FPU_USED 1U
    #else
        #error "Compiler generates FPU instructions for a device without an FPU (check __FPU_PRESENT)"
        #define __FPU_USED 0U
    #endif
    #else
        #define __FPU_USED 0U
#endif
```
因为__FPU_PRESENT标志定义在stm32f429xx.h中，但是core_cm4.h没有包含该文件，所以默认硬件浮点是关闭的。所以在文件头部包含stm32f429xx.h。

![image](https://github.com/cjw7360/program-stm32-with-vscode/raw/master/img_src/13.png)
个人认为这里应该由条件编译自动包含对应头文件，不知道为什么st官方没有处理好。
库文件修改完毕，接下来修改makefile文件。
在makefile文件约109行处可以找到C_DEFS条目。原始条目应该是:
```
# C defines
C_DEFS = \
-DUSE_HAL_DRIVER \
-DSTM32F429xx
```
为支持dsp lib，修改成:
```
# C defines
C_DEFS = \
-DUSE_HAL_DRIVER \
-DSTM32F429xx \
-DARM_MATH_CM4 \
-D__VFP_FP__ \
-DARM_MATH_MATRIX_CHECK \
-DARM_MATH_ROUNDING
```
其中第三条和第四条必须添加。
接下来添加arm的数学库。
在Drivers/CMSIS/Lib/GCC目录下可以看到两个文件
> libarm_cortexM4l_math.a
> libarm_cortexM4lf_math.a

这是已经编译过的库。libarm_cortexM4l_math.a由大端模式使用，libarm_cortexM4lf_math.a
由小端模式使用。多数情况下都是小端模式。
在makefile约153行LIBDIR条目处添加
> -L ./ Drivers/CMSIS/Lib/GCC/libarm_cortexM4lf_math.a

如图：

![image](https://github.com/cjw7360/program-stm32-with-vscode/raw/master/img_src/14.png)
至此dsp lib设置完成，在需要的地方包含arm_math.h即可使用dsp库。

---

---

## 3.vs code设置
* gdb服务器设置
一开始希望使用openocd作为gdb服务器进行在线硬件调试。但是无论怎样都不能连接板卡。之前使用Truestudio时发现在其根目录下有一个Services文件夹，里面有J-Link_gdbserver、ST-LINK_gdbserver、STM32CubeProgrammer三个文件夹。我的官方demo板自带stlink，所以选择这里的ST-LINK_gdbserver作为调试服务器。在使用ST-LINK_gdbserver时会调用STM32CubeProgrammer内的文件，所以不要修改任何文件，包括目录结构。
我选择将Services文件夹放在msys2的~目录下，并重命名为STM32_Servers文件夹。
打开msys2的中端，在/bin目录下新建st-link-gdb-server.sh文件，添加内容：
> cd /c/msys64/home/63143/STM32_Servers/ST-LINK_gdbserver/
> ./ST-LINK_gdbserver.exe -c config.txt

这样就可以直接运行st-link-gdb-server.sh来启动gdb server。默认gdb调试端口为localhost:6123。

---
使用vs code打开上一步新建工程文件夹。

![image](https://github.com/cjw7360/program-stm32-with-vscode/raw/master/img_src/15.png)
 
* c_cpp_properties.json文件
该文件关系到自动补全等，设置错误会引起错误的提示。最重要的是这里的是全局宏定义defines的设置，应与makefile中C_DEFS的内容相同。
```
{
        "configurations": [
            {
                "name": "ARM STM32",
                "includePath": [
                    "${workspaceFolder}/**"
                ],
                "defines": [
                    "_DEBUG",
                    "UNICODE",
                    "_UNICODE",
                    "__GNUC__",
                    "STM32F429xx",
                    "USE_HAL_DRIVER",
                    "ARM_MATH_CM4",
                    "__VFP_FP__"
                ],
                "compilerPath": "C:/msys64/home/63143/gcc-arm-none-eabi-7-2018-q2-update-win32/bin/arm-none-eabi-gcc.exe",
                "cStandard": "c11",
                "cppStandard": "c++17",
                "intelliSenseMode": "clang-x64"
            }
        ],
        "version": 4
}
```
我的设置如上。compilerPath设置为arm-gcc路径即可，注意windows下/和\区别。

---

* tasks.json文件
该文件中可以定义一些任务进行调用。如下：
```
{
    "tasks": [
        {
            "type": "shell",
            "label": "build",
            "command": "make",
            "args": ["-j4"],
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "type": "shell",
            "label": "clean",
            "command": "make",
            "args": ["clean"],
            "problemMatcher": [
                "$gcc"
            ]
        },
        {
            "type": "shell",
            "label": "run st-link server",
            "command": "st-link-gdb-server.sh",
            "problemMatcher": [
                "$gcc"
            ]
        }
    ],
    "version": "2.0.0"
}
```
第一个名为build的任务用来编译，第二个名为clean的任务用来清除编译产生的文件，第三个名为run st-link server的任务用来启动gdb server(手动启动亦可)。若此处运行命令出错请检查环境变量设置是否正确。注意，vs code只会读取系统环境变量，和msys2内部环境变量没有关系，linux或者mac os没有这些问题。此时按下F1，选择Tasks:Run task就可以手动选择任务运行。

---

* launch.json文件
此文件用于设置调试。
```
{
    // 使用 IntelliSense 了解相关属性。
    // 悬停以查看现有属性的描述。
    // 欲了解更多信息，请访问: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "arm debug",
            "type": "cppdbg",
            "request": "launch",
            "targetArchitecture": "arm",
            "program": "${workspaceFolder}/build/${workspaceRootFolderName}.elf",
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": true,
            "MIMode": "gdb",
            "miDebuggerPath": "C:/msys64/home/63143/gcc-arm-none-eabi-7-2018-q2-update-win32/bin/arm-none-eabi-gdb.exe",
            "setupCommands": [
                {
                "text": "file C:/Users/63143/Desktop/demo/build/demo.elf'"
                },
                {
                "text": "target remote localhost:61234"
                },
                {
                "text": "monitor reset"
                },
                {
                "text": "load"
                }
            ],
            "preLaunchTask": "build"
        }
    ]
}
```
name属性自行选择，targetArchitecture必须为arm，program为编译生成的.elf文件路径，miDebuggerPath为arm-none-eabi-gdb.exe路径。setupCommands是gdb启动后执行的命令。其中file C:/Users/63143/Desktop/demo/build/demo.elf用来选择elf文件，这里无法使用相对路径，若修改了工程路径也要手动修改。target remote localhost:61234用来连接到gdb server。monitor reset用来reset芯片。load用来装载elf文件。preLaunchTask在运行调试前先运行编译任务(build--在tasks.json中设置的名称)。


---

---

## 4.结束
至此基本完成了使用vs code+gcc+gdb调试stm32。理论上适合任何支持gcc的芯片和任何操作系统。整个过程涉及环境变量、编译器、链接器等相关，内容较多不一一说明。
参考文章 [用VS Code开发STM32](https://zhuanlan.zhihu.com/p/61519415) 感谢！(侵删)
