/**
Nombre(s):Manzano Saturnino Daniel
		  Peña Pescador Adair
*/

#include "Hanoi.h"
/**
Constructor 
@params Discos
@result void
Calcula el numero de movimientos que hara la 
torre
*/
Hanoi::Hanoi(int Discos)
{
	this->Discos= Discos;
	this->NumMovimientos=pow(2,this->Discos);
}

/**
Resuelve el juego de las Torres 
de Hanoi con N discos
dependiendo de la condicion llama los 
metodos para resolver por par o impar
despues muestra el resultado 
@params void
@result void
*/
void Hanoi::Resolver()
{

	if (this->Discos%2 == 0)
	{
		this->Par();	
		this->MostrarTorres();
	}else
	{
		this->Impar();
		this->MostrarTorres();
	}

}
/**
Verificar
@paraments:void 
@Result:void
llena la primera torre
*/
void Hanoi::LlenarTorre()
{
	for(int i= this->Discos; i>0 ; --i)
	{
		this->origen.push(i);
	}
}
/**
Mostrar Torres
@paraments:void 
@Result:void 
Muestra las torres llama al metodo 
y para hacerlo lo recorre desde el valor 
que arroje verificar hasta 0 muestra cada 
torre segun el caso  
*/

void Hanoi::MostrarTorres()
{
	std::stack<int> auxO;
	std::stack<int> auxA;	
	std::stack<int> auxD;
	for(int i=this->verficar(); i>0 ;--i)
	{
		if(i<=origen.size())
		{
			std::cout<<origen.top()<<" ";
			auxO.push(origen.top());
			origen.pop();	
		}else{
			std::cout<<"*"<<" ";
		}
		if(i<=auxiliar.size())
		{
			std::cout<<auxiliar.top()<<" ";
			auxA.push(auxiliar.top());
			auxiliar.pop();	
		}else{
			std::cout<<"*"<<" ";
		}
		if(i<=destino.size())
		{
			std::cout<<destino.top()<<std::endl;
			auxD.push(destino.top());
			destino.pop();	
		}else{
			std::cout<<"*"<<std::endl;
		}	
	}

}
/**
Verificar
@paraments:void 
@Result:int un entero 
verifica el tamaño de las torres 
para poder ser llamado 
*/
int Hanoi::verficar()
{
	int mayor;
	if(this->origen.size() > this->auxiliar.size() && this->origen.size() > this->destino.size())
	{
		mayor=origen.size();
	}else if(this->auxiliar.size() > this->origen.size() && this->auxiliar.size() > this->destino.size())
	{
		mayor=auxiliar.size();
	}else
	{
		mayor=destino.size();	
	}
	return mayor;
}
/**
Par
@paraments:void 
@Result: void
Resuelve la torre si es numero par
y ahora hace un for y posteriormente hace el algoritmo
desarrollado en clase
*/

void Hanoi::Par()
{
	for (int i = 1; i < this->NumMovimientos; ++i)
		{
			
			int O=(this->origen.empty())?INFINITY:this->origen.top();
			int A=(this->auxiliar.empty())?INFINITY:this->auxiliar.top();
			int D=(this->destino.empty())?INFINITY:this->destino.top();
			this->Imprimeaux(A,O,D);
			if (i%3==1)
			{//movimento entre origen y auxiliar
				if (O>A)
				{
					this->origen.push(this->auxiliar.top());
					this->auxiliar.pop();
				}else
				{
					this->auxiliar.push(this->origen.top());
					this->origen.pop();
				}
			}
			if (i%3==2)
			{//movimento entre origen y destino
				if ( O>D)
				{
					this->origen.push(this->destino.top());
					this->destino.pop();
				}else
				{
					this->destino.push(this->origen.top());
					this->origen.pop();
				}	
			}
			if (i%3==0)
			{//movimento entre destino y auxiliar
				if ( A>D)
				{
					this->auxiliar.push(this->destino.top());
					this->destino.pop();
				}else
				{
					this->destino.push(this->auxiliar.top());
					this->auxiliar.pop();
				}
			}
		}

}
/**
Impar
@paraments:void 
@Result: void
Resuelve la torre si es numero impar
y ahora hace un for y posteriormente hace el algoritmo
desarrollado en clase
*/
void Hanoi::Impar()
{
		for (int i = 1; i < this->NumMovimientos; ++i)
		{

			int O=(this->origen.empty())?INFINITY:this->origen.top();
			int A=(this->auxiliar.empty())?INFINITY:this->auxiliar.top();
			int D=(this->destino.empty())?INFINITY:this->destino.top();
			this->Imprimeaux(A,O,D);
			std::cout<<O<<" "<<A<<" "<<D<<std::endl;
			if (i%3==1)
			{//movimento entre origen y destino
				
				if ( O>D)
				{

					this->origen.push(this->destino.top());
					this->destino.pop();
				}else
				{
					this->destino.push(this->origen.top());
					this->origen.pop();
				}	


			}
			if (i%3==2)
			{//movimento entre origen y auxiliar
				
				if (O>A)
				{
					this->origen.push(this->auxiliar.top());
					this->auxiliar.pop();
				}else
				{
					this->auxiliar.push(this->origen.top());
					this->origen.pop();
				}
			}
			if (i%3==0)
			{//movimento entre destino y auxiliar
				if ( A>D)
				{
					this->auxiliar.push(this->destino.top());
					this->destino.pop();
				}else
				{
					this->destino.push(this->auxiliar.top());
					this->auxiliar.pop();
				}
			}
		}
}
/**
Imprimeaux
@paraments: int,int,int tres enteros
@Result: void
este metodo se encarga de imprimir movimiento 
a movimiento primero pregunta si los 
los discos son mayores a segunda torre 
si esto se cumple imprime B si no un caracter
despues entra a un segundo if y pregunta 
si se cumple que los discos son mayores a la torre
A si es asi imprime a si no un caracter 
asi lo mimso para la torre c 
*/
void Hanoi::Imprimeaux(int A, int B, int C){
	if(Discos>=B){
		std::cout<<B<<" ";
	}else{
		std::cout<<"*"<<" ";
	}if(Discos>=A){
		std::cout<<A<<" ";
	}else{
		std::cout<<"*"<<" ";	
	}if(Discos>=C){
		std::cout<<C<<std::endl;
	}else{
		std::cout<<"*"<<std::endl;
	}
std::cout<<"---------------------------------------------"<<std::endl;
}
