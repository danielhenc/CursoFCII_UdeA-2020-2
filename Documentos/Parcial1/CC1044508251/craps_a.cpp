#include<iostream>
#include<time.h>

using namespace std;

int tirar_dados()
{
  return 1 + rand() % 6;
}

int main()
{
  srand(time(NULL));

  int d1 = 0, d2 = 0, dplus = 0;
  int i = 0, point = 0;
  
  d1 = tirar_dados();
  d2 = tirar_dados();
  
  dplus = d1 + d2;
 
  cout <<"Dados ("<< d1 <<", "<< d2 << ") y su suma es: " << dplus << endl;
  
  if(dplus==7 || dplus==11)
    {
      cout << "Ganaste!" << endl;
    }
  else
    {
      
      if(dplus==2 || dplus==3 || dplus==1)
	{
	  cout << "Perdiste!" << endl;
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
	      
	      cout << "Punto: " << point << " Suma: " << dplus << endl;

	      if(dplus==7)
		{
		  cout << "Perdiste!" << endl;
		  i=1;
		}
	      
	      if (dplus==point)
		{
		  cout << "Ganaste!" << endl;
		  i=1;
		}
	    } 
	}
    }
  
  return 0;
}
