#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  string S;
  string tmp = "keyence";
  cin >> S;
  bool ret = false;
  for(int i=0; i<S.size(); i++) {
    for(int j=i; j<S.size(); j++) {
      string trgt = S.substr(0, i) + S.substr(j, S.size());
      if(trgt == tmp) {
	ret = true;
	break;
      }
    }
  }
  if(ret)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}

