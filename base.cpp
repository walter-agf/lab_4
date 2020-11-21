#include "funciones.h"

map<string, map<string,list<string>>> base(map<string, map<string, int> > inicial)
{
    vector <string> claves;
    map <string,map<string,list<string>>> final;
    bool ava = false;
    int mod, agre;
    string contenido;
    //cout << "\n\n\n YA CASI \n\n\n";
    for (auto var : inicial){
        claves.push_back(var.first);
    }
    for (auto var : inicial){
        for (auto con : claves){
            contenido = "";
            ava = false;
            for (auto var2 : inicial[var.first]){
                if (con == var2.first) ava = true;
            }
            if (ava == true) {
                mod = inicial[var.first][con];

                if (mod == 0)contenido = "0";
                while (mod != 0){
                    agre = mod%10;
                    contenido = char(agre + 48) + contenido;
                    mod/=10;
                }

                final[var.first][con].push_front(contenido);
            }
            else final[var.first][con].push_front("-1");
            final[var.first][con].push_back("______");
        }
    }






























    return final;
}
