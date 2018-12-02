#include "tree.h"
#include <math.h>
#include <set>
#include <sstream>
#include <iostream>
#include <limits.h>
#include <stack>
#include <list>
using namespace std;
using namespace huaguisoftware;

// 试题二说明：
// 要求设计并实现一个“完全二叉树”，处理加减乘除的计算公式
// 不考虑括号，遇到非数字或者运算符(+-*/)请抛出异常
// 
//判断是否是double
bool isnum(string& s){
    if( !s.empty() ){
        s.erase(0,s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
    }
    stringstream sin(s);
    double t;
    char p;
    if(!(sin >> t)) return false;
    if(sin >> p) return false;
    else return true;
}
// string 2 double
double stringToDouble(string& str){  
    if( !str.empty() ){
        str.erase(0,str.find_first_not_of(" "));
        str.erase(str.find_last_not_of(" ") + 1);
    }
    istringstream iss(str);  
    double num;  
    iss >> num;  
    return num;      
} 
//visit node data
string visit(const pBiNode& p){
    if(p) 
		return p->data+ " ";
	else
		return "";
}

string preorder(const pBiNode& p){
    string temp;
    if(p)
    {
        temp.append(visit(p));
        temp.append(preorder(p->leftchild));
        temp.append(preorder(p->rightchild));
    }
    return temp;
}

string inorder(const pBiNode& p){
    string temp;
    if(p){
        temp.append(inorder(p->leftchild));
        temp.append(visit(p));
        temp.append(inorder(p->rightchild));
    }
    return temp;
}

string rightfirstorder(const pBiNode& p){
    string temp;
    if(p) {
        temp.append(rightfirstorder(p->rightchild));
        temp.append(visit(p));
        temp.append(rightfirstorder(p->leftchild));
    }
    return temp;
}

string postorder(const pBiNode& p){
    string temp;
    if(p){
        temp.append(postorder(p->leftchild));
        temp.append(postorder(p->rightchild));
        temp.append(visit(p));
    }
    return temp;
}

//constuctor
tree::tree(string input){
    mRoot = 0;        			// root init to NULL
    mSrcinput.clear();  		// all node data clear
    mOrginput.clear();
    if(input.size( )== 0) return; // empty tree
    string temp;    
    for(int i=0 ; i< input.size() ; ++i){
        if(input[i] >= '0' && input[i] <= '9'){
            temp.append(1,input[i]);
        }
        else if (input[i] == '.'){
            temp.append(1,input[i]);
        }
        else if (OPERATOR.find(input[i]) != OPERATOR.end()){
            if (!temp.empty()){
                mSrcinput.push_back(temp);
                mOrginput.push_back(temp);
                temp.clear();
            }
            string x;
            x.append(1,input[i]);
            mSrcinput.push_back(x);
            mOrginput.push_back(x);
        }
        else if (input[i] == '(' || input[i] == ')'){
            //ignore the '(' and ')'
            if(!temp.empty()){
                mSrcinput.push_back(temp);
                mOrginput.push_back(temp);
                temp.clear();
            }
            cout << "The  '" << input[i] << "' has been ignored" <<endl; 
            
            string x;
            x.append(1,input[i]);
            mOrginput.push_back(x);         //remain ( ) for calculate
            continue;
        }
        else{
            throw invalid_argument(string(" Exception::error input char : ").append(1,input[i]));
        }
    }

    if(!temp.empty()) {
        mSrcinput.push_back(temp);	// last element push back
        mOrginput.push_back(temp);	// last element push back
    }
    if(mSrcinput.size() >0) make_tree(0,mSrcinput.size());  // make tree
        
}

tree::~tree(){}

pBiNode tree::make_tree(int _begin,int _end){
    int height = 0;
    double rootPos = -1;
    pBiNode newNode = 0;
    
    if( _end - _begin > 0){
        height = log( _end  - _begin )/log(2) + 1;
        newNode = new BiNode();
		// this tree root node init
        if (_begin == 0 && _end == mSrcinput.size())
            mRoot=newNode;
        
		if (height == 1) {	// just one element,then make node and return
            rootPos = 1;
            newNode->data=mSrcinput[_begin];
            newNode->leftchild=0;
            newNode->rightchild=0;
            return newNode;
        }

        // calculate current root node,and assign node data
        rootPos = pow(2.0 , (double)(height - 1));
        newNode->data=mSrcinput[(int)rootPos + _begin - 1];

        // make left child tree
        pBiNode rt=make_tree( _begin,( _begin + (int)rootPos)-1);
        newNode->leftchild = rt;
        
		// make right child tree
        rt = make_tree( _begin+(int)rootPos , _end );        
        newNode->rightchild = rt;
    }
    return newNode;
}

// 左遍历
// 左 根 右 顺序
string tree::traverse_left_first(){

    return  inorder(mRoot); 
	// 注释上面的代码并在此实现题目的要求。
}

// 右遍历
// 右 根 左 方式
string tree::traverse_right_first(){
    return rightfirstorder(mRoot);
	// 注释上面的代码并在此实现题目的要求。
}

// 深度优先遍历
string tree::traverse_depth_first(){
    
    stack<pBiNode> nodeStack;
    nodeStack.push(mRoot);
    string temp;
    while (!nodeStack.empty()){
        pBiNode node = nodeStack.top();
        temp.append(node->data + " ");
        nodeStack.pop();
        if (node->rightchild){
           nodeStack.push(node->rightchild);
        }
        if (node->leftchild){
           nodeStack.push(node->leftchild);
        }
    }

    return temp;
	// 注释上面的代码并在此实现题目的要求。
}

double tree::calculate(const string& op,const double& left,const double& right){
    double d=LONG_MIN; 
    if (left!=LONG_MIN && right!=LONG_MIN){
        if(op == "+") d = left + right ;
        else if(op == "-") d = left - right ;
        else if(op == "*") d = left * right ;
        else if(op == "/"){ 
                if (right!=0) d=left/right;
                else throw std::overflow_error(string("Exception::the divisor is 0"));
            }
        else
            throw std::invalid_argument("Exception :: " + op + " is invalid calculate");
     }           
     return d;           
    
}
int tree::checkPriority(const string& op)
{
    if (op == "+" ||  op == "-")
        return 0;
    else if (op=="*" ||  op == "/")
        return 1;
    else if (op=="(")       
        return 2;
    else if (op==")")
        return 3;
    else
        throw std::invalid_argument("Exception:: " + op + " is invalid");
        
}

// 计算结果
//double tree::calc(){
//	return calc_tree(mRoot); 
	//	return -1;
	// 注释上面的代码并在此实现题目的要求。
double tree::calc_mid(list<string>& st){
    //后缀表达式生成ok了,直接算最后结果.
    stack<double> st_num;   //操作数
    while(!st.empty()){
        string op=st.front();
        if(isnum(op))
            st_num.push(stringToDouble(op));
        else{
            double right = st_num.top();
            st_num.pop();
            double left = st_num.top();
            st_num.pop();

            double d=calculate(op,left,right);
            st_num.push(d);     //计算后结果再次放入
        }
        st.pop_front();
    }

    //完成循环后 st_num 就一个元素，就是最后的值
    double d=st_num.top();
    st_num.pop();
    return d;
}

//利用中缀表达式
double tree::calc(){
    stack<string> st_op;    //操作符号栈
    list<string> out_mid;
    for(int i=0;i<mOrginput.size();++i)
    {

        if(isnum(mOrginput[i])){     //数字直接入栈
            out_mid.push_back(mOrginput[i]);
            continue;
            }
        int priority = checkPriority(mOrginput[i]);
        if(priority >=0 && priority <3){   // + - * / ( 五个个符号
            if(st_op.empty()) {
                st_op.push(mOrginput[i]);    //栈为空，直接入库
                continue;
            }

            int pri_st=checkPriority(st_op.top());
            if (pri_st==2 || priority>pri_st){                 //"(" 直接push
                 st_op.push(mOrginput[i]);
            }
            else if(pri_st>=priority) {          //栈顶优先级>= 新来的操作符号
                 while(pri_st>=priority && pri_st!=2)
                 {
                    string x=st_op.top();
                    out_mid.push_back(x);  
                    st_op.pop();                    //弹出优先级高的运算符
                    if (!st_op.empty())
                         pri_st=checkPriority(st_op.top());
                    else
                        break;
                 }
                 st_op.push(mOrginput[i]);
            }
        }
        else if(priority==3){       //碰到 ")"
            while(!st_op.empty() && checkPriority(st_op.top())!=2) {  
                out_mid.push_back(st_op.top());
                st_op.pop();
            }                       //遇到 "(" 停止
            st_op.pop();            // 弹出 "("     
        }
    }
    while(!st_op.empty()){
        string x=st_op.top();
        out_mid.push_back(x);
        st_op.pop();
    }
    //中缀完成后，直接计算输出结果
    return calc_mid(out_mid);
}

