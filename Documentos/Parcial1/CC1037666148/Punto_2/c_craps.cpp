#include <iostream>
#include <iomanip>
#include <cstdlib> 
#include <ctime>
#include "c_craps.h"
 //Definición de la clase para el juego de craps

using namespace std;

Craps_Game :: Craps_Game(int apuesta ) //Constructor
{
  SaldoenBanco = 1000000;
  Apuesta = apuesta;
  bool ganar;
}



int Craps_Game :: saldo() //Función para ver si la apuesta sí es mayor que cero
{
  
  int test_Saldo = SaldoenBanco - Apuesta;
  return test_Saldo;  
}


//Suma de las caras de los dados
int Craps_Game :: suma(int cara_1,int cara_2)
{
  return cara_1 + cara_2;
}


//Se modifica el SaldoenBanco si se pierde o se gana el juego
void Craps_Game ::  M_saldo_banco()
{
  if (ganar)
    SaldoenBanco = SaldoenBanco + Apuesta;
  else
    SaldoenBanco = SaldoenBanco - Apuesta;
}



//Condiciones para las apuestas después de cada ronda
void Craps_Game :: play_again(char answer)
{
  char t_apuesta;
  int find_saldo;
  
  if ((answer=='y') && (Apuesta>0))
    {
      cout << "Su saldo en Banco es de: " << SaldoenBanco <<endl;
      cout << "Deseas apostar de nuevo?(y o n)"<< endl;
      cin >> t_apuesta;
      if (t_apuesta == 'y')
	{
	  cout << "Ingrese el valor de su nueva apuesta"<<endl;
	  cin >> Apuesta;
	  find_saldo = saldo();
	  while (find_saldo < 0)
	    {
	      cout << "El valor de la apuesta supera el saldo en banco, ingrese de nuevo el valor de su apuesta en pesos Colombianos." << endl;
	      cin >> Apuesta;
	      find_saldo = saldo();
	    }

	  
	}
      else
	Apuesta = 0;
      
    } 
}


//Mensajes de salida para las apuestas
void Craps_Game :: warnings()
{
  if (Apuesta != 0)
    {
      if ((Apuesta < 100000)&&(SaldoenBanco>700000))
	cout << "Un juego muy conservador, arriesgate! Aun tienes mucho dinero" << endl;
      else if (SaldoenBanco%Apuesta==0)
	cout << "Una apuesta muy arriesgada... Piensalo bien luego" << endl;
      else if ((SaldoenBanco < 500000)&&(SaldoenBanco> 300000)) 
	cout << "Ya vas en la mitad de tu capital. Suerte! La necesitarás..." << endl;
      else if ((SaldoenBanco <= 200000)&&(SaldoenBanco > 100000))
	cout << "Estas agotando tus fondos! Tal vez en este juego tengas más suerte"<<endl;
      else if ((SaldoenBanco <= 100000)&&(SaldoenBanco > 50000))
	cout << "Este juego no parece lo tuyo..." << endl;
      else if (SaldoenBanco <= 50000)
	cout << " Insistes! Aceptalo, ya perdiste todo " << endl; 
      else if ((SaldoenBanco >= 1500000)&&(SaldoenBanco <2000000))
	cout << "Estas volando!" <<endl;
      else if ((SaldoenBanco >= 2000000)&&(SaldoenBanco <3000000))
	cout << "Este juego es en definitiva lo tuyo!" <<endl;
      else if (SaldoenBanco> 3000000)
	cout << "Te vas a volver millonaria/o"<< endl;
    }
}


// Se crea la instancia de "punto" en el juego
void Craps_Game :: s_punto(int cara1, int cara2)
{
  int punto = suma(cara1,cara2);
  int punto2;
  cout << "Punto! Debe tirar de nuevo hasta obtener otro: "<< punto << endl;
  int dado3;
  int dado4;
  char answer2;

  cout << "Desea continuar (y o n)"<<endl;
  cin >> answer2;
  while (answer2 =='y')
    {
      //Se crean los dados para la instancia "punto"
       dado3 = 1 + rand() % 6;
       dado4 = 1 + rand() % 6;
       punto2 = suma(dado3,dado4);
       cout<< "Su lanzamiento ha sumado: "<< punto2 << endl;

       if (punto2 == punto)
	   {
	     cout << "Felicidades! usted ha ganado!"<<endl;
	     answer2 = 'n';
	     ganar = true;
	     
	     break;
	   }
	else if (punto2 == 7)
	   {
	      cout << "Lo sentimos, ha perdido. Más suerte la próxima"<<endl;
	      ganar = false;
	      break;
	   }
	    
	 
	else
	   {
	      cout << "Desea seguir tirando?(y o n)"<<endl;
	      cin >>answer2;
	      if (answer2 == 'n')
		{
		  ganar = false;
		  break;
		}
	    }
	  
     }

  
}



//Se crea la instancia para el juego de Craps
int Craps_Game ::  craps()
{
  char answer;
  char r_apuesta;
  srand(time(NULL)); 
  cout << "Empecemos el juego!" << endl;
  answer ='y';
  warnings();

  
  int cara1;
  int cara2;
  while ( answer=='y')
    {
      cara1 = 1 + rand() % 6;
      cara2 = 1 + rand() % 6; 
      

      cout << "Su tiro ha sido:" << endl;
      cout << "Dado_1: " << cara1 << " y Dado_2: " << cara2 << ". suma="<<suma(cara1,cara2)<<endl;
  
      // Evalua las salidas de las caras
      switch ( suma(cara1,cara2) )
	{  
	case 7:
	case 11:
	  cout << "Felicidades ha ganado!" << endl;
	  ganar = true;
	  M_saldo_banco();
	  cout << "¿Desea volver a jugar?(y o n)" << endl;
	  cin >> answer;
	  play_again(answer);
	  warnings();
	  break;
	case 2:
	case 3:
	case 12:
	  cout << "Lo sentimos ha perdido!" << endl;
	  ganar = false;
	  M_saldo_banco();
	  cout << "¿Desea volver a jugar?(y o n)" << endl;
	  cin >> answer;
	  play_again(answer);
	  if (answer =='y')
	    warnings();
	  break;
	case 4:
	case 5:
	case 6:
	case 8:
	case 9:
	case 10:
	  {
	    s_punto(cara1,cara2);
	    M_saldo_banco();
	    cout << "Desea jugar de nuevo?(y o n)" << endl;
	    cin >> answer;
	    
	    play_again(answer);
	    if (answer=='y')
	      warnings();
	   
	    break;	    
	  }
	default: 
	  cout << "¿Qué haces aquí?"<<endl;
	}
  	
    } 
  return 0;
 
}




