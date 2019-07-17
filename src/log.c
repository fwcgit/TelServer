//
//  log.c
//  TelServer
//
//  Created by fwc on 2019/7/17.
//  Copyright © 2019 fwc. All rights reserved.
//

#include "log.h"
#include <stdarg.h>
#include <stdio.h>
void log_flush(const char *format,...)
{
    va_list args;
    
    va_start(args,format);
    vprintf(format,args); //必须用vprintf
    va_end(args);
    fflush(stdout);
}
