#pragma once
#include "Compound.h"
#include "Suspension.h"

class Bottom : public Compound {
public:
	Bottom() {
		glm::vec3 silver = glm::vec3(0.7f, 0.7f, 0.7f);
		auto left = std::unique_ptr<Suspension>(new Suspension());
		auto right = std::unique_ptr<Suspension>(new Suspension());
		auto body = std::unique_ptr<Cube>(new Cube(silver));

		right->scale2(glm::vec3(1.0f, 1.0f, -1.0f));
		right->move2(glm::vec3(0.0f, 0.0f, 0.38f));

		body->move(glm::vec3(-0.3f, 0.15f, 0.19f));
		body->scale(glm::vec3(0.8f, 0.2f, 0.38f));


		addObject(std::move(left));
		addObject(std::move(right));
		addObject(std::move(body));
	}
};