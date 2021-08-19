#pragma once
#include <vector>
#include <string>

class Load_obj_real
{
private:
	std::vector <std::string> vertices_list;
	std::vector <std::string> normals_list;
	std::vector <std::string> uv_list;
	std::vector <std::string> triangles_list;
	std::vector <std::string> lines_list;

public:	
	void Save_list(std::vector<std::string>* , std::string*);
	Load_obj_real(std::string);
	~Load_obj_real();
};