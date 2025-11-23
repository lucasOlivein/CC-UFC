#include "class.h"

string Midia::getArtista()
{
    return artista;
}
void Midia::setArtista(string artista_)
{
    artista = artista_;
}

string Midia::getTitulo()
{
    return titulo;
}
void Midia::setTitulo(string titulo_)
{
    titulo = titulo_;
}

vector<string> Midia::getFaixas()
{
    return faixas;
}
void Midia::setFaixas(vector<string> faixa_)
{
    faixas = faixa_;
}
 /* bool getFaixa(string faixa_)
{
    if(find(faixas.begin(), faixa))
}  */

int Midia::getLancamento()
{
    return lancamento;
}
void Midia::setLancamento(int lancamento_)
{
    lancamento = lancamento_;
}

string Midia::getGenero()
{
    return genero;
}
void Midia::setGenero(string genero_)
{
    genero = genero_;
}

vector<string> Midia::getKeywords()
{
    return keyords;
}
void Midia::setKeywords(vector<string> Keyword_)
{
    keyords = Keyword_;
}

void CD::setDuracao(int duracao_)
{
    duracao = duracao_;
}
int CD::getDuracao()
{
    return duracao;
}

void CD::setVolume(float volume_)
{
    volume = volume_;
}
float CD::getVolume()
{
    return volume;
}

void CD::setColetania(bool coletania_)
{
    coletania = coletania_;
}
bool CD::getColetania()
{
    return coletania;
}
void CD::setKeywords()
{
    Midia::setKeywords({"CD", Midia::getArtista(), to_string(Midia::getLancamento()), Midia::getTitulo(), Midia::getGenero()});
}

set<string> DVD::getFormatAudio()
{
    return formatoAudio;
}
void DVD::setFormatAudio(set<string> formAud)
{
    formatoAudio = formAud;
}

set<string> DVD::getFormatTela()
{
    return formatoTela;
}
void DVD::setFormatTela(set<string> formTela)
{
    formatoTela = formTela;
}

list<string> DVD::getLegendas()
{
    return legendas;
}
void DVD::setLegendas(list<string> legen)
{
    legendas = legen;
}
void DVD::setKeywords()
{
    Midia::setKeywords({"DVD", Midia::getArtista(), to_string(Midia::getLancamento()), Midia::getTitulo(), Midia::getGenero()});
}




///////////////////////////////OPERACOES//////////////////////////////////////////////

void Op1(vector<Midia> &midia, string ope)
{
    multimap<int, string> midias_artist;
    map<int, string> cds;
    map<int, string> dvds;

    for (int i = 0; i < midia.size(); i++)
    {
        vector<string> key_aux = midia[i].getKeywords();
        if (key_aux[1] == ope)
        {
            midias_artist.insert(make_pair(midia[i].getLancamento(), midia[i].getTitulo()));
            if (key_aux[0] == "CD")
                cds.insert(make_pair(midia[i].getLancamento(), midia[i].getTitulo()));
            else if (key_aux[0] == "DVD")
            {
                dvds.insert(make_pair(midia[i].getLancamento(), midia[i].getTitulo()));
            }
        }
    }

    map<int, string>::iterator it;

    cout << "\nCDs:\n";
    for (it = cds.begin(); it != cds.end(); ++it)
        cout << "-> " << it->second << " (" << it->first << ")\n";
    cout << "\nDVDs:\n";
    for (it = dvds.begin(); it != dvds.end(); ++it)
        cout << "-> " << it->second << " (" << it->first << ")\n";

    cout << "\nMidias:\n";
    for (it = midias_artist.begin(); it != midias_artist.end(); ++it)
        cout << "-> " << it->second << " (" << it->first << ")\n";
}



////////////////////////// OP2////////////////////////////////////////////////

void Op2(vector<Midia> &midia, string ope)
{
    set<string> midias_ano;
    for (int i = 0; i < midia.size(); i++)
    {
        vector<string> key_aux = midia[i].getKeywords();
        if (ope == key_aux[2])
        {
            midias_ano.insert(midia[i].getTitulo());
        }
    }
    set<string>::iterator it;
    cout << "\nMidias do ano:\n";
    for (it = midias_ano.begin(); it != midias_ano.end(); ++it)
        cout << "-> " << *it << '\n';
}


