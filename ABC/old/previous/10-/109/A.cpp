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
  if(A % 2 == 0 || B % 2 == 0)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
  return 0;
}

