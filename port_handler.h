#ifndef PORT_HANDLER_H
#define PORT_HANDLER_H

#include <sys/stat.h>
#include <sys/types.h>

void sleep_ms(int milliseconds);
void clear_console();
void prints(const char *text, int delay_ms);

#endif