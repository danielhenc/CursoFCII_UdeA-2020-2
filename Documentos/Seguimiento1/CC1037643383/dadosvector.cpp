#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int main()
{
  srand(time(NULL));
  int tiro;
  int cara1;
  int cara2;
  vector< int > frecuencia(13, 0);

  for (tiro=0; tiro < 36000; tiro++)
    {
      cara1 = 1 + rand() % 6;
      cara2 = 1 + rand() % 6;
      frecuencia[cara1 + cara2]++;
    }
  for (tiro=2; tiro < 13; tiro++)
    {
      cout << setw(4) << tiro << setw(12) << frecuencia[tiro] << endl;
    }

  return 0;
}
  
