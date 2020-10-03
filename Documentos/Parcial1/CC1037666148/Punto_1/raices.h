
//Se define la clase que calcula raices
 
class C_raices
{
 public:
  C_raices(double,double,double);
  void raices();
 private:
  double a;
  double b;
  double c;
  bool imaginario;
  double det();
  double term1();
  double term2(double);
};
