#pragma once
#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>
#include <iostream>

#include <vector>

const glm::vec3 POSITION = glm::vec3(0.0f, 0.0f, 15.0f);
const glm::vec3 FRONT = glm::vec3(0.0f, 0.0f, 1.0f);
const glm::vec3 WORLD_UP = glm::vec3(0.0f, 1.0f, 0.0f);
const float ANGLE_SPEED = 0.1f;
const float POSITION_SPEED = 0.02f;
const float YAW = -90.0f;
const float PITCH = 0.0f;

class Camera {
private:
    glm::vec3 cameraPos;
    glm::vec3 cameraFront;
    glm::vec3 cameraUp;
    float yaw;
    float pitch;

    void updateCameraVectors() {
        glm::vec3 front;
        if (pitch > 89.0f)
            pitch = 89.0f;
        if (pitch < -89.0f)
            pitch = -89.0f;
        front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        front.y = sin(glm::radians(pitch));
        front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        cameraFront = glm::normalize(front);
        glm::vec3 right = glm::normalize(glm::cross(cameraFront, WORLD_UP));
        cameraUp = glm::normalize(glm::cross(right, cameraFront));
    }

public:
    Camera(
        glm::vec3 position = POSITION,
        glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f)
    ) : cameraFront(FRONT), yaw(YAW), pitch(PITCH) {
        cameraPos = position;
        cameraUp = up;
        updateCameraVectors();
    }

    glm::mat4 viewMatrix() {
        return glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
    }

    void processInput(GLFWwindow* window) {
        if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
            cameraPos = POSITION;
            cameraFront = FRONT;
            yaw = YAW;
            pitch = PITCH;
        }

        if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
            yaw += ANGLE_SPEED;
        if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
            yaw -= ANGLE_SPEED;
        if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
            pitch -= ANGLE_SPEED;
        if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
            pitch += ANGLE_SPEED;

        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
            cameraPos += POSITION_SPEED * cameraFront;
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
            cameraPos -= POSITION_SPEED * cameraFront;
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
            cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * POSITION_SPEED;
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
            cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * POSITION_SPEED;

        updateCameraVectors();
    }
};

#endif
