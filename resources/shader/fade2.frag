uniform float fadeAmount; // fade amount (between 0 and 1)
uniform vec2 resolution; // screen resolution

void main()
{
    // Get the screen center
    vec2 screenCenter = vec2(0.5, 0.5);
    
    // Calculate the distance from the fragment to the center of the screen
    vec2 distance = gl_FragCoord.xy - (screenCenter * resolution.xy);
    float dist = length(distance) / length(resolution.xy);
    
    // Calculate the alpha value based on the distance from the center of the screen
    float alpha = smoothstep(0.0, fadeAmount, dist);
    
    // Set the output color with the modified alpha value
    gl_FragColor = vec4(1.0, 1.0, 1.0, alpha);
}