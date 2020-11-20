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
