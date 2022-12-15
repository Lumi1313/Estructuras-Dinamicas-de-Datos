#include<stdio.h>
#include <stdlib.h>
#include<limits.h>
#include <iostream>
#include <queue> //Importar esto hace mas facil todo
using namespace std;

// void para la funcion de mostrar el queue
void display_queue(queue<string> q);

int main() {

  // crear queue
  queue<string> animals;

  // insertar al queue
  animals.push("Gato");
  animals.push("Perro");
  animals.push("Zorro");
  
  cout << "Queue inicial: ";
  display_queue(animals);
  
  //quitar elementos del queue
  animals.pop();
  
  cout << "Queue final: ";
  display_queue(animals);
  
  return 0;
}

// funcion para mostrar el queue
void display_queue(queue<string> q) {
  while(!q.empty()) {
    cout << q.front() << ", ";
    q.pop();
  }

  cout << endl;
}
