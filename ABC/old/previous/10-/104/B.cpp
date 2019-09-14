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
  int N = S.size();
  int count = 0;
  bool low = true;
  for(int i=0; i<N; i++){
    if(S[i] != 'A' && S[i] != 'C' && S[i] >= 'A' && S[i] <= 'Z')
      low = false;
    if(i >= 2 && i <= N-2)
      if(S[i] == 'C')
	count++;
  }
  if(S[0] == 'A' && count == 1 && low)
    cout << "AC" << endl;
  else
    cout << "WA" << endl;
  return 0;
}

