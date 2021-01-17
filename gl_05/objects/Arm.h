#pragma once
#include "Compound.h"
#include "Cube.h"
#include "Cylinder.h"

class Arm : public Compound {
public:
	Arm() {
		glm::vec3 silver = glm::vec3(0.75f, 0.75f, 0.75f);
		glm::vec3 silver2 = glm::vec3(0.65f, 0.65f, 0.65f);
		glm::vec3 black = glm::vec3(0.03f, 0.03f, 0.03f);
		const float spacing = 0.2;
		const float baseThickness = 0.03;
		const float mainBeamThickness = 0.03;
		const float topBeamThickness = 0.025;

		auto baseLeft = std::unique_ptr<Cube>(new Cube(silver));
		auto baseRight = std::unique_ptr<Cube>(new Cube(silver));
		auto mainAxis = std::unique_ptr<Cylinder>(new Cylinder(32, 0.02, spacing, silver));
		auto mainBeamRight = std::unique_ptr<Cube>(new Cube(silver2));
		auto mainBeamLeft = std::unique_ptr<Cube>(new Cube(silver2));
		auto middleAxis = std::unique_ptr<Cylinder>(new Cylinder(32, 0.015, spacing - 2*mainBeamThickness, silver));
		auto topBeamRight = std::unique_ptr<Cube>(new Cube(silver2));
		auto topBeamLeft = std::unique_ptr<Cube>(new Cube(silver2));
		auto topAxis = std::unique_ptr<Cylinder>(new Cylinder(32, 0.015, spacing - 2 * mainBeamThickness - 2*topBeamThickness, silver));
		auto clawMount = std::unique_ptr<Cube>(new Cube(silver));
		auto clawBase = std::unique_ptr<Cylinder>(new Cylinder(32, 0.1, 0.015, silver));
		auto claw1 = std::unique_ptr<Cylinder>(new Cylinder(3, 0.02, 0.05, black));
		auto claw1End = std::unique_ptr<Cylinder>(new Cylinder(3, 0.02, 0.1, black));
		auto claw2 = std::unique_ptr<Cylinder>(new Cylinder(3, 0.02, 0.05, black));
		auto claw2End = std::unique_ptr<Cylinder>(new Cylinder(3, 0.02, 0.1, black));
		auto claw3 = std::unique_ptr<Cylinder>(new Cylinder(3, 0.02, 0.05, black));
		auto claw3End = std::unique_ptr<Cylinder>(new Cylinder(3, 0.02, 0.1, black));


		baseLeft->move(glm::vec3(0.0f, 0.3f, 0.19 + spacing/2));
		baseLeft->rotate(glm::vec3(0.0f, 0.0f, 0.0f));
		baseLeft->scale(glm::vec3(0.08f, 0.1f, baseThickness));
		baseRight->move(glm::vec3(0.0f, 0.3f, 0.19 - spacing/2));
		baseRight->rotate(glm::vec3(0.0f, 0.0f, 0.0f));
		baseRight->scale(glm::vec3(0.08f, 0.1f, baseThickness));
		mainAxis->move(glm::vec3(0.0f, 0.325f, 0.19 - spacing / 2));
		mainAxis->rotate(glm::vec3(90.0f, 0.0f, 0.0f));

		mainBeamLeft->move(glm::vec3(0.09f, 0.48f, 0.19 + spacing / 2 - (baseThickness + 0.006)));
		mainBeamLeft->rotate(glm::vec3(0.0f, 0.0f, -30.0f));
		mainBeamLeft->scale(glm::vec3(0.08f, 0.4f, mainBeamThickness));
		mainBeamRight->move(glm::vec3(0.09f, 0.48f, 0.19 - spacing / 2 + (baseThickness + 0.006)));
		mainBeamRight->rotate(glm::vec3(0.0f, 0.0f, -30.0f));
		mainBeamRight->scale(glm::vec3(0.08f, 0.4f, mainBeamThickness));
		middleAxis->move(glm::vec3(0.18f, 0.64f, 0.19 - spacing / 2 + mainBeamThickness));
		middleAxis->rotate(glm::vec3(90.0f, 0.0f, 0.0f));

		topBeamLeft->move(glm::vec3(0.35f, 0.65f, 0.19 + spacing / 2 - (baseThickness + 0.006) - mainBeamThickness));
		topBeamLeft->rotate(glm::vec3(0.0f, 0.0f, -80.0f));
		topBeamLeft->scale(glm::vec3(0.08f, 0.4f, topBeamThickness));
		topBeamRight->move(glm::vec3(0.35f, 0.65f, 0.19 - spacing / 2 + (baseThickness + 0.006) + mainBeamThickness));
		topBeamRight->rotate(glm::vec3(0.0f, 0.0f, -80.0f));
		topBeamRight->scale(glm::vec3(0.08f, 0.4f, topBeamThickness));
		topAxis->move(glm::vec3(0.52f, 0.68f, 0.19 - spacing / 2 + mainBeamThickness + topBeamThickness));
		topAxis->rotate(glm::vec3(90.0f, 0.0f, 0.0f));


		clawMount->move(glm::vec3(0.53f, 0.68f, 0.19f));
		clawMount->rotate(glm::vec3(0.0f, 0.0f, 0.0f));
		clawMount->scale(glm::vec3(0.08f, 0.05f, 0.035));
		clawBase->move(glm::vec3(0.58f, 0.68f, 0.19f));
		clawBase->rotate(glm::vec3(0.0f, 0.0f, 90.0f));
		claw1->move(glm::vec3(0.61f, 0.575f, 0.19f));
		claw1->rotate(glm::vec3(0.0f, 0.0f, 45.0f));
		claw1End->move(glm::vec3(0.595f, 0.58f, 0.19f));
		claw1End->rotate(glm::vec3(0.0f, 0.0f, -60.0f));
		claw2->move(glm::vec3(0.61f, 0.74f, 0.27f));
		claw2->rotate(glm::vec3(-120.0f, 0.0f, 45.0f));
		claw2End->move(glm::vec3(0.595f, 0.74f, 0.27f));
		claw2End->rotate(glm::vec3(-120.0f, 0.0f, -60.0f));
		claw3->move(glm::vec3(0.61f, 0.74f, 0.11f));
		claw3->rotate(glm::vec3(120.0f, 0.0f, 45.0f));
		claw3End->move(glm::vec3(0.595f, 0.74f, 0.11f));
		claw3End->rotate(glm::vec3(120.0f, 0.0f, -60.0f));



		addObject(std::move(baseLeft));
		addObject(std::move(baseRight));
		addObject(std::move(mainAxis));
		addObject(std::move(mainBeamLeft));
		addObject(std::move(mainBeamRight));
		addObject(std::move(middleAxis));
		addObject(std::move(topBeamLeft));
		addObject(std::move(topBeamRight));
		addObject(std::move(topAxis));
		addObject(std::move(clawMount));
		addObject(std::move(clawBase));
		addObject(std::move(claw1));
		addObject(std::move(claw1End));
		addObject(std::move(claw2));
		addObject(std::move(claw2End));
		addObject(std::move(claw3));
		addObject(std::move(claw3End));
	}
};