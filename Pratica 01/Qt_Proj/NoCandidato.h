#ifndef NOCANDIDATO_H
#define NOCANDIDATO_H

#include "Candidato.h"
#include <iostream>

using namespace std;

class NoCandidato {
//private:
public:
    Candidato *conteudo;
    NoCandidato *next;

    inline NoCandidato(): conteudo(NULL), next(NULL) {}
    inline NoCandidato(Candidato *c, NoCandidato *nx): conteudo(c), next(nx) {}




};

#endif // NOCANDIDATO_H
