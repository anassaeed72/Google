#include <iostream>
#include <fstream>
#include<vector>
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
//    int  u  =1;
    std::string num1;
    std::ofstream myfile;
    myfile.open ("example.txt");
    std::ifstream read;
    read.open("a.txt");
    std::getline(read, num1);
        int num = atoi(num1.c_str());
for (int u = 1; u !=num+1; u++) {
    int one,one11,one12,one13,one14;
    int two,two11,two12,two13,two14;
    std::string on1;
    std::getline(read, on1);
    one = atoi(on1.c_str());
    std::string dummy;
    for (int  i = 1; i < 5; i++) {
        std::string temp1;
        std::getline(read, temp1);
        if (one == i) {
            std::vector<std::string> y =string_split(temp1,' ');
            one11 = atoi(y[0].c_str());
            one12 = atoi(y[1].c_str());
            one13 = atoi(y[2].c_str());
            one14 = atoi(y[3].c_str());
//            std::cout << one11 << " " << one12 << " " << one13 <<" " << one14;
        }
    }
    std::string twos;
    std::getline(read, twos);
    two = atoi(twos.c_str());
    for (int  i = 1; i < 5; i++) {
        std::string temp1;
        std::getline(read, temp1);
        if (two == i) {
            std::vector<std::string> y =string_split(temp1,' ');
            two11 = atoi(y[0].c_str());
            two12 = atoi(y[1].c_str());
            two13 = atoi(y[2].c_str());
            two14 = atoi(y[3].c_str());
//            std::cout << two11 << " " << two12 << " " <<two13 << " " << two14;

        }
    }
    
    int count =0;
    int value = 0;
    if (one11 == two11 ||one11 == two12 ||one11 == two13 ||one11 == two14 ) {
        value = one11;
        count++;
    }
    if (one12 == two11 ||one12 == two12 ||one12 == two13 ||one12 == two14 ) {
        value = one12;
        count++;
    }
    if (one13 == two11 ||one13 == two12 ||one13 == two13 ||one13 == two14 ) {
        value = one13;
        count++;
    }
    if (one14 == two11 ||one14 == two12 ||one14 == two13 ||one14 == two14 ) {
        value = one14;
        count++;
    }
    if (count == 0) {
        std::cout <<"Case #" <<u << ": Volunteer cheated!" << std::endl;
    }else    if (count >1) {
        std::cout <<"Case #" <<u << ": Bad magician!" << std::endl;
    }else{
        std::cout <<"Case #" <<u <<": "<< value <<std::endl;
    }
}

    myfile.close();
return 0;
}

