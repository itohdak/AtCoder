#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

#define MAX_N 160005

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

bool M[405][405];
void sub(int i1, int j1, int i2, int j2, int W) {
  if(M[i1][j1] xor M[i2][j2]) {
    unite(i1*W+j1, i2*W+j2);
  }
}

int main(){
  int H, W;
  cin >> H >> W;
  for(int i=0; i<H; i++) {
    string S;
    cin >> S;
    for(int j=0; j<W; j++) {
      if(S[j] == '.') // white
	M[i][j] = true;
      else // black
	M[i][j] = false;
    }
  }
  init(H*W);
  for(int i=0; i<H; i++) {
    for(int j=0; j<W; j++) {
      bool self = M[i][j];
      // if(i != 0)
      // 	sub(i, j, i-1, j, W);
      if(i != H-1)
	sub(i, j, i+1, j, W);
      // if(j != 0)
      // 	sub(i, j, i, j-1, W);
      if(j != W-1)
	sub(i, j, i, j+1, W);
    }
  }
  vector<ll> white(H*W, 0);
  vector<ll> black(H*W, 0);
  for(int i=0; i<H; i++) {
    for(int j=0; j<W; j++) {
      if(M[i][j]) { // white
	white[root(i*W+j)]++;
      } else { // black
	black[root(i*W+j)]++;
      }
    }
  }
  ll ans = 0;
  for(int i=0; i<H*W; i++)
    ans += white[i] * black[i];
  cout << ans << endl;
  return 0;
}

