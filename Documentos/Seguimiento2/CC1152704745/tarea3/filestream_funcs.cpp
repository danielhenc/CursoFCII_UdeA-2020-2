#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using std::ifstream;
using std::cout;
using std::cin;
using std::endl;
using std::string;

ifstream load_rfile(string);
int rfile_count(ifstream &);
void readBytes(ifstream &,long,int);

int main(){
	// Create ifstream instance to load an input file
	ifstream read_file;

	// Create a string variable to store the input file name and let the user input it
	string file_name;
	cout << "Input the name of the file to open (read olny): ";
	cin >> file_name;

	// Provide the file name to the load function
	read_file = load_rfile(file_name);

	// Define position from where to read characters, and how many characters to read and let user input them
	long pos;
	int nchar;

	cout << "From which position do you want to read the file from: ";
	cin >> pos;

	cout << "How many characters do you want to read: ";
	cin >> nchar;

	// Print characters from file
	readBytes(read_file,pos,nchar);
	
	return 0;
}

// ----- functions -----

// Load read file
ifstream load_rfile(string fname){
	// Try to load file. Raise exception otherwise
	try{
		// Create a ifstream instance and load the file with the name provided
		ifstream rfile(fname.c_str());

		// If the file could not open, throw an exception
		if (rfile.fail()) throw fname;	
		else{
			// notify if file was successfully read
			cout << "File " << fname << " successfully read, containing " << rfile_count(rfile) << " characters."  << endl;
		}
		// If the file was loaded succesfully, return the ifstream instance
		return rfile;
	}
	catch(string fname){
		// Print an error message to notify the user that the file can't be opened if the exception was thrown
		cout << "Could not open file: " << fname << endl;
		cout << "Can't open or does not exist" << endl;	

		exit(1);
	}
}

// Count characters in text file
int rfile_count(ifstream &rfile){
	// character count
	int ccount = 0;
	
	// read a line to count characters in it
	string rline;
	
	// while the file can be read, read a line and cout its characters
	while(std::getline(rfile,rline)){
		ccount += rline.length();	
	}	

	// return character count
	return ccount;
}

// read file characters
void readBytes(ifstream &rfile, long pos, int cnum){
	// Define character to be read
	char rchar;

	// Print how many chars will be read and from which position
	cout << "Reading " << cnum << " characters form position " << pos << endl;

	// print the characters from the given position to the last, given by pos+cnum
	for (long cpos = pos; cpos < (pos + cnum); cpos++){
		// get on the position cpos of the file to print the respective character
		rfile.seekg(cpos,std::ios::beg);

		// get the character from file
		rchar = rfile.get();

		// print the character
		cout << rchar;
	}

	// print a line jumpt at the end
	cout << endl;
}
