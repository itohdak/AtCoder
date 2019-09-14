#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int m;
  cin >> m;
  double M = m / 1000.0;
  if(M < 0.1){
    cout << "00" << endl;
  } else if(M >= 0.1 && M <= 5){
    int tmp = M * 10;
    cout << tmp / 10 << tmp % 10 << endl;
  } else if(M >= 6 && M <= 30){
    cout << M + 50 << endl;
  } else if(M >= 35 && M <= 70){
    cout << (M - 30) / 5 + 80 << endl;
  } else if(M > 70){
    cout << 89 << endl;
  }
  return 0;
}

