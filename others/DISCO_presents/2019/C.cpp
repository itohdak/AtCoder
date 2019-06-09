#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long
#define mod 1000000007

ll count(int n) {
  ll ret = 1L;
  ll ret2 = 1L;
  for(int i=0; i<10; i++) {
    ret *= n;
    ret %= mod;
    ret2 *= (n-1);
    ret2 %= mod;
  }
  return (ret - ret2) % mod;
}

int main(){
  int N;
  cin >> N;
  ll ret = 0L;
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N/i; j++){
      ret += (count(i) * count(j)) % mod;
      ret %= mod;
    }
  }
  cout << ret << endl;
  return 0;
}

