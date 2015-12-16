//
//  main.cpp
//  Saving_the_Universe
//
//  Created by Anas Saeed on 26/05/2014.
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
std::vector<std::string> remove(std::vector<std::string> input, std::string removable);
std::vector<std::string> remove(std::vector<std::string> input, std::string removable){
    std::vector<std::string> output;
    int count = 0;
    for ( auto x: input){
        if (x == removable && count ==0) {
            count++;
            continue;
        }
        output.push_back(x);
    }
    return output;
}
std::vector<std::string> add_all_except(std::vector<std::string> input, std::string prohibited);
std::vector<std::string> add_all_except(std::vector<std::string> input, std::string prohibited){
    std::vector<std::string> output;
    bool check = false;
    for ( auto x: input){
        if (x == prohibited && check == false) {
            check = true;
            continue;
        }
        output.push_back(x);
    }
    return  output;
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
        int search_engines_number, queries_number,count = 0;
        std::string dummy;
        std::getline(read,dummy);
        search_engines_number = atoi(dummy.c_str());
        std::vector<std::string> search_engines;
        std::vector<std::string> queries;
        for (int j = 0; j < search_engines_number; j++) {
            std::getline(read,dummy);
            search_engines.push_back(dummy);
        }
        std::getline(read,dummy);
        queries_number = atoi(dummy.c_str());
        for (int j = 0; j < queries_number; j++) {
            std::getline(read,dummy);
            queries.push_back(dummy);
        }
        std::vector<std::string> choices;
        for ( auto x: search_engines){
            choices.push_back(x);
        }
        for ( auto x: queries){
            if (choices.size() == 1 && x == choices[0]) {
                count++;
                choices = add_all_except(search_engines, x);
            }else{
//                std::cout << x << " ";
                choices = remove(choices, x);

            }
        }
        
        myfile << "Case #" << i << ": " << count << std::endl;
        std::cout  << "Case #" << i << ": " << count << std::endl;
    }
    return 0;
}

