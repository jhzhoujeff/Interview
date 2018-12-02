#ifndef _INTER_TRIE_TREE__
#define _INTER_TRIE_TREE__
// a~z lower
#define MAX_CHILD_NUM 26
#include<vector>
#include<string>
using std::vector;
using std::string;

typedef vector<string> PRINT_RESULT;
typedef vector<string>::const_iterator PRINT_RESULT_CITOR;
typedef vector<string>::iterator PRINT_RESULT_ITOR;

typedef struct trieTreeNode{
	char letter;				//node represented char 
	int count;					//reference count
	bool is_word;				//is word
	trieTreeNode *next[MAX_CHILD_NUM];	//child
	trieTreeNode();				//constructor
}trieTreeNode,*ptrieTreeNode;

class trieTree {
	public:
		trieTree();
		int Search(char* );
		void Insert(char*);
		void RemoveString(char*);
		void DestroyTree();
		//output ptrieTreeNode's tree
		PRINT_RESULT Print(const ptrieTreeNode) const;
		//void Print(char*) const;
		//out put whole tree
		void Print() const;
		~trieTree();
	private:
		ptrieTreeNode CreateNode();
		int Search(ptrieTreeNode,char*);
		void Insert(ptrieTreeNode,char*);
		void Destroy(ptrieTreeNode);
		void RemoveString(char*,ptrieTreeNode);

	private:
		ptrieTreeNode mRoot;

};
#endif // _INTER_TRIE_TREE__
