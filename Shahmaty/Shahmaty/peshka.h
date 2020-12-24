//
//  peshka.h
//  Shahmaty
//
//  Created by Кирилл Броцкий on 25.12.2020.
//  Copyright © 2020 Кирилл Броцкий. All rights reserved.
//

#ifndef peshka_h
#define peshka_h
#include "Header.h"
#include "peshka.h"
#include "ladya.h"
#include "hourse.h"
#include "ferz.h"
#include "king.h"
#include "slon.h"
#include "otvet.h"

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
        if (((y-y_nov<=1) && (y-y_nov>=0)) || ((y_nov-y>=-1) && (y_nov-y<=1))){
        board[x_nov][y_nov] = board[x][y];
        board[x][y] = 0;
         
        }
    }
    else {
        std::cout << "Ваш ход неверный! Cчитаю вам стоит подучить правила ;)" << std::endl;
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

void intel_peshka(){
    int pred_x=x,  pred_x_nov=x_nov, vub;
    int pred_y=y,  pred_y_nov=y_nov, znach_nov=0, znach_star=0;
    srand(time(0));
    std::cout<<"=="<<x<<" "<<y<<" "<<pred_y_nov;
    
    if (y<7 && y>0){
    for (i=0; i<8; i++){
        for (j=0; j<8; j++){
            if (board[i][j]==-1){
                if(j<7){
                if ((board[i+1][j+1]!=0) && (board[i+1][j+1]>0)){
                    k=1;
                    x=i;
                    y=j;
                    x_nov=i+1;
                    y_nov=j+1;
                    
                    break;
                }
                    if ((board[i-1][j+1]!=0) && (board[i-1][j+1]>0)){
                        k=1;
                        x=i;
                        y=j;
                        x_nov=i+1;
                        y_nov=j+1;
                        
                        break;
                    }
                }
                if (j>0){
                if ((board[i+1][j-1]!=0) && (board[i+1][j-1]>0)){
                    k=1;
                    x=i;
                    y=j;
                    x_nov=i+1;
                    y_nov=j-1;
                    
                    break;
                }
                    if ((board[i-1][j-1]!=0) && (board[i-1][j-1]>0)){
                        k=1;
                        x=i;
                        y=j;
                        x_nov=i-1;
                        y_nov=j-1;
                        
                        break;
                    }
                }
                
            }
        }
    }
    }
    std::cout<<"!!!";
    if (k==1){
        znach_nov=board[x_nov][y_nov];
        znach_star=board[x][y];
        board[x_nov][y_nov]=-1;
        board[x][y]=0;
        prov_hod=1;
        hod_p=true;
    }
    k=0;
    std::cout<<"!!!"<<hod_p;
    while ((hod_p==false) && (sch!=2)){
        x=pred_x;
        y=pred_y;
    while ((board[x][y]!=-1) && (hod_p==false)){
        srand(time(0));
        while(board[x][y]!=-1){
        x=rand()%8;
        y=rand()%8;
        }
        if ((board[x][y]==-1)&&(pred_y_nov-y<=1) && (y-pred_y_nov>=0)){
            break;
        }
    }
    //cout<<endl<<"======"<<x<<" "<<y<<" "<<pred_y_nov;
    if (board[x][y]==-1){
        
        if ((pred_x-pred_x_nov>=2) && (x==1)){
            
            vub=rand()%100;
            if (vub<50){  x_nov=x+2;  y_nov=y;    }
            if (vub>50){  x_nov=x+1;  y_nov=y;     }
           // if (vub==2){  x_nov=x+1;  y_nov=y;   }
        }
        
        if ((pred_x-pred_x_nov==1)){
            
            vub=rand()%100;
            //if (vub<50){  x_nov=x+2;  y_nov=y;    }
            if (vub>50){  x_nov=x+1;  y_nov=y;     }
           // if (vub==2){  x_nov=x+1;  y_nov=y;   }
        }
        
        if (y<7 && y>0){
        if ((board[x_nov][y_nov]==0) && (board[x_nov+1][y_nov-1]==0) && board[x_nov+1][y_nov+1]==0){
            znach_nov=board[x_nov][y_nov];
            znach_star=board[x][y];
            board[x_nov][y_nov]=-1;
            board[x][y]=0;
            prov_hod=1;
            hod_p=true;
            break;
        }
        } else {
            if ((board[x_nov][y_nov]==0) && (board[x_nov+1][y_nov+1]==0) && (y_nov==0)){
                znach_nov=board[x_nov][y_nov];
                znach_star=board[x][y];
                board[x_nov][y_nov]=-1;
                board[x][y]=0;
                prov_hod=1;
                hod_p=true;
                break;
            }if ((board[x_nov][y_nov]==0) && (board[x_nov+1][y_nov-1]==0) && (y_nov==7)){
                znach_nov=board[x_nov][y_nov];
                znach_star=board[x][y];
                board[x_nov][y_nov]=-1;
                board[x][y]=0;
                prov_hod=1;
                hod_p=true;
                break;
            }
            
        }
    }
        sch++;
    }
    std::cout<<"!---!---!";
    hod_p=false;
    if ((znach_star<0) && (znach_nov>0)){
        schet_cher++;
    }
   
}

#endif /* peshka_h */
