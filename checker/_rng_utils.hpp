#pragma once

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

const int inf = 0x3f3f3f3f;

ull seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937_64 rng(seed);


// creat vector with n elements  ,  inclusive[lo, hi]
auto random_vec(int n, int lo, int hi){
    uniform_int_distribution<int> dist(lo, hi);
    vector<int> ans;
    while(n--) ans.push_back(dist(rng));
    return ans;
}

// creat random permutation // 0-index
auto random_permutation_0_st(int n){ // [0, n-1]
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    shuffle(p.begin(), p.end(), rng);
    return p;
}
auto random_permutation_1_st(int n){ // [1, n]
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    shuffle(p.begin(), p.end(), rng);
    return p;
}

// 只要把 [1..n] 的映射打乱, 就能得到完全随机的树
// get a random tree
auto random_tree(int n){ // n vertex
    vector<pii> edge;
    for(int i=2; i<=n; i++){
        uniform_int_distribution<int> dist(1, i-1);
        int fa = dist(rng);
        edge.push_back({fa, i});
    }
    return edge;
}

