/*
Se le pide crear un arbol binario al que se le pueda ingresar los valores: 
35,15,80,10,20,18,17,50,100,70,40. Este arbol binario debe tener numeros 
menores  a la raiz a su izquierda y numeros mayores a la derecha. 
Mostrar sus tres recorridos, en orden, preorden y post orden,  y 
demostrar la funcion Buscar.

*/

#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

//Definimos la estructura de  los nodos que vamos a usar
struct estructuraNodo{
	//nodo 
	int valor;
	//punteros
	struct estructuraNodo *izquierda;
	struct estructuraNodo *derecha;
};

//alias
typedef struct estructuraNodo *nodo;
//Funcion insertar.
/*
Si la raiz es nula, se crea un nodo
Si valor < raiz, se inserta un nodo a la izquierda
Si valor > raiz, se inserta un nodo a la derecha
*/
void insertar(int valor,nodo &raiz){
	if(raiz == NULL){
		//Creamos el nodo nuevo
		nodo nuevo = new (struct estructuraNodo);
		//Asignamos un valor
		nuevo->valor = valor;
		//puntero derecho e izquierdo apuntan a null
		nuevo->izquierda = NULL;
		nuevo->derecha = NULL;
		raiz = nuevo;
	}else{
		//cuando es mayor, a la derecha
		if(valor > raiz->valor){
			insertar(valor,raiz->derecha);
		}//cuando es menor, a la izquierda
		else if(valor < raiz->valor){
			insertar(valor,raiz->izquierda);
		}else{
			// Por si hay numeros repetidos
		}
	}
}


// ------- RECORRIDOS ----------
//	Preorden 		(Raiz) Izquierdo Derecho
//	Inorden  		Izquierdo (Raiz) Derecho *
//	Postorden		Izquierdo Derecho (Raiz)	

void preorden(nodo raiz){
	if(raiz != NULL){
		cout<<raiz->valor<<", ";
		preorden(raiz->izquierda);
		preorden(raiz->derecha);
	}
}

void inorden(nodo raiz){
	if(raiz != NULL){
		inorden(raiz->izquierda);
		cout<<raiz->valor<<", ";
		inorden(raiz->derecha);
	}
}

void postorden(nodo raiz){
	if(raiz != NULL){
		postorden(raiz->izquierda);
		postorden(raiz->derecha);
		cout<<raiz->valor<<", ";
	}
}
//Funcion busqueda
bool buscar(nodo raiz,int numero){
	if(raiz != NULL){
		if(raiz->valor == numero){
			return true;
		}else if(numero > raiz->valor){
			return buscar(raiz->derecha,numero);
		}else if(numero < raiz->valor){
			return buscar(raiz->izquierda,numero);
		}else{
			return false;
		}
	}
}

int main(){
	//Creamos nuestro arbol con tipo nodo
	nodo arbol = NULL;
	//insertar(35,arbol);
	int numeros[] = {35,15,80,10,20,18,17,50,100,70,40};
	int sizeArray = (sizeof(numeros)/sizeof(*numeros));
	
	for(int i=0 ; i < sizeArray; i++){
		insertar(numeros[i],arbol);
	}
	

	cout<<endl<<"PREORDEN : "<<endl;
	preorden(arbol);
	cout<<endl<<"INORDEN : "<<endl;
	inorden(arbol);
	cout<<endl<<"POSTORDEN : "<<endl;
	postorden(arbol);
	
	int busquedaNumero = 0;
	
	cout<<endl<<endl<<"Ingrese numero a buscar:";
	cin>>busquedaNumero;
	cout<<endl;
	
	cout<< ( buscar(arbol,busquedaNumero) ? "Valor encontrado :) ":
	 "Numero no encontrado :( " )<<endl;
	
	getch();
	return 0;
	
}
