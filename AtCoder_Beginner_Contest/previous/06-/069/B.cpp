#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define ll long long

int main(){
  string s;
  cin >> s;
  int len = s.size();
  cout << s[0] << len-2 << s[len-1] << endl;
  return 0;
}

