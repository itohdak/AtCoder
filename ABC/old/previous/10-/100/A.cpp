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
  if(A <= 8 && B <= 8)
    cout << "Yay!" << endl;
  else
    cout << ":(" << endl;
  return 0;
}

