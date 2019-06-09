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
  int cnt = 0;
  for(int i=0; i<N; i++)
    if((i % 2 == 0 && S[i] == '0') ||
       (i % 2 == 1 && S[i] == '1'))
      cnt++;
  cout << min(N-cnt, cnt) << endl;
  return 0;
}

