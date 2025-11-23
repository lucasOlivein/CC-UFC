#include <iostream>
#include "class.h"
#include <string>
using namespace std;
// Todas definidas em class.cpp;
void Op1(vector<Midia> &midia, string ope);                                   // Referente ao nome do Artista; resolucao dos itens A, B, C.
void Op2(vector<Midia> &midia, string ope);                                   // Refente ao Ano de lanamento; resolucao do item D
void Op3(vector<Midia> &midia, vector<string> &keyords, int aux, string ope); // Referente ao Titulo da midia; resolucao do item E.
void Op4(vector<Midia> &midia, string ope);                                   // Referente ao Genero; resolucao do Item F.
void print_keywords(vector<string> &keywords);                                // Keywords do Item G.
void create_midia(vector<Midia> &midia, string ope);
vector<string> get_files(string path);
bool load_midias(vector<Midia> &midia, string ope); // Carrega a colecao Midia com a colecao de CD e de DVD escritas em um arquivo txt;
vector<string> get_files(string path);

void removerColecao(string colecao)
{
    vector<string> files = get_files("./colecao");
    for (int i = 0; i < files.size(); i++)
    {
        if (files[i] == colecao + ".txt")
        {
            rename(("./colecao/" + colecao + ".txt").c_str(), ("./colecao/deletado/" + colecao + ".txt").c_str());
            cout << "\n  << removido com sucesso >>\n\n";
            system("pause");
            return;
        }
    }

    cout << " << colecao nao encontrada >>\n";
    system("pause");
}
bool update_midia(Midia &midia, string titulo)
{
    string name;
    cout << "Atualizar Artista? (s/n):: ";
    getline(cin, name, '\n');
    if (name == "s")
    {
        cout << "Digite o novo nome do Artista:: ";
        getline(cin, name, '\n');
        midia.setArtista(name);
        cout << "<< atualizado >>\n";
    }

    cout << "Atualizar Titulo? (s/n):: ";
    getline(cin, name, '\n');
    if (name == "s")
    {
        cout << "Digite o novo Titulo:: ";
        getline(cin, name, '\n');
        midia.setTitulo(name);
        cout << "<< atualizado >>\n";
    }

    cout << "Atualizar Genero? (s/n):: ";
    getline(cin, name, '\n');
    if (name == "s")
    {
        cout << "Digite o novo Genero:: ";
        getline(cin, name, '\n');
        midia.setGenero(name);
        cout << "<< atualizado >>\n";
    }

    cout << "Atualizar Lancamento? (s/n):: ";
    getline(cin, name, '\n');
    if (name == "s")
    {
        cout << "Digite o novo Lancamento:: ";
        while (1)
        {
            getline(cin, name, '\n');
            if (stoi(name) > 2020 || stoi(name) < 0)
                cout << "Ano invalido, digite novamente:: ";
            else
                break;
        }

        midia.setLancamento(stoi(name));
        cout << "<< atualizado >>\n";
    }

    cout << "Atualizar Faixas? (s/n):: ";
    getline(cin, name, '\n');
    if (name == "s")
    {
        while (1)
        {
            cout << "Digite a opcao:: \n1:: << Adicionar faixa >> \n2::<< Remover faixa >>\n << 0 para sair >>\n::";
            getline(cin, name, '\n');
            if (name == "1")
            {
                cout << "Digite o nome da nova faixa:: ";
                getline(cin, name, '\n');
                midia.adicionarFaixa(name);
                cout << "<< adcionado >>\n";
            }
            else if (name == "2")
            {
                cout << "Digite o nome da faixa a ser removida:: ";
                getline(cin, name, '\n');
                midia.removerFaixa(name);
                cout << "<< removido >>\n";
            }
            else if (name == "0")
            {
                cout << "<< operacao abortada >>\n";
                break;
            }
            else
            {
                cout << "<< Opcao invalida >>\n";
            }
        }
    }

    if (midia.getDuracao() != 0)
    {
        cout << "Atualizar Duracao? (s/n):: ";
        getline(cin, name, '\n');
        if (name == "s")
        {
            cout << "Digite a nova duracao:: ";
            while (1)
            {
                getline(cin, name, '\n');
                if (name == "0")
                    break;
                if (stoi(name) < 0 || stoi(name) > 1000)
                {
                    cout << "Duracao invalida, digite 0 para abordar ou digite novamente:: ";
                }
                else
                {
                    midia.setDuracao(stoi(name));
                    cout << "<< atualizado >>\n";
                    break;
                }
            }
        }
    }
}

