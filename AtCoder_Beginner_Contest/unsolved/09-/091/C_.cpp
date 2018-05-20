#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)
#include <queue>

using namespace std;
#define ll long long

struct point{
  int x;
  int y;
};

#define INF 100000000

int BreadthFirstSearch(const int** C, const int** E, int s, int t){
  vector<int> P(n, -1);
  P[s] = -2;
  vector<int> M(n);
  P[s] = INF;
  queue<int> Q;
  Q.push_back(s);
  while(Q.size() > 0){
    u = Q.pop_front();
    for(vector<int>::iterator v=E[u].begin(); v!=E[u].end(); v++){
      if(C[u][v] - F[u][v] > 0 && P[v] = -1){
	P[v] = u;
	M[v] = min(M[u], C[u][v] - F[u][v]);
	if(v != t){
	  Q.push_back(v);
	} else {
	  return M[t], P;
	}
      }
    }
  }
  return 0, P;
}

int main(){
  int N;
  cin >> N;
  vector<point> P, Q;
  for(int i=0; i<N; i++){
    int a, b;
    cin >> a >> b;
    point p = {a, b};
    P.push_back(p);
  }
  for(int i=0; i<N; i++){
    int c, d;
    cin >> c >> d;
    point q = {c, d};
    Q.push_back(q);
  }
  int C[N][N], C_[N][N];
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(P[i].x < Q[j].x && P[i].y < Q[j].y){
	C[i][j] = 1;
      } else {
	C[i][j] = 0;
      }
      C_[i][j] = 0;
    }
  }

  return 0;
}

