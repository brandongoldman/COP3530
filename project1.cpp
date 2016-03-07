/* 
	Project 1 - Calculator
	Brandon Goldman
	COP3530 - Spring 2016
*/

#include <iostream>			// cin from console
#include <string> 			// store characters as string
#include <unordered_map>	// store variable declarations
#include <stack>			// convert infix -> postfix
#include <sstream>			// for getline
#include <math.h>			// for exponential algebra
#include <stdexcept>

using namespace std;

/*	This project utilizes the built in Stack and Hashmap libraries in C++ to create a
	calculator that takes in an infix expression and converts to postfix using the
	Shunting Yard Algoirthm. The program uses a hashmap to efficiently handle variable
	declarations (where the program uses the String library to find the keyword 'let' 
	to declare a variable).
 */


// remove blank spaces from infix equation so that we can parse
string removeSpaces(string infixEquation)
{
    int size = infixEquation.size();
    string s; // s will be expression without spaces

    for (int i = 0; i < size; i++)
    {
    	// if char is not a space, push char to infix equation string
        if (infixEquation.at(i) != ' ')
        {
            s.push_back(infixEquation.at(i));	// appends character at position i to end of string, increasing length by one.
        }
    }

    // else 
    	// skip over char
    return s;
}

// method to calculate answer
// takes in operator, and two numbers from the stack
string Evaluate(char op, double op1, double op2, int &flag)
{
    double answer;
    stringstream stream;

    if(op == '+')
    {
    	answer = op1 + op2;
    }

    else if(op == '-')
    {
    	answer = op1 - op2;
    }

    else if(op == '*')
    {
    	answer = op1 * op2;
    }

    else if(op == '/')
    {
    	// throw flag if you try to divide by zero
    	if(op2 == 0)
    	{
    		cout << "Division-By-Zero" << endl;
    		flag = 2;
    	}

    	else
    		answer = op1 / op2;
    }

    else if(op == '^')
    {
    	// use math function from math library
    	answer = pow(op1,op2);
    }

    stream << answer;
    return stream.str();
}

// this function will allow program to search hashtable to check if variable exists (or is undeclared)
string insertHashKey(unordered_map<string, string> &mapOfVariables, string expression, int &flag)
{
	// hashmap key is string (used for parsing) and the value is kept as string
	// essentially, let x = 5 --> (x,5) at [0]
	// map is name of variable
    unordered_map<string, string>::const_iterator map = mapOfVariables.find(expression);
    
    // if the variable exists, declare / update it
    if (map != mapOfVariables.end())
    {
        expression = map->second;
    }

    // otherwise the variable isn't declared
    else
    {
        cout << "Undeclared-Variable" << endl;
        flag = 1;
    }

    return expression;
}

// use shunting yard algorithm to conver to postfix equation
string convertToPostfix(string expression, unordered_map<string, string> &mapOfmapOfVariablesiables, int &flag)
{
	// create map to declare mapOfVariablesiable precedence similar to:
		// operator precedence
		int opPriority(const string &op) 
		{
		  switch (op) 
		  {
		    case '^': return 3;
		    case '/': return 2;
		    case '*': return 2;
		    case '+': return 1;
		    case '-': return 1;
		    default : return 0;
		  }
		}

    // create stack to hold operands
    stack<char> elements;

    string postfix; // infix equation after conversion
    string s;
    string tempmapOfVariables;

    for(int i = 0; i < size; i++)
    {

        if(isdigit(charIterator) || charIterator == '.')
        {
            s.push_back(charIterator);
        }


        // corner case if just character, push char
        else if(isalpha(charIterator))
        {
            tempmapOfVariables.push_back(charIterator);
        }

        // handle parenthesis
        else if(charIterator == '(')
        {
            elements.push(charIterator);
        }

        else if(charIterator == ')')
        {
            while(!elements.empty() && elements.top() != '(')
            {
                postfix.push_back(elements.top());
                elements.pop();
            }

            elements.pop();
        }

        // if char is operator
        else if(charIterator == '+' || charIterator == '-' || charIterator == '*' || charIterator == '/' || charIterator == '^')
        {
        	// if occurs after parenthesis, push char operator
            if(elements.empty() || elements.top() == '(')
            {
                elements.push(charIterator);
            }

            // get priority of operator
            else
            {
            	// assume no parenthesis, stack pops double 
                while (!elements.empty() && elements.top() != '(' && ! isdigit(elements.top()) && charIterator != '^' && priority.at(charIterator) <= priority.at(elements.top()))
                {
                    postfix.push_back(elements.top());
                    elements.pop();
                }

                elements.push(charIterator);
            }
        }
    }

    return postfix;
}


