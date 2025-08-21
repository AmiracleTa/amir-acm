#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

#include "const.hpp"
#include "checker.hpp"
#include "utils.hpp"
#include "rng_utils.hpp"


// 生成测试样例
void gen(){  
    std::ofstream ofs(PATH_INPUT); // output file stream // 请略过..

// 用 ofs 代替 cout 以写入到 INPUT 文件中
// 示例:
    ofs << t << '\n';

    int n = 5, lo = 15, hi = 30; 
    for(int tt=0; tt<t; tt++){
        ofs << n << '\n';
        auto vec = random_vec(n, lo, hi); // 生成长度为 n 的随机数组, 元素范围 [lo, hi]
        ofs << utils::to_string(vec) << '\n'; // 转化成 "a1 a2 a3 a4..." 标准形式
    }

}


int main(){
    init();
    for(int i=0; i<k; i++){
        gen(); // generate test cases (input)
        work();
    }

}

