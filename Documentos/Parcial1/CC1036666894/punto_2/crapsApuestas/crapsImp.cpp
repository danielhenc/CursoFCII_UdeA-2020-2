#include <iostream>
#include <iomanip>
#include <ctime>
#include <unistd.h>

#include "craps.h"

using namespace std;

craps::craps(){
  
  srand(time(NULL));
}

//reglas del juego
void craps::reglas(){

  char ign; //ignorar

  cout << "____________________________________"<<endl;
  cout << "____________________________________"<<endl;
  cout << "Las reglas del juego son:" << endl;
  cout << " " << endl;
  cout<<"Se tiran dos dados de 6 caras cada uno y se suman las caras superiores.";
  cout<<"Si la suma es 7 u 11 en el primer tiro, el jugador gana. Si la suma es 2, 3 o 12, el jugador pierde.";
  cout<<" Si la suma es 4, 5, 6, 7, 8, 9 o 10, en el primer tiro, el jugador obtiene un punto con valor igual al resultado obtenido.";
  cout<<" Para ganar, el jugador debe seguir lanzando los dados hasta obtener el mismo valor del punto. Pero si el jugador obtiene un 7 antes de obtener el valor del punto, el jugador pierde."<<endl;
  cout << "____________________________________" << endl;
  cout << "____________________________________" << endl;
  cout << " " << endl;

  cout<<"Oprime cualquier tecla para volver al menu."<<endl;
  cin>>ign;
  cin.clear();
  
  menu();
    
}

//ingresa mensajes dependiendo de la cantidad a apostar e inicializa la apuesta
void craps::apuesta(){

  bool cond = false;

  while (cond==false){

    cout << "Tu saldo en banco es: " << saldoenBanco << endl;
    cout << " " << endl;
    
    cout << "Ingresa la cantidad de dinero que deseas apostar: " << endl;
    cin>> valorApuesta;
    cin.clear();

    if (valorApuesta>saldoenBanco){
      cout << "No tienes tanto dinero, ingresa otro valor." << endl;
    }
    
    else if (valorApuesta<0)
      cout << "No puedes apostar dinero negativo, ingresa otro valor." << endl;

    else if (valorApuesta==saldoenBanco){
      cout << "Estás apostando todo ¡Buena suerte!" << endl;
      cond = true;
    }
    else if (valorApuesta>0.5*saldoenBanco and valorApuesta<0.8*saldoenBanco){
      cout << "Estás apostando más de la mitad de tu dinero ¡Ojo!" << endl;
      cond = true;
    }
    
    else if (valorApuesta>=0.8*saldoenBanco){
      cout << "Estás apostando casi todo tu dinero ¡Con cuidado!" << endl;
      cond = true;
    }
    
    else if (valorApuesta<0.5*saldoenBanco and valorApuesta>0.2*saldoenBanco){
      cout << "Estás apostando menos de la mitad de tu dinero ¡Eres una persona prudente!" << endl;
      cond = true;
    }
    
     else if (valorApuesta<=0.2*saldoenBanco){
       cout << "Estás apostando muy poco dinero ¡El que no se arriesga no gana!" << endl;
       cond = true;
    }
     else if (valorApuesta==0.5*saldoenBanco){
       cout << "Estás apostando la mitad de tu dinero ¡Vamos a ganar!" << endl;
       cond = true;
     }
  }
  cin.clear();
}


//tira los dados y devuelve la suma de ellos
int craps::tirarDados(){                                                               
                                                                                
  int dado1 = 0;                                                                
  int dado2 = 0;                                                                
  int resultado = 0;
  char ign;
  
  cout << " " <<endl;
  //para lanzar los dados se debe oprimir cualquer tecla + enter
  cout<<"Oprime una tecla para lanzar los dados."<<endl;
  cin>>ign;
  cin.ignore();

  dado1 = 1 + rand()%6;                                                         
  dado2 = 1 + rand()%6;                                                         
                                                                                
  resultado = dado1 + dado2;
                                                                                
  return resultado;                                                             
}

