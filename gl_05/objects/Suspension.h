#pragma once
#include "Compound.h"
#include "Cube.h"
#include "Cylinder.h"

class Suspension : public Compound {
public:
	Suspension() {
		glm::vec3 silver = glm::vec3(0.75f, 0.75f, 0.75f);
		glm::vec3 silver2 = glm::vec3(0.65f, 0.65f, 0.65f);
		glm::vec3 black = glm::vec3(0.03f, 0.03f, 0.03f);
		auto rear = std::unique_ptr<Cube>(new Cube(silver));
		auto crossbeam = std::unique_ptr<Cube>(new Cube(silver));
		auto front1 = std::unique_ptr<Cube>(new Cube(silver));
		auto front2 = std::unique_ptr<Cube>(new Cube(silver));
		auto tire1 = std::unique_ptr<Cylinder>(new Cylinder(32,0.1,0.1,black));
		auto tire2 = std::unique_ptr<Cylinder>(new Cylinder(32, 0.1, 0.1, black));
		auto tire3 = std::unique_ptr<Cylinder>(new Cylinder(32, 0.1, 0.1, black));
		auto hub1 = std::unique_ptr<Cylinder>(new Cylinder(32, 0.07, 0.107, silver));
		auto hub2 = std::unique_ptr<Cylinder>(new Cylinder(32, 0.07, 0.107, silver));
		auto hub3 = std::unique_ptr<Cylinder>(new Cylinder(32, 0.07, 0.107, silver));
		auto connector1 = std::unique_ptr<Cylinder>(new Cylinder(32, 0.02, 0.05, silver2));
		auto connector2 = std::unique_ptr<Cylinder>(new Cylinder(32, 0.02, 0.05, silver2));
		auto connector3 = std::unique_ptr<Cylinder>(new Cylinder(32, 0.02, 0.05, silver2));

		front1->move(glm::vec3(-0.05f, 0.0f, 0.0f));
		front1->rotate(glm::vec3(0.0f, 0.0f, 60.0f));
		front1->scale(glm::vec3(0.05f, 0.7f, 0.03f));
		front2->move(glm::vec3(-0.17f, -0.08f, 0.0f));
		front2->rotate(glm::vec3(0.0f, 0.0f, -45.0f));
		front2->scale(glm::vec3(0.05f, 0.3f, 0.03f));
		crossbeam->move(glm::vec3(-0.28f, 0.02f, 0.0f));
		crossbeam->rotate(glm::vec3(0.0f, 0.0f, 90.0f));
		crossbeam->scale(glm::vec3(0.05f, 0.4f, 0.03f));
		rear->move(glm::vec3(-0.5f, 0.0f, 0.0f));
		rear->rotate(glm::vec3(0.0f, 0.0f, -45.0f));
		rear->scale(glm::vec3(0.05f, 0.5f, 0.03f));
		tire1->move(glm::vec3(-0.665f, -0.165f, -0.13f));
		tire1->rotate(glm::vec3(90.0f, 0.0f, 0.0f));
		connector1->move(glm::vec3(-0.666f, -0.165f, -0.05f));
		connector1->rotate(glm::vec3(90.0f, 0.0f, 0.0f));
		hub1->move(glm::vec3(-0.665f, -0.165f, -0.135f));
		hub1->rotate(glm::vec3(90.0f, 0.0f, 0.0f));
		tire2->move(glm::vec3(-0.26f, -0.17f, -0.13f));
		tire2->rotate(glm::vec3(90.0f, 0.0f, 0.0f));
		connector2->move(glm::vec3(-0.26f, -0.17f, -0.05f));
		connector2->rotate(glm::vec3(90.0f, 0.0f, 0.0f));
		hub2->move(glm::vec3(-0.26f, -0.17f, -0.135f));
		hub2->rotate(glm::vec3(90.0f, 0.0f, 0.0f));
		tire3->move(glm::vec3(0.235f, -0.17f, -0.13f));
		tire3->rotate(glm::vec3(90.0f, 0.0f, 0.0f));
		connector3->move(glm::vec3(0.235f, -0.17f, -0.05f));
		connector3->rotate(glm::vec3(90.0f, 0.0f, 0.0f));
		hub3->move(glm::vec3(0.235f, -0.17f, -0.135f));
		hub3->rotate(glm::vec3(90.0f, 0.0f, 0.0f));
		

		addObject(std::move(rear));
		addObject(std::move(crossbeam));
		addObject(std::move(front1));
		addObject(std::move(front2));
		addObject(std::move(tire1));
		addObject(std::move(tire2));
		addObject(std::move(tire3));
		addObject(std::move(hub1));
		addObject(std::move(hub2));
		addObject(std::move(hub3));
		addObject(std::move(connector1));
		addObject(std::move(connector2));
		addObject(std::move(connector3));
	}
};