#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>
#include "Object.h"

class Cube : public Object {
public:
	Cube() {
		vertices = {
			// coordinates			// color			// texture
			 0.5f,  0.5f,  -0.5f,	0.0f, 0.0f, 1.0f,	0.0f,  0.0f,	//0
			-0.5f,  0.5f,  -0.5f,	0.0f, 0.0f, 1.0f,	0.0f,  0.0f,	//1
			-0.5f, -0.5f,  -0.5f,	0.0f, 0.0f, 1.0f,	0.0f,  0.0f,	//2
			0.5f, -0.5f,  -0.5f,	0.0f, 0.0f, 1.0f,	0.0f,  0.0f,	//3
			-0.5f, -0.5f,  0.5f,	0.0f, 0.0f, 1.0f,	0.0f,  0.0f,	//4
			-0.5f,  0.5f,  0.5f,	0.0f, 0.0f, 1.0f,	0.0f,  0.0f,	//5
			0.5f,  0.5f,  0.5f,		0.0f, 0.0f, 1.0f,	0.0f,  0.0f,	//6
			0.5f, -0.5f,  0.5f,		0.0f, 0.0f, 1.0f,	0.0f,  0.0f,	//7
			-0.5f, -0.5f,  -0.5f,	0.0f, 1.0f, 0.0f,	0.0f,  0.0f,	//8
			-0.5f, -0.5f,  0.5f,	0.0f, 1.0f, 0.0f,	0.0f,  0.0f,	//9
			0.5f, -0.5f,  0.5f,		0.0f, 1.0f, 0.0f,	0.0f,  0.0f,	//10
			0.5f, -0.5f,  -0.5f,	0.0f, 1.0f, 0.0f,	0.0f,  0.0f,	//11
			-0.5f,  0.5f,  0.5f,	0.0f, 1.0f, 0.0f,	0.0f,  0.0f,	//12
			-0.5f,  0.5f,  -0.5f,	0.0f, 1.0f, 0.0f,	0.0f,  0.0f,	//13
			0.5f,  0.5f,  -0.5f,	0.0f, 1.0f, 0.0f,	0.0f,  0.0f,	//14
			0.5f,  0.5f,  0.5f,		0.0f, 1.0f, 0.0f,	0.0f,  0.0f,	//15
			-0.5f, -0.5f,  -0.5f,	1.0f, 0.0f, 0.0f,	0.0f,  0.0f,	//16
			-0.5f,  0.5f,  -0.5f,	1.0f, 0.0f, 0.0f,	0.0f,  0.0f,	//17
			-0.5f,  0.5f,  0.5f,	1.0f, 0.0f, 0.0f,	0.0f,  0.0f,	//19
			-0.5f, -0.5f,  0.5f,	1.0f, 0.0f, 0.0f,	0.0f,  0.0f,	//18
			0.5f, -0.5f,  -0.5f,	1.0f, 0.0f, 0.0f,	0.0f,  0.0f,	//20
			0.5f, -0.5f,  0.5f,		1.0f, 0.0f, 0.0f,	0.0f,  0.0f,	//21
			0.5f,  0.5f,  0.5f,		1.0f, 0.0f, 0.0f,	0.0f,  0.0f,	//22
			0.5f,  0.5f,  -0.5f,	1.0f, 0.0f, 0.0f,	0.0f,  0.0f		//23
		};
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
		init();
	}
	Cube(glm::vec3 color) {
		vertices = {
			// coordinates			// color					// texture
			 0.5f,  0.5f,  -0.5f,	color.x, color.y, color.z,	0.0f,  0.0f,	//0
			-0.5f,  0.5f,  -0.5f,	color.x, color.y, color.z,	0.0f,  0.0f,	//1
			-0.5f, -0.5f,  -0.5f,	color.x, color.y, color.z,	0.0f,  0.0f,	//2
			0.5f, -0.5f,  -0.5f,	color.x, color.y, color.z,	0.0f,  0.0f,	//3
			-0.5f, -0.5f,  0.5f,	color.x, color.y, color.z,	0.0f,  0.0f,	//4
			-0.5f,  0.5f,  0.5f,	color.x, color.y, color.z,	0.0f,  0.0f,	//5
			0.5f,  0.5f,  0.5f,		color.x, color.y, color.z,	0.0f,  0.0f,	//6
			0.5f, -0.5f,  0.5f,		color.x, color.y, color.z,	0.0f,  0.0f,	//7
			-0.5f, -0.5f,  -0.5f,	color.x, color.y, color.z,	0.0f,  0.0f,	//8
			-0.5f, -0.5f,  0.5f,	color.x, color.y, color.z,	0.0f,  0.0f,	//9
			0.5f, -0.5f,  0.5f,		color.x, color.y, color.z,	0.0f,  0.0f,	//10
			0.5f, -0.5f,  -0.5f,	color.x, color.y, color.z,	0.0f,  0.0f,	//11
			-0.5f,  0.5f,  0.5f,	color.x, color.y, color.z,	0.0f,  0.0f,	//12
			-0.5f,  0.5f,  -0.5f,	color.x, color.y, color.z,	0.0f,  0.0f,	//13
			0.5f,  0.5f,  -0.5f,	color.x, color.y, color.z,	0.0f,  0.0f,	//14
			0.5f,  0.5f,  0.5f,		color.x, color.y, color.z,	0.0f,  0.0f,	//15
			-0.5f, -0.5f,  -0.5f,	color.x, color.y, color.z,	0.0f,  0.0f,	//16
			-0.5f,  0.5f,  -0.5f,	color.x, color.y, color.z,	0.0f,  0.0f,	//17
			-0.5f,  0.5f,  0.5f,	color.x, color.y, color.z,	0.0f,  0.0f,	//19
			-0.5f, -0.5f,  0.5f,	color.x, color.y, color.z,	0.0f,  0.0f,	//18
			0.5f, -0.5f,  -0.5f,	color.x, color.y, color.z,	0.0f,  0.0f,	//20
			0.5f, -0.5f,  0.5f,		color.x, color.y, color.z,	0.0f,  0.0f,	//21
			0.5f,  0.5f,  0.5f,		color.x, color.y, color.z,	0.0f,  0.0f,	//22
			0.5f,  0.5f,  -0.5f,	color.x, color.y, color.z,	0.0f,  0.0f		//23
		};
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
		init();
	}
};