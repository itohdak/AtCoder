#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main() {
  int N, K;
  cin >> N >> K;
  vector<ll> V(N);
  for(int i=0; i<N; i++)
    cin >> V[i];
  ll ans = 0;
  for(int i=0; i<=min(N, K); i++) {
    for(int j=0; j<=min(N, K)-i; j++) {
      vector<ll> tmp(i);
      copy(V.begin(), V.begin()+i, tmp.begin());
      vector<ll> tmp2(j);
      copy(V.end()-j, V.end(), tmp2.begin());
      tmp.insert(tmp.end(), tmp2.begin(), tmp2.end());

      // for(int k=0; k<tmp.size(); k++)
      // 	cout << tmp[k] << ' ';
      // cout << endl;

      sort(tmp.begin(), tmp.end());
      int tmp3 = lower_bound(tmp.begin(), tmp.end(), 0) - tmp.begin();
      ans = max(ans, accumulate(tmp.begin()+min(tmp3, K-i-j), tmp.end(), 0LL));
    }
  }
  cout << ans << endl;
  return 0;
}

