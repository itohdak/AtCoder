#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

#define MAX_N 200000

int par[MAX_N]; // 親の番号
int depth[MAX_N];

// n要素で初期化
void init(int n){
  for(int i=0; i<n; i++){
    par[i] = i;
    depth[i] = 0;
  }
}
// 木の根を求める
int root(int x){
  if(par[x] == x){ // 根
    return x;
  } else {
    return par[x] = root(par[x]); // 経路圧縮
  }
}

// xとyが同じ集合に属するか否か
bool same(int x, int y){
  return root(x) == root(y);
}

// xとyの属する集合を併合
void unite(int x, int y){
  x = root(x);
  y = root(y);
  if(x == y) return;

  if(depth[x] < depth[y]){
    par[x] = y;
  } else {
    par[y] = x;
    if(depth[x] == depth[y])
      depth[x]++;
  }
}

struct edge {
  int from;
  int to;
  ll cost;
  edge(int f, int t, ll c) : from(f), to(t), cost(c){};
};

bool comp(edge e1, edge e2) {
  return e1.cost < e2.cost;
}

int main(){
  int N;
  ll D;
  vector<edge> E;
  cin >> N >> D;
  init(N);
  vector<ll> A(N);
  for(int i=0; i<N; i++)
    cin >> A[i];
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      edge e(i, j, abs(i-j)*D+A[i]+A[j]);
      E.push_back(e);
    }
  }
  sort(E.begin(), E.end(), comp);
  ll ans = 0;
  for(int i=0; i<E.size(); i++) {
    edge e = E[i];
    if(!same(e.from, e.to)) {
      ans += e.cost;
      unite(e.from, e.to);
    }
  }
  cout << ans << endl;
  return 0;
}

