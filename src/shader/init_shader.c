/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_shader
*/

#include "rpg.h"

static void init_shader_step(shader_t *shader)
{
    shader->shader_rain = sfShader_createFromFile(NULL, NULL, RS_RAIN);
    shader->shader_blood = sfShader_createFromFile(NULL, NULL, RS_BLOOD);
    shader->shader_fade = sfShader_createFromFile(NULL, NULL, RS_FADE);
    shader->states_rain = init_renderstate(shader->shader_rain);
    shader->states_blood = init_renderstate2(shader->shader_blood);
    shader->states_fade = init_renderstate2(shader->shader_fade);
    shader->rain_bool = 0;
    shader->blood_bool = 0;
    shader->fade_bool = 0;
    shader->fade_val = 0;
    shader->shader_clock = sfClock_create();
    shader->fade_clock = sfClock_create();
    sfShader_setVec2Uniform(shader->shader_rain, resolution_vec);
    sfShader_setVec2Uniform(shader->shader_blood, resolution_vec);
    sfShader_setVec2Uniform(shader->shader_fade, resolution_vec);
}

shader_t *init_shader(void)
{
    shader_t *shader = malloc(sizeof(shader_t));
    init_shader_step(shader);
    shader->shader_torch = sfShader_createFromFile(NULL, NULL, RS_TORCH);
    shader->states_torch = init_renderstate2(shader->shader_torch);

    shader->torch_bool = 0;
    return (shader);
}
