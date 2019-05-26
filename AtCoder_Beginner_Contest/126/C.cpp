#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)
#include <iomanip>

using namespace std;
#define ll long long

int main() {
  int N, K;
  cin >> N >> K;
  double ans = 0;
  for(int i=1; i<=N; i++) {
    if(i >= K)
      ans += 1.0 / N;
    else
      ans += 1.0 / N * pow(0.5, ceil(log2(1.0 * K / i)));
  }
  cout << setprecision(15) << ans << endl;
  return 0;
}

