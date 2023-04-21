#version 120

#ifdef GL_ES
precision mediump float;
#endif

uniform float time;
uniform sampler2D currentTexture;
uniform vec2 resolution;

float rain(vec2 uv, float scale)
{
    float w = smoothstep(1.0, 0.0, -uv.y * (scale / 10.0));
    if (w < .1) return 0.0;
    uv.y += time * 8.5 / scale;
    uv.x += sin(uv.y + time * .8) / scale * 5.0;
    uv *= scale;
    vec2 s = floor(uv), f = fract(uv), p;
    float k = 3.0, d;
    p = .5 + .35 * sin(11.0 * fract(sin((s + scale) * mat2(vec2(7, 3),vec2(6, 5))) * 5.0))- f;

    d = length(p);
    d = smoothstep(0.0, d, sin(f.x + f.y) * 0.01);

    return d * w;
}

void main(void)
{
    vec2 coord = gl_TexCoord[0].xy;
    vec4 pixel_color = texture2D(currentTexture, coord);

    vec2 uv = (gl_FragCoord.xy * 2. - resolution.xy) / min(resolution.x, resolution.y);
    uv.y *= resolution.y / resolution.x;
    vec3 finalColor = vec3(0.0f);
    vec3 color = vec3(0.13f, 0.58f, 0.94f);
    float c = 0;

    // // c += rain(uv, 14.0 + 0.01 * fract(time * 0.5)) * 3.0;
    c += rain(uv, 10.0 + 0.01 * fract(time * 0.5)) * 2.0;
    c += rain(uv, 8.0 + 0.02 * fract(time * 0.5)) * 1.0;
    //rain in background
    c += rain(uv, 14.0 + 0.02 * fract(time * 0.5)) * 2.0;
    // c += rain(uv, 5.0) * 0.4;
    // c += rain(uv, 9.0) * (2.0 + fract(time * 0.5) * 0.2);
    // c += rain(uv, 5.5) * 2.;
    // c += rain(uv, 5.0) * 2.;

    pixel_color.rgb = mix(pixel_color.rgb, color, c);
    finalColor = pixel_color.rgb;
    gl_FragColor = vec4(finalColor, 1.0);
}