#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main() {
  int M;
  ll K;
  cin >> M >> K;
  if(M == 0) {
    if(K == 0)
      cout << 0 << " " << 0 << endl;
    else
      cout << -1 << endl;
  } else if(M == 1) {
    if(K == 0)
      cout << 0 << " " << 0 << " " << 1 << " " << 1 << endl;
    else
      cout << -1 << endl;
  } else {
    if(K < pow(2, M)) {
      for(int i=0; i<pow(2, M); i++)
	if(i != K)
	  cout << i << ' ';
      cout << K << ' ';
      for(int i=pow(2, M)-1; i>=0; i--)
	if(i != K)
	  cout << i << ' ';
      cout << K << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}

