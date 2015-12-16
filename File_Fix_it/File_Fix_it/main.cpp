//
//  main.cpp
//  File_Fix_it
//
//  Created by Anas Saeed on 25/05/2014.
//  Copyright (c) 2014 Anas Saeed. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
std::vector<std::string> directories;
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
std::vector<std::string> string_split123(std::string input, char breaker);
std::vector<std::string> string_split123(std::string input, char breaker){
    std::vector<std::string> output;
    std::string result;
    int count = 0;
    for(auto x :input){
        if (x == breaker && count!= 0) {
            output.push_back(result);
            continue;
        }
        count++;
        result = result + x;
    }
    output.push_back(result);
    return output;
}
bool present(std::string input);
bool present(std::string input){
    for ( auto x: directories){
        if (x == input) {
            return true;
        }
    }
    directories.push_back(input);
    return false;
}
int main(int argc, const char * argv[])
{
    std::ofstream myfile;
    myfile.open ("example.txt");
    std::ifstream read;
    read.open("a.txt");
    std::string num1;
    std::getline(read, num1);
    int num = atoi(num1.c_str());
    for (int i = 1; i != num+1 ; i++) {
        int count = 0;
        directories = {};
        int done,todo;
        std::string dummy;
        std::getline(read,dummy);
        std::vector<std::string> abc = string_split(dummy, ' ');
        done = atoi(abc[0].c_str());
        todo = atoi(abc[1].c_str());
        for (int  j = 0; j < done; j++) {
            std::getline(read,dummy);
            std::vector<std::string> c = string_split123(dummy, '/');
            for ( auto x: c){
                directories.push_back(x);
            }
        }
        for (int j = 0; j < todo; j++) {
            std::getline(read, dummy);
            std::vector<std::string> c1 = string_split123(dummy, '/');
            for (auto x: c1){
                bool check = present(x);
                if (check == false) {
                    count++;
                }
            }
            
        }
        myfile << "Case #"<<i << ": " << count<< std::endl;
        std::cout  << "Case #"<<i << ": " << count << std::endl;
        directories ={};
    }
    return 0;
}

