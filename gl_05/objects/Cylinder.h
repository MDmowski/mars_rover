#pragma once
#include "Object.h"

class Cylinder : public Object {
	const float PI = 3.1415926f;
public:
	Cylinder(int slices, float radius, float height, glm::vec3 color) {
		vertices = { 0.0f, 0.0f, 0.0f, color.x, color.y, color.z, 0.0f, 0.0f }; // center of the bottom
		for (int i = 0; i < slices; i++) {
			vertices.push_back(radius * sin(i * 2 * PI / slices));
			vertices.push_back(0.0f);
			vertices.push_back(radius * cos(i * 2 * PI / slices));
			vertices.push_back(color.x);
			vertices.push_back(color.y);
			vertices.push_back(color.z);
			vertices.push_back(0.0f); // TODO: Fix texture
			vertices.push_back(0.0f); // TODO: Fix texture
		}
		// center of the top
		vertices.push_back(0.0f);
		vertices.push_back(height);
		vertices.push_back(0.0f);
		vertices.push_back(color.x);
		vertices.push_back(color.y);
		vertices.push_back(color.z);
		vertices.push_back(0.0f);
		vertices.push_back(0.0f);
		for (int i = 0; i < slices; i++) {
			vertices.push_back(radius * sin(i * 2 * PI / slices));
			vertices.push_back(height);
			vertices.push_back(radius * cos(i * 2 * PI / slices));
			vertices.push_back(color.x);
			vertices.push_back(color.y);
			vertices.push_back(color.z);
			vertices.push_back(0.0f); // TODO: Fix texture
			vertices.push_back(0.0f); // TODO: Fix texture
		}
		for (int i = 1; i < slices; i++) {
			indices.push_back(0);
			indices.push_back(i);
			indices.push_back(i+1);
		}
		indices.push_back(0);
		indices.push_back(slices);
		indices.push_back(1);

		for (int i = slices + 2; i <= 2*slices; i++) {
			indices.push_back(slices+1);
			indices.push_back(i);
			indices.push_back(i + 1);
		}
		indices.push_back(slices+1);
		indices.push_back(2*slices+1);
		indices.push_back(slices+2);

		for (int i = 1; i < slices; i++) {
			indices.push_back(i);
			indices.push_back(i+1);
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
