
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;


int main()
{
  bool restart = false;
  bool quit = false;
  srand( time( NULL ) );


  while (quit==false)
  {
    restart = false;
    char answer;

    cout<< "Bienvenido, ¿desea jugar 'Craps' ? (y/n) "<<endl;
    cin>>answer;

    if (answer == 'n')
    {
      cout<<"Gracias por jugar"<<endl;
      quit = true;
    }

    else
    {
      quit = false;
    }


    while (quit==false && restart==false)
    {
      int n1;
      int n2;
      int s;

      n1 = 1 + rand() % 6;
      n2 = 1 + rand() % 6;
      s = n1 + n2;
      //s = 7;
      cout<<"El resultado del primer tiro de los dados es"<<endl;
      cout<<n1 << " y "<< n2<<endl;

      if (s==7 || s==11)
      {
        cout<<"¡Felicitaciones la suma es "<<s<<", usted ha ganado!"<<endl;
        cout<<"¿Desea jugar de nuevo? (y/n)"<<endl;
        cin>>answer;

        if (answer=='y')
        {
          restart = true;
        }
        else
        {
          cout<<"Gracias por jugar"<<endl;
          quit = true;
        }

      }

      else if (s==2 || s==3 || s==12)
      {
        cout<<"¡Craps! la suma es "<<s<<endl;
        cout<<"Usted ha perdido"<<endl;
        cout<<"¿Desea jugar de nuevo?  (y/n)"<<endl;
        cin>>answer;

        if (answer=='y')
        {
          restart = true;
        }
        else
        {
          cout<<"Gracias por jugar"<<endl;
          quit = true;
        }

      }


      else
      {
        int p;
        p=s;
        char answer2;
        cout<<"La suma es "<<p<<". Su punto ahora es "<<p<<endl;
        cout<<"¿Tirar los dados de nuevo? (y/n)"<<endl;
        cin>>answer2;

        if (answer2=='y')
        {
          quit = false;
        }
        else
        {
          quit = true;
        }

        while (quit==false && restart==false)
        {
          n1 = 1 + rand() % 6;
          n2 = 1 + rand() % 6;
          s = n1 + n2;

          if (s!=7)
          {
            cout<<"El resultado del tiro es"<<endl;
            cout<<n1<<" y "<<n2<<endl;

            if (s==p)
            {
              cout<<"¡Felicitaciones la suma es "<<s<<", usted ha ganado!"<<endl;
              cout<<"¿Desea jugar de nuevo?  (y/n)"<<endl;
              cin>>answer;
              if (answer=='y')
              {
                restart = true;
              }
              else
              {
                cout<<"Gracias por jugar"<<endl;
                quit = true;
              }

            }

            else
            {
              cout<<"La suma es "<<s<<endl;
              cout<<"¿Tirar los dados de nuevo? (y/n)"<<endl;
              cin>>answer2;
              if (answer2=='y')
              {
                quit = false;
              }
              else
              {
                quit = true;
              }

            }
          }

          else
          {
            cout<<"El resultado del tiro es"<<endl;
            cout<<n1<<" y "<<n2<<endl;
            cout<<"¡Craps! la suma es "<<s<<endl;
            cout<<"Usted ha perdido"<<endl;
            cout<<"¿Desea jugar de nuevo?  (y/n)"<<endl;
            cin>>answer;

            if (answer=='y')
            {
              restart = true;
            }
            else
            {
              cout<<"Gracias por jugar"<<endl;
              quit = true;
            }
      }

    }

    if (answer2=='n')
    {
      cout<<"Gracias por jugar"<<endl;
      quit = true;
    }

  }

}
}
}
