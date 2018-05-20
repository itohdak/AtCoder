#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  string candidates[16] = {"AKIHABARA", "AKIHABAR", "AKIHABRA", "AKIHABR",
			   "AKIHBARA", "AKIHBAR", "AKIHBRA", "AKIHBR",
			   "KIHABARA", "KIHABAR", "KIHABRA", "KIHABR",
			   "KIHBARA", "KIHBAR", "KIHBRA", "KIHBR"};
  string S;
  cin >> S;
  bool there_is = false;
  for(int i=0; i<16; i++){
    if(S == candidates[i]){
      there_is = true;
      break;
    }
  }
  if(there_is){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}

