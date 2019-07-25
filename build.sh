#!/usr/bin/env bash

# windows系统采用的编译器为mingw编译器
# 脚本解释器采用bash
# windows下的bash解释器为git的bash解释器

# 创建build文件夹
if [ ! -e build ] ;then
mkdir build
cd build
else
cd build
rm * -rf
fi

# 判断当前运行系统
# 单独使用uname命令时相当于uname -s
 
osname=`uname`;
if [ ${osname} == "Darwin" ];then
    echo  "Mac OS X 操作系统"
elif [ ${osname:0:5}  == "Linux" ];then
    echo  "GNU/Linux操作系统"
    cmake ..
    make
    make install
elif [ ${osname:0:10} == "MINGW32_NT" ];then
    echo  "Windows NT操作系统"
    which sh
    if [ $? == "0" ] ;then
        echo "sh.exe存在" # 对于MinGW Makefiles,sh和make不能在同一个环境变量
        cmake .. -G "MSYS Makefiles"
    else
        cmake .. -G "MinGW Makefiles"
    fi
    mingw32-make
    mingw32-make install
fi

echo  "编译完毕"


