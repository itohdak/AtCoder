#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N, K;
  cin >> N >> K;
  vector<ll> H(N);
  for(int i=0; i<N; i++)
    cin >> H[i];
  sort(H.begin(), H.end());
  // for(int i=0; i<N; i++)
  //   cout << H[i] << ' ';
  // cout << endl;
  ll ans = 1000000000;
  for(int i=0; i<N-K+1; i++) {
    if(H[i+K-1] - H[i] < ans)
      ans = H[i+K-1] - H[i];
  }
  cout << ans << endl;
  return 0;
}

