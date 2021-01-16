#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>
#include "Object.h"

class Cube : public Object {
	void initVertices(glm::vec3 color) {
		vertices = {
			// coordinates			// color					// texture		//normals
			 0.5f,  0.5f,  -0.5f,	color.x, color.y, color.z,	0.0f,  0.0f,	0.577350259f, 0.577350259f, -0.577350259f,	//0
			-0.5f,  0.5f,  -0.5f,	color.x, color.y, color.z,	0.0f,  0.0f,	-0.577350259f, 0.577350259f, -0.577350259f,	//1
			-0.5f, -0.5f,  -0.5f,	color.x, color.y, color.z,	0.0f,  0.0f,	-0.577350259f, -0.577350259f, -0.577350259f,//2
			0.5f, -0.5f,  -0.5f,	color.x, color.y, color.z,	0.0f,  0.0f,	0.577350259f, -0.577350259f, -0.577350259f,	//3
			-0.5f, -0.5f,  0.5f,	color.x, color.y, color.z,	0.0f,  0.0f,	-0.577350259f, -0.577350259f, 0.577350259f,	//4
			-0.5f,  0.5f,  0.5f,	color.x, color.y, color.z,	0.0f,  0.0f,	-0.577350259f, 0.577350259f, 0.577350259f,	//5
			0.5f,  0.5f,  0.5f,		color.x, color.y, color.z,	0.0f,  0.0f,	0.577350259f, 0.577350259f, 0.577350259f,	//6
			0.5f, -0.5f,  0.5f,		color.x, color.y, color.z,	0.0f,  0.0f,	0.577350259f, -0.577350259f, 0.577350259f,	//7
			-0.5f, -0.5f,  -0.5f,	color.x, color.y, color.z,	0.0f,  0.0f,	-0.577350259f, -0.577350259f, -0.577350259f,//8
			-0.5f, -0.5f,  0.5f,	color.x, color.y, color.z,	0.0f,  0.0f,	-0.577350259f, -0.577350259f, 0.577350259f,	//9
			0.5f, -0.5f,  0.5f,		color.x, color.y, color.z,	0.0f,  0.0f,	0.577350259f, -0.577350259f, 0.577350259f,	//10
			0.5f, -0.5f,  -0.5f,	color.x, color.y, color.z,	0.0f,  0.0f,	0.577350259f, -0.577350259f, -0.577350259f,	//11
			-0.5f,  0.5f,  0.5f,	color.x, color.y, color.z,	0.0f,  0.0f,	-0.577350259f, 0.577350259f, 0.577350259f,	//12
			-0.5f,  0.5f,  -0.5f,	color.x, color.y, color.z,	0.0f,  0.0f,	-0.577350259f, 0.577350259f, -0.577350259f,	//13
			0.5f,  0.5f,  -0.5f,	color.x, color.y, color.z,	0.0f,  0.0f,	0.577350259f, 0.577350259f, -0.577350259f,	//14
			0.5f,  0.5f,  0.5f,		color.x, color.y, color.z,	0.0f,  0.0f,	0.577350259f, 0.577350259f, 0.577350259f,	//15
			-0.5f, -0.5f,  -0.5f,	color.x, color.y, color.z,	0.0f,  0.0f,	-0.577350259f, -0.577350259f, -0.577350259f,//16
			-0.5f,  0.5f,  -0.5f,	color.x, color.y, color.z,	0.0f,  0.0f,	-0.577350259f, 0.577350259f, -0.577350259f,	//17
			-0.5f,  0.5f,  0.5f,	color.x, color.y, color.z,	0.0f,  0.0f,	-0.577350259f, 0.577350259f, 0.577350259f,	//18
			-0.5f, -0.5f,  0.5f,	color.x, color.y, color.z,	0.0f,  0.0f,	-0.577350259f, -0.577350259f, 0.577350259f,	//19
			0.5f, -0.5f,  -0.5f,	color.x, color.y, color.z,	0.0f,  0.0f,	0.577350259f, -0.577350259f, -0.577350259f,	//20
			0.5f, -0.5f,  0.5f,		color.x, color.y, color.z,	0.0f,  0.0f,	0.577350259f, -0.577350259f, 0.577350259f,	//21
			0.5f,  0.5f,  0.5f,		color.x, color.y, color.z,	0.0f,  0.0f,	0.577350259f, 0.577350259f, 0.577350259f,	//22
			0.5f,  0.5f,  -0.5f,	color.x, color.y, color.z,	0.0f,  0.0f,	0.577350259f, 0.577350259f, -0.577350259f	//23
		};
	}
	void initIndices() {
		indices = {
			0,1,2,
			0,2,3,
			4,5,6,
			4,6,7,
			8,9,10,
			8,10,11,
			12,13,14,
			12,14,15,
			16,17,18,
			16,18,19,
			20,21,22,
			20,22,23
		};
	}
public:
	Cube(glm::vec3 color) {
		initVertices(color);
		initIndices();
		init();
	}
};