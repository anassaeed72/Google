//
//  main.cpp
//  Recycle
//
//  Created by Anas Saeed on 22/05/2014.
//  Copyright (c) 2014 Anas Saeed. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
char single(int in);
char single(int in){
    if (in == 0) {
        return '0';
    }
    if (in == 1) {
        return '1';
    }
    if (in == 2) {
        return '2';
    }
    if (in == 3) {
        return '3';
    }
    if (in == 4) {
        return '4';
    }
    if (in == 5) {
        return '5';
    }
    if (in == 6) {
        return '6';
    }
    if (in == 7) {
        return '7';
    }
    if (in == 8) {
        return '8';
    }
    return '9';
}
int singlely(char in);
int singlely(char in){
    if (in =='0') {
        return 0;
    }
    if (in =='1') {
        return 1;
    }
    if (in =='2') {
        return 2;
    }
    if (in =='3') {
        return 3;
    }
    if (in =='4') {
        return 4;
    }
    if (in =='5') {
        return 5;
    }
    if (in =='6') {
        return 6;
    }
    if (in =='7') {
        return 7;
    }
    if (in =='8') {
        return 8;
    }
    return 9;
}
std::string reverser(std::string in);
std::string reverser(std::string in){
    std::string output;
    for (int i = in.length()-1; i>=0; i--) {
        output = output + in[i];
    }
    return output;
}
std::string int_string(int input);
std::string int_string(int input){
    std::string output;
    int num = 10;
    while (input >0) {
        int dummy = input%num;
        input = input/num;
        //        num = num*10;
        output = output + single(dummy);
    }
    return reverser(output);
}
int string_int(std::string input);
int string_int(std::string input){
    int out = 0;
    input = reverser(input);
    int num = 1;
    for ( auto x: input){
        out = out + singlely(x)*num;
        num = num*10;
    }
    return out;
}
std::vector<std::string> rotation(std::string in);
std::vector<std::string> rotation(std::string in){
    std::vector<std::string> result;
    for (int i = 1; i < in.length(); i++) {
        std::string dummy;
        int index = in.length()-i;
        for (int j = 0 ; j < in.length(); j++) {
            dummy = dummy + in[index];
            index++;
            index = index%in.length();
        }
//        std::cout << dummy << " ";
        result.push_back(dummy);
    }
    return result;
}
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


int num(int lower, int upper);
int num(int lower, int upper){
    int total = 0;
    for (int i = lower+1; i < upper; i++) {
        std::vector<std::string> result = rotation(int_string(i));
        for ( auto x : result){
            if (i == string_int(x) || string_int(x) < i) {
                continue;
            }
            if (string_int(x) >= lower && string_int(x) < upper-1) {
//                std::cout <<x << " ";
                total++;
            }
        }
    }
    return total;
}
int main(int argc, const char * argv[])
{
    std::string num1;
    std::ofstream myfile;
    myfile.open ("example.txt");
    std::ifstream read;
    read.open("a.txt");
    std::getline(read, num1);
    int num12 = atoi(num1.c_str());
    for (int u = 1; u !=num12+1; u++) {
        std::string out;
        std::getline(read,out);
        std::vector<std::string> one = string_split(out, ' ');
        int ans = num(string_int(one[0]),string_int(one[1]));
        myfile<<"Case #" <<u <<": " << ans << std::endl;
//        std::cout<<"Case #" <<u <<": " << ans << std::endl;
        
    }

    // insert code here...
    std::cout << "Hello, World!\n" << num(1111,2222) << " " << num(1, 9) << " "<< num(10, 40) << " " << num(100, 500);
    return 0;
}

