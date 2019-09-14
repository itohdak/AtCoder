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
  int ret = 0;
  for(int i=0; i<4; i++)
    if(S[i] == '+')
      ret++;
    else
      ret--;
  cout << ret << endl;
  return 0;
}

