#pragma once
#include "Object.h"

//static const float PI = 3.1415926f;

class Cone : public Object {
public:
	Cone(int slices, float radiusBottom, float radiusTop, float height, glm::vec3 color) {
		vertices = { 0.0f, 0.0f, 0.0f, color.x, color.y, color.z, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f }; // center of the bottom
		for (int i = 0; i < slices; i++) {
			vertices.push_back(radiusBottom * sin(i * 2 * PI / slices));
			vertices.push_back(0.0f);
			vertices.push_back(radiusBottom * cos(i * 2 * PI / slices));
			vertices.push_back(color.x);
			vertices.push_back(color.y);
			vertices.push_back(color.z);
			vertices.push_back(0.0f); // TODO: Fix texture
			vertices.push_back(0.0f); // TODO: Fix texture
			glm::vec3 upward = glm::vec3(0.0f, height, 0.0f);
			glm::vec3 edge1 = glm::vec3(radiusBottom * sin((i + 1) * 2 * PI / slices) - radiusBottom * sin(i * 2 * PI / slices), 0.0f, radiusBottom * cos((i + 1) * 2 * PI / slices) - radiusBottom * cos(i * 2 * PI / slices));
			glm::vec3 edge2 = glm::vec3(radiusBottom * sin((i - 1) * 2 * PI / slices) - radiusBottom * sin(i * 2 * PI / slices), 0.0f, radiusBottom * cos((i - 1) * 2 * PI / slices) - radiusBottom * cos(i * 2 * PI / slices));
			glm::vec3 normal1 = glm::cross(upward, edge1);
			glm::vec3 normal2 = glm::cross(edge2, upward);
			glm::vec3 result = normalize(upward) + normalize(normal1) + normalize(normal2);
			result /= sqrt(result.x * result.x + result.y * result.y + result.z * result.z);
			result *= -1;
			vertices.push_back(result.x);	//normal vector x
			vertices.push_back(result.y);	//normal vector y
			vertices.push_back(result.z);	//normal vector z
		}
		// center of the top
		vertices.push_back(0.0f);
		vertices.push_back(height);
		vertices.push_back(0.0f);
		vertices.push_back(color.x);
		vertices.push_back(color.y);
		vertices.push_back(color.z);
		vertices.push_back(0.0f);	// TODO: Fix texture
		vertices.push_back(0.0f);	// TODO: Fix texture
		vertices.push_back(0.0f);	//normal vector x
		vertices.push_back(1.0f);	//normal vector y
		vertices.push_back(0.0f);	//normal vector z
		for (int i = 0; i < slices; i++) {
			vertices.push_back(radiusTop * sin(i * 2 * PI / slices));
			vertices.push_back(height);
			vertices.push_back(radiusTop * cos(i * 2 * PI / slices));
			vertices.push_back(color.x);
			vertices.push_back(color.y);
			vertices.push_back(color.z);
			vertices.push_back(0.0f); // TODO: Fix texture
			vertices.push_back(0.0f); // TODO: Fix texture
			glm::vec3 downward = glm::vec3(0.0f, -height, 0.0f);
			glm::vec3 edge1 = glm::vec3(radiusBottom * sin((i + 1) * 2 * PI / slices) - radiusBottom * sin(i * 2 * PI / slices), 0.0f, radiusBottom * cos((i + 1) * 2 * PI / slices) - radiusBottom * cos(i * 2 * PI / slices));
			glm::vec3 edge2 = glm::vec3(radiusBottom * sin((i - 1) * 2 * PI / slices) - radiusBottom * sin(i * 2 * PI / slices), 0.0f, radiusBottom * cos((i - 1) * 2 * PI / slices) - radiusBottom * cos(i * 2 * PI / slices));
			glm::vec3 normal1 = glm::cross(edge1, downward);
			glm::vec3 normal2 = glm::cross(downward, edge2);
			glm::vec3 result = downward + normal1 + normal2;;
			result /= sqrt(result.x * result.x + result.y * result.y + result.z * result.z);
			result *= -1;
			vertices.push_back(result.x);	//normal vector x
			vertices.push_back(result.y);	//normal vector y
			vertices.push_back(result.z);	//normal vector z
		}
		for (int i = 1; i < slices; i++) {
			indices.push_back(0);
			indices.push_back(i);
			indices.push_back(i + 1);
		}
		indices.push_back(0);
		indices.push_back(slices);
		indices.push_back(1);

		for (int i = slices + 2; i <= 2 * slices; i++) {
			indices.push_back(slices + 1);
			indices.push_back(i);
			indices.push_back(i + 1);
		}
		indices.push_back(slices + 1);
		indices.push_back(2 * slices + 1);
		indices.push_back(slices + 2);

		for (int i = 1; i < slices; i++) {
			indices.push_back(i);
			indices.push_back(i + 1);
			indices.push_back(i + slices + 1);
			indices.push_back(i + slices + 1);
			indices.push_back(i + 1);
			indices.push_back(i + slices + 2);
		}
		indices.push_back(slices);
		indices.push_back(2 * slices + 1);
		indices.push_back(1);
		indices.push_back(1);
		indices.push_back(2 * slices + 1);
		indices.push_back(slices + 2);
		init();
	}
};
