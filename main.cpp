#include "funciones.h"
int main()
{
    //Creacion de la matriz final
    string name = "";
    bool ava = true;
    map <string,map<string,int>> inicial;
    //Lectura del archivo

    while (ava){
        name = lectura();
        ava = falla (name);
        if (ava ==true) cout << "ERROR - en la lectura del nombre del archivo";
    }
    //Creacion del diccionario inicial
    inicial = dic(name);


    for (auto var : inicial){
        cout << var.first << "\t_______  ";
        for (auto var1 = var.second.begin(); var1 != var.second.end(); var1 ++){
            cout << var1 ->first << " -> " << var1->second << " ; ";
        }
        cout << endl;
    }

    //Creacion de base

    //________________________________________________________

    //MENU


    system("pause()");
    return 0;
}
