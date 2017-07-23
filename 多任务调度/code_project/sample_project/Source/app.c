/*************************************** Copyright (c)******************************************************
** File name            :   app.c
** Latest modified Date :   2016-06-01
** Latest Version       :   0.1
** Descriptions         :   应用代码
**
**********************************************************************************************************/
#include "tinyOS.h"

/**********************************************************************************************************
** 应用示例
** 演示任务状态的查询
**********************************************************************************************************/
// 任务1和任务2的任务结构，以及用于堆栈空间
tTask tTask1;
tTask tTask2;
tTask tTask3;
tTask tTask4;
tTaskStack task1Env[1024];
tTaskStack task2Env[1024];
tTaskStack task3Env[1024];
tTaskStack task4Env[1024];

int task1Flag;
void task1Entry (void * param) 
{
    tTaskInfo taskInfo;

    tSetSysTickPeriod(10);
    for (;;)
    {
        // 获取自己的状态信息
        tTaskGetInfo(currentTask, &taskInfo);

        // 获取任务4的状态信息
        tTaskGetInfo(&tTask4, &taskInfo);

        task1Flag = 1;
        tTaskDelay(1);
        task1Flag = 0;
        tTaskDelay(1);
    }
}

int task2Flag;
void task2Entry (void * param) 
{

    for (;;) 
    {
        task2Flag = 1;
        tTaskDelay(1);
        task2Flag = 0;
        tTaskDelay(1);
    }
}

int task3Flag;
void task3Entry (void * param) 
{
    for (;;) 
    {
        task3Flag = 1;
        tTaskDelay(1);
        task3Flag = 0;
        tTaskDelay(1);
    }
}

int task4Flag;
void task4Entry (void * param) 
{
    for (;;) 
    {
        task4Flag = 1;
        tTaskDelay(1);
        task4Flag = 0;
        tTaskDelay(1);
    }
}

/**********************************************************************************************************
** Function name        :   tInitApp
** Descriptions         :   初始化应用接口
** parameters           :   无
** Returned value       :   无
***********************************************************************************************************/
void tInitApp (void) 
{
    // 初始化任务1和任务2结构，传递运行的起始地址，想要给任意参数，以及运行堆栈空间
    tTaskInit(&tTask1, task1Entry, (void *)0x11111111, 0, &task1Env[1024]);
    tTaskInit(&tTask2, task2Entry, (void *)0x22222222, 1, &task2Env[1024]);
    tTaskInit(&tTask3, task3Entry, (void *)0x33333333, 0, &task3Env[1024]);
    tTaskInit(&tTask4, task4Entry, (void *)0x44444444, 1, &task4Env[1024]);
}


