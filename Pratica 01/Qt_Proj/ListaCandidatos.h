#ifndef LISTACANDIDATOS_H
#define LISTACANDIDATOS_H

#include "Candidato.h"
#include "NoCandidato.h"
#include <iostream>
#include <string>

using namespace std;

class ListaCandidatos {

public:
    NoCandidato *head;

    inline ListaCandidatos(): head(NULL) {}
    inline void adicioneComoHead(Candidato *c) {head = new NoCandidato(c,head);}
    inline bool estaVazia() {return head==NULL;}

};

#endif // LISTACANDIDATOS_H
