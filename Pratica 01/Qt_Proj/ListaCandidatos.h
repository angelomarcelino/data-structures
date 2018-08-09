#ifndef LISTACANDIDATOS_H
#define LISTACANDIDATOS_H

#include "Candidato.h"
#include "NoCandidato.h"
#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>

using namespace std;

class ListaCandidatos {

public:
    NoCandidato *head;

    //Construtores
    inline ListaCandidatos(): head(NULL) {}
    ListaCandidatos(string arq): head(NULL) {
        ifstream fcin(arq);

        string dados;
        getline(fcin,dados);
        cout << "criacao de lista de candidatos de: " << dados << endl;

        while(getline(fcin,dados))
        {
            adicioneComoHead(new Candidato(dados));
        }
    }

    //Métodos
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
    bool remove(string nome, string sobrenome){
        NoCandidato* it = head;
        bool achou = false;
        int cont = 0;
        while(!achou && it!=NULL){
            if(it->conteudo->igual(nome,sobrenome))
            {
                achou = true;
                if(cont==0)
                {
                    head = it->next;
                    delete it;
                }
                else
                {
                    NoCandidato* aux = head;
                    for(int i=0; i<cont-1; i++)
                    {
                        aux = aux->next;
                    }
                    aux->next = it->next;
                    delete it;
                }

            }
            else it = it->next;
            cont ++;
        }
        return achou;
    }

};

#endif // LISTACANDIDATOS_H
