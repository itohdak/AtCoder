#include <iostream>
#include <cstdlib>

using namespace std;

#define INF (1 << 29)
int N, M, R;
int d[201][201];
int r[9];
int A, B, C;
int res;
bool used[9];

void dfs(int c, int las, int dist){
  if(c == R+1){
    if(res > dist) res = dist;
    return;
  }
  for(int i=0; i<=R; i++){
    if(!used[i]){
      used[i] = true;
      if(las == -1) dfs(c+1, i, 0);
      else dfs(c+1, i, dist+d[r[las]][r[i]]);
      used[i] = false;
    }
  }
}

int main(){
  cin >> N >> M >> R;

  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      if(i != j)
	d[i][j] = INF;

  for(int i=0; i<R; i++)
    cin >> r[i];

  for(int i=0; i<M; i++){
    cin >> A >> B >> C;
    if(d[A][B] > C)
      d[A][B] = d[B][A] = C;
  }

  for(int k=0; k<N; k++)
    for(int i=0; i<N; i++)
      for(int j=0; j<N; j++)
	if(d[i][j] > d[i][k] + d[k][j])
	  d[i][j] = d[i][k] + d[k][j];

  res = INF;
  dfs(1, -1, 0);
  cout << res << endl;

  return 0;
}

