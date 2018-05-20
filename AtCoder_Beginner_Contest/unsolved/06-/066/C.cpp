#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <deque>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int n;
  cin >> n;
  deque<int> ret;
  bool tmp;
  if(n % 2 == 0)
    tmp = false;
  else
    tmp = true;
  for(int i=0; i<n; i++){
    int in;
    cin >> in;
    if(tmp){
      ret.push_front(in);
      tmp = false;
    } else {
      ret.push_back(in);
      tmp = true;
    }
  }
  for(int i=0; i<n; i++)
    cout << ret[i] << " ";
  cout << endl;
  return 0;
}

