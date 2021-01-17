
#include "Compound.h"
#include "FenceSegment.h"

#define CENTER_X 10.0
#define CENTER_Z 0.0

class FenceFull : public Compound
{
public:
	FenceFull()
	{
		auto segment1 = std::unique_ptr<FenceSegment>(new FenceSegment());
		addObject(std::move(segment1));

		auto segment2 = std::unique_ptr<FenceSegment>(new FenceSegment());
		segment2->move2(glm::vec3(DEPTH / 2, 0.0f, -DEPTH / 2));
		segment2->rotate90();
		addObject(std::move(segment2));
		
		auto segment3 = std::unique_ptr<FenceSegment>(new FenceSegment());
		segment3->move2(glm::vec3(-DEPTH, 0.0f, 0.0f));
		addObject(std::move(segment3));
		
		auto segment4 = std::unique_ptr<FenceSegment>(new FenceSegment());
		segment4->move2(glm::vec3(-DEPTH / 2, 0.0f, -DEPTH / 2));
		segment4->rotate90();
		addObject(std::move(segment4));
	}


};