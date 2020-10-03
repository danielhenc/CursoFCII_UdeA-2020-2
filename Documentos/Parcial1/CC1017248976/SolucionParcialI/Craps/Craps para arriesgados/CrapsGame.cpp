#include <iostream>
#include <iomanip>
#include <cstdlib> // rand function
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
  bool win=true;
  int Saldo=1000000;
  int Apuesta=0;
}


//Esta funcion da un mensaje de bienvenida al iniciar el juego
void CrapsGame::DisplayMessage(){
    cout<<"     ------------------------------------------------------------------"<<"\n";
    cout<<"     ---------------------    BIENVENIDO    ---------------------------"<<"\n";
    cout<<"     ----------------   A CRAPS PARA ARRIESGADOS    -------------------"<<"\n";
    cout<<"     --El juego donde solo el más arriesgado se lleva el mejor premio--"<<"\n";
    cout<<"     ------------------------------------------------------------------"<<"\n";
    cout<<"     ------------------------------------------------------------------"<<"\n";
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
      cout<<"Para ganar, el jugador debe lanzar los dados y obtener que la suma sea igual al puntaje acumulado, puede \nlanzar cuantas veces desee pero si lanza una combinación que de 7 el jugador perderá automaticamente, la \nronda y el juego acaban cuando el jugador pierda o gane, la opción que ocurra primero\n";
      cout<<"\nEn cuanto a las apuestas\n";
      cout<<"Se tiene una apuesta base, la cual debe ser siempre menor o igual al saldo base ya que en la medida que \nel jugador gane o pierda se sumará la apuesta o se restará\n";
      cout<<"Recuerde además que para retirarse y reclamar su dinero basta con presionar R en vez de L";
      cout<<"\nAhora si, QUE COMIENCE EL JUEGO!!! \n";
    }
    else{cout<<"CRAPS ha comenzado! \n";}
    Saldo=1000000;
    cout<<"\nSu saldo inicial es: "<< Saldo <<" de pesos"<<"\n";
    cout << "Ingrese una apuesta, sea bien arriesgado!\n";
    cin >> Apuesta;
    cout<<"-------------------------------------------------------------\n";
    cout<<"**No olvide por favor que para retirarse y reclamar su dinero\nbasta con presionar R en vez de L\n";
    cout<<"-------------------------------------------------------------\n";
    cout<<"Mucha suerte, a jugar!!!!\n";
}

//Esta funcion da la despedida cuando el juego ha finalizado
void CrapsGame::Despedida(){
    cout<<"     ------------------------------------------------------------------"<<"\n";
    cout<<"     --------------------- JUEGO FINALIZAD0 ---------------------------"<<"\n";
    cout<<"     ------------------------------------------------------------------"<<"\n";
    cout<<"     -----------------Esperamos que vuelvas pronto---------------------"<<"\n";
    cout<<"     ------------------------------------------------------------------"<<"\n";
    cout<<"     ------------------------------------------------------------------"<<"\n";
}

//Esta funcion se encarga de modificar el saldo del jugador, debita o agrega dinero a su saldo en la medida que va jugando
void CrapsGame::Debitar(bool win){
    cout<<"\nSu saldo actual es: "<< Saldo <<"\n";
    if(Saldo >= Apuesta){
        if (win){
            Saldo=Saldo+Apuesta;
            cout<<"Su nuevo saldo es: "<< Saldo <<"\n";
        }
        else{
            Saldo=Saldo-Apuesta;
            cout<<"Su nuevo saldo es: "<< Saldo <<"\n";
        }
      } 
    }

//Esta funcion se encarga del lanzamiento de un dado
int CrapsGame::lanzar(){
  return 1 + rand() % 6;
}    
    
    
//Esta funcion se encarga de imprimir mensajes aleatorios en el juego    
void CrapsGame::RandomMessage(bool p){
    int l; 
    l=1 + rand() % 7;//se elige un numero aleatorio para las frases
    
    //se crearan frases positivas para el jugador
    if(p){
        switch(l){
            case 1:
            cout<<"Ufff a este paso te vas a volver millonari@!!\n";
            break;
            case 2:
            cout<<"En la próxima apuesta el doble, qué manera de jugar!!\n";
            break;
            case 3:
            cout<<"La sacaste del estadio!!\n";
            break;
            case 4:
            cout<<"Eres el mejor jugador que he visto!! <3\n";
            break;
            case 5:
            cout<<"Me vas a dejar sin dinero a este ritmo!! \n";
            break;
            case 6:
            cout<<"Qué buena suerte!! hubieras apostado el doble\n";
            break;
            case 7:
            cout<<"Tu mamá debe estar muy orgulloso de ti!\n";
            break;
        }
    }
    //se crean frases para burlarse un poco del jugador
    else{
        switch(l){
            case 1:
            cout<<"Ufff a este paso te vas a quedar sin casa!!\n";
            break;
            case 2:
            cout<<"En la próxima apuesta menos (sarcasmo), qué juego tan lento!!! me aburrooo... :O\n";
            break;
            case 3:
            cout<<"Creo que este no es tu día de suerte!!\n";
            break;
            case 4:
            cout<<"Eres el peor jugador que he visto!! </3\n";
            break;
            case 5:
            cout<<"Vayase para la casa mejor!!\n";
            break;
            case 6:
            cout<<"Qué mala suerte!!\n";
            break;
            case 7:
            cout<<"En la próxima ronda te repones, sigue intentando!! \n";
            break;
        }
    }
}
    

