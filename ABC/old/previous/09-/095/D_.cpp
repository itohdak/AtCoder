#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  ll N, C;
  cin >> N >> C;
  vector<ll> X, V;
  bool flag[N];
  for(ll i=0; i<N; i++){
    ll x, v;
    cin >> x >> v;
    X.push_back(x);
    V.push_back(v);
    flag[i] = true;
  }
  ll pos = 0;
  ll ret = 0;
  while(1){
    ll maxv = -10000;
    ll maxi = -1;
    for(int i=0; i<N; i++){
      if(flag[i]){
	if(V[i] - min(abs(X[i]-pos), C-abs(X[i]-pos)) > maxv){
	  maxv = V[i] - min(abs(X[i]-pos), C-abs(X[i]-pos));
	  maxi = i;
	}
      }
    }
    if(maxv < 0){
      break;
    } else {
      for(int i=0; i<N; i++){
	if(flag[i]){
	  if((X[maxi] > pos && X[maxi]-pos == min(abs(X[maxi]-pos), C-abs(X[maxi]-pos)) &&
	      X[i] > pos && X[i] < X[maxi]) ||
	     (X[maxi] < pos && pos-X[maxi] == min(abs(X[maxi]-pos), C-abs(X[maxi]-pos)) &&
	      X[i] < pos && X[i] > X[maxi]) ||
	     (X[maxi] < pos && pos-X[maxi] == max(abs(X[maxi]-pos), C-abs(X[maxi]-pos)) &&
	      (X[i] > pos || X[i] < X[maxi])) ||
	     (X[maxi] > pos && X[maxi]-pos == max(abs(X[maxi]-pos), C-abs(X[maxi]-pos)) &&
	      (X[i] < pos || X[i] > X[maxi]))
	     ){
	    ret += V[i];
	    flag[i] = false;
	  }
	}
      }
      ret += maxv;
      flag[maxi] = false;
      pos = X[maxi];
    }
  }
  cout << ret << endl;
  return 0;
}
