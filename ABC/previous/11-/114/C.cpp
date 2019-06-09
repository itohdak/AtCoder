#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long
int ans = 0;
ll N;

int digit(ll N) {
  int res = 0;
  while(N > 0) {
    res++;
    N /= 10;
  }
  return res;
}

bool all_used(int n) {
  bool ret[3];
  ret[0] = ret[1] = ret[2] = false;
  while(n > 0) {
    switch(n%10) {
    case 3:
      ret[0] = true;
      break;
    case 5:
      ret[1] = true;
      break;
    case 7:
      ret[2] = true;
      break;
    }
    n /= 10;
  }
  return ret[0] && ret[1] && ret[2];
}

void work(int tmp, int n) {
  if(tmp <= N) {
    if(all_used(tmp)) {
      ans++;
    }
    if(n <= 0)
      return;
    work(tmp*10+3, n-1);
    work(tmp*10+5, n-1);
    work(tmp*10+7, n-1);
  }
}

int main(){
  cin >> N;
  int d = digit(N);
  work(3, d-1);
  work(5, d-1);
  work(7, d-1);

  cout << ans << endl;
  return 0;
}

