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
  cin >> S;
  vector<bool> alpha(26, false);
  bool ret = true;
  for(int i=0; i<S.size(); i++){
    if(!alpha[(int)S[i] - (int)'a'])
      alpha[(int)S[i] - (int)'a'] = true;
    else{
      ret = false;
      break;
    }
  }
  if(ret)
    cout << "yes" << endl;
  else
    cout << "no" << endl;
  return 0;
}

