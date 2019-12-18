#include "Obiecte2D.h"

#include <Core/Engine.h>

Mesh* Obiecte2D::CreatePipe(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill)
{
	glm::vec3 corner = leftBottomCorner;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(corner, color),
		VertexFormat(corner + glm::vec3(10, 0, 0), color),
		VertexFormat(corner + glm::vec3(length, length, 0), color),
		VertexFormat(corner + glm::vec3(0, length, 0), color)
	};

	Mesh* pipe = new Mesh(name);
	std::vector<unsigned short> indices = { 0, 1, 2, 3};

	if (!fill) {
		pipe->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		// draw 2 triangles. Add the remaining 2 indices
		indices.push_back(0);
		indices.push_back(2);
	}

	pipe->InitFromData(vertices, indices);
	return pipe;
}

Mesh* Obiecte2D::CreateSquare(std::string name, glm::vec3 color)
{
	std::vector<VertexFormat> vertices =
	{
		VertexFormat(glm::vec3(0, 0, 0), color),
		VertexFormat(glm::vec3(1, 0, 0), color),
		VertexFormat(glm::vec3(1, 1, 0), color),
		VertexFormat(glm::vec3(0, 1, 0), color)
	};

	Mesh* square = new Mesh(name);
	std::vector<unsigned short> indices = { 0, 1, 2, 3, 0, 2 };

	square->InitFromData(vertices, indices);
	return square;
}


Mesh* Obiecte2D::CreateCircle(std::string name, glm::vec3 color) {

	std::vector<VertexFormat> cerc_vertices{};
	std::vector<unsigned short> cerc_indices{};

	Mesh* circle = new Mesh(name);

	int centru = 0;
	cerc_indices.push_back(centru);
	double radius = 1;
	int index = 1;

	for (int i = 0; i < 360; i++) {
		double heading = i * 3.142 / 180;
		cerc_vertices.push_back(VertexFormat(glm::vec3(cos(heading) * radius, sin(heading) * radius, 0), color));
		cerc_indices.push_back(index);
		index++;
	}
	circle->InitFromData(cerc_vertices, cerc_indices);
	circle->SetDrawMode(GL_TRIANGLE_FAN);
	return circle;
}

Mesh* Obiecte2D::CreateTriangle(std::string name, glm::vec3 color) {

	std::vector<VertexFormat> vertices = 
	{
		VertexFormat(glm::vec3(0, -0.5, 0), color),
		VertexFormat(glm::vec3(1, 0, 0), color),
		VertexFormat(glm::vec3(0, 0.5, 0), color)
	};
	std::vector<unsigned short> indices = {0, 1, 2};

	Mesh* triangle = new Mesh(name);
	triangle->InitFromData(vertices, indices);
	return triangle;
}

Mesh* Obiecte2D::CreateWing(std::string name, glm::vec3 color) {

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(glm::vec3(-0.5, 0, 0), color),
		VertexFormat(glm::vec3(0, 1, 0), color),
		VertexFormat(glm::vec3(0.5, 0, 0), color)
	};
	std::vector<unsigned short> indices = { 0, 2, 1 };

	Mesh* Wing = new Mesh(name);
	Wing->InitFromData(vertices, indices);
	return Wing;
}