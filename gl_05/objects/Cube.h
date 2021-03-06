#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>
#include "Object.h"

class Cube : public Object {
	void initVertices(glm::vec3 color) {
		vertices = {
            // positions          // normals           // texture coords
			-0.5f, -0.5f, -0.5f, color.x, color.y, color.z, 0.0f,  0.0f, 0.0f,  0.0f, -1.0f, 
			 0.5f, -0.5f, -0.5f, color.x, color.y, color.z, 0.0f,  0.0f, 0.0f,  0.0f, -1.0f, 
			 0.5f,  0.5f, -0.5f, color.x, color.y, color.z, 0.0f,  0.0f, 0.0f,  0.0f, -1.0f, 
			 0.5f,  0.5f, -0.5f, color.x, color.y, color.z, 0.0f,  0.0f, 0.0f,  0.0f, -1.0f, 
			-0.5f,  0.5f, -0.5f, color.x, color.y, color.z, 0.0f,  0.0f, 0.0f,  0.0f, -1.0f, 
			-0.5f, -0.5f, -0.5f, color.x, color.y, color.z, 0.0f,  0.0f, 0.0f,  0.0f, -1.0f, 

			-0.5f, -0.5f,  0.5f, color.x, color.y, color.z, 0.0f,  0.0f, 0.0f,  0.0f,  1.0f, 
			 0.5f, -0.5f,  0.5f, color.x, color.y, color.z, 0.0f,  0.0f, 0.0f,  0.0f,  1.0f, 
			 0.5f,  0.5f,  0.5f, color.x, color.y, color.z, 0.0f,  0.0f, 0.0f,  0.0f,  1.0f, 
			 0.5f,  0.5f,  0.5f, color.x, color.y, color.z, 0.0f,  0.0f, 0.0f,  0.0f,  1.0f, 
			-0.5f,  0.5f,  0.5f, color.x, color.y, color.z, 0.0f,  0.0f, 0.0f,  0.0f,  1.0f, 
			-0.5f, -0.5f,  0.5f, color.x, color.y, color.z, 0.0f,  0.0f, 0.0f,  0.0f,  1.0f, 

			-0.5f,  0.5f,  0.5f, color.x, color.y, color.z, 0.0f,  0.0f,-1.0f,  0.0f,  0.0f, 
			-0.5f,  0.5f, -0.5f, color.x, color.y, color.z, 0.0f,  0.0f,-1.0f,  0.0f,  0.0f, 
			-0.5f, -0.5f, -0.5f, color.x, color.y, color.z, 0.0f,  0.0f,-1.0f,  0.0f,  0.0f, 
			-0.5f, -0.5f, -0.5f, color.x, color.y, color.z, 0.0f,  0.0f,-1.0f,  0.0f,  0.0f, 
			-0.5f, -0.5f,  0.5f, color.x, color.y, color.z, 0.0f,  0.0f,-1.0f,  0.0f,  0.0f, 
			-0.5f,  0.5f,  0.5f, color.x, color.y, color.z, 0.0f,  0.0f,-1.0f,  0.0f,  0.0f, 

			 0.5f,  0.5f,  0.5f, color.x, color.y, color.z, 0.0f,  0.0f, 1.0f,  0.0f,  0.0f,
			 0.5f,  0.5f, -0.5f, color.x, color.y, color.z, 0.0f,  0.0f, 1.0f,  0.0f,  0.0f,
			 0.5f, -0.5f, -0.5f, color.x, color.y, color.z, 0.0f,  0.0f, 1.0f,  0.0f,  0.0f,
			 0.5f, -0.5f, -0.5f, color.x, color.y, color.z, 0.0f,  0.0f, 1.0f,  0.0f,  0.0f,
			 0.5f, -0.5f,  0.5f, color.x, color.y, color.z, 0.0f,  0.0f, 1.0f,  0.0f,  0.0f,
			 0.5f,  0.5f,  0.5f, color.x, color.y, color.z, 0.0f,  0.0f, 1.0f,  0.0f,  0.0f,

			-0.5f, -0.5f, -0.5f, color.x, color.y, color.z, 0.0f,  0.0f, 0.0f, -1.0f,  0.0f,
			 0.5f, -0.5f, -0.5f, color.x, color.y, color.z, 0.0f,  0.0f, 0.0f, -1.0f,  0.0f,
			 0.5f, -0.5f,  0.5f, color.x, color.y, color.z, 0.0f,  0.0f, 0.0f, -1.0f,  0.0f,
			 0.5f, -0.5f,  0.5f, color.x, color.y, color.z, 0.0f,  0.0f, 0.0f, -1.0f,  0.0f,
			-0.5f, -0.5f,  0.5f, color.x, color.y, color.z, 0.0f,  0.0f, 0.0f, -1.0f,  0.0f,
			-0.5f, -0.5f, -0.5f, color.x, color.y, color.z, 0.0f,  0.0f, 0.0f, -1.0f,  0.0f,

			-0.5f,  0.5f, -0.5f, color.x, color.y, color.z, 0.0f,  0.0f, 0.0f,  1.0f,  0.0f,
			 0.5f,  0.5f, -0.5f, color.x, color.y, color.z, 0.0f,  0.0f, 0.0f,  1.0f,  0.0f,
			 0.5f,  0.5f,  0.5f, color.x, color.y, color.z, 0.0f,  0.0f, 0.0f,  1.0f,  0.0f,
			 0.5f,  0.5f,  0.5f, color.x, color.y, color.z, 0.0f,  0.0f, 0.0f,  1.0f,  0.0f,
			-0.5f,  0.5f,  0.5f, color.x, color.y, color.z, 0.0f,  0.0f, 0.0f,  1.0f,  0.0f,
			-0.5f,  0.5f, -0.5f, color.x, color.y, color.z, 0.0f,  0.0f,  0.0f,  1.0f,  0.0f

		};
	}
	void initIndices() {
		indices = {
			0,1,2,
			3,4,5,
			6,7,8,
			9,10,11,
			12,13,14,
			15,16,17,
			18,19,20,
			21,22,23,
			24,25,26,
			27,28,29,
			30,31,32,
			33,34,35
		};
	}
public:
	Cube(glm::vec3 color) {
		initVertices(color);
		initIndices();
		init();
	}
};