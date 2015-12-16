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
    int total_runs;
    std::ofstream myfile;
    myfile.open ("example.txt");
    std::ifstream read;
    read.open("a.txt");
    std::string dummy;
    std::getline(read,dummy);
    total_runs = atoi(dummy.c_str());
    for (int i = 1; i <= total_runs; i++) {
        std::getline(read,dummy);
        std::getline(read,dummy);
        std::vector<std::string> a = string_split(dummy, ' ');
        std::vector<long> one;
        for (auto x: a){
            one.push_back(atoi(x.c_str()));
        }
        std::getline(read,dummy);
        std::vector<std::string> b = string_split(dummy, ' ');
        std::vector<long> two;
        for (auto x: b){
            two.push_back(atoi(x.c_str()));
        }
        sort(one.begin(),one.end());
        sort(two.begin(),two.end(),std::greater<long>());
        unsigned int index = 0;
        long ans = 0;
        for ( auto x:one){
            x = 0;
            ans = ans +one[index]*two[index];
            index++;
        }
        myfile <<"Case #" <<i  <<": " << ans << std::endl;
    }
    return 0;
}

