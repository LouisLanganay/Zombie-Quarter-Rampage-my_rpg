/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_renderstate2
*/

#include "rpg.h"

sfRenderStates init_renderstate2(sfShader *shader)
{
    const sfTexture *texture = sfTexture_createFromFile
    ("resources/shader/void.png", NULL);
    sfBlendMode blendMode = {sfBlendFactorSrcAlpha,
    sfBlendFactorOneMinusSrcAlpha, sfBlendEquationAdd,
    sfBlendFactorOne, sfBlendFactorZero, sfBlendEquationAdd};
    sfRenderStates render = (sfRenderStates){
        .shader = shader,
        .blendMode = blendMode,
        .transform = sfTransform_Identity,
        .texture = texture
    };
    return render;
}
