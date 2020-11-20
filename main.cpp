#include "funciones.h"
int main()
{
    //Creacion de la matriz final
    string name = "";
    bool ava = true;
    int conti = 0;
    map <string,map<string,int>> inicial;
    //Lectura del archivo

    while (ava){
        name = lectura();
        ava = falla (name);
        if (ava ==true) cout << "ERROR - en la lectura del nombre del archivo";
    }
    //Creacion del diccionario inicial
    inicial = dic(name);

    /*
    for (auto var : inicial){
        cout << var.first << "\t_______  ";
        for (auto var1 = var.second.begin(); var1 != var.second.end(); var1 ++){
            cout << var1 ->first << " -> " << var1->second << " ; ";
        }
        cout << endl;
    }
    */

    //Creacion de base

    //________________________________________________________

    //MENU
    cout << "\n\nRED CREADA CON EXITO\n";
    while (!ava){

        cout << "\n\n\tQue desea realizar ?\n\n";
        cout << "\t1) Ver matriz\n";
        cout << "\t2) Ingresar nuevo nodo\n";
        cout << "\t3) Modificar nodo\n";
        cout << "\t4) Eliminar nodo\n";
        cout << "\t5) Saber distancia entre nodos\n";
        cout << "\t6) Imprimir camino\n";
        cout << "\t7) SALIR\n";

        cout << "\n ---> "; cin >> conti;

        switch (conti) {

        case 1:{
            break;
        }

        case 2:{
            break;
        }

        case 3:{

        }

        case 4:{

        }

        case 5:{

        }

        case 6:{

        }

        case 7:{
            ava = true;
            break;
        }
        default :{
            cout << "\n\nVALOR FUERA DE RANGO -- REINGRESE";
        }
        }
    }
    system("pause()");
    return 0;
}