/////////////////////////////OP3///////////////////////////////////////////

void Op3(vector<Midia> &midia, vector<string> &keyords, int aux, string ope)
{
    string ope_aux;
    int aux2 = {};
    cout << "<<" << keyords[aux - 3] << " encontrado>>\n" << keyords[aux - 2]  << " (" << keyords[aux - 1] << "), " << keyords[aux+1] << "\n\n";
    

    if (keyords[aux - 3] == "CD")
    {
        cout << "\nDigite um DVD do mesmo artista: ";
        getline(cin, ope_aux, '\n');

        for (int i = 3; i < keyords.size(); i += 5)
        {
            if ((ope_aux == keyords[i]) && (keyords[i - 3] == "DVD") && (keyords[i - 2] == keyords[aux - 2]))
            {
                aux2 = i;
                break;
            }
            if (i + 5 >= keyords.size())
            {
                cout << "Nao encontrado\n";
                abort();
            }
        }

        vector<string> aux_dvd = midia[(aux2 - 3) / 5].getFaixas();
        vector<string> aux_cd = midia[(aux - 3) / 5].getFaixas();

        auto en = remove_if(aux_cd.begin(), aux_cd.end(), [&](auto &x)
                            {
                
                if(find_if(aux_dvd.begin(), aux_dvd.end(), [&](string& y){
                    // cout << x << " "<< y<<(x==y)<<"jik\n";
                    return (x == y);
                }) == aux_dvd.end() ){
                    return false;
                }
                /// x esta em dvd 
                return true; });

        cout << "\nMidias Apenas no CD\n";
        for (auto q = aux_cd.begin(); q != en; ++q)
            cout << "-> " << *q << "\n";

        auto cd2 = midia[(aux - 3) / 5].getFaixas();

        en = remove_if(aux_dvd.begin(), aux_dvd.end(), [&](auto &x)
                       {
                /// x esta em dvd 
                if(find_if(cd2.begin(), cd2.end(), [&](string& y){
                    // cout << x << " "<< y<<"\n";
                    return x == y;
                }) == cd2.end() ){
                    return false;
                }
                return true; });

        cout << "\n\nMidias Apenas no DVD\n";
        for (auto it = aux_dvd.begin(); it != en; it++)
        {
            cout << "->" << (*it) << "\n";
        }

        auto dvd2 = midia[(aux2 - 3) / 5].getFaixas();

        en = remove_if(dvd2.begin(), dvd2.end(), [&](auto &x)
                       {
                /// x esta em dvd 
                if(find_if(cd2.begin(), cd2.end(), [&](string& y){
                    // cout << x << " "<< y<<"\n";
                    return x == y;
                }) != cd2.end() ){
                    return false;
                }
                return true; });

        cout << "\n\nMidias em Comum\n";
        for (auto q = dvd2.begin(); q != en; ++q)
            cout << "->" << *q << "\n";
    }
    else
    {
        cout << "\nDigite um CD do mesmo artista: ";
        getline(cin, ope_aux, '\n');

        for (int i = 3; i < keyords.size(); i += 5)
        {
            if ((ope_aux == keyords[i]) && (keyords[i - 3] == "CD") && (keyords[i - 2] == keyords[aux - 2]))
            {
                aux2 = i;
                break;
            }
            else if (i + 5 > keyords.size())
            {
                cout << "Nao encontrado\n";
                abort();
            }
        }

        vector<string> aux_dvd = midia[(aux2 - 3) / 5].getFaixas();
        vector<string> aux_cd = midia[(aux - 3) / 5].getFaixas();

        auto en = remove_if(aux_cd.begin(), aux_cd.end(), [&](auto &x)
                            {
                
                if(find_if(aux_dvd.begin(), aux_dvd.end(), [&](string& y){
                    // cout << x << " "<< y<<(x==y)<<"jik\n";
                    return (x == y);
                }) == aux_dvd.end() ){
                    return false;
                }
                /// x esta em dvd 
                return true; });

        cout << "Midias Apenas no DVD\n";
        for (auto q = aux_cd.begin(); q != en; ++q)
            cout << "-> " << *q << "\n";

        auto cd2 = midia[(aux - 3) / 5].getFaixas();

        en = remove_if(aux_dvd.begin(), aux_dvd.end(), [&](auto &x)
                       {
                /// x esta em dvd 
                if(find_if(cd2.begin(), cd2.end(), [&](string& y){
                    // cout << x << " "<< y<<"\n";
                    return x == y;
                }) == cd2.end() ){
                    return false;
                }
                return true; });

        cout << "\n\nMidias Apenas no CD\n";
        for (auto it = aux_dvd.begin(); it != en; it++)
        {
            cout << "->" << (*it) << "\n";
        }

        auto dvd2 = midia[(aux2 - 3) / 5].getFaixas();

        en = remove_if(dvd2.begin(), dvd2.end(), [&](auto &x)
                       {
                /// x esta em dvd 
                if(find_if(cd2.begin(), cd2.end(), [&](string& y){
                    // cout << x << " "<< y<<"\n";
                    return x == y;
                }) != cd2.end() ){
                    return false;
                }
                return true; });

        cout << "\n\nMidias em Comum\n";
        for (auto q = dvd2.begin(); q != en; ++q)
            cout << "->" << *q << "\n";
    }
}

