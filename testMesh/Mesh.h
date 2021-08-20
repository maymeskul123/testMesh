#pragma once
#include <vector>
#include <string>

class Mesh
{
public:
	float* normals;
	int* lines;
	float* vertices;
	float* colors;
	int* faces;
	float* uvs;
	Mesh(std::vector <std::string>* vertices_list, std::vector <std::string>* uvs_list, std::vector <std::vector <int>>* triangles,
		std::vector <std::string>* normals, std::vector <std::string>* lines);
	~Mesh();
};