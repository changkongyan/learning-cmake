/**
 * 
 * Copyright (c) 2019 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\cmake\common.h
 * @author   詹长建 (2233930937@qq.com)
 * @date     2019-07
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-07-24
 * Modified By:    詹长建 (2233930937@qq.com)
 * 
 */
#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>


/*
 * 在C/C++宏定义
 * #        对应变量字符串化  
 * ##       把宏参数名与宏定义代码序列中的标识符连接在一起，形成一个新的标识符
 * 连接符#@ 它将单字符标记符变换为单字符，即加单引号。例如：#define B(x) #@x  则B(a)即'a'，B(1)即'1'，但B(abc)却不甚有效。
 * __VA_ARGS__  即将宏左边的 ... 的内容复制在宏右边 __VA_ARGS__ 所在的位置。例如：
 * define debug(...) printf(__VA_ARGS__) ... 代表一个可以变化的参数表，使用保留名 __VA_ARGS__ 把参数传递给宏。
 * Debug("Y = %d\n", y) ===> printf("Y = %d\n", y)
 * ##__VA_ARGS__这里的"##"有特殊作用，即编译器忽略前面一个逗号，不然编译器会报错
 */
/**
 * @brief 打印错误信息
 * 
 */
#ifndef LOG
#define LOG(info,...)  printf("%s/%d:"#info"\n",__FILE__,__LINE__,##__VA_ARGS__)
#endif

#endif