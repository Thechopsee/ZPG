#version 330
out vec4 frag_colour;
uniform samplerCube textureUnitID;
in vec2 uv;
void main () {
     //frag_colour = vec4(uv,1.0,1.0); //test na funkcnost uv souøadnic
     frag_colour = texture(textureUnitID, vec3(uv,1.0f));
}