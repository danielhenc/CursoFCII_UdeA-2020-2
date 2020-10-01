#include "quad_roots.h"

int main(){
	quad_solve q_solve;

	q_solve.set_coefs();
	q_solve.show_coefs();
	q_solve.poly_roots();

	return 0;
}

