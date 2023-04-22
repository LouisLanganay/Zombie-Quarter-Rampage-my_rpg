/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** docu_h.c
*/

#include "rpg.h"

static const char* help_message = "USER GUIDE\n Link of wiki:"
" https://github.com/EpitechPromo2027/B-MUL-200-REN-2-1-myrpg-louis."
"langanay/wiki\n"
"Resume of Game: This game type RPG created in a post-apocalyptic world,\n"
" Jules the main hero is a geek stuck in his world and"
"one day they wake up lost alone,\n"
"the continuation in the game ...\n"
"Game Control:\n Z: Move ForWard    Q: Move Left    S: MoveBackWard"
" D: Move Right\n"
"i:  Inventory Y: choice of dialog 1    U: choice of dialog number 2"
"E: Pick Up  Directional Arrow: for move when you are in inventory\n"
"Each game control can be change in setting menu\n";

int doc_function(int ac, char **av)
{
    if (ac > 1 && my_strcmp(av[1], "-h") == 0) {
        printf("%s", help_message);
        return 1;
    }
    return 0;
}
