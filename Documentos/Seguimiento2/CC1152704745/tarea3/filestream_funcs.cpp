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
long rfile_count(ifstream &);
void readBytes_a(ifstream &,long,int);
void readBytes_b(ifstream &,long,int,char *);

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
	readBytes_a(read_file,pos,nchar);
	
	// Define an array of chars to store the extracted chars from the file
	const int cs_len = nchar+1;
	char read_chars[cs_len];

	// Fill char array with the extracted chars
	readBytes_b(read_file,pos,nchar,read_chars);
	
	// Print char array of extracted chars from file
	cout << "Saved array contains: " << read_chars << endl;

	// Close file
	read_file.close();

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
			
		// notify if file was successfully read
		cout << "File " << fname << " successfully read, containing " << rfile_count(rfile) << " characters."  << endl;
		
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
long rfile_count(ifstream &rfile){
	// Place the marker at the end of the file
	rfile.seekg(0L,std::ios::end);
	
	// return position of the marker placed at the end
	return rfile.tellg() - 1L;
}

// read file characters
void readBytes_a(ifstream &rfile, long pos, int cnum){
	// Define character to be read
	char rchar;

	// Print how many chars will be read and from which position
	cout << "Reading " << cnum << " characters form position " << pos << endl;

	// print the characters from the given position to the last, given by pos+cnum
	for (long cpos = pos; cpos <= (pos + cnum); cpos++){
		// get on the position cpos of the file to print the respective character
		rfile.seekg(cpos,std::ios::beg);

		// get the character from file
		rfile.get(rchar);

		// print the character
		cout << rchar;
	}

	// print a line jumpt at the end
	cout << endl;
}

// read file characters and save them in an array
void readBytes_b(ifstream &rfile, long pos, int cnum, char *strpos){
	// Define character to be read
	char rchar;

	// Print how many chars will be read and from which position
	cout << "Saving " << cnum << " characters form position " << pos << endl;

	// print the characters from the given position to the last, given by pos+cnum
	for (long cpos = pos; cpos <= (pos + cnum); cpos++){
		// get on the position cpos of the file to print the respective character
		rfile.seekg(cpos,std::ios::beg);

		// get the character from file
		rfile.get(rchar);

		// save char on array and increment the pointer position 
		*strpos++ = rchar;
	}
	// Add an EOL character to the char array
	*strpos = '\0';
}
