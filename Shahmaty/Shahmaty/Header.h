//
//  Header.h
//  Shahmaty
//
//  Created by Кирилл Броцкий on 25.12.2020.
//  Copyright © 2020 Кирилл Броцкий. All rights reserved.
//

#ifndef Header_h
#define Header_h
// 11.10.2020
//

#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <vector>
#include "peshka.h"
#include "ladya.h"
#include "hourse.h"
#include "ferz.h"
#include "king.h"
#include "slon.h"
#include "otvet.h"
//#include <Windows.h>



template <typename Stream>
bool read_num(Stream &stream, int &number) {
    char c = 0;
    std::string buf;
    while (true) {
        stream.read(&c, 1);
        if (c == ' ' || stream.eof()) {
            if (!buf.empty()) {
                number = atoi(buf.c_str());
                return true;
            }
        } else {
            buf +=c ;
        }
    }
    return false;
}

void unpacking(){
    std::ifstream digits;
    digits.open("/Users/kirillbrockij/"+nazvanie+".txt", std::ios_base::in);
    while (!digits.eof()) {
        int num;
        if (read_num(digits, num)){
            board[i][j]=num; // тут можно складывать в список
            if ((i<8) && (j<8)){
                if (j==7){
            i++;
                }
                
            j++;
                if (j==8){
                    j=0;
                    
                }
            }
        }
    }
}

