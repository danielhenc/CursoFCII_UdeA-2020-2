#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>  
#include <fstream>

#define WORDS_PATH "palabras.txt"


using namespace std;

void escoger_palabra(int *);
void jugar(void);
int turno(int *, string *);
void mostrar_palabra(string);
int numero_de_letras(void);
void presentar(void);
void dibujar(int);

string palabra;

int main(int argc, char const *argv[])
{
	int play = 1;
	int nivel;

	srand(time(NULL));

	presentar();
	cout << "Bienvenido jugador,";

	while(play != -1){

		cout << "selecciona la dificultad para continuar: " << endl;
		cout << "1. Facil" << endl;
		cout << "2. Medio" << endl;
		cout << "3. Dificil" << endl;
		cout << "4. exit" << endl;
		cin >> nivel;
	
		if(nivel == 4) break ;

		escoger_palabra(&nivel);
		cout << "main" <<endl;
		cout << palabra << endl;
		jugar();

		cout << "Bien jugado! Presiona cualquier tecla para volver a jugar o -1 para salir" << endl;
		cin >> play;
	}

	return 0;
}

void escoger_palabra(int *nivel){

	vector <string> lista_palabras;
	string palabra_aux;
	ifstream archivo_palabras(WORDS_PATH);

	if (archivo_palabras.fail()){
      cout << "No se pudo abrir el archivo" << endl;
      exit( 1 );
    }

    while(archivo_palabras >> palabra_aux){
    	
    	switch(*nivel){
    		case 1:
    			if (palabra_aux.length() <= 7 ) 
    				lista_palabras.push_back(palabra_aux);
    			break;
    		case 2:
    			if (palabra_aux.length() > 7  && palabra_aux.length() <= 11) 
    				lista_palabras.push_back(palabra_aux);
    			break;
    		case 3:
    			if (palabra_aux.length() > 11 ) 
    				lista_palabras.push_back(palabra_aux);
    			break;
    		default:
    			if (palabra_aux.length() <= 7 ) 
    				lista_palabras.push_back(palabra_aux);
    			break;
    	}
    }

    int i = rand() % lista_palabras.size();

    palabra = lista_palabras.at(i);
}


void jugar(void){

	int intento = 0;
	int numero_de_letras_restantes = numero_de_letras();
	int stop = 0;
	bool winner = false;
	string letras_adivinadas = " ";

	cout << "Comience...\n" << endl;

	while(stop == 0){
		
		numero_de_letras_restantes += turno(&intento, &letras_adivinadas);
		
		if(intento == 8) break;

		if (numero_de_letras_restantes == 0){
			winner = true;
			break;
		}
	}

	if(winner){
		dibujar(-1);
		cout << "FELICITACIONES USTED GANO" << endl;	
	}
	else{
		cout << "YA SE MURIO, MEJOR SUERTE LA PROXIMA" << endl;	
	}

}

int turno(int *intento, string *letras_adivinadas){
	char letra;

	cout << "Palabra: " ;
	mostrar_palabra(*letras_adivinadas);
	cout << endl;
	dibujar(*intento);
	cout << "Letra: ";
	cin >> letra;

	if (palabra.find(letra) != string::npos)
		(*letras_adivinadas).append(letra);
		return -1;	
	else
		*intento++;
	
	return 0;

}


void mostrar_palabra(string letras_adivinadas){
	
	string palabra_aux(palabra.length(), '-');

	int i = palabra.find(letras_adivinadas);

	while(i != string::npos){
		palabra_aux.replace(i, 1, "F");
		i = palabra.find(letras_adivinadas, i + 1);
	}

	cout << palabra_aux;
}


int numero_de_letras(void){
	int contador;
	string letras;

	for (int i = 0; i < palabra.length(); i++)
		contador = (letras.find(palabra[i]) != strng::npos) ? contador + 1;

	return contador;
}


void dibujar(int intento){
    switch (intento){
	    case 0:
	        cout << "__________\n|         |\n|\n|\n|\n|\n|\n|";
	        break;
	    case 1:
	        cout << "__________\n|         |\n|         0\n|\n|\n|\n|\n|";
	        break;
	    case 2:
	        cout << "__________\n|         |\n|         0\n|         |\n|\n|\n|\n|";
	        break;
	    case 3:
	        cout << "__________\n|         |\n|         0\n|         |\n|         |\n|\n|\n|";
	        break;
	    case 4:
	        cout << "__________\n|         |\n|         0\n|        /|\n|         |\n|\n|\n|";
	        break;
	    case 5:
	        cout << "__________\n|         |\n|         0\n|        /|\\\n|         |\n|\n|\n|";
	        break;
	    case 6:
	        cout << "__________\n|         |\n|         0\n|        /|\\\n|         |\n|        /\n|\n|";
	        break;
	    case 7:
	        cout << " _________\n|         |\n|         0\n|        /|\\\n|         |\n|        / \\\n|\n|\n";
	        break;
	    case -1: //GANADOR
	        cout << "__________\n|         |\n|         \n|      0\n|     \\|/\n|      |\n|     / \\\n";
	        break;
	    default:
	    	break;
    }
    cout << endl;
}


void presentar(){
	cout << R"(
	                 8888888888 888
	                 888        888                     __________
	                 888        888                    |         |
	                 8888888    888                    |         0
	                 888        888                    |        /|\
	                 888        888                    |        / \
	                 888        888                    |
	                 8888888888 888                    |



	                          888                                             888
	                          888                                             888
	                          888                                             888
	                  8888b.  88888b.   .d88b.  888d888 .d8888b  8888b.   .d88888  .d88b.
	                     "88b 888 "88b d88""88b 888P"  d88P"        "88b d88" 888 d88""88b
	                 .d888888 888  888 888  888 888    888      .d888888 888  888 888  888
	                 888  888 888  888 Y88..88P 888    Y88b.    888  888 Y88b 888 Y88..88P
	                 "Y888888 888  888  "Y88P"  888     "Y8888P" Y888888  "Y88888  "Y88P"
	    )" << endl;//'\n';
}