#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)
#include <set>

using namespace std;
#define ll long long

int f(int s) {
  if(s % 2 == 0)
    return s / 2;
  else
    return 3 * s + 1;
}

int main(){
  int s;
  cin >> s;
  int i = 1;
  set<int> S;
  while(true) {
    if(S.find(s) != S.end()) {
      cout << i << endl;
      break;
    } else {
      S.insert(s);
      s = f(s);
      i++;
    }
  }
  return 0;
}

