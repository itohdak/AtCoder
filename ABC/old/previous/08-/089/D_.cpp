#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int px[90001], py[90001];
int d[90001];

int main(){
  int H, W, D;
  cin >> H >> W >> D;
  for(int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      int in;
      cin >> in;
      px[in] = i;
      py[in] = j;
    }
  }
  for(int i=D+1; i<=H*W; i++)
    d[i] = d[i-D] + abs(px[i] - px[i-D]) + abs(py[i] - py[i-D]);
  int Q;
  cin >> Q;
  for(int i=0; i<Q; i++){
    int l, r;
    cin >> l >> r;
    cout << d[r] - d[l] << endl;
  }
  return 0;
}

