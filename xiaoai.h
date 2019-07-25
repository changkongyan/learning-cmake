/**
 * 
 * Copyright (c) 2019 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\cmake\xiaoai.h
 * @author   詹长建 (2233930937@qq.com)
 * @date     2019-07
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-07-25
 * Modified By:    詹长建 (2233930937@qq.com)
 * 
 */
#ifndef XIAOAI_H
#define XIAOAI_H

/**
 * @brief 日志类型
 * 
 */
enum LOG {log,warning,error,fatal};


#ifdef __cplusplus 
extern "C" {
#endif
/**
 * @brief 打印日志
 * 
 * @param s    打印的记录
 * @param type 打印类型
 * @return int 成功返回0
 */
int print(const char *s , int type=0);
#ifdef __cplusplus 
}
#endif

/**
 * @brief 简短打印信息类
 * 
 */
class XiaoAi
{
private:
    /* data */
public:
    XiaoAi(/* args */);
    ~XiaoAi();
    /**
     * @brief 开始运行
     * 
     * @return int 成功返回0
     */
    int run();
};

#endif /* XiAOAI_H */