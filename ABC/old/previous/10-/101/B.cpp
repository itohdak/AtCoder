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

int main(){
  ll N;
  cin >> N;
  if(N % S(N) == 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}

