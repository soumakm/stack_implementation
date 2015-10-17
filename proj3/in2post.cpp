#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include "stack.h"



using namespace std;
using namespace cop4530;

//error handling
bool isOperand(string x)
{
	if(x != "+" &&  x != "-" && x != "*" && x != "/" && x != "(" && x != ")")
		return true;
	else
		return false;
}

bool isOperator(string x)
{
	if(x == "+" || x == "-" || x == "*" || x == "/")
		return true;
	else 
		return false;
}

//This function returns true if 2nd argument has lower precedence than the first
bool isLowerPrecedence(string operator1, string operator2)
{
	   /* if ( operator1 == "*" || operator1 == "/" )
           return true;
        else if ( operator1 == "+" || operator1 == "-" )
        {	
           if ( operator2 == "*" || operator2 == "/" )
              return false;
           else
              return true;
        }

        return false;*/
        if(operator2 == "-" && operator1 != "-")
        	return true;
        else if (operator2 == "+" && (operator1 == "*" || operator1 == "/"))
        	return true;
        else if (operator2 == "*" && operator1 == "/")
        	return true;
        else
        	return false;
}

int main()
{
	// stack to hold the operator
	Stack<string> oprt; 
	//Stack to use for evaluation
	Stack<string> eval;
	//string to rad input line
	string  input;
	//string buffer to hold each string
	string buf;
	//vector of string tokens for input
	vector<string> tokens;
	// output string
	string output;
	//error handling variables
	bool error=false;
	string errorMsg;
	string last;

	while(1)
	{
		output = "";
		oprt.clear();
		tokens.clear();
		cout << "Enter infix expression (\"exit\" to quit): ";
		if(getline(cin, input))
		{
			cout << endl;
			if(input == "exit")
				break;
			stringstream ss(input);
			while (ss >> buf)
				tokens.push_back(buf);

	        for (auto & x: tokens)
	        {
	        	//step 1
	        	if(isOperand(x))
	        		output += " " + x;
	        	
	        	//step 2
	        	if (x == "(")
	        	{
	        		oprt.push(x);
	        	}

	        	//step 3
	        	if(isOperator(x))
	        	{
	        		while(!oprt.empty() && oprt.top() != "(" && (!isLowerPrecedence(x, oprt.top()) && oprt.size() > 0))
	        		{
	        			output += " " + oprt.top();
	        			oprt.pop();
	        		}
	        		oprt.push(x);
	        	}

	        	//step 4
	        	if(x == ")")
	        	{
	        		if(isOperator(last))
	        		{
	        			error = true;
	        			errorMsg = "Cannot have closing prenthesis after an operator!";
	        			break;
	        		}

	        		while(oprt.top() != "(")
	        		{
	        			output += " " + oprt.top();
	        			oprt.pop();
	        		}
	        		if(oprt.top() == "(")
	        			oprt.pop();
	        		else
	    			{
	    				error = true;
	    				errorMsg = "Open parenthesis not found!";
	    			}	
	        	}

	        	last = x;
	        }

	        if(isOperator(last))
	        {
	        	error = true;
	        	errorMsg = "Operator cannot be in the end!";

	        }
            //print rest of the stack
        	while(!oprt.empty())
        	{
        		output += " " + oprt.top();
        		oprt.pop();
        	}
	        

	        // Print output or error message
	        if (error)
				cout << errorMsg << endl;
			else
			{
				cout << "Postfix expression:" << output << endl;
				cout << "Postfix evaluation:" << output << " = " << output << endl;

			}
		}
		else
		{
			cout << endl;
			break;
		}
	}
}