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
    
    
    
    for (int o = 1; o <= total_runs; o++) {
        double total_cookies;
        double production = 2;
        double addtional;
        double total_required;
        double time;
        time = 0;
        std::string dummy1;
        std::getline(read,dummy1);
//        std::cout << dummy1 << " ";
        std::vector<std::string> dummy2 = string_split(dummy1, ' ');
//        std::cout << dummy2[0];
        total_cookies = atof(dummy2[0].c_str());
        addtional = atof(dummy2[1].c_str());
        total_required = atof(dummy2[2].c_str());
//        std::cout << total_cookies << " " << addtional << " " << total_required << std::endl;
        while (true) {
            double one = total_required/production;
            double three = total_cookies/production;
            double two = total_cookies/production;
            production = production + addtional;
            two = two + total_required/production;
            if (one< two) {
                time = time + one;
                break;
            }else {
                time = time + three;
            }
        }
        myfile.setf(7);
        std::cout << "Case #" <<o <<": "<< time << std::endl;
    }
    return 0;
}

