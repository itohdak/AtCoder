#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N;
  cin >> N;
  vector<int> H(N);
  for(int i=0; i<N; i++)
    cin >> H[i];
  int tmpMax = -1;
  int ans = 0;
  for(int i=0; i<N; i++) {
    if(tmpMax <= H[i]) {
      ans++;
      tmpMax = H[i];
    }
  }
  cout << ans << endl;
  return 0;
}

