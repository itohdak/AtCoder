#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  ll K;
  cin >> K;
  vector<ll> A;
  for(ll i=0; i<K; i++){
    ll in;
    cin >> in;
    A.push_back(in);
  }
  reverse(A.begin(), A.end());
  ll N[K+1][2];
  N[0][0] = N[0][1] = 2;
  for(ll i=0; i<K+1; i++){
    ll tmpA = A[i];
    ll min = N[i][0], max = N[i][1];
    if(ceil(min*1.0/tmpA) > floor(max*1.0/tmpA)){
      cout << -1 << endl;
      return 0;
    } else {
      N[i+1][0] = tmpA*ceil(N[i][0]*1.0/tmpA);
      N[i+1][1] = tmpA*floor(N[i][1]*1.0/tmpA)+tmpA-1;
    }
  }
  cout << N[K][0] << ' ' << N[K][1] << endl;
  return 0;
}

