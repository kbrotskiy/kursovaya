//
//  king.h
//  Shahmaty
//
//  Created by Кирилл Броцкий on 25.12.2020.
//  Copyright © 2020 Кирилл Броцкий. All rights reserved.
//

#ifndef king_h
#define king_h

#include "Header.h"
#include "peshka.h"
#include "ladya.h"
#include "hourse.h"
#include "ferz.h"
#include "king.h"
#include "slon.h"
#include "otvet.h"

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

void intel_king(){
    if ((board[x][y] == -6) && (prov_hod==0)) {
        if ((board[x-1][y-1]>0) && (prov_hod==0)){
            if (board[x-1][y-1]>0){
                schet_cher+=6;
            }
            board[x-1][y-1]=-6;
            board[x][y]=0;
            prov_hod=1;
        }
        if ((board[x-1][y]>0) && (prov_hod==0)){
            if (board[x-1][y]>0){
                schet_cher+=6;
            }
            board[x-1][y]=-6;
            board[x][y]=0;
            prov_hod=1;
        }
        if ((board[x-1][y+1]>0) && (prov_hod==0)){
            if (board[x-1][y+1]>0){
                schet_cher+=6;
            }
            board[x-1][y+1]=-6;
            board[x][y]=0;
            prov_hod=1;
        }
        if ((board[x][y-1]>0) && (prov_hod==0)){
            if (board[x][y-1]>0){
                schet_cher+=6;
            }
            board[x][y-1]=-6;
            board[x][y]=0;
            prov_hod=1;
        }
        if ((board[x][y+1]>0) && (prov_hod==0)){
            if (board[x][y+1]>0){
                schet_cher+=6;
            }
            board[x][y+1]=-6;
            board[x][y]=0;
            prov_hod=1;
        }
        if ((board[x+1][y-1]>0) && (prov_hod==0)){
            if (board[x+1][y-1]>0){
                schet_cher+=6;
            }
            board[x+1][y-1]=-6;
            board[x][y]=0;
            prov_hod=1;
        }
        if ((board[x+1][y]>0) && (prov_hod==0)){
            if (board[x+1][y]>0){
                schet_cher+=6;
            }
            board[x+1][y]=-6;
            board[x][y]=0;
            prov_hod=1;
        }
        if ((board[x+1][y+1]>0) && (prov_hod==0)){
            if (board[x+1][y+1]>0){
                schet_cher+=6;
            }
            board[x+1][y+1]=-6;
            board[x][y]=0;
            prov_hod=1;
        }
    }
}


#endif /* king_h */
