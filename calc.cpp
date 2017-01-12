#include <iostream>
#include <string>
#include <stack>
#include<cmath> //Added so we could use pow()-power-.

using namespace std;
int main(int argc, char *argv[]){
	// Simple math expression calculator 3*4/3+5
	// to compile: g++ -Wall -o calc calc.cpp

	// TODO 1. support multi-digits and decimal points 23.23*43.2
	// TODO 2. support paranthesis 
	// TODO 3. support power (^) operation 
	// TODO 4. support functions like sin/cos/log

	cout << "Insert the operation sign(+,-,*,^,/) and numbers in infix : " << endl;
	string infix_line;
	getline(cin, infix_line, '\n');
	string rpn_line = infix_line;
	stack<float> numbers;

	// First lets convert from infix notation to Reverse Polish Notation (NPR)
	// This code could be buggy
	int ni = 0;
	int oi = infix_line.length() - 1;
	for (unsigned int m = 0; m < infix_line.length(); m++) {
		char token = (char)infix_line[m];
		if(token == '+' || token == '-' || token == '*' || token == '/' || token == '^') {
			rpn_line[oi] = token;
			oi --;
		} else {
			rpn_line[ni] = token;
			ni++;
		}
	}

	cout << "RPN line: " << rpn_line << endl;

	// Now, lets parse and calculate the result
	for (unsigned int i = 0; i < rpn_line.length(); i++) {
		char token = (char)rpn_line[i];
		float a,b;
		switch(token) {
			case '+': 
				a = numbers.top();
				numbers.pop();
				b = numbers.top();
				numbers.pop();
				numbers.push(a+b);
				break;
			case '-':
				a = numbers.top();
				numbers.pop();
				b = numbers.top();
				numbers.pop();
				numbers.push(b-a);
				break;
			case '*':
				a = numbers.top();
				numbers.pop();
				b = numbers.top();
				numbers.pop();
				numbers.push(a*b);
				break;
			case '/':
				a = numbers.top();
				numbers.pop();
				b = numbers.top();
				numbers.pop();
				numbers.push(b/a);
				break;
			case '^':
				a = numbers.top();
				numbers.pop();
				b = numbers.top();
				numbers.pop();
				numbers.push(pow(a,b));
				break;
			default: // This must be a number, lets push it onto the stack
				numbers.push((float)(token-'0'));
				break;
		}
	}

	cout << "The result is: " << numbers.top() << endl;

	return 0;
}

