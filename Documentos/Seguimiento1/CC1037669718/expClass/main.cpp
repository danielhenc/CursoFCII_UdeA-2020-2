#include"expClass.h"

int main(){
  expClass miExp(1, 20);

  miExp.print();

  cout << "\n";

  miExp.set(-1, 3);

  miExp.print();

  cout << "\n";
  
  miExp.set(-1, 20);
  
  miExp.print();

  cout << "\n";
  
  return 0;
}
