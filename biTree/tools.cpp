#include "tools.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;
using namespace huaguisoftware;

// 试题一说明：
// 要求使用最简洁的代码实现“字符串翻转”功能
// input1: Peter is boy
// output1: boy is Peter
// inout2: CocaCola is soft drink
// output2: drink soft is CocaCola
// input3: less is more simple is better
// output3: better is simple more is less
// 
string tools::reverseWords(string input){
    size_t size=input.size();
    reverse(input.begin(),input.end());
    int start=0;
    int pos=input.find(' ',0);

    while( pos != string::npos) {
        reverse(input.begin()+start,input.begin()+pos);
        start = pos+1;
        pos = input.find(' ',start);
    }

    reverse(input.begin()+start,input.end());
    
    return input;
    //return "not implemented";//
	// 注释上面的代码并在此实现题目的要求。
}

