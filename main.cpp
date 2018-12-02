#include "trieTree.h"
#include "game.h"
#include<stdlib.h>
#include<iostream>
using namespace std;
void test_game()
{
    cout<< "***************begin Game test****************" <<endl;
    Game* game=new Game(6,7);
    cout<<"game init over......."<<endl;
    game->Print();
    cout<<"game after played...."<<endl;
    game->Start();
    game->Print();
    cout<< "***************end Game test****************" <<endl;
}
void test_trieTree(){
    
    cout<< "***************begin trieTree test ****************" <<endl;
	trieTree* trie=new trieTree();
    char a0[]="ape";
    char a1[]="apple";
    char a2[]="apples";
    trie->Insert(a0);
    trie->Insert(a1);
    trie->Insert(a2);

    char b0[]="blue";
    char b1[]="blind";
    char b2[]="blink";
    
	trie->Insert(b0);
    trie->Insert(b1);
    trie->Insert(b2);
    
    char c0[]="cat";
    char c1[]="catch";
    char c2[]="cow";
    
	trie->Insert(c0);
    trie->Insert(c1);
    trie->Insert(c2);

    trie->Print();
    cout<< "***************end trieTree test ****************" <<endl;
	return;
	

}

int  main()
{
    test_game();
	test_trieTree();
    return 0;
}
