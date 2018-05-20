#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  string S;
  cin >> S;
  int a = 0, b = 0, c = 0;
  for(int i=0; i<S.size(); i++){
    if(S[i] == 'a') a++;
    else if(S[i] == 'b') b++;
    else if(S[i] == 'c') c++;
  }

  if(abs(a-b) > 1 || abs(b-c) > 1 || abs(c-a) > 1)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;

  return 0;
}
