namespace leerBytes
{
	//Funcion para el punto 6.a
	void leerBytesa(ifstream& archivo, long desp, int numcar)
	{
		//Variable para almacenar los caracteres
  	char texto;
		//Se mueve a la posición de desplazamiento indicada
  	archivo.seekg(desp, ios::beg);
		//Ciclo para obtener la cantidad de caracteres deseada
  	for(int i = 0; i < numcar; i++)
		{
  	  texto = archivo.get();
  	  cout << texto;
  	}
	}

	//Funcion para el punto 6.b
	void leerBytesb(ifstream& archivo_entrada, long desp, int numcar, string nombre_salida)
	{
		//Arreglo para almacenar todos los caracteres
		char texto[numcar] = {};
		//Declara el objeto de flujo de salida
		ofstream archivo_salida;
		//Se mueve a la posición de desplazamiento indicada
  	archivo_entrada.seekg(desp ,ios::beg);
		//Ciclo para obtener la cantidad de caracteres deseada
  	for( int i = 0 ; i < numcar ; i++ )
		{
  	  texto[i] = archivo_entrada.get();
	  }
		//Se abre el archivo de salida
		archivo_salida.open(nombre_salida.c_str());
		//Escribir los caracteres en el archivo de salida
		archivo_salida << texto;
	}

}
