#pragma once
#include "Compound.h"
#include "Bottom.h"
#include "Arm.h"

class Rover : public Compound {
	glm::vec3 moved;
public:
	Rover() {
		moved = glm::vec3(0.0f, 0.0f, 0.0f);
		auto arm = std::unique_ptr<Arm>(new Arm);
		auto bottom = std::unique_ptr<Bottom>(new Bottom);
		arm->move2(glm::vec3(-0.07f, 0.0f, 0.0f));

		addObject(std::move(arm));
		addObject(std::move(bottom));
	}

	void rotateArm(glm::vec3 rotate) {
		dynamic_cast<Arm&>(*objects[0]).rotateArm(rotate, moved);
	}

	void moveRover(glm::vec3 move) {
		move2(move);
		moved += move;
	}
};