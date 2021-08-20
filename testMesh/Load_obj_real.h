#pragma once
#include <vector>
#include <string>

class Load_obj_real
{
public:
	std::vector <std::string> vertices_list;
	std::vector <std::string> normals_list;
	std::vector <std::string> uv_list;
	std::vector <std::vector <int>> triangles_list;
	std::vector <std::string> lines_list;

	void Save_list(std::vector<std::string>* , std::string*);
	void Save_list_f(std::vector<std::vector<int>>*, std::string*);
	Load_obj_real(std::string);
	~Load_obj_real();
};