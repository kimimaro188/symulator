#include <iostream>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include <conio.h>

using namespace std;
void gotoxy( const int x, const int y ){ ///funkcja ktora ustawia kursor w wybranym miejscu

    COORD coord = { x, y };
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );
}
int wylozkarte(int karta){ ///zamiana wartosci liczbowych na karty
if(karta==2)cout<<"Dwojka    ";
else if(karta==3)cout<<"Trojka    ";
else if(karta==4)cout<<"Czworka   ";
else if(karta==5)cout<<"Piatka    ";
else if(karta==6)cout<<"Szostka   ";
else if(karta==7)cout<<"Siodemka  ";
else if(karta==8)cout<<"Osemka    ";
else if(karta==9)cout<<"Dziewiatka";
else if(karta==10)cout<<"Dycha     ";
else if(karta==11)cout<<"Jupek     ";
else if(karta==12)cout<<"Dama      ";
else if(karta==13)cout<<"Krol      ";
else cout<<"As        ";
}

void symulacjagry(){
    int cards1=26,cards2=26,ruchy[2000];
    int gracz1[100],gracz2[100],tablica[54],x,y;

    for(int e=0;e<100;e++){ ///uzupelnienie kart graczy wartosciami 0, czyli zadnymi kartami
        gracz1[e]=0;
        gracz2[e]=0;
    }
    srand(time(NULL));
    for(int i=0;i<26;i++){          ///mechanizm rozlosowania losowych kart obu graczom
        x=rand()%52;
        for(int q=0;q<2*i;q++){
           if(tablica[q]==x){
            x=rand()%52;
            q=-1;
           }
        }
    tablica[2*i]=x;
    gracz1[i]=x;
    /// losowanie karty dla drugiego gracza
    y=rand()%52;
        for(int q=0;q<=2*i;q++){
           if(tablica[q]==y){
            y=rand()%52;
            q=-1;
           }
        }
    tablica[2*i+1]=y;
    gracz2[i]=y;
    }

        for(int i=0;i<26;i++){
        for(int p=0;p<26;p++){
            if(gracz1[i]==gracz2[p]){cout<<i<<"powtorzenie!!!!!!"<<p<<endl;}     ///          Test czy jakies wartosci sie powtarzaja
        }
    }

        for(int i=0;i<26;i++){  ///petla ktora zamienia wartosci na takie zeby funkcja wylozkarte() moglo zamienic na wartosci "karciane"
                gracz1[i]=(gracz1[i]/4)+2;
                gracz2[i]=(gracz2[i]/4)+2;
        }

int a=rand()%4+1;               ///Zabieg kosmetyczny tasowania kart, ktore tak naprawde tasuja sie ulamek sekundy :)
for(int i=0;i<a;i++){
system("cls");
cout<<"Trwa tasowanie kart";
Sleep(400);
cout<<".";
Sleep(400);
cout<<".";
Sleep(400);
cout<<".";
Sleep(400);
}
system("cls");

cout<<"Karty gracza nr.1:"<<'\t'<<'\t'<<'\t'<<'\t'<<"Karty gracz nr. 2:"<<endl<<endl;       ///wypisanie kart obu graczy zaraz po rozdaniu w dwoch ladnych kolumnach

    for(int i=0;i<26;i++){
        Sleep(100);
        wylozkarte(gracz1[i]);
        cout<<'\t'<<'\t'<<'\t'<<'\t'<<'\t';
        Sleep(100);
        wylozkarte(gracz2[i]);
        cout<<endl;
    }

cout<<endl<<endl<<"Po nacisnieciu dowolnego klawisza nastapi symulacja gry w wojne";
getch();
a=rand()%3+1;
for(int i=0;i<a;i++){
system("cls");
cout<<"Trwa symulacja gry, prosze czekac"; ///kolejny zabieg kosmetyczny
Sleep(400);
cout<<".";
Sleep(400);
cout<<".";
Sleep(400);
cout<<".";
Sleep(400);
}
system("cls");
/*************************************************************************************************/
/*************************************************************************************************/
/*************************************************************************************************/
/*************************************************************************************************/
int licznik=0;
while((gracz1[0]!=0)&&(gracz2[0]!=0)){ ///glowna petla programu ktora rozstrzyga wygrana w kazdym ruchy
licznik++;

         if(gracz1[0]>gracz2[0]){ ///gracz 1 wygrywa

            ruchy[(2*licznik)-2]=gracz1[0]; ///zapis do zmiennej ktora na koncu wyswietla wszystkie ruchy po kolei
            ruchy[(2*licznik)-1]=gracz2[0];

            gracz1[cards1]=gracz1[0]; /// zapis na koncu talii wygranych kart podczas wojny
            cards1++;
            cards2--;
            gracz1[cards1]=gracz2[0];

            for(int p=0;p<98;p++){ ///przenumerowanie kart
                gracz1[p]=gracz1[p+1];
                gracz2[p]=gracz2[p+1];
            }
                }

///*************************************************************************************************************************************************************************\\\
///*************************************************************************************************************************************************************************\\\


            else if(gracz2[0]>gracz1[0]){ ///gracz 2 wygrywa i procedura jak we wczesniejszym przypadku

                ruchy[(2*licznik)-2]=gracz1[0];
                ruchy[(2*licznik)-1]=gracz2[0];

                gracz2[cards2]=gracz2[0];
                cards2++;
                cards1--;
                gracz2[cards2]=gracz1[0];

            for(int g=0;g<98;g++){ //przesuniecie kart do wyjsciowej pozycji
                gracz1[g]=gracz1[g+1];
                gracz2[g]=gracz2[g+1];
                }
            }

///*************************************************************************************************************************************************************************\\\
///*************************************************************************************************************************************************************************\\\

else if(gracz1[0]==gracz2[0]){ ///przypadek kiedy mamy do czynienia z dogrywka

            ruchy[(2*licznik)-2]=gracz1[0]; ///zapis do zmiennej ktora wyswietla ruchy na koncu aplikacji
            ruchy[(2*licznik)-1]=gracz2[0];

int powt=2;
for(;;){
            ruchy[(2*licznik)-2+powt]=gracz1[0];  ///w przypadku dogrywki udzial w grze bierze conajmniej 6kart, musi byc wiecej przypisow
            ruchy[(2*licznik)-1+powt]=gracz2[0];

            ruchy[(2*licznik)-1+powt]=gracz1[0];
            ruchy[(2*licznik)+powt]=gracz2[0];

        if((gracz1[powt]==0)||(gracz1[powt-1]==0)){ ///przypadek kiedy gracz1 nie ma wystarczajaco kart do rozegrania dogrywki
            goto koniec2;
        }

///*************************************************************************************************************************************************************************\\\

        else if((gracz2[powt]==0)||(gracz2[powt-1]==0)){ ///przypadek kiedy gracz2 nie ma wystarczajaco kart do rozegrania dogrywki
            goto koniec1;
        }

///*************************************************************************************************************************************************************************\\\


        else if(gracz1[powt]==gracz2[powt]){ /// przypadek kiedy potrzebna jest dogrywka dogrywki
            powt=powt+2;
        }

///*************************************************************************************************************************************************************************\\\

        else if(gracz1[powt]>gracz2[powt]){ ///gracz1 wygrywa dogrywke, nastepuje przypisanie kart, a potem przenumerowanie
            for(int i=0;i<=powt;i++){
                gracz1[cards1+i]=gracz1[i];
                gracz1[cards1+i+powt+1]=gracz2[i];

            }

            cards1=cards1+1+powt;
            cards2=cards2-(1+powt);

            for(int i=0;i<=90;i++){
                gracz1[i]=gracz1[powt+1+i];
                gracz2[i]=gracz2[powt+1+i];
            }


            break;
        }

 ///*************************************************************************************************************************************************************************\\\

        else if(gracz2[powt]>gracz1[powt]){  ///gracz2 wygrywa dogrywke, nastepuje przypisanie kart, a potem przenumerowanie
            for(int i=0;i<=powt;i++){
                gracz2[cards2+i]=gracz2[i];
                gracz2[cards2+i+powt+1]=gracz1[i];

            }

            cards2=cards2+1+powt;
            cards1=cards1-(1+powt);

            for(int i=0;i<=90;i++){
                gracz1[i]=gracz1[powt+1+i];
                gracz2[i]=gracz2[powt+1+i];
            }


            break;
        }

}
    }
}

        if(cards1==0){  ///gracz 2 wygrywa
                koniec2:
        cout<<"wygral gracz nr2, potrzebowal na to "<<licznik<<" ruchow"<<endl<<endl;
        Sleep(900);
        cout<<"Oto koncowe rozstawienie kart w talii zwycieskiego gracza:"<<endl<<endl<<endl;
        for(int i=1;i<=4;i++){
        for(int a=1;a<=13;a++){
        gotoxy(12*i-12,a+4);
      //  wylozkarte(gracz2[(i*a)-1]);
          wylozkarte(gracz2[(13*(i-1))+a-1]);

    Sleep(90);
    }
}
                    }


        else if(cards2==0){ ///gracz 1 wygrywa
                koniec1:
        cout<<"wygral gracz nr1, potrzebowal na to "<<licznik<<" ruchow"<<endl<<endl;
        Sleep(900);
        cout<<"Oto koncowe rozstawienie kart w talii zwycieskiego gracza:"<<endl<<endl<<endl;

        for(int i=1;i<=4;i++){
        for(int a=1;a<=13;a++){
        gotoxy(12*i-12,a+4);
      //  wylozkarte(gracz1[(i*a)-1]);
           wylozkarte(gracz1[(13*(i-1))+a-1]);

    Sleep(90);
    }
}
}



gotoxy(0,20);

cout<<"Jesli chcesz zobaczyc przebieg gry wpisz tutaj liczbe ruchow"<<endl;  ///caly mechanizm wypisywania na ekran ruchow
cout<<"ktore chcesz zobaczyc i kliknij 'enter'"<<endl<<endl;
cout<<"Po wcisnieciu 0 zostaniesz przeniesiony do menu"<<endl<<endl;

int ile;
cin>>ile;
system("cls");
int z=0;

for(int i=0;i<ile;i++){
        Sleep(90);
cout<<"gracz1: ";
    wylozkarte(ruchy[2*i]);
    cout<<"   vs   ";
    cout<<"gracz2: ";
    wylozkarte(ruchy[(2*i)+1]);
    if((ruchy[2*i])>(ruchy[(2*i)+1])){
        if(z==1){z=0;cout<<'\t'<<"Karty sa dalej na stole"<<endl;}
        else{cout<<'\t'<<"Wygral gracz nr.1"<<endl;}
    }
    else if((ruchy[2*i])<(ruchy[(2*i)+1])){
        if(z==1){z=0;cout<<'\t'<<"Karty sa dalej na stole"<<endl;}
        else{cout<<'\t'<<"Wygral gracz nr.2"<<endl;}
    }
    else{
        if(z==1){
            z=0;
            cout<<'\t'<<"Karty sa dalej na stole"<<endl;
        }
        else{
        cout<<'\t'<<"Dogrywka!"<<endl;
        z=1;
        }
    }
}
if(ile!=0){
        cout<<endl<<"Po nacisnieciu dowolnego przycisku zostaniesz przeniesiony do menu.";
    getch();
}
}

