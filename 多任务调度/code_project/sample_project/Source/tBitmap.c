/*************************************** Copyright (c)******************************************************
** File name            :   tBitmap.c
** Latest modified Date :   2016-06-01
** Latest Version       :   0.1
** Descriptions         :   tinyOS所用的位图数据结构。
**********************************************************************************************************/
#include "tLib.h"

/**********************************************************************************************************
** Function name        :   tBitmapInit
** Descriptions         :   初始化bitmap将所有的位全清0
** parameters           :   无
** Returned value       :   无
***********************************************************************************************************/
void tBitmapInit (tBitmap * bitmap) 
{
	bitmap->bitmap = 0;
}

/**********************************************************************************************************
** Function name        :   tBitmapPosCount
** Descriptions         :   返回最大支持的位置数量
** parameters           :   无
** Returned value       :   最大支持的位置数量
***********************************************************************************************************/
uint32_t tBitmapPosCount (void) 
{
	return 32;
}

/**********************************************************************************************************
** Function name        :   tBitmapSet
** Descriptions         :   设置bitmap中的某个位
** parameters           :   pos 需要设置的位
** Returned value       :   无
***********************************************************************************************************/
void tBitmapSet (tBitmap * bitmap, uint32_t pos)
{
	bitmap->bitmap |= 1 << pos;
}

/**********************************************************************************************************
** Function name        :   tBitmapClear
** Descriptions         :   清除bitmap中的某个位
** parameters           :   pos 需要清除的位
** Returned value       :   无
***********************************************************************************************************/
void tBitmapClear (tBitmap * bitmap, uint32_t pos)
{
	bitmap->bitmap &= ~(1 << pos);
}

/**********************************************************************************************************
** Function name        :   tBitmapGetFirstSet
** Descriptions         :   从位图中第0位开始查找，找到第1个被设置的位置序号
** parameters           :   无
** Returned value       :   第1个被设置的位序号
***********************************************************************************************************/
uint32_t tBitmapGetFirstSet (tBitmap * bitmap) 
{
	static const uint8_t quickFindTable[] =     
	{
	    /* 00 */ 0xff, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	    /* 10 */ 4,    0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	    /* 20 */ 5,    0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	    /* 30 */ 4,    0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	    /* 40 */ 6,    0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	    /* 50 */ 4,    0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	    /* 60 */ 5,    0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	    /* 70 */ 4,    0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	    /* 80 */ 7,    0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	    /* 90 */ 4,    0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	    /* A0 */ 5,    0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	    /* B0 */ 4,    0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	    /* C0 */ 6,    0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	    /* D0 */ 4,    0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	    /* E0 */ 5,    0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0,
	    /* F0 */ 4,    0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0
	};

	if (bitmap->bitmap & 0xff)
    {
        return quickFindTable[bitmap->bitmap & 0xff];
    }
    else if (bitmap->bitmap & 0xff00)
    {
        return quickFindTable[(bitmap->bitmap >> 8) & 0xff] + 8;
    }
    else if (bitmap->bitmap & 0xff0000)
    {
        return quickFindTable[(bitmap->bitmap >> 16) & 0xff] + 16;
    }
    else if (bitmap->bitmap & 0xFF000000)
    {
        return quickFindTable[(bitmap->bitmap >> 24) & 0xFF] + 24;
    }
    else
    {
        return tBitmapPosCount();
    }
}
