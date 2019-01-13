#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)
#include <map>

using namespace std;
#define ll long long

int main(){
  int H, W, N;
  cin >> H >> W >> N;
  vector< vector<int> > XY(H);
  for(int i=0; i<N; i++) {
    int x, y;
    cin >> x >> y;
    XY[x-1].push_back(y-1);
  }
  for(int i=0; i<H; i++)
    sort(XY[i].begin(), XY[i].end());

  int ans = H;
  for(int i=0; i<H; i++) {
    for(int j=0; j<XY[i].size(); j++) {
      if(XY[i][j] <= i) {
	ans = i+1;
	break;
      }
    }
    if(ans != H)
      break;
  }

  // for(int i=0; i<H; i++) {
  //   for(int j=0; j<XY[i].size(); j++) {
  //     cout << XY[i][j] << ' ';
  //   }
  //   cout << endl;
  // }

  cout << ans << endl;
  return 0;
}

