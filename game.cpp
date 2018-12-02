#include "game.h"
#include <iostream>
using namespace std;
//get random number
using namespace std;
inline void setRandSeed(){
    srand((unsigned)time(0) );
}
//get random position from 0 to n
inline int GetRandom(const unsigned int& n){
    int x=(rand() % n);
    return x;
}

Player::Player(char& c){
	mCh=c;
}

unsigned int Player::Play(const unsigned int& nCol){
    return GetRandom(nCol);
}
char Player::GetPiece() const {
    return mCh;
}

Game::Game(unsigned int nRow, unsigned int nCol)
{
	if (nRow<=0 || nCol <=0)
		cout<<"parmeter error"<<endl;
    else{
        mRow=nRow;mCol=nCol;
        mBoard=new char *[nRow];
        for (int i=0;i<nRow;i++){
            mBoard[i]=new char[nCol];
            memset(mBoard[i],'.',sizeof(**mBoard)*nCol);
        }
        char x='x';
        char y='y';
        p1=new Player(x);
        p2=new Player(y);
        mCount=0;
      }
};
void Game::Print() const{
	for (int i=0;i<mRow;++i){
		for (int j=0;j<mCol;++j){
            cout << *(*(mBoard+i)+j) <<' ';
        }
        cout<<endl;
    }
}
//return put position
bool  Game::Play(Player* p,std::pair<int,int>& _pos)
{
	if(p==NULL)
		 cout<<"Player Error" <<endl;
      //first p1
    unsigned int _col=p->Play(mCol);
   
    for(int i=mRow-1;i>=0;--i) {
		if(mCount>=(mRow*mCol)){
			break;
		}
		if(*(*(mBoard+i)+_col) =='.'){
			*(*(mBoard+i)+_col)=p->GetPiece();
			mCount++;
			_pos=make_pair(i,_col);
			return true;
       }
     } 
     return true;
   }

bool Game::CheckIsFull() const {
     return mCount<(mRow*mCol)? true:false;
}

bool Game::GetNextPosition(int& nRow,int& nCol,SEARCH_WAY& _way){
	if(nRow>=mRow || nCol>=mCol) return false;
	
	if(_way==RIGHT) nCol++;
    else if(_way==LEFT) nCol--;
    else if(_way==UP)   nRow--;
    else if(_way==DOWN) nRow++;
    else if(_way==RIGHTUP){
		nRow--; nCol++;	}
    else if(_way==RIGHTDOWN){
        nRow++; nCol--;}
    else if(_way==LEFTUP){
        nRow--; nCol--;}
    else if(_way==LEFTDOWN){
        nRow++; nCol++;}
    else 
		return false;

    if(nRow>=mRow || nCol>=mCol) return false;

	return true;
}

int Game::SearchDiffrentWay(char& ch,int nRow,int nCol,SEARCH_WAY _way){
    int _row=nRow;
    int _col=nCol;
    int cnt=0;

    while(GetNextPosition(_row,_col,_way)){
		if(*(*(mBoard+_row)+_col)==ch){
			//count++ and then count equal 3
           if(++cnt==3)
			   break;
        }
        else 
			break;
    } 
    return cnt;
}
bool Game::Search(char& ch,int nRow,int nCol){
	if(nRow>=mRow || nCol>=mCol) return false;
    std::pair<SEARCH_WAY,SEARCH_WAY> _way[4];
	//four way to search
    _way[0]=make_pair(RIGHT,LEFT);
    _way[1]=make_pair(UP,DOWN);
    _way[2]=make_pair(RIGHTUP,RIGHTDOWN);
    _way[3]=make_pair(LEFTUP,LEFTDOWN);

    int cnt=1;    
    for (int i=0;i<4 ;++i){
        int a=SearchDiffrentWay(ch,nRow,nCol,_way[i].first);
        if((cnt+a)>=4) return true;
        int b=SearchDiffrentWay(ch,nRow,nCol,_way[i].second);
        if((cnt+a+b)>=4) return true;
    }
    return false;
}
bool Game::CheckWinPlayer(char ch,int nRow,int nCol){
    if (mCount<4) return false;
    return Search(ch,nRow,nCol); 
}
void Game::Start(){
	setRandSeed();  
	int i=0;
    while(CheckIsFull()){
		std::pair<int,int> pos;
        if(!Play(p1,pos)){
			cout<<p1->GetPiece()<<" put error"<<endl;
            break;
        };
        if (!CheckIsFull()) break;
        if(CheckWinPlayer(p1->GetPiece(),pos.first,pos.second)){
             cout<<"Winner is "<<p1->GetPiece()<<endl;
             break;
        } 
        std::pair<int,int> pos2;
        if(!Play(p2,pos2)){
             cout<<p2->GetPiece()<<" put error"<<endl;
             break;
        }
        if(CheckWinPlayer(p2->GetPiece(),pos2.first,pos2.second)){
             cout<<"Winner is "<<p2->GetPiece()<<endl;
             break;
        }
      }
} 
