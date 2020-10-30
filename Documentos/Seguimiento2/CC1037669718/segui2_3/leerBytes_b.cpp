#include "leerBytes_b.h"

using namespace std;

void leerBytes(ifstream& file, long pos, int size, string* output_adress){
  file.seekg( pos , ios::beg );
  for( int i = 0 ; i < size ; i++ ){
    (*output_adress).append( string( 1 , file.get() ) );
  }
}
