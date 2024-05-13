#include <iostream>
#include<cstdlib>
using namespace std;

struct stNode
{
    int	value;
	stNode *next;
	
};
stNode *top=NULL;

void Push(int value){
	
    stNode temp = (stNode *)malloc(sizeof(stNode));
    temp->value = value; 
    temp->next = top;
    top = temp;
	
}

int pop(){
	
	if(top == NULL){
		return -1;
	}
	
	int poppedvalue= top->value;
	stNode* temp=top;
	top=top->next;
	free(temp);
	return poppedvalue;

}

int precedence(char op){
    if (op=='*'|| op=='/' || op=='%') return 6;
    if (op=='+'|| op=='-' ) return 5;
    if (op=='<'|| op=='>' || op=='<='|| op=='=>') return 4;
    if (op=='==' || op=='!=') return 3;
    if (op=='&&') return 2;
    if (op=='||') return 1;
    return 0;
}
string infixToPostfix(string infix) {
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            postfix += ch;
        } else if (ch == '(') {
            Push(ch);
        } else if (ch == ')') {
            while (top != NULL && top->value != '(') {
                postfix += top->value;
                pop();
            }
            if (top != NULL)
                pop();
        } else {
            while (top != NULL && precedence(ch) <= precedence(top->value)) {
                postfix += top->value;
                pop();
            }
            Push(ch);
        }
    }

    while (top != NULL) {
        postfix += top->value;
        pop();
    }

    return postfix;
}



int main() {
    string infixExpression = "a+(b*c/(x+e)*(y-x*d))";
    cout << "Infix Expression: " << infixExpression << endl;
    cout << "Postfix Expression: " << infixToPostfix(infixExpression) << endl;
    return 0;

}