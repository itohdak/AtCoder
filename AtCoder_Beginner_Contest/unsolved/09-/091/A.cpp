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
  if(A + B >= C)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}

