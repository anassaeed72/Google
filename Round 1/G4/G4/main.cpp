//
//  main.cpp
//  Google_2
//
//  Created by Anas Saeed on 12/04/2014.
//  Copyright (c) 2014 Anas Saeed. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <algorithm>
std::vector<std::string> string_split(std::string input, char breaker);
std::vector<std::string> string_split(std::string input, char breaker){
    std::vector<std::string> output;
    unsigned int vec_size = 0;
    std::string result;
    for(auto x :input){
        if (x == breaker) {
            std::string intial = "";
            output.push_back(result);
            result = "";
            continue;
        }
        result = result + x;
    }
    output.push_back(result);
    return output;
}
int main(int argc, const char * argv[])
{
    double total_runs;
    std::ofstream myfile;
    myfile.open ("example.txt");
    std::ifstream read;
    read.open("a.txt");
    std::string dummy;
    std::getline(read,dummy);
    total_runs = atoi(dummy.c_str());
    
    
    
    myfile << " ";
    return 0;
}

