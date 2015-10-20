@echo off
rem eg. cr friday.cpp
if exist %1. (
    echo file exists!
) else (
    touch %1
    cp tem.cxx %1
    sed -i 's/TASK_NAME/%~n1/g' %1
)
