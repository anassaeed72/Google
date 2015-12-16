#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <algorithm>
int count  = 0;
int change(std::vector<std::string> a, std::vector<std::string> b);
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
std::vector<std::string> toggle(std::vector<std::string> input, int num);
std::vector<std::string> toggle(std::vector<std::string> input,unsigned int num){
    unsigned int i = 0;
    for ( auto & x: input){
        if (input[i][num] == '1') {
            input[i][num] = '0';
        }
        else if (input[i][num] == '0') {
            input[i][num] = '1';
        }
        i++;
    }
    
    return input;
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
    std::vector<std::string> needed;
    std::vector<std::string> given;
    for (int  i = 1; i!=total_runs+1; i++) {
        int total = 0;
        int switches = 0;
        int flips =0;
        std::getline(read, dummy);
        std::vector<std::string> xk = string_split(dummy, ' ');
        total =atoi(xk[0].c_str());
        switches = atoi(xk[1].c_str());
        std::getline(read,dummy);
        needed = string_split(dummy, ' ');
        std::getline(read,dummy);
        given = string_split(dummy, ' ');
        count = 0;
        flips = change(needed, given);
        if (flips >total ) {
//            myfile << "Case #" << i <<": " << "NOT POSSIBLE"<< std::endl;
//            continue;

        }
    myfile << "Case #" << i <<": " << flips<< std::endl;
    }
    return 0;
}
int change(std::vector<std::string> a, std::vector<std::string> b){
//    std::vector<std::string> not1;
//    if (a == b) {
//        return 0;
//    }
//    if (count <= 0) {
//        return 0;
//    }
//    int flips  = 0;
//    std::vector<bool> ch = std::vector<bool> (a.size());
//    int k = 0;
//    for (auto  x : ch){
//        x = 0;
//        ch[k] = false;
//        k++;
//    }
//    for (auto x: a){
//        bool check = false;
//        
//        k = 0;
//        for (auto y : b){
//            if (x ==y) {
//                check = true;
//                ch[k] = true;
//                continue;
//            }
//            k++;
//        }
//        if (check == false) {
//            not1.push_back(x);
//        }
//    }
//            unsigned int num1 = 0;
//            unsigned int num = 0;
//            for (auto z:ch){
//                if ( z == false) {
//                    std::string match = not1[num1];
//                    num1++;
//                    std::string match1 = b[num];
//                
//                    unsigned int i = 0;
//                
//                    
//                    for ( auto x:match){
//                        if ( x != match1[i]) {
//                            flips++;
//                            count--;
//                            a = toggle(a, i);
//                            if (a == b) {
//                                break;
//                            }
//                        }
//                    }}
//                    if ( count  <=0) {
//                        break;
//                    }
//                }
//                num++;
//    return flips;
   
    
    if (count >= 1000) {
        return -1;
    }
    int flips=0;
    unsigned int index = 0;
    unsigned int in =0;
    bool check = false;
    for ( auto x: a){
        in  = 0;
        index = 0;
        for (auto y:b){
            if (x == y) {
                check = true;
            }else if (check == false){
                index = in;
            }
            in++;
        }
        if (check == false) {
            unsigned int local = 0;
//            std::cout << index;
            std::string local_ = b[index];
            for ( auto xx: x){
                std::cout << xx << " " << local_[local] << "    ";
                if (xx!=local_[local]) {
                    flips++;
                    a = toggle(a, local);
                }
                local++;
            }
        }
    }
    if ( a!= b) {
        std::cout << a[0] << " " << a[1] << "    " << b[0] << " " << b[1] << std::endl;
        count++;
        int local = change(a, b);
        if (local == -1) {
            return  -1;
        }
        flips = flips +change(a, b);
    }
    return flips;
}
