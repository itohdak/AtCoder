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
  cin >> N;
  if(N < 105)
    cout << 0 << endl;
  else if(N < 135)
    cout << 1 << endl;
  else if(N < 165)
    cout << 2 << endl;
  else if(N < 189)
    cout << 3 << endl;
  else if(N < 195)
    cout << 4 << endl;
  else
    cout << 5 << endl;
  return 0;
}

