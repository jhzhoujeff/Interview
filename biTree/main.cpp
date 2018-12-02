#include "hello.h"
#include "tools.h"
#include "tree.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
using namespace interviewsoftware;

int main(int argc, char *argv[]) {
	Hello h;
	h.print();

	string str1 = "Peter is boy";
	cout << tools::reverseWords(str1) << endl; // output: boy is Peter
	string str2 = "CocaCola is soft drink";
	cout << tools::reverseWords(str2) << endl; // output: drink soft is CocaCola
	string str3 = "less is more simple is better";
	cout << tools::reverseWords(str3) << endl; // output: better is simple more is less
    
    cout<< "****************************************************************" <<endl;
	cout<< "Complete Binary Tree" << endl;
	try
	{

            
        tree *t1 = new tree("1.5");
		cout << t1->traverse_left_first() << endl;
		cout << t1->traverse_right_first() << endl;
		cout << t1->traverse_depth_first() << endl;
		cout << t1->calc() << endl;
		delete t1;
        cout << "***************************************************" <<endl;
		tree *t2 = new tree("1.5+2.4*3");
		cout << t2->traverse_left_first() << endl;

		cout << t2->traverse_right_first() << endl;
		cout << t2->traverse_depth_first() << endl;
		cout << t2->calc() << endl;
		delete t2;
        cout << "***************************************************" <<endl;

		tree *t3 = new tree("1.5+2.4*3*12-200/4+5.66");
		cout << t3->traverse_left_first() << endl;
		cout << t3->traverse_right_first() << endl;
		cout << t3->traverse_depth_first() << endl;
		cout << t3->calc() << endl;
		delete t3;
        cout << "***************************************************" <<endl;

		tree *t4 = new tree("1.5+2.4*3*12-200/4+5.66/0");
		cout << t4->traverse_left_first() << endl;
		cout << t4->traverse_right_first() << endl;
		cout << t4->traverse_depth_first() << endl;
		cout << t4->calc() << endl;
		delete t4;
        cout << "***************************************************" <<endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

	try
	{
        cout << "***************************************************" <<endl;
		
        tree *t5 = new tree("(1.5+2.4)*3.3");
		cout << t5->traverse_left_first() << endl;
		cout << t5->traverse_right_first() << endl;
		cout << t5->traverse_depth_first() << endl;
		cout << t5->calc() << endl;
		delete t5;
        cout << "***************************************************" <<endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}

