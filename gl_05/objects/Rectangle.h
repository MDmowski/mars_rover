#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>
#include "Object.h"
using namespace std;

class Rectangle : public Object {
	void initVertices(glm::vec3 color) {
		vertices = {
		// coordinates			// color			// texture		//normals
		0.5f, 0.5f, 0.0f,	color.x, color.y, color.z, 0.0f, 0.0f,	0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,	color.x, color.y, color.z, 0.0f, 0.0f,	0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,	color.x, color.y, color.z, 0.0f, 0.0f,	0.5f, -0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f,	color.x, color.y, color.z, 0.0f, 0.0f,	0.5f, -0.5f, 0.0f,
	};
}
	void initIndices() {
		indices = {
			0, 1, 3,
			1, 2, 3
		};
	}

public:
	Rectangle(glm::vec3 color) {
		initVertices(color);
		initIndices();
		init();
	}
};