class TrapezoidRule
{
 public:
  TrapezoidRule();
  void SetValues();
  void DisplayMessage();
  float Function(float);
  float Rule();
  void Result();
 private:
  //Definicion variables
  float a,b,A,B,C;
  float x,f,I;
  int k;
  

};
