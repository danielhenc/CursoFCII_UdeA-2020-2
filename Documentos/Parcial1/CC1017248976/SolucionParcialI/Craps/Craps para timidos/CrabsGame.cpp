#include <iostream>
#include <iomanip>
#include <cstdlib> //rand function
#include <ctime>
#include "Crap.h"

using std::setw;
using std::rand;
using namespace std;

//INicializacion de las variables
CrapsGame::CrapsGame(){
  srand(time(NULL));
  int d1=0;
  int d2=0;
  int s=0;
  bool cont=true;

}
//Esta funcion da un mensaje de bienvenida al iniciar el juego
void CrapsGame::DisplayMessage(){
    cout<<"     -----------------------------------------------"<<"\n";
    cout<<"     -------------    BIENVENIDO      --------------"<<"\n";
    cout<<"     -------------     A CRAPS        --------------"<<"\n";
    cout<<"     -----------------------------------------------"<<"\n";
    cout<<"     -----------------------------------------------"<<"\n";
}

//Esta funcion despliega bajo peticion del jugador las instrucciones del juego
void CrapsGame::Instructions(){
    char a;
    cout<<"Si deseas ver las intrucciones del juego, presiona S"<<"\n";
    cout<<"De lo contrario presiones cualquier otra letra\n";
    cin >> a;
    if ((a == 'S') || (a == 's'))
    { cout<<"   ---------------- INSTRUCCIONES ----------------\n";
      cout<<"         Este juego consiste de dos rondas \n";
      cout<<"\nPRIMERA RONDA: \n"<<"El jugador lanza los dados, hay tres opciones dependiendo de su resultado:\n";
      cout<<"Opcion 1: La suma de los dados es 7 u 11 -> El jugador gana automaticamente y el juego finaliza \n";
      cout<<"Opcion 2: La suma de los dados es 2 3 o 12 -> El jugador pierde automaticamente y el juego finaliza \n";
      cout<<"Opcion 3: Esta es la única opciones que permite pasar a la segunda ronda, en esta simplemente se acumula \nla suma de los dados, considerandose como el puntaje, de acá se pasa a la segunda ronda \n";
      cout<<"\nSEGUNDA RONDA: \n"<<"En esta ronda es vital el puntaje acumulado de la ronda anterior \n";
      cout<<"Para ganar, el jugador debe lanzar los dados y obtener que la suma sea igual al puntaje acumulado, puede \nlanzar cuantas veces desee pero si lanza una combinación que de 7 el jugador perderá automaticamente, la \nronda y el juego acaban cuando el jugador pierda o gane, la opción que ocurra primero\n"<<"\nAhora si, QUE COMIENCE EL JUEGO!!! \n";
    }
    else{cout<<"CRAPS ha comenzado! \n";}
    
}

//Esta funcion se encarga del lanzamiento de un dado
int CrapsGame::lanzar(){
  return 1 + rand() % 6;
}

//Esta funcion contiene las reglas del juego y es la base para el desenlace del mismo
void CrapsGame::begin(int turno)
{
  d1 = lanzar();
  d2 = lanzar();
  //informamos al jugador de su resultado
cout <<"\nEl resultado del lanzamiento es: " << d1 << ", " << d2 <<"\n";

  if(turno == 0){//define que esta en la primera ronda
    s = d1 + d2;
    
    if ((s == 7) || (s == 11)){
      cout << "GANASTE!! \n";
      cont=false; //cont se encarga de dar continuidad al juego false acaba el juego

    }
    else if ((s == 2) || (s == 3) || (s == 12)){
      cout << "CRAPS!: PERDISTE :( \n";
      cont=false;
      
    }
    else{
      cout << "Sumaste " << s << " puntos\n"<<"pasa a la segunda ronda\n";
      cont = true; //permite que el usuaio siga jugando 
      turno=turno+1; //permite que se pase a la segunda ronda
    }
  }

  else{
    cout << "Llevas " << s << " puntos\n";
    
    int S = d1 + d2;

    if(S == 7){
      cout<<"Sacaste "<< S <<"\n";
      cout << "CRAPS!: PERDISTE :( \n";
      cont=false;
      
    }
    else if (S == s){
      cout<<"Sacaste "<< S <<"\n";
      cout << "GANASTE!! \n";
      cont=false;
    }
    else{
      cout<<"Sacaste: " << S << " , sigue lanzando aún puedes ganar\n";
      cont = true;
    }

	}

  }
  
//Esta funcion es la que va en main se encarga de enlazar todas las funciones y que el juego pueda llevarse a cabo
void CrapsGame::play(){
  char q;
  int t=0;
  DisplayMessage();
  Instructions();
  while (cont){
    cout<< "\nPresione L para lanzar los dados\n"; 
    cin >> q;
    if ((q == 'L') or (q == 'l')){// permite que el jugador lance los dados
      begin(t);
      t=t+1;//permite avanzar a la segunda ronda
      
    }
      else{
	cout << "Esta opción no es válida, bai\n";
	break;
      }
    }

  }

