#pragma once
#include "Compound.h"
#include "Bottom.h"
#include "Arm.h"

class Rover : public Compound {
	float moved = 0;
public:
	Rover() {
		auto arm = std::unique_ptr<Arm>(new Arm);
		auto bottom = std::unique_ptr<Bottom>(new Bottom);
		arm->move2(glm::vec3(-0.07f, 0.0f, 0.0f));

		addObject(std::move(arm));
		addObject(std::move(bottom));
	}

	void rotateArm(glm::vec3 rotate) {
		dynamic_cast<Arm&>(*objects[0]).rotateArm(rotate, moved);
	}

	void moveRover(float step) {
		move2(glm::vec3(step, 0.0f, 0.0f));
		moved += step;
	}
};