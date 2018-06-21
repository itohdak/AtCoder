#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>

using namespace std;
#define ll long long

int main(){
  ll N;
  cin >> N;
  vector<ll> A;
  ll x = 0, y = 0;
  for(int i=0; i<N; i++){
    ll a;
    cin >> a;
    A.push_back(a);
    if(i == 0)
      x += a;
    else
      y += a;

  }
  ll min = 100000000000;
  ll tmp;
  for(int i=1; i<N; i++){
    tmp = abs(x - y);
    // cout << x << ' ' << y << ' ' << tmp << endl;
    if(tmp < min){
      min = tmp;
    }
    x += A[i];
    y -= A[i];
  }
  cout << min << endl;
  return 0;
}

