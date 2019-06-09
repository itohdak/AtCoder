#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

ll S(ll n){
  ll m = n;
  ll sum = 0;
  while(m > 0){
    sum += m % 10;
    m /= 10;
  }
  return sum;
}
double calc(ll x){
  return 1.0 * x / S(x);
}

int main(){
  ll K;
  cin >> K;
  ll N = 1;
  while(K > 0){
    ll next = N;
    if(N < 9){
      next = N + 1;
    } else {
      ll min = 1e+15;
      for(int d=0; d<=log(N)/log(10)+1; d++){
	if(calc((ll)pow(10, d+1) * ceil(N / pow(10, d+1) + 1) - 1) < calc(min))
	  min = (ll)pow(10, d+1) * ceil(N / pow(10, d+1) + 1) - 1;
      }
      next = min;
    }
    cout << N << endl;
    N = next;
    K--;
  }
  return 0;
}

