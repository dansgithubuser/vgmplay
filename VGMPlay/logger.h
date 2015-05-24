#ifndef LOGGER_H_INCLUDED
#define LOGGER_H_INCLUDED

#define MAX_LOG_ID 255

void logCreate(unsigned logId, const char* fileName);
void logPrint(unsigned logId, const char* format, ...);
void logFinish();

#endif
