#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

using namespace std;

int main(){
  string S;
  cin >> S;
  int len = S.length();
  int a[len];
  for(int i=0; i<len; i++){
    char s = S[i];
    if(i == 0)
      a[i] = 1 << (int(s) -97);
    else
      a[i] = a[i-1] + (1 << (int(s) - 97));
  }



  return 0;
}

