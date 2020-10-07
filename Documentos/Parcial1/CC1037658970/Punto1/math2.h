/**
 * @author Valentina Roquemen Echeverry
 * @brief  Se diseña un a clase que calcula las raices de una ecuacion
 *		   cuadratica de la forma ax^2+bx+c. Los valores a,b y c son
 *         constantes. Se imprime los resultados en pantalla. 
 */
  
class Roots
{
	public :

	const static int parametros = 3; // Numero de parametros

   /**
   * @param arregloParametros  Arreglo que contiene: a,b y c respectivamente.
   */ 
  	Roots(const float[ parametros ] ); 

	/*
	* Fija los parametros de a,b,c ingresados por el usuario 
	*/
	void establecerParametros(const float[ parametros ]);

	/*
	* Realiza el calculo de las raices
	*/
	void calcularRaices(); 

	/*
	* Imprime en pantalla el resultado del calculo
	*/    
	void imprimirResultados();

	private :     
	
	float a,b,c; // Parametros de la ecuacion cuadratica
	float r_root1,i_root1=0; //Parte real e imaginaria de la raiz 1
	float r_root2,i_root2=0; //Parte real e imaginaria de la raiz 2

};
