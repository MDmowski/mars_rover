#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>
#include "Object.h"

class Triangle : public Object {
	void initVertices(glm::vec3 color) {
		vertices = {
			// coordinates			// color					// texture		//normals
			 -0.5f,  -0.5f,  0.0f,	color.x, color.y, color.z,	0.0f,  0.0f,	0.577350259f, 0.577350259f, -0.577350259f,	//0
			0.5f,  -0.5f,  0.0f,	color.x, color.y, color.z,	0.0f,  0.0f,	-0.577350259f, 0.577350259f, -0.577350259f,	//1
			0.0f, 0.5f,  0.0f,	color.x, color.y, color.z,	0.0f,  0.0f,	-0.577350259f, -0.577350259f, -0.577350259f,//2
			};
	}
	void initIndices() {
		indices = {
			0,1,2,
		};
	}
public:
	Triangle(glm::vec3 color) {
		initVertices(color);
		initIndices();
		init();
	}
};