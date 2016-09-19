/**
	Nombre(s):Manzano Saturnino Daniel
			  Peña Pescador Adair
	Descripccion:
	Esta clase resuelve el juego de las torres
	de Hanoi
*/

#include <iostream>
#include <stack>
#include <cmath>

class Hanoi
{
private:
	int Discos;
	int NumMovimientos;
	std::stack<int> origen;
	std::stack<int> auxiliar;
	std::stack<int> destino;
public:
	Hanoi(int Discos);
	void Resolver();
	void Par();
	void Impar();
	int verficar();
	void Imprimeaux(int A,int B,int C);
	void LlenarTorre();
	void MostrarTorres();
};
