# Console-based-Chess
This project has been developed using C++ which is an extension to C language and was developed by Bjarne Stroustrup in the AT&T Bell laboratory. It is an intermediate level language, as it comprises of both high-level and low-level language features. C++ is a statically typed, free form, multiparadigm, and object-oriented general-purpose programming language. The compiler used for this project is Turbo C++, version 3.0, 1992-1993 by Borland International.

The main aim of this project is to develop a light-weighted game software which can be utilised on easy setup and installation.  These games have been implemented on console, which makes it as fast to access.
## Requirements
- Windows 10 PC
- [Turbo C++](https://developerinsider.co/download-turbo-c-for-windows-7-8-8-1-and-windows-10-32-64-bit-full-screen/) compiler and interface
- Download the project and run CHESS.PRJ.
## Features
### Chess Board
- We can use ASCII characters to draw the board.
- The character with ASCII code 219 represents a block (█).
- This is used to build the blocks for the chess board of required size.
- <conio.h> holds the functions to change colours of the blocks as required.
### Menus
- This program features Menus with easy segregation of required functions.
- The program starts with a Main Menu, which allows you to choose a desired game.
- The Menu in the beginning of the chess game, allows us to make a move(M), Save(S) the game, Load(L) the saved game, and Exit(X).
- The current game can be saved, and this is done by saving the BOARD[][] array into a text file. This is retrieved later when load function is used.
## Description
This program has been incorporated as a set of modules for ease of access to different parts of the code.
### Modules
#### Header File [<ptyp.h>](PTYP.H)
This header file holds all the global function prototypes, structures, and classes definitions which can be easily accessed by each and every module.
#### Data Structures
Data structures used in this program are summarised as below:


| Name | Description |
|:-------:|:---------:|
| enum bool | For Boolean datatype|
| struct Position | To define the position for a piece |
| enum PieceColor | To define integers for the colour  |
| struct Round | Two moves of each colour form a round |

#### Classes
The classes used in this program are summarised in Figure below and described in the following Table.

| Class | Description |
|:-----:|:-----------:|
| [Board](UI.CPP) |	Used to make the layout of the chess board. Holds the array of BOARD pieces. Also contains functions for implementation and access of pieces, colour of pieces and to save and load game. |
| [Chess](CHESS.CPP) |	Holds a Board class as a data member. It includes all the functions which is used in the validation of a move. |
| [Game](GAME.CPP)	| The overall class which ensures the workflow for each round and displays error messages as and when required. |

![UML](docs/assets/uml.jpg)

#### Structure of the project
The project consists of 8 files which are described below:

| File Name | Description |
|:---------:|:---------:|
| [CHESS](CHESS.CPP) |	Holds function definitions for chess class |
| [CHECK](CHECK.CPP) |	Holds function definitions for chess class, but includes those which detect check and checkmates. |
| [GAME](GAME.CPP)  |	Holds function definitions for game class |
|  [UI](UI.CPP)   |	Holds the function definition to display the User interface with the board |
| [UI_INPUT](UI_INPUT.CPP) |	Specifically, to input and validate the options and moves |
| [UTILITY](UTILITY.CPP) |	Holds some miscellaneous utility functions |
| [MAIN](MAIN.CPP) |	Holds the function for the Chess program |

#### Sample Output

![sampleout](docs/assets/chess_main_page.png)
