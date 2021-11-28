#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include "ptyp.h"
extern Game game,Gtemp;
extern char BLOCK;
extern int bg;

bool posCmp(Position A ,Position B){
   if ((A.X==B.X)&&(A.Y==B.Y))  return true;
   return false;
}

void box(int left, int top, int right, int bottom, int color=LIGHTGRAY){
   textcolor(color);
   gotoxy(left,top);
   for(int i=0;i<bottom;i++){
      gotoxy(left,i+top);
      if ((i==0)||(i==bottom-1)){
	  if (i==0)  cprintf("É");
	  else if (i==bottom-1) cprintf("È");
	  for(int j=1;j<right-1;j++) cprintf("Í");
	  if (i==0) cprintf("»");
	  if (i==bottom-1) cprintf("¼");
      }
      else {
	  cprintf("º");
	  gotoxy(right+left-1,i+top);
	  cprintf("º");
      }

   }
}


void printLine(int col1,int col2, int CELLROW){    //Prints a line of checked
   int col[2] = {col1,col2};
   char ch;
   int cell = 4, CELLCOL = 0;
   Position CELL;

   for (int r=0;r<(cell/2);r++){   //THICKNESS OF CELL
     cout<<"\n\t\t     ";
     for(int c=0;c<4;c++){   // FOURS OF A PAIR
	for(int i=0;i<2;i++){  //A PAIR - > COL[1],COL[2]
	   if (r==1){               //algorithm to get columncell
	      if(i==1) CELLCOL+=1;
	   }
	   for(int j=0;j<cell;j++){ //A CELL
	      if((j==cell/4)&&(r==cell/4)){
		 CELL.X=CELLROW; CELL.Y=CELLCOL;
		 ch=game.detectPiece(CELL);
		 if(ch==' '){
		    textcolor(col[i]);
		    cprintf("%c",BLOCK);   //if empty then fill with app color
		 }
		 else{textbackground(col[i]); textcolor(WHITE); cprintf("%c",ch);}
	      }
	      else{ textcolor(col[i]); cprintf("%c",BLOCK);}
	   }
	}
	if (r==1) CELLCOL+=1;
     }
   }
   textbackground(bg);
}




