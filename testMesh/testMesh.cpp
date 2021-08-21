// testMesh.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include "Load_obj_real.h"
#include "Mesh.h"
#include "stdio.h"
#include <chrono>
#include <vector>





int main(int argc, char* argv[])
{    
    auto start = std::chrono::high_resolution_clock::now();
    Load_obj_real load = Load_obj_real("mesh_fit_visibility_n_15.obj");
    Mesh mesh = Mesh(&load.vertices_list, &load.uv_list, &load.triangles_list);    
    mesh.Write_obj("1111.obj");    
    auto end = std::chrono::high_resolution_clock::now();    
    std::chrono::duration<double> dur_time = end - start;    
    std::cout << dur_time.count() << "s\n" << std::endl;
    std::cin.get();
}