//this file is used to calculate in reversed polish notation
//first, transform infix manner to postfix manner
//then,use stack to calculate
//we suppose each expression is valid
//and number are all integers, we only consider + - * / ( )
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

stack<char> stk;
string res = "";

//calculate postfix expression
int getByRPN(string postfixExpr){


//use map store operator priority 
    map<char,int> op;
    op['(']=0;
    op[')']=0;
    op['+']=1;
    op['-']=1;
    op['*']=2;
    op['/']=2;

    int a;
    int b;
    int res = 0;
    stack<int> number;
    for(int i = 0; i < postfixExpr.size();i++){
        char aux = postfixExpr[i];
        if(!op.count(aux)){
            int p = aux - '0';
            number.push(p);
        }else{
            switch(aux){
                case '+':
                    a = number.top();
                    number.pop();
                    b = number.top();
                    number.pop();
                    number.push(b + a);
                    break;
                case '-':
                    a = number.top();
                    number.pop();
                    b = number.top();
                    number.pop();
                    number.push(b - a);
                    break;
                case '*':
                    a = number.top();
                    number.pop();
                    b = number.top();
                    number.pop();
                    number.push(b * a);
                    break;
                case '/':
                    a = number.top();
                    number.pop();
                    b = number.top();
                    number.pop();
                    number.push(b / a);
                    break;
            }
        }
    }
    return number.top();
}

//tranform infix to postfix expression
int toPostfix(string s){


//use map store operator priority 
    map<char,int> op;
    op['(']=0;
    op[')']=0;
    op['+']=1;
    op['-']=1;
    op['*']=2;
    op['/']=2;

    int n = s.size();
    for(int i = 0; i < n; i++){
        char tmp = s[i];
        if(op.count(tmp)){
            if(tmp == ')'){
                while(stk.top() != '('){
                    res += stk.top();
                    stk.pop();
                }
                stk.pop();//pop (
            }else if(stk.empty() || tmp == '(' || op[tmp] > op[stk.top()]){
                stk.push(tmp);
            }else if(op[tmp] <= op[stk.top()]){
                while(op[tmp] <= op[stk.top()] && (!stk.empty())){
                    res += stk.top();
                    stk.pop();
                    if(stk.empty()) break;
                }
                stk.push(tmp);
            }
        }else{
            res += tmp; //if number, push
        }
    }
    while(stk.size() > 0){
        res += stk.top();
        stk.pop();
    }
    cout<<"after RPN, the expression is: "<<res<<endl;
    return getByRPN(res);
}


int main(){
    cout<<"please input your valid math expression: "<<endl;
    string expr;
    cin>>expr;
    cout<<"The calculation answer is: "<<toPostfix(expr)<<endl;
    return 0;
}


