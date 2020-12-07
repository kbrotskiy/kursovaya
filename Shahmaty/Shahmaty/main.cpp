// 11.10.2020
//



//пешка пропала у черных
//белая ладья съела своего
#include <iostream>
#include <cstring>
#include <iomanip>
//#include <Windows.h>


using namespace std;
int board[8][8], vuborka[64][3], k_vub, i, j, x, y, vubor_sis, x_nov, y_nov, izmen_figura_cher, izmen_figura_bel, x_ogr, y_ogr, klych, x_ogr_goriz, y_ogr_goriz;
int ogr_ferz_goriz, ogr_ferz_vertikal, vubor;
int schet_bel = 0;
int schet_cher = 0;
int prov=0, schet=0, schet2=0, hod=0;
int pr = 0;//проверка дл€ счета дл€ белых
int pr_ch = 0;//проверка дл€ счета дл€ черных
int x_1_ogr, y_1_ogr, x_2_ogr, y_2_ogr, x_3_ogr, y_3_ogr, x_4_ogr, y_4_ogr; // ограничени€ дл€ диагоналей
int shax_and_mat=0;
string itog[8][8], bukv[8];
char buk, tsifr;

void vuvod() {
   // HANDLE hConsol = GetStdHandle(STD_OUTPUT_HANDLE);
    bukv[0] = "A";
    bukv[1] = "B";
    bukv[2] = "C";
    bukv[3] = "D";
    bukv[4] = "E";
    bukv[5] = "F";
    bukv[6] = "G";
    bukv[7] = "H";
    cout << endl;
    if (vubor == 1) {
        //SetConsoleTextAttribute(hConsol, 6);
        for (j = 0; j < 39; j++) {
            cout << "-";
        }
        cout<<endl;
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                cout << setw(2) << board[i][j] << " | ";
            }
            cout << "   " << i + 1;
            if (i == 4) {
            cout << "        Счет:  " << schet_bel << " : " << schet_cher;
        }
cout << endl;
      for (j = 0; j < 39; j++) {
                cout << "-";
            }
            cout<<endl;
        }
        
        
        
        for (i = 0; i < 8; i++) {
            if (i==0){
            cout << " " << bukv[i] << "  ";
            }
            if (i==1){
                cout << "  " << bukv[i] << " ";
            }
            if (i==2){
                cout << "   " << bukv[i] << "   ";
            }
            if (i==3){
            cout << " " << bukv[i] << "  ";
            }
            if (i==4){
                cout << "  " << bukv[i] << " ";
            }
            if (i==5){
                cout << "   " << bukv[i] << "  ";
            }
            if (i==6){
                cout << "  " << bukv[i] << "  ";
            }
            if (i==7){
                cout << "  " << bukv[i] << "   ";
            }
            
        }
    }
    if (vubor == 2) {

        for (j = 0; j < 8; j++) {
            if ((j % 2 == 0) && (board[0][j] == 0)) {
                itog[0][j] = "W ";
            }
            else { itog[0][j] = "B "; }

            if ((j % 2 == 1) && (board[1][j] == 0)) {
                itog[1][j] = "W ";
            }
            else { itog[1][j] = "B "; }

            if ((j % 2 == 0) && (board[2][j] == 0)) {
                itog[2][j] = "W ";
            }
            else { itog[2][j] = "B "; }

            if ((j % 2 == 1) && (board[3][j] == 0)) {
                itog[3][j] = "W ";
            }
            else { itog[3][j] = "B "; }

            if ((j % 2 == 0) && (board[4][j] == 0)) {
                itog[4][j] = "W ";
            }
            else { itog[4][j] = "B "; }

            if ((j % 2 == 1) && (board[5][j] == 0)) {
                itog[5][j] = "W ";
            }
            else { itog[5][j] = "B "; }

            if ((j % 2 == 0) && (board[6][j] == 0)) {
                itog[6][j] = "W ";
            }
            else { itog[6][j] = "B "; }

            if ((j % 2 == 1) && (board[7][j] == 0)) {
                itog[7][j] = "W ";
            }
            else { itog[7][j] = "B "; }
        }

        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                if (board[i][j] == 1) {
                    itog[i][j] = "Pw";
                }
                if (board[i][j] == 2) {
                    itog[i][j] = "Hw";
                }
                if (board[i][j] == 3) {
                    itog[i][j] = "Sw";
                }
                if (board[i][j] == 4) {
                    itog[i][j] = "Lw";
                }
                if (board[i][j] == 5) {
                    itog[i][j] = "Fw";
                }
                if (board[i][j] == 6) {
                    itog[i][j] = "Kw";
                }

                if (board[i][j] == -1) {
                    itog[i][j] = "Pb";
                }
                if (board[i][j] == -2) {
                    itog[i][j] = "Hb";
                }
                if (board[i][j] == -3) {
                    itog[i][j] = "Sb";
                }
                if (board[i][j] == -4) {
                    itog[i][j] = "Lb";
                }
                if (board[i][j] == -5) {
                    itog[i][j] = "Fb";
                }
                if (board[i][j] == -6) {
                    itog[i][j] = "Kb";
                }
            }
        }

        for (j = 0; j < 48; j++) {
            cout << "-";
        }cout << endl;

        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                //вывод белых фигур
                if ((itog[i][j] == "W ") || (itog[i][j] == "Pw") || (itog[i][j] == "Hw") || (itog[i][j] == "Sw") || (itog[i][j] == "Lw") || (itog[i][j] == "Fw") || (itog[i][j] == "Kw")) {
                    //SetConsoleTextAttribute(hConsol, 11);
                    cout << setw(4) << itog[i][j] << " |";
                }

                //вывод черных фигур
                if ((itog[i][j] == "B ") || (itog[i][j] == "Pb") || (itog[i][j] == "Hb") || (itog[i][j] == "Sb") || (itog[i][j] == "Lb") || (itog[i][j] == "Fb") || (itog[i][j] == "Kb")) {
                   // SetConsoleTextAttribute(hConsol, 12);
                    cout << setw(4) << itog[i][j] << " |";
                }

                
            }
           // SetConsoleTextAttribute(hConsol, 14);
            cout << "   " << i + 1;
            if (i==4){
                cout << "        Счет:  " << schet_bel << " : " << schet_cher;
            }
            cout << endl;
            
            for (j = 0; j < 48; j++) {
                cout << "-";
            }cout << endl;
        }
        
        for (i = 0; i < 8; i++) {
                   if (i==0){
                   cout << "  " << bukv[i] << "  ";
                   }
                   if (i==1){
                       cout << "   " << bukv[i] << " ";
                   }
                   if (i==2){
                       cout << "    " << bukv[i] << "   ";
                   }
                   if (i==3){
                   cout << "  " << bukv[i] << "  ";
                   }
                   if (i==4){
                       cout << "   " << bukv[i] << " ";
                   }
                   if (i==5){
                       cout << "    " << bukv[i] << "  ";
                   }
                   if (i==6){
                       cout << "   " << bukv[i] << "  ";
                   }
                   if (i==7){
                       cout << "   " << bukv[i] << "   ";
                   }
                   
               }

        cout << endl << endl;
    }
    if (vubor == 3) {

        for (j = 0; j < 8; j++) {
            if ((j % 2 == 0) && (board[0][j] == 0)) {
                itog[0][j] = "";
            }
            else { itog[0][j] = ""; }

            if ((j % 2 == 1) && (board[1][j] == 0)) {
                itog[1][j] = "";
            }
            else { itog[1][j] = ""; }

            if ((j % 2 == 0) && (board[2][j] == 0)) {
                itog[2][j] = "";
            }
            else { itog[2][j] = ""; }

            if ((j % 2 == 1) && (board[3][j] == 0)) {
                itog[3][j] = "";
            }
            else { itog[3][j] = ""; }

            if ((j % 2 == 0) && (board[4][j] == 0)) {
                itog[4][j] = "";
            }
            else { itog[4][j] = ""; }

            if ((j % 2 == 1) && (board[5][j] == 0)) {
                itog[5][j] = "";
            }
            else { itog[5][j] = ""; }

            if ((j % 2 == 0) && (board[6][j] == 0)) {
                itog[6][j] = "";
            }
            else { itog[6][j] = ""; }

            if ((j % 2 == 1) && (board[7][j] == 0)) {
                itog[7][j] = "";
            }
            else {
                itog[7][j] = ""; }
        }

        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                if (board[i][j] == 1) {
                    itog[i][j] = "♙";
                }
                if (board[i][j] == 2) {
                    itog[i][j] = "♘";
                }
                if (board[i][j] == 3) {
                    itog[i][j] = "♗";
                }
                if (board[i][j] == 4) {
                    itog[i][j] = "♖";
                }
                if (board[i][j] == 5) {
                    itog[i][j] = "♕";
                }
                if (board[i][j] == 6) {
                    itog[i][j] = "♔";
                }

                if (board[i][j] == -1) {
                    itog[i][j] = "♟︎";
                }
                if (board[i][j] == -2) {
                    itog[i][j] = "♞";
                }
                if (board[i][j] == -3) {
                    itog[i][j] = "♝";
                }
                if (board[i][j] == -4) {
                    itog[i][j] = "♜";
                }
                if (board[i][j] == -5) {
                    itog[i][j] = "♛";
                }
                if (board[i][j] == -6) {
                    itog[i][j] = "♚";
                }
            }
        }

        for (j = 0; j < 40; j++) {
            cout << "-";
        }cout << endl;

        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                //вывод белых фигур
                if ((itog[i][j] == "") || (itog[i][j] == "♙") || (itog[i][j] == "♘") || (itog[i][j] == "♗") || (itog[i][j] == "♖") || (itog[i][j] == "♕") || (itog[i][j] == "♔")) {
                    //SetConsoleTextAttribute(hConsol, 11);
                    if (itog[i][j]!=""){
                    cout << setw(5) << itog[i][j] << " |";
                    } else {
                        cout << setw(3) << itog[i][j] << " |";
                    }
                }

                //вывод черных фигур
                if ((itog[i][j] == "♟︎") || (itog[i][j] == "♞") || (itog[i][j] == "♝") || (itog[i][j] == "♜") || (itog[i][j] == "♛") || (itog[i][j] == "♚")) {
                   // SetConsoleTextAttribute(hConsol, 12);
                    if (itog[i][j]!=""){
                    cout << setw(2) <<""<< itog[i][j] << " |";
                    } else {
                        cout << setw(3) << itog[i][j] << " |";
                    }
                }

                
            }
           // SetConsoleTextAttribute(hConsol, 14);
            cout << "   " << i + 1;
            if (i==4){
                cout << "        Счет:  " << schet_bel << " : " << schet_cher;
            }
            cout << endl;
            
            for (j = 0; j < 40; j++) {
                cout << "-";
            }cout << endl;
        }
        
        for (i = 0; i < 8; i++) {
                   if (i==0){
                   cout << "  " << bukv[i] << " ";
                   }
                   if (i==1){
                       cout << "   " << bukv[i] << "";
                   }
                   if (i==2){
                       cout << "    " << bukv[i] << " ";
                   }
                   if (i==3){
                   cout << "   " << bukv[i] << "  ";
                   }
                   if (i==4){
                       cout << "  " << bukv[i] << " ";
                   }
                   if (i==5){
                       cout << "   " << bukv[i] << "  ";
                   }
                   if (i==6){
                       cout << "  " << bukv[i] << "  ";
                   }
                   if (i==7){
                       cout << "  " << bukv[i] << "   ";
                   }
                   
               }

        cout << endl << endl;
    }
}



