#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<math.h>
#include "ptyp.h"

extern Game game,Gtemp;

bool IsCheckmate(int color){
   Position pos,pos1;
   bool validate=false;
   Position* pKing=Gtemp.detectPosition('k', color);
   Position king=*pKing;
   for(int i=-1;i<=1;i++) {
      for(int j=-1;j<=1;j++){
	 pos.X=king.X+i; pos.Y=king.Y+j;
	 if((Gtemp.detectPiece(pos)==' ')||(Gtemp.detectColor(pos)==color))
	 { continue; }
	 switch(tolower(Gtemp.detectPiece(pos))){
	   case 'k': validate=King(pos,king);break;
	   case 'b': validate=Bishop(pos,king);break;
	   case 'n': validate=Knight(pos,king);break;
	   case 'q': validate=Queen(pos,king);break;
	   case 'p': validate=Pawn(pos,king);break;
	   case 'r': validate=Rook(pos,king);break;
	 }
	 if (validate==true){
	    for(int p=0;p<8;p++){
	       for(int q=0;q<8;q++){
		  pos1.X=j; pos1.Y=i;
		  if((Gtemp.detectPiece(pos1)==' ')||(Gtemp.detectColor(pos1)==color))
		     { continue; }
		  switch(tolower(Gtemp.detectPiece(pos1))){
		      case 'k': validate=King(pos1,pos);break;
		      case 'b': validate=Bishop(pos1,pos);break;
		      case 'n': validate=Knight(pos1,pos);break;
		      case 'q': validate=Queen(pos1,pos);break;
		      case 'p': validate=Pawn(pos1,pos);break;
		      case 'r': validate=Rook(pos1,pos);break;
		  }
		  if (validate==true) return false;
	       }
	    }
	    if (validate==false)  return true;
	 }
      }
   }
   return false;

}

bool IsCheck(int color){
   Position pos;
   bool validate=false;
   Position* pKing=Gtemp.detectPosition('k', color);
   for(int i=0;i<8;i++){
      for(int j=0;j<8;j++){
	 pos.X=j; pos.Y=i;
	 if((Gtemp.detectPiece(pos)==' ')||(Gtemp.detectColor(pos)==color))
	 { continue; }
	 switch(tolower(Gtemp.detectPiece(pos))){
	   case 'k': validate=King(pos,*pKing);break;
	   case 'b': validate=Bishop(pos,*pKing);break;
	   case 'n': validate=Knight(pos,*pKing);break;
	   case 'q': validate=Queen(pos,*pKing);break;
	   case 'p': validate=Pawn(pos,*pKing);break;
	   case 'r': validate=Rook(pos,*pKing);break;
	 }
	 if (validate==true) return true;
      }
   }
   return false;
}
//RECHECK KNIGHT
bool Knight(Position initMove, Position finalMove){
   int X=initMove.X, Y=initMove.Y, nX=finalMove.X, nY=finalMove.Y;
   int count=0, itemp, jtemp;
   int Move[2][4]={{1,-1,2,-2},{2,-2,1,-1}};
   for(int n=0;n<=1;n++){
      for(int i=0;i<=1;i++){
	 for (int j=0;j<=1;j++){
	    itemp=i;
	    jtemp=j;
	    if(count>4) {
	       itemp+=2;
	       jtemp+=2;
	    }
	    if((nX==(X+Move[0][itemp]))&&(nY==(Y+Move[1][jtemp])))  return true;
	    count++;
	 }
      }
   }
   return false;
}

bool Rook(Position initMove, Position finalMove){
   int X=initMove.X, Y=initMove.Y, nX=finalMove.X, nY=finalMove.Y;
   Position temp;

   if(nX==X){
      //check if all blocks between X and nX is empty
      for(int i=1;i<abs(nY-Y);i++){
	 temp.X=X;
	 if(nY>Y) temp.Y=Y+i;
	 else temp.Y=Y-i;
	 if (game.detectPiece(temp)!=' ') return false;
      }
      return true;
   }
   else if(nY==Y){
      for(int i=1;i<abs(nX-X);i++){
	 temp.Y=Y;
	 if(nX>X) temp.X=X+i;
	 else temp.X=X-i;
	 if (game.detectPiece(temp)!=' ') return false;
      }
      return true;
   }
   return false;
}

bool Bishop(Position initMove, Position finalMove){
   int X=initMove.X, Y=initMove.Y, nX=finalMove.X, nY=finalMove.Y;
   int sign[4][2] = { {-1,1},{1,1},{1,-1},{-1,-1} };
   int c; Position pos;
   if(((nX-X)==0)||((nY-Y)==0))return false;  //avoid divide error
   for(int i=0;i<4;i++){  //i for quadrant
     if( (((nX-X)/abs(nX-X))==sign[i][0]) && (((nY-Y)/abs(nY-Y))==sign[i][1]) ){
	 cout<<i<<" ";
	 c=1;
	 do{
	    pos.X = X+(sign[i][0]*c); pos.Y=Y+(sign[i][1]*c);
//	    if ((game.detectPiece(pos)!=' ')&&(game.detectColor(pos)==game.detectColor(initMove)))
//		 return false;  //if path not clear
//***BUG FIXED->PROBLEM WITH CHECKs
	    if ((game.detectPiece(pos)!=' ')){
	       if(posCmp(pos,finalMove)==true) return true;
	       return false;  //if path not clear
	    }
	    c++;
	 }while(posCmp(pos,finalMove)==false);
	 return true;
      }
   }
   return false;
}

bool Queen(Position initMove, Position finalMove){
   if(Rook(initMove,finalMove)) return true;
   else if(Bishop(initMove,finalMove)) return true;
   return false;
}

bool Pawn(Position initMove, Position finalMove){
   int X=initMove.X, Y=initMove.Y;
   int color=game.detectColor(initMove);
   int arr[2]={1,-1};//changed mark
   Position diagonal[2]={ {X+arr[color],Y+1}, {X+arr[color],Y-1} };
   for(int i=0;i<=1;i++){
      if(posCmp(finalMove,diagonal[i])){
	 if(game.detectPiece(diagonal[i])==' ')   return false;
	 else {
	    if (game.detectColor(diagonal[i])!=color) return true;
	 }
      }
   }
   int rowColor[2]={1,6};
   Position step[2]={ {X+arr[color],Y}, {X+(2*arr[color]),Y} };
   if(game.detectPiece(finalMove)==' '){
      if (posCmp(finalMove,step[0])==true) return true;
      if (X==rowColor[color]){
	 if (posCmp(finalMove,step[1])==true) return true;
      }
   }
   return false;
}

bool King(Position initMove, Position finalMove){
   Position pos;
   for(int i=-1;i<=1;i++) {
      for(int j=-1;j<=1;j++){
	 pos.X=initMove.X+i; pos.Y=initMove.Y+j;
	 if(posCmp(pos,finalMove)==true) return true;
      }
   }
   return false;
}




