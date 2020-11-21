#ifndef FUNCIONES_H
#define FUNCIONES_H

#endif // FUNCIONES_H

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <time.h>
#include <list>
#include <vector>

using namespace std;


string lectura ();
bool falla (string name);
map <string,map<string,int>> dic(string name);



bool encontrar (string nodo,map <string,map<string,int>> inicial);

map <string,map<string,int>> eliminar (string nodo,map <string,map<string,int>> inicial);


void mostrar(map <string,map<string,int>> inicial);

map <string,map<string,int>> crear (string nodo, map <string,map<string,int>> inicial);
map <string,map<string,int>> crear_azar (map<string,int> ram, map <string,map<string,int>> inicial);

string azar (int *B);

map <string,map<string,int>> modificar (string nodo, map <string,map<string,int>>inicial);



//________________________________________________________________________________________


map <string,map<string,list<string>>> base(map <string,map<string,int>> inicial);
