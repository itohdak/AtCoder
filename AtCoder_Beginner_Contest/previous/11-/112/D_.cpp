#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

/*
  約数
*/
vector<ll> divisor;
void find_divisor(ll N) {
  for(int i=1; i<ceil(sqrt(N))+1; i++) {
    if(N % i == 0)
      divisor.push_back(i);
  }
  int n = divisor.size();
  for(int i=n-1; i>=0; i--) {
    if(N != (ll)pow(divisor[i], 2))
      divisor.push_back(N / divisor[i]);
  }
}

int main(){
  int N;  ll M;
  cin >> N >> M;
  find_divisor(M);
  for(int i=divisor.size()-1; i>=0; i--) {
    if(divisor[i] * N <= M) {
      cout << divisor[i] << endl;
      break;
    }
  }
  return 0;
}

