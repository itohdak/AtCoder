#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
  string S_, T;
  cin >> S_ >> T;
  int ls = S_.length();
  int lt = T.length();
  string S = S_;

  bool found = false;
  for(int i=ls-lt; i>=0; i--){
    bool possible = true;
    for(int j=0; j<lt; j++){
      if(S_[i+j] != '?' && T[j] != S_[i+j]){
	possible = false;
	break;
      }
    }
    if(possible){
      for(int j=0; j<ls; j++){
	if(S[j] == '?'){
	  S[j] = 'a';
	}
      }
      for(int j=0; j<lt; j++){
	S[i+j] = T[j];
      }
      found = true;
      break;
    }
  }

  if(found){
    cout << S << endl;
  } else {
    cout << "UNRESTORABLE"<< endl;
  }

  return 0;
}
