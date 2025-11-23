#include "class.h"

List::List()
{
    inicio = NULL;
    fim = NULL;
    size = 0;
}

List::~List()
{
    Node *i;
    while (inicio != NULL)
    {
        i = inicio;
        inicio = inicio->prox;
        delete i;
    }
}

List::Node *List::find(string dado)
{
    Node *i = inicio;
    while (i != NULL)
    {
        if (i->nome == dado)
        {
            return i;
        }
        i = i->prox;
    }
    return NULL;
}

List::Node *List::insert(string dado)
{
    if (find(dado) != NULL)
        return NULL;

    Node *novo = new Node(dado);
    size++;

    if (inicio == NULL)
    {
        inicio = novo;
        fim = novo;
        return fim;
    }

    Node *i = inicio;
    while (i != NULL && i->nome < dado)
        i = i->prox;

    if (i == NULL)
    {
        fim->prox = novo;
        novo->prev = fim;
        fim = novo;
        return fim;
    }

    if (i->prev == NULL)
    {
        i->prev = novo;
        novo->prox = i;
        novo->prev = NULL;
        inicio = novo;
        return inicio;
    }

    novo->prev = i->prev;
    novo->prox = i;
    i->prev->prox = novo;
    i->prev = novo;
    return novo;
}

bool List::erase(string dado)
{
    Node *i = find(dado);
    if (i == NULL)
        return false;

    if (size == 1)
    {
        inicio = NULL;
        fim = NULL;
    }
    else if (i->prev == NULL)
    {
        i->prox->prev = NULL;
        inicio = i->prox;
    }
    else if (i->prox == NULL)
    {
        i->prev->prox = NULL;
        fim = i->prev;
    }
    else
    {
        i->prev->prox = i->prox;
        i->prox->prev = i->prev;
    }

    size--;
    delete i;
    return true;
}

void List::print()
{
    Node *aux = inicio;
    while (aux != NULL)
    {
        cout << "-> " << aux->nome << endl;
        aux = aux->prox;
    }
}

//////////FUNCOES DA CLASSE COMUNIDADE///////////////////////
void Comunidade::incluirComunidade(string nomeComunidade, string nomeParticipante)
{
    List::Node *aux = a.insert(nomeComunidade);
    if (aux != NULL)
        cout << "<< Comunidade Criada >>\n";
    else
    {
        cout << "<< Comunidade Encontrada >>\n";
        aux = a.find(nomeComunidade);
    }

    if (aux->part->insert(nomeParticipante) != NULL)
    {
        cout << "<< Participante Inserido >>\n";
    }
    else
        cout << "<< Participante ja Inserido >>\n";
}
int Comunidade::size()
{
    return a.size;
}
void Comunidade::listarComunidade()
{
    if (a.size > 0)
        a.print();
    else
        cout << "<< Sem Comunidades >>\n";
}

void Comunidade::excluirComunidade(string nomeComunidade)
{
    if (a.erase(nomeComunidade))
        cout << " Comunidade removida << " << nomeComunidade << " >>\n";
    else
        cout << "<< Comunidade nao Encontrada >>\n";
}

void Comunidade::listarParticipantes(string nomeComunidade)
{
    List::Node *aux = a.find(nomeComunidade);
    if (aux != NULL)
    {
        cout << "Participante(s):\n";
        aux->part->print();
    }
    else
        cout << "<< Comunidade nao Encontrada >>\n";
}

void Comunidade::listarComunidadeParticipante(string nomeParticipante)
{
    int ope = 0;
    List::Node *i = a.inicio;
    List::Node *aux;
    while (i != NULL)
    {
        aux = i->part->find(nomeParticipante);
        if (aux != NULL)
        {
            if (ope == 0)
                ope = 1;
            if (ope == 1)
            {
                cout << "Comunidade(s):\n";
                ope = 2;
            }
            cout << "-> " << i->nome << endl;
        }
        i = i->prox;
    }

    if (ope == 0)
        cout << "<< Participante nao Encontrado >>\n";
}

void Comunidade::excluirParticipante(string nomeParticipante)
{
    int ope = 0;
    List::Node *i = a.inicio;
    List::Node *aux;

    while (i != NULL)
    {
        if (i->part->find(nomeParticipante))
        {
            ope = 1;
            if (i->part->erase(nomeParticipante))
                cout << " Participante removido da comunidade << " << i->nome << " >>\n";

            if (i->part->size == 0)
            {
                aux = i;
                i = i->prox;
                cout << " Comunidade removida << " << aux->nome << " >>\n";
                a.erase(aux->nome);
                continue;
            }
        }
        i = i->prox;
    }

    if (ope == 0)
        cout << "<< Participante nao Encontrado >>\n";
}