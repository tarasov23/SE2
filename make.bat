@echo offsetlocal EnableDelayedExpansion
set PATH=%PATH%;C:\CodeBlocks\MinGW\bin
doskey make=mingw32-make.exe $*
cmd.exe /k
 