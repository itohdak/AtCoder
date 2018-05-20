#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define ll long long

int main(){
  int A, B;
  string S;
  cin >> A >> B >> S;
  bool ret = true;
  for(int i=0; i<A; i++)
    if(!isdigit(S[i]))
      ret = false;
  if(!(S[A] == '-'))
    ret = false;
  for(int i=0; i<B; i++)
    if(!isdigit(S[A+1+i]))
      ret = false;
  if(ret)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}

