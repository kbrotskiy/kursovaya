//
//  hourse.h
//  Shahmaty
//
//  Created by Кирилл Броцкий on 25.12.2020.
//  Copyright © 2020 Кирилл Броцкий. All rights reserved.
//

#ifndef hourse_h
#define hourse_h
#include "peshka.h"
#include "ladya.h"
#include "hourse.h"
#include "ferz.h"
#include "king.h"
#include "slon.h"
#include "otvet.h"

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

void intel_hourse(){
    for (i=0; i<8; i++){
        for (j=0; j<8; j++){
            if (board[i][j]==-2){
                if ((i>1) && (j>0) && (i<6) && (j<6)){
                    if ((board[i-2][j-1]>0) && (board[i-2][j-1]!=2) && (prov_hod==0)){
                        if (board[i-2][j-1]>0){
                            schet_cher+=2;
                        }
                        board[i-2][j-1]=-2;
                        board[i][j]=0;
                        prov_hod=1;
                    }
                    if ((board[i-2][j+1]>0) && (board[i-2][j+1]!=2) && (prov_hod==0)){
                        if (board[i-2][j+1]>0){
                            schet_cher+=2;
                        }
                        board[i-2][j+1]=-2;
                        board[i][j]=0;
                        prov_hod=1;
                    }
                    if ((board[i+2][j-1]>0) && (board[i+2][j-1]!=2) && (prov_hod==0)){
                        if (board[i+2][j-1]>0){
                            schet_cher+=2;
                        }
                        board[i+2][j-1]=-2;
                        board[i][j]=0;
                        prov_hod=1;
                    }
                    if ((board[i+2][j+1]>0) && (board[i+2][j+1]!=2) && (prov_hod==0)){
                        if (board[i-2][j-1]>0){
                            schet_cher+=2;
                        }
                        board[i-2][j-1]=-2;
                        board[i][j]=0;
                        prov_hod=1;
                    }
                    if ((board[i-1][j-2]>0) && (board[i-1][j-2]!=2) && (prov_hod==0)){
                        if (board[i-1][j-2]>0){
                            schet_cher+=2;
                        }
                        board[i-1][j-2]=-2;
                        board[i][j]=0;
                        prov_hod=1;
                    }
                    if ((board[i+1][j-2]>0) && (board[i+1][j-2]!=2) && (prov_hod==0)){
                        if (board[i+1][j-2]>0){
                            schet_cher+=2;
                        }
                        board[i+1][j-2]=-2;
                        board[i][j]=0;
                        prov_hod=1;
                    }
                    if ((board[i-1][j+2]>0) && (board[i-1][j+2]!=2) && (prov_hod==0)){
                        if (board[i-1][j+2]>0){
                            schet_cher+=2;
                        }
                        board[i-1][j+2]=-2;
                        board[i][j]=0;
                        prov_hod=1;
                    }
                    if ((board[i+1][j+2]>0) && (board[i+1][j+2]!=2) && (prov_hod==0)){
                        if (board[i+1][j+2]>0){
                            schet_cher+=2;
                        }
                        board[i+1][j+2]=-2;
                        board[i][j]=0;
                        prov_hod=1;
                    }
                }
            }
        }
    }
}

#endif /* hourse_h */
