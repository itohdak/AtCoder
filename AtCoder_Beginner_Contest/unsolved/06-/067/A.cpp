#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define ll long long

int main(){
  int A, B;
  cin >> A >> B;
  if(A % 3 == 0 || B % 3 == 0 || (A+B) % 3 == 0)
    cout << "Possible" << endl;
  else
    cout << "Impossible" << endl;
  return 0;
}

