#pragma once

#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>
#include <glm\gtc\matrix_transform.hpp>
using namespace std;

class Item {

public:

	virtual ~Item() {}

	virtual void draw(GLuint shader) = 0;

	virtual void move(const glm::vec3& vector) = 0;

	virtual void move2(const glm::vec3& vector) = 0;

	virtual void rotate(const glm::vec3& vector) = 0;

	virtual void rotate2(const glm::vec3& vector) = 0;

	virtual void scale(const glm::vec3& vector) = 0;

	virtual void scale2(const glm::vec3& vector) = 0;
};
