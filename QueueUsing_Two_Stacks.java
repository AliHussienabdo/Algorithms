/******************************************************************************
 *  Compilation:  javac QueueWithTwoStacks.java
 *  Execution:    java QueueWithTwoStacks < input.txt
 *  Dependencies: StdIn.java StdOut.java
 *  Data files:   https://algs4.cs.princeton.edu/13stacks/tobe.txt
 *
 *  A generic queue, implemented using two stacks.
 *
 *  % java QueueWithTwoStacks < tobe.txt
 *  to be or not to be (2 left on queue)
 *
 ******************************************************************************/

import java.util.NoSuchElementException;
import java.util.Stack;
import java.util.regex.Pattern;
import java.util.Scanner;

public class QueueUsing_Two_Stacks<Item> {
    private Stack<Item> stack1;    // back of queue
    private Stack<Item> stack2;    // front of queue

    // create an empty queue
    public QueueUsing_Two_Stacks() {
        stack1 = new Stack<Item>();
        stack2 = new Stack<Item>();
    }

    // move all items from stack1 to stack2
    private void moveStack1ToStack2() {
        while (!stack1.isEmpty())
            stack2.push(stack1.pop());
    }

    // is the queue empty?
    public boolean isEmpty() {
        return stack1.isEmpty() && stack2.isEmpty();
    }


    // return the number of items in the queue.
    public int size() {
        return stack1.size() + stack2.size();
    }

    // return the item least recently added to the queue.
    public Item peek() {
        if (isEmpty()) throw new NoSuchElementException("Queue underflow");
        if (stack2.isEmpty()) moveStack1ToStack2();
        return stack2.peek();
    }

    // add the item to the queue
    public void enqueue(Item item) {
        stack1.push(item);
    }

    // remove and return the item on the queue least recently added
    public Item dequeue() {
        if (isEmpty()) throw new NoSuchElementException("Queue underflow");
        if (stack2.isEmpty()) moveStack1ToStack2();
        return stack2.pop();
    }


    // a test client
    public static void main(String[] args) {
    	QueueUsing_Two_Stacks<String> q = new QueueUsing_Two_Stacks<String>();
        int i = 5;
        while (i == 0) {
        	Scanner sc = new Scanner(System.in);
            String item = sc.next();
            if (!item.equals("-")) q.enqueue(item);
            else if (!q.isEmpty()) System.out.print(q.dequeue() + " ");
            --i;
        }
        System.out.println("(" + q.size() + " left on queue)");
    }
}