#pragma once
#include "Object.h"
#include <vector>
#include <memory>


class Compound : public Item
{
protected:
	std::vector<std::unique_ptr<Item>> objects;
public:

	void addObject(std::unique_ptr<Item> object) {
		objects.push_back(std::move(object));
	}

	void draw(GLuint shaderId)  override {
		for (auto& object : objects) {
			object->draw(shaderId);
		}
	}

	void move(const glm::vec3& vector) override {
		for (auto& object : objects) {
			object->move(vector);
		}
	}

	void move2(const glm::vec3& vector) override {
		for (auto& object : objects) {
			object->move2(vector);
		}
	}

	void rotate(const glm::vec3& vector) override {
		for (auto& object : objects) {
			object->rotate(vector);
		}
	}

	void rotate2(const glm::vec3& vector) override {
		for (auto& object : objects) {
			object->rotate2(vector);
		}
	}

	void rotate3(const glm::vec3& vector, const glm::vec3& pivot) override {
		for (auto& object : objects) {
			object->rotate3(vector, pivot);
		}
	}

	void scale(const glm::vec3& vector) {
		for (auto& object : objects) {
			object->scale(vector);
		}
	}

	void scale2(const glm::vec3& vector) {
		for (auto& object : objects) {
			object->scale2(vector);
		}
	}

};