void peshka(){
    //бела€ пешка атака диагональ вправо
    if ((x - x_nov < 2) && (x - x_nov > 0) && (y_nov - y < 2) && (y_nov - y > 0)) {
        if (((board[x_nov][y_nov] != -6) || (board[x_nov][y_nov] != 6)) && (board[x_nov][y_nov] != 0)) {
            board[x_nov][y_nov] = board[x][y];
            board[x][y] = 0;
            pr = 1;
            schet_bel+=1;
        }
    }

    //бела€ пешка атака диагональ влево
    if ((x - x_nov < 2) && (x - x_nov > 0) && (y - y_nov < 2) && (y - y_nov > 0)) {
        if (((board[x_nov][y_nov] != -6) || (board[x_nov][y_nov] != 6)) && (board[x_nov][y_nov] != 0)) {
            board[x_nov][y_nov] = board[x][y];
            board[x][y] = 0;
            pr = 1;
            schet_bel+=1;
        }
    }

    //черна€ пешка атака диагональ вправо
    if ((x_nov - x < 2) && (x_nov - x > 0) && (y_nov - y < 2) && (y_nov - y > 0)) {
        if (((board[x_nov][y_nov] != -6) || (board[x_nov][y_nov] != 6)) && (board[x_nov][y_nov] != 0)) {
            board[x_nov][y_nov] = board[x][y];
            board[x][y] = 0;
            pr_ch = 1;
            schet_cher+=1;
        }
    }

    //черна€ пешка атака диагональ влево
    if ((x_nov - x < 2) && (x_nov - x > 0) && (y - y_nov < 2) && (y - y_nov > 0)) {
        if (((board[x_nov][y_nov] != -6) || (board[x_nov][y_nov] != 6)) && (board[x_nov][y_nov] != 0)) {
            board[x_nov][y_nov] = board[x][y];
            board[x][y] = 0;
            pr_ch = 1;
            schet_cher+=1;
        }
    }

    //ход пешки вперед
    if (((((((x - x_nov) < 2) && (x - x_nov > 0)) || (((x_nov - x) < 2) && (x_nov - x > 0)))) || (((((x - x_nov) < 3) && (x - x_nov > 0) && (x = 6)) || (((x_nov - x) < 3) && (x_nov - x > 0) && (x = 1))) && ((y_nov - y) < 1))) && (board[x_nov][y_nov]==0)) {
        if (((y-y_nov<=1) && (y-y_nov>=0)) || ((y_nov-y>=-1) && (y_nov-y<=0))){
        board[x_nov][y_nov] = board[x][y];
        board[x][y] = 0;
        }
    }
    else {
        cout << "Ваш ход неверный! Cчитаю вам стоит подучить правила ;)" << endl;
    }
    
    //замена белых пешек на другие фигуры
    if ((board[0][0] == 1) || (board[0][1] == 1) || (board[0][2] == 1) || (board[0][3] == 1) || (board[0][4] == 1) || (board[0][5] == 1) || (board[0][6] == 1) || (board[0][7] == 1)) {
        if (board[0][0] == 1) { board[0][0] = izmen_figura_bel; }
        if (board[0][1] == 1) { board[0][1] = izmen_figura_bel; }
        if (board[0][2] == 1) { board[0][2] = izmen_figura_bel; }
        if (board[0][3] == 1) { board[0][3] = izmen_figura_bel; }
        if (board[0][4] == 1) { board[0][4] = izmen_figura_bel; }
        if (board[0][5] == 1) { board[0][5] = izmen_figura_bel; }
        if (board[0][6] == 1) { board[0][6] = izmen_figura_bel; }
        if (board[0][7] == 1) { board[0][7] = izmen_figura_bel; }
    }

    //замена черных пешек на другие фигуры
    if ((board[7][0] == 1) || (board[7][1] == 1) || (board[7][2] == 1) || (board[7][3] == 1) || (board[7][4] == 1) || (board[7][5] == 1) || (board[7][6] == 1) || (board[7][7] == 1)) {
        if (board[7][0] == -1) { board[7][0] = izmen_figura_cher; }
        if (board[7][1] == -1) { board[7][1] = izmen_figura_cher; }
        if (board[7][2] == -1) { board[7][2] = izmen_figura_cher; }
        if (board[7][3] == -1) { board[7][3] = izmen_figura_cher; }
        if (board[7][4] == -1) { board[7][4] = izmen_figura_cher; }
        if (board[7][5] == -1) { board[7][5] = izmen_figura_cher; }
        if (board[7][6] == -1) { board[7][6] = izmen_figura_cher; }
        if (board[7][7] == -1) { board[7][7] = izmen_figura_cher; }
    }
}


