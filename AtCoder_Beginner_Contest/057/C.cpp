#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

vector<ll> divisor;
void find_divisor(ll N) {
  for(int i=1; i<=sqrt(N); i++) {
    if(N % i == 0)
      divisor.push_back(i);
  }
  int n = divisor.size();
  for(int i=n-1; i>=0; i--) {
    if(N != (ll)pow(divisor[i], 2))
      divisor.push_back(N / divisor[i]);
  }
}
int digit(ll N) {
  ll n = N;
  int ret = 0;
  while(n > 0) {
    ret++;
    n /= 10;
  }
  return ret;
}

int main(){
  ll N;
  cin >> N;
  find_divisor(N);
  int n = divisor.size();
  for(int i=0; i<n; i++)
    divisor[i] = digit(divisor[i]);
  int ret = 100;
  for(int i=0; i<(n+1)/2; i++) {
    if(divisor[n-1-i] < ret)
      ret = divisor[n-1-i];
  }
  cout << ret << endl;
  return 0;
}

