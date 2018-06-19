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
  vector<int> alpha(26, 0);
  for(int i=0; i<S.size(); i++){
    alpha[(int)S[i] - (int)'a']++;
  }
  string ans = "None";
  for(int i=0; i<26; i++){
    if(alpha[i] == 0){
      ans = (char)((int)'a' + i);
      break;
    }
  }
  cout << ans << endl;
  return 0;
}

