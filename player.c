#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "player.h"
#include "port_handler.h"

#include <sys/stat.h>
#include <sys/types.h>

#ifdef _WIN32
#include <direct.h>
#define MAKE_DIR(path) _mkdir(path)
#else
#define MAKE_DIR(path) mkdir(path, 0777)
#endif

void init_player();

void ensure_player_dir()
{
    const char *dir_name = "player";

    struct stat st = {0};

    if (stat(dir_name, &st) == -1)
    {
        if (MAKE_DIR(dir_name) == 0)
        {
            prints("Player data directory created.", 30);
            printf("\n");
        }
        else
        {
            prints("Error: Could not create player data directory!", 30);
            printf("\n");
            exit(1);
        }
    }
}

bool check_p_exists(const char *p_file)
{
    FILE *fp;

    fp = fopen(p_file, "r");

    if (fp != NULL)
    {
        fclose(fp);
        return true;
    }

    return false;
}

void init_player()
{
    ensure_player_dir();

    FILE *fp_stat = fopen(STAT_P, "w");
    FILE *fp_items = fopen(ITEMS_P, "w");

    if (fp_stat == NULL || fp_items == NULL)
    {
        prints("cannot open file for writing, even after dir creation.", 50);
        printf("\n");
        fflush(stdout);
        sleep_ms(3000);
        exit(1);
    }

    fprintf(fp_stat, "Health = 100\n");
    fprintf(fp_stat, "Mana = 100\n");
    fprintf(fp_stat, "Level = 1\n");
    fprintf(fp_stat, "EXP = 0\n");
    fprintf(fp_stat, "Intuition = 0\n");

    fprintf(fp_items, "Torch\n");

    fclose(fp_stat);
    fclose(fp_items);
}

void see_stats()
{
    FILE *fp_stat = NULL;

    if (!check_p_exists(STAT_P))
    {
        init_player();
    }

    fp_stat = fopen(STAT_P, "r");

    char buffer[256];

    if (fp_stat == NULL)
    {
        prints("FATAL: Could not open stats file for reading.", 30);
        printf("\n");
        return;
    }

    prints("--- Player Stats ---\n", 20);
    printf("\t\t\n\e[1;31mHealth\e[0m:\t\t%d", get_health());
    sleep_ms(500);
    printf("\t\n\e[1;34mMana\e[0m:\t\t%d", get_mana());
    sleep_ms(500);
    printf("\t\n\e[1;37mLevel\e[0m:\t\t%d", get_lvl());
    sleep_ms(500);
    printf("\t\n\e[1;35mEXP\e[0m:\t\t%d", get_exp());
    sleep_ms(500);
    printf("\t\n\e[1;36mIntuition\e[0m:\t%d\n", get_intuition());
    sleep_ms(500);

    prints("--------------------\n", 20);
    printf("\n");


    fclose(fp_stat);
}

int get_health()
{
    if (!check_p_exists(STAT_P))
    {
        init_player();
    }

    FILE *fp = fopen(STAT_P, "r");
    if (fp == NULL)
    {
        prints("FATAL: Could not open stats file for reading.", 30);
        printf("\n");
        return -1;
    }

    char line[256];
    int health = -1;
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        char *p = strstr(line, "Health");
        if (p != NULL)
        {
            int val;
            if (sscanf(p, "Health = %d", &val) == 1)
            {
                health = val;
                break;
            }
        }
    }

    fclose(fp);
    return health;
}

int get_mana()
{
    if (!check_p_exists(STAT_P))
    {
        init_player();
    }

    FILE *fp = fopen(STAT_P, "r");
    if (fp == NULL)
    {
        prints("FATAL: Could not open stats file for reading.", 30);
        printf("\n");
        return -1;
    }

    char line[256];
    int mana = -1;
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        char *p = strstr(line, "Mana");
        if (p != NULL)
        {
            int val;
            if (sscanf(p, "Mana = %d", &val) == 1)
            {
                mana = val;
                break;
            }
        }
    }

    fclose(fp);
    return mana;
}

int get_lvl()
{
    if (!check_p_exists(STAT_P))
    {
        init_player();
    }

    FILE *fp = fopen(STAT_P, "r");
    if (fp == NULL)
    {
        prints("FATAL: Could not open stats file for reading.", 30);
        printf("\n");
        return -1;
    }

    char line[256];
    int lvl = -1;
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        char *p = strstr(line, "Level");
        if (p != NULL)
        {
            int val;
            if (sscanf(p, "Level = %d", &val) == 1)
            {
                lvl = val;
                break;
            }
        }
    }

    fclose(fp);
    return lvl;
}

int get_exp()
{
    if (!check_p_exists(STAT_P))
    {
        init_player();
    }

    FILE *fp = fopen(STAT_P, "r");
    if (fp == NULL)
    {
        prints("FATAL: Could not open stats file for reading.", 30);
        printf("\n");
        return -1;
    }

    char line[256];
    int exp = -1;
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        char *p = strstr(line, "EXP");
        if (p != NULL)
        {
            int val;
            if (sscanf(p, "EXP = %d", &val) == 1)
            {
                exp = val;
                break;
            }
        }
    }

    fclose(fp);
    return exp;
}

int get_intuition()
{
    if (!check_p_exists(STAT_P))
    {
        init_player();
    }

    FILE *fp = fopen(STAT_P, "r");
    if (fp == NULL)
    {
        prints("FATAL: Could not open stats file for reading.", 30);
        printf("\n");
        return -1;
    }

    char line[256];
    int intuition = -1;
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        char *p = strstr(line, "Intuition");
        if (p != NULL)
        {
            int val;
            if (sscanf(p, "Intuition = %d", &val) == 1)
            {
                intuition = val;
                break;
            }
        }
    }

    fclose(fp);
    return intuition;
}