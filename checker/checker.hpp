#pragma once
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

#include "utils.hpp"
#include "const.hpp" // 常量

int CNT = 0;

 
// compile
void compile(){
    outmsg("compiling...");
    int ret1 = system(CMD_CORRECT.c_str());
    int ret2 = system(CMD_MINE.c_str());
    if(ret1 || ret2) outerr("Compilation Failed");
    outmsg("Compile done");
}
void init(){
// clear file
    std::ofstream(PATH_INPUT).close();  
    std::ofstream(PATH_OUTPUT_CORRECT).close();  
    std::ofstream(PATH_OUTPUT_MINE).close();  
    std::ofstream(PATH_LOG).close();

    compile();
}


//// core logic
void work(){
    outmsg("testcase " + to_string(++CNT) + " is running..");

// redirection 
//   && running
    int ret1 = system((PATH_EXE_CORRECT + " < " + PATH_INPUT + " > " + PATH_OUTPUT_CORRECT).c_str()); // to c string
    int ret2 = system((PATH_EXE_MINE + " < " + PATH_INPUT + " > " + PATH_OUTPUT_MINE).c_str());
    if(ret1 || ret2) outerr("Redirection or Running failed");
    // outmsg("Rdirection && running finished");


// reading file
    ifstream ifs1(PATH_OUTPUT_CORRECT), ifs2(PATH_OUTPUT_MINE); // input file stream // 读取文件
    if(!ifs1 || !ifs2) outerr("Failed to open output.out");
    // outmsg("Reading succeeded");

    string ans, mine, line;
    bool flg_wa = false;
    int cnt1 = 0, cnt2 = 0;

// count lines
    while(getline(ifs1, line)) if(!line.empty()) cnt1++;
    while(getline(ifs2, line)) if(!line.empty()) cnt2++;
    ifs1.clear(), ifs1.seekg(0); // 指针回到开始
    ifs2.clear(), ifs2.seekg(0);
    if(cnt1 != cnt2){
        outmsg( "The number of lines in the output is not the same" );
        flg_wa = true;
    }

// check answer
    int lines = min(cnt1, cnt2);
    int cur = 0;
    for(int i=1; i<=lines; i++){
        while(getline(ifs1, ans) && ans.empty());
        while(getline(ifs2, mine) && mine.empty());
        ++cur;

        if(ans != mine){
            outmsg("diff from line " + to_string(cur));
            flg_wa = true;
        }
    }

    if(flg_wa){
        outmsg("wa on this testcase QAQ");
        exit(1);
    }

    if(CNT == k){
        string AC = "All testcases accepted!";
        outmsg(AC);
    }

}

