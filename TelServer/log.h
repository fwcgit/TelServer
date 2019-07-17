/*********************************************************************
File Name: log.h
Author: fuweicheng
mail: fu_huaicheng@163.com
Created Time: Fri 17 Aug 2018 03:09:55 PM CST
Description:
*************************************************************/
#ifndef _LOG_H
#define _LOG_H

extern char logStr[200];
void jlog(int type,char *ch);
void log_flush(const char *format,...);
#endif
