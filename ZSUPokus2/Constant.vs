#version 330
layout(location=0) in vec4 vp;
layout(location=1) in vec4 vc;
uniform mat4 modelMatrix=mat4(1.0f);
uniform mat4 viewMatrix=mat4(1.0f);
uniform mat4 projectionMatrix=mat4(1.0f);
out vec4 vertexColor;

void main () {
  gl_Position = projectionMatrix*viewMatrix*modelMatrix*vec4(vp);
  vertexColor = vec4(vc);
}