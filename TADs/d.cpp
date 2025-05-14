#include <iostream>
#include <fstream>
using namespace std;

class DocumentoMusical{
private:
    string nomeMusica;
    string nomeCompositor;
    string estiloMusical;
    string tipoDocumento;

public:
    DocumentoMusical();
    void cadastrar(string nM, string nC, string eM, string tD); // todos os valores entre parenteses serao inseridos pelo usuario
    void mostrarDadosDocumento();
    string retornarNomeMusica() { return nomeMusica; }
};

    DocumentoMusical::DocumentoMusical(){
        //inicilizar os valores de cada documento musical

        nomeMusica = "Disponivel";
        nomeCompositor = "--";
        estiloMusical = "--";
        tipoDocumento = "--";

    }

    void DocumentoMusical::cadastrar(string nM, string nC, string eM, string tD){
        //cadastrar cada documento musical com base no que o usuario digitar para preencher
        
        nomeMusica = nM;
        nomeCompositor = nC;
        estiloMusical = eM;
        tipoDocumento = tD;

    }

    void DocumentoMusical::mostrarDadosDocumento(){
        // mostrar os dados de cada documento que possui o mesmo estilo inserido pelo usuario pela entrada padrao

     cout << nomeMusica << ", " << nomeCompositor << ", " << estiloMusical << ", " << tipoDocumento << ";" << endl;

    }


class DadosBandas{
    private:
    string nomeBanda;
    string instrumentoTocado;
    string estiloBanda;


public: 
    DadosBandas();
    void cadastrarBandas(string nB, string iT, string eB);
    void mostrarDadosBanda();
    string retornarNomeBanda() { return nomeBanda; }

};

    DadosBandas::DadosBandas(){
        //inicializar os valores do nome da banda e etc

        nomeBanda= "nada";
        instrumentoTocado= "--";
        estiloBanda = "--";
    }

   void DadosBandas::cadastrarBandas(string nB, string iT, string eB){
        // cadastrar os dados de cada banda baseado nos dados inseridos pelo usuario

        nomeBanda = nB;
        instrumentoTocado = iT;
        estiloBanda = eB;

    }

    void DadosBandas::mostrarDadosBanda(){
        //mostrar os dados da banda baseado no estilo que o usuario inserio pela entrada padrao

        cout << nomeBanda << ", " << instrumentoTocado << ", " << estiloBanda << ";"  << endl;
    }

class AcervoDocumentos{
private: 
    DocumentoMusical *documento;
    int qntDocumentos;
    int aux=0;


public:
    AcervoDocumentos(int qntD); // construtor
    ~AcervoDocumentos(); // destrutor
    bool registrarDocumentos(string nM, string nC, string eM, string tD);
    bool consultarDocumentos(string eM);

};

AcervoDocumentos::AcervoDocumentos(int qntD){
    // inicializar o vetor que conterá todos os documentos cadastrados pelo usuario
    documento = new DocumentoMusical[qntD];
    qntDocumentos = qntD;
}

AcervoDocumentos::~AcervoDocumentos(){
    // remover da memoria os dados armazenados pelo vetor documentos e apagar o vetor   
    delete [] documento;

}

bool AcervoDocumentos::registrarDocumentos(string nM, string nC, string eM, string tD){
    //registrar todos os documentos inseridos pelo usuario em um vetor documentos

    
    if(aux<qntDocumentos){
        documento[aux].cadastrar(nM, nC, eM, tD);
        aux++;
        return true;
    }
    return false;
}

bool AcervoDocumentos::consultarDocumentos(string eM){
    // consultar no vetor documentos se ha algum deles com o estilo musical inserido pelo usuario, se houver, sera imprimido na tela
    int indice=0;	
    while((indice<qntDocumentos) and (documento[indice].retornarNomeMusica() != eM)){
        indice++;
        }
        documento[indice].mostrarDadosDocumento();

 return false;
}

class AcervoBandas{
private: 
    DadosBandas *banda;
    int qntBandas;
    int aux1=0;


public:
    AcervoBandas(int qntB); // construtor
    ~AcervoBandas(); // destrutor
    bool registrarBandas(string nB, string iT, string eB);
    bool consultarBandas(string eB);
    
};

AcervoBandas::AcervoBandas(int qntB){
    // inicializar o vetor que conterá as informacoes de cada banda cadastrada pelo usuario
    banda = new DadosBandas[qntB];
    qntBandas = qntB;
}

AcervoBandas::~AcervoBandas(){
    // remover da memoria os dados armazenados pelo vetor bandas e apagar o vetor
    delete[] banda;

}

bool AcervoBandas::registrarBandas(string nB, string iT, string eB){
    //registrar todos as bandas inseridos pelo usuario em um vetor bandas

   
    if(aux1<qntBandas){
        banda[aux1].cadastrarBandas(nB, iT, eB);
        aux1++;
        return true;
    }
return false;
}

bool AcervoBandas::consultarBandas(string eB){
    // consultar no vetor bandas se ha algum deles com o estilo musical inserido pelo usuario, se houver, sera imprimido na tela
    int indice1=0;
    while((indice1<qntBandas) and (banda[indice1].retornarNomeBanda() != eB)){
        indice1++;
        }
        banda[indice1].mostrarDadosBanda();
return false;
}


int main (){
    
    string nomeMusica;
    string nomeCompositor;
    string estiloMusical;
    string tipoDocumento;

    cout << endl << "Insira a quantidade de documentos que serao cadastrados: " << endl;
    int quantidadeDocumentos;
    cin >> quantidadeDocumentos;
    AcervoDocumentos vetorDocumentos(quantidadeDocumentos);

    for(int i=0; i<quantidadeDocumentos; i++){
    cout << "Insira o nome da musica: " << endl;
    cin >> nomeMusica;
    cout << "Insira o nome do compositor: " << endl;
    cin >> nomeCompositor;
    cout << "Insira o estilo musical: " << endl;
    cin >> estiloMusical;
    cout << "Insira o tipo de documento(partituras, tablaturas e cifras): " << endl;
    cin >> tipoDocumento;
    vetorDocumentos.registrarDocumentos(nomeMusica, nomeCompositor, estiloMusical, tipoDocumento);
    }


    string nomeBanda;
    string instrumentoTocado;
    string estiloBanda;

    cout << endl << "Insira a quantidade de Bandas que serao cadastrados: " << endl;
    int quantidadeBandas;
    cin >> quantidadeBandas;
    AcervoBandas vetorBanda(quantidadeBandas);

    for(int i=0; i<quantidadeBandas; i++){
    cout << "Insira o nome da banda: " << endl;
    cin >> nomeBanda;
    cout << "Insira o nome do instrumento mais tocado: " << endl;
    cin >> instrumentoTocado;
    cout << "Insira o estilo da banda: " << endl;
    cin >> estiloBanda;
    vetorBanda.registrarBandas(nomeBanda, instrumentoTocado, estiloBanda);
    }
    
    int resposta=-1;

    while(resposta!=2){
        cout << "Deseja pesquisar por estilos musicais? " << endl << "1)Sim " << endl << "2)Nao" << endl;
        cin >> resposta;
        if(resposta==1){ // filtrar por estilo musical
        string filtroMusical;
        cout << "Insira o filtro: " << endl;
        cin >> filtroMusical;

        cout << "------------------------------------" << endl << "Documentos com o estilo filtrado: " << endl;
                vetorDocumentos.consultarDocumentos(filtroMusical);

        cout << "------------------------------------" << endl << "Bandas com o estilo filtrado: " << endl;
                vetorBanda.consultarBandas(filtroMusical);

        }
    }










    return 0;
}
