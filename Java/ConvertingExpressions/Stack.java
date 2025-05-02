/*  Program by Jessa K. West
    Converting Infix Expressions: Stack Code
 
    Currently only works on expressions with single-digit numbers.
 */

import java.util.NoSuchElementException;

public class Stack<ItemType> {
    private final List<ItemType> stackList;

    public Stack() { stackList = new List<>(); }
    public void push(ItemType data) { stackList.insertAtFront(data); }
    public ItemType pop() throws NoSuchElementException { return stackList.removeFromFront(); }
    public ItemType peek() throws NoSuchElementException { return stackList.peekFront(); }
    public boolean isEmpty() { return stackList.isEmpty(); }
    public void print() { stackList.print(); }
}
