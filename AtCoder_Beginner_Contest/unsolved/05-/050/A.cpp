#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  ll A, B;
  char op;
  cin >> A >> op >> B;
  if(op == '+')
    cout << A + B << endl;
  else
    cout << A - B << endl;
  return 0;
}

