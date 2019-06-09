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
  int low = 0, high = N-1;
  while(low < high){
    int mid = (low + high) / 2;
    if(sum[N-1] - sum[mid] > sum[mid])
      low = mid + 1;
    else
      high = mid;
  }

  ll ans = 1e+15;
  int margin = 5;
  for(int i=max(high-margin, 1); i<min(high+margin, N-2); i++){
    int l1=0, h1=i-1;
    int l2=i+1, h2=N-1;
    while(l1 < h1){
      int mid = (l1 + h1) / 2;
      if(sum[i] - sum[mid] > sum[mid])
	l1 = mid + 1;
      else
	h1 = mid;
    }
    while(l2 < h2){
      int mid = (l2 + h2) / 2;
      if(sum[N-1] - sum[mid] > sum[mid] - sum[i])
	l2 = mid + 1;
      else
	h2 = mid;
    }
    for(int j=max(h1-margin, 0); j<min(h1+margin, i); j++){
      for(int k=max(h2-margin, i+1); k<min(h2+margin, N-1); k++){
	vector<ll> num(4);
	num[0] = sum[j];
	num[1] = sum[i] - sum[j];
	num[2] = sum[k] - sum[i];
	num[3] = sum[N-1] - sum[k];
	ll max_num = *max_element(num.begin(), num.end());
	ll min_num = *min_element(num.begin(), num.end());
	if(max_num - min_num < ans){
	  ans = max_num - min_num;
	}
      }
    }
  }
  cout << ans << endl;
  return 0;
}

