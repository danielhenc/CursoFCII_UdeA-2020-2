#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

int tirarDados(){
  
  int dado1 = 0;
  int dado2 = 0;
  int resultado = 0;
  dado1 = 1 + rand()%6;
  dado2 = 1 + rand()%6;

  resultado = dado1 + dado2;
  
  return resultado;
}

int main(){

  srand(time(NULL));
  bool condition = true;
  string seguirJuego;
  int punto = 0;

  while(condition==true){
    cout << "¿Deseas empezar/seguir jugando craps? (s/n)" << endl; //en cualquier momento el jugador se puede salir del juego.
    cin >> seguirJuego;

    if(seguirJuego == "s"){
      
      int tirada = 0;
      tirada = tirarDados(); //llama a la funcion tirar los dados
      
      cout << "Obtuviste: " << tirada  << endl;
      cout << " " << endl;

      //en la primera tirada de dados la ruta del codigo es esta
      if (punto==0){

	if (tirada==7 or tirada==11){
	  cout << "Acabas de ganar. ¡Felicitaciones!" << endl;
	  condition = false;
	}
	
	else if (tirada==2 or tirada==3 or tirada==12){
	  cout << "Acabas de perder. Lo siento mucho. :(" << endl;
	  condition = false;
	}
	//si el jugador no gana o pierde en la primera tirada de dados, sigue esta ruta
	else {
	  punto = tirada; //se agrega el punto al jugador
	  cout << "Sacaste un punto ¡Saca el mismo numero para ganar!" << endl;
	  cout << " " << endl;
      }
    }
      //ruta para las siguientes tiradas de dados despues de la primera, hasta ganar o perder,
      //o si el jugador decide salirse del juego
      else {
	if (tirada==punto){
	  cout << "Acabas de sacar de sacar de nuevo el punto ¡Ganaste!" << endl;
	  condition = false;
	}
	else if (tirada==7){
	  cout << "Sacaste un 7 y por lo tanto has perdido. :( " << endl;
	  condition = false;
	}
      }
      
    }
    //si el jugador decide no continuar
    else {
    cout << "Juego terminado ¡Vuelve pronto!" << endl;
    condition = false;
    }
  }


  return 0;

}
