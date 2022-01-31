#version 330 core

#define MAX_LIGHTS 4

out vec4 frag_colour;
in vec2 uvc;
uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos; 
uniform vec3 viewPos;

uniform sampler2D textureUnitID;

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

    bool imdirect;
    bool imspot;
    bool impoint;
};

uniform float numberOfLights=3;
uniform Light lightu[MAX_LIGHTS];
in vec3 FragPos; 
in vec3 Normal;  
void main()
{   

vec3 result;
for (int index = 0; index < numberOfLights; index++) 
{
    Light light=lightu[index];

    float ambientStrength = 0.1;
    float specularStrength = 0.7;


    vec3 lpfc=vec3(light.position.x,light.position.y,light.position.z);
    if (light.imdirect) 
    {
        vec3 lightDir = normalize(-light.direction);  
        
        
        vec3 ambient = ambientStrength * lightColor;
                
                
        vec3 norm = normalize(Normal);
                          
        float diff = max(dot(norm, lightDir), 0.0);
        vec3 diffuse = diff *lightColor;
                
        vec3 viewDir = normalize(viewPos - FragPos);
        vec3 reflectDir = reflect(-lightDir, norm);  
                
        float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
        vec3 specular = specularStrength * spec * lightColor;  

        result += (ambient + diffuse + specular) * objectColor;

    }
    else if(light.imspot)
    {
        vec3 lightDir = normalize(lpfc - FragPos);


            vec3 ambient = ambientStrength * lightColor;
        
            float theta = dot(lightDir, normalize(-light.direction)); 
        
            if(theta > light.cutOff) 
            {   
                vec3 norm = normalize(Normal);
                  
               float diff = max(dot(norm, lightDir), 0.0);
               vec3 diffuse = diff *objectColor;
        
               vec3 viewDir = normalize(viewPos - FragPos);
               vec3 reflectDir = reflect(-lightDir, norm);  
        
               float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
               vec3 specular = specularStrength * spec * lightColor;  
               float distance    = length(lpfc - FragPos);
               float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));     

               ambient  *= attenuation; 
               diffuse  *= attenuation;
               specular *= attenuation;  
       
               result += (ambient + diffuse + specular) * objectColor;

            }
            else
            {
                result += ambient * objectColor;
               
            }
        }
        else
        {
        vec3 lightDir = normalize(lpfc - FragPos);  
        
        
                vec3 ambient = ambientStrength * lightColor;
                
                
                vec3 norm = normalize(Normal);
                          
               float diff = max(dot(norm, lightDir), 0.0);
               vec3 diffuse = diff *lightColor;
                
               vec3 viewDir = normalize(viewPos - FragPos);
               vec3 reflectDir = reflect(-lightDir, norm);  
                
               float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
               vec3 specular = specularStrength * spec * lightColor;  

               float distance    = length(lightPos - FragPos);
               float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));     
        
               ambient  *= attenuation; 
               diffuse  *= attenuation;
               specular *= attenuation;  
               
               result += (ambient + diffuse + specular) * objectColor;
               
        }
    



  }    
  frag_colour = vec4(result, 1.0) *texture(textureUnitID, uvc);;
}