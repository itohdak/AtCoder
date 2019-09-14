#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long
#define MAX_N 100000

int par[MAX_N]; // 親の番号
int depth[MAX_N];
int nGroup[MAX_N];
ll ans;

// n要素で初期化
void init(int n){
  for(int i=0; i<n; i++){
    par[i] = i;
    depth[i] = 0;
    nGroup[i] = 1;
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
  ans = 0;
  x = root(x);
  y = root(y);
  if(x == y) return;

  if(depth[x] < depth[y]){
    par[x] = y;
    ans = nGroup[x] * nGroup[y];
    nGroup[y] += nGroup[x];
    nGroup[x] = 0;
  } else {
    par[y] = x;
    ans = nGroup[x] * nGroup[y];
    nGroup[x] += nGroup[y];
    nGroup[y] = 0;
    if(depth[x] == depth[y])
      depth[x]++;
  }
}

int main(){
  init(MAX_N);
  int N, M;
  cin >> N >> M;
  vector<pair<int, int> > bridge;
  for(int i=0; i<M; i++) {
    int A, B;
    cin >> A >> B;
    bridge.push_back(pair<int, int>(A, B));
  }
  vector<int> vAns;
  for(int i=M-1; i>=0; i--){
    pair<int, int> tmp = bridge[i];
    int A = tmp.first, B = tmp.second;
    unite(A, B);
    vAns.push_back(ans);
  }
  ll tmp = 0;
  for(int i=M-1; i>=0; i--) {
    tmp += vAns[i];
    cout << tmp << endl;
  }
  return 0;
}
