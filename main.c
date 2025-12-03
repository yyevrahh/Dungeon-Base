#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "port_handler.h"
#include "player.h"

// Ubuntu, Ctrl + Shift + B in VSCode to run

//yyevrahh: update tasks for compatibility, delete post-defined files, and other necessities for compatibility

int main()
{
    clear_console();
    clear_console();
    char input[16];
    while (1)
    {
        if (!check_p_exists(STAT_P) || !check_p_exists(ITEMS_P))
        {
            prints("Player profile not found. Initializing...", 100);
            for (int i = 0; i < 3; i++)
            {
                sleep_ms(100);
                printf(".");
                fflush(stdout);
            }
            clear_console();
            prints("\nInitializing new Player!", 50);
            sleep_ms(1000);

            init_player();
        }
        else
        {
            prints("\nPlayer profile found.", 30);
            sleep_ms(2000);
            prints("\nLoading...", 50);
            sleep_ms(1000);
            clear_console();
        }

        clear_console();
        see_stats();

        prints("\n\nPress ENTER to quit...", 10);
        if (fgets(input, sizeof input, stdin) == NULL) break;
        if (input[0] == '\n') break;
        clear_console();
    }
    
    return 0;
}