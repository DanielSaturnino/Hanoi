/**
Nombre(s):Manzano Saturnino Daniel
		  Peña Pescador Adair
*/
#include "Hanoi.h"

int main()
{
	
	std::cout<<"Torres de Hanoi"<<std::endl;
	Hanoi H(4);
	H.LlenarTorre();
	H.Resolver();
	return 0;
}
