#include "Compound.h"
#include "Cylinder.h"
#include "Cone.h"
#include "Triangle.h"

class Rocket : public Compound {
public:
	Rocket() {
		glm::vec3 sand = glm::vec3(0.7725f, 0.7765f, 0.6745f);
		glm::vec3 blue = glm::vec3(0.0f, 0.02f, 0.612f);
		glm::vec3 red = glm::vec3(0.7569f, 0.0902f, 0.0902f);


		auto upperHalfBody = std::unique_ptr<Cone>(new Cone(32, 0.1, 0.01, 0.4, sand));
		auto lowerHalfBody = std::unique_ptr<Cone>(new Cone(32, 0.03, 0.1, 0.4, sand));
		auto base = std::unique_ptr<Cone>(new Cone(32, 0.05, 0.01, 0.1, red));
		
		auto roof = std::unique_ptr<Cone>(new Cone(32, 0.01, 0.0001, 0.1, blue));
		auto baseTriangle1 = std::unique_ptr<Triangle>(new Triangle(blue));
		auto baseTriangle2 = std::unique_ptr<Triangle>(new Triangle(blue));


		roof->move(glm::vec3(0.0f, 0.4f, 0.0f));
		roof->rotate(glm::vec3(0.0f, 60.0f, 0.0f));

		lowerHalfBody->move(glm::vec3(0.0f, -0.4f, 0.0f));

		base->move(glm::vec3(0.0f, -0.45f, 0.0f));
		base->rotate(glm::vec3(0.0f, 60.0f, 0.0f));

		baseTriangle1->scale(glm::vec3(0.2, 0.3, 1.0));
		baseTriangle1->move(glm::vec3(0.0, -1.0, 0.0));

		baseTriangle2->rotate(glm::vec3(0.0f, 90.0f, 0.0f));
		baseTriangle2->scale(glm::vec3(0.2, 0.3, 1.0));
		baseTriangle2->move(glm::vec3(0.0, -1.0, 0.0));


		addObject(std::move(upperHalfBody));
		addObject(std::move(lowerHalfBody));
		addObject(std::move(roof));
		addObject(std::move(base));
		addObject(std::move(baseTriangle1));
		addObject(std::move(baseTriangle2));

	}
};
