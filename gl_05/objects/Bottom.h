#pragma once
#include "Compound.h"
#include "Suspension.h"

class Bottom : public Compound {
public:
	Bottom() {
		auto left = std::unique_ptr<Suspension>(new Suspension());
		auto right = std::unique_ptr<Suspension>(new Suspension());

		right->scale2(glm::vec3(1.0f, 1.0f, -1.0f));
		right->move2(glm::vec3(0.0f, 0.0f, 0.4f));


		addObject(std::move(left));
		addObject(std::move(right));
	}
};