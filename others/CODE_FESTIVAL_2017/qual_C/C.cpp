#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main(){
  string S;
  cin >> S;
  string S_without_x;
  for(int i=0; i<S.length(); i++)
    if(!(S[i] == 'x'))
      S_without_x += S[i];

  string S_without_x_copy = S_without_x;
  int ret = 0;
  reverse(S_without_x.begin(), S_without_x.end());
  if(!(S_without_x_copy == S_without_x)){
    ret = -1;
  } else {
    int begin = 0, end = S.length()-1;
    while(!(begin >= end)){
      if(S[begin] != 'x' && S[end] != 'x'){
	begin++;
	end--;
      }
      else if(S[begin] == 'x' && S[end] != 'x'){
	begin++;
	ret++;
      }
      else if(S[begin] != 'x' && S[end] == 'x'){
	end--;
	ret++;
      }
      else if(S[begin] == 'x' && S[end] == 'x'){
	begin++;
	end--;
      }
    }
  }

  cout <<  ret << endl;

  return 0;
}

