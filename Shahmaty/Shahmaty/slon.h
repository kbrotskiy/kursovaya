//
//  slon.h
//  Shahmaty
//
//  Created by Кирилл Броцкий on 25.12.2020.
//  Copyright © 2020 Кирилл Броцкий. All rights reserved.
//

#ifndef slon_h
#define slon_h
#include "Header.h"
#include "peshka.h"
#include "ladya.h"
#include "hourse.h"
#include "ferz.h"
#include "king.h"
#include "otvet.h"

int board[8][8], vuborka[64][3], k_vub, i, j, x, y, vubor_sis, x_nov, y_nov, izmen_figura_cher, izmen_figura_bel, x_ogr, y_ogr, klych, x_ogr_goriz, y_ogr_goriz, count_left=0, count_center=0, count_right=0, vub_otveta=0;
int ogr_ferz_goriz, ogr_ferz_vertikal, vubor, prov_hod=0;
int schet_bel = 0;
int sch=0;
int schet_cher = 0;
int prov=0, schet=0, schet2=0, hod=0;
int pr = 0;//проверка для счета для белых
int pr_ch = 0;//проверка для счета для черных
int x_1_ogr, y_1_ogr, x_2_ogr, y_2_ogr, x_3_ogr, y_3_ogr, x_4_ogr, y_4_ogr; // ограничени€ дл€ диагоналей
int shax_and_mat=0;
int k=0;
std::string itog[8][8], bukv[8], nazvanie;
bool hod_p;
char buk, tsifr;
std::string pr_save, pr_unpack;

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
            std::cout << x_1_ogr << "  " << y_1_ogr;
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

void intel_slon(){
    int k=0;
    if (prov_hod==0){
    for (i=7; i>-1; i--){
        for (j=7; j>-1; j--){
            if (board[i][j]==-3){
                // диагонали
                for (k=i; k<8; k++){
                    if ((board[k][k+1]>0) && (prov_hod==0)){
                        if (board[k][k+1]>0){
                            schet_cher+=3;
                        }
                        board[k][k+1]=-3;
                        board[i][j]=0;
                        prov_hod=1;
                        break;
                    }
                }
                for (k=i; k>-1; k--){
                    if ((board[k][k-1]>0) && (prov_hod==0)){
                        if (board[k][k-1]>0){
                            schet_cher+=3;
                        }
                        board[k][k-1]=-3;
                        board[i][j]=0;
                        prov_hod=1;
                        break;
                    }
                }
                for (k=i; k>-1; k--){
                    if ((board[k][k+1]>0) && (prov_hod==0)){
                        if (board[k][k+1]>0){
                            schet_cher+=3;
                        }
                        board[k][k+1]=-3;
                        board[i][j]=0;
                        prov_hod=1;
                        break;
                    }
                }
                for (k=i; k<8; k++){
                    if ((board[k][k-1]>0) && (prov_hod==0)){
                        if (board[k][k-1]>0){
                            schet_cher+=3;
                        }
                        board[k][k-1]=-3;
                        board[i][j]=0;
                        prov_hod=1;
                        break;
                    }
                }
            }
        }
    }
    }
}

#endif /* slon_h */
