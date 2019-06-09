#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  int A, B;
  string S;
  cin >> A >> B >> S;
  if(S.size() >= A && S.size() <= B)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}

