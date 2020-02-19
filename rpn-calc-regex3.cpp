/*
RPN Calculator in pseudocode
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
for each token in the postfix expression:
  if token is an operand:
    push token onto the stack
  else if token is an operator:
    operand_2 ← pop from the stack
    operand_1 ← pop from the stack
    result ← evaluate token with operand_1 and operand_2
    push result back onto the stack
result ← pop from the stack
*/

#include <stack>
#include <string>
#include <regex>
#include <iostream>
#include <cmath>

using namespace std;

stack<double> st;
string instr;
string num_pattern("(\\+|-)?[0-9]+(\\.[0-9]*)?");
string sym_pattern("(chi|pi|xi|e)");
string op_pattern("(\\*|\\/|\\+|\\-|\\^|ln)");
regex re(num_pattern+"|"+op_pattern+"|"+sym_pattern);

int main(int argc, char **argv) {
    if (argc == 1) return 0;

    instr = argv[1];
    sregex_iterator it(instr.begin(), instr.end(), re);
    sregex_iterator it_end;

    for (;it != it_end; ++it) {
      if (it->str().find_first_not_of("+*/-^%") != it->str().npos) {
        //cout << it->str().c_str() << "   ";
        double op1;
        switch(it->str()[0]) {
          case 'e': st.push( M_E ); break;
          case 'p': st.push( M_PI ); break;
          case 'l': 
            op1 = st.top(); st.pop();
            st.push( log( op1 ) ); break;
          default: 
            st.push( atof(it->str().c_str()) ); break;
        }
      } else {
        double op2 = st.top(); st.pop();
        double op1 = st.top(); st.pop();
        switch(it->str()[0]) {
          case '+': st.push( op1 + op2 ); break;
          case '-': st.push( op1 - op2 ); break;
          case '*': st.push( op1 * op2 ); break;
          case '/': st.push( op1 / op2 ); break;
          case '^': st.push( pow(op1, op2) ); break;
          case '%': st.push( fmod(op1, op2) ); break;
        }
      }
    }
    if (!st.empty()) cout << " = " << st.top() << endl;
  return 0;
}
