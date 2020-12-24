//
//  ferz.h
//  Shahmaty
//
//  Created by Кирилл Броцкий on 25.12.2020.
//  Copyright © 2020 Кирилл Броцкий. All rights reserved.
//

#ifndef ferz_h
#define ferz_h
#include "Header.h"
#include "peshka.h"
#include "ladya.h"
#include "hourse.h"
#include "ferz.h"
#include "king.h"
#include "slon.h"
#include "otvet.h"

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

void intel_ferz(){
    int k=0;
    if (prov_hod==0){
    for (i=7; i>-1; i--){
        for (j=7; j>-1; j--){
            if (board[i][j]==-5){
                for (k=j; k<8; k++){
                    if ((board[i][k]>0) && (prov_hod==0)) {
                        if (board[i][k]>0){
                            schet_cher+=5;
                        }
                        board[i][k]=-5;
                        board[i][j]=0;
                        prov_hod=1;
                        break;
                    }
                }
                for (k=8; k>j; k--){
                    if ((board[i][k]>0) && (prov_hod==0)) {
                        if (board[i][k]>0){
                            schet_cher+=5;
                        }
                        board[i][k]=-5;
                        board[i][j]=0;
                        prov_hod=1;
                        break;
                    }
                }
                for (k=i; k<8; k++){
                    if ((board[k][j]>0) && (prov_hod==0)){
                        if (board[k][j]>0){
                            schet_cher+=5;
                        }
                        board[k][j]=-5;
                        board[i][j]=0;
                        prov_hod=1;
                        break;
                    }
                }
                for (k=8; k>i; k--){
                    if ((board[k][j]>0) && (prov_hod==0)){
                        if (board[k][j]>0){
                            schet_cher+=5;
                        }
                        board[k][j]=-5;
                        board[i][j]=0;
                        prov_hod=1;
                        break;
                    }
                }
                // диагонали
                for (k=i; k<8; k++){
                    if ((board[k][k+1]>0) && (prov_hod==0)){
                        if (board[k][k+1]>0){
                            schet_cher+=5;
                        }
                        board[k][k+1]=-5;
                        board[i][j]=0;
                        prov_hod=1;
                        break;
                    }
                }
                for (k=i; k>-1; k--){
                    if ((board[k][k-1]>0) && (prov_hod==0)){
                        if (board[k][k-1]>0){
                            schet_cher+=5;
                        }
                        board[k][k-1]=-5;
                        board[i][j]=0;
                        prov_hod=1;
                        break;
                    }
                }
                for (k=i; k>-1; k--){
                    if ((board[k][k+1]>0) && (prov_hod==0)){
                        if (board[k][k+1]>0){
                            schet_cher+=5;
                        }
                        board[k][k+1]=-5;
                        board[i][j]=0;
                        prov_hod=1;
                        break;
                    }
                }
                for (k=i; k<8; k++){
                    if ((board[k][k-1]>0) && (prov_hod==0)){
                        if (board[k][k-1]>0){
                            schet_cher+=5;
                        }
                        board[k][k-1]=-5;
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

#endif /* ferz_h */
