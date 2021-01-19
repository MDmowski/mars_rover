#define GLEW_STATIC
#include <GL/glew.h>
#include "shprogram.h"
#include <GLFW/glfw3.h>
#include <SOIL.h>
#include <iostream>
using namespace std;
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "objects/Rectangle.h"
#include "objects/Cube.h"
#include "objects/Cylinder.h"
#include "objects/Rover.h"
#include "objects/Bottom.h"
#include "objects/Camp.h"
#include "objects/Skybox.h"
#include "shprogram.h"
#include "camera.hpp"
#include "sun.hpp"

#define GROUND_COLOR glm::vec3(0.61f, 0.36f, 0.01f)

const GLuint WIDTH = 800, HEIGHT = 600;
const float PLANE_SIZE = 1000.0f;
const float ROVER_LIMIT = 4.5f;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	cout << key << endl;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

GLuint LoadMipmapTexture(GLuint texId, const char* fname)
{
	int width, height;
	unsigned char* image = SOIL_load_image(fname, &width, &height, 0, SOIL_LOAD_RGB);
	if (image == nullptr)
		throw exception("Failed to load texture file");

	GLuint texture;
	glGenTextures(1, &texture);

	glActiveTexture(texId);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);
	return texture;
}

ostream& operator<<(ostream& os, const glm::mat4& mx)
{
	for (int row = 0; row < 4; ++row)
	{
		for (int col = 0; col < 4; ++col)
			cout << mx[row][col] << ' ';
		cout << endl;
	}
	return os;
}

void roverMovement(Rover& object, ShaderProgram& theProgram, GLFWwindow* window, glm::vec3& roverPosition) {
	std::cout << roverPosition.x << std::endl;
	object.draw(theProgram.get_programID());
	if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS) {
		glm::vec3 move = glm::vec3(0.01f, 0.0f, 0.0f);
		if (roverPosition.x < ROVER_LIMIT) {
			roverPosition += move;
			object.moveRover(move);
		}
	}
	if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS) {
		glm::vec3 move = glm::vec3(-0.01f, 0.0f, 0.0f);
		if (roverPosition.x > -ROVER_LIMIT) {
			roverPosition += move;
			object.moveRover(move);
		}
	}
	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS) {
		glm::vec3 rotate = glm::vec3(0.0f, 0.2f, 0.0f);
			object.rotateArm(rotate);
	}
	if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS) {
		glm::vec3 rotate = glm::vec3(0.0f, -0.2f, 0.0f);
		object.rotateArm(rotate);
	}
}


