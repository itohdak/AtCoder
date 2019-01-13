#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  cout << (char)toupper(s1[0]) << (char)toupper(s2[0]) << (char)toupper(s3[0]) << endl;
  return 0;
}

