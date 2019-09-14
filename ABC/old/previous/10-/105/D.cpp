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
  int N;
  ll M;
  cin >> N >> M;
  vector<ll> A(N);
  for(int i=0; i<N; i++)
    cin >> A[i];

  vector<ll> B(N+1, 0);
  for(int i=0; i<N; i++)
    B[i+1] = B[i] + A[i];

  map<ll, int> m1;
  vector<ll> m2;
  for(int i=0; i<N+1; i++) {
    ll mod = B[i] % M;
    m1[mod];
    if(m1[mod] == 0)
      m2.push_back(mod);
    m1[mod]++;
  }

  ll ans = 0;
  for(int i=0; i<m2.size(); i++) {
    ll num = m1[m2[i]];
    ans += num * (num - 1) / 2;
  }

  cout << ans << endl;
  return 0;
}

