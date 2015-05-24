#include "logger.h"

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

FILE* fLogs[MAX_LOG_ID+1];

void logInit(){
	unsigned i;
	for(i=0; i<=MAX_LOG_ID; ++i) fLogs[i]=NULL;
}

void logCreate(unsigned logId, const char* fileName){
	fLogs[logId]=fopen(fileName, "w");
}

void logPrint(unsigned logId, const char* format, ...){
	va_list args;
	va_start(args, format);
	vfprintf(fLogs[logId], format, args);
	va_end(args);
}

void logFinish(){
	unsigned i;
	for(i=0; i<=MAX_LOG_ID; ++i) if(fLogs[i]) fclose(fLogs[i]);
}