void write(vector<Midia> &midia, string file)
{
    bool flag = false;
    vector<string> files = get_files("./colecao");
    for (int i = 0; i < files.size(); i++)
    {
        if (files[i] == file + ".txt")
            flag = true;
    }

    if (flag)
    {
        rename(("./colecao/" + file + ".txt").c_str(), ("./colecao/deletado/" + file + ".txt").c_str());
    }

    ofstream fout("./colecao/" + file + ".txt");
    vector<string> key;
    for (int i = 0, aux = 0; i < midia.size(); i++, aux += 5)
    {
        key = midia[i].getKeywords();
        if (key[aux] == "CD")
        {
            vector<string> faixas;

            fout << "CD{" << endl;
            fout << "Artista::" << endl;
            fout << midia[i].getArtista() << ';' << endl;
            fout << "Titulo::" << endl;
            fout << midia[i].getTitulo() << ';' << endl;
            fout << "Duracao::" << endl;
            fout << midia[i].getDuracao() << ';' << endl;

            faixas = midia[i].getFaixas();
            fout << "Faixas::" << endl;
            for (int i = 0; i < faixas.size(); i++)
            {
                fout << '"' << faixas[i] << '"' << ',';
            }
            fout << ';' << endl;
            fout << "Lancamento::" << endl;
            fout << midia[aux].getLancamento() << ';' << endl;
            fout << "Genero::" << endl;
            fout << midia[aux].getGenero() << ';' << endl;

            fout << "}" << endl
                 << endl;
        }
        else if (key[aux] == "DVD")
        {

            vector<string> faixas;
            fout << "DVD{" << endl;
            fout << "Artista::" << endl;
            fout << midia[i].getArtista() << ';' << endl;
            fout << "Titulo::" << endl;
            fout << midia[i].getTitulo() << ';' << endl;

            faixas = midia[i].getFaixas();
            fout << "Faixas::" << endl;
            for (int i = 0; i < faixas.size(); i++)
            {
                fout << '"' << faixas[i] << '"' << ',';
            }
            fout << ';' << endl;
            fout << "Lancamento::" << endl;
            fout << midia[i].getLancamento() << ';' << endl;
            fout << "Genero::" << endl;
            fout << midia[i].getGenero() << ';' << endl;

            fout << "}" << endl
                 << endl;
        }
    }
    fout.close();
}

void show_files(string path)
{
    DIR *dir;
    bool flag = false;
    struct dirent *ent;
    if ((dir = opendir(path.c_str())) != NULL)
    {
        while ((ent = readdir(dir)) != NULL)
        {
            // listar apenas os arquivos

            if (ent->d_type == DT_REG)
                if (ent->d_name[0] != '.' && ent->d_name[0] != '\n')
                {
                    cout << ":: << ";
                    for (int i = 0; ent->d_name[i] != '.'; i++)
                    {
                        cout << ent->d_name[i];
                        flag = true;
                    }
                    cout << " >>";
                }
            if (flag)
                cout << endl;

            flag = false;
        }
        closedir(dir);
    }
    else
    {
        perror("Nao foi possivel abrir o diretorio");
    }
}

//

