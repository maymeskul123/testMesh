#include "Load_obj_real.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

void Load_obj_real::Save_list(std::vector<std::string> *vector_list, std::string *filesLine)
{
    std::stringstream sub2(filesLine->substr(0, filesLine->length() - 1));
    //std::stringstream test(sub2);
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
                found = "found v";
                Save_list(&vertices_list, &line);
            }
            if (sub1.compare ("f ") == 0)
            {
                found = "found f";
                //Save_list(&vertices_list, &line);
            }
            if (sub1.compare("vt") == 0)
            {
                found = "found vt";
                Save_list(&uv_list, &line);
                /*std::string sub2 = line.substr(2, line.length() - 1);
                std::stringstream test(sub2);
                std::string segment;

                while (std::getline(test, segment, ' '))
                {
                    uv_list.push_back(segment);
                }*/
            }
            if (sub1.compare("vn") == 0)
            {
                found = "found vn";
                Save_list(&normals_list, &line);
                /*std::string sub2 = line.substr(2, line.length() - 1);
                std::stringstream test(sub2);
                std::string segment;

                while (std::getline(test, segment, ' '))
                {
                    normals_list.push_back(segment);
                }*/
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
