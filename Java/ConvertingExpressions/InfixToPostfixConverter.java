/*  Program by Jessa K. West
    Converting Infix Expressions: InfixToPostfixConverter Code
 
    Currently only works on expressions with single-digit numbers.
 */

public class InfixToPostfixConverter {
    public StringBuffer convertToPostfix(StringBuffer infix) {
        Stack<Character> stack = new Stack<>();
        StringBuffer postfix = new StringBuffer();

        stack.push('(');
        infix.append(')');

        for(int i = 0; i < infix.length(); i++) {
            char c = infix.charAt(i);

            if (Character.isDigit(c)) { postfix.append(c).append(' '); }
            else if (c == '(') { stack.push(c); }
            else if (isOperator(c)) {
                while (!stack.isEmpty() && evaluatePrecedence(stack.peek(), c) && isOperator(stack.peek())) {
                    postfix.append(stack.pop()).append(' ');
                }
                stack.push(c);
            }
            else if (c == ')') {
                while (!stack.isEmpty() && evaluatePrecedence(stack.peek(), c) && isOperator(stack.peek())) {
                    postfix.append(stack.pop()).append(' ');
                }
                stack.pop();
            }
        }
        return postfix;
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
}
