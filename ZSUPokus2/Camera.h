#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>

#include <vector>

enum MovementEnum {
    F,
    B,
    L,
    R
};


const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 1.5f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.0f;


class Camera
{
private:
    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Up;
    glm::vec3 Right;
    glm::vec3 WorldUp;
public:
    bool firstmouse;
    double lastX;
    double lastY;
    int win_height = 600;
    int win_width = 800;

    float Yaw;
    float Pitch;

    float MovementSpeed;
    float MouseSensitivity;
    float Zoom;

    glm::vec3 getPosition()
    {
        return Position;
    }
    glm::vec3 getFront()
    {
        return Front;
    }

    glm::mat4 projectionMatrix;
    void calculatePerspective() 
    {
        glm::mat4 projection = glm::perspective(glm::radians(this->Zoom), (float)this->win_width / this->win_height, 0.1f, 100.0f);
        this->projectionMatrix = projection;
    }

    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH) ;
    
    glm::mat4 GetViewMatrix();


    void ProcessKeyboard(MovementEnum direction, float deltaTime);


    void ProcessMouseMovement(float xpos, float ypos,bool new_mouse,GLboolean constrainPitch = true);


    void ProcessMouseScroll(float fov);


private:

    void updateCameraVectors();
   
};
