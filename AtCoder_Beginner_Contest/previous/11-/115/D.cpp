#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

ll count(int l, ll n, ll ret) { // n >= 0
  if(n == 0)
    return ret;
  if(l == 0) // n == 1
    return ret + 1;
  if(n >= (((ll)pow(2,l+2)-3)-1)/2) {
    if(n >= (((ll)pow(2,l+2)-3)+1)/2) {
      return count(l-1, n-(((ll)pow(2,l+2)-3)+1)/2, ret+(ll)pow(2,l)-1+1);
    } else { // n == (((ll)pow(2,l+2)-3)-1)/2
      return ret+(ll)pow(2,l)-1;
    }
  } else {
    return count(l-1, max(n-1, 0LL), ret);
  }
}

int main(){
  int N;
  ll X;
  cin >> N >> X;
  cout << count(N, X, 0LL) << endl;
  return 0;
}

