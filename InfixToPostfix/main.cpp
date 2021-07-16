// this program converts an infix mathematical expression into its postfix equivalent, using a stack ds
#include<iostream>
#include<stack>
#include<string>

using namespace std;

string InfixToPostfix(string expression);
bool isNumericDigit(char C);
bool isOperator(char C);
int getOperatorWeight(int op);
bool hasHigherPrecedence(char Top, char C);

int main() {
    cout << "Enter an infix expression: ";
    string expression;
    getline(cin, expression);
    string answer = InfixToPostfix(expression);
    cout << "Postfix: " << answer << endl;

    return 0;
}

string InfixToPostfix(string expression) {
    stack<char> S;
    string result = "";
    // still need to add parentheses for separate numbers
    for(int i = 0; i < expression.length(); i++) {
        if(expression[i] == ' ' || expression[i] == ',') continue;

        if(isNumericDigit(expression[i])) {
            result += expression[i];
        }

        else if(isOperator(expression[i])) {
            if(!S.empty() && hasHigherPrecedence(S.top(), expression[i])) {
                while(!S.empty()) {
                    result += S.top();
                    S.pop();
                }
            }
            S.push(expression[i]);
        }
    }

    while(!S.empty()) {
        result += S.top();
        S.pop();
    }
    return result;
}

bool isNumericDigit(char C) {
    if(C >= '0' && C <= '9') return true;
    if(C >= 'a' && C <= 'z') return true;
    if(C >= 'A' && C <= 'Z') return true;
    return false;
}

bool isOperator(char C) {
    if(C == '-' || C == '+' || C == '*' || C == '/') {
        return true;
    }
    return false;
}

bool hasHigherPrecedence(char Top, char C) {
    if((Top == '*' || Top == '/') && (C == '+' || C == '-')) return true;
    return false;
}

