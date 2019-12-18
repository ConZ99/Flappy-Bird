#include "Laborator1.h"

#include <vector>
#include <iostream>

#include <Core/Engine.h>

using namespace std;

// Order of function calling can be seen in "Source/Core/World.cpp::LoopUpdate()"
// https://github.com/UPB-Graphics/Framework-EGC/blob/master/Source/Core/World.cpp

Laborator1::Laborator1()
{
}

Laborator1::~Laborator1()
{
}

void Laborator1::Init()
{
	// Load a mesh from file into GPU memory
	{
		Mesh* mesh = new Mesh("box");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "box.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}
	{
		Mesh* mesh = new Mesh("archer");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Characters/Archer", "Archer.fbx");
		meshes[mesh->GetMeshID()] = mesh;
	}
	{
		Mesh* mesh = new Mesh("teapot");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "teapot.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}
	{
		Mesh* mesh = new Mesh("sphere");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "sphere.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}
}

void Laborator1::FrameStart()
{

}

float x = 0, y = 0, z = 0;
float r, g, b;
string item = "box";
string dab [3] = { "box", "teapot", "sphere" };
bool grounded = true;


void Laborator1::Update(float deltaTimeSeconds)
{
	glm::ivec2 resolution = window->props.resolution;

	// sets the clear color for the color buffer
	glClearColor(r, g, b, 1);

	// clears the color buffer (using the previously set color) and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);

	// render the object
	RenderMesh(meshes[item], glm::vec3(1, 0.5f, 0), glm::vec3(0.5f));

	// render the object again but with different properties
	RenderMesh(meshes["box"], glm::vec3(-1, 0.5f, 0));

	RenderMesh(meshes["archer"], glm::vec3(x, y, z), glm::vec3(0.01f));

	if (grounded == true) {
		if (y > 0) {
			y -= 0.1f;
		}
	}

	if (grounded == false) {
		if (y < 1) {
			y += 0.1f;
		}
	}

	if (y >= 1)
		grounded = true;
}

void Laborator1::FrameEnd()
{
	DrawCoordinatSystem();
}

// Read the documentation of the following functions in: "Source/Core/Window/InputController.h" or
// https://github.com/UPB-Graphics/Framework-EGC/blob/master/Source/Core/Window/InputController.h

void Laborator1::OnInputUpdate(float deltaTime, int mods)
{
	if (window->KeyHold(GLFW_KEY_LEFT)) {
		x = x + 0.1;
	}
	if (window->KeyHold(GLFW_KEY_RIGHT)) {
		x = x - 0.1;
	}
	if (window->KeyHold(GLFW_KEY_UP)) {
		z = z + 0.1;
	}
	if (window->KeyHold(GLFW_KEY_DOWN)) {
		z = z - 0.1;
	}
	if (window->KeyHold(GLFW_KEY_PAGE_UP)) {
		y = y + 0.1;
	}
	if (window->KeyHold(GLFW_KEY_PAGE_DOWN)) {
		y = y - 0.1;
	}
};

void Laborator1::OnKeyPress(int key, int mods)
{
	if (key == GLFW_KEY_F) {
		r = rand() % 1;
		g = rand() & 1;
		b = rand() & 1;
	}
	if (key == GLFW_KEY_T) {
		item = dab[rand() % 3];
	}
	if (key == GLFW_KEY_SPACE) {
		if (grounded)
			grounded = false;
	}
};

void Laborator1::OnKeyRelease(int key, int mods)
{
	// add key release event
};

void Laborator1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	// add mouse move event
};

void Laborator1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button press event
};

void Laborator1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button release event
}

void Laborator1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
	// treat mouse scroll event
}

void Laborator1::OnWindowResize(int width, int height)
{
	// treat window resize event
}
