#ifdef GL_ES
precision mediump float;
#endif

uniform float u_time;
inform vec2 u_resolution;


void main()
{
	vec2 coord = (gl_FragCoord.xy / u_resolution);
	float color = 0.0;

	color += 0.1 * 0.1 / length(coord);

	gl_FragColor = vec4(vec3(color), 1.0);
}
