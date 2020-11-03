#include "leerBytes_a.h"

using namespace std;

void leerBytes(ifstream& file, long pos, int size){
  char chr;
  file.seekg( pos , ios::beg );
  for( int i = 0 ; i < size ; i++ ){
    chr = file.get();
    cout << chr;
  }
}
