#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>
#include <iostream>
#include "shprogram.h"
#include <vector>
#include <GL\glew.h>

class Sun {
private:
	glm::vec3 direction;
	glm::vec3 ambience;
	glm::vec3 diffusion;
	glm::vec3 specularity;

public:
	Sun(glm::vec3 direction, glm::vec3 ambience, glm::vec3 diffusion, glm::vec3 specularity)
		: direction(direction), ambience(ambience), diffusion(diffusion), specularity(specularity)
	{
	};

	void updateShader(const ShaderProgram& shader) {
		glUniform3fv(glGetUniformLocation(shader.get_programID(), "sun.direction"), 1, &direction[0]);
		glUniform3fv(glGetUniformLocation(shader.get_programID(), "sun.ambience"), 1, &ambience[0]);
		glUniform3fv(glGetUniformLocation(shader.get_programID(), "sun.diffusion"), 1, &diffusion[0]);
		glUniform3fv(glGetUniformLocation(shader.get_programID(), "sun.specularity"), 1, &specularity[0]);
	};

	void processInput(GLFWwindow* window, const ShaderProgram& shader) {

		if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
			this->ambience -= glm::vec3(0.001f, 0.001f, 0.001f);
		if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) != GLFW_PRESS)
			this->ambience += glm::vec3(0.001f, 0.001f, 0.001f);
		if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
			this->diffusion -= glm::vec3(0.001f, 0.001f, 0.001f);
		if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) != GLFW_PRESS)
			this->diffusion += glm::vec3(0.001f, 0.001f, 0.001f);
		if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
			this->specularity -= glm::vec3(0.001f, 0.001f, 0.001f);
		if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) != GLFW_PRESS)
			this->specularity += glm::vec3(0.001f, 0.001f, 0.001f);
		this->updateShader(shader);
	};




};
