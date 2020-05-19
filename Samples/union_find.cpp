#include <iostream>

using namespace std;

#define MAX_N 100000

int par[MAX_N];
int depth[MAX_N];
int nGroup[MAX_N];

void init(int n){
  for(int i=0; i<n; i++){
    par[i] = i;
    depth[i] = 0;
    nGroup[i] = 1;
  }
}
int root(int x){
  if(par[x] == x){
    return x;
  } else {
    return par[x] = root(par[x]);
  }
}

bool same(int x, int y){
  return root(x) == root(y);
}

void unite(int x, int y){
  x = root(x);
  y = root(y);
  if(x == y) return;

  if(depth[x] < depth[y]){
    par[x] = y;
    nGroup[y] += nGroup[x];
    nGroup[x] = 0;
  } else {
    par[y] = x;
    nGroup[x] += nGroup[y];
    nGroup[y] = 0;
    if(depth[x] == depth[y])
      depth[x]++;
  }
}

int main(){
  init(MAX_N);
  int N;
  cin >> N;
  for(int i=0; i<N; i++){
    int x, y;
    cin >> x >> y;
    unite(x, y);
  }
  for(int i=0; i<N; i++){
    cout << i << ": "
	 << root(i) << ' '
	 << depth[i] << ' '
	 << nGroup[i] << endl;
  }
  return 0;
}
