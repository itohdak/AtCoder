#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  string in1, in2;
  cin >> in1 >> in2;
  if(in1[0] == in2[2] &&
     in1[1] == in2[1] &&
     in1[2] == in2[0])
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}