int main()
{
	{
		glm::mat4 trans;
		cout << trans << endl;
		trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
		cout << trans << endl;
	}
	if (glfwInit() != GL_TRUE)
	{
		cout << "GLFW initialization failed" << endl;
		return -1;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	try
	{
		GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "GKOM - OpenGL 05", nullptr, nullptr);
		if (window == nullptr)
			throw exception("GLFW window not created");
		glfwMakeContextCurrent(window);
		glfwSetKeyCallback(window, key_callback);

		glewExperimental = GL_TRUE;
		if (glewInit() != GLEW_OK)
			throw exception("GLEW Initialization failed");

		glEnable(GL_DEPTH_TEST);
		glViewport(1, 0, WIDTH, HEIGHT);

		// Build, compile and link shader program
		ShaderProgram lightingShader("shaders/light.vert", "shaders/light.frag");
		ShaderProgram skyboxShader("shaders/skybox.vert", "shaders/skybox.frag");
		ShaderProgram shadowShader("shaders/shadow.vert", "shaders/shadow.frag");

		// DEPTH MAP
		const unsigned int SHADOW_WIDTH = 4096, SHADOW_HEIGHT = 4096;
		unsigned int depthMapFBO;
		glGenFramebuffers(1, &depthMapFBO);
		// create depth texture
		unsigned int depthMap;
		glGenTextures(1, &depthMap);
		glBindTexture(GL_TEXTURE_2D, depthMap);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, SHADOW_WIDTH, SHADOW_HEIGHT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
		float border[] = { 1.0f, 0.0f, 1.0f, 1.0f };
		glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, border);

		// Use depthFBO
		glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthMap, 0);
		glDrawBuffer(GL_NONE);
		glReadBuffer(GL_NONE);
		glBindFramebuffer(GL_FRAMEBUFFER, 0);

		const float near = 7.5f, far = 15.0f;
		const float ORTH = 5.0f;
		glm::vec3 sunDirection(-0.34188f, -0.50663f, -0.90679f);

		glm::mat4 lightProjection = glm::ortho(-ORTH, ORTH, -ORTH, ORTH, near, far);
		glm::mat4 lightView = glm::lookAt(-10.0f * sunDirection, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		glm::mat4 lightSpaceMatrix = lightProjection * lightView;

		Sun sun(sunDirection, glm::vec3(0.3f, 0.24f, 0.14f), glm::vec3(0.7f, 0.42f, 0.26f), glm::vec3(0.5f, 0.5f, 0.5f));

		
		//Rectangle plane;
		Rover rover;
		rover.scale2(glm::vec3(0.4f, 0.4f, 0.4f));
		rover.move2(glm::vec3(0.0f, 0.1f, 0.0f));
		rover.moveRover(glm::vec3(0.0f, 0.0f, -1.5f));

		Camp camp;

		// prepare textures
		GLuint texture0 = LoadMipmapTexture(GL_TEXTURE0, "../resources/8k_mars.jpg");
		GLuint texture1 = LoadMipmapTexture(GL_TEXTURE2, "../resources/top.jpg");
		Camera camera;
		Skybox skybox;

		Rectangle rectangle(GROUND_COLOR);
		rectangle.scale(glm::vec3(PLANE_SIZE, PLANE_SIZE, PLANE_SIZE));
		rectangle.rotate(glm::vec3(90.0f, 0.0f, 0.0f));
		Cylinder cylinder(20, 0.2f, 0.2f, glm::vec3(0.0f, 1.0f, 0.0f));
		cylinder.rotate(glm::vec3(0.2f, 0.0f, -0.5f));
		glm::vec3 roverPosition = glm::vec3(0.0f, 0.0f, 0.0f);

		// main event loop
		while (!glfwWindowShouldClose(window))
		{
			// Check if any events have been activated (key pressed, mouse moved etc.) and call corresponding response functions
			glfwPollEvents();

			// Clear the colorbuffer
			glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			// Bind Textures using texture units
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, texture0);


			glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
			camera.processInput(window);
			glm::mat4 view = camera.viewMatrix();
			glm::vec3 viewPosition = camera.getPosition();

			shadowShader.Use();
			glUniformMatrix4fv(glGetUniformLocation(shadowShader.get_programID(), "lightSpaceMatrix"), 1, GL_FALSE, glm::value_ptr(lightSpaceMatrix));

			glViewport(0, 0, SHADOW_WIDTH, SHADOW_HEIGHT);
			glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
			glClear(GL_DEPTH_BUFFER_BIT);

			roverMovement(rover, shadowShader, window, roverPosition);
			rectangle.draw(shadowShader.get_programID());

			rover.draw(shadowShader.get_programID());
			camp.draw(shadowShader.get_programID());

			glBindFramebuffer(GL_FRAMEBUFFER, 0);

			// set viewport to window dimensions
			glViewport(0, 0, WIDTH, HEIGHT);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			lightingShader.Use();
			

			glUniformMatrix4fv(glGetUniformLocation(lightingShader.get_programID(), "projection"), 1, GL_FALSE, &projection[0][0]);
			glUniformMatrix4fv(glGetUniformLocation(lightingShader.get_programID(), "view"), 1, GL_FALSE, &view[0][0]);
			glUniform3fv(glGetUniformLocation(lightingShader.get_programID(), "viewPosition"), 1, &viewPosition[0]);
			glUniformMatrix4fv(glGetUniformLocation(lightingShader.get_programID(), "lightSpaceMatrix"), 1, GL_FALSE, glm::value_ptr(lightSpaceMatrix));
			glUniform1i(glGetUniformLocation(lightingShader.get_programID(), "shadowMap"), 1);

			sun.processInput(window, lightingShader);

			glActiveTexture(GL_TEXTURE1);
			glBindTexture(GL_TEXTURE_2D, depthMap);

			glUniform1i(glGetUniformLocation(lightingShader.get_programID(), "Texture0"), 0);
			rectangle.draw(lightingShader.get_programID());
			//glActiveTexture(GL_TEXTURE2);
			//glBindTexture(GL_TEXTURE_2D, texture1);
			//glUniform1i(glGetUniformLocation(lightingShader.get_programID(), "Texture0"), 0);
			roverMovement(rover, lightingShader, window, roverPosition);

			camp.draw(lightingShader.get_programID());

			skybox.draw(projection, view, skyboxShader);

			// Swap the screen buffers
			glfwSwapBuffers(window);
		}
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
	}
	glfwTerminate();

	return 0;
}