#include <iostream>
#include <cmath>
#include <ctime>
#include "CRAPS.h"

using namespace std;


int main()
{



  bool restartApuesta = false;
  bool quitApuesta = false;


  while (quitApuesta==false)
  {

    int SaldoEnBanco = 1000000;
    char answer;

    cout<< "Bienvenido al juego 'Craps' con apuestas, ¿Desea introducir una apuesta? (y/n) "<<endl;
    cin>>answer;


    if (answer == 'n')
    {
      cout<<"¡Gracias por jugar!"<<endl;
      quitApuesta = true;
    }

    else
    {
      quitApuesta = false;
    }

    while (quitApuesta==false && restartApuesta==false)
    {

      while(SaldoEnBanco>0)
      {
        int Apuesta;
        cout<< "Ingrese el monto con el que desesa iniciar la apuesta"<<endl;
        cin>>Apuesta;

        while (Apuesta > 1000000)
        {
          cout<<"El monto igresado supera el valor permitido"<<endl;
          cout<<"Ingrese nuvamente una apuesta con un valor menor o igual a 1000000 $ "<<endl;
          cin>>Apuesta;
        }

        cout<<"El valor ingrsado para la apuesta es "<<Apuesta<<" $ "<<endl;

        bool quitCraps = false;

        while (quitCraps==false)
        {
          int Partida;

          bool restartCraps = false;

          while (quitCraps==false && restartCraps==false)
          {

            Partida=CRAPS();

            if (Partida==0)  //PARTIDA PERDIDA
            {
              SaldoEnBanco=SaldoEnBanco-Apuesta;

              if(SaldoEnBanco<=0)
              {
                cout<<"Su saldo es ahora 0 $"<<endl;
                cout<<"Lo siento. Se quedó sin fondos."<<endl;
                cout<<"!Gracias por jugar¡"<<endl;
                exit(0);
              }

              else if( SaldoEnBanco < 950000 && SaldoEnBanco > 350000 )
              {
                cout<<"Partida perdida, su saldo es ahora "<<SaldoEnBanco<<" $"<<endl;
                cout<<"¡No se rinda! Aún puede recuperase y aumentar su saldo"<<endl;
                cout<<"¿Desea jugar de nuevo? (y/n)"<<endl;
                cin>>answer;

                if (answer=='y')
                {
                  restartCraps = true;
                }
                else
                {
                  cout<<"!Gracias por jugar!"<<endl;
                  quitCraps = true;
                }

              }



              else if( SaldoEnBanco < 350000 && SaldoEnBanco > 100000 )
              {
                cout<<"Partida perdida, su saldo es ahora "<<SaldoEnBanco<<" $"<<endl;
                cout<<"Tal parece que su saldo ha disminuido notoriamente"<<endl;
                cout<<"¿Desea jugar de nuevo? (y/n)"<<endl;
                cin>>answer;

                if (answer=='y')
                {
                  restartCraps = true;
                }
                else
                {
                  cout<<"!Gracias por jugar!"<<endl;
                  quitCraps = true;
                }

              }


              else if( SaldoEnBanco < 100000 && SaldoEnBanco > 1000 )
              {
                cout<<"Partida perdida, su saldo es ahora "<<SaldoEnBanco<<" $"<<endl;
                cout<<"Parece que su saldo se esta acabando"<<endl;
                cout<<"¿Desea jugar de nuevo? (y/n)"<<endl;
                cin>>answer;

                if (answer=='y')
                {
                  restartCraps = true;
                }
                else
                {
                  cout<<"!Gracias por jugar!"<<endl;
                  quitCraps = true;
                }

              }



              else if(SaldoEnBanco < 1000 && SaldoEnBanco > 0)
              {
                cout<<"Partida perdida, su saldo es ahora "<<SaldoEnBanco<<" $"<<endl;
                cout<<"Su saldo ya es demasiado bajo, ¡Deberia retirarse si no quiere perderlo todo!"<<endl;
                cout<<"¿Desea jugar de nuevo? (y/n)"<<endl;
                cin>>answer;

                if (answer=='y')
                {
                  restartCraps = true;
                }
                else
                {
                  cout<<"!Gracias por jugar!"<<endl;
                  quitCraps = true;
                }

              }


              else
              {
                cout<<"Partida perdida, su saldo es ahora "<<SaldoEnBanco<<" $"<<endl;
                cout<<"¿Desea jugar de nuevo? (y/n)"<<endl;
                cin>>answer;

                if (answer=='y')
                {
                  restartCraps = true;
                }
                else
                {
                  cout<<"!Gracias por jugar!"<<endl;
                  quitCraps = true;
                }
              }

            }

            else if (Partida==1) //PARTIDA GANADA
            {
              SaldoEnBanco=SaldoEnBanco+Apuesta;

              if (1010000 < SaldoEnBanco &&  SaldoEnBanco < 1999999)
              {
                cout<<"¡Partida ganada!, su saldo es ahora "<<SaldoEnBanco<<" $"<<endl;
                cout<<"Parece que le esta yendo muy bien, ¡vamos arriesgese y siga jugando!"<<endl;
                cout<<"¿Desea jugar de nuevo? (y/n)"<<endl;
                cin>>answer;

                if (answer=='y')
                {
                  restartCraps = true;
                }
                else
                {
                  cout<<"!Gracias por jugar!"<<endl;
                  quitCraps = true;
                }
              }

              else if ( SaldoEnBanco > 2000000 )
              {
                cout<<"¡Partida ganada!, su saldo es ahora "<<SaldoEnBanco<<" $"<<endl;
                cout<<"¡La sacaste del estadio!"<<endl;
                cout<<"Ya has ganado bastante, deberias condierar ir a reclamar tu dinero."<<endl;
                cout<<"¿Desea jugar de nuevo? (y/n)"<<endl;
                cin>>answer;

                if (answer=='y')
                {
                  restartCraps = true;
                }
                else
                {
                  cout<<"!Gracias por jugar!"<<endl;
                  quitCraps = true;
                }
              }

              else if ( 500000 < SaldoEnBanco &&  SaldoEnBanco < 1000000)
              {
                cout<<"¡Partida ganada!, su saldo es ahora "<<SaldoEnBanco<<" $"<<endl;
                cout<<"¡Vamos aún puede aumentar sus ganancias! Arriesgese y siga jugando"<<endl;
                cout<<"¿Desea jugar de nuevo? (y/n)"<<endl;
                cin>>answer;

                if (answer=='y')
                {
                  restartCraps = true;
                }
                else
                {
                  cout<<"!Gracias por jugar!"<<endl;
                  quitCraps = true;
                }
              }

              else
              {
                cout<<"¡Partida ganada!, su saldo es ahora "<<SaldoEnBanco<<" $"<<endl;
                cout<<"¿Desea jugar de nuevo? (y/n)"<<endl;
                cin>>answer;

                if (answer=='y')
                {
                  restartCraps = true;
                }
                else
                {
                  cout<<"!Gracias por jugar!"<<endl;
                  quitCraps = true;
                }

              }

            }

            else  //PARTIDA INCOMPLETA
            {
              SaldoEnBanco=SaldoEnBanco;
              cout<<"Usted no ha completado el juego, su saldo es ahora "<<SaldoEnBanco<<" $"<<endl;
              cout<<"¿Desea jugar de nuevo? (y/n)"<<endl;
              cin>>answer;

              if (answer=='y')
              {
                restartCraps = true;
              }
              else
              {
                cout<<"!Gracias por jugar!"<<endl;
                quitCraps = true;
              }
            }
          }
        }

        cout<<"¿Desea seguir apostando?(y/n)"<<endl;
        cin>>answer;

        if(answer=='y')
        {
          cout<<"Su saldo es ahora "<<SaldoEnBanco<<" $"<<endl;
          restartApuesta = false;
        }

        else
        {
          cout<<"Su saldo final es "<<SaldoEnBanco<<" $"<<endl;
          cout<<"!Gracias por jugar!"<<endl;
          exit(0);
        }
      }

    }
  }
}
