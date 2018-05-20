#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  int in;
  cin >> in;
  int s1, s2, s3;
  s1 = in / 100;
  s2 = (in / 10) % 10;
  s3 = in % 10;
  cout << s1 + s2 + s3 << endl;
  return 0;
}