void saving(){
    std::ofstream f;
    
    f.open("/Users/kirillbrockij/"+nazvanie+".txt", std::ios::out);
    for (i=0; i<8; i++) {
        for (j=0; j<8; j++) {
            f<<board[i][j]<<" ";
        }
        f<<"\n";
    }
    f.close();

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
    std::cout << std::endl;
    if (vubor == 1) {
        //SetConsoleTextAttribute(hConsol, 6);
        for (j = 0; j < 39; j++) {
            std::cout << "-";
        }
        std::cout<<std::endl;
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                std::cout << std::setw(2) << board[i][j] << " | ";
            }
            std::cout << "   " << i + 1;
            if (i == 4) {
            std::cout << "        Счет:  " << schet_bel << " : " << schet_cher;
        }
            std::cout << std::endl;
      for (j = 0; j < 39; j++) {
                std::cout << "-";
            }
            std::cout<<std::endl;
        }
        
        
        
        for (i = 0; i < 8; i++) {
            if (i==0){
                std::cout << " " << bukv[i] << "  ";
            }
            if (i==1){
                std::cout << "  " << bukv[i] << " ";
            }
            if (i==2){
                std::cout << "   " << bukv[i] << "   ";
            }
            if (i==3){
                std::cout << " " << bukv[i] << "  ";
            }
            if (i==4){
                std::cout << "  " << bukv[i] << " ";
            }
            if (i==5){
                std::cout << "   " << bukv[i] << "  ";
            }
            if (i==6){
                std::cout << "  " << bukv[i] << "  ";
            }
            if (i==7){
                std::cout << "  " << bukv[i] << "   ";
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
            std::cout << "-";
        }std::cout << std::endl;

        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                //вывод белых фигур
                if (itog[i][j] == "W "){
                    std::cout<<"\x1b[36m"<< std::setw(4) << itog[i][j] << "\x1b[0m"<< " |";
                }
                if ((itog[i][j] == "Pw") || (itog[i][j] == "Hw") || (itog[i][j] == "Sw") || (itog[i][j] == "Lw") || (itog[i][j] == "Fw") || (itog[i][j] == "Kw")) {
                    //SetConsoleTextAttribute(hConsol, 11);
                    std::cout<< "\x1b[33m"<< std::setw(4) << itog[i][j] << "\x1b[0m" <<  " |";
                    
                }

                //вывод черных фигур
                if (itog[i][j] == "B "){
                    std::cout<<"\x1b[31m"<< std::setw(4) << itog[i][j] << "\x1b[0m"<< " |";
                }
                if ((itog[i][j] == "Pb") || (itog[i][j] == "Hb") || (itog[i][j] == "Sb") || (itog[i][j] == "Lb") || (itog[i][j] == "Fb") || (itog[i][j] == "Kb")) {
                   // SetConsoleTextAttribute(hConsol, 12);
                    std::cout << "\x1b[34m"<<  std::setw(4) << itog[i][j] << "\x1b[0m" << " |";
                }

                
            }
           // SetConsoleTextAttribute(hConsol, 14);
            std::cout << "   " << i + 1;
            if (i==4){
                std::cout << "        Счет:  " << schet_bel << " : " << schet_cher;
            }
            std::cout << std::endl;
            
            for (j = 0; j < 48; j++) {
                std::cout << "-";
            }std::cout << std::endl;
        }
        
        for (i = 0; i < 8; i++) {
                   if (i==0){
                       std::cout << "  " << bukv[i] << "  ";
                   }
                   if (i==1){
                       std::cout << "   " << bukv[i] << " ";
                   }
                   if (i==2){
                       std::cout << "    " << bukv[i] << "   ";
                   }
                   if (i==3){
                       std::cout << "  " << bukv[i] << "  ";
                   }
                   if (i==4){
                       std::cout << "   " << bukv[i] << " ";
                   }
                   if (i==5){
                       std::cout << "    " << bukv[i] << "  ";
                   }
                   if (i==6){
                       std::cout << "   " << bukv[i] << "  ";
                   }
                   if (i==7){
                       std::cout << "   " << bukv[i] << "   ";
                   }
                   
               }

        std::cout << std::endl << std::endl;
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
            std::cout << "-";
        }std::cout << std::endl;

        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                //вывод белых фигур
                if ((itog[i][j] == "") || (itog[i][j] == "♙") || (itog[i][j] == "♘") || (itog[i][j] == "♗") || (itog[i][j] == "♖") || (itog[i][j] == "♕") || (itog[i][j] == "♔")) {
                    //SetConsoleTextAttribute(hConsol, 11);
                    if (itog[i][j]!=""){
                        std::cout << std::setw(5) << itog[i][j] << " |";
                    } else {
                        std::cout << std::setw(3) << itog[i][j] << " |";
                    }
                }

                //вывод черных фигур
                if ((itog[i][j] == "♟︎") || (itog[i][j] == "♞") || (itog[i][j] == "♝") || (itog[i][j] == "♜") || (itog[i][j] == "♛") || (itog[i][j] == "♚")) {
                   // SetConsoleTextAttribute(hConsol, 12);
                    if (itog[i][j]!=""){
                    std::cout << std::setw(2) <<""<< itog[i][j] << " |";
                    } else {
                        std::cout << std::setw(3) << itog[i][j] << " |";
                    }
                }

                
            }
           // SetConsoleTextAttribute(hConsol, 14);
            std::cout << "   " << i + 1;
            if (i==4){
                std::cout << "        Счет:  " << schet_bel << " : " << schet_cher;
            }
            std::cout << std::endl;
            
            for (j = 0; j < 40; j++) {
                std::cout << "-";
            }std::cout << std::endl;
        }
        
        for (i = 0; i < 8; i++) {
                   if (i==0){
                   std::cout << "  " << bukv[i] << " ";
                   }
                   if (i==1){
                       std::cout << "   " << bukv[i] << "";
                   }
                   if (i==2){
                       std::cout << "    " << bukv[i] << " ";
                   }
                   if (i==3){
                       std::cout << "   " << bukv[i] << "  ";
                   }
                   if (i==4){
                       std::cout << "  " << bukv[i] << " ";
                   }
                   if (i==5){
                       std::cout << "   " << bukv[i] << "  ";
                   }
                   if (i==6){
                       std::cout << "  " << bukv[i] << "  ";
                   }
                   if (i==7){
                       std::cout << "  " << bukv[i] << "   ";
                   }
                   
               }

        std::cout << std::endl << std::endl;
    }
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

    
void menu(){
    std::cout << "Вас приветствует программа шахматы Броцкого Кирилла Александровича, студента ИУ8-32" << std::endl;
    std::cout << std::endl << std::endl<<std::endl;
    srand(time(0));
    vub_otveta=random()%3;
    std:: cout<<vopros_partiya[vub_otveta]<<" (Y/N)"<<"    ";
    std::cin>>pr_unpack;
    if ((pr_unpack=="Y") || (pr_unpack=="y") || (pr_unpack=="Yes") || (pr_unpack=="YES")) {
        std::cout<<"Напомните мне название своей игры: ";
        std::cin>>nazvanie;
        std::ifstream digits;
        digits.open("/Users/kirillbrockij/"+nazvanie+".txt", std::ios_base::in);
        while (!digits.is_open()){
            vub_otveta=random()%6;
            std::cout<<not_open[vub_otveta];
            std::cout<<std::endl<<"Введите название игры: ";
            std::cin>>nazvanie;
            digits.open("/Users/kirillbrockij/"+nazvanie+".txt", std::ios_base::in);
        }
        unpacking();
    }
    srand(time(0));
    vub_otveta=random()%4;
    std:: cout<<vopros_soxr[vub_otveta]<<" (Y/N)"<<"    ";
    std::cin>>pr_save;
    if (((pr_save=="Y") || (pr_save=="y") || (pr_save=="Yes") || (pr_save=="YES")) && ((pr_unpack!="Y") && (pr_unpack!="y") && (pr_unpack!="Yes") && (pr_unpack!="YES"))) {
        std::cout<<"С удовольствием сохраню вашу игру!";
        std::cout<<std::endl<<"Введите название вашей игры: ";
        std::cin>>nazvanie;
    } else {
        if (((pr_unpack!="Y") && (pr_unpack!="y") && (pr_unpack!="Yes") && (pr_unpack!="YES")) || ((pr_save!="Y") && (pr_save!="y") && (pr_save!="Yes"))){
            vub_otveta=random()%4;
            std:: cout<<otvet_soxr[vub_otveta]<<"    ";
        }
    }
    std::cout << std::endl<< std::endl <<"В программе присутствует 3 режима игры и инерфейса: \n  Режим: 1 - числовой, 2 - буквенный (цветной), 3 - фигурами" << std::endl<< "  Выбор противника: 1 - против человека 🤓, 2 - против ИИ 🤖";
    std::cout << std::endl << std::endl<<std::endl;
    std::cout << std::endl<< "Введите режим: ";
    std::cin >> vubor;
    std::cout << "Введите противника (1/2): ";
    std::cin >> vubor_sis;
    std::cout << std::endl;
    if ((pr_unpack!="Y") && (pr_unpack!="y") && (pr_unpack!="Yes") && (pr_unpack!="YES")){
    rasstanovka();
    }
    klych = 1;
}
        
