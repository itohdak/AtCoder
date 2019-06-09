#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

void solve(vector<int> H, int begin, int end, int lower, int& ans) {
  if(end != begin) {
    vector<int>::iterator minItr = min_element(H.begin()+begin, H.begin()+end);
    int minH = *minItr;
    ans += minH - lower;
    int tmp = begin;
    for(int i=begin; i<end; i++) {
      if(H[i] == minH) {
	solve(H, tmp, i, minH, ans);
	while(i < end && H[i] == minH)
	  i++;
	tmp = i;
      }
    }
    solve(H, tmp, end, minH, ans);
  }
}

int main(){
  int N;
  cin >> N;
  vector<int> H(N);
  for(int i=0; i<N; i++)
    cin >> H[i];
  int ans = 0;
  solve(H, 0, N, 0, ans);
  cout << ans << endl;
  return 0;
}

