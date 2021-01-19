
#include "Cube.h"
#include "Compound.h"

#define BLOCK_HEIGHT 0.1
#define BLOCK_WIDTH 0.2
#define BLOCK_DEPTH 3.0
#define FENCE_HEIGHT 1.0
#define ROOM_BETWEEN 0.1
#define PIPE_WIDTH 0.03
#define PIPE_DEPTH 0.03
#define NR_OF_PIPES 100

#define PIPE_POSITION (FENCE_HEIGHT / 2 + BLOCK_HEIGHT / 4)
#define PIPE_HEIGHT (FENCE_HEIGHT - 3 * BLOCK_HEIGHT / 2)
#define OFFSET ((NR_OF_PIPES * ROOM_BETWEEN - ROOM_BETWEEN) / 2)
#define DEPTH ((NR_OF_PIPES * ROOM_BETWEEN + ROOM_BETWEEN))

class FenceSegment : public Compound {
public:
	FenceSegment()
	{
		glm::vec3 grey = glm::vec3(0.45098f, 0.4627f, 0.45098f);
		glm::vec3 brown = glm::vec3(0.3255f, 0.2196f, 0.0f);

		auto blockDown = std::unique_ptr<Cube>(new Cube(brown));
		auto blockTop = std::unique_ptr<Cube>(new Cube(brown));

		blockDown->move(glm::vec3(0.0f, BLOCK_HEIGHT / 2, 0.0f));
		blockDown->scale(glm::vec3(BLOCK_WIDTH, BLOCK_HEIGHT, DEPTH));
		addObject(std::move(blockDown));

		blockTop->move(glm::vec3(0.0f, FENCE_HEIGHT, 0.0f));
		blockTop->scale(glm::vec3(BLOCK_WIDTH, BLOCK_HEIGHT, DEPTH));
		addObject(std::move(blockTop));

		std::unique_ptr<Cube> pipes[NR_OF_PIPES];
		for (int i = 0; i < NR_OF_PIPES; ++i)
		{
			pipes[i] = std::unique_ptr<Cube>(new Cube(grey));
			pipes[i]->move(glm::vec3(0.0f, PIPE_POSITION, -OFFSET + i * ROOM_BETWEEN));
			pipes[i]->scale(glm::vec3(PIPE_WIDTH, PIPE_HEIGHT, PIPE_DEPTH));
			addObject(std::move(pipes[i]));
		}

	}

	

	void rotate90()
	{
		for (int i = 0; i < 2; ++i)
		{
			objects[i]->rotate2(glm::vec3(0.0f, 90.0f, 0.0f));
		}

		for (int i = 2; i < NR_OF_PIPES + 2; ++i)
		{
			objects[i]->rotate2(glm::vec3(0.0f, 90.0f, 0.0f));

		}
	}
};