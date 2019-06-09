#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int A, B, X;
  cin >> A >> B >> X;
  if(A <= X && X <= A + B)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}

