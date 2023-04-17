uniform vec2 resolution;
uniform float time;
// default 1, 0 for no smooth
uniform int smooth;
//defaut smooth = 1

void main()
{
    //if (smooth == -1) {} exit(0);
    if (smooth == -1) {
        gl_FragColor = vec4(0.0, 0.0, 0.0, 0.0);
        return;
    }
    float alpha = 0.0;
    vec2 center_screen = resolution / 2.0;
    vec2 center = gl_FragCoord.xy - center_screen;
    vec3 color = vec3(0.0f);
    float dist = distance(center, vec2(0.0));

    dist *= exp(-time * 2.0);
    alpha = 1.0 - 1.0 / dist;
    if (smooth == 1)
        alpha = smoothstep(0.0, 1.0, alpha);
    else
        alpha = step(0.0, alpha);

    gl_FragColor = vec4(color, alpha);
}