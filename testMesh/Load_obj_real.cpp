#include "Load_obj_real.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

void Load_obj_real::Save_list(std::vector<std::string> *vector_list, std::string *filesLine)
{
    std::stringstream sub2(filesLine->substr(0, filesLine->length() - 1));    
    std::string segment;
    bool first = true;
    while (std::getline(sub2, segment, ' '))
    {
        if (first)
        {
            first = false;       
        }
        else
        {
            vector_list->push_back(segment);
        }
    }
}

void Load_obj_real::Save_list_f(std::vector<std::vector<int>>*, std::string *filesLine)
{
    std::stringstream sub2(filesLine->substr(0, filesLine->length()));
    std::string segment;
    bool first = true;
    std::vector <std::string> temp;
    while (std::getline(sub2, segment, ' '))
    {
        if (first)
        {
            first = false;
        }
        else
        {
            temp.push_back(segment);
        }
    }

    std::vector <std::string> temp2;
    std::vector <int> temp_int;
    for (std::string elem : temp)
    {
        std::stringstream sub2(elem.substr(0, elem.length()));
        while (std::getline(sub2, segment, '/'))
        {
            temp2.push_back(segment);
        }
    }
    for (auto& element : temp2)
    {            
        temp_int.push_back(std::stoi(element) - 1);
    }
    triangles_list.push_back(temp_int);
}

Load_obj_real::Load_obj_real(std::string path)
{
	std::string line;
    std::ifstream in(path); // окрываем файл для чтения
    if (in.is_open())
    {
        while (getline(in, line))
        {
            std::string found = "Not found";
            std::string sub1 = line.substr(0, 2);

            if (sub1.compare("v ") == 0)
            {                
                Save_list(&vertices_list, &line);
            }
            if (sub1.compare ("f ") == 0)
            {
                Save_list_f(&triangles_list, &line);
            }
            if (sub1.compare("vt") == 0)
            {                
                Save_list(&uv_list, &line);                
            }
            if (sub1.compare("vn") == 0)
            {                
                Save_list(&normals_list, &line);
            }

            //std::cout << found << std::endl;
        }
    }
    in.close();     // закрываем файл

    std::cout << "End of program" << std::endl;
}

Load_obj_real::~Load_obj_real()
{
}
