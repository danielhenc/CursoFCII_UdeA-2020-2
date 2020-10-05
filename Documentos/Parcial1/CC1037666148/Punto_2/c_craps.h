

class Craps_Game

{
public:
  Craps_Game(int); //constructor
  int Apuesta;
  int SaldoenBanco;
  int craps(void);
  int saldo();
private:
  bool ganar;
  void M_saldo_banco();
  void play_again(char);
  int suma(int,int);
  void s_punto(int,int);
  void warnings(void);
  //  void n_saldo(void);
  
};
