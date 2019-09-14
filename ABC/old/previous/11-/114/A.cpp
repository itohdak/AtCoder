#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int X;
  cin >> X;
  if(X == 7 || X == 5 || X == 3)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}

