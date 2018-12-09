#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int A, B, C;
  cin >> A >> B >> C;
  bool ret = false;
  for(int i=1; i<=B; i++)
    if((A * i) % B == C) {
      ret = true;
      break;
    }
  if(ret)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}

