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
  if(K % 2 == 0) { // even
    ll n1 = N / K;
    ll n2 = N / (K / 2) - n1;
    cout << n1*n1*n1 + n2*n2*n2 << endl;
  } else { // odd
    ll n = N / K;
    cout << n*n*n << endl;
  }
  return 0;
}

