#include "midias.h"
#include "class.h"
#include <fstream>
#include <dirent.h>
using namespace std;

// Todas definidas em class.cpp;
void Op1(vector<Midia> &midia, string ope);                                   // Referente ao nome do Artista; resolucao dos itens A, B, C.
void Op2(vector<Midia> &midia, string ope);                                   // Refente ao Ano de lanamento; resolucao do item D
void Op3(vector<Midia> &midia, vector<string> &keyords, int aux, string ope); // Referente ao Titulo da midia; resolucao do item E.
void Op4(vector<Midia> &midia, string ope);                                   // Referente ao Genero; resolucao do Item F.
void print_keywords(vector<string> &keywords);                                // Keywords do Item G.

// funcao que mostra os arquivos do diretorio do tipo txt
void show_files(string path)
{
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(path.c_str())) != NULL)
    {
        while ((ent = readdir(dir)) != NULL)
        {
            if (ent->d_name[0] != '.' && ent->d_name[0] != '\n')
                cout << ent->d_name << endl;
        }
        closedir(dir);
    }
    else
    {
        perror("Nao foi possivel abrir o diretorio");
    }
}

int main()
{
    system("cls");

    vector<Midia> midia;
    vector<string> keyords;
    // load_midias(&midia); // Carrega a colecao Midia com as colecoes de CD e de DVD instanciada em "Midias.h";

    string ope; // Variavel auxiliar que salva o que é digitado;

    cout << "1 ::Carregar Colecao\n2 ::Criar Colecao\n3 ::Atualizar Colecao\n\n";
    cout << "Selecione uma opcao: ";
    getline(cin, ope, '\n');

    if (ope == "1")
    {
        system("cls");
        cout << "Colecoes disponiveis:\n";
        show_files("./colecao");

        ifstream fin("./colecao/test.txt");

        if (!fin.is_open())
        {
            cout << "Arquivo nao encontrado\n";
            return 0;
        }
        // printar o conteudo de fin
        string line;
        while (getline(fin, line))
        {
            if (line == "testing")
                cout << "achou\n";
            cout << line << endl;
        }
        // create_midias(&midia);
        // else if(ope == "3")
        // update_midias(&midia);
    }
    else if (ope == "2")
    {
        cout << "Digite o nome da colecao: ";
        getline(cin, ope, '\n');
        ofstream fout("./colecao/" + ope + ".txt");
        if (fout.is_open())
        {
            cout << "<< arquivo criado >>\n";
            return 0;
        }
        fout.close();


    }

    else
        return 0;
    for (int i = 0; i < midia.size(); i++) // Carrega a Keywords da colecao de Midias em uma variavel Local.
    {
        vector<string> aux;
        aux = midia[i].getKeywords();
        keyords.insert(keyords.end(), aux.begin(), aux.end());
    }

    // cout << "Digite << exit >> para sair\n";

    while (1)
    {
        cout << "\nSeach: ";
        getline(cin, ope, '\n');
        int aux = {};

        for (int i = 0; i != keyords.size(); i++) // Busca correspondecia da palavra digitada na Keywords Local ou finaliza o programa.
        {
            if (ope == "exit" || ope == "sair")
                return 0;
            if (ope == keyords[i])
            {
                aux = i;
                break;
            }
            if (i == keyords.size() - 1)
            {
                cout << "<<Nao encontrado>>\n\nKeyWords registradas:\n";
                print_keywords(keyords); // Exite as Keywords caso nao haja correspondencia (nas keywords) com a palavra digitada.
                cout << "\nRetry: ";
                getline(cin, ope, '\n');
                i = 0;
            }
        }

        // Ao encontrar uma correspondencia em Keywords:

        if (aux % 5 == 1) // A palavra digitada eh um artista
        {
            Op1(midia, ope); // Operacao 1 :
            // Exibe as midias nos CDs, nos DVDs e todas as midias
        }
        else if (aux % 5 == 2) // A palavra digitada eh um ano;
        {
            Op2(midia, ope); // Operacao 2:
            // Exibe as Midias do ano digitado;
        }
        else if (aux % 5 == 3) // A palavra digitada eh uma midia
        {
            Op3(midia, keyords, aux, ope); // Operacao 3:
            // Exibe pequena informacao sobre Titulo infomado e recebe outro titulo
            // caso seja do mesmo autor exibe quais faixas sao inerente a cada midia e quais ambos possuem em comum.
        }
        else if (aux % 5 == 4) /// a palavra digitada eh um genero
        {
            Op4(midia, ope); // Operacao 4:
            // Exibe as Midias com esse o genero informado;
        }
    }
}