opisgry(){ ///instrukcja
    cout<<"Jest to typowa symulacja karcianej gry w wojne, wygrany gracz zgarnia wszystkie karty ze stolu, przegrany zadnej. Sa 3 warianty pojedynczego rozdania:"<<endl<<endl;
    cout<<"1. Karta gracza pierwszego ma wieksza wartosc od karty gracza drugiego,"<<endl;
    cout<<"wtedy jako pierwsza do talii wsuwa swoja zwycieska karte, nastepnie karte"<<endl<<"przeciwnika"<<endl;
    cout<<endl<<"2. Karta gracza drugiego ma wieksza wartosc od karty gracza pierwszego, wtedy"<<endl<<"jako pierwsza do talii wsuwa swoja zwycieska karte, nastepnie karte przeciwnika."<<endl;
    cout<<"3. Ostatnia opcja ma miejsce kiedy karty obu graczy sa rowne, kiedy na przyklad"<<endl<<"obaj wyciagna 'jupka'. W takiej sytuacji nastepuje tzw. 'dogrywka', gdzie obaj"<<endl<<
    "gracze klada ";
    cout<<"na stos kolejna karte ktora nie bierze udzialu w grze i na nia"<<endl<<"klada nastepna od ktorej zalezy wynik wojny, jesli karty sa znowu rowne nalezy"<<endl<<"powtorzyc czynnosc z 'dogrywki'."<<endl;
    cout<<endl<<"Wygrany gracz zgarnia wszystkie karty dla siebie zaczynajac od swoich."<<endl;
    cout<<"Gra trwa do momentu kiedy ktoremus z graczy skoncza sie karty.";
}



