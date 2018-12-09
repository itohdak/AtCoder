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
  int count = 0;
  for(int i=1; i<S.size(); i++)
    if(S[i] != S[i-1])
      count++;
  cout << count << endl;
  return 0;
}

