#version 120

#ifdef GL_ES
precision mediump float;
#endif

uniform sampler2D currentTexture;
uniform vec2 resolution;
uniform vec2 mouse;

// float spot_light(vec2 uv, vec2 pos, float radius, float falloff)
// {
//     vec2 to_light = pos - uv;
//     float dist = length(to_light);
//     float intensity = smoothstep(radius, radius - falloff, dist);
//     return intensity;
// }

float cone_spot_light(vec2 uv, vec2 pos, float radius, float falloff)
{


    vec2 center = vec2(0.0, 0.0);
    //the light is at the center of the screen
    vec2 to_light = - uv;
    float dist = length(to_light);
    float intensity = smoothstep(radius, radius - falloff, dist) * 0.8;
    //60 degree cone
    vec2 direction = normalize(pos - center);
    float angle = dot(normalize(to_light), direction);
    angle -= 0.3;
    //float angle = dot(normalize(to_light), normalize(pos - center));
    return intensity * angle;
}

vec2 direction_from_angle(vec2 mouse, vec2 center, float angle)
{
    vec2 direction = normalize(mouse - center);
    float x = cos(angle) * direction.x - sin(angle) * direction.y;
    float y = sin(angle) * direction.x + cos(angle) * direction.y;
    return vec2(x, y);
}

void main(void)
{
    vec2 coord = gl_TexCoord[0].xy;
    vec4 pixel_color = texture2D(currentTexture, coord);
    vec2 center = vec2(0.5, 0.5);

    vec2 uv = gl_FragCoord.xy / resolution.xy;
    uv = uv * 2.0 - 1.0;
    uv.x *= resolution.x / resolution.y;
    gl_FragColor = vec4(0.0f, 0.0f, 0.0f, 0.75f);

    vec3 col = vec3(0.0, 0.0, 0.0);
    vec2 ms = 2.0 * mouse / resolution - 1.0;
    ms.x *= resolution.x / resolution.y;
    ms.y *= -1.0;

    //if mouse is to the left of the screen, the light is to the left of the screen
    ms = direction_from_angle(ms, vec2(0.0,0.0), 0.0);

    //float phong = max(0.0, dot(lDir, normalize(vec3(uv, 1.0))));
    //col += phong * spot_light(uv, ms, 0.2, 0.1);
    col += cone_spot_light(uv, -ms, 2.0, 1.2);
    gl_FragColor += vec4(col * pixel_color.rgb, 0.2);
    if (gl_FragColor.a < 0.3) discard;
}