#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int n;
  cin >> n;
  vector<ll> A(n);
  ll sum_p = 0LL;
  ll sum_n = 0LL;
  ll ans_p = 0LL;
  ll ans_n = 0LL;
  for(int i=0; i<n; i++) {
    cin >> A[i];
    sum_p += A[i];
    sum_n += A[i];
    if(i % 2 == 0) {
      if(sum_p <= 0) {
	ans_p += abs(1 - sum_p);
	sum_p += 1 - sum_p;
      }
      if(sum_n >= 0) {
	ans_n += abs(- 1 - sum_n);
	sum_n += - 1 - sum_n;
      }
    } else {
      if(sum_p >= 0) {
	ans_p += abs(- 1 - sum_p);
	sum_p += - 1 - sum_p;
      }
      if(sum_n <= 0) {
	ans_n += abs(1 - sum_n);
	sum_n += 1 - sum_n;
      }
    }
  }
  cout << min(ans_p, ans_n) << endl;
  return 0;
}

