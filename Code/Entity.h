#pragma once
#include "Mesh.h"
#include "Texture.h"
#include "Demo.h"

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

// forward declaration
class Demo;
class Mesh;
class Texture;

class Entity
{
public:

	// This is only for dynamic font
	// It will be left empty for everything else
	char name[100];

	// Entity data
	// Only one of these will be used
	// per entity, not both at once
	BufferCPU* matrixBufferCPU;
	BufferCPU* spriteBufferCPU;
	VkDescriptorSet descriptor_set;

	// mesh of the entity
	Mesh* mesh;
	
	// for color and normal
	Texture* texture[2];

	glm::vec3 pos;
	glm::vec3 rot;
	glm::vec3 scale;
	glm::mat4 modelMatrix;
	glm::mat4 parentModelMatrix = glm::mat4(1.0);
	float radius;

	glm::mat4 GetModelMatrix();
	glm::vec3 GetWorldPosition();

	Entity(Demo* demo);
	~Entity();

	void CreateDescriptorSetBasic(Demo* demo);
	void CreateDescriptorSetBumpy(Demo* demo);
	void CreateDescriptorSet2D(Demo* demo);

	void Draw(VkCommandBuffer cmd, VkPipelineLayout pipeline_layout);
	void Update3D(glm::mat4x4 projection, glm::mat4x4 view);
	void Update2D(int screenWidth, int screenHeight);
};