/////////////////////////////////OP4////////////////////////////////////

void Op4(vector<Midia> &midia, string ope)
{
    map<string, int> cds;
    map<string, int> dvds;

    for (int i = 0; i < midia.size(); i++)
    {
        vector<string> key_aux = midia[i].getKeywords();

        if (key_aux[4] == ope)
        {
            if (key_aux[0] == "CD")
            {
                cds.insert(make_pair(midia[i].getTitulo(), midia[i].getLancamento()));
            }
            else if (key_aux[0] == "DVD")
            {
                dvds.insert(make_pair(midia[i].getTitulo(), midia[i].getLancamento()));
            }
        }
    }
    map<string, int>::iterator it;

    cout << "\nCDs:\n";
    for (it = cds.begin(); it != cds.end(); ++it)
        cout << "-> " << it->first << " (" << it->second << ")\n";
    cout << "\nDVDs:\n";
    for (it = dvds.begin(); it != dvds.end(); ++it)
        cout << "-> " << it->first << " (" << it->second << ")\n";
}


///////////////////////////////OP5////////////////////////////////////////////////

void print_keywords(vector<string> &keywords)
{   
    set<string> aux;
    set<pair<string,string>> certo;

    cout << "\nArtistas: \n";
    for (int i = 1; i < keywords.size(); i += 5) if(!keywords[i].empty()) aux.insert(keywords[i]);
    for(set<string>::iterator it =aux.begin(); it != aux.end(); ++it) cout << " -> " << *it << '\n';
    aux.clear();


    cout << "\nAno de Lancamento: \n";
    for (int i = 2; i < keywords.size(); i += 5)  if(!keywords[i].empty()) aux.insert(keywords[i]);
    for(set<string>::iterator it =aux.begin(); it != aux.end(); ++it) cout << " -> " << *it << '\n';
    aux.clear();
    
    cout << "\nTitulos: \n";
    for (int i = 3; i < keywords.size(); i += 5) if(!keywords[i].empty()) certo.insert(make_pair(keywords[i-3],keywords[i]));
    
    for(set<pair<string, string>>::iterator it =certo.begin(); it != certo.end(); ++it) cout << "-> " << it->second << " (" << it->first << ")\n";
    
    cout << "\nGeneros: \n";
    for (int i = 4; i < keywords.size(); i += 5) if(!keywords[i].empty()) aux.insert(keywords[i]);
    for(set<string>::iterator it =aux.begin(); it != aux.end(); ++it) cout << " -> " << *it << '\n';
}

////////////////////////////////////////END////////////////////////////////////////////