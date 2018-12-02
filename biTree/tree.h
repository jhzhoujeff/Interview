#pragma once
#include "Stdafx.h"
#include <string>
#include <set>
#include <vector>
#include <list>
using namespace std;

namespace interviewsoftware{

    //tree node struct
    typedef struct _node {
        string data;
        _node* leftchild;
        _node* rightchild;
    } BiNode,*pBiNode;
    
    //valid operator list
    static char array[] = {'+','-','*','/'};
    static set<char> OPERATOR (array,array+sizeof(array)/sizeof(*array));
    
    //class tree define
	class tree{
	public:
		tree(string input);
		~tree();
	public:
		string traverse_left_first();
		string traverse_right_first();
		string traverse_depth_first();
		double calc();
        double calc_mid(list<string>&);     //get postfix list
        double calculate(const string& op,const double& ,const double&);
        int  checkPriority(const string&);  //oprator priority
    private:
        pBiNode make_tree(int _begin,int _end);
    private:
        pBiNode mRoot;              //root node
        vector<string> mSrcinput;   //example 1.5+2.4*3 save to "1.5" “+" ”2.4“ "*‘ "3"i
        vector<string> mOrginput;   //just remain () different from up mSrcinput                                    
	};
}
