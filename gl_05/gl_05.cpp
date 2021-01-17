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
#include "objects/Skybox.h"
#include "shprogram.h"
#include "camera.hpp"

const GLuint WIDTH = 800, HEIGHT = 600;

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

		// Let's check what are maximum parameters counts
		GLint nrAttributes;
		glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
		cout << "Max vertex attributes allowed: " << nrAttributes << std::endl;
		glGetIntegerv(GL_MAX_TEXTURE_COORDS, &nrAttributes);
		cout << "Max texture coords allowed: " << nrAttributes << std::endl;
		

		// Build, compile and link shader program
		ShaderProgram theProgram("gl_05.vert", "gl_05.frag");
		ShaderProgram skyboxShader("skybox.vert", "skybox.frag");

		// prepare textures
		GLuint texture0 = LoadMipmapTexture(GL_TEXTURE0, "../resources/lazik.png");
		Camera camera;
		Skybox skybox;
		//Rectangle plane;
		glm::vec3 vec = glm::vec3(1.0f, 1.0f, -1.0f);
		vec /= sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
		Cylinder cylinder(20, 0.2f, 0.2f, glm::vec3(0.0f, 1.0f, 0.0f));

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
			glUniform1i(glGetUniformLocation(theProgram.get_programID(), "Texture0"), 0);

			theProgram.Use();
			glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
			camera.processInput(window);
			glm::mat4 view = camera.viewMatrix();

			// Draw our first triangle
			glUniformMatrix4fv(glGetUniformLocation(theProgram.get_programID(), "projection"), 1, GL_FALSE, &projection[0][0]);
			glUniformMatrix4fv(glGetUniformLocation(theProgram.get_programID(), "view"), 1, GL_FALSE, &view[0][0]);

			cylinder.rotate(glm::vec3(0.1f, 0.0f, 0.0f));
			//cylinder.move(glm::vec3(0.0001f, 0.0f, 0.0f));
			cylinder.draw(theProgram.get_programID());

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
