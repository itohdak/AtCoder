#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  string sin;
  cin >> sin;
  string sout = "";
  for(int i=0; i<sin.size(); i++)
    if(i % 2 == 0)
      sout += sin[i];
  cout << sout << endl;
  return 0;
}

