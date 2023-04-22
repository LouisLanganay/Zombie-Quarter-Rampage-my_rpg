/*
** EPITECH PROJECT, 2022
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** docu_h.c
*/

#include "rpg.h"

static const char* help_message = "USER GUIDE\n\tLink of wiki:"
" https://github.com/EpitechPromo2027/B-MUL-200-REN-2-1-myrpg-louis."
"langanay/wiki\n"
"\tResume of Game: This game type RPG created in a post-apocalyptic world,\n"
"\tJules the main hero is a geek stuck in his world and"
"\tone day they wake up lost alone,\n"
"\tthe continuation in the game ...\n"
"DEFAULT CONTROLS\n\tZ: Move ForWard\tQ: Move Left\tS: Move BackWard"
"\tD: Move Right\n"
"\tI: Inventory\tEscape: Pause"
"\tE: Pick Up\tDirectional Arrow: for move when you are in inventory\n"
"DEBUG MODE\n\tTo activate the debug mode: ./my_rpg -d\n";

int doc_function(int ac, char **av)
{
    if (ac > 1 && my_strcmp(av[1], "-h") == 0) {
        my_putstr(help_message, -1);
        return 1;
    }
    return 0;
}
