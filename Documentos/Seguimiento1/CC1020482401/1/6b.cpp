#include <iostream>
#include <cmath>
#include <fstream>


using std::cout; 
using std::cin; 
using std::ofstream;


ofstream file("normal_data.txt"); // file initialization for normal function data


void normal_function(float, float, int, float, float); // function to write data to file


int main(int argc, char const *argv[])
{
	float mu, sigma, a, b; 
	int n;

	cout << "Ingrese el valor donde quiere centrar la distribucion y la desviacion (mu sigma): \n";
	cin >> mu >> sigma;
	cout << "Ingrese el numero de puntos y el intervalo para la graficacion (n a b): \n";
	cin >> n >> a >> b;

	normal_function(mu, sigma, n, a, b);
	system("gnuplot normal_graph.gp"); // bash command for graph the function 

	return 0;
}


void normal_function(float mu, float sigma, int n, float a, float b)
{
	float N, z;
	float dx = (b-a) / n; 		

	N = 1 / (sigma * sqrt(2 * M_PI));

	for(float x = a; x <= b; x = x + dx)
	{
		z = (x - mu) / sigma;
		file << "    " << N * exp(-0.5 * pow(z, 2)) << "\n";
	}

	file.close();
}