#pragma once

#include <bits/stdc++.h>
using namespace std;


//调用请使用 utils::name
namespace utils{


// vec 转化成标准输入 -> "1 4 3 3 2 2 3"
template<typename T>
std::string to_string(vector<T>& vec){
    string s;
    for(int i=0; i<vec.size(); i++){
        s += std::to_string(vec[i]);
        if(i != vec.size()-1) s += ' ';
    }
    return s;
}
 




}