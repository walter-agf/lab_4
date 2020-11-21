#include "funciones.h"

string lectura()
{
    string nombre = "", name = "";
    cout << "\n\n\tIngrese el nombre del documento con la informacion de la red de enrrutadores\n\n--> ";cin >> nombre;
    name = "./" + nombre + ".txt";
    fstream prueba (name.c_str(), fstream::in);
    if (prueba.fail() == 1) name = "../lab_4/" + nombre + ".txt";
    prueba.close();
    return name;
}

bool falla(string name)
{
    fstream doc (name.c_str(), fstream::in);
    if (!doc.fail()) return false;
    return true;
}

map<string, map<string, int> > dic(string name)
{
    string info = "", use = "", use2 ="",use3="";
    int a = 0, longitud = 0,distancia = 0, comodin=0, mul=0;
    map <string,map<string,int>> inicial;

    fstream doc (name.c_str(), fstream::in);
    while (!doc.eof()){
        getline(doc,info);
        longitud = info.length();
        a = 0;

        use = "";
        use2 = "";
        use3 = "";
        distancia = 0;
        while(int(info[a]) != 32){
            use.push_back(info[a]);
            a++;
        }
        //cout << "\t"<< use << "\t";
        a++;
        while(int(info[a]) != 32){
            use2.push_back(info[a]);
            a++;
        }
        a++;
        while(a != longitud){
            use3.push_back(info[a]);
            a++;
        }
        a = 1;
        longitud = use3.length();
        mul = 1;
        while(a != longitud+1){
            comodin = int(use3[longitud - a]);
            comodin -= 48;
            //cout<< comodin << endl;
            comodin *=mul;
            mul *=10;
            distancia += comodin;
            a++;
        }
        //cout << distancia << endl;
        inicial[use].insert(pair <string,int> (use2,distancia));
        inicial[use2].insert(pair <string,int> (use,distancia));

        inicial[use].insert(pair <string,int> (use,0));

        //cout << info << endl;
    }

    return inicial;
}

void mostrar(map<string, map<string, int> > inicial)
{
    for (auto var : inicial){
        cout << var.first << "\t_______  ";
        for (auto var1 = var.second.begin(); var1 != var.second.end(); var1 ++){
            cout << var1 ->first << " -> " << var1->second << " ; ";
        }
        cout << endl;
    }
}

bool encontrar(string nodo, map<string, map<string, int> > inicial)
{
    bool esta = false;
    for (auto var : inicial){
        if (var.first == nodo){
            esta = true;
            break;
        }
    }
    return esta;
}

map<string, map<string, int> > eliminar(string nodo, map<string, map<string, int> > inicial)
{
    int conti = 0;
    bool ava = true;
    string eli= "";
    while (ava == true){
        cout << "\n\n\tQue desea realizar ?\n\n";
        cout << "\t1) Eliminar todo un nodo\n";
        cout << "\t2) Eliminar solo la coneccion de dos nodos\n";
        cout << "\n ---> "; cin >> conti;

        switch (conti) {

        case 1:{
            inicial.erase(nodo);
            for (auto var : inicial){
                inicial[var.first].erase(nodo);
            }
            ava = false;
            break;
        }

        case 2:{
            cout << "\n\n\tIngrese el nombre a eliminar dentro de [ " << nodo << " ]\n\n";
            cout << "\n ---> "; cin >> eli;

            bool esta = false;
            for (auto var : inicial[nodo]){
                if (var.first == eli){
                    esta = true;
                    break;
                }
            }

            if (esta == true){
                inicial[nodo].erase(eli);
                inicial[eli].erase(nodo);
            }
            ava = false;
            break;
        }

        default:{
            cout << "VALOR FUERA DE RANGO - REINGRESE";
            break;
        }
        }
    }

    //BARRIDO

    for (auto var : inicial){
        eli = "";
        for (auto var2 : inicial[var.first]){
            eli += var2.first;
        }
        cout << "\n\n" << eli << "\n\n";
        if (var.first == eli) inicial.erase(eli);
    }

    return inicial;
}

map<string, map<string, int> > crear(string nodo, map<string, map<string, int> > inicial)
{
    string name = "0";
    int valor = 0;
    cout << "\n\nIngrese los nombres de las conecciones del nuevo nodo, junto con su valor";
    cout << "\n(Cuando ingrese -1, como valor, dejara de resibir datos)";

    while (valor != -1){
        cout << "\n\n Nombre -->  "; cin >> name; cout << " Valor --> "; cin >> valor;
        bool esta = false;
        for (auto var : inicial){
            if (var.first == name){
                esta = true;
                break;
            }
        }
        if (esta == true){
            if (valor != -1){
                inicial[nodo].insert(pair <string,int> (name,valor));
            }
        }
    }
    return inicial;
}


map<string, map<string, int> > crear_azar(string nodo, map<string, map<string, int> > inicial)
{

}

string azar(int *B)
{
    string nodo = "";
    int A = 0, C = 0;

    while (true){
        srand(*B);
        C = rand()%1000;
        srand(time(NULL));//definimos un cambio de entorno para encontrar la variable
        A = rand() * C;
        A = A%100; // se encuentra el numero aleatorio
        if (A < 65 || A > 90 ){
            A += 100;
        }
        *B =(*B) * 7;
        if (A >=65 && A <= 90 ) break;
    }
    srand(A);
    *B =rand() * C;
    C = *B%10;
    //cout <<  "\n\n" << A << endl;
    nodo.push_back(char(A));
    if (C != 0 )nodo.push_back(char((*B%10) + 48));
    //cout << endl << nodo << endl;
    return nodo;
}
