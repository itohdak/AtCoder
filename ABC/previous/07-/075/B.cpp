#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){
  int h, w;
  cin >> h >> w;

  char s[h][w];
  for(int i=0; i<h; i++){
    string in;
    cin >> in;
    for(int j=0; j<w; j++){
      s[i][j] = in[j];
    }
  }

  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      if(s[i][j] == '#'){
  	cout << '#';
      } else {
  	int n = 0;
  	for(int in=i-1; in<=i+1; in++){
  	  for(int jn=j-1; jn<=j+1; jn++){
  	    if(!(in == i && jn == j) && in >= 0 && jn >= 0 && in < h && jn < w)
  	      if(s[in][jn] == '#')
  		n++;
  	  }
  	}
  	cout << n;
      }
    }
    cout << endl;
  }

  return 0;
}

