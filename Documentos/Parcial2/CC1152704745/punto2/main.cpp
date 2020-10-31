#include "acc.h"

int main(){
	base_acc bacc_instance(69420.666);
	
	bacc_instance.cargar(314.33);
	bacc_instance.abonar(44.);

	bacc_instance.getSaldo();	

	return 0;
}

