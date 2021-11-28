#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include "ptyp.h"

void Game::Reset(){  //Constructor to initialise the BOARD
   // roundNumber=1;
    color=1;
    //for initialising the Board
    char PIECE[8][8]={	{'r','n','b','k','q','b','n','r'},
			{'p','p','p','p','p','p','p','p'},
			{'B',' ',' ',' ',' ',' ',' ',' '},
			{' ',' ',' ',' ',' ',' ',' ',' '},
			{' ',' ',' ',' ',' ',' ',' ',' '},
			{' ',' ',' ',' ',' ',' ',' ',' '},
			{'P','P','P','P','P','P','P','P'},
			{'R','N','B','K','Q','B','N','R'} };
    for(int i=0;i<8;i++){ for(int j=0;j<8;j++) BOARD[i][j]=PIECE[i][j]; }
}
char* Game::getcolor(){
   if (!color) return "BLACK";
   else return "WHITE";
}
void Game::UpdateBoard(Position initMove, Position finalMove) {   //Note that all data has alredy been validated b4 updating board
   //By convention, coordinates start at (1,1) from bottomleft i.e whiterook
   //Y,X is correct due to checking at runtime
   int X=initMove.X, Y=initMove.Y , nX=finalMove.X, nY=finalMove.Y;

   BOARD[nX][nY]=BOARD[X][Y];
   BOARD[X][Y] = ' ';

}
char Game::detectPiece(Position location, int type){      //type
   int X,Y;                                                 //0<-for all purpose
   if (type==0) return BOARD[location.X][location.Y];
   //non 0 <- only for specific cases like forced input
   else return BOARD[7-location.X][location.Y];  //testing purpose
}

Position* Game::detectPosition(char Piece, int color){
   int PosNum;
   char pieces[2]={tolower(Piece),toupper(Piece)};
   switch (tolower(Piece)){
      case 'p': PosNum=8;break;
      case 'k': PosNum=1;break;
      case 'b': PosNum=2;break;
      case 'n': PosNum=2;break;
      case 'q': PosNum=1;break;
      case 'r': PosNum=2;break;

   }
   //To define the number of possible positions
   Position *p=new Position[PosNum];   //try and replace posnum
   int count=0;
   for(int i=0;i<8;i++){
      for(int j=0;j<8;j++){
	 if (BOARD[i][j]==pieces[color]){
	       p[count].Y=j;
	       p[count].X=i;
	       count++;
	 }
      }
   }
   return p;
}

int Game::detectColor(Position A){
   int X=A.X, Y=A.Y;
   if(BOARD[X][Y]!=' '){
      if(islower(BOARD[X][Y])) return 0;
      if(isupper(BOARD[X][Y])) return 1;
   }
   return -1; //if empty
}



bool Game::ValidatePos(Position move){

      char piece=detectPiece(move);
      if (piece==' '){
	 cout<<"ERROR: Position is blank :\n";
	 return false;
      }
      if(detectColor(move)!=color){
	 cout<<"ERROR: Cannot move piece of different color :\n";
	 return false;
      }
      else return true;
}  // THIS function checks whether intial piece is on empty place or not

bool Game::ValidateMove(Position initMove, Position finalMove){
   if(posCmp(initMove,finalMove)==true){
      cout<<"ERROR: Inital and final positions cannot be same : ";
      return false;
   }

   bool validate=false;
   if(detectPiece(finalMove)!=' '){
      if (detectColor(finalMove)==detectColor(initMove)){
	  cout<<"ERROR: Piece of same color on final position\n";
	  return false;
      }
   }
    //checkmate algorithm not added
    if(IsCheck(color)==false){ //if not check
      switch (tolower(detectPiece(initMove))){ //validation of moves
	  case 'q': validate=Queen(initMove,finalMove);break;
	  case 'r': validate=Rook(initMove,finalMove);break;
	  case 'n': validate=Knight(initMove,finalMove);break;
	  case 'p': validate=Pawn(initMove,finalMove);break;
	  case 'b': validate=Bishop(initMove,finalMove);break;
	  case 'k': validate=King(initMove,finalMove);break;
      }
      if (validate==false){
	 cout<<"ERROR 3: INVALID MOVE ";
	 return false;
      }
    }
    else{
       cout<<"ILLEGAL MOVE: "<<getcolor()<<" King is in check!\n";
       return false;
    }
   initPos=initMove; finalPos=finalMove;
   return true;
}

void Game::NextMove(){

   UpdateBoard(initPos, finalPos);
 //  roundNumber++;
   //change color
   if (color==Black) color=White;
   else color=Black;
   if(!IsCheckmate(color)) clrscr();
   else {
      cout<<"\t";
      textcolor(RED);
      cprintf("Checkmate!");
      cout<<" The game is over.";
      getch();
      Reset();
   }
   Display();
}

void Game::BOARDEQ(Game A){
  for(int i=0;i<8;i++){
     for(int j=0;j<8;j++){
	 A.BOARD[i][j]=BOARD[i][j];
     }
  }
}


