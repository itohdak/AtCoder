#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

ll gcd(ll x, ll y) {
  if(x > y)
    return gcd(y, x);
  else if(x == 0)
    return y;
  else
    return gcd(y % x, x);
}

int main(){
  int N;
  cin >> N;
  vector<ll> T(N);
  for(int i=0; i<N; i++)
    cin >> T[i];
  sort(T.begin(), T.end());
  vector<ll> D(N-1), D2(N-2);
  for(int i=0; i<N-1; i++)
    D[i] = T[i+1] - T[i];
  sort(D.begin(), D.end());
  for(int i=0; i<N-2; i++)
    D2[i] = T[i+2] - T[i];
  sort(D2.begin(), D2.end());

  ll tmp = D[0];
  ll tmpGcd = D[0];
  for(int i=1; i<N-1; i++)
    tmpGcd = gcd(tmpGcd, D[i]);
  cout << tmpGcd << endl;
  // for(int i=0; i<N-1; i++)
  //   cout << D[i]<< ' ';
  // cout << endl;
  // for(int i=0; i<N-2; i++)
  //   cout << D2[i]<< ' ';
  // cout << endl;
  return 0;
}

