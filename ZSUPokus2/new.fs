#version 330 core
out vec4 frag_colour;
  
uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos; 
uniform vec3 viewPos;

struct Light {
    vec3 position; 
    vec3 direction;
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float cutOff;

    float constant ;
    float linear;
    float quadratic;

};

uniform Light lightu;
in vec3 FragPos; 
in vec3 Normal;  
void main()
{   
    Light light=lightu;

    light.cutOff=0.976f;
    //light.constant=1.0f;
    //light.linear=0.09f;
    light.quadratic=0.032f;

    //light.position=viewPos;
    float ambientStrength = 0.1;
    float specularStrength = 0.7;

    vec3 lightDir = normalize(-light.direction);  


        vec3 ambient = ambientStrength * lightColor;
        
        
        vec3 norm = normalize(Normal);
                  
       float diff = max(dot(norm, lightDir), 0.0);
       vec3 diffuse = diff *lightColor;
        
       vec3 viewDir = normalize(viewPos - FragPos);
       vec3 reflectDir = reflect(-lightDir, norm);  
        
       float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
       vec3 specular = specularStrength * spec * lightColor;  
        // attenuation
      /* float distance    = length(lightPos - FragPos);
       float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));     

       ambient  *= attenuation; 
       diffuse  *= attenuation;
       specular *= attenuation;  
       */
       vec3 result = (ambient + diffuse + specular) * objectColor;
       frag_colour = vec4(result, 1.0);
    



          
}