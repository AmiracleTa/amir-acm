#pragma once
#include<bits/stdc++.h>
using namespace std;


const int k = 33;  // 总测试轮数
const int t = 10;  // 每轮 t 组测试数据


// input & output file
const string PATH_INPUT = "input.in";
const string PATH_OUTPUT_CORRECT = "output_ans.out";
const string PATH_OUTPUT_MINE = "output_mine.out";

// log file
const string PATH_LOG = "check_log.out";

// cpp file
const string PATH_CORRECT = "correct.cpp";
const string PATH_MINE = "mine.cpp";
const string PATH_EXE_CORRECT = "correct.exe";
const string PATH_EXE_MINE = "mine.exe";

// compile cmd
const string VER = "-std=c++17";
const string CMD_CORRECT = "g++ " + VER + " " + PATH_CORRECT + " -o " + PATH_EXE_CORRECT;
const string CMD_MINE = "g++ " + VER + " " + PATH_MINE + " -o " + PATH_EXE_MINE;

