/*************************************** Copyright (c)******************************************************
** File name            :   tConfig.h
** Latest modified Date :   2016-06-01
** Latest Version       :   0.1
** Descriptions         :   tinyOS的配置文件。
**
**********************************************************************************************************/
#ifndef TCONFIG_H
#define TCONFIG_H

#define	TINYOS_PRO_COUNT				32						// TinyOS任务的优先级序号
#define TINYOS_SLICE_MAX				10						// 每个任务最大运行的时间片计数

#define TINYOS_IDLETASK_STACK_SIZE		1024					// 空闲任务的堆栈单元数

#endif /* TCONFIG_H */
