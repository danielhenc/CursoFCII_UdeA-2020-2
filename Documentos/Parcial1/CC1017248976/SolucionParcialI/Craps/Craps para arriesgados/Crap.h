class CrapsGame{
 public:
  CrapsGame();
  void play();
  

 private:
  int d1, d2, s;
  bool cont, win, p;
  int Saldo, Apuesta;
  void DisplayMessage();  
  void Instructions();
  int lanzar();
  void begin(int);
  void Debitar(bool);
  void Despedida();
  void RandomMessage(bool);
  
};
