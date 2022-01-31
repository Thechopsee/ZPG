#version 330
layout(location=0) in vec4 vp;
layout(location=1) in vec4 vcc;
layout (location = 2) in vec2 aTexCoord;
uniform mat4 modelMatrix=mat4(1.0f);
uniform mat4 viewMatrix=mat4(1.0f);
uniform mat4 projectionMatrix=mat4(1.0f);
out vec3 vertexColor;
out vec2 uv;
void main () {
	uv=aTexCoord;
  gl_Position = projectionMatrix*viewMatrix*modelMatrix*vec4(vp);
  vertexColor = vec3(vp);
}