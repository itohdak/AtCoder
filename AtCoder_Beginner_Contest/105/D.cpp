#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N;
  ll M;
  cin >> N >> M;
  vector<ll> A(N);
  for(int i=0; i<N; i++)
    cin >> A[i];

  vector<ll> B(N+1, 0);
  for(int i=0; i<N; i++)
    B[i+1] = B[i] + A[i];

  ll ans = 0LL;
  vector< vector<ll> > memo(N, vector<ll>(0));
  for(int i=0; i<N; i++){
    ll tmp = A[i];
    if(i != 0){
      for(int j=0; j<memo[i-1].size(); j++){
	if(memo[i-1][j]%M == 0)
	  ans++;
	memo[i].push_back((memo[i-1][j]+tmp)%M);
      }
    }
    memo[i].push_back(tmp%M);
  }
  for(int j=0; j<memo[N-1].size(); j++)
    if((memo[N-1][j])%M == 0)
      ans++;

  cout << ans << endl;
  return 0;
}

