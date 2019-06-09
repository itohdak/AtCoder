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
  if(S.substr(0,3) == "yah" & S[3] == S[4])
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}

