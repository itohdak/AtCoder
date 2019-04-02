#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int H, W, h, w;
  cin >> H >> W >> h >> w;
  cout << (H - h) * (W - w) << endl;
  return 0;
}

