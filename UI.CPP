#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include "ptyp.h"
#include<string.h>
extern Game game;
//****************************FUNCTION PROTOTYPEs**********************

void Board();
void Status(char*);
void Menu();

char BLOCK='Û';
int bg=BLUE;

//***************************DISPLAY FUNCTION*************************
// MAIN FOR THIS MODULE
void Display(){

  textbackground(bg);
  textcolor(WHITE);
  clrscr();

  Board();
  Status(game.getcolor());
 // gotoxy(2,20);
//  DebugPieces();
  Menu();
}
//****************************DISPLAY FUNCTIONs**************************
void Status(char *color){
   gotoxy(2,2);
   cout<<"CURRENT MOVE:";
	 textcolor(YELLOW+BLINK);
	 cprintf(color);

//    box(62,4,18,14,WHITE);
//    gotoxy(68,5);textcolor(BLACK);cprintf("STATUS");
    /*
    if(game.roundNumber!=1){
    for(int n=1;n<5;n++){
       for(int i=0;i<2;i++){
	  strcpy(move[n][i],move[n-1][i]);
       }
    }
    for(int i=0;i<2;i++) strcpy(move[0][i],game.pos[i]);
    for(n=1;n<5;n++){
       for(int i=0;i<2;i++){
	  gotoxy(63,5+n);
	  cout<<move[n][i]<<"-";
       }
    }
   }*/
}


void Menu(){
   char menuText[5][18]={" ","M -> MOVE","S -> SAVE","L -> LOAD","X -> EXIT"};
   char menu[4]={'m','s','l','x'};
   char ch;
   gotoxy(9,5);  textcolor(BLACK); cprintf("MENU");
   box(1,4,19,15,WHITE);
   for(int i=0;i<5;i++){
      gotoxy(3,6+i);   cout<<menuText[i];
   }
   gotoxy(2,20);
   cout<<"Please click an appropriate option from the MENU List: ";
   ch=getch();
   cout<<ch<<"\n";
   ch=tolower(ch);
   bool Validate=false;
   while(!Validate){
      for(i=0;i<4;i++) {
	 if (ch==menu[i]) Validate=true;
      }
      if(!Validate){
	 cout<<"ERROR 1 : INVALID MENU OPTION : RE-ENTER: ";
	 ch=getch();
	 cout<<ch<<"\n";
	 ch=tolower(ch);
      }
   }

   switch(ch){
      case 'm':
	    input();
	    break;
   }
}

void Board(){
   gotoxy(17,2);
   textcolor(BLACK);
   cprintf("      A   B   C   D   E   F   G   H");
   cout<<"\n";
   int temp=1;
   for (int i=1;i<=4;i++){
      printLine(BLACK,LIGHTGRAY,temp-1);  cout<<"     "<<9-temp;
      printLine(LIGHTGRAY,BLACK,temp);  cout<<"     "<<9-temp-1;
      temp+=2;
   }
}

