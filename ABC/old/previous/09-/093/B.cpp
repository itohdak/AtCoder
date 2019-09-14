#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  ll A, B;
  int K;
  cin >> A >> B >> K;
  if(A+K <= B-K+1){
    for(ll i=A; i<A+K; i++)
      cout << i << endl;
    for(ll i=B-K+1; i<=B; i++)
      cout << i << endl;
  } else {
    for(ll i=A; i<=B; i++)
      cout << i << endl;
  }
  return 0;
}

