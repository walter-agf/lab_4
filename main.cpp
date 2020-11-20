#include "funciones.h"
int main()
{
    //Creacion de la matriz final
    string name = "", nodo = "";
    bool ava = true, esta = false;
    int conti = 0;
    map <string,map<string,int>> inicial;
    map <string,map<string,int>> final;
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
                //nodo = azar();
                esta = encontrar (nodo,inicial);
                while (esta == true){
                    //nodo = azar();
                    esta = encontrar (nodo,inicial);
                }
                //inicial = crear_azar (nodo,inicial);
                for (auto var : inicial){
                    nodo = "";
                    for (auto var2 : inicial[var.first]){
                        nodo += var2.first;
                    }
                    cout << "\n\n" << nodo << "\n\n";
                    if (var.first == nodo) inicial.erase(nodo);
                }
                //final = base (inicial);
            }

            default :{
                cout << "\n\nVALOR FUERA DE RANGO \n\n\n";
            }

            }

            break;
        }

        case 3:{
            nodo = "";
            cout << "\n\n\tIngrese el nombre del nodo a modificar\n";
            cout << "\n ---> "; cin >> nodo;
            esta = encontrar (nodo,inicial);
            cout << esta;
            if (esta == true){
                //inicial = modificar (nodo,inicial)
                //final = base (inicial);
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
                mostrar(inicial);
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
