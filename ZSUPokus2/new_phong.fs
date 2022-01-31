#version 450


in vec3 fragmentWorldPosition;

in vec3 vnc;
in vec2 uvc;
in vec3 tgc;

in mat3 tbn;

uniform sampler2D textureUnitID;
uniform sampler2D UINormal;
uniform int intensity=1;

uniform vec3 lightPos; 
uniform vec3 objectColor;
uniform vec3 viewPos;
uniform vec3 lightColor;

out vec4 frag_colour;

float calcDiffuse(vec3 lightDir, vec3 normal)
{
	return max(dot(normalize(lightDir), normalize(normal)), 0.0);
}

float calcSpec(vec3 light, vec3 normal, float shininess)
{
	return  pow(max(dot(normalize(light), normalize(normal)), 0.0),shininess) ;
}


void main () {
	 vec4 specular = vec4(0,0,0,0);
	 vec4 diffuse = vec4(0,0,0,0);
	 vec4 ambient = vec4( 0.1, 0.1, 0.1, 1.0);
	 
	 vec3 camPosition=viewPos;
	 vec3 lightPosition= lightPos;

	 //
	 vec3 encodedNormal  = texture(UINormal, uvc).rgb;
	 encodedNormal = 2.0 * encodedNormal - 1.0; //RGB to vector
	 encodedNormal = normalize (encodedNormal*vec3(1,1,intensity)); //intensity
	 vec3 normal = normalize(tbn * encodedNormal) ;
	
	 vec3 lightDirection = normalize(lightPosition - fragmentWorldPosition);
	 vec3 cameraDirection = normalize(camPosition - fragmentWorldPosition);

	 if( dot(normalize(lightDirection), normalize(normal)) > 0){
		diffuse = calcDiffuse(lightDirection, normal) *  texture(textureUnitID, uvc); //vec4( 0.385, 0.647, 0.812, 1.0);
		vec3 reflectDir= reflect(-normalize(lightDirection),normalize(normal));
		specular = calcSpec(reflectDir, cameraDirection, 32)  *vec4(lightColor,1.0f);
	 }
    frag_colour = (ambient + diffuse + specular)*vec4(objectColor,1.0f);	 
}

