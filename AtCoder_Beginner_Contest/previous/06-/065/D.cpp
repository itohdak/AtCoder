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
int node_rank[MAX_N];

// n要素で初期化
void init(int n){
  for(int i=0; i<n; i++){
    par[i] = i;
    node_rank[i] = 0;
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

  if(node_rank[x] < node_rank[y]){
    par[x] = y;
  } else {
    par[y] = x;
    if(node_rank[x] == node_rank[y])
      node_rank[x]++;
  }
}

struct data{
  int n;
  ll x;
  ll y;
};
struct edge{
  int p;
  int q;
  ll cost;
};

bool compx(data d1, data d2){
  return d1.x < d2.x;
}
bool compy(data d1, data d2){
  return d1.y < d2.y;
}
bool compe(edge e1, edge e2){
  return e1.cost < e2.cost;
}

int main(){
  int N;
  cin >> N;
  vector<data> Dx, Dy;

  for(int i=0; i<N; i++){
    ll x, y;
    cin >> x >> y;
    data dtmp = {i, x, y};
    Dx.push_back(dtmp);
    Dy.push_back(dtmp);
  }
  sort(Dx.begin(), Dx.end(), compx);
  sort(Dy.begin(), Dy.end(), compy);

  // cout << endl;
  // for(int i=0; i<Dx.size(); i++)
  //   cout << Dx[i].x << ' ' << Dx[i].y << endl;
  // cout << endl;
  // cout << endl;
  // for(int i=0; i<Dy.size(); i++)
  //   cout << Dy[i].x << ' ' << Dy[i].y << endl;
  // cout << endl;

  vector<edge> E;
  for(int i=0; i<N-1; i++){
    edge etmpx = {Dx[i].n, Dx[i+1].n, Dx[i+1].x - Dx[i].x};
    edge etmpy = {Dy[i].n, Dy[i+1].n, Dy[i+1].y - Dy[i].y};
    E.push_back(etmpx);
    E.push_back(etmpy);
  }
  sort(E.begin(), E.end(), compe);

  init(N);
  ll ans = 0;
  for(int i=0; i<2*(N-1); i++){
    // cout << E[i].p << ' ' << E[i].q << ' ' << E[i].cost;
    edge e = E[i];
    if(!same(e.p, e.q)){
      ans += e.cost;
      unite(e.p, e.q);
      // cout << " o" << endl;
    } else {
      // cout << " x" << endl;
    }
  }
  cout << ans << endl;
  return 0;
}
