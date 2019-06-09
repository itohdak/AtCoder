#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  vector<int> height(W, 0);
  for(int i=0; i<H; i++) {
    cin >> S[i];
    for(int j=0; j<W; j++) {
      if(S[i][j] == '#' && height[j] == 0)
	height[j] = H-i;
    }
  }

  // for(int i=0; i<W; i++)
  //   cout << height[i] << ' ';
  // cout << endl;

  int ans = 0;
  for(int i=0; i<W-1; i++)
    ans += max(0, height[i+1]-height[i]);
  cout << ans << endl;
  return 0;
}

