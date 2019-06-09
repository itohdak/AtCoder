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
  cin >> N;
  vector<ll> S;
  ll sum = 0;
  S.push_back(sum);
  int ret = 0;
  for(int i=0; i<N; i++){
    ll in;
    cin >> in;
    sum += in;
    S.push_back(sum);
  }
  sort(S.begin(), S.end());
  int i = 0;
  while(i < N+1){
    int init = i;
    ll s = S[i];
    while(i+1 < N+1 && S[i+1] == s){
      i++;
    }
    ret += ((i - init + 1) * (i - init) / 2);
    i++;
  }
  cout << ret << endl;
  return 0;
}