// iterate through expression, pop two operands and will evaluate expression
string extractOperands(string expression, int &flag)
{
    stack<string> elements;
    int size = expression.size();
    string s;

    for(int i = 0; i < size; i++)
    {
    	// when expression iterates to operator, pop two operands from stack for evaluation
        if(expression.at(i) == '+' || expression.at(i) == '-' || expression.at(i) == '*' || expression.at(i) == '/' || expression.at(i) == '^' )
        {
                double element2 = stod(elements.top().c_str());
                elements.pop();

                // second element popped will be first operand
                double element1 = stod(elements.top().c_str());
                elements.pop();

                // send the two popped values to Evaluate method
                elements.push(Evaluate(expression.at(i), element1, element2, flag));
                
                if(flag != 0)
                {
                    return "";
                }
        }

        // if expression does not iterate to operator, check if decimal exists
        else if (isdigit(expression.at(i)) || expression.at(i) == '.')
        {
            while (i < size && (isdigit(expression.at(i)) || expression.at(i) == '.'))
            {
                s.push_back(expression.at(i));
                i++; // move iterator
            }
        }
        if (s.size() > 0)
        {
            elements.push(s);
            s.clear();
        }
    }
    // return elements for use of evaluation
    return elements.top().c_str();
}


// take input and push to hashmap
// done in O(1) time (worst case look up is O(n))
int insertHashValue(string in, unordered_map<string,string> &mapOfVariables)
{
    string element;
    string elements;
    // assume flag doesn't exist
    int flag = 0;
    int it = 0;
    
    // this will handle the remaining portion of the string from main method after "let __ " was removed
    while(in.at(it) != '=')
    {
        element.push_back(in.at(it));   // we want to push the value to the hashtable
        in.erase(in.begin());			// erase by iteration
    }

    unordered_map<string,string>::const_iterator value = mapOfVariables.find(element);
 
 	// add expression in string after equal sign 
    elements.append(in.substr(1, in.size() - (it + 1)));
    
    elements = convertToPostfix(elements, mapOfVariables, flag);
    
    // if not divide by zero or not undefined
    if(flag != 1 && flag != 2)
    {
        if(value != mapOfVariables.end())
        {
        	// remove variable from expression
            mapOfVariables.erase(element);
            // pair variable with expression
            mapOfVariables.insert(make_pair<std::string, string>(element.c_str(), extractOperands(elements, flag)));
        }

        else
        {
        	// repeat until you reach end of mapOfVariables
            mapOfVariables.insert(make_pair<std::string, string>(element.c_str(), extractOperands(elements, flag)));
        }
    }
    return flag;
}

int main()
{
	// make cin faster
	std::ios::sync_with_stdio(false);

	// create hashtable to contain variable declarations
    unordered_map<string, string> mapOfVariables;
    
    // input will contain expressions and variable declarations in form of string
    string input;

    while(input != "quit")
    {
        getline(std::cin, input);	// this will get entire line from console rather than just one word before first space

        string s;
        string varDeclaration = "let";
        int flag = 0;

        // search for keywords 'let' and 'quit'
        size_t quit = input.find("quit");
        size_t let = input.find("let");

        // follow until end of string
        if (quit != string::npos) // if quit was NOT found...
        {
            break;	// prevent console from outputting data values unnecessarily 
        }

        if (let != string::npos) // if let was NOT found...
        {

            input = removeSpaces(input);
            input.erase(let, let + (varDeclaration.size()));	// remove word 'let' from string
            insertHashValue(input, mapOfVariables); 			// insert remaining portion of string to hashmap
        }

        else
        {
            if(mapOfVariables.size() > 0)
            {
                s = convertToPostfix(input, mapOfVariables, flag);
                
                if(flag != 1 && flag != 2)
                { 
                    string output = extractOperands(s, flag);
                        
                    if(flag != 1 && flag != 2)
                    {
                        cout << output << endl;
                    }
                    // if not, the program will cout message from findExpressionInMap or Evaluate method
                }            
            }

            else
            {
                
                string output = convertToPostfix(input, mapOfVariables, flag);
                
                if(flag != 1 && flag != 2)
                {
                    output = extractOperands(output, flag);
                    
                    if(flag != 1 && flag != 2)
                    {
                        cout << output << endl;
                    }
                    // if not, the program will cout message from findExpressionInMap or Evaluate method

                }
            }
        }
    }
    return 0;
}
