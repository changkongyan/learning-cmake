/**
 * 
 * Copyright (c) 2019 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\cmake\xiaoai.cpp
 * @author   詹长建 (2233930937@qq.com)
 * @date     2019-07
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-07-24
 * Modified By:    詹长建 (2233930937@qq.com)
 * 
 */
#include "xiaoai.h"
#include "greeting/nihao.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int print(const char *s,int type){
    switch (type)
    {
    case 0:
        fprintf(stdout,"Logging:%s\n",s);
        break;
    case 1:
        fprintf(stdout,"Warning:%s\n",s);
        break;
    case 2:
        fprintf(stderr,"error:%s\n",s);
        break;
    case 3:
        fprintf(stderr,"fatal:%s\n",s);
        exit(1);
    default:
        fprintf(stdout,"Logging:%s\n",s);
        break;
    }
    return EXIT_SUCCESS;
}

XiaoAi::XiaoAi(/* args */)
{
}

XiaoAi::~XiaoAi()
{
}

int XiaoAi::run(){
    const char *s="this is logging message"; 
    print(s,log);
    s="this is warning message";
    print(s,warning);
    s="this is error message"; 
    print(s,error);
    nihao();
    return EXIT_SUCCESS;
}