#include "Laborator4.h"

#include <vector>
#include <string>
#include <iostream>

#include <Core/Engine.h>
#include "Transform3D.h"

using namespace std;

Laborator4::Laborator4()
{
}

Laborator4::~Laborator4()
{
}

void Laborator4::Init()
{
	polygonMode = GL_FILL;

	Mesh* mesh = new Mesh("box");
	mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "box.obj");
	meshes[mesh->GetMeshID()] = mesh;

	// initialize tx, ty and tz (the translation steps)
	translateX = 0;
	translateY = 0;
	translateZ = 0;

	// initialize sx, sy and sz (the scale factors)
	scaleX = 1;
	scaleY = 1;
	scaleZ = 1;
	
	// initialize angularSteps
	angularStepOX = 0;
	angularStepOY = 0;
	angularStepOZ = 0;

	//initialize speeds
	tSpeed = 1;
	sSpeed = 1;
	rSpeed = 1;

	up = false;
	limit = 1;
	angular = 0;
	check = false;
	saritura = 0;
}

void Laborator4::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);
	centru = 15;
}

void Laborator4::Update(float deltaTimeSeconds)
{
	glLineWidth(3);
	glPointSize(5);
	glPolygonMode(GL_FRONT_AND_BACK, polygonMode);

	if (up == false) {
		if (translateY < limit) {
			scaleX += 1*deltaTimeSeconds;
			scaleY += 1*deltaTimeSeconds;
			scaleZ += 1*deltaTimeSeconds;
			translateY += 2 * deltaTimeSeconds;
		}
		else {
			up = true;
		}
	}
	else {
		if (translateY > 0) {
			scaleX -= 1*deltaTimeSeconds;
			scaleY -= 1*deltaTimeSeconds;
			scaleZ -= 1*deltaTimeSeconds;
			translateY -= 2 * deltaTimeSeconds;
		}
		else {
			up = false;
		}
	}


	modelMatrix = glm::mat4(1);
	modelMatrix *= Transform3D::Translate(-2.5f, 0.5f,-1.5f);
	modelMatrix *= Transform3D::Translate(0, translateY, 0);
	RenderMesh(meshes["box"], shaders["VertexNormal"], modelMatrix);

	modelMatrix = glm::mat4(1);
	modelMatrix *= Transform3D::Translate(0.0f, 0.5f, -1.5f);
	modelMatrix *= Transform3D::Scale(scaleX, scaleY, scaleZ);
	RenderMesh(meshes["box"], shaders["Simple"], modelMatrix);

	modelMatrix = glm::mat4(1);
	modelMatrix *= Transform3D::Translate(2.5f, 0.5f, -1.5f);
	modelMatrix *= Transform3D::RotateOX(angularStepOX);
	modelMatrix *= Transform3D::RotateOY(angularStepOY);
	modelMatrix *= Transform3D::RotateOZ(angularStepOZ);
	RenderMesh(meshes["box"], shaders["VertexNormal"], modelMatrix);

	modelMatrix = glm::mat4(1);
	//centru e la x-5
	if(angular < 3.14)
		angular += 2 * deltaTimeSeconds;
	if (angular > 3.14) {
		angular = 0;
		saritura ++;
	}

	modelMatrix *= Transform3D::Translate(-20.0f, 0.5f, 0.0f);
	modelMatrix *= Transform3D::Translate(10 * saritura, 0, 0) * Transform3D::RotateOZ(-angular) * Transform3D::Translate(-5, 0, 0);
	RenderMesh(meshes["box"], shaders["VertexNormal"], modelMatrix);
}

void Laborator4::FrameEnd()
{
	DrawCoordinatSystem();
}

void Laborator4::OnInputUpdate(float deltaTime, int mods)
{
	//Rotate
	if (window->KeyHold(GLFW_KEY_3))
	{
		angularStepOX += rSpeed * deltaTime;
	}
	if (window->KeyHold(GLFW_KEY_4))
	{
		angularStepOX -= rSpeed * deltaTime;
	}
	if (window->KeyHold(GLFW_KEY_5))
	{
		angularStepOY += rSpeed * deltaTime;
	}
	if (window->KeyHold(GLFW_KEY_6))
	{
		angularStepOY -= rSpeed * deltaTime;
	}
	if (window->KeyHold(GLFW_KEY_7))
	{
		angularStepOZ += rSpeed * deltaTime;
	}
	if (window->KeyHold(GLFW_KEY_8))
	{
		angularStepOZ -= rSpeed * deltaTime;
	}
}

void Laborator4::OnKeyPress(int key, int mods)
{
	// add key press event
	if (key == GLFW_KEY_SPACE)
	{
		switch (polygonMode)
		{
		case GL_POINT:
			polygonMode = GL_FILL;
			break;
		case GL_LINE:
			polygonMode = GL_POINT;
			break;
		default:
			polygonMode = GL_LINE;
			break;
		}
	}
}

void Laborator4::OnKeyRelease(int key, int mods)
{
	// add key release event
}

void Laborator4::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	// add mouse move event
}

void Laborator4::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button press event
}

void Laborator4::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button release event
}

void Laborator4::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Laborator4::OnWindowResize(int width, int height)
{
}
