
#include "Compound.h"
#include "Cylinder.h"
#include "Cone.h"

class Building : public Compound {
public:
	Building() {
		glm::vec3 sand = glm::vec3(0.7725f, 0.7765f, 0.6745f);
		glm::vec3 blue = glm::vec3(0.0f, 0.02f, 0.612f);
		glm::vec3 red = glm::vec3(0.7569f, 0.0902f, 0.0902f);

		
		auto base = std::unique_ptr<Cylinder>(new Cylinder(32, 0.3, 0.6, sand));
		auto pillar1 = std::unique_ptr<Cylinder>(new Cylinder(32, 0.015, 0.4, red));
		auto pillar2 = std::unique_ptr<Cylinder>(new Cylinder(32, 0.015, 0.4, red));
		auto pillar3 = std::unique_ptr<Cylinder>(new Cylinder(32, 0.015, 0.4, red));
		auto pillar4 = std::unique_ptr<Cylinder>(new Cylinder(32, 0.015, 0.4, red));
		auto roof = std::unique_ptr<Cone>(new Cone(32, 0.3, 0.07, 0.2, blue));

				
		roof->move(glm::vec3(0.0f, 0.6f, 0.0f));
		roof->rotate(glm::vec3(0.0f, 60.0f, 0.0f));

		pillar1->rotate(glm::vec3(0.0f, 0.0f, 20.0f));
		pillar1->move(glm::vec3(0.4f, -0.15f, 0.0f));

		pillar2->rotate(glm::vec3(0.0f, 0.0f, -20.0f));
		pillar2->move(glm::vec3(-0.4f, -0.15f, 0.0f));

		pillar3->rotate(glm::vec3(20.0f, 0.0f, 0.0f));
		pillar3->move(glm::vec3(0.0f, -0.15f, -0.4f));

		pillar4->rotate(glm::vec3(-20.0f, 0.0f, 0.0f));
		pillar4->move(glm::vec3(0.0f, -0.15f, 0.4f));

		
		addObject(std::move(base));
		addObject(std::move(roof));

		addObject(std::move(pillar1));
		addObject(std::move(pillar2));
		addObject(std::move(pillar3));
		addObject(std::move(pillar4));
		
	}
};
