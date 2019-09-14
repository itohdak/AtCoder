#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N, T;
  cin >> N >> T;
  vector<int> c(N), t(N);
  int ans = 1001;
  for(int i=0; i<N; i++) {
    cin >> c[i] >> t[i];
    if(t[i] <= T && ans > c[i]) {
      ans = c[i];
    }
  }
  if(ans == 1001)
    cout << "TLE" << endl;
  else
    cout << ans << endl;
  return 0;
}

