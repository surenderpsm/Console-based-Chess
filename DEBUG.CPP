#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include "ptyp.h"
extern Game game;

void DebugPieces(){
   bool validate;
   Position init,final;

/*   //rook

   init.X=5; init.Y=2;
   final.X=5; final.Y=4;

   validate=Rook(init,final);
   cout<<validate;
*/
   //pawn
   init.X=3; init.Y=5;
   final.X=1; final.Y=7;

   validate=Bishop(init,final);
   cout<<validate;
   //Knight

   getch();
}


/*
void DebugPieces(){
   bool validate;
   Position pos[2];
   char name[6][5]={"rook","knight","bishop","pawn","queen","king"};
   int moves[2][2][2]={{ {5,2},{5,4} },
		       { {4,5},{3,6} } };

   for(int i=0;i<6;i++){
     for(int j=0;j<2;j++){
	if()pos[j].Y=move[i][j][1];
     }
	switch i{
	   case 0:  Rook()
}
*/