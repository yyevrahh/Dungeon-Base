#include "port_handler.h"
#include <stdlib.h>
#include <stdio.h>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

void sleep_ms(int milliseconds) {
#ifdef _WIN32
    Sleep(milliseconds); 
#else
    usleep(milliseconds * 1000); 
#endif
}

void clear_console() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void prints(const char *text, int delay_ms) {
    printf("\t");
    for (int i = 0; text[i] != '\0'; i++) {
        putchar(text[i]);
        fflush(stdout); 
        sleep_ms(delay_ms);
    }
}