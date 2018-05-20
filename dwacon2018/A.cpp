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
  if(S[0] == S[2] && S[1] == S[3])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}

