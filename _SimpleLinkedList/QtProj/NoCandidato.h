#ifndef NOCANDIDATO_H
#define NOCANDIDATO_H

#include "Candidato.h"
#include <iostream>
#include <string>

using namespace std;

class NoCandidato {
//private:
public:
    Candidato *conteudo;
    NoCandidato *next;

    inline NoCandidato(): conteudo(NULL), next(NULL) {}
    inline NoCandidato(Candidato *c, NoCandidato *nx): conteudo(c), next(nx) {}

    string toString() {
        string aux;
        NoCandidato *nc = this;
        while (nc!=NULL)
        {
            aux += nc->conteudo->toString();
            aux += " -> ";
            nc = nc->next;
        }
        aux += "0";
        return aux;
    }

};

#endif // NOCANDIDATO_H
