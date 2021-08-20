#include "Mesh.h"
#include <string>
#include <vector>
#include "windows.h"
//#include <algorithm>

Mesh::Mesh(std::vector<std::vector<std::string>>* vertices_list, std::vector<std::vector<std::string>>* uvs_list, std::vector<std::vector<int>>* triangles_list,
	std::vector<std::vector<std::string>>* normals_list, std::vector<std::vector<std::string>>* lines_list)
{	
	std::vector<float> temp;
	for (auto val : vertices_list[0])
	{		
		for (auto el : val)
		{
			/*char s[100];
			sprintf(s, "%d \n", el);
			OutputDebugStringA(s);*/
			//std::string line = "bla";
			//OutputDebugStringA(el.c_str());
			temp.push_back(std::stof(el));
		}
		vertices.push_back(temp);
		temp.clear();
	}

	if (vertices[1].size() > 3)
	{
		for (auto vert : vertices)
		{			
			for (int i = 3; i < vert.size(); i++)
			{
				temp.push_back(vert[i]);				
			}			
			colors.push_back(temp);
			temp.clear();
		}
		for (int i = 0; i < vertices.size(); i++)
		{
			vertices[i].erase(vertices[i].begin() + 3, vertices[i].end());
		}
	}
	
	std::vector<int> temp_int;
	for (auto val : triangles_list[0])
	{		
		for (auto el : val)
		{			
			temp_int.push_back(el);			
		}
		faces.push_back(temp_int);
		temp_int.clear();
	}

	for (auto val : uvs_list[0])
	{		
		for (auto el : val)
		{
			temp.push_back(std::stof(el));
		}
		uvs.push_back(temp);
		temp.clear();
	}
	/*char s[100];
	sprintf(s, "Size %d \n", (int)vertices_list->size());
	OutputDebugStringA(s);*/	
	//colors = new float [6];
}

Mesh::~Mesh()
{
}
