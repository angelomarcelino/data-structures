#ifndef LISTACANDIDATOS_H
#define LISTACANDIDATOS_H

#include "Candidato.h"
#include "NoCandidato.h"
#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

class ListaCandidatos {

public:
    NoCandidato *head;

    inline ListaCandidatos(): head(NULL) {}
    inline void adicioneComoHead(Candidato *c) {head = new NoCandidato(c,head);}
    inline bool estaVazia() {return head==NULL;}

    int tamanho() const {
        NoCandidato *aux = head;
        int cont(0);
        while (aux!=NULL)
        {
            cont++;
            aux = aux->next;
        }
        return cont;
    }

    string toString() const {
        stringstream stream;
        stream << head->toString();
        return stream.str();
    }
};

#endif // LISTACANDIDATOS_H
