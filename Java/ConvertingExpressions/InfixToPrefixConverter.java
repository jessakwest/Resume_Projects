/*  Program by Jessa K. West
    Converting Infix Expressions: InfixToPrefixConverter Code
 
    Currently only works on expressions with single-digit numbers.
 */

public class InfixToPrefixConverter {
    //Overview: reverse infix, convert to postfix, reverse postfix
    public StringBuffer convertToPrefix(StringBuffer infix) {
        StringBuffer reversedInfix = reverseInfix(infix);
        StringBuffer postfix = convertToPostfix(reversedInfix);
        StringBuffer prefix = reversePostfix(postfix);

        return prefix;
    }
    private boolean isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%';
    }
    private int getPrecedence(char operator) {
        switch (operator) {
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':                
                return 2;
            case '^':
            case '%':
                return 3;
            default:
                return 0;
        }
    }
    private boolean evaluatePrecedence(char o1, char o2) {
        return getPrecedence(o1) >= getPrecedence(o2);
    }
    private StringBuffer reverseInfix(StringBuffer infix) {
        StringBuffer reversed = new StringBuffer();
        
        for (int i = infix.length()-1; i >= 0; i--) {
            char c = infix.charAt(i);

            if (c == '(') {
                reversed.append(')');
            }
            else if (c == ')') {
                reversed.append("(");
            }
            else {
                reversed.append(c);
            }
        }
        return reversed;
    }
    private StringBuffer convertToPostfix(StringBuffer expression) {
        Stack<Character> stack = new Stack<>();
        StringBuffer output = new StringBuffer();

        stack.push('(');
        expression.append(')');

        for(int i = 0; i < expression.length(); i++) {
            char c = expression.charAt(i);

            if (Character.isDigit(c)) { 
                output.append(c).append(' '); 
            }
            else if (c == '(') { 
                stack.push(c); 
            }
            else if (isOperator(c)) {
                while (!stack.isEmpty() && evaluatePrecedence(stack.peek(), c) && isOperator(stack.peek())) {
                    output.append(stack.pop()).append(' ');
                }
                stack.push(c);
            }
            else if (c == ')') {
                while (!stack.isEmpty() && evaluatePrecedence(stack.peek(), c) && isOperator(stack.peek())) {
                    output.append(stack.pop()).append(' ');
                }
                stack.pop();
            }
        }
        return output;
    }
    private StringBuffer reversePostfix(StringBuffer postfix) {
        StringBuffer reversed = new StringBuffer();
        for (int i = postfix.length()-1; i >=0; i--) {
            reversed.append(postfix.charAt(i));
        }
        return reversed;
    }
}


