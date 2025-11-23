#include "class.h"
void interface(const string operacoes);

int main()
{
    Comunidade *comunidades = new Comunidade;
    string ope;
    string comun;
    string part;

    interface("0");
    while (1)
    {
        cout << "\n> Operacao: ";
        getline(cin, ope, '\n');
        if (ope == "exit" || ope == "sair")
            return 0;
        else if (ope == "0")
        {
            system("cls");
            interface("0");
        }
        else if (ope == "1")
        {

            system("cls");
            interface("1");
            cout << "> Digite o nome da Comunidade: ";
            getline(cin, comun, '\n');
            cout << "> Digite o nome do Participante: ";
            getline(cin, part, '\n');
            system("cls");
            interface("0");
            cout << "Comunidade: " <<comun << ", Participante: "<< part << endl;
            comunidades->incluirComunidade(comun, part);
        }
        else if (ope >= "2" && ope <= "6" && comunidades->size() == 0)
        {
            system("cls");
            interface("0");
            cout << "<< Sem Comunidade >>\n";
        }
        else if (ope == "2")
        {
            system("cls");
            interface("2");
            cout << "Lista de Comunidades: \n";
            comunidades->listarComunidade();
        }
        else if (ope == "3")
        {
            system("cls");
            interface("3");
            cout << "> Digite o nome da Comunidade a ser excluida: ";
            getline(cin, comun, '\n');
            system("cls");
            interface("0");
            comunidades->excluirComunidade(comun);
        }
        else if (ope == "4")
        {
            system("cls");
            interface("4");

            cout << "> Digite o nome da Comunidade: ";
            getline(cin, part, '\n');
            system("cls");
            interface("0");
            cout << "Comunidade << " << part << " >>\n";
            comunidades->listarParticipantes(part);
        }
        else if (ope == "5")
        {
            system("cls");
            interface("5");
            cout << "> Digite o nome do Participante: ";
            getline(cin, part, '\n');
            system("cls");
            interface("0");
            comunidades->listarComunidadeParticipante(part);
        }
        else if (ope == "6")
        {
            system("cls");
            interface("6");

            cout << "> Digite o nome do Participante: ";
            getline(cin, part, '\n');
            system("cls");
            interface("0");
            comunidades->excluirParticipante(part);
        }
        else{
            system("cls");
            interface("0");
            cout << "<< Operacao nao Reconhecida >>\n";
        }
    }
}

void interface(const string ope)
{
    const string ops[7] = {
        "",
        "Incluir Comunidade / Participante",
        "Listar Comunidades",
        "Excluir Comunidade",
        "Listar Participantes",
        "Listar Comunidade(s) do Participante",
        "Excluir Participante"
    };

    cout << "Digite << exit >> para sair\n\n";

    cout << "::: Operacoes :::\n";

    for (int i = 1; i <= 6; i++) {
        if (stoi(ope) == i)
            cout << " " << i << ". << " << ops[i] << " >>\n";
        else
            cout << " " << i << ". " << ops[i] << "\n";
    }

    cout << "\n";
}
