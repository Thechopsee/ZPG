#version 330
layout(location=0) in vec3 vp;
uniform mat4 modelMatrix=mat4(1.0f);
uniform mat4 viewMatrix=mat4(1.0f);
uniform mat4 projectionMatrix=mat4(1.0f);
out vec3 vertexColor;
out vec3 uv;
void main () {
	uv=vp;
  gl_Position = projectionMatrix*viewMatrix*modelMatrix*vec4(vp,1.0f);
  vertexColor = vec3(vp);
}