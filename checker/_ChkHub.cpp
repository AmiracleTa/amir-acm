#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

#include "_rng_utils.hpp"
#include "_utils.hpp"

#ifdef ONLINE_JUDGE
    #define debug(...) 42;
    #define out(x) 114514;
#else
    #include "_debug.hpp"
#endif

                ////** 请看本文件最后 **////

//  .`]nCLY1, '^^`. .`^^'  .^^^'  .^""'  '""".  '^^' !fCQYf>.  
// .]m*#****wfi'.``''`'``'''````'''````''```^`''''^-Xh#**##aUI 
// ;aMoooooo*#hX-^'^^'..'""^...`"^^...`""`...^``l|0*#ooooooo&Y 
// '/p##ooooooo#*m\; '^^`..'^^^`..'"^^'..'"`.'<ubM#oooooo*#*0_ 
// ..:(0o#*oooooo*#bc_^.`'''````'''````'''.;)Ca#*oooooo*#kz?`..
// .^`'^_XhM*oooooo*#oQ{:'`^'..`""^...`'`>jp##ooooooo##pjI '^"'
//  ...```>jq##ooooooo##pr>.'^^`..'^^'^?Uh#*ooooooo#oL{:''^'.. 
// .'''```'.,)0*#ooooooo*MaU["''`'.'l\m*#ooooooo*#kz+'.``'```'.
// ."^"'..'"^'`+zkM*ooooooo##m/i`"_vb##ooooooo#*wfl '^^`...""".
// ....``'`...^`'lfq##ooooooo*#hXQo#ooooooooMoL["'`^'..'`'`... 
// .`..:<-_I.'```'.,1Lo#oooooooo#*ooooooo*Mkc+`.``'`' `>-_!^.'.
// .`+Xpa**kY?'  '"^''~ck#ooooooooooooo##wtI '""^.  I\Za*okZf:.
//  1o#*oooo#oO(I. .."``!tq**oooooooo#oL}"'^^'...^~ubM*oooo*MZ,
//  t##ooooooo*#bv<`.```'.,{Lo#****#kc~`.```''.,10o#*oooooo*#dI
// .^_Yh#*oooooo*#oL{"  `^^''~cqkbZtI '^^^' .>rp##ooooooo#*wtl 
//  .  !jp##ooooooo##qri. .'```",,`'`^'.  ,}Jh#*ooooooo#oC}^   
// .`''' "{0o#ooooooo*#hY-^.````''```''.I/m*#ooooooo*#bc~'.`'`.
// ."^^'.  ^+ck#*ooooooo#*Zt;  `^^^. '_zk#*ooooooo##Z\l. .'^^^.
//  ...`""^.  lfw##ooooooo*#bv_` . ;(0*#oooooooo#aC}`  `"^^... 
// .````''``'`' "}Qo#ooooooo*#o01<xd##ooooooo*#bx>..`'``''````.
// .^^^'..'"^"'...^+ck#*ooooooo#*a#*ooooooo#*Z\l. .'"^^`..'"^".
//   ..^""^...^""^.  ltq##oooooooooooooo*#aJ]`  '""^'..`^^^... 
// .````''`````''````' ^}Lo#oooooooooo*#dn>..````''````^'''```.
// .^^"'..'"""'..`""^....^+vb#*ooooo#*O|I'...^""`..."""`...^"^.
//  . .^"^^...^^^^...^""`.  ltmo###hU]`  '"""' .'^^^'..`""^..  
//     ''''   ''''   ''''  .. ^_uY(i'..  .```.  .'''.  .'''.   



// CONST
// input & output file
const string PATH_IN = "_input.in";
const string PATH_OUT_CORRECT = "_output_ans.out";
const string PATH_OUT_MINE = "_output_mine.out";

// log file
const string PATH_LOG = "_check_log.out";

// cpp file
const string PATH_CORRECT = "_correct.cpp";
const string PATH_MINE = "_mine.cpp";
const string PATH_EXE_CORRECT = "_correct.exe";
const string PATH_EXE_MINE = "_mine.exe";

// compile cmd // 自行更改编译参数
const string VER = "-std=c++23";
const string CMD_CORRECT = "g++ " + VER + " " + PATH_CORRECT + " -o " + PATH_EXE_CORRECT;
const string CMD_MINE = "g++ " + VER + " " + PATH_MINE + " -o " + PATH_EXE_MINE;



// state var for error
int ret1, ret2;


// massage output
auto outmsg = [](string msg) ->void {
    std::ofstream ofs(PATH_LOG, std::ios::app);
    ofs << msg << '\n';
};
// error output
auto outerr = [](string msg) ->void {
    outmsg(msg);
    cerr << "Error?? QWQ" << '\n';
    cerr << msg << '\n';
    exit(1);
};
// clear file
void init(){
    std::ofstream(PATH_IN, std::ios::out); // 默认 out 模式     
    std::ofstream(PATH_OUT_CORRECT, std::ios::out); // 默认 out 模式     
    std::ofstream(PATH_OUT_MINE, std::ios::out); // 默认 out 模式     
    std::ofstream(PATH_LOG, std::ios::out); // 默认 out 模式     
}
// compile
void compile(){
    ret1 = system(CMD_CORRECT.c_str());
    ret2 = system(CMD_MINE.c_str());
    if(ret1 || ret2) outerr("Compilation Failed");
    outmsg("Compile done");
    cout << "Compile done" << '\n';
}


