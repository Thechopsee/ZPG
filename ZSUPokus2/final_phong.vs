#version 450
layout(location=0) in vec3 vp;
layout (location = 1) in vec3 aNormal;
layout(location = 2) in vec2 uv;

out vec2 uvc;

uniform mat4 modelMatrix=mat4(1.0f);
uniform mat4 viewMatrix=mat4(1.0f);
uniform mat4 projectionMatrix=mat4(1.0f);

out vec3 Normal;
out vec3 FragPos;
void main () {
  gl_Position = projectionMatrix*viewMatrix*modelMatrix*vec4(vp,1.0);
  FragPos = vec3(modelMatrix * vec4(vp, 1.0));
  Normal = mat3(transpose(inverse(modelMatrix))) * aNormal; 
  uvc=uv;
}