/*  Program by Jessa K. West
    Converting Infix Expressions: Linked List & List Node Code
 
    Currently only works on expressions with single-digit numbers.
 */

import java.util.NoSuchElementException;

class ListNode<ItemType> {
    ItemType data;
    ListNode<ItemType> next;

    ListNode(ItemType data) { this(data, null); }

    ListNode(ItemType data, ListNode<ItemType> next) {
        this.data = data;
        this.next = next;
    }

    ItemType getData() { return data; }

    ListNode<ItemType> getNext() { return next; }
}

public class List<ItemType> {
    private ListNode<ItemType> head;
    private ListNode<ItemType> tail;

    public List() { head = tail = null; }

    public void insertAtFront(ItemType item) {
        if (isEmpty()) {
            head = tail = new ListNode<ItemType>(item);
        }
        else {
            head = new ListNode<ItemType>(item, head);
        }
     }
    public void insertAtBack(ItemType item)  {
        if (isEmpty()) {
            head = tail = new ListNode<ItemType>(item);
        }
        else {
            tail.next = new ListNode<ItemType>(item);
            tail = tail.next;
        }
    }
    public ItemType removeFromFront() throws NoSuchElementException {
        if (isEmpty()) { throw new NoSuchElementException("Empty list."); }

        ItemType removed = head.data;

        if ( head == tail) { head = tail = null; }
        else { head = head.next; }
        return removed;
     }
    public ItemType removeFromBack() throws NoSuchElementException {
        if (isEmpty()) { throw new NoSuchElementException("Empty list."); }

        ItemType removed = tail.data;

        if (head == tail) { head = tail = null; }
        else {
            ListNode<ItemType> current = head;
            while (current.next != tail) {
                current = current.next;
            }
            tail = current;
            tail.next = null;
        }
        return removed;
    }
    public boolean isEmpty() { return head == null; }
    public ItemType peekFront() throws NoSuchElementException {
        if (isEmpty()) { throw new NoSuchElementException("Empty list."); }
        return head.data;
    }
    public void print() {
        if (isEmpty()) {
            System.out.println("Empty list");
            return;
        }

        System.out.println("List contents: ");
        ListNode<ItemType> current = head;

        while(current != null) {
            System.out.printf("%s ", current.data);
            current = current.next;
        }
        System.out.println();
    }
}