int main(){ ///mechanizm menu, uzyte funkcje wyzej
int wybor;
    int poprzedniWybor;
    bool wykonujPetle;

    //pêtla g³ówna programu
    start:
    while( 1 )
    {
        wybor = 0;
        poprzedniWybor = wybor;
        wykonujPetle = true;

        //rysowanie menu
        system( "cls" );
        gotoxy( 3, 1 );
        cout << "Symulacja";
        gotoxy( 3, 3 );
        cout << "Instrukcja symulatora ";
        gotoxy( 3, 5 );
        cout << "Wyjscie";
        gotoxy( 46, 10 );
        cout<<"Artur Szczypta "<<char(1);
        gotoxy( 46, 11 );
        cout<<"Kontakt: szczypta.artur@gmail.com";
        gotoxy( 46, 1);
        cout<<"Nacisnij strzalke w prawo";

        //przesuwanie strza³ki
        while( wykonujPetle )
        {
            //rysowanie strza³ki wyboru
            gotoxy( 1, wybor * 2 + 1 );
            cout << static_cast < char >( 16 );

            //obs³uga klawiatury
            poprzedniWybor = wybor;
            switch( getch() )
            {
            case 224: //STRZA£KI
                switch( getch() )
                {
                case 72: //strza³ka w górê
                    if( 0 < wybor ) wybor--;
                    else wybor = 2;

                    break;

                case 80: //strza³ka w dó³
                    if( wybor < 2 ) wybor++;
                    else wybor = 0;

                    break;

                case 77: //strza³ka w prawo
                    //je¿eli wciœniêto strza³kê w prawo, sprawdŸ wybran¹ opcjê i wykonaj odpowiedni¹ akcjê
                    switch( wybor )
                    {
                    case 0:
                        system("cls");
                        symulacjagry();
                        getch();
                        goto start;

                    case 1:
                        system("cls");
                        opisgry();
                        getch();
                        goto start;

                    case 2:
                        return 0;
                    }
                }
                break;
            }

            //czyszczenie strza³ki wyboru
            gotoxy( 1, poprzedniWybor * 2 + 1 );
            cout << " ";
        }
    }
    return 0;
}
