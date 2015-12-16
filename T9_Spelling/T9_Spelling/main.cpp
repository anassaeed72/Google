//
//  main.cpp
//  T9_Spelling
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
std::string one(char i);
std::string one(char input){
    if (input =='a') {
        return "2";
    }
    if (input =='b') {
        return "22";
    }
    if (input =='c') {
        return "222";
    }
    if (input =='d') {
        return "3";
    }
    if (input =='e') {
        return "33";
    }
    if (input =='f') {
        return "333";
    }
    if (input =='g') {
        return "4";
    }
    if (input =='h') {
        return "44";
    }
    if (input =='i') {
        return "444";
    }
    if (input =='j') {
        return "5";
    }
    if (input =='k') {
        return "55";
    }
    if (input =='l') {
        return "555";
    }
    if (input =='m') {
        return "6";
    }
    if (input =='n') {
        return "66";
    }
    if (input =='o') {
        return "666";
    }
    if (input =='p') {
        return "7";
    }
    if (input =='q') {
        return "77";
    }
    if (input =='r') {
        return "777";
    }
    if (input =='s') {
        return "7777";
    }
    if (input =='t') {
        return "8";
    }
    if (input =='u') {
        return "88";
    }
    if (input =='v') {
        return "888";
    }
    if (input =='w') {
        return "9";
    }
    if (input =='x') {
        return "99";
    }
    if (input =='y') {
        return "999";
    }
    if (input ==' ') {
        return "0";
    }
    
    return "9999";
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
        std::string output;
        int count = 0;
        for ( auto x : temp){
            std::string dummy = one(x);
            if (count != 0) {
                if (output[output.length()-1] == dummy[0]) {
                    output = output + " ";
                }
            }
            output = output + dummy;
            count++;
        }
        myfile << "Case #" << i <<": " << output << std::endl;
        std::cout << output << std::endl;
    }
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

