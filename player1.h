/*#include <iostream>
#include <fstream>
#include <conio.h> //getch()
#include <windows.h> ///remover
#include <ctime>
#include <wchar.h>
#include <ctype.h>
using namespace std;


void menu();
struct clockt {
    string soma;
};

/// Struct do meu heroi
struct PLAYER {
    int x,y;

    void coord (int li, int co){
        x=li;
        y=co;

    }
};

struct PLAYER1 {
    int x1,y1;

    void coord1 (int li, int co){
        x1=li;
        y1=co;
    }
};


struct ARQUIVO {



    char* nome;
    int x, y;
    int** m;
    int** mi;


    void tam(int li, int co){
        x=li;
        y=co;
    }


    void carrega (){
        m = new int*[x];
        for (int i=0; i<x; i++){
            m[i]=new int[y];
        }

        ifstream mapa;
        mapa.open(nome);
        char c;

        ///coloca na matriz o mapa
        for(int i=0; i<x;i++){
            for(int j=0; j<y;j++){
                    mapa>>c;
                    m[i][j]=c-48;
            }
        }
    }

};


void mostrarCursor(bool showFlag){


/// fun��o nao utilizada
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}
void colorir (int cor) {


/// posi��o do mapa no cmd

    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(out, cor);
}
void posicaoxy( int column, int line )    {
        COORD coord;
        coord.X = column;
        coord.Y = line;
        SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
    }


void mostra_mapa(ARQUIVO a, PLAYER p){
    posicaoxy(0,0);
    for (int i=p.x-5; i<p.x+5; i++){
        for (int j=p.y-5; j<p.y+5; j++){
            if(i<0 || j<0 ){
                        cout << " ";
                        }else {
                            switch(a.m[i][j]){
                            case 0: cout << " ";break;
                            case 1: cout <<char(219); break;
                            case 2: cout << char(1);break;
                            case 5: cout << char(2);break;
                            case 6: cout  <<char(15);break;
                            case 7:cout << char(23);break;
                            }
                        }
                    }cout<<endl;
        }

}


void mostra_mapa1 (ARQUIVO a, PLAYER1 p) {
    posicaoxy(0,16);
        for (int j=p.y1-5; j<p.y1+5; j++){
    for (int i=p.x1-5; i<p.x1+5; i++){
            if(i<0 || j<0 ){
                        cout << " ";
                        }else {
                            switch(a.m[i][j]){
                            case 0: cout << " ";break;
                            case 1: cout <<char(219); break;
                            case 2: cout << char(1);break;
                            case 5: cout << char(2);break;
                            case 6:cout << char(15);break;
                            case 7:cout << char(23);break;
                            }
                        }
                    }cout<<endl;
        }
}


void extrai(int m, string l){

    fstream arq;
    arq.open(l);
    arq<<m;
    arq.close();
}

int expor(int m, string l ){

        fstream aqr;
        aqr.open(l);
        aqr>>m;
        aqr.close();
        return m;
}


char getchnolock(){

     return _kbhit() ? _getch() : -1;
}

void mover (PLAYER &p,PLAYER1 &p1, ARQUIVO &mapa){
    char tecla=getchnolock();
    if(!kbhit())
    switch (tecla){
    case 'w':
        if(mapa.m[p.x-1][p.y]==0){
            mapa.m[p.x][p.y]=0;
            mapa.m[p.x-1][p.y]=2;
            p.x=p.x-1;
        }else if(mapa.m[p.x-1][p.y]==6){
            mapa.m[p.x][p.y]=0;
            p.coord(1,81);
            mapa.m[p.x][p.y]=2;
        }
        break;
    case 's':
         if(mapa.m[p.x+1][p.y]==0){
            mapa.m[p.x][p.y]=0;
            mapa.m[p.x+1][p.y]=2;
            p.x=p.x+1;
        }else if(mapa.m[p.x+1][p.y]==6){
            mapa.m[p.x][p.y]=0;
            p.coord(52,87);
            mapa.m[p.x][p.y]=2;
        }
        break;
    case 'a':
        if(mapa.m[p.x][p.y-1]==0){
            mapa.m[p.x][p.y]=0;
            mapa.m[p.x][p.y-1]=2;
            p.y=p.y-1;
        }else if(mapa.m[p.x][p.y-1]==6){
            mapa.m[p.x][p.y]=0;
            p.coord(83,80);
            mapa.m[p.x][p.y]=2;
        }
        break;
    case 'd':
        if(mapa.m[p.x][p.y+1]==0){
            mapa.m[p.x][p.y]=0;
            mapa.m[p.x][p.y+1]=2;
            p.y=p.y+1;
        }else if(mapa.m[p.x][p.y+1]==6){
            mapa.m[p.x][p.y]=0;
            p.coord(75,43);
            mapa.m[p.x][p.y]=2;
        }
        break;
    case 72:
        if(mapa.m[p1.x1][p1.y1-1]==0){
            mapa.m[p1.x1][p1.y1]=0;
            mapa.m[p1.x1][p1.y1-1]=5;
            p1.y1=p1.y1-1;
        }else if(mapa.m[p1.x1][p1.y1-1]==6){
            mapa.m[p1.x1][p1.y1]=0;
            p1.coord1(2,2);
            mapa.m[p1.x1][p1.y1]=5;
        }
        break;
    case 80:
         if(mapa.m[p1.x1][p1.y1+1]==0){
            mapa.m[p1.x1][p1.y1]=0;
            mapa.m[p1.x1][p1.y1+1]=5;
            p1.y1=p1.y1+1;
        }else if(mapa.m[p1.x1][p1.y1+1]==6){
            mapa.m[p1.x1][p1.y1]=0;
            p1.coord1(42,16);
            mapa.m[p1.x1][p1.y1]=5;
        }
        break;
    case 75:
        if(mapa.m[p1.x1-1][p1.y1]==0){
            mapa.m[p1.x1][p1.y1]=0;
            mapa.m[p1.x1-1][p1.y1]=5;
            p1.x1=p1.x1-1;
        }else if(mapa.m[p1.x1-1][p1.y1]==6){
            mapa.m[p1.x1][p1.y1]=0;
            p1.coord1(45,40);
            mapa.m[p1.x1][p1.y1]=5;
        }
        break;
    case 77:
        if(mapa.m[p1.x1+1][p1.y1]==0){
            mapa.m[p1.x1][p1.y1]=0;
            mapa.m[p1.x1+1][p1.y1]=5;
            p1.x1=p1.x1+1;
        }else if(mapa.m[p1.x1+1][p1.y1]==6){
            mapa.m[p1.x1][p1.y1]=0;
            p1.coord1(30,10);
            mapa.m[p1.x1][p1.y1]=5;
        }
        break;
    case 'u':
        int m;
        m = p.x;
        extrai(m,"x.txt");
        m = p.y;
        extrai(m,"y.txt");
        m = p1.x1;
        extrai(m,"x1.txt");
        m = p1.y1;
        extrai(m,"y1.txt");
        break;
    case 'j':

        system("cls");
        menu();

        break;
    }
}


int jogosalvo(){

    mostrarCursor(false);
    PLAYER p;
    int m,n;
    m = expor(m,"x.txt");
    n = expor(n,"y.txt");
    p.coord(m,n);
    PLAYER1 p1;
    int r,t;
    r = expor(r,"x1.txt");
    t = expor(t,"y1.txt");
    p1.coord1(t,r);

    ARQUIVO mapa;
    mapa.nome="labirinto.txt";
    mapa.tam(90,89);
    mapa.carrega();



    while (true){
        mostra_mapa(mapa, p);
        mostra_mapa1(mapa,p1);

        if(abs(p.x-p1.x1)>=3||abs(p.y-p1.y1)>=3){
            mover(p, p1, mapa);

    }else{
            system("cls");
            cout<<"Voce perdeu"<<endl;
            system("pause");
             return 0;
            }


    }
}


int jogoinicial(){

    system("cls");

    cout << endl << endl << endl << endl << endl;
    cout << "\n\n\n\n\n\n\n Pause: press [n]";

    mostrarCursor(false);
    PLAYER p;
    p.coord(1,1);
    PLAYER1 p1;
    p1.coord1(49,7);

    ARQUIVO mapa;
    mapa.nome="labirinto.txt";
    mapa.tam(90,90);
    mapa.carrega();

    clock_t inicio;
    inicio = clock(); // tempo inicial
    while (true){
        mostra_mapa(mapa, p);
        mostra_mapa1(mapa,p1);
         ;
        if(abs(p.x-p1.x1)>=3||abs(p.y-p1.y1)>=3){
            mover(p, p1, mapa);

    }else{
            system("cls");
            cout<<"Voce perdeu"<<endl;
            system("pause");
             return 0;
            }


    }

}


bool iskeypressed(){
  return WaitForSingleObject(
    GetStdHandle( STD_INPUT_HANDLE ),
    0
    ) == WAIT_OBJECT_0;
    return getch();
  }

char getchno(){

    if(iskeypressed()==1){
        return getch();
    }return -1;
}

void relogio(clock_t inicio){

    clock_t soma=33.33;
    posicaoxy(0, 27);
    cout<<"relogio: "<<( clock() - inicio + soma ) / (double) CLOCKS_PER_SEC;

}


void menu (){
    ifstream pause;
        pause.open("pause.txt");
        string linha;
        if(pause.is_open()){
                while(getline(pause, linha)){
                    cout << linha << endl;
                }
        }else {
            cout << "N�o foi poss�vel carregar o Menu...";
        }
        char tec=getch();
        switch (tec){
        case 'a':
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n Pause: press [n]";

    break;

        case 'b':
            system("cls");
            jogoinicial();

    break;

        case 'p':
            system("cls");
            cout << "---- FIM DE JOGO ----" << endl;
            system("pause");
            system("cls");

            ifstream Menu;

        Menu.open("Menu.txt");
        string linha;

        if(Menu.is_open()){

                while(getline(Menu, linha)){
                    cout << linha << endl;
                }

        }else {
            cout << "N�o foi poss�vel carregar o Menu...";
        }
        cout << "Select: ";
        int opcao=getch();
        switch (opcao){
        case '1':
            Menu.close();
            jogoinicial();
        }
    }
}


int main()
{
    mostrarCursor(false);
    PLAYER p;
    PLAYER1 p1;
    p.coord(1,1);
    p1.coord1(49,7);

    ARQUIVO mapa;
    mapa.nome="labirinto.txt";
    mapa.tam(90,89);
    mapa.carrega();
    ifstream Menu;
        Menu.open("Menu.txt");
        string linha;
        if(Menu.is_open()){
                while(getline(Menu, linha)){
                    cout << linha << endl;
                }
        }else {
            cout<< "N�o foi poss�vel carregar o Menu...";
        }
        cout<< "Select: ";
        int opcao=getch();
        switch (opcao){
        case 'v':
            Menu.close();
            system("cls");
            jogoinicial();
            break;
        case 'c' :
            Menu.close();
            system("cls");
            jogosalvo();
            break;

}

clock_t inicio;
inicio = clock(); // tempo inicial


    while (true){

        relogio(inicio);
        mostra_mapa(mapa,p);
        mostra_mapa1(mapa,p1);
        if(abs(p.x-p1.x1)>=3||abs(p.y-p1.y1)>=3){
        mover(p,p1, mapa);
    }
        else{
            int e;
            system("cls");
            cout<<"GAME OVER"<<endl;
            cout<<"Deseja continuar?"<<endl;
            cout<<"1.JOGAR DE NOVO"<<endl<<"2.SAIR DO JOGO"<<endl;
            cin>>e;
            if(e==2){
            system("cls");
            system("pause");
            return 0;
            }
            else{
                return main();
            }
        }
    }
    return 0;
}
*/
