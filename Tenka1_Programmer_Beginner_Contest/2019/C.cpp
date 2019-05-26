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
  string S;
  cin >> N >> S;
  vector<int> white(N+1), black(N+1);
  for(int i=1; i<N+1; i++) {
    white[i] = white[i-1];
    black[i] = black[i-1];
    if(S[i-1] == '.')
      white[i]++;
    else
      black[i]++;
  }
  int ans = N+1;
  for(int i=0; i<N+1; i++) {
    ans = min(ans, black[i]+(white[N]-white[i]));
  }
  cout << ans << endl;
  return 0;
}

