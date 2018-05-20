#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int Deg, Dis;
  cin >> Deg >> Dis;
  float dis = round(Dis / 60.0 * 10) / 10.0;
  if(dis <= 0.2) cout << "C";
  else if(Deg < 112.5) cout << "N";
  else if(Deg < 337.5) cout << "NNE";
  else if(Deg < 562.5) cout << "NE";
  else if(Deg < 787.5) cout << "ENE";
  else if(Deg < 1012.5) cout << "E";
  else if(Deg < 1237.5) cout << "ESE";
  else if(Deg < 1462.5) cout << "SE";
  else if(Deg < 1687.5) cout << "SSE";
  else if(Deg < 191.25) cout << "S";
  else if(Deg < 2137.5) cout << "SSW";
  else if(Deg < 2362.5) cout << "SW";
  else if(Deg < 2587.5) cout << "WSW";
  else if(Deg < 2812.5) cout << "W";
  else if(Deg < 3037.5) cout << "WNW";
  else if(Deg < 3262.5) cout << "NW";
  else if(Deg < 3487.5) cout << "NNW";
  else cout << "N";
  cout << ' ';
  if(dis <= 0.2) cout << 0;
  else if(dis <= 1.5) cout << 1;
  else if(dis <= 3.3) cout << 2;
  else if(dis <= 5.4) cout << 3;
  else if(dis <= 7.9) cout << 4;
  else if(dis <= 10.7) cout << 5;
  else if(dis <= 13.8) cout << 6;
  else if(dis <= 17.1) cout << 7;
  else if(dis <= 20.7) cout << 8;
  else if(dis <= 24.4) cout << 9;
  else if(dis <= 28.4) cout << 10;
  else if(dis <= 32.6) cout << 11;
  else cout << 12;
  cout << endl;
  return 0;
}

