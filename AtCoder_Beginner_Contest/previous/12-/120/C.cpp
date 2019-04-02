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
  cin >> S;
  int nRed = 0, nBlue = 0;
  for(int i=0; i<S.size(); i++) {
    if(S[i] == '0')
      nRed++;
    else
      nBlue++;
  }
  cout << min(nRed, nBlue) * 2 << endl;
  return 0;
}

