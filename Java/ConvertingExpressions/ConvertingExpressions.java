/*  Program by Jessa K. West
    Converting Infix Expressions: Main Code
 
    Currently only works on expressions with single-digit numbers.
 */

import java.io.IOException;
import java.util.Scanner;

public class ConvertingExpressions {
        static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) throws Exception {
        System.out.printf("%nExpression Conversion Program by Jessa K. West%n-----------%n");
        ConvertingExpressions obj = new ConvertingExpressions();

        try {
            char input;
            do {
                obj.processExpression();
                input = obj.newExpression();
            } while (Character.toUpperCase(input) != 'N');
        }

        catch (IOException e) {
            e.printStackTrace();
        } finally {
            scanner.close();
        }
        
        System.out.printf("End of Program.%n");
    }

    public void processExpression() throws IOException {
        System.out.print("\nEnter infix expression: ");
        String input = scanner.nextLine();

        InfixToPostfixConverter postfixConverter = new InfixToPostfixConverter();
        StringBuffer postfix = postfixConverter.convertToPostfix(new StringBuffer(input));
        
        InfixToPrefixConverter prefixConverter = new InfixToPrefixConverter();
        StringBuffer prefix = prefixConverter.convertToPrefix(new StringBuffer(input));

        System.out.println("\nInfix: " + input);
        System.out.println("Postfix: " + postfix);
        System.out.println("Prefix: " + prefix + '\n');
    }
    public char newExpression(){
        System.out.print("Enter another expression? Y or N: ");
        char c = scanner.next().charAt(0);
        scanner.nextLine();
        return c;
    }

}
