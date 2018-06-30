#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int A, B;
  cin >> A >> B;
  if(A + B < 10)
    cout << A + B << endl;
  else
    cout << "error" << endl;
  return 0;
}

