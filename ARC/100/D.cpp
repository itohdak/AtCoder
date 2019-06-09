#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)
#include <functional>

using namespace std;
#define ll long long

int main(){
  int N;
  cin >> N;
  vector<ll> A(N);
  for(int i=0; i<N; i++)
    cin >> A[i];
  vector<ll> sum(N, 0LL);
  sum[0] = A[0];
  for(int i=1; i<N; i++){
    sum[i] += sum[i-1] + A[i];
  }
  vector<int> L(N, 0);
  vector<int> R(N, 0);
  int mid = 0;
  for(int i=0; i<N; i++){
    while(sum[mid] < sum[i] - sum[mid] && mid < i)
      mid++;
    int best;
    if(mid == 0)
      best = mid;
    else
      if(abs(sum[mid] - (sum[i] - sum[mid])) < abs(sum[mid-1] - (sum[i] - sum[mid-1])))
	best = mid;
      else
	best = mid-1;
    L[i] = best;
  }
  mid = 0;
  for(int i=0; i<N; i++){
    while(sum[mid] - sum[i] < sum[N-1] - sum[mid] && mid < N-1)
      mid++;
    int best;
    if(mid == 0)
      best = mid;
    else
      if(abs((sum[mid] - sum[i]) - (sum[N-1] - sum[mid])) < abs((sum[mid-1] - sum[i]) - (sum[N-1] - sum[mid-1])))
	best = mid;
      else
	best = mid-1;
    R[i] = best;
  }
  ll ans = 1e+15;
  for(int i=1; i<N-2; i++){
    vector<ll> num(4);
    num[0] = sum[L[i]];
    num[1] = sum[i] - sum[L[i]];
    num[2] = sum[R[i]] - sum[i];
    num[3] = sum[N-1] - sum[R[i]];
    ll max_num = *max_element(num.begin(), num.end());
    ll min_num = *min_element(num.begin(), num.end());
    if(max_num - min_num < ans){
      ans = max_num - min_num;
    }
  }
  cout << ans << endl;
  return 0;
}

