#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N, M;
  cin >> N >> M;
  vector<ll> v1(N), v2(N), v3(N), v4(N), v5(N), v6(N), v7(N), v8(N);
  for(int i=0; i<N; i++){
    ll x, y, z;
    cin >> x >> y >> z;
    v1[i] = - x - y - z;    v2[i] = - x - y + z;    v3[i] = - x + y - z;    v4[i] = - x + y + z;
    v5[i] = + x - y - z;    v6[i] = + x - y + z;    v7[i] = + x + y - z;    v8[i] = + x + y + z;
  }
  sort(v1.begin(), v1.end(), greater<ll>());  sort(v2.begin(), v2.end(), greater<ll>());
  sort(v3.begin(), v3.end(), greater<ll>());  sort(v4.begin(), v4.end(), greater<ll>());
  sort(v5.begin(), v5.end(), greater<ll>());  sort(v6.begin(), v6.end(), greater<ll>());
  sort(v7.begin(), v7.end(), greater<ll>());  sort(v8.begin(), v8.end(), greater<ll>());
  ll ans = accumulate(v1.begin(), v1.begin()+M, 0LL);
  ans = max(ans, accumulate(v2.begin(), v2.begin()+M, 0LL));
  ans = max(ans, accumulate(v3.begin(), v3.begin()+M, 0LL));
  ans = max(ans, accumulate(v4.begin(), v4.begin()+M, 0LL));
  ans = max(ans, accumulate(v5.begin(), v5.begin()+M, 0LL));
  ans = max(ans, accumulate(v6.begin(), v6.begin()+M, 0LL));
  ans = max(ans, accumulate(v7.begin(), v7.begin()+M, 0LL));
  ans = max(ans, accumulate(v8.begin(), v8.begin()+M, 0LL));

  cout << ans << endl;
  return 0;
}

