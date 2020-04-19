#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){
  string S;
  cin >> S;
  bool ret = false;

  for(int i=0; i<S.length(); i++)
    if(S[i] == 'A' && S[i+1] == 'C'){
      ret = true;
      break;
    }

  if(ret)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}

