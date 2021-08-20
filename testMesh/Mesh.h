#pragma once
#include <vector>
#include <string>

class Mesh
{
public:
	float* normals;
	int* lines;
	std::vector <std::vector<float>> vertices;
	std::vector <std::vector<float>> colors;
	std::vector <std::vector<int>> faces;
	std::vector <std::vector<float>> uvs;
	Mesh(std::vector <std::vector<std::string>>* vertices_list, std::vector <std::vector<std::string>>* uvs_list, std::vector <std::vector <int>>* triangles_list,
		std::vector <std::vector<std::string>>* normals_list = NULL, std::vector <std::vector<std::string>>* lines_list = NULL);
	~Mesh();
};