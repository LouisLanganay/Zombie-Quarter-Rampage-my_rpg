uniform vec2 resolution;
uniform float time;

void main()
{
    float alpha = 0.0;
    vec2 center_screen = resolution / 2.0;
    vec2 center = gl_FragCoord.xy - center_screen;
    vec3 color = vec3(0.0f);
    float dist = distance(center, vec2(0.0));

    dist *= exp(-time * 5.0);
    alpha = 1.0 - 1.0 / dist;
    alpha = step(0.0, alpha);

    gl_FragColor = vec4(color, alpha);
}