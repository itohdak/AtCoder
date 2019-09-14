#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define ll long long

ll gcd(ll n1, ll n2){
  if(n2 == 0)
    return n1;
  else
    return gcd(n2, n1 % n2);
}
ll lcm(ll n1, ll n2){
  return n1 / gcd(n1, n2) * n2;
}

int main(){
  int N;
  cin >> N;
  vector<ll> T;
  ll ans = 1;
  for(int i=0; i<N; i++){
    ll in;
    cin >> in;
    ans = lcm(max(ans, in), min(ans, in));
  }
  cout << ans << endl;
  return 0;
}
