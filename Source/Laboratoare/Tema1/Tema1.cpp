#include "Header.h"
#include <vector>
#include <queue>
#include <iostream>
#include <Core/Engine.h>
#include "Transformari2D.h"
#include "Obiecte2D.h"
#include "Tema1.h"
using namespace std;

Tema1::Tema1() {

}

Tema1::~Tema1() {

}

void Tema1::MakePipe(int transX, int transY, int scaleX, int scaleY){
	//construieste meshul pentru obstacole
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transformari2D::Translate(transX, transY);
	modelMatrix *= Transformari2D::Scale(scaleX, scaleY);
	RenderMesh2D(meshes["Pipe"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transformari2D::Translate(transX-20, transY+scaleY);
	modelMatrix *= Transformari2D::Scale(scaleX + 40, 20);
	RenderMesh2D(meshes["Pipe"], shaders["VertexColor"], modelMatrix);
}

void Tema1::MakePipeRosu(int transX, int transY, int scaleX, int scaleY) {
	//obstacole rosii
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transformari2D::Translate(transX - 20, transY + scaleY);
	modelMatrix *= Transformari2D::Scale(scaleX + 40, 20);
	RenderMesh2D(meshes["PipeAlbastru"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transformari2D::Translate(transX, transY);
	modelMatrix *= Transformari2D::Scale(scaleX, scaleY);
	RenderMesh2D(meshes["PipeRosu"], shaders["VertexColor"], modelMatrix);
}

void Tema1::MakePipeAlbastru(int transX, int transY, int scaleX, int scaleY) {
	//obstacole albastre
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transformari2D::Translate(transX - 20, transY + scaleY);
	modelMatrix *= Transformari2D::Scale(scaleX + 40, 20);
	RenderMesh2D(meshes["PipeRosu"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transformari2D::Translate(transX, transY);
	modelMatrix *= Transformari2D::Scale(scaleX, scaleY);
	RenderMesh2D(meshes["PipeAlbastru"], shaders["VertexColor"], modelMatrix);
}

void Tema1::MakeBirb(int transX, int transY, float angularStep) {
	//mesh pt ochi
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transformari2D::Translate(275, transY + 5);
	modelMatrix *= Transformari2D::Translate(-35, -5) * Transformari2D::Rotate(angularStep) * Transformari2D::Translate(35, 5);
	modelMatrix *= Transformari2D::Scale(5, 5);
	RenderMesh2D(meshes["eye"], shaders["VertexColor"], modelMatrix);

	//corp - fac rotatie in functie de centrul acestui colp
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transformari2D::Translate(240, transY);
	modelMatrix *= Transformari2D::Scale(25, 25);
	RenderMesh2D(meshes["body"], shaders["VertexColor"], modelMatrix);

	//mesh pt cap
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transformari2D::Translate(270, transY);
	modelMatrix *= Transformari2D::Translate(-30, 0) * Transformari2D::Rotate(angularStep) * Transformari2D::Translate(30, 0);
	modelMatrix *= Transformari2D::Scale(20, 20);
	RenderMesh2D(meshes["body"], shaders["VertexColor"], modelMatrix);

	//mesh pt cioc
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transformari2D::Translate(280, transY);
	modelMatrix *= Transformari2D::Translate(-40, 0) * Transformari2D::Rotate(angularStep) * Transformari2D::Translate(40, 0);
	modelMatrix *= Transformari2D::Scale(30, 30);
	RenderMesh2D(meshes["beak"], shaders["VertexColor"], modelMatrix);

	//mesh pt coada
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transformari2D::Translate(195, transY);
	modelMatrix *= Transformari2D::Translate(45, 0) * Transformari2D::Rotate(angularStep) * Transformari2D::Translate(-45, 0);
	modelMatrix *= Transformari2D::Scale(30, 30);
	RenderMesh2D(meshes["beak"], shaders["VertexColor"], modelMatrix);


	//mesh pt aripa
	int wingTrans = 15;
	int wingScale = 30;
	if (angularStep > 0) {
		wingScale = -wingScale;
		wingTrans = -wingTrans;
	}
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transformari2D::Translate(240, transY + wingTrans);
	modelMatrix *= Transformari2D::Translate(0, -wingTrans) * Transformari2D::Rotate(angularStep) * Transformari2D::Translate(0, wingTrans);
	modelMatrix *= Transformari2D::Scale(wingScale, wingScale);
	RenderMesh2D(meshes["Wing"], shaders["VertexColor"], modelMatrix);
	/*End render bird*/
}

void Tema1::MakeBackground(){
	//desenez primul nor
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transformari2D::Translate(900, 600);
	modelMatrix *= Transformari2D::Scale(40, 30);
	RenderMesh2D(meshes["cloud"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transformari2D::Translate(970, 590);
	modelMatrix *= Transformari2D::Scale(35, 25);
	RenderMesh2D(meshes["cloud"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transformari2D::Translate(850, 600);
	modelMatrix *= Transformari2D::Scale(30, 25);
	RenderMesh2D(meshes["cloud"], shaders["VertexColor"], modelMatrix);
	//desenez al doilea nor
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transformari2D::Translate(600, 650);
	modelMatrix *= Transformari2D::Scale(40, 30);
	RenderMesh2D(meshes["cloud"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transformari2D::Translate(670, 640);
	modelMatrix *= Transformari2D::Scale(35, 25);
	RenderMesh2D(meshes["cloud"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transformari2D::Translate(550, 650);
	modelMatrix *= Transformari2D::Scale(30, 25);
	RenderMesh2D(meshes["cloud"], shaders["VertexColor"], modelMatrix);
	//desenez soarele
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transformari2D::Translate(1280, 720);
	modelMatrix *= Transformari2D::Scale(100, 100);
	RenderMesh2D(meshes["sun"], shaders["VertexColor"], modelMatrix);
}

void Tema1::Init() {
	glm::ivec2 resolution = window->GetResolution();
	auto camera = GetSceneCamera();
	camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
	camera->SetPosition(glm::vec3(0, 0, 50));
	camera->SetRotation(glm::vec3(0, 0, 0));
	camera->Update();
	GetCameraInput()->SetActive(false);
	//pana aici seteaza camera

	Mesh* obstacle = Obiecte2D::CreateSquare("obstacle", glm::vec3(0, 1, 0));
	AddMeshToList(obstacle);

	Mesh* body = Obiecte2D::CreateCircle("body", glm::vec3(0, 0.5, 0));
	AddMeshToList(body);

	Mesh* eye = Obiecte2D::CreateCircle("eye", glm::vec3(0, 0, 0));
	AddMeshToList(eye);

	Mesh* beak = Obiecte2D::CreateTriangle("beak", glm::vec3(1, 0, 0));
	AddMeshToList(beak);
	
	Mesh* Wing = Obiecte2D::CreateWing("Wing", glm::vec3(1, 0, 0));
	AddMeshToList(Wing);

	Mesh* Pipe = Obiecte2D::CreateSquare("Pipe", glm::vec3(0, 1, 0));
	AddMeshToList(Pipe);

	Mesh* PipeRosu = Obiecte2D::CreateSquare("PipeRosu", glm::vec3(1, 0, 0));
	AddMeshToList(PipeRosu);

	Mesh* PipeAlbastru = Obiecte2D::CreateSquare("PipeAlbastru", glm::vec3(0, 0, 1));
	AddMeshToList(PipeAlbastru);

	Mesh* sun = Obiecte2D::CreateCircle("sun", glm::vec3(1, 1, 0.5));
	AddMeshToList(sun);

	Mesh* cloud = Obiecte2D::CreateCircle("cloud", glm::vec3(1, 1, 1));
	AddMeshToList(cloud);
	//Construiesc meshurile necesare

	//var pt pasare
	transY = 500;
	direction_up = false;
	limit = 0;
	speed = 500;

	//var pt scor si endgame
	score = 0;
	pass = false;
	endgame = false;

	//var pt dreptungiuri
	distSectiuni = 320;
	transX = 1280;
	sectiuni.assign(10, 100);
	scaleLimit = 200;
	closing = true;
}

void Tema1::glisarePipe(int at, int i, int closeLim, int apartLim){
	//glisarea obstacolelor, schimb scalarea pentru a le schimba distanta dintre 2 obstacole
	if (closing == true) {
		if (sectiuni.at(at) + sectiuni.at(at+1) + 100 <= closeLim) {
			sectiuni.at(at) += i;
			sectiuni.at(at+1) += i;
		}
		else {
			closing = false;
		}
	}
	else {
		if (sectiuni.at(at) + sectiuni.at(at+1) + 100 > apartLim) {
			sectiuni.at(at) -= i;
			sectiuni.at(at+1) -= i;
		}
		else {
			closing = true;
		}
	}
}

void Tema1::FrameStart() {
	//setez o culoare ambientala de fundal
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glm::ivec2 resolution = window->GetResolution();
	glViewport(0, 0, resolution.x, resolution.y);
}

void Tema1::Update(float deltaTimeSeconds) {
	glm::ivec2 resolution = window->GetResolution();

	glClearColor(0, 0.75, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (endgame != true) {
		//verificare pentru miscarea pasarii pe Ox si rotatia ei
		if (direction_up == true) {
			if (transY < 720) {
				if (transY < limit) {
					transY += speed * deltaTimeSeconds;
					if (angularStep < 0.5)
						angularStep += 0.25;
				}
				else {
					direction_up = false;
					if (angularStep > -0.5)
						angularStep -= 0.25;
				}
			}
			else {
				transY = 720;
				direction_up = false;
				if (angularStep > -0.5)
					angularStep -= 0.25;
			}
		}
		else {
			if (angularStep > -0.5)
				angularStep -= 0.25;
			transY -= 200 * deltaTimeSeconds;
		}
		//daca trece de limita de jos trebuie terminat jocul
		if (transY <= 0) {
			endgame = true;
			printf("You lost!	Final Score: %d\n", score);
		}

		//fac translatia dreptungiurilor
		transX -= 300 * deltaTimeSeconds + (score/5);
		if (transX < -100) {
			transX += distSectiuni;

			sectiuni.erase(sectiuni.begin());
			sectiuni.erase(sectiuni.begin());

			x1 = rand() % 250 + 100;
			sectiuni.push_back(x1);
			x2 = rand() % 250 + 50;
			sectiuni.push_back(x2);
		}

		if (x1 != 0 && x2 != 0) {
			glisarePipe(2, 2, x1 + x2 + 100, x1 + x2);
		}

		//coliziune
		if (transX <= 310 && transX >= 65) {
			if (transY >= 695 - sectiuni.at(0)) {
				pass = false;
				endgame = true;
				printf("You lost!	Final Score: %d\n", score);
			}
			else if (transY <= sectiuni.at(1) + 25) {
				pass = false;
				endgame = true;
				printf("You lost!	Final Score: %d\n", score);
			}
			else {
				pass = true;
			}
		}

		if (endgame == false && transX < 65 && pass == true) {
			pass = false;
			score++;
			printf("Score: %d\n", score);
		}

		//la inceput oferim playerului putin timp de ragaz

		MakePipeAlbastru(transX + distSectiuni * 0, 0, 100, sectiuni.at(1));
		MakePipe(transX + distSectiuni * 0, 720, 100, -sectiuni.at(0));

		MakePipeRosu(transX + distSectiuni * 1, 0, 100, sectiuni.at(3));
		MakePipe(transX + distSectiuni * 1, 720, 100, -sectiuni.at(2));
		
		MakePipeRosu(transX + distSectiuni * 2, 720, 100, -sectiuni.at(4));
		MakePipe(transX + distSectiuni * 2, 0, 100, sectiuni.at(5));

		MakePipeAlbastru(transX + distSectiuni * 3, 0, 100, sectiuni.at(7));
		MakePipeRosu(transX + distSectiuni * 3, 720, 100, -sectiuni.at(6));

		MakePipeAlbastru(transX + distSectiuni * 4, 720, 100, -sectiuni.at(8));
		MakePipe(transX + distSectiuni * 4, 0, 100, sectiuni.at(9));

		MakeBirb(transX, transY, angularStep);

		MakeBackground();
	}	
}

void Tema1::FrameEnd() {

}

void Tema1::OnInputUpdate(float deltaTime, int mods) {
	
}

void Tema1::OnKeyRelease(int key, int mods) {

}
void Tema1::OnKeyPress(int key, int mods) {
	if (key == GLFW_KEY_SPACE) {
		limit = transY + 55;
		speed = 140;
		direction_up = true;
	}
}

void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) {
}

void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) {
}

void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) {
}

void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) {
}

void Tema1::OnWindowResize(int width, int height) {
}