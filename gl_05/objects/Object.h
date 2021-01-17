#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>
#include "Item.h"
#include <glm\gtc\matrix_transform.hpp>
using namespace std;

class Object : public Item{
	GLuint vao, vbo, ebo;
	glm::vec4 color; //todo: fix color and texture
	glm::mat4 model;
protected:
	vector<GLfloat> vertices;
	vector<GLuint> indices;
public:
	Object() :model(glm::mat4(1.0f)) {}

	glm::mat4 getModel() {
		return model;
	}

	void init() {
		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &vbo);
		glGenBuffers(1, &ebo);
		glBindVertexArray(vao);

		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices[0]), &vertices[0], GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(indices[0]), &indices[0], GL_STATIC_DRAW);

		// vertex geometry data
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);

		// vertex color data
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);

		// vertex texture coordinates
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 11 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
		glEnableVertexAttribArray(2);

		// vertex normals data
		glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(GLfloat), (GLvoid*)(8 * sizeof(GLfloat)));
		glEnableVertexAttribArray(3);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	~Object() {
		glDeleteVertexArrays(1, &vao);
		glDeleteBuffers(1, &vbo);
		glDeleteBuffers(1, &ebo);
	}

	void draw(GLuint shader) override {
		glUniformMatrix4fv(glGetUniformLocation(shader, "model"), 1, GL_FALSE, &model[0][0]);
		glUniform4fv(glGetUniformLocation(shader, "Color"), 1, &color[0]);
		glBindVertexArray(vao);
		glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}

	void move(const glm::vec3& vector) override
	{
		model = translate(model, vector);
	}

	void move2(const glm::vec3& vector) override
	{
		model = translate(glm::mat4(1.0f), vector) * model;
	}

	void rotate(const glm::vec3& vector) override
	{
		model = glm::rotate(model, glm::radians(vector.x), glm::vec3(1.0f, 0.0f, 0.0f));
		model = glm::rotate(model, glm::radians(vector.y), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(vector.z), glm::vec3(0.0f, 0.0f, 1.0f));
	}

	void rotate2(const glm::vec3& vector) override
	{
		model = glm::rotate(glm::mat4(1.0f), glm::radians(vector.x), glm::vec3(1.0f, 0.0f, 0.0f)) * model;
		model = glm::rotate(glm::mat4(1.0f), glm::radians(vector.y), glm::vec3(0.0f, 1.0f, 0.0f)) * model;
		model = glm::rotate(glm::mat4(1.0f), glm::radians(vector.z), glm::vec3(0.0f, 0.0f, 1.0f)) * model;
	}

	void scale(const glm::vec3& vector) override
	{
		model = glm::scale(model, vector);
	}

	void scale2(const glm::vec3& vector) override
	{
		model = glm::scale(glm::mat4(1.0f), vector) * model;
	}

	void popModel() {
		model = glm::mat4(1.0f);
	}
};