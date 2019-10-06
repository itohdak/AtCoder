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

  if(a * b % 2 == 0)
    cout << "Even" << endl;
  else
    cout << "Odd" << endl;

  return 0;
}

