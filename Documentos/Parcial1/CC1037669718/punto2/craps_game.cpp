#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<limits>

using namespace std;

bool crapsGame(){ // Función que simula una partida de craps
  
  int dado1, dado2, punto, suma;

  srand(time(NULL)); // Toma el tiempo como semilla
  cin.ignore(numeric_limits < streamsize>::max(), '\n'); // Limpia el buffer de cin
  cin.clear();
  
  cout << "⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄\n⚄⚄  Presione enter para lanzar los dados ⚄⚄\n";
  cin.ignore();
  
  dado1 = 1 + rand()%6; // Genera los dados
  dado2 = 1 + rand()%6;
  punto = dado1+dado2; // Guarda el valor de la suma inicial

  cout << "⚄⚄⚄⚄⚄⚄ Obtuvo " << dado1 << " y " << dado2 << ", lo cual suma " << setw(2) << punto << " ⚄⚄⚄⚄⚄⚄\n";
  if(punto == 7 || punto == 11){
    cout << "☺                 ¡Ganaste!               ☺\n";
    return true;
  }
  else if(punto == 2 || punto == 3 || punto == 12){
    cout << "☹                 Perdiste                ☹\n";
    return false;
  }
  else{
    cout << "⚄ Debe obtener nuevamente " << setw(2) << punto << " sin obtener 7⚄\n";
    while(1){
      cout << "⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄\n⚄⚄  Presione enter para lanzar los dados ⚄⚄\n";
      cin.ignore();

      dado1 = 1 + rand()%6;
      dado2 = 1 + rand()%6;
      suma = dado1+dado2;

      cout << "⚄⚄⚄⚄⚄⚄ Obtuvo " << dado1 << " y " << dado2 << ", lo cual suma " << setw(2) << suma << " ⚄⚄⚄⚄⚄⚄\n";

      if(suma == punto){
	cout << "☺                 ¡Ganaste!               ☺\n";
	return true;
      }
      else if(suma == 7){
	cout << "☹                 Perdiste                ☹\n";
	return false;
      }
    }
  }
};

int main(){
  int apuesta, ganancias, SaldoEnBanco = 1000000;
  bool resultado; // Define si el jugador ha ganado en la partida
  char jugando = 'n'; // Define si el jugador permanecerá jugando

  cout << "⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄\n⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄🎲Craps🎲⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄\n⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄\n";
  
  while( 1 ){ // Ciclo de juego

    while( 1 ){ // Ciclo de apuestas
      
      apuesta = 0;
      
      cout << "⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄ Saldo:" << fixed << setw(11) << SaldoEnBanco << " ⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄\n";
      cout << "⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄ Introduzca su apuesta ⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄\n";

      cin >> apuesta;
	
      if( cin.fail() ){ // Si introduce algo que no pueda ser asignado a un int entonces repite
	cout << "⮾     Introduzca una cantidad válida      ⮾\n";
	cin.clear(); // Limpia cin.fail()
	cin.ignore(numeric_limits < streamsize>::max(), '\n'); // Limpia el buffer de cin

      }else if( apuesta <= 0 || apuesta > SaldoEnBanco ){ // Si la apuesta no es un valor válido, se repito el ciclo de apuestas
	cout << "⮾     Introduzca una cantidad válida      ⮾\n";
	cin.clear(); // Limpia cin.fail()
	cin.ignore(numeric_limits < streamsize>::max(), '\n'); // Limpia el buffer de cin
      }else{
        break;
      }
    }

    resultado = crapsGame(); // Se ejecuta el juego de craps
    SaldoEnBanco += (2*resultado - 1)*apuesta; // Suma o resta la cantidad apostada al saldo
    ganancias  = SaldoEnBanco - 1000000;
    
    cout << "⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄ Saldo:" << fixed << setw(11) << SaldoEnBanco << " ⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄\n";

    if( SaldoEnBanco <= 0 ){
      cout << "⮾  Se ha quedado sin saldo, ¡qué lástima! ⮾\n";
      break;
    }

    if( SaldoEnBanco <= 50000){
      cout << "⚠  Ha perdido mucho dinero, piénsela bien ⚠\n";
    };

    if( SaldoEnBanco >= 3000000 && resultado){
      cout << "👍 Haragán, considere canjear sus fichas 👍\n";
    }
    
    cout << "⚄⚄¿Desea retirarse y canjear su saldo?(s)⚄⚄\n";
    
    jugando = cin.get();
    
    if( cin.fail() ){
      continue;
    }else if( jugando == 's'){
      cout << "⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄  Se ha retirado ⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄⚄\n";
      cout << "⚄⚄⚄ Ha ganado (o perdido) " << fixed << setw(9) << ganancias << " COP ⚄⚄⚄\n";
      break;
      }
    }

  cin.ignore(numeric_limits < streamsize>::max(), '\n'); // Limpia el buffer de cin
  cin.clear();
  return 0;
}
