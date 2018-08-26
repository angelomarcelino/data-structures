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
        NoCandidato* aux = NULL;
        bool achou = false;
        while(!achou && it!=NULL){
            if(it->conteudo->igual(nome,sobrenome))
            {
                achou = true;
                if(it == head)
                {
                    head = it->next;
                    delete it;
                }
                else {
                    aux->next = it->next;
                    delete it;
                }
            }
            else { 
                aux = it;
                it = it->next;
            }
        }
        return achou;
    }

    void filtrarCandidatos(int nota){
        NoCandidato* it=head;
        NoCandidato* aux = NULL;
        while(it!=NULL){
            if(it->conteudo->menorQnota(nota))
            {
                aux = it->next;
                remove(it->conteudo->nome,it->conteudo->sobrenome);
                it = aux;
            } else {
                it = it->next;
            }

        }
    }
};

#endif // LISTACANDIDATOS_H
