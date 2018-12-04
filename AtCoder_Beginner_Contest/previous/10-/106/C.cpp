#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  string S;
  ll K;
  cin >> S >> K;
  vector<ll> N(100, 0L);
  int count = 0;
  while(count < (int)S.size()) {
    if(S[count] == '1')
      count++;
    else
      break;
  }
  if(K <= count || count == (int)S.size())
    cout << '1' << endl;
  else
    cout << S[count] << endl;
  return 0;
}

