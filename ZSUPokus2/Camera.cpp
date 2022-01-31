#include "Camera.h"
void Camera::ProcessMouseScroll(float fov)
{
    Zoom = fov;
    calculatePerspective();
}
void Camera::updateCameraVectors()
{

    glm::vec3 front;
    front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    front.y = sin(glm::radians(Pitch));
    front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    Front = glm::normalize(front);

    Right = glm::normalize(glm::cross(Front, WorldUp));
    Up = glm::normalize(glm::cross(Right, Front));
}

Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch) : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM)
{
        Position = position;
        WorldUp = up;
        Yaw = yaw;
        Pitch = pitch;
        updateCameraVectors();
        calculatePerspective();
    }

glm::mat4 Camera::GetViewMatrix()
{
    return glm::lookAt(Position, Position + Front, Up);
}

void Camera::ProcessKeyboard(MovementEnum direction, float deltaTime)
{
    float velocity = MovementSpeed * deltaTime;
    if (direction == F)
        Position += Front * velocity;
    if (direction == B)
        Position -= Front * velocity;
    if (direction == L)
        Position -= Right * velocity;
    if (direction == R)
        Position += Right * velocity;
}

void Camera::ProcessMouseMovement(float xpos, float ypos, bool new_mouse, GLboolean constrainPitch )
{
    if (new_mouse)
    {
        lastX = xpos;
        lastY = ypos;
    }
    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos;
    lastX = xpos;
    lastY = ypos;
    Yaw += xoffset;
    Pitch += yoffset;

    

    if (constrainPitch)
    {
        if (Pitch > 89.0f)
            Pitch = 89.0f;
        if (Pitch < -89.0f)
            Pitch = -89.0f;
    }




    updateCameraVectors();
}