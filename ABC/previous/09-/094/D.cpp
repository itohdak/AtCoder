#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  ll n;
  cin >> n;
  vector<ll> A;
  for(ll i=0; i<n; i++){
    ll in;
    cin >> in;
    A.push_back(in);
  }
  sort(A.begin(), A.end());
  ll max = A[n-1];
  vector<ll>::iterator it1 = A.begin();
  while(*it1 <= floor(max/2) && it1 != A.end()) it1++;
  if(it1 != A.end()) it1--;
  vector<ll>::iterator it2 = A.end(); it2--;
  while(*it2 >= ceil(max/2) && it2 != A.begin()) it2--;
  if(it2 != A.begin()) it2++;

  ll cand1 = *it1;
  ll cand2 = *it2;
  if(max % 2 == 0){
    if(abs(cand1-max/2) <= abs(cand2-max/2)){
      cout << max << ' ' << cand1 << endl;
    } else {
      cout << max << ' ' << cand2 << endl;
    }
  } else {
    if(abs(cand1-(max-1)/2) <= abs(cand2-(max+1)/2)){
      cout << max << ' ' << cand1 << endl;
    } else {
      cout << max << ' ' << cand2 << endl;
    }
  }
  return 0;
}
