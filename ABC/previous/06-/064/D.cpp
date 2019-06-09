#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N;
  string S;
  cin >> N >> S;
  int countl = 0, countr = 0;
  int lastl = -1;
  int add = 0;
  string ans;
  for(int i=0; i<N; i++){
    if(S[i] == '('){
      countl++;
      ans += S[i];
      lastl = i + add;
    } else {
      if(countl < countr+1){
	ans = '(' + ans;
	countl++;
	lastl++;
	add++;
      }
      countr++;
      ans += S[i];
    }
  }
  for(int i=0; i<countl-countr; i++)
    ans += ')';
  cout << ans << endl;
  return 0;
}
