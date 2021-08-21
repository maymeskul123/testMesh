#include "Mesh.h"
#include <string>
#include <vector>
#include "windows.h"
//#include <algorithm>
#include <iostream>
#include <fstream>

#define _CRT_SECURE_NO_WARNINGS

Mesh::Mesh(std::vector<std::vector<std::string>>* vertices_list, std::vector<std::vector<std::string>>* uvs_list, std::vector <std::vector <std::vector <int>>>* triangles_list,
	std::vector<std::vector<std::string>>* normals_list, std::vector<std::vector<std::string>>* lines_list)
{	
	std::vector<float> temp;
	for (auto val : vertices_list[0])
	{		
		for (auto el : val)
		{			
			temp.push_back(std::stof(el));
		}
		vertices.push_back(temp);
		temp.clear();
	}
	
	for (auto vert : vertices)
	{			
		if (vert.size() > 3)
		{
			for (int i = 3; i < vert.size(); i++)
			{
				temp.push_back(vert[i]);
			}
			colors.push_back(temp);
			temp.clear();
		}
		else
		{
			colors.push_back(temp);
		}
	}
	for (int i = 0; i < vertices.size(); i++)
	{
		vertices[i].erase(vertices[i].begin() + 3, vertices[i].end());
	}	
	
	std::vector<int> temp_int;
	std::vector <std::vector <int>> temp_int_all;
	for (auto lst_el : triangles_list[0])
	{		
		for (auto elmts : lst_el)
		{			
			for (auto el : elmts)
			{
				temp_int.push_back(el);
			}
			temp_int_all.push_back(temp_int);
			temp_int.clear();
		}
		faces.push_back(temp_int_all);
		temp_int_all.clear();
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

void Mesh::Write_obj(std::string path)
{	
	/*std::ofstream out;
	out.open(path);*/
	FILE* fp;
	if ((fp = fopen(path.c_str(), "w")) == NULL) {
		printf("Cannot open file.\n");
		exit(1);
	}

	if (colors.size() > 0)
	{		
		for (long i = 0; i < vertices.size(); i++)
		{
			auto v = vertices[i];	//write vertices with colors
			auto x = v[0];
			auto y = v[1];
			auto z = v[2];
			auto c = colors[i];
			auto r = c[0];
			auto g = c[1];
			auto b = c[2];
			fprintf(fp, "v %.8f %.8f %.8f %.8f %.8f %.8f\n", x, y, z, r, g, b);
		}
	}
	else
	{
		for (auto vert : vertices) //write vertices without colors
		{			
			auto x = vert[0];
			auto y = vert[1];
			auto z = vert[2];
			fprintf(fp, "v %.8f %.8f %.8f\n", x, y, z);			
		}
	}

	for (auto uv : uvs) //write uvs
	{		
		auto u = uv[0];
		auto v = uv[1];		
		fprintf(fp, "vt %.8f %.8f\n", u, v);
	}

	for (auto nor : normals) //write normals
	{
		auto x = nor[0];
		auto y = nor[1];
		auto z = nor[2];
		fprintf(fp, "vn %.8f %.8f %.8f\n", x, y, z);
	}

	for (auto fac : faces) //write faces
	{
		fprintf(fp, "f");
		for (auto one_fac : fac)
		{
			fprintf(fp, " ");
			int i = 0;
			for (auto one: one_fac)
			{
				if (one > -1)
				{
					fprintf(fp, "%d", one + 1);
					if (i != one_fac.size() - 1)
					{
						fprintf(fp, "/");
					}					
				}
				i++;
			}
		}
		fprintf(fp, "\n");
	}
	//out.close();
	fclose(fp);
}