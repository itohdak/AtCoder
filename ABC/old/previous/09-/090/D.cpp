#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  ll N, K;
  cin >> N >> K;
  ll ret = 0;
  if(K == 0){
    cout << N * N << endl;
  } else {
    for(ll i=K+1; i<=N; i++){ // b
      for(ll j=0; j<=N/i; j++){ // a/b
	if(j == N/i){
	  ret += max(N - i * j - K + 1, (ll)0);
	} else {
	  ret += i - K;
	}
      }
    }
    cout << ret << endl;
  }
  return 0;
}
