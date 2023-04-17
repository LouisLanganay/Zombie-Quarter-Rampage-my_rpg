/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_renderstate
*/

#include "rpg.h"

sfRenderStates init_renderstate(sfShader *shader)
{
    const sfTexture *texture = sfTexture_createFromFile
    ("resources/shader/void.png", NULL);
    sfRenderStates render = (sfRenderStates){
        .shader = shader,
        .blendMode = sfBlendAdd,
        .transform = sfTransform_Identity,
        .texture = texture
    };
    return render;
}
