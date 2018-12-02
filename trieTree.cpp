/*
 * author zhoujinha
 *
 * trieTree.cpp
 * 
 *
 * */

#include "trieTree.h"
#include <assert.h>
#include <string.h>
#include <stdexcept>
#include <iostream>
using namespace std;

trieTreeNode::trieTreeNode()
	:count(0),
	is_word(false) {
		memset(next,0,sizeof(next));
}

trieTree::trieTree()
	:mRoot(NULL) {
	mRoot=CreateNode();
}

ptrieTreeNode trieTree::CreateNode() {
	ptrieTreeNode node=new trieTreeNode();
	assert(node!=NULL);
	return node;
}

void trieTree::Insert(ptrieTreeNode root,char* str) {
	assert(root!=NULL);
	if(str==NULL || !strcmp(str,""))
		return;
	ptrieTreeNode pNode=root;
	char* ptr=str;
	int id=0;
	while(*ptr){
		if(*ptr >='0' && *ptr <= '9') 
			id=*ptr-'0';
		else if (*ptr >= 'a' && *ptr <='z')
			id=*ptr-'a';
		else if (*ptr >= 'A' && *ptr <='Z')
			id=*ptr - 'A';
		else
			throw std::runtime_error("element should between a ~ z or A ~ Z or 0 ~ 9 \n");
	
		if(pNode->next[id]==NULL){
			pNode->next[id] = CreateNode();
		}
		pNode = pNode->next[id];
		pNode->letter=*ptr;
		++ptr;
		pNode->count++;
	}
	pNode->is_word = true;		//after end while the last node is leaf
}

int trieTree::Search(ptrieTreeNode root,char* str){
	assert(root != NULL);
	if(str == NULL || !strcmp("",str))
		return -1;
	char *ptr=str;
	int id=0;
	ptrieTreeNode pnode = root;
	while(*ptr){
		if(*ptr >='0' && *ptr <= '9') 
			id=*ptr-'0';
		else if (*ptr >= 'a' && *ptr <='z')
			id=*ptr-'a';
		else if (*ptr >= 'A' && *ptr <='Z')
			id=*ptr - 'A';
		else
			throw std::runtime_error("element should between a ~ z or A ~ Z or 0 ~ 9 \n");
		pnode=pnode->next[id];
		if(pnode==NULL)
			return 0;
		++ptr;
	}
	return pnode->count;
}

void trieTree::Destroy(ptrieTreeNode root){
	assert(root!=NULL);
	for(int i=0;i<MAX_CHILD_NUM;++i){
		if(root->next[i] != NULL)
			Destroy(root->next[i]);
	}
	delete root;
	root=NULL;
}

void trieTree::DestroyTree(){
	Destroy(mRoot);
}

trieTree::~trieTree(){
	DestroyTree();
}

int trieTree::Search(char* str){
	return Search(mRoot,str);
}

void trieTree::Insert(char* str){
	Insert(mRoot,str);
}

void trieTree::RemoveString(char* str,ptrieTreeNode tree)
{
	assert(tree !=NULL);
	if(str == NULL || !strcmp("",str))
		return ;
	if(*str=='\0')	return;
	
	int id = 0;
	char* ptr = str;
	ptrieTreeNode pnode = tree;
	
	if(*ptr >='0' && *ptr <= '9') 
		id=*ptr-'0';
	else if (*ptr >= 'a' && *ptr <='z')
		id=*ptr-'a';
	else if (*ptr >= 'A' && *ptr <='Z')
		id=*ptr - 'A';
	else
		throw std::runtime_error("element should between a ~ z or A ~ Z or 0 ~ 9 \n");
		
	if(pnode->next[id] !=NULL){
		--pnode->next[id]->count;
		pnode = pnode->next[id];
		++ptr;
		if(*ptr == '\0') pnode->is_word = false;
		RemoveString(ptr,pnode);
	}
}

void trieTree::RemoveString(char* str){
	RemoveString(str,mRoot);
}

void trieTree::Print() const {
	if (mRoot==NULL) return;
	//root save no letter 
	for(int i=0;i<MAX_CHILD_NUM;++i){
		if(mRoot->next[i] != NULL){
			PRINT_RESULT temp=Print(mRoot->next[i]);
			if(!temp.empty()){
				PRINT_RESULT_ITOR itor=temp.begin();
				for(;itor!=temp.end();++itor)
				{
					cout<<*itor << " ";	
				}
				cout<<endl;
			}
		}
	}
	return;
}

PRINT_RESULT trieTree::Print(const ptrieTreeNode root) const {
	assert(root!=NULL);
	string strRtn("");
	strRtn.append(1,root->letter);
	PRINT_RESULT vecRtn;
		
	for(int i=0;i<MAX_CHILD_NUM;++i){
		if (root->next[i] != NULL){
			PRINT_RESULT temp;
			temp=Print(root->next[i]);
			if(!temp.empty()){
				PRINT_RESULT_ITOR itor=temp.begin();
				for(;itor!=temp.end();++itor)
				{
					vecRtn.push_back(strRtn+(*itor));	
				}
			}
		}	
	}
    if (vecRtn.empty() || root->is_word) vecRtn.push_back(strRtn);
	
	return vecRtn;
}
