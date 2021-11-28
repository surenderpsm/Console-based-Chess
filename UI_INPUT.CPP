#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include "ptyp.h"
extern Game game,Gtemp;


void input(){
   char keyword[2][10] ={"initial", "final"};
   char rcnames[2][8]={ {'A','B','C','D','E','F','G','H'},
			{'8','7','6','5','4','3','2','1'}  };
   char input[3];
   Position Move[2];
   bool validate=false;
fullinp:
   for(int i=0;i<2;i++){
      inp:
      cout<<"\tEnter the "<<keyword[i]<<" position : "; gets(input);
      //strcpy(game.pos[i],input);
      if((!isalpha(input[0])) || (!isdigit(input[1]))||
	    ((isprint(input[2])) && (!isspace(input[2]))) )
      {
	 cout<<"ERROR: Incorrect Format: ";
	 goto inp;
      }
      //VALIDATING THE ENTERED POSITION
	 for(int j=0;j<2;j++){
	    for(int k=0;k<8;k++){
	       if(input[j]==rcnames[j][k]){
		   if(j==0) Move[i].Y=k;    //col        -Alphabet
		   if(j==1) Move[i].X=k;    //row
		   validate=true;
	       }
	    }
	    if(validate==false){
	       cout<<"ERROR: INVALID Position. ";
	       goto inp;
	    }
	    validate=false;
	 }
      //Format and Range validation complete
      if(i==0){
	 if(!game.ValidatePos(Move[i])){
	    goto inp;
	 }
      }
      if(i==0){
	 cout<<"You chose to move a ";
	 textcolor(LIGHTRED+BLINK);
	 switch(tolower(game.detectPiece(Move[i]))){
	     case 'q':cprintf("QUEEN");break;
	     case 'r':cprintf("ROOK");break;
	     case 'n':cprintf("KNIGHT");break;
	     case 'b':cprintf("BISHOP");break;
	     case 'p':cprintf("PAWN");break;
	     case 'k':cprintf("KING");break;
	 }
	 cout<<"\n";
      }
   }
   Gtemp.UpdateBoard(Move[0],Move[1]);//only to test check
   if(!game.ValidateMove(Move[0], Move[1])){
      goto fullinp;
   }
   game.BOARDEQ(Gtemp);
   game.NextMove();
}