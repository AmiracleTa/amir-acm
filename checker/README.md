### 简介

这是一个可以帮助你快速对拍的工具，目标是 5 min 内完成对拍纠错

你是否遇到以下情况：

- 希望找到一组小样例，以便 debug 自己的代码来快速纠错

- 希望快速写出数据生成器，以便对拍

那么，你可以借助这个对拍器快速找样例纠错



### 使用说明

此对拍器，无需额外配置环境，c++17 的初始环境就足以使用

**步骤：**

1. 将自己的代码粘贴到 "mine.cpp"，将正确代码粘贴到 "correct.cpp"
2. 在 "main.cpp" 里重写 ”gen()" 函数 (即数据生成器)

3. 运行 "main.cpp" 即可

**提醒：**

0. 反复编译非常耗费时间，没有多测最好改成多测

1. 对拍的状态信息在 "check_log.out" 文件
2. "gen()" 生成的样例在 "input.in" 文件
3. 自己代码 和 正确代码 的输出分别在 "output_mine.out" , "output_ans.out"
4. 随机数生成工具在 "rng_utils.hpp"
5. 程序段错误, 会导致 ret 非 0, 然后 exit(1)
6. 仅支持答案唯一，答案不唯一要自己写一个 checker()

**随机数生成工具使用范例：**

```cpp
void gen(){  
    // ... 
    
    int n = 5, lo = 15, hi = 30; 
    vector<int> vec = random_vec(n, lo, hi); // 生成长度为 n 的随机数组, 元素范围 [lo, hi]
    
    // ... 
}

```



### 更新日志

重构了代码, 结构更清晰, 更易使用 - t250821





*// ACCEPTED - or DEBUG TILL DEATH.*

*// ACCEPTED is destiny..*