//recibe un booleano desde jugar()
//para determinar si se le suma o resta la apuesta al saldoenBanco
void craps::resultadoApuesta(bool ap){

  if (ap==true){
    saldoenBanco += valorApuesta;
  }
  else{
    saldoenBanco -= valorApuesta;
  }

}

//aqui es donde se encapsula la funcion de jugar craps
//y envia un true o false a resultadoApuesta
void craps::jugar(){

  apuesta();

  bool condition = true;
  int punto = 0;
  
while(condition==true){
       
      int tirada = 0;
      tirada = tirarDados(); //llama a la funcion tirar los dados
      
      cout << "Obtuviste: " << tirada  << endl;

      //en la primera tirada de dados la ruta del codigo es esta
      if (punto==0){

	if (tirada==7 or tirada==11){
	  cout<<"Acabas de ganar. ¡Felicitaciones!"<<endl;
	  resultadoApuesta(true);
	  condition = false;
	}
	
	else if (tirada==2 or tirada==3 or tirada==12){
	  cout<<"Acabas de perder. Lo siento mucho. :("<<endl;
	  resultadoApuesta(false);
	  condition = false;
	}
	//si el jugador no gana o pierde en la primera tirada de dados, sigue esta ruta
	else {
	  punto = tirada; //se agrega el punto al jugador
	  cout << "Sacaste un punto ¡Saca el mismo numero para ganar!" << endl;
	  cout << " " <<endl;
      }
    }
      //ruta para las siguientes tiradas de dados despues de la primera, hasta cumplir una de las dos condiciones,
      //o si el jugador decide salirse del juego
      else {
	if (tirada==punto){
	  cout<< "Acabas de sacar de sacar de nuevo el punto ¡Ganaste!"<<endl;
	  cout << " " <<endl;
	  resultadoApuesta(true);
	  condition = false;
	}
	else if (tirada==7){
	  cout<<"Sacaste un 7 y por lo tanto has perdido. :( "<<endl;
	  cout << " " <<endl;
	  resultadoApuesta(false);
	  condition = false;
	}
      }
  }

 menu();
}

//menu principal donde se empieza a jugar,
//el jugador decide si quiere comenzar a jugar, ver las reglas o salir del juego
void craps::menu(){

  int opcion;

  cout << "___________________________________"<< endl;
  cout << "___________________________________"<< endl;
  cout << " " << endl;
  cout << "Menu del juego."<<endl;
  cout << " " << endl;
  cout << "Su saldo actual es de: " << saldoenBanco << endl;
  cout << "Seleccione una opción: "<< endl;
  cout << "1. Empezar/seguir jugando." <<  endl;
  cout << "2. Consultar las reglas del juego." << endl;
  cout << "3. Salir del juego." << endl;
  cout << " " << endl;
  cout << "___________________________________" <<endl;
  cout << "___________________________________" <<endl;
  cout << " " << endl;
  cin>>opcion;
  
  if (opcion==1){
    if (saldoenBanco>0){
    jugar();
    }
    else{
      string volver;
      
      //se agrega la posibilidad de recomprar 1000000 para seguir apostando
      cout << "Ya no tienes saldo ¿Deseas recargar 1000000? (y/n)." << endl;
      cin>>volver;                                                           
      if (volver=="y"){
	saldoenBanco = 1000000;
	jugar();
      }
      else{
	cout << "Espero vuelvas pronto." << endl;
      }
    }
  }

  else if (opcion==2){
    reglas();
  }

  //mensaje de despedida
  else if (opcion==3){
    cout << "¡Hasta la próxima!" << endl;
    cout << "Espero vuelvas pronto." << endl;
    cout << "Te retiras con un saldo de: " << saldoenBanco << endl;
  }

  //si no se ingresa una opcion valida en el menu
  else{
    cout << "Por favor ingresa una opción válida." << endl;
    menu();
  }
 
}

