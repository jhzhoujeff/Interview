#ifndef __MY__GAME__
#define __MY__GAME__
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include <string.h>
#include <utility>
#include <algorithm>
//get random number
using namespace std;
inline void setRandSeed();
inline int GetRandom(const unsigned int& n);

class Player
{
public:
  explicit Player(char& c); 
  unsigned int Play(const unsigned int& nCol);
  char GetPiece() const;
private:
  char mCh;   //piece
};

enum SEARCH_WAY{UP,DOWN,LEFT,RIGHT,RIGHTUP,RIGHTDOWN,LEFTUP,LEFTDOWN};

class Game
{
public:
	explicit Game(unsigned int nRow, unsigned int nCol);
    void Print() const;
	bool Play(Player* p,std::pair<int,int>& _pos);
	bool CheckIsFull() const;
	bool GetNextPosition(int& nRow,int& nCol,SEARCH_WAY& _way);
	int  SearchDiffrentWay(char& ch,int nRow,int nCol,SEARCH_WAY _way);
	bool Search(char& ch,int nRow,int nCol); 
	bool CheckWinPlayer(char ch,int nRow,int nCol);
	void Start();
private:
    unsigned mRow,mCol;
    char** mBoard;    //game board
    Player* p1;
    Player* p2;
    unsigned int mCount;
};
#endif //
