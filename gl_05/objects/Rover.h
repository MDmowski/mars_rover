#pragma once
#include "Compound.h"
#include "Bottom.h"
#include "Arm.h"

class Rover : public Compound {
public:
	Rover() {
		auto arm = std::unique_ptr<Arm>(new Arm);
		auto bottom = std::unique_ptr<Bottom>(new Bottom);


		addObject(std::move(arm));
		addObject(std::move(bottom));
	}
};