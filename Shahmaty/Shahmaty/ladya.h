//
//  ladya.h
//  Shahmaty
//
//  Created by Кирилл Броцкий on 25.12.2020.
//  Copyright © 2020 Кирилл Броцкий. All rights reserved.
//

#ifndef ladya_h
#define ladya_h
#include "Header.h"
#include "peshka.h"
#include "ladya.h"
#include "hourse.h"
#include "ferz.h"
#include "king.h"
#include "slon.h"
#include "otvet.h"

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

void intel_ladya(){
    int k=0;
    if (prov_hod==0){
    for (i=7; i>-1; i--){
        for (j=7; j>-1; j--){
            if (board[i][j]==-4){
                for (k=j; k<8; k++){
                    if ((board[i][k]>0) && (prov_hod==0)) {
                        if (board[i][k]>0){
                            schet_cher+=4;
                        }
                        board[i][k]=-4;
                        board[i][j]=0;
                        prov_hod=1;
                        break;
                    }
                }
                for (k=8; k>j; k--){
                    if ((board[i][k]>0) && (prov_hod==0)) {
                        if (board[i][k]>0){
                            schet_cher+=4;
                        }
                        board[i][k]=-4;
                        board[i][j]=0;
                        prov_hod=1;
                        break;
                    }
                }
                for (k=i; k<8; k++){
                    if ((board[k][j]>0) && (prov_hod==0)){
                        if (board[k][j]>0){
                            schet_cher+=4;
                        }
                        board[k][j]=-4;
                        board[i][j]=0;
                        prov_hod=1;
                        break;
                    }
                }
                for (k=8; k>i; k--){
                    if ((board[k][j]>0) && (prov_hod==0)){
                        if (board[k][j]>0){
                            schet_cher+=4;
                        }
                        board[k][j]=-4;
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

#endif /* ladya_h */
