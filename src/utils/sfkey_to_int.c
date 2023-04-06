/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** sfkey_to_int
*/

#include "rpg.h"

int sfkey_to_int(sfKeyCode key)
{
    sfKeyCode arr[] = {
        sfKeyA, sfKeyB, sfKeyC, sfKeyD, sfKeyE, sfKeyF, sfKeyG, sfKeyH, sfKeyI,
        sfKeyJ, sfKeyK, sfKeyL, sfKeyM, sfKeyN, sfKeyO, sfKeyP, sfKeyQ, sfKeyR,
        sfKeyS, sfKeyT, sfKeyU, sfKeyV, sfKeyW, sfKeyX, sfKeyY, sfKeyZ,
        sfKeyNum0, sfKeyNum1, sfKeyNum2, sfKeyNum3, sfKeyNum4, sfKeyNum5,
        sfKeyNum6, sfKeyNum7, sfKeyNum8, sfKeyNum9, sfKeyEscape, sfKeyLControl,
        sfKeyLShift, sfKeyLAlt, sfKeyLSystem, sfKeyRControl, sfKeyRShift,
        sfKeyRAlt, sfKeyRSystem, sfKeyMenu, sfKeyLBracket, sfKeyRBracket,
        sfKeySemiColon, sfKeyComma, sfKeyPeriod, sfKeyQuote, sfKeySlash,
        sfKeyBackSlash, sfKeyTilde, sfKeyEqual, sfKeyDash, sfKeySpace,
        sfKeyReturn, sfKeyBack, sfKeyTab, sfKeyPageUp, sfKeyPageDown,
        sfKeyEnd, sfKeyHome, sfKeyInsert, sfKeyDelete, sfKeyAdd, sfKeySubtract,
        sfKeyMultiply, sfKeyDivide, sfKeyLeft, sfKeyRight, sfKeyUp, sfKeyDown,
        sfKeyNumpad0, sfKeyNumpad1, sfKeyNumpad2, sfKeyNumpad3, sfKeyNumpad4,
        sfKeyNumpad5, sfKeyNumpad6, sfKeyNumpad7, sfKeyNumpad8, sfKeyNumpad9,
        sfKeyF1, sfKeyF2, sfKeyF3, sfKeyF4, sfKeyF5, sfKeyF6, sfKeyF7, sfKeyF8,
        sfKeyF9, sfKeyF10, sfKeyF11, sfKeyF12, sfKeyF13, sfKeyF14, sfKeyF15,
        sfKeyPause
    };
    for (int i = 0; sizeof(arr) / sizeof(sfKeyCode); i++)
        if (arr[i] == key) return (i);
}
