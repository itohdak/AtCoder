#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

ll gcd(ll a, ll b){
  ll c = min(a, b), d = max(a, b);
  while(c != 0){
    ll tmp = c;
    c = d % c;
    d = tmp;
  }
  return d;
}

int main(){
  int T;
  cin >> T;
  cout << endl;
  for(int i=0; i<T; i++){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    bool ok = true;
    if(a < b)
      ok = false;
    else if(b > d)
      ok = false;
    else if(b > c){
      ll g = gcd(b, d);
      ll max = b - g + a % g;
      if(max > c)
	ok = false;
    }
    if(ok)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}

