//
//  main.cpp
//  Google_4
//
//  Created by Anas Saeed on 12/04/2014.
//  Copyright (c) 2014 Anas Saeed. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
std::vector<double> rem(std::vector<double> a,double breaker);
std::vector<double> rem(std::vector<double> a,double breaker){
    std::vector<double> out;
    for(auto x: a){
        if (x == breaker) {
            continue;
        }
        out.push_back(x);
    }
    return out;
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

int main(int argc, const char * argv[])
{
    double chosen_naomi;
    double chosen_ken;
    double told_naomi;
    double blocks;
    std::ofstream myfile;
    myfile.open ("example.txt");
    myfile.setf(7);
    std::ifstream read;
    read.open("a.txt");
    std::string yt;
    std::getline(read, yt);
    int times = atoi(yt.c_str());
    for (int p = 1; p<=times; p++) {
        std::string dummy;
        std::getline(read,dummy);
        blocks =atoi(dummy.c_str());
        std::string dummy1,dummy2;
        std::getline(read,dummy1);
        std::getline(read,dummy2);
        std::vector<std::string> v = string_split(dummy1, ' ');
        std::vector<std::string> v1 = string_split(dummy2, ' ');
        
        std::vector<double> one,two;
        for (int i = 0;i < blocks; i++) {
            one.push_back(atof(v[i].c_str()));
        }
        std::sort(one.begin(),one.end());
        for (int  i = 0; i < blocks; i++) {
    //        myfile <<one[i] <<" ";
        }
        for (int  i = 0; i < blocks; i++) {
            two.push_back(atof(v1[i].c_str()));
        }
        std::sort(two.begin(),two.end());
        int score = 0;
        std::vector<double> other = two;
        for (int  i = blocks-1; i >=0; i--) {
    //        std::cout << one[i] << " " << two[i] <<std::endl;
            double a=10;
            bool check = false;
            for (auto x: two){
                if (x >one[i] && x<a) {
    //                std::cout << x << " " << one[i];
                    check = true;
                    a = x;
                }
            }
            two = rem(two,a);
            if ( check ==false ) {
                score++;
            }
        }
        // for the optimization
        int other_score = 0;
        for (int  i = 0; i < blocks; i++) {
//            std::cout <<one[blocks-i-1]  <<" " << other[i] << std::endl;
            double u = 0;
            bool check = false;
            for(auto x:other){
                if (x>u && x<one[i]) {
                    check = true;
                    u = x;
                }
            }
            other = rem(other, u);
            if (check == true) {
                other_score++;
            }
        }
        myfile <<"Case #"<<p<<": "<<other_score << "  "<< score<< std::endl;
    }
    return 0;
}

