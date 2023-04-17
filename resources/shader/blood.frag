uniform vec2 resolution;
uniform float time;
float PI = 3.1415926535897932384626433832795;

float distance2 (vec2 a, vec2 b) {
    vec2 d = a - b;
    return dot(d, d);
}

float beat (float t, float freq, float amp) {
    return amp * sin(freq * t);
}

float heart_beat(float time, float freq, float intensity) {
    float v = atan(sin(time * PI * freq) * intensity);
    return (v + PI / 2.0) / PI;
}

void main()
{
    float alpha = 0.0;
    vec2 center_screen = resolution / 2.0;
    vec2 center = gl_FragCoord.xy - center_screen;
    float red = sin(time) * 0.5 + 0.5;
    vec3 color = vec3(0.77f, 0.07f, 0.07f);
    float dist = distance(center_screen, gl_FragCoord.xy);
    alpha = dist / 2500.0;

    dist = heart_beat(time, 2.0, 5.0);
    gl_FragColor = vec4(dist, color.y, color.z, alpha);
}
