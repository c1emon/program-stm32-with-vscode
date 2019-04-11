@ECHO OFF

FOR %%i IN (Exe, Output, Release, Debug, Settings, Flash, RAM) DO IF EXIST %%i RD %%i /S/Q

FOR %%i IN (EX~, DEP, PLG, APS, NCB, TMP, ZIP, LOG, ILK, SIO, ERR, TPU, RES, BAK) DO IF EXIST *.%%i DEL *.%%i
