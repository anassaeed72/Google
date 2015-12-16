//
//  main.cpp
//  Shifting
//
//  Created by Anas Saeed on 22/05/2014.
//  Copyright (c) 2014 Anas Saeed. All rights reserved.
//

#include <iostream>
#include <fstream>
char change(char in){
    if (in == ' ') {
        return ' ';
    }
    if (in == 'a') {
        return 'y';
    }
    if (in == 'b') {
        return 'h';
    }
    if (in == 'c') {
        return 'e';
    }
    if (in == 'd') {
        return 's';
    }
    if (in == 'e') {
        return 'o';
    }
    if (in == 'f') {
        return 'c';
    }
    if (in == 'g') {
        return 'v';
    }
    if (in == 'h') {
        return 'x';
    }
    if (in == 'i') {
        return 'd';
    }
    if (in == 'j') {
        return 'u';
    }
    if (in == 'k') {
        return 'i';
    }
    if (in == 'l') {
        return 'g';
    }
    if (in == 'm') {
        return 'l';
    }
    if (in == 'n') {
        return 'b';
    }
    if (in == 'o') {
        return 'k';
    }
    if (in == 'p') {
        return 'r';
    }
    if (in == 'q') {
        return 'z';
    }
    if (in == 'r') {
        return 't';
    }
    if (in == 's') {
        return 'n';
    }
    if (in == 't') {
        return 'w';
    }
    if (in == 'u') {
        return 'j';
    }
    if (in == 'v') {
        return 'p';
    }
    if (in == 'w') {
        return 'f';
    }
    if (in == 'x') {
        return 'm';
    }
    if (in == 'y') {
        return 'a';
    }
    return 'q';
    
}
int main(int argc, const char * argv[])
{

    std::string num1;
    std::ofstream myfile;
    myfile.open ("example.txt");
    std::ifstream read;
    read.open("a.txt");
    std::getline(read, num1);
    int num = atoi(num1.c_str());
    for (int u = 1; u !=num+1; u++) {
        std::string out;
        std::getline(read,out);
        std::string one;
        for ( auto x: out){
            one = one + change(x);
        }
        out = one;
        myfile<<"Case #" <<u <<": " << out << std::endl;
        std::cout<<"Case #" <<u <<": " << out << std::endl;

    }
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

