//Se importan las librerías
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int Craps(void); //Función con las reglas del juego
void Charla(void); //Función que entabla una charla con el jugador
int Ganar = 0;  //Contador de las veces que se gana de manera consecutiva
int Perder = 0;  //Contador de las veces que se pierde de manera consecutiva
float SaldoenBanco = 1000000; 

int main(){
  int Apuesta = 0; //Se inicializa el valor de la apuesta
  
  while(SaldoenBanco >= Apuesta ){
    cout << "Díganos cuánto desea apostar ";
    cin >> Apuesta; //Valor que apuesta el jugador
    if(Apuesta > SaldoenBanco or SaldoenBanco == 0) {
      cout << "Lo sentimos, usted se ha quedado sin fondos suficientes " << endl;
      break;}
    
    if(Craps() == 1){ //Caso en el que gana el tiro
      SaldoenBanco += Apuesta;
      Ganar += 1;
      Perder = 0;
      cout << "Tu nuevo saldo en Banco es: " << SaldoenBanco << endl;
	}
   
    else{ //Caso en el que pierde el tiro 
	SaldoenBanco -= Apuesta;
	Ganar = 0;
	Perder += 1;
	cout << "Tu nuevo saldo en Banco es: " << SaldoenBanco << endl;
	}
    
    Charla(); //Se establece charla con el jugador
    Apuesta = 0;}
 
     
return 0; 
}


int Craps(){ //Reglas del juego

  srand( time( NULL ) );
  
  int dado1 = 1 + rand() % 6; //Número aleatorio entre 1 y 6
  int dado2 = 1 + rand() % 6;
  int Resultado; //Variable que va a indicar si el tiro se pierde o se gana

  //Gana en el primer lanzamiento
  if (dado1 + dado2 == 7 or dado1 + dado2 == 11) {
    
     Resultado = 1;
     cout << "Felicitaciones, ganaste" << endl;
    }

  //Pierde en el primer lanzamiento
   else if (dado1 + dado2 == 2 or dado1 + dado2 == 3 or dado1 + dado2 == 12) {

     Resultado = 0;
     cout << "Lo lamentamos, perdiste" << endl;
    }

  //El jugador obtiene "su punto"
   else {

     int punto = dado1 + dado2;
     cout << "Tu punto es " << punto << endl;
    
     int tiro = 1;

     //Ciclo para realizar lanzamientos hasta que finalmente el jugador obtenga su puntaje o termine perdiendo la partida
     while(tiro <= tiro +1 )
       { int tiro1 = 1 + rand() % 6;
	 int tiro2 = 1 + rand() % 6;

	 if (tiro1 + tiro2 == punto)
	   {  Resultado = 1;
	      cout << "Felicitaciones, ganaste" << endl;
	      break;}
              
	 else if (tiro1 + tiro2 != punto and tiro1 + tiro2 != 7)
	   {}
	 else {
	      Resultado = 0;
	      cout << "Lo lamentamos, perdiste" << endl;
	      break;}
	 };
    }
   return Resultado;
}

//Diferentes condiciones que se ponen para darle ciertos mensajes al jugador mientras está en la partida 
void Charla(){
  
  if(SaldoenBanco <= 200000){
      cout << "Creemos que ha perdido suficiente, sería conveniente que se retire "<< endl;
  }
  
  else if(SaldoenBanco >= 3000000 and SaldoenBanco <= 5000000){
      cout << "Usted ya tiene dinero suficiente para que se dé unas merecidas vacaciones "<< endl;
 }
  
  else if(SaldoenBanco <= 500000){
      cout << "Apueste todo lo que tiene, sin mente como las barbies "<< endl;
 }
  
  else if(SaldoenBanco >= 2000000 and SaldoenBanco <= 3000000){
      cout << "Podrías retirarte ya y empezar a ahorrar para la universidad de tus hijos "<< endl;
 }
  
  else if(SaldoenBanco > 5000000 and SaldoenBanco < 8000000 ){
       cout << "Su juego ya ha sido considerablemente exitoso, podría retirarse "<< endl;
 }
  
  else if(SaldoenBanco < 1000000){
       cout << "Ni piense en retirarse, no puede volver a casa sin recuperar al menos lo que tenía en un principio "<< endl;
 }
 
 if(Ganar > 3){
       cout << "La suerte te acompaña, arriésgate a apostar más "<< endl;
 }

 if(Perder == 2){
       cout << "Perdiste dos veces seguidas, pero la tercera es la vencida, apueste todo en esta ronda  "<< endl;
 }
 
 if(Ganar > 5){
       cout << "Naciste para esto, más de cinco turnos seguidos ganando "<< endl;
 }
 
}
