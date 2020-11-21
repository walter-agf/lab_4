#include "funciones.h"
int main()
{
    //Creacion de la matriz final
    string name = "", nodo = "";
    bool ava = true, esta = false;
    int conti = 0;
    map <string,map<string,int>> inicial;
    map <string,map<string,int>> final;
    int B = 0;
    map <string,int> ram;
    //Lectura del archivo

    while (ava){
        name = lectura();
        ava = falla (name);
        if (ava ==true) cout << "ERROR - en la lectura del nombre del archivo";
    }
    //Creacion del diccionario inicial
    inicial = dic(name);

    //mostrar(inicial);

    //Creacion de base

    //final = base (inicial);

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
            cout << "\n\n\tQue desea realizar ?\n\n";
            cout << "\t1) Ver matriz especifica\n";
            cout << "\t2) Ver matriz completa\n";

            cout << "\n ---> "; cin >> conti;

            switch (conti) {

            case 1:{
                break;
            }

            case 2:{
                break;
            }

            default :{
                cout << "\n\nVALOR FUERA DE RANGO \n\n\n";
            }

            }

            break;
        }

        case 2:{

            cout << "\n\n\tQue desea realizar ?\n\n";
            cout << "\t1) Ingresar nombre del nodo\n";
            cout << "\t2) Crear nodo aleatorio\n";

            cout << "\n ---> "; cin >> conti;

            switch (conti) {

            case 1:{
                nodo = "";
                cout << "\n\n\tIngrese el nombre del nodo a crear\n";
                cout << "\n ---> "; cin >> nodo;
                esta = encontrar (nodo,inicial);
                if (esta == false){
                    inicial = crear (nodo,inicial);
                    //mostrar(inicial);
                    //final = base (inicial);
                }
                else {
                    cout << "\n\nCLAVE DADA ESTA DENTRO DE LA RED, NO SE PUEDE CREAR, DIRIJASE A MODIFICAR\n\n\n";
                }
                break;
            }

            case 2:{
                srand(time(NULL));
                B = rand();
                nodo = azar(&B);
                esta = encontrar (nodo,inicial);
                while (esta == true){
                    nodo = azar(&B);
                    esta = encontrar (nodo,inicial);
                }
                ram[nodo] = 0;
                for (int i = 0; i < 24 ;i++){
                    nodo = azar(&B);
                    if (ram.find(nodo) == ram.end()){
                        srand(B);
                        conti = rand();
                        conti %= 100;
                        if (conti != 0)ram[nodo] = conti;
                    }
                }
                inicial = crear_azar (ram,inicial);
                //____________________________________________
                //mostrar(inicial);
                esta = false;
                for (auto var : inicial){
                    nodo = "";
                    for (auto var2 : inicial[var.first]){

                        for (auto var3 : inicial){
                            if (var2.first == var3.first)nodo += var2.first;
                        }
                    }
                    //cout << "\n" << nodo << "\t" << var.first;

                    if (var.first == nodo) esta = true;
                }
                if (esta == true) inicial.erase(nodo);

                ram.clear();

                //mostrar(inicial);
                //____________________________________________

                //final = base (inicial);

                cout << "\n\n\tVALOR AGREGADO CORRECTAMENTE\n\n";
                break;
            }

            default :{
                cout << "\n\nVALOR FUERA DE RANGO \n\n\n";
                break;
            }
            }
            break;
        }

        case 3:{
            nodo = "";
            cout << "\n\n\tIngrese el nombre del nodo a modificar\n";
            cout << "\n ---> "; cin >> nodo;
            esta = encontrar (nodo,inicial);
            if (esta == true){
                inicial = modificar (nodo,inicial);
                //final = base (inicial);
                //mostrar(inicial);
                cout << "\n\n\tMODIFICACION COMPLETA\n\n\n";
            }
            else {
                cout << "\n\nCLAVE DADA NO ESTA DENTRO DE LA RED, NO SE PUEDE MODIFICAR\n\n\n";
            }
            break;
        }

        case 4:{
            nodo = "";
            cout << "\n\n\tIngrese el nombre del nodo a proceder con la eliminacion\n";
            cout << "\n ---> "; cin >> nodo;
            esta = encontrar (nodo,inicial);
            if (esta == true){
                inicial = eliminar (nodo,inicial);
                //mostrar(inicial);
                //final = base (inicial);
                cout << "\n\n\tELIMINACION CULMINADA CON EXITO\n\n";
            }
            else {
                cout << "\n\nCLAVE DADA NO ESTA DENTRO DE LA RED, NO SE PUEDE ELIMINAR\n\n\n";
            }
            break;
        }

        case 5:{
            break;
        }

        case 6:{
            break;
        }

        case 7:{
            ava = true;
            break;
        }
        default :{
            cout << "\n\nVALOR FUERA DE RANGO -- REINGRESE\n\n\n";
        }
        }
    }
    return 0;
}
