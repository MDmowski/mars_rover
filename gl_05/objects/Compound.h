#pragma once
#include "Object.h"
#include <vector>
#include <memory>


class Compound : public Object
{
protected:
	std::vector<std::unique_ptr<Object>> objects;
public:

	void addObject(std::unique_ptr<Object> object) {
		objects.push_back(std::move(object));
	}

	void draw(int shaderId)  {
		for (auto& object : objects) {
			object->draw(shaderId);
		}
	}

	void move(const glm::vec3& vector) {
		for (auto& object : objects) {
			object->move(vector);
		}
	}

	void rotate(const glm::vec3& vector) {
		for (auto& object : objects) {
			object->rotate(vector);
		}
	}

	void scale(const glm::vec3& vector) {
		for (auto& object : objects) {
			object->scale(vector);
		}
	}

};
