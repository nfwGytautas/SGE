#include "Engine.h"

#include <iostream>

int main()
{
	Engine::Initialize(1280, 720, "Game");

	float vertices[] = {
		-0.5f, 0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.5f, 0.5f, 0.0f,
	};

	unsigned int indices[] = {
		0,1,3,
		3,1,2
	};

	float textureCoords[] = {
		0,0,
		0,1,
		1,1,
		1,0
	};

	Mesh testMesh = Engine::Loader::LoadToVAO(ArrayToVector(vertices), ArrayToVector(textureCoords), ArrayToVector(indices));
	Material testMaterial = Engine::Loader::LoadMaterial("E:/Test files/nfw/grassTexture.png");

	Model testModel(testMesh, testMaterial);

	while (!Engine::ShouldClose())
	{
		Engine::Renderer::Prepare();
		Engine::Renderer::Render(testModel);


		Engine::Update();
	}

	Engine::Terminate();
	return 0;
}