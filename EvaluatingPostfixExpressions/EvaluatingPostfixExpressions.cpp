// EvaluatingPostfixExpressions.cpp 
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

double evaluatePostfix(vector<string> exp);

int main()
{
    //Postfix expression
    vector<string> exp{ "3", "1", "+", "5", "*" };

    double expResult = evaluatePostfix(exp);

    cout << "The result of the expressions is " << expResult << endl;

}


double evaluatePostfix(vector<string> exp)
{
    //Argument stack
    stack<double> stk;

    //Argument holders
    double arg1, arg2, result;

    string operators = "+-*/%^";

    for (string sym : exp) {
        //Are you a numeric argument?
        if (operators.find(sym) == string::npos) {
            //Store argument on the stack
            stk.push(stod(sym));
        }
        else {
            arg2 = stk.top(); stk.pop();
            arg1 = stk.top(); stk.pop();

            // Evaluate the current operator
            if (sym == "+") {
                result = arg1 + arg2;
                stk.push(result);
            }
            else if (sym == "*") {
                result = arg1 * arg2;
                stk.push(result);
            }
            //TODO - similar logic for the remaining operators

        }
    }//for

    return  stk.top();
}
