//*****ENUMERATIONS defined****
enum bool{
  false,true
};
enum pieceColor{
  Black,White
};

//*****UI.cpp*****
void Board();
void Display();
//*****UI_INPUT.cpp****
void input();
//*****UTLITY.cpp*****
void box(int,int,int,int,int); //to draw a box
void printLine(int,int,int); //line of checked squares for board


//*****STRUCTURES defined*****
//****STRUCT POSITION****
struct Position{
   int X;
   int Y;
};
bool posCmp(Position,Position);  //Definition in UTILITY.CPP
//*****POSITION ENDS*****
struct Round{
   Position White[2];
   Position Black[2];
};
//******CHESS.cpp******
bool Bishop(Position,Position);
bool Knight(Position,Position);
bool Pawn(Position,Position);
bool Queen(Position,Position);
bool Rook(Position,Position);
bool IsCheck(int);
bool IsCheckmate(int);
bool King(Position,Position);
//****CLASSES defined*****
class Game
{
   char BOARD[8][8];
   Position initPos;
   Position finalPos;
   int color;  //0 for black 1 for white

   public:
 //     int roundNumber;
 //     char pos[2][2];
      void Reset();
      int MoveCounter();//NOT DEFINED YET
      void NextMove();
      void UpdateBoard(Position,Position);
      char detectPiece(Position, int type=0);
      Position* detectPosition(char,int);
      int detectColor(Position);  //returns color of piece 0-Black and 1-White -1 for blank piece
      char* getcolor(); //accessor func
      bool ValidatePos(Position); //validate position
      bool ValidateMove(Position,Position);  //validates a move


      void BOARDEQ(Game);
};


//***DEBUG TOOLS***
void DebugPieces();