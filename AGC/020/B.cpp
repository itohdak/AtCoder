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
  vector<ll> N[K];
  N[0].push_back(2);
  for(ll i=0; i<K-1; i++){
    ll tmpA = A[i];
    int size = N[i].size();
    if(size == 0){
      cout << -1 << endl;
      return 0;
    } else if (size == 1){
      ll tmpN = N[i][0];
      if(tmpN % tmpA == 0){
	if((ll)ceil(tmpN*1.0/A[i+1]) <= (ll)floor((tmpN+tmpA-1)*1.0/A[i+1])){
	  N[i+1].push_back(A[i+1]*(ll)ceil(tmpN*1.0/A[i+1]));
	  if((ll)ceil(tmpN*1.0/A[i+1]) != (ll)floor((tmpN+tmpA-1)*1.0/A[i+1])){
	    N[i+1].push_back(A[i+1]*(ll)floor((tmpN+tmpA-1)*1.0/A[i+1]));
	  }
	}
      }
    } else {
      ll tmpNmin = N[i][0], tmpNmax = N[i][1];
      N[i+1].push_back(A[i+1]*(ll)ceil(tmpNmin*1.0/A[i+1]));
      N[i+1].push_back(A[i+1]*(ll)floor((tmpNmax+tmpA-1)*1.0/A[i+1]));
    }
  }
  if(N[K-1].size() == 0){
    cout << -1 << endl;
  } else if(N[K-1].size() == 1){
    cout << N[K-1][0] << ' ' << N[K-1][0]+A[K-1]-1 << endl;
  } else {
    cout << N[K-1][0] << ' ' << N[K-1][1]+A[K-1]-1 << endl;
  }
  return 0;
}

