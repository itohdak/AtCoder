#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
  string str;
  cin >> str;
  if(str[0] == str[1] &&
     str[1] != str[2] &&
     str[2] == str[3])
    cout << "Yes";
  else
    cout << "No";
  cout << endl;
  return 0;
}
