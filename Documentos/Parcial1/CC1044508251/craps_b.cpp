#include<iostream>
#include<time.h>

using namespace std;

int tirar_dados()
{
  return 1 + rand() % 6;
}

int craps()
{
  int d1 = 0, d2 = 0, dplus = 0;
  int i = 0, point = 0;
  
  d1 = tirar_dados();
  d2 = tirar_dados();
  
  dplus = d1 + d2;
  
  cout << "\nLos dados fueron (" << d1 << ", " << d2 << ") y la suma fue " << dplus << ".\n"<< endl;
  
  if(dplus==7 || dplus==11)
    {
      cout << "Ganaste!" << endl;
      return 1;
    }
  else
    {
      
      if(dplus==2 || dplus==3 || dplus==1)
	{
	  cout << "Perdiste!" << endl;
	  return 0;
	}
      
      if( (dplus>=4 && dplus<=6) || (dplus>=8 && dplus<=10) )
	
	{  
	  point = dplus;
	  
	  while(i==0)	
	    {
	      cout << "Tira de nuevo" << endl;
	      
	      d1 = tirar_dados();
	      d2 = tirar_dados();
	      
	      dplus = d1 + d2;
	      
	      cout << "Punto: " << point << " --- Suma: " << dplus << endl;
	      
	      if(dplus==7)
		{
		  cout << "Perdiste!" << endl;
		  i=1;
		  return 0;
		}
	      
	      if (dplus==point)
		{
		  cout << "Ganaste!" << endl;
		  i=1;
		  return 1;
		}
	    } 
	}
    }
}

int main()
{

  cout << "\n BIENVENIDO A CRAMPS - APUESTAS \n" << endl;
    
  srand(time(NULL));

  int game, i=0;
  float saldoEnBanco = 1000000, bet;
  float saldoInicial = saldoEnBanco;

  while(i==0)
    {
      
      cout << "Cuanto desea apostar: "; 
      cin >> bet;
      
      while(bet>saldoEnBanco)
	{
	  cout << "Valor invalido, ingreselo nuevamente: "; 
	  cin >> bet;      
	}

      game = craps();
  
      if(game==1)
	{
	  saldoEnBanco += bet;
	  cout << "Su saldo es: " << saldoEnBanco << "."<< endl;
	}
      else
	{
	  saldoEnBanco -= bet;
	  
	  if(saldoEnBanco<0)
	    { 
	      cout << "Su saldo es: " << 0 << "."<< endl;
	    }

	  cout << "Su saldo es: " << saldoEnBanco << "."<< endl;
	}

      if(saldoEnBanco<=0)
	{ 
	  cout << "\nLo siento. Se quedo sin fondos." << endl;
	  cout << "Vuelve pronto." << endl;
	  i=1;
	}
	     
      if(saldoEnBanco<=saldoInicial/4 && saldoEnBanco>0)
	{
	  cout << "\nUsted se esta quebrando, no le parece." << endl;
	}
      
      if(saldoEnBanco<=saldoInicial/2 && saldoEnBanco>saldoInicial/4)
	{
	  cout << "\nHagale, arriesgue, no pasa nada." << endl;
	}
      
      if(saldoEnBanco>saldoInicial/2 && saldoEnBanco<=3*saldoInicial/2)
	{
	  cout << "\nVea que todavia tiene plata, sin miedo." << endl;
	}
      
      if(saldoEnBanco>3*saldoInicial/2)
	{
	  cout << "\nEstas ganando plata ya, cambie la fichas por plata." << endl;
	}

      if(saldoEnBanco!=0)
	{  
	  cout << "\nSi desea apostar nuevamente escriba 0, sino se quedara con su saldo actual." << endl;
	  cin >> i;

	  cout << "================================================================\n" << endl;
	}
      
      if(i!=0)
	{
	  cout << "\nSu saldo final fue de: " << saldoEnBanco << "\n"<< endl;
	}
    }
      
  return 0;
}
