namespace entFrac
{
	//Funcion que entrega la parte entera de un numero
	int entero(float a)
	{
		return(a);
	}
	//Funcion que entrega la parte decimal de un munero utilizando la funcion "entero()"
	float fraccion(float a)
	{
		return(a - entero(a));
	}
}
