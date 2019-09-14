#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int a, b;
  cin >> a >> b;
  int ans = 0;
  for(int i=0; i<(b - a); i++)
    ans += i+1;
  cout << ans - b << endl;
  return 0;
}

