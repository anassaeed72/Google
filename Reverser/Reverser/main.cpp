//
//  main.cpp
//  Reverser
//
//  Created by Anas Saeed on 25/05/2014.
//  Copyright (c) 2014 Anas Saeed. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
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
std::vector<std::string> string_split(std::string input);
std::vector<std::string> string_split(std::string input){
    return string_split(input, ' ');
}

std::string reverse_words(std::string input);
std::string reverse_words(std::string input){
    std::vector<std::string> vec = string_split(input,' ');
    std::vector<std::string> real;
    for (int i = vec.size()-1; i >=0; i--) {
        real.push_back(vec[i]);
    }
    int index = 0;
    std::string output;
    for ( auto x: real){
        index++;
        output = output + x;
        if (index == real.size()) {
            continue;
        }
        output = output + " ";
    }
    return output;
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
    for (int i = 1; i != num +1; i++) {
        std::string temp;
        std::getline(read,temp);
        temp = reverse_words(temp);
        myfile << "Case #" <<i << ": " << temp << std::endl;
        std::cout  << "Case #" <<i << ": " << temp << std::endl;

        
    }
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

