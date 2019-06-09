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
  vector<ll> A(N);
  for(int i=0; i<N; i++){
    cin >> A[i];
    A[i] -= i+1;
  }
  sort(A.begin(), A.end());
  vector<ll> sum(N, 0LL);
  sum[0] = A[0];
  for(int i=1; i<N; i++){
    sum[i] += sum[i-1] + A[i];
  }
  // for(int i=0; i<N; i++)
  //   cout << A[i] << ' ';
  // cout << endl;
  // for(int i=0; i<N; i++)
  //   cout << sum[i] << ' ';
  // cout << endl;
  ll ans = 1e+15;
  for(int i=0; i<N; i++){
    ll b = A[i];
    ll tmp = (sum[N-1] - sum[i]) - sum[i] - b * (N-(i+1)-(i+1));
    if(tmp < ans)
      ans = tmp;
  }
  cout << ans << endl;
  return 0;
}

