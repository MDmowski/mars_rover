#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>
#include "Object.h"
using namespace std;

class Rectangle : public Object {
public:
	Rectangle() {
		vertices = {
			// coordinates			// color			// texture		//normals
			 0.5f,  0.5f, 0.0f,	0.5f, 0.0f, 0.0f,	0.0f,  0.0f,	0.5f, -0.5f, 0.0f, 
			 0.5f, -0.5f, 0.0f,	1.0f, 0.0f, 0.0f,	0.0f,  0.0f,	0.5f, -0.5f, 0.0f,
			-0.5f, -0.5f, 0.0f,	0.0f, 1.0f, 0.0f,	0.0f,  0.0f,	0.5f, -0.5f, 0.0f,
			-0.5f, 0.5f, 0.0f,	0.0f, 1.0f, 0.0f,	0.0f,  0.0f,	0.5f, -0.5f, 0.0f,
		};
		indices = {
			0, 1, 3,
			1, 2, 3 
		};
		init();
	}
};