#include<bits/stdc++.h>
using namespace std;
int prec(char c){
    if(c=='+'||c=='-')
    return 1;
    if(c=='*'||c=='/')
    return 2;
    return 0;
}
int apply(int a, int b, char op){
    if(op=='+')
        return a+b;
    else if(op=='-')
        return a-b;
    else if(op=='*')
        return a*b;
    else if(op=='/')
        return a/b;
}
int evaluate(string s){
    stack<int> values;
    stack<char> op;
    for(int i=0; i<s.length(); i++){
        if(s[i]==' ')
        continue;
        if(s[i]=='('){
            op.push(s[i]);
        }
        else if(isdigit(s[i])){
            int val=0;
            while(i<s.length() && isdigit(s[i])){
                val= (val*10) + (s[i]-'0');
                i++;
            }
            values.push(val);
            i--;
        }else if(s[i]==')'){
            while(!op.empty() && op.top()!='('){
                int val1=values.top();
                values.pop();
                int val2=values.top();
                values.pop();
                char opr=op.top();
                op.pop();
                int temp=apply(val2, val1, opr);
                values.push(temp);
            }
            if(!op.empty()){
                op.pop();
            }
        }else{
            while(!op.empty() && prec(op.top()) >= prec(s[i])){
                int val1=values.top();
                values.pop();
                int val2=values.top();
                values.pop();
                char opr=op.top();
                op.pop();
                int temp=apply(val2, val1, opr);
                values.push(temp);
            }
            op.push(s[i]);
        }
    }
    while(!op.empty()){
        int val1=values.top();
        values.pop();
        int val2=values.top();
        values.pop();
        char opr=op.top();
        op.pop();
        int temp=apply(val2, val1, opr);
        values.push(temp);
    }
    return values.top();
}
int main(){
    cout<<evaluate("10+20-(40/20*3)");
}