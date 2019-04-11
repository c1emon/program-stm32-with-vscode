@echo off
cmd /K "ST-LINK_gdbserver.exe -c config.txt || echo GDB server exited"
