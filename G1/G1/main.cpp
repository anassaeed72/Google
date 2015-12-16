//
//  main.cpp
//  G1
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
int main(int argc, const char * argv[])
{
    std::ofstream myfile;
    myfile.open ("example.txt");
    std::ifstream read;
    read.open("a.txt");
    std::string num1;
    std::getline(read, num1);
    int one,two;
    int num = atoi(num1.c_str());
    for (int i = 1; i != num +1; i++) {
        int credit;
        int items;
        std::vector<int> values;
        std::string dummy;
        std::getline(read,dummy);
        credit = atoi(dummy.c_str());
        std::getline(read, dummy);
        items = atoi(dummy.c_str());
        std::getline(read,dummy);
        std::vector<std::string> temp = string_split(dummy, ' ');
        for ( auto x : temp){
            values.push_back(atoi(x.c_str()));
        }
        for (int j = 0; j < items; j++) {
            for (int k = j+1; k < items; k++) {
                if ((values[j] + values[k]) == credit) {
                    one = j;
                    two = k;
                    break;
                }
            }
        }
        myfile << "Case #" << i << ": " << one+1 << " " << two+1 << std::endl;
        std::cout  << "Case #" << i << ": " << one+1 << " " << two+1 << std::endl;

    }
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

