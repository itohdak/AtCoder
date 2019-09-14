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
  int num;
  if(b < 10)
    num = a * 10 + b;
  else if(b < 100)
    num = a * 100 + b;
  else
    num = a * 1000 + b;

  int root = floor(sqrt(num));
  if(num == root * root)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}