//Esta funcion contiene las reglas del juego y es la base para el desenlace del mismo
void CrapsGame::begin(int turno)
{
  d1 = lanzar(); //se lanzan los dados
  d2 = lanzar();
  //le decimos al usuario que resultado tuvo su lanzamiento
cout <<"\nEl resultado del lanzamiento es: " << d1 << ", " << d2 <<"\n";

  if(turno == 0){ //para la primera ronda
    s = d1 + d2; //realiza la suma de sus puntos
    
    if ((s == 7) || (s == 11)){
      cout << "GANASTE!! \n";
      RandomMessage(true); //imprime un mensaje aleatorio positivo ya que el jugador gano esta ronda
      cont = true; //esta variable es la que permite al jugador seguir jugando
      Debitar(true); //realiza una suma a su saldo ya que gano
      

    }
    else if ((s == 2) || (s == 3) || (s == 12)){
      cout << "CRAPS!: PERDISTE :( \n";
      RandomMessage(false); //imprime un mensaje aleatorio negativo ya que el jugador perdio esta ronda
      cont = true;
      Debitar(false);//debita dinero del saldo ya que el jugador perdio
      
      
    }
    else{
      cout << "Sumaste " << s << " puntos\n"<<"pasa a la segunda ronda\n";
      cont = true;
      turno=turno+1; //con esto el jugador pasara a la segunda ronda
    }
  }

  else{ //Segunda ronda en esta el jugador debe lanzar los dados hasta obtener sus puntos pasado, si saca una suma igual a 7 pierde
    cout << "Llevas " << s << " puntos\n";
    int S = d1 + d2; //suma de los dados

    if(S == 7){
      cout<<"Sacaste "<< S <<"\n";
      cout << "CRAPS!: PERDISTE :( \n";
      RandomMessage(false);
      //cont=false;
      cont = true;
      Debitar(false);// el true implica sumar, el falsa implica debitar dinero
      
    }
    else if (S == s){
      cout<<"Sacaste "<< S <<"\n";
      cout << "GANASTE!! \n";
      RandomMessage(true);
      //cont=false;
      cont = true;
      Debitar(true);
      
    }
    else{
      cout<<"Sacaste: " << S << " , sigue lanzando aún puedes ganar\n";
      cont = true;
    }

	}
	if(Saldo==0){cout<<"Su saldo es insuficiente, debe recargar bai bai \n";
        cont=false;// Si el usuario se queda sin saldo el juego debe finalizar
    }
    else if(Saldo < Apuesta){ //si la apuesta ya no es menor que el saldo, el usuario debe modificar la apuesta
        cout<<"Su apuesta ya no es válida, por favor ingrese una menor que su saldo actual, para seguir jugando\n";
        RandomMessage(true); //imprime un mensaje pisotivo para motivar al jugardor a apostar
        cin>> Apuesta; 
    }

  }
  
//Esta funcion es la que va en main se encarga de enlazar todas las funciones y que el juego pueda llevarse a cabo
void CrapsGame::play(){
  char q;
  int t=0; //inicializa el turno en cero
  DisplayMessage(); //se da la bienvenida al juego
  Instructions(); //se pregunta si se quiere conocer las instrucciones
  
    //este ciclo while permite al usuario jugar
  while (cont){//el contador cont es quien permita que el juego siga
    cout<< "\nPresione L para lanzar los dados o M para modificar la apuesta\n";
    cin >> q;
    if ((q == 'L') or (q == 'l')){
      begin(t);//funcion con las reglas
      t=t+1; //permite que haya un nuevo turno
    }
    else if ((q == 'R') or (q == 'r')){//permite al usuario retirarse del juego
        cout<<"Lamentamos que quieras irte :'(\n";
        cout<<"Ganaste: "<< Saldo <<" ve a taquilla a reclamar tu dinero!\n";
        cout<<"(PD:Sabemos dónde vives...)\n"; //pequeña broma
        cont=false; //finaliza el juego
    }
    else if((q == 'M') or (q == 'm')){//permite al usuario modificar la apuesta
        cout << "Ingrese su nueva apuesta, ahora sí sea bien arriesgado!\n";
        cin >> Apuesta;
        
    }
      else{
	cout << "Esta opción no es válida, bai\n"; //en caso de que el jugador no brinde una opcion valida
	break;
      }
    }
    Despedida();//se da una despedida ya que el juego ha acabado
}
  


