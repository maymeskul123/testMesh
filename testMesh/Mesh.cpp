#include "Mesh.h"
#include <string>
#include <vector>

Mesh::Mesh(std::vector<std::string>* vertices_list, std::vector<std::string>* uvs_list, std::vector<std::vector<int>>* triangles,
	std::vector<std::string>* normals = NULL, std::vector<std::string>* lines = NULL)
{
	vertices = new float [vertices_list->size()];
	uvs = new float[uvs_list->size()];

}

Mesh::~Mesh()
{
}