int main()
{
    vector<Midia> midia;
    vector<string> keyords;
    string ope;

    while (1)
    {
        system("cls");
        cout << "1 ::Carregar Colecao\n2 ::Atualizar Biblioteca\n3 ::  <<Entrar>>\n0 ::  <<Sair>>\n\n";
        cout << "Selecione uma opcao: ";
        getline(cin, ope, '\n');

        if (ope == "0")
            break;
        else if (ope == "1")
        {
            while (1)
            {
                system("cls");
                cout << "Colecoes disponiveis:\n";
                show_files("./colecao");
                cout << "\nDigite << 0 >> para voltar\nDigite o nome da colecao: ";
                getline(cin, ope, '\n');
                if (ope == "0")
                    break;

                if (load_midias(midia, ope))
                {
                    cout << "<< carregado com sucesso >>\n\n\n";
                    system("pause");
                    break;
                }
                else
                    cout << "<< erro ao carregar >>\n\n\n";

                system("pause");
            }
        }
        else if (ope == "2")
        {
            while (1)
            {
                system("cls");
                cout << " << Opcoes >>\n1::Criar Colecao\n2::Excluir Colecao\n3::Atualizar Colecao\n << 0 para sair >>\n\nSelecione uma opcao:: ";
                getline(cin, ope, '\n');

                if (ope == "0")
                    break;
                if (ope == "1")
                {
                    cout << "Digite o nome da colecao:: ";
                    getline(cin, ope, '\n');
                    create_midia(midia, ope);
                }
                else if (ope == "2")
                {
                    show_files("./colecao");
                    cout << "\n\n";
                    cout << "Digite o nome da colecao:: ";
                    getline(cin, ope, '\n');
                    removerColecao(ope);
                }
                else if (ope == "3")
                    while (1)
                    {
                        bool flag = false;
                        vector<Midia> midia_aux;
                        vector<string> keyords_aux;
                        string ope_aux;
                        system("cls");
                        cout << "Colecoes disponiveis:\n";
                        show_files("./colecao");
                        cout << "\nDigite << 0 >> para voltar\nDigite o nome da colecao: ";
                        getline(cin, ope, '\n');
                        if (ope == "0")
                            break;

                        if (load_midias(midia_aux, ope))
                            cout << "<< midias carregada >>\n";
                        else
                        {
                            cout << "<< erro ao carregar >>\n";
                            system("pause");
                            break;
                        }

                        for (int i = 0; i < midia_aux.size(); i++) // Carrega a Keywords da colecao de Midias em uma variavel Local.
                        {
                            vector<string> aux = {};
                            aux = midia_aux[i].getKeywords();
                            keyords_aux.insert(keyords_aux.end(), aux.begin(), aux.end());
                        }
                        while (1)
                        {
                            cout << " ::Buscar por Midia::\n";
                            cout << "KeyWords disponiveis:\n<< Artista >> \n<< Titulo >> \n<< Genero >> \n<< Lancamento >> \n<< 0 >> para voltar\n";
                            getline(cin, ope_aux, '\n');
                            int aux1 = {};

                            if (ope_aux == "Artista")
                            {
                                cout << "Artistas:: \n";
                                cout << "//////////DEVIA MOSTRAR AS MIDIAS DO ARTISTAS/////\n";

                                for (int i = 1; i + 2 < keyords_aux.size(); i += 2)
                                {
                                    cout << " -> " << keyords_aux[i] << endl;
                                }
                            }
                            else if (ope_aux == "Titulo")
                            {
                                cout << "Titulos:: \n";
                                for (int i = 2; i + 2 < keyords_aux.size(); i += 2)
                                {
                                    cout << " -> " << keyords_aux[i] << endl;
                                }
                            }
                            else if (ope_aux == "Genero")
                            {
                                cout << "Generos:: \n";
                                cout << "//////////DEVIA MOSTRAR AS MIDIAS DESSE GENERO/////\n";

                                for (int i = 3; i + 2 < keyords_aux.size(); i += 2)
                                {
                                    cout << " -> " << keyords_aux[i] << endl;
                                }
                            }
                            else if (ope_aux == "Lancamento")
                            {
                                cout << "Lancamentos:: \n";
                                cout << "//////////DEVIA MOSTRAR AS MIDIAS COM ESSE LANÇAMENTO/////\n";

                                for (int i = 4; i + 2 < keyords_aux.size(); i += 2)
                                {
                                    cout << " -> " << keyords_aux[i] << endl;
                                }
                            }
                            else
                            {
                                for (int i = 2; i != keyords.size(); i += 2) // Busca correspondecia da palavra digitada na Keywords Local ou finaliza o programa.
                                {

                                    if (ope == keyords[i])
                                    {
                                        cout << "<< encontrado >>\n";
                                        aux1 = i;
                                        break;
                                    }
                                    if (i == keyords.size() - 1)
                                    {
                                        cout << "<<Nao encontrado>>\n";
                                        cout << "\nRetry: ";
                                        print_keywords(keyords);
                                        getline(cin, ope, '\n');
                                        i = 0;
                                    }
                                }
                            }

                            if (update_midia(midia[(aux1 - 2) / 5], ope))
                            {
                                cout << "<< atualizado com sucesso >>\n\n\n";
                                flag = true;
                            }
                            else
                                cout << "<< erro ao atualizar >>\n\n\n";

                            if (flag)
                            {
                                write(midia_aux, ope);
                                cout << "<< colecao atualizada >>\n\n\n";
                            }
                            cout << "Deseja atualizar outra midia? (s/n): ";
                            getline(cin, ope, '\n');
                            if (ope == "n")
                                break;
                        }
                        cout << "Deseja atualizar outra colecao? (s/n): ";
                        getline(cin, ope, '\n');
                        if (ope == "n")
                            break;
                        system("pause");
                    }
            }
        }
        else if (ope == "3")
        {
            for (int i = 0; i < midia.size(); i++) // Carrega a Keywords da colecao de Midias em uma variavel Local.
            {
                vector<string> aux;
                aux = midia[i].getKeywords();
                keyords.insert(keyords.end(), aux.begin(), aux.end());
            }
            if (midia.size() == 0)
            {
                cout << "<< nenhuma colecao carregada >>\n\n\n";
                system("pause");
            }
            else
            {
                while (1)
                {
                    system("cls");
                    cout << "\nDigite << exit >> para sair\n";
                    cout << "\nSeach: ";
                    getline(cin, ope, '\n');
                    int aux = {};

                    if (ope == "exit" || ope == "sair")
                        break;

                    for (int i = 0; i != keyords.size(); i++) // Busca correspondecia da palavra digitada na Keywords Local ou finaliza o programa.
                    {

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
                    cout << "\n\n\n";
                    system("pause");
                }
            }
        }
    }
}
