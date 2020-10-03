class CrapsGame{
 public:
  CrapsGame();
  void play();

 private:
  int d1, d2, s;
  bool cont;
  void DisplayMessage();  
  void Instructions();
  int lanzar();
  void begin(int);
  
  



};
