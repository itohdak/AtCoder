#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int D;
ll G;
int P[10];
ll C[10];
int ans = 1000;

void select_problem(int t, int i=0, int n=0, ll tmp=0LL) {
  // cout << t << ' ' << i << ' ' << n << ' ' << tmp << endl;
  if(i == D) {
    // cout << ceil(max((G - tmp), 0LL) / 100.0*(t+1)) << endl;
    if(tmp + 100*(t+1)*P[t] >= G && n + ceil(max((G - tmp), 0LL) / (100.0*(t+1))) < ans) {
      ans = n + ceil(max((G - tmp), 0LL) / (100.0*(t+1)));
    }
    return;
  } else {
    if(i != t)
      select_problem(t, i+1, n+P[i], tmp+100*(i+1)*P[i]+C[i]);
    select_problem(t, i+1, n, tmp);
  }
}

int main(){
  cin >> D >> G;
  for(int i=0; i<D; i++)
    cin >> P[i] >> C[i];
  for(int i=0; i<D; i++)
    select_problem(i);
  cout << ans << endl;
  return 0;
}

