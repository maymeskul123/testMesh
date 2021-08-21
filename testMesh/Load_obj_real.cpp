#include "Load_obj_real.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

void Load_obj_real::Save_list(std::vector <std::vector<std::string>> *vector_list, std::string *filesLine)
{
    std::stringstream sub2(filesLine->substr(0, filesLine->length() - 1));    
    std::string segment;
    bool first = true;
    std::vector <std::string> temp_str;
    while (std::getline(sub2, segment, ' '))
    {
        if (first)
        {
            first = false;       
        }
        else
        {
            temp_str.push_back(segment);
        }
    }
    vector_list->push_back(temp_str);
}

void Load_obj_real::Save_list_f(std::vector<std::vector <std::vector <int>>>*, std::string *filesLine)
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
    std::vector <std::vector<std::string>> temp3;
    std::vector <int> temp_int;
    
    for (std::string elem : temp)
    {
        std::stringstream sub2(elem.substr(0, elem.length()));
        while (std::getline(sub2, segment, '/'))
        {
            temp2.push_back(segment); 
        }
        temp3.push_back(temp2);         //[[1,1,1], [2,2,2],[3,3,3]] in strings
        temp2.clear();
    }
    std::vector <std::vector<int>> temp_int_all;
    for (auto element : temp3)
    {            
        for (auto el : element)
        {
            temp_int.push_back(std::stoi(el) - 1);
        }
        temp_int_all.push_back(temp_int);
        temp_int.clear();
    }
    triangles_list.push_back(temp_int_all);
    temp_int_all.clear();
}

Load_obj_real::Load_obj_real(std::string path)
{    
    //Op_file(path);

    std::string line;
    std::ifstream in(path); // open file
    
    if (in.is_open())
    {
        while (getline(in, line))
        {            
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
        }
    }
    in.close();     // close file
    
}

Load_obj_real::~Load_obj_real()
{
}

//void Load_obj_real::Op_file(std::string path)
//{    
//    FILE* file_;
//    char c;
//    unsigned int i = 0;
//    file_ = fopen(path.c_str(), "r");
//    while (1) {
//        c = fgetc(file_);
//        buf[i] = c;
//        printf("%d %c\n", i, buf[i]);
//        
//        if (feof(file_)) {
//            break;
//        }
//        i++;
//        //printf("%c", c);
//    }
//
//    ////std::ifstream in(path);
//    //std::fstream in(path);    
//
//
//    //int i = 0;
//    //if (in.is_open())
//    //{
//    //    while (getline(in, line))
//    //    {
//    //        i++;
//    //        //std::cout << line;
//    //        //buffer_str.push_back(line);
//    //    }
//    //}
//    //in.close();
//    // Close stream if it isn't NULL
//    fclose(file_);
//}
