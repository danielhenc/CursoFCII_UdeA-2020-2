#include <string>

using namespace std;

class cuadratica
{
public:

  cuadratica(float, float, float);
  bool discriminante();
  void calculoResultado();
  void imprimirResultado();
  
 private:
  
  float a;
  float b;
  float c;
  float x1=0;
  float x2=0;
  float x1r=0;
  float x2r=0;
  float x1i=0;
  float x2i=0;
  float disc = 0;
  bool condition = true;
};