void work(){
// redirection 
//   && running
    ret1 = system((PATH_EXE_CORRECT + " < " + PATH_IN + " > " + PATH_OUT_CORRECT).c_str()); // to c string
    ret2 = system((PATH_EXE_MINE + " < " + PATH_IN + " > " + PATH_OUT_MINE).c_str());
    if(ret1 || ret2) outerr("Redirection or Running failed");
    // outmsg("Rdirection && running finished");


// reading file
    ifstream ifs1(PATH_OUT_CORRECT), ifs2(PATH_OUT_MINE); // input file stream // 读取文件
    if(!ifs1 || !ifs2) outerr("Failed to open output.out");
    // outmsg("Reading succeeded");


//  out wa msg
    auto wa = [&](int k){
        outmsg("WA on lines " + to_string(k) + " QAQ");
    };

    string ans, mine, line;
    bool flg_wa = false;
    int cnt1 = 0, cnt2 = 0;

// count lines
    while(getline(ifs1, line)) if(!line.empty()) cnt1++;
    while(getline(ifs2, line)) if(!line.empty()) cnt2++;
    ifs1.clear(), ifs1.seekg(0); // 指针回到开始
    ifs2.clear(), ifs2.seekg(0);
    if(cnt1 != cnt2){
        outmsg( "The number of lines is not the same" );
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
            wa(cur);
            flg_wa = true;
        }
    }
    if(flg_wa){
        outmsg("wa on this testcase... QAQ");
        cout << "wrong answser" << '\n';
        exit(1);
    }
}



//// **
// generate random testcase //
// 需根据实际样例改写
void gen_input(){  
    std::ofstream ofs(PATH_IN); // output file stream  
//** 注意是 ofs 输入到文件 , 并非 cout **//
// 示例
    int t = 50; // 多测
    ofs << t << '\n';
    
    while(t--){
        auto vec = random_vec(2, 30, 100); // n=2  inclusive=[30, 100]

        ofs << vec[0] << ' ' << vec[1] << '\n';

    }

}


// 测试接口 // 测试比如 random
void test(){
    gen_input();

    // while(t--){
    // }

    exit(1);
}


int main(){
    init(); // clear file

    outmsg("is preparing..");
    cout << "is preparing.." << '\n';
    compile();
    
    // test(); // test fun 
    
    outmsg("running..");
    cout << "running.." << '\n';

    int k = 33, cur = 0; // k轮测试 & 当前轮次
    while(k--){
        outmsg("testcase " + to_string(++cur) + " is running");
        gen_input(); // random generate testcases
        work();
    }

    string AC = "All testcases accepted";
    outmsg( AC );
    cout << AC << '\n';
    
    return 0;
}


/* 
// ACCEPTED - or - DEBUG TILL DEATH.


// description
  随机生成大量数据, 然后和正确代码对拍
  以找到错误样例, 调试出难以察觉的错误, 节约时间

 
// instructions
.for useing **

  0. 本文件需要修改的有 gen_input() , 文件开头的 编译参数(可能) , 文件路径(可能)

  1. _correct.cpp 写正确代码   _mine.cpp 写待测代码
  2. 修改 gen_input(), 以生成所需样例
  运行即可
  
  3. _input.in 中为 gen_input() 生成的样例
  4. _rng_utils.hpp 有一些常用的随机函数  (虽然目前还很少
  5. 程序会对比 _output_correct , _output_mine 两个文件,
     即检查和 ans 输出是否相同,
     不同则结束本轮测试
  6. 注意最好是多测形式 , 没多测要改成多测 , 要么会很慢
  7. 测试信息请看 _check_log.out
  8. 若无 c++23 , 可以改成 "-std=c++14(17)"

.


////
.useless:
(废话)
  需一份标答代码对拍, 若无, 可ai一份 正确|暴力 代码进行对拍找样例
  
  频繁 system 调用文件花销很大
  多测减少 system 调用次数, 就很好使


// cur problems:

.important

  不太好找是哪个测试样例错了 (不过一般会错的比较靠前.. 应该)

...

.
  对某些问题
  有点难区分输出是来自哪个测试样例 
.
  还有就是, 开始时间略微有点久(??)
.
  有代码会多输出奇怪的空格...
.
  暂时只支持答案唯一
.
  非多测要改成多测
.
  可能存在位置bug
.
  未完成un...
.


// 已知:
.
  程序段错误, 会导致 ret 非 0, 然后 exit(1)



*/
// ACCEPTED is destiny..
