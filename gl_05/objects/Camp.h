
#include "Compound.h"
#include "FenceFull.h"
//#include "Rocket.h"
#include "Building.h"

class Camp : public Compound {
public:
	Camp() {
		auto building1 = std::unique_ptr<Building>(new Building());
		auto building2 = std::unique_ptr<Building>(new Building());
		auto building3 = std::unique_ptr<Building>(new Building());
		//auto rocket = std::unique_ptr<Rocket>(new Rocket());
		auto fence = std::unique_ptr<FenceFull>(new FenceFull());
	

		fence->scale2(glm::vec3(0.18f, 0.18f, 0.18f));
		fence->move2(glm::vec3(0.9f, 0.0f, 0.0f));
		

		building1->scale2(glm::vec3(0.9f, 0.9f, 0.9f));
		building1->move2(glm::vec3(-0.49f, 0.0f, 0.49f));

		building2->scale2(glm::vec3(0.7f, 0.7f, 0.7f));
		building2->move2(glm::vec3(-0.49f, 0.0f, -0.49f));

		building3->scale2(glm::vec3(1.2f, 1.2f, 1.2f));
		building3->move2(glm::vec3(0.33f, 0.0f, -0.25f));



		addObject(std::move(building1));
		addObject(std::move(building2));
		addObject(std::move(building3));
		//addObject(std::move(rocket));
		addObject(std::move(fence));


	}

};
