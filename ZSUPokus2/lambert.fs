#version 330 
out vec4 frag_colour;
  
uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;

in vec3 FragPos; 
in vec3 Normal;  
void main()
{   
        float ambientStrength = 0.1;
       vec3 ambient = ambientStrength *lightColor;

       vec3 lightDir = normalize(lightPos - FragPos);  

       float diff = max(dot(lightDir,normalize(Normal)), 0.0);
       vec3 diffuse = diff *lightColor;

       vec3 result = (ambient + diffuse)*objectColor;
       frag_colour = vec4(result, 1.0);
}