//void peshka_intel(){


void ladya(){
    if (board[x][y] == 4) {
        //ограничение по вертикали дл€ белой ладьи снизу вверх
        if ((y_nov == y) && (x > x_nov)) {
            for (i = x - 1; i > -1; i--) {
                if (board[i][y] != 0) {
                    pr = 1;
                    x_ogr = i;
                    y_ogr = y;
                    break;
                }
            }
        }

        if (((y_nov == y_ogr) && (x_nov < x)) || ((y_nov == y_ogr) && (x_nov == x) && ((board[x_nov][y_nov] > -6) && (board[x_nov][y_nov] <= 0)))) {
            board[x_nov][y_nov] = board[x][y];
            board[x][y] = 0;
            pr = 1;
        }

        //ограничение по вертикали дл€ белой ладьи сверху вниз
        if ((y_nov == y) && (x < x_nov)) {
            for (i = x + 1; i < 7; i++) {
                if (board[i][y] != 0) {
                    pr = 1;
                    x_ogr = i;
                    y_ogr = y;
                    break;
                }
            }
        }

        if (((y_nov == y_ogr) && (x < x_nov)) || ((y_nov == y) && (x_nov == x) && ((board[x_nov][y_nov] > -6) && (board[x_nov][y_nov] <= 0)))) {
            board[x_nov][y_nov] = board[x][y];
            board[x][y] = 0;
            pr = 1;
        }
        int x_ogr_goriz = 0;
        int y_ogr_goriz = 0;

        if (x == x_nov) {
            //ограничение по горизонтали дл€ белой ладьи справа налево
            if ((x_nov == x) && (y > y_nov)) {
                for (i = y - 1; i > -1; i--) {
                    if (board[x][i] != 0) {
                        pr = 1;
                        x_ogr_goriz = x;
                        y_ogr_goriz = i;
                        break;
                    }
                    else {
                        x_ogr_goriz = x;
                        pr = 1;
                        y_ogr_goriz = 0;
                    }
                }
            }

            if (((y_nov > y_ogr_goriz) && (x_nov >= x_ogr_goriz)) || (((x_nov == x_ogr_goriz) || (x_nov > x_ogr_goriz)) && (y_nov == y) && ((board[x_nov][y_nov] > -6) && (board[x_nov][y_nov] < 0)))) {
                board[x_nov][y_nov] = board[x][y];
                board[x][y] = 0;
                pr = 1;
            }
            //ограничение по горизонтали дл€ белой ладьи слева направо
            if ((x_nov == x) && (y < y_nov)) {
                for (i = y + 1; i > -1; i--) {
                    if (board[x][i] != 0) {
                        x_ogr_goriz = x;
                        pr = 1;
                        y_ogr_goriz = i;
                        break;
                    }
                    else {
                        x_ogr_goriz = x;
                        pr = 1;
                        y_ogr_goriz = 0;
                    }
                }
            }

            if (((y_nov < y_ogr_goriz) && (x_nov == x_ogr_goriz)) || ((x_nov < x_ogr_goriz) && (y_nov == y) && ((board[x_nov][y_nov] > -6) && (board[x_nov][y_nov] < 0)))) {
                board[x_nov][y_nov] = board[x][y];
                board[x][y] = 0;
                pr = 1;
            }

        }
    }



    //„≈–Ќјя Ћјƒ№я
    if (board[x][y] == -4) {

        //ограничение по вертикали дл€ черной ладьи сверху вниз
        if ((y_nov == y) && (x < x_nov)) {
            for (i = x + 1; i < 7; i++) {
                if (board[i][y] != 0) {
                    x_ogr = i;
                    pr_ch = 1;
                    y_ogr = y;
                    break;
                }
            }
            //cout << x_ogr << " - - - - -" << y_ogr;


            if ((((x_nov < x_ogr) && (y_nov == y)) && (x_nov > x)) || ((x_nov == x_ogr) && (y_nov == y_ogr) && (board[x_nov][y_nov] < 6) && (board[x_nov][y_nov] > 0))) {
                pr_ch = 1;
                board[x_nov][y_nov] = board[x][y];
                board[x][y] = 0;
            }
        }


        //снизу вверх
        if ((y_nov == y) && (x > x_nov)) {
            for (i = x - 1; i > -1; i--) {
                if (board[i][y] != 0) {
                    x_ogr = i;
                    pr_ch = 1;
                    y_ogr = y;
                    break;
                }
            }
            //cout << x_ogr << " - - - - -" << y_ogr;


            if (((x_nov > x_ogr) && (y_nov == y)) || ((x_nov == x_ogr) && (y_nov == y_ogr) && (board[x_nov][y_nov] < 6) && (board[x_nov][y_nov] >= 0))) {
                pr_ch = 1;
                board[x_nov][y_nov] = board[x][y];
                board[x][y] = 0;
            }
        }


        //ограничение по горизонтали дл€ черной слева направо
        if ((x_nov == x) && (y < y_nov)) {
            for (i = y + 1; i < 7; i++) {
                if (board[x][i] != 0) {
                    x_ogr_goriz = x;
                    pr_ch = 1;
                    y_ogr_goriz = i;
                    break;
                }
                else {
                    x_ogr_goriz = x;
                    pr_ch = 1;
                    y_ogr_goriz = 0;
                }
            }
            //cout << x_ogr_goriz << "----" << y_ogr_goriz;
        }

        if ((((y_nov < y_ogr_goriz) || (y_ogr_goriz == 0)) && (x_nov == x_ogr_goriz)) || ((x_nov < x_ogr_goriz) && (y_nov == y) && ((board[x_nov][y_nov] < 6) && (board[x_nov][y_nov] > 0)))) {
            board[x_nov][y_nov] = board[x][y];
            board[x][y] = 0;
            pr_ch = 1;
        }



        //ограничение по горизонтали дл€ черной ладьи справа налево
        if ((x_nov == x) && (y > y_nov)) {
            for (i = y + 1; i < 7; i++) {
                if (board[x][i] != 0) {
                    x_ogr_goriz = x;
                    pr_ch = 1;
                    y_ogr_goriz = i;
                    break;
                }
                else {
                    x_ogr_goriz = x;
                    pr_ch = 1;
                    y_ogr_goriz = 0;
                }
            }
            //cout << x_ogr_goriz << "--" << y_ogr_goriz;

            if ((((y_nov <= y_ogr_goriz) || (y_nov > y_ogr_goriz)) && (x_nov == x_ogr_goriz)) || ((x_nov == x_ogr_goriz) && (y_nov == y) && ((board[x_nov][y_nov] < 6) && (board[x_nov][y_nov] > 0)))) {
                board[x_nov][y_nov] = board[x][y];
                board[x][y] = 0;
                pr_ch = 1;
            }
        }


    }

}


void hourse(){
    if (board[x][y] == 2) {
        if ((board[x_nov][y_nov] <= 0) && (board[x_nov][y_nov] > -6)) {
            if (y_nov - y < 0) {
                //вверх влево
                if ((x_nov - x > -3) && (x_nov - x < 0) && (y_nov - y < 2) && (y_nov - y >= -1)) {
                    //cout << x_nov << " " << x << endl;
                    //cout << y_nov << " " << y << endl;
                    board[x_nov][y_nov] = board[x][y];
                    board[x][y] = 0;
                    pr = 1;
                }
            }


            //вверх вправо
            if (y_nov - y > 0) {
                if ((y_nov - y < 2) && (y_nov - y > 0) && (x_nov - x > -3) && (x_nov - x < 0)) {
                    board[x_nov][y_nov] = board[x][y];
                    board[x][y] = 0;
                    pr = 1;
                }
            }

            // вниз влево
            if ((x_nov - x < 3) && (x_nov - x > 0) && (y_nov - y > -2) && (y_nov - y < 0)) {
                board[x_nov][y_nov] = board[x][y];
                board[x][y] = 0;
                pr = 1;
            }


            //вниз  вправо
            if ((y_nov - y < 2) && (y_nov - y > 0) && (x_nov - x < 3) && (x_nov - x > 1)) {
                board[x_nov][y_nov] = board[x][y];
                board[x][y] = 0;
                pr = 1;
            }

            //влево вверх
            if ((x - x_nov == 1) && (y - y_nov == 2)) {
                board[x_nov][y_nov] = board[x][y];
                board[x][y] = 0;
                pr = 1;
            }

            //влево вниз
            if ((x - x_nov == -1) && (y - y_nov == 2)) {
                board[x_nov][y_nov] = board[x][y];
                board[x][y] = 0;
                pr = 1;
            }

            //вправо вверх
            if ((y_nov - y == 2) && (x - x_nov == 1)) {
                board[x_nov][y_nov] = board[x][y];
                board[x][y] = 0;
                pr = 1;
            }

            //вправо вниз
            if ((y_nov - y == 2) && (x_nov - x == 1)) {
                board[x_nov][y_nov] = board[x][y];
                board[x][y] = 0;
                pr = 1;
            }

        }
    }

   
    if (board[x][y] == -2) {
        if ((board[x_nov][y_nov] >= 0) && (board[x_nov][y_nov] < 6)) {
            //вниз вправо
            if ((y_nov - y < 2) && (y_nov - y > 0) && (x_nov - x < 3) && (x_nov - x > 1)) {
                board[x_nov][y_nov] = board[x][y];
                board[x][y] = 0;
                pr_ch = 1;
            }

            // вниз влево
            if ((x_nov - x < 3) && (x_nov - x > 0) && (y_nov - y > -2) && (y_nov - y <= -1)) {
                board[x_nov][y_nov] = board[x][y];
                board[x][y] = 0;
                pr_ch = 1;
            }


            //влево вниз
            if ((x - x_nov == -1) && (y - y_nov == 2)) {
                board[x_nov][y_nov] = board[x][y];
                board[x][y] = 0;
                pr_ch = 1;
            }


            //влево вверх
            if ((x - x_nov == 1) && (y - y_nov == 2)) {
                board[x_nov][y_nov] = board[x][y];
                board[x][y] = 0;
                pr_ch = 1;
            }



            //вправо вниз
            if ((y_nov - y == 2) && (x_nov - x == 1)) {
                board[x_nov][y_nov] = board[x][y];
                board[x][y] = 0;
                pr_ch = 1;
            }


            //вправо вверх
            if ((y_nov - y == 2) && (x - x_nov == 1)) {
                board[x_nov][y_nov] = board[x][y];
                board[x][y] = 0;
                pr_ch = 1;
            }


            if (y_nov - y < 0) {
                //вверх влево
                //cout << "-0-0-0-0-";
                if ((x_nov - x > -3) && (x_nov - x < 0) && (y_nov - y < 2) && (y_nov - y >= -1)) {
                    //cout << x_nov << " " << x << endl;
                    //cout << y_nov << " " << y << endl;
                    board[x_nov][y_nov] = board[x][y];
                    board[x][y] = 0;
                    pr_ch = 1;
                }
            }


            //вверх вправо
            if (y_nov - y > 0) {
                //cout << "!!!@@@";
                if ((y_nov - y < 2) && (y_nov - y > 0) && (x_nov - x > -3) && (x_nov - x < 0)) {
                    board[x_nov][y_nov] = board[x][y];
                    board[x][y] = 0;
                    pr_ch = 1;
                }
            }
        }
    }
}

void slon(){
    if (board[x][y] == 3) {
        //диагональ влево вверх
        if ((x_nov < x) && (y_nov < y)) {
            i = x - 1;
            j = y - 1;

            for (i = x; i > -1; i--) {
                if (j > -1) {
                    if (board[i][j] != 0) {
                        x_1_ogr = i;
                        y_1_ogr = j + 1;
                        pr = 1;
                        break;
                    }
                }
                j--;
            }
            cout << x_1_ogr << "  " << y_1_ogr;
            if ((x_nov > x_1_ogr) && (y_nov > y_1_ogr) && (board[x_nov][y_nov] == 0)) {
                board[x_nov][y_nov] = board[x][y];
                pr = 1;
                board[x][y] = 0;
            }

        }

        //диагональ вправо вниз
        if ((x < x_nov) && (y < y_nov)) {
            i = x;
            j = y + 1;
            for (i = x + 1; i < 9; i++) {
                if (j < 9) {
                    if (board[i][j - 1] != 0) {
                        x_4_ogr = i;
                        pr = 1;
                        y_4_ogr = j - 1;
                        break;
                    }
                }
                j++;
            }

            if ((x_nov < x_4_ogr) && (y_nov <= y_4_ogr)) {
                pr = 1;
                board[x_nov][y_nov] = board[x][y];
                board[x][y] = 0;
            }

        }

        //диагональ влево вниз
        if ((x < x_nov) && (y > y_nov)) {
            i = x + 1;
            j = 0;
            for (i = x + 1; i < 9; i++) {
                if (j > -1) {
                    if (board[i][y - j] != 0) {
                        x_3_ogr = i;
                        pr = 1;
                        y_3_ogr = y - j;
                        break;
                    }
                }
                j++;
            }
            y_3_ogr = y_3_ogr - 1;
            //cout << x_3_ogr << "  " << y_3_ogr;

            if ((x_nov < x_3_ogr) && (y_nov > y_3_ogr)) {
                pr = 1;
                board[x_nov][y_nov] = board[x][y];
                board[x][y] = 0;
            }

        }

        //диагональ вправо вверх
        if ((x_nov < x) && (y < y_nov)) {
            i = x;
            j = y;
            for (i = x - 1; i > -1; i--) {
                if (j < 8) {
                    if (board[i][j] != 0) {
                        x_2_ogr = i;
                        pr = 1;
                        y_2_ogr = j;
                        break;
                    }
                }
                j++;
            }
            y_2_ogr = y_2_ogr + 1;
            //cout << x_2_ogr << "  " << y_2_ogr;
            if ((x > x_2_ogr) && (y < y_2_ogr)) {
                board[x_nov][y_nov] = board[x][y];
                pr = 1;
                board[x][y] = 0;
            }
        }
    }

    //„≈–Ќџ… —ЋќЌ
    if (board[x][y] == -3) {
        //диагональ влево вверх
        if ((x_nov < x) && (y_nov < y)) {
            i = x;
            j = y + 1;

            for (i = x - 1; i > -1; i--) {
                if (j > -1) {

                    if (board[i][j - 1] != 0) {
                        x_1_ogr = i;
                        pr_ch = 1;
                        y_1_ogr = j - 1;
                        break;
                    }
                }
                j--;
            }
            //cout << x_1_ogr << "  " << y_1_ogr;
            if ((x_nov > x_1_ogr) && (y_nov > y_1_ogr)) {
                board[x_nov][y_nov] = board[x][y];
                pr_ch = 1;
                board[x][y] = 0;
            }

        }

        //диагональ вправо вниз
        if ((x < x_nov) && (y < y_nov)) {
            i = x;
            j = y + 1;
            for (i = x + 1; i < 9; i++) {
                if (j < 9) {
                    if (board[i][j - 1] != 0) {
                        x_4_ogr = i;
                        pr_ch = 1;
                        y_4_ogr = j - 1;
                        break;
                    }
                }
                j++;
            }
            //cout << x_4_ogr << "  " << y_4_ogr;

            if ((x_nov < x_4_ogr) && (y_nov <= y_4_ogr)) {
                board[x_nov][y_nov] = board[x][y];
                pr_ch = 1;
                board[x][y] = 0;
            }

        }

        //диагональ влево вниз
        if ((x < x_nov) && (y > y_nov)) {
            i = x + 1;
            j = 0;
            for (i = x + 1; i < 9; i++) {
                if (j > -1) {
                    if (board[i][y - j] != 0) {
                        x_3_ogr = i;
                        pr_ch = 1;
                        y_3_ogr = y - j;
                        break;
                    }
                }
                j++;
            }
            y_3_ogr = y_3_ogr - 1;
            //cout << x_3_ogr << "  " << y_3_ogr;

            if ((x_nov < x_3_ogr) && (y_nov > y_3_ogr)) {
                board[x_nov][y_nov] = board[x][y];
                pr_ch = 1;
                board[x][y] = 0;
            }

        }

        //диагональ вправо вверх
        if ((x_nov < x) && (y < y_nov)) {
            i = x;
            j = y;
            for (i = x - 1; i > -1; i--) {
                if (j < 9) {
                    if (board[i][j] != 0) {
                        x_2_ogr = i;
                        pr_ch = 1;
                        y_2_ogr = j;
                        break;
                    }
                }
                j++;
            }
            y_2_ogr = y_2_ogr + 1;
            //cout << x_2_ogr << "  " << y_2_ogr;
            if ((x > x_2_ogr) && (y < y_2_ogr)) {
                board[x_nov][y_nov] = board[x][y];
                pr_ch = 1;
                board[x][y] = 0;
            }
        }
    }
}

void ferz(){
    if (board[x][y] == 5) {
        //диагональ влево вверх
        if ((x_nov < x) && (y_nov < y)) {
            i = x;
            j = y + 1;
            for (i = x - 1; i > -1; i--) {
                if (j > -1) {

                    if (board[i][j - 1] != 0) {
                        x_1_ogr = i;
                        pr = 1;
                        y_1_ogr = j - 1;
                        break;
                    }
                }
                j--;
            }
            if ((x_nov > x_1_ogr) && (y_nov > y_1_ogr)) {
                pr = 1;
                board[x_nov][y_nov] = board[x][y];
                board[x][y] = 0;
            }

        }
        //диагональ вправо вниз
        if ((x < x_nov) && (y < y_nov)) {
            i = x;
            j = y + 1;
            for (i = x + 1; i < 9; i++) {
                if (j < 9) {
                    if (board[i][j - 1] != 0) {
                        pr = 1;
                        x_4_ogr = i;
                        y_4_ogr = j - 1;
                        break;
                    }
                }
                j++;
            }

            if ((x_nov < x_4_ogr) && (y_nov <= y_4_ogr)) {
                board[x_nov][y_nov] = board[x][y];
                pr = 1;
                board[x][y] = 0;
            }

        }

        //диагональ влево вниз
        if ((x < x_nov) && (y > y_nov)) {
            i = x + 1;
            j = 0;
            for (i = x + 1; i < 9; i++) {
                if (j > -1) {
                    if (board[i][y - j] != 0) {
                        x_3_ogr = i;
                        pr = 1;
                        y_3_ogr = y - j;
                        break;
                    }
                }
                j++;
            }
            y_3_ogr = y_3_ogr - 1;
            //cout << x_3_ogr << "  " << y_3_ogr;

            if ((x_nov < x_3_ogr) && (y_nov > y_3_ogr)) {
                board[x_nov][y_nov] = board[x][y];
                pr = 1;
                board[x][y] = 0;
            }

        }

        //диагональ вправо вверх
        if ((x_nov < x) && (y < y_nov)) {
            i = x;
            j = y;
            for (i = x - 1; i > -1; i--) {
                if (j < 9) {
                    if (board[i][j] != 0) {
                        x_2_ogr = i;
                        pr = 1;
                        y_2_ogr = j;
                        break;
                    }
                }
                j++;
            }
            y_2_ogr = y_2_ogr + 1;
            //cout << x_2_ogr << "  " << y_2_ogr;
            if ((x > x_2_ogr) && (y < y_2_ogr)) {
                board[x_nov][y_nov] = board[x][y];
                pr = 1;
                board[x][y] = 0;
            }
        }

        //снизу вверх
        if ((y_nov == y) && (x > x_nov)) {
            for (i = x - 1; i > -1; i--) {
                if (board[i][y] != 0) {
                    x_ogr = i;
                    pr = 1;
                    y_ogr = y;
                    break;
                }
            }
        }

        if (((x_nov > x_ogr) && (y_nov == y)) || ((x_nov == x_ogr) && (y_nov == y_ogr) && (board[x_nov][y_nov] > 6) && (board[x_nov][y_nov] <= 0))) {
            board[x_nov][y_nov] = board[x][y];
            pr = 1;
            board[x][y] = 0;
        }

        //ограничение по вертикали дл€ черной ладьи сверху вниз
        if ((y_nov == y) && (x < x_nov)) {
            for (i = x + 1; i < 7; i++) {
                if (board[i][y] != 0) {
                    x_ogr = i;
                    pr = 1;
                    y_ogr = y;
                    break;
                }
            }
            //cout << x_ogr << " - - - - -" << y_ogr;
        }

        if (((x_nov < x_ogr) && (y_nov == y)) || ((x_nov == x_ogr) && (y_nov == y_ogr) && (board[x_nov][y_nov] > -6) && (board[x_nov][y_nov] <= 0))) {
            board[x_nov][y_nov] = board[x][y];
            pr = 1;
            board[x][y] = 0;
        }


        if (x == x_nov) {
            //ограничение по горизонтали дл€ белой ладьи справа налево
            if ((x_nov == x) && (y > y_nov)) {
                for (i = y - 1; i > -1; i--) {
                    if (board[x][i] != 0) {
                        x_ogr_goriz = x;
                        pr = 1;
                        y_ogr_goriz = i;
                        break;
                    }
                    else {
                        x_ogr_goriz = x;
                        pr = 1;
                        y_ogr_goriz = 0;
                    }
                }
                //cout << x_ogr_goriz << "--" << y_ogr_goriz;
            }

            if (((y_nov > y_ogr_goriz) && (x_nov >= x_ogr_goriz)) || (((x_nov == x_ogr_goriz) || (x_nov > x_ogr_goriz)) && (y_nov == y) && ((board[x_nov][y_nov] > -6) && (board[x_nov][y_nov] <= 0)))) {
                board[x_nov][y_nov] = board[x][y];
                pr = 1;
                board[x][y] = 0;
            }



            //ограничение по горизонтали дл€ белой ладьи слева направо
            if ((x_nov == x) && (y < y_nov)) {
                for (i = y + 1; i > -1; i--) {
                    if (board[x][i] != 0) {
                        x_ogr_goriz = x;
                        pr = 1;
                        y_ogr_goriz = i;
                        break;
                    }
                    else {
                        x_ogr_goriz = x;
                        pr = 1;
                        y_ogr_goriz = 0;
                    }
                }
            }

            if (((y_nov < y_ogr_goriz) && (x_nov == x_ogr_goriz)) || ((x_nov < x_ogr_goriz) && (y_nov == y) && ((board[x_nov][y_nov] > -6) && (board[x_nov][y_nov] < 0)))) {
                board[x_nov][y_nov] = board[x][y];
                pr = 1;
                board[x][y] = 0;
            }
        }
    }



    // „≈–Ќџ… ‘≈–«№
    if (board[x][y] == -5) {
        //диагональ влево вверх
        if ((x_nov < x) && (y_nov < y)) {
            i = x;
            j = y + 1;

            for (i = x - 1; i > -1; i--) {
                if (j > -1) {

                    if (board[i][j - 1] != 0) {
                        x_1_ogr = i;
                        pr_ch = 1;
                        y_1_ogr = j - 1;
                        break;
                    }
                }
                j--;
            }
            //cout << x_1_ogr << "  " << y_1_ogr;
            if ((x_nov > x_1_ogr) && (y_nov > y_1_ogr)) {
                board[x_nov][y_nov] = board[x][y];
                pr_ch = 1;
                board[x][y] = 0;
            }

        }

        //диагональ вправо вниз
        if ((x < x_nov) && (y < y_nov)) {
            i = x;
            j = y + 1;
            for (i = x + 1; i < 9; i++) {
                if (j < 9) {
                    if (board[i][j - 1] != 0) {
                        x_4_ogr = i;
                        pr_ch = 1;
                        y_4_ogr = j - 1;
                        break;
                    }
                }
                j++;
            }
            //cout << x_4_ogr << "  " << y_4_ogr;

            if ((x_nov < x_4_ogr) && (y_nov <= y_4_ogr)) {
                board[x_nov][y_nov] = board[x][y];
                pr_ch = 1;
                board[x][y] = 0;
            }

        }

        //диагональ влево вниз
        if ((x < x_nov) && (y > y_nov)) {
            i = x + 1;
            j = 0;
            for (i = x + 1; i < 9; i++) {
                if (j > -1) {
                    if (board[i][y - j] != 0) {
                        x_3_ogr = i;
                        pr_ch = 1;
                        y_3_ogr = y - j;
                        break;
                    }
                }
                j++;
            }
            y_3_ogr = y_3_ogr - 1;
            //cout << x_3_ogr << "  " << y_3_ogr;

            if ((x_nov < x_3_ogr) && (y_nov > y_3_ogr)) {
                board[x_nov][y_nov] = board[x][y];
                pr_ch = 1;
                board[x][y] = 0;
            }

        }

        //диагональ вправо вверх
        if ((x_nov < x) && (y < y_nov)) {
            i = x;
            j = y;
            for (i = x - 1; i > -1; i--) {
                if (j < 9) {
                    if (board[i][j] != 0) {
                        x_2_ogr = i;
                        pr_ch = 1;
                        y_2_ogr = j;
                        break;
                    }
                }
                j++;
            }
            y_2_ogr = y_2_ogr + 1;
            //cout << x_2_ogr << "  " << y_2_ogr;
            if ((x > x_2_ogr) && (y < y_2_ogr)) {
                pr_ch = 1;
                board[x_nov][y_nov] = board[x][y];
                board[x][y] = 0;
            }
        }

        //ограничение по вертикали дл€ черной ладьи сверху вниз
        if ((y_nov == y) && (x < x_nov)) {
            for (i = x + 1; i < 7; i++) {
                if (board[i][y] != 0) {
                    x_ogr = i;
                    pr_ch = 1;
                    y_ogr = y;
                    break;
                }
            }
            //cout << x_ogr << " - - - - -" << y_ogr;


            if ((((x_nov < x_ogr) && (y_nov == y)) && (x_nov > x)) || ((y_nov == y_ogr) && (board[x_nov][y_nov] < 6) && (board[x_nov][y_nov] > 0))) {
                //cout << "1";
                board[x_nov][y_nov] = board[x][y];
                pr_ch = 1;
                board[x][y] = 0;
            }
        }

        //снизу вверх
        if ((y_nov == y) && (x > x_nov)) {
            for (i = x - 1; i > -1; i--) {
                if (board[i][y] != 0) {
                    x_ogr = i;
                    pr_ch = 1;
                    y_ogr = y;
                    break;
                }
            }
            //cout << x_ogr << " - - - - -" << y_ogr;


            if (((x_nov > x_ogr) && (y_nov == y)) || ((x_nov == x_ogr) && (y_nov == y_ogr) && (board[x_nov][y_nov] < 6) && (board[x_nov][y_nov] >= 0))) {
                //cout << "2";
                board[x_nov][y_nov] = board[x][y];
                pr_ch = 1;
                board[x][y] = 0;
            }
        }

        //ограничение по горизонтали дл€ черной слева направо
        if ((x_nov == x) && (y < y_nov)) {
            for (i = y + 1; i < 7; i++) {
                if (board[x][i] != 0) {
                    x_ogr_goriz = x;
                    y_ogr_goriz = i;
                    pr_ch = 1;
                    break;
                }
                else {
                    x_ogr_goriz = x;
                    pr_ch = 1;
                    y_ogr_goriz = 0;
                }
            }
            //cout << x_ogr_goriz << "----" << y_ogr_goriz;
        }

        if ((((y_nov < y_ogr_goriz) || (y_ogr_goriz == 0)) && (x_nov == x_ogr_goriz)) || ((x_nov < x_ogr_goriz) && (y_nov == y) && ((board[x_nov][y_nov] < 6) && (board[x_nov][y_nov] > 0)))) {
            //cout << "3";
            board[x_nov][y_nov] = board[x][y];
            pr_ch = 1;
            board[x][y] = 0;
        }



        //ограничение по горизонтали дл€ черной ладьи справа налево
        if ((x_nov == x) && (y > y_nov)) {
            for (i = y + 1; i < 7; i++) {
                if (board[x][i] != 0) {
                    x_ogr_goriz = x;
                    pr_ch = 1;
                    y_ogr_goriz = i;
                    break;
                }
                else {
                    x_ogr_goriz = x;
                    pr_ch = 1;
                    y_ogr_goriz = 0;
                }
            }
            //cout << x_ogr_goriz << "--" << y_ogr_goriz;

            if ((((y_nov <= y_ogr_goriz) || (y_nov > y_ogr_goriz)) && (x_nov == x_ogr_goriz)) || ((x_nov == x_ogr_goriz) && (y_nov == y) && ((board[x_nov][y_nov] < 6) && (board[x_nov][y_nov] > 0)))) {
                //cout << "4";
                board[x_nov][y_nov] = board[x][y];
                pr_ch = 1;
                board[x][y] = 0;
            }
        }

    }

}

void king(){
    if (board[x][y] == 6) {
        //сверху вниз
        if (((x_nov == x) || (x_nov - x == 1) || (x - x_nov == 1)) && ((y == y_nov) || (y - y_nov == 1) || (y_nov - y == 1))) {
            board[x_nov][y_nov] = board[x][y];
            board[x][y] = 0;
            pr = 1;
        }
    }

    //„≈–Ќџ…  ќ–ќЋ№
    if (board[x][y] == -6) {
        //сверху вниз
        if (((x_nov == x) || (x_nov - x == 1) || (x - x_nov == 1)) && ((y == y_nov) || (y - y_nov == 1) || (y_nov - y == 1))) {
            board[x_nov][y_nov] = board[x][y];
            board[x][y] = 0;
            pr_ch = 1;
        }
    }
}

void rasstanovka(){
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            board[i][j] = 0;
        }
    }
    for (j = 0; j < 8; j++) {
        board[1][j] = -1;
        board[6][j] = 1;

    }
    //черные
    board[0][0] = -4;
    board[0][1] = -2;
    board[0][2] = -3;
    board[0][3] = -5;
    board[0][4] = -6;
    board[0][5] = -3;
    board[0][6] = -2;
    board[0][7] = -4;

    //белые
    board[7][0] = 4;
    board[7][1] = 2;
    board[7][2] = 3;
    board[7][3] = 5;
    board[7][4] = 6;
    board[7][5] = 3;
    board[7][6] = 2;
    board[7][7] = 4;
}

void opredelenie_koord(){
    if (buk == 'A') { y = 0; }
    if (buk == 'B') { y = 1; }
    if (buk == 'C') { y = 2; }
    if (buk == 'D') { y = 3; }
    if (buk == 'E') { y = 4; }
    if (buk == 'F') { y = 5; }
    if (buk == 'G') { y = 6; }
    if (buk == 'H') { y = 7; }
    
    if (buk == 'a') { y = 0; }
    if (buk == 'b') { y = 1; }
    if (buk == 'c') { y = 2; }
    if (buk == 'd') { y = 3; }
    if (buk == 'e') { y = 4; }
    if (buk == 'f') { y = 5; }
    if (buk == 'g') { y = 6; }
    if (buk == 'h') { y = 7; }
    if (tsifr == '1') { x = 0; }
    if (tsifr == '2') { x = 1; }
    if (tsifr == '3') { x = 2; }
    if (tsifr == '4') { x = 3; }
    if (tsifr == '5') { x = 4; }
    if (tsifr == '6') { x = 5; }
    if (tsifr == '7') { x = 6; }
    if (tsifr == '8') { x = 7; }
}


void opredelenie_koord_nov(){
    if (buk == 'A') { y_nov = 0; }
    if (buk == 'B') { y_nov = 1; }
    if (buk == 'C') { y_nov = 2; }
    if (buk == 'D') { y_nov = 3; }
    if (buk == 'E') { y_nov = 4; }
    if (buk == 'F') { y_nov = 5; }
    if (buk == 'G') { y_nov = 6; }
    if (buk == 'H') { y_nov = 7; }
    
    if (buk == 'a') { y_nov = 0; }
    if (buk == 'b') { y_nov = 1; }
    if (buk == 'c') { y_nov = 2; }
    if (buk == 'd') { y_nov = 3; }
    if (buk == 'e') { y_nov = 4; }
    if (buk == 'f') { y_nov = 5; }
    if (buk == 'g') { y_nov = 6; }
    if (buk == 'h') { y_nov = 7; }
    if (tsifr == '1') { x_nov = 0; }
    if (tsifr == '2') { x_nov = 1; }
    if (tsifr == '3') { x_nov = 2; }
    if (tsifr == '4') { x_nov = 3; }
    if (tsifr == '5') { x_nov = 4; }
    if (tsifr == '6') { x_nov = 5; }
    if (tsifr == '7') { x_nov = 6; }
    if (tsifr == '8') { x_nov = 7; }
}


void iis_1(){
    for (i=0; i<8; i++){
        for (j=0; j<8; j++){
            if (board[i][j]==-1){
                if ((i==1) && ((j<2) || (j>5))){
                    if ((board[i+3][j+1]==0) && (board[i+3][j-1]==0)){
                        vuborka[k_vub][0]=i;
                        vuborka[k_vub][1]=j;
                        vuborka[k_vub][2]=1;
                        k_vub++;
                    }
                }
                
                if ((i==1) && ((j>2) || (j<5))) {
                    if ((board[i+3][j+1]==0) && (board[i+3][j-1]==0)){
                        vuborka[k_vub][0]=i;
                        vuborka[k_vub][1]=j;
                        vuborka[k_vub][2]=3;
                        k_vub++;
                    }
                }
                 
                if ((i!=1) && ((j>2) || (j<5))) {
                    if ((board[i+2][j+1]==0) && (board[i+2][j-1]==0)){
                        vuborka[k_vub][0]=i;
                        vuborka[k_vub][1]=j;
                        vuborka[k_vub][2]=1;
                        k_vub++;
                    }
                }
                
                if (i!=1) {
                    if ((board[i+2][j+1]==1) && (board[i+2][j-1]==1)){
                        vuborka[k_vub][0]=i;
                        vuborka[k_vub][1]=j;
                        vuborka[k_vub][2]=5;
                        k_vub++;
                    }
                }
                
                
                if (i!=1) {
                    if ((board[i+2][j+1]!=0) && (board[i+2][j-1]!=0)){
                        vuborka[k_vub][0]=i;
                        vuborka[k_vub][1]=j;
                        vuborka[k_vub][2]=0;
                        k_vub++;
                    }
                }
            }
        }
    }

    
}
    
    
            
    
    
int main() {
//    int schet_bel;
    
    //SetConsoleOutputCP(1251); //объ€вление русского €зыка
    //HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //SetConsoleTextAttribute(hConsole, 6);
    
    cout << "Вас приветствует программа шахматы Броцкого Кирилла Александровича, студента ИУ8-32" << endl;
    cout << "В программе присутствует 2 режима игры и инерфейса: \n  Режим: 1 - числовой, 2 - буквенный (цветной), 3 - фигурами" << endl<< "  Выбор противника: 1 - против человека, 2 - против ИИ";
    cout << endl << endl;
   
    vuvod();
    cout << "Введите режим: ";
    cin >> vubor;
    cout << "Введите противника (1/2): ";
    cin >> vubor_sis;
    cout << endl;
    rasstanovka();
    klych = 1;
    vuvod();
   

   // SetConsoleTextAttribute(hConsole, 15);
    if (vubor_sis==1){
    while (klych == 1) {
       
        string str;
     //   SetConsoleTextAttribute(hConsole, 7);
        cout << endl << "Выберите фигуру: ";
        cin >> str;
        x=5;
        y=5;
         while (prov==0){
             if (hod==0){
             if (schet>0){
                 cout<<"Вы ввели неверную координату! Сейчас ходят белые фигуры!"<<endl<<"Введите координаты заново: ";
                 
        cin >> str;
             }
             schet++;
        buk = str[0];
        tsifr = str[1];
        
        //cout << buk << "|" << tsifr;
        if (buk == 'A') { y = 0; }
        if (buk == 'B') { y = 1; }
        if (buk == 'C') { y = 2; }
        if (buk == 'D') { y = 3; }
        if (buk == 'E') { y = 4; }
        if (buk == 'F') { y = 5; }
        if (buk == 'G') { y = 6; }
        if (buk == 'H') { y = 7; }
        
        if (buk == 'a') { y = 0; }
        if (buk == 'b') { y = 1; }
        if (buk == 'c') { y = 2; }
        if (buk == 'd') { y = 3; }
        if (buk == 'e') { y = 4; }
        if (buk == 'f') { y = 5; }
        if (buk == 'g') { y = 6; }
        if (buk == 'h') { y = 7; }
        if (tsifr == '1') { x = 0; }
        if (tsifr == '2') { x = 1; }
        if (tsifr == '3') { x = 2; }
        if (tsifr == '4') { x = 3; }
        if (tsifr == '5') { x = 4; }
        if (tsifr == '6') { x = 5; }
        if (tsifr == '7') { x = 6; }
        if (tsifr == '8') { x = 7; }

             if ((board[x][y]>0) && (board[x][y]!=0)){
                 prov=1;
                 hod=1;
             }
                 
             }
             
             if (hod==1){
                  if (schet2>0){
                      cout<<"Вы ввели неверную координату! Сейчас ходят черные фигуры!"<<endl<<"Введите координаты заново: ";
                      
             cin >> str;
                  }
                  schet2++;
             buk = str[0];
             tsifr = str[1];
             
             //cout << buk << "|" << tsifr;
             if (buk == 'A') { y = 0; }
             if (buk == 'B') { y = 1; }
             if (buk == 'C') { y = 2; }
             if (buk == 'D') { y = 3; }
             if (buk == 'E') { y = 4; }
             if (buk == 'F') { y = 5; }
             if (buk == 'G') { y = 6; }
             if (buk == 'H') { y = 7; }
             
             if (buk == 'a') { y = 0; }
             if (buk == 'b') { y = 1; }
             if (buk == 'c') { y = 2; }
             if (buk == 'd') { y = 3; }
             if (buk == 'e') { y = 4; }
             if (buk == 'f') { y = 5; }
             if (buk == 'g') { y = 6; }
             if (buk == 'h') { y = 7; }
             if (tsifr == '1') { x = 0; }
             if (tsifr == '2') { x = 1; }
             if (tsifr == '3') { x = 2; }
             if (tsifr == '4') { x = 3; }
             if (tsifr == '5') { x = 4; }
             if (tsifr == '6') { x = 5; }
             if (tsifr == '7') { x = 6; }
             if (tsifr == '8') { x = 7; }

                  if ((board[x][y]<0) && (board[x][y]!=0)){
                      prov=1;
                      hod=0;
                  }
                      
                  }
        }
        schet=0; schet2=0;
        prov=0;
        cout << "Введите новые координаты: ";
        cin >> str;
        buk = str[0];
        tsifr = str[1];
        opredelenie_koord_nov();
        cout << endl;
     

        //пешка
        if ((board[x][y] == 1) || (board[x][y] == -1)) {
            peshka();
        }
        
        // конь
        if ((board[x][y] == 2) || (board[x][y] == -2)) {
            hourse();
        }
        
        //слон
        if ((board[x][y] == 3) || (board[x][y] == -3)){
            slon();
        }
        
        // ладья
        if ((board[x][y] == 4) || (board[x][y] == -4)) {
            ladya();
        }
                
        //ферзь
        if ((board[x][y] == 5) || (board[x][y] == -5)){
            ferz();
        }

        //король
        if ((board[x][y] == 5) || (board[x][y] == -5)){
            king();
        }


      
        

        //======================================================================

     
        

        

        
        /*
        if ((board[x_nov][y_nov] < 0) && (board[x][y] > 0)) {
            schet_bel++;
            
        }

        if ((board[x][y] < 0) && (board[x_nov][y_nov] > 0)) {
            cout << "zas";
            schet_cher = schet_cher + 1;;
         }
        cout << board[x][y] << " - " << board[x_nov][y_nov] << endl;
        cout << x << "++++" << y;
        pr = 0;
        pr_ch = 0;
        cout << "!!!!!!!!!!!!!!!";
        cout << schet_bel<<" "<<schet_cher; */
        vuvod();

    }
    }
    
    if (vubor_sis==2){
    while (klych == 1) {
       
        string str;
     //   SetConsoleTextAttribute(hConsole, 7);
        cout << endl << "Выберите фигуру: ";
        
       
        
        prov=0;
        while (prov==0){
        buk = str[0];
        tsifr = str[1];
        
        
             
             cin >> str;
             schet2++;
             buk = str[0];
             tsifr = str[1];
             
             //cout << buk << "|" << tsifr;
                 opredelenie_koord();
            
                  if ((board[x][y]>0) && (board[x][y]!=0)){
                      prov=1;
                      cout<<x<<y;
                  }
                      
                  
        }
        schet=0; schet2=0;
        prov=0;
        cout << "Введите новые координаты: ";
        cin >> str;
        buk = str[0];
        tsifr = str[1];
        opredelenie_koord_nov();
        cout << endl;
     

        //пешка
        if (board[x][y] == 1) {
            peshka();
        }
        
        // конь
        if (board[x][y] == 2) {
            hourse();
        }
        
        //слон
        if (board[x][y] == 3){
            slon();
        }
        
        // ладья
        if (board[x][y] == 4) {
            ladya();
        }
                
        //ферзь
        if (board[x][y] == 5){
            ferz();
        }

        //король
        if (board[x][y] == 6){
            king();
        }


      
        

        //======================================================================

     
        

        

        
        /*
        if ((board[x_nov][y_nov] < 0) && (board[x][y] > 0)) {
            schet_bel++;
            
        }

        if ((board[x][y] < 0) && (board[x_nov][y_nov] > 0)) {
            cout << "zas";
            schet_cher = schet_cher + 1;;
         }
        cout << board[x][y] << " - " << board[x_nov][y_nov] << endl;
        cout << x << "++++" << y;
        pr = 0;
        pr_ch = 0;
        cout << "!!!!!!!!!!!!!!!";
        cout << schet_bel<<" "<<schet_cher; */
        vuvod();

    }
    }
    
   
    
    
}
