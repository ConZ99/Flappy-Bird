#pragma once

#include <Component/SimpleScene.h>
#include <string>
#include <Core/Engine.h>
#include <vector>

class Tema1 : public SimpleScene
{
public:
	Tema1();
	~Tema1();

	void Init() override;

private:

	void FrameStart() override;
	void Update(float deltaTimeSeconds) override;
	void FrameEnd() override;

	void glisarePipe(int at, int i, int closeLim, int apartLim);
	void MakePipe(int transX, int transY, int scaleX, int scaleY);
	void MakePipeRosu(int transX, int transY, int scaleX, int scaleY);
	void MakePipeAlbastru(int transX, int transY, int scaleX, int scaleY);
	void MakeBirb(int transX, int transY, float angularStep);
	void MakeBackground();

	void OnInputUpdate(float deltaTime, int mods) override;
	void OnKeyPress(int key, int mods) override;
	void OnKeyRelease(int key, int mods) override;
	void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
	void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
	void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
	void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
	void OnWindowResize(int width, int height) override;
	std::vector<int> sectiuni;
	std::vector<int>::iterator it;
protected:
	
	glm::mat3 modelMatrix;
	float scaleX, scaleY, angularStep;
	int transY, transX, distSectiuni, limit, score, speed, scaleLimit;
	int x1, x2, x3;
	bool direction_up, endgame, closing, pass;
};
#pragma once
