#include <iostream>
#include<cstdlib>
using namespace std;


struct stNode {
    char value;
    stNode* next;
};

stNode* top = NULL;

void Push(char value) {
    stNode temp = (stNode *)malloc(sizeof(stNode));
    temp->value = value;
    temp->next = top;
    top = temp;
}

char pop() {
    if (top == NULL) {
        return -1;
    }

    char poppedvalue = top->value;
    stNode* temp = top;
    top = top->next;
    delete temp;
    return poppedvalue;
}

int precedence(char op) {
    if (op == '*' || op == '/' || op == '%') return 6;
    if (op == '+' || op == '-') return 5;
    if (op == '<' || op == '>' || op == '<=' || op == '>=') return 4;
    if (op == '==' || op == '!=') return 3;
    if (op == '&&') return 2;
    if (op == '||') return 1;
    return 0;
}

string infixToPrefix(string infix) {
    string prefix = "";
    stack<char> s;

    for (int i = infix.length() - 1; i >= 0; i--) {
        char ch = infix[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            prefix = ch + prefix;
        } else if (ch == ')') {
            s.push(ch);
        } else if (ch == '(') {
            while (!s.empty() && s.top() != ')') {
                prefix = s.top() + prefix;
                s.pop();
            }
            if (!s.empty()) s.pop();
        } else {
            while (!s.empty() && precedence(ch) < precedence(s.top())) {
                prefix = s.top() + prefix;
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty()) {
        prefix = s.top() + prefix;
        s.pop();
    }

    return prefix;
}

int main() {
    string infixExpression = "a+(b*c/(x+e)*(y-x*d))";
    cout << "Infix Expression: " << infixExpression << endl;
    cout << "Prefix Expression: " << infixToPrefix(infixExpression) << endl;
    return 0;
}
