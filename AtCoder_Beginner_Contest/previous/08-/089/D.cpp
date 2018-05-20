#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

struct pos{
  int x;
  int y;
};

int main(){
  int H, W, D;
  cin >> H >> W >> D;
  pos P[H*W];
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      int in;
      cin >> in;
      in--;
      pos p = {i, j};
      P[in] = p;
    }
  }

  int C[H*W]; // cost
  for(int i=0; i<H*W; i++){
    if(i < D){
      C[i] = 0;
    } else {
      C[i] = C[i-D] + abs(P[i-D].x - P[i].x) + abs(P[i-D].y - P[i].y);
    }
  }

  int Q;
  cin >> Q;
  for(int i=0; i<Q; i++){
    int l, r;
    cin >> l >> r;
    cout << C[r-1] - C[l-1] << endl;
  }

  // int C[H*W][H*W]; // cost
  // for(int i=0; i<H*W; i++){
  //   for(int j=0; j<H*W; j++){
  //     C[i][j] = 0;
  //   }
  // }

  // for(int i=0; i<D; i++){
  //   for(int j=i; j<H*W-D; j+=D){
  //     C[j][j] = 0;
  //     pos ps = P[j], pd = P[j+D];
  //     int psx = ps.x, psy = ps.y;
  //     int pdx = pd.x, pdy = pd.y;
  //     int cost = abs(psx-pdx) + abs(psy-pdy);
  //     for(int k=j; k>=0; k-=D)
  // 	C[k][j+D] = C[k][j] + cost;
  //   }
  // }

  // int Q;
  // cin >> Q;
  // for(int i=0; i<Q; i++){
  //   int l, r;
  //   cin >> l >> r;
  //   cout << C[l-1][r-1] << endl;
  // }

  return 0;
}