void start(){
    // SetConsoleTextAttribute(hConsole, 15);
    if (vubor_sis==1){
    while (klych == 1) {
        std::string str;
    //   SetConsoleTextAttribute(hConsole, 7);
        std::cout << std::endl << "Выберите фигуру: ";
        std::cin >> str;
        x=5;
        y=5;
         while (prov==0){
             if (hod==0){
             if (schet>0){
                 std::cout<<"Вы ввели неверную координату! Сейчас ходят белые фигуры!"<<std::endl<<"Введите координаты заново: ";
        std::cin >> str;
             }
             schet++;
        buk = str[0];
        tsifr = str[1];
        opredelenie_koord();
             if ((board[x][y]>0) && (board[x][y]!=0)){
                 prov=1;
                 hod=1;
             }
                 
             }
             if (hod==1){
                  if (schet2>0){
                      std::cout<<"Вы ввели неверную координату! Сейчас ходят черные фигуры!"<<std::endl<<"Введите координаты заново: ";
             std::cin >> str;
                  }
                  schet2++;
             buk = str[0];
             tsifr = str[1];
             opredelenie_koord();
                  if ((board[x][y]<0) && (board[x][y]!=0)){
                      prov=1;
                      hod=0;
                  }
                  }
        }
        schet=0; schet2=0;
        prov=0;
        std::cout << "Введите новые координаты: ";
        std::cin >> str;
        buk = str[0];
        tsifr = str[1];
        opredelenie_koord_nov();
        std::cout << std::endl;
     
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

     
        

        

        
    
        vuvod();

    }
    }
    
    if (vubor_sis==2){
    while (klych == 1) {
       
        std::string str;
     //   SetConsoleTextAttribute(hConsole, 7);
        std::cout << std::endl << "Выберите фигуру: ";
        
       
        
        prov=0;
        while (prov==0){
        buk = str[0];
        tsifr = str[1];
        
        
             
             std::cin >> str;
             schet2++;
             buk = str[0];
             tsifr = str[1];
             
             //cout << buk << "|" << tsifr;
                 opredelenie_koord();
            
                  if ((board[x][y]>0) && (board[x][y]!=0)){
                      prov=1;
                      std::cout<<x<<y;
                  }
                      
                  
        }
        schet=0; schet2=0;
        prov=0;
        std::cout << "Введите новые координаты: ";
        std::cin >> str;
        buk = str[0];
        tsifr = str[1];
        opredelenie_koord_nov();
        std::cout << std::endl;
     

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
        //int vub;
        
        
        
        while (prov_hod==0){
            intel_peshka();
            intel_hourse();
            intel_slon();
            intel_ladya();
            intel_ferz();
            intel_king();
        }
        prov_hod=0;
        saving();
        vuvod();
    }
    }
}


#endif /* Header_h */
