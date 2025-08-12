#pragma once

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

const int inf = 0x3f3f3f3f;

ull seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937_64 rng(seed);

/*
.Note
  int range only. (

.cur
  number
  array
  permutation
  01matrix with expectation

  tree
  simple (un)onnected graph


*/

// get one random number
auto random_num(int lo, int hi){
    uniform_int_distribution<int> dist(lo, hi);
    int num = dist(rng);
    return num;
}
// create vector with n elements  ,  inclusive[lo, hi]
auto random_vec(int n, int lo, int hi){
    uniform_int_distribution<int> dist(lo, hi);
    vector<int> ans;
    while(n--) ans.push_back(dist(rng));
    return ans;
}

// create random permutation // 0-index
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
auto random_01mat(int n, int m, double exp=0.5){ // exp - P(X=1) - probability of 1 occurring - inclusive[0.0, 1.0]
    vector<vector<int>> mat(n, vector<int>(m));
    vector<double> wt{1-exp, exp}; // weight
    discrete_distribution<int> dist(wt.begin(), wt.end());

    for(auto& vec : mat) for(auto& x : vec){
        x = dist(rng);
    }

    return mat;
}

// 只要把 [1..n] 的映射打乱, 就能得到完全随机的树
// create a random tree
auto random_tree(int n){ // n vertex
    vector<pii> edge;
    for(int i=2; i<=n; i++){
        uniform_int_distribution<int> dist(1, i-1);
        int fa = dist(rng);
        edge.push_back({fa, i});
    }
    return edge;
}
// create a  -simple undirected-  graph
auto random_sim_gra(int n, int m){
    assert( m <= 1ll*n*(n-1)/2 );

    auto edge = random_tree(n);
    shuffle(edge.begin(), edge.end(), rng); 
    int ext = max(0, n-1-m);
    int del = random_num(ext, ext+min(n-1,m)/2); 
    edge.erase(edge.end()-del, edge.end()); // delete extra edges && delete some edges randomly

    set<pii> vis(edge.begin(), edge.end());
    while(edge.size() < m){
        auto vec = random_vec(2, 1, n);
        int u = vec[0], v = vec[1];
        if(u > v) swap(u, v);
        if(u == v || vis.count({u, v})) continue;
        edge.push_back({u, v});
        vis.insert({u, v});
    }
    return edge;
}
// create a  -simple connected undirected-  graph
auto random_sim_con_gra(int n, int m){ // 简单连通图 // 需要 m>=n-1
    assert( n-1 <= m && m <= 1ll*n*(n-1)/2 );

    auto edge = random_tree(n);
    set<pii> vis(edge.begin(), edge.end());
    while(edge.size() < m){
        auto vec = random_vec(2, 1, n);
        int u = vec[0], v = vec[1];
        if(u > v) swap(u, v);
        if(u == v || vis.count({u, v})) continue;
        edge.push_back({u, v});
        vis.insert({u, v});
    }
    return edge;
}

