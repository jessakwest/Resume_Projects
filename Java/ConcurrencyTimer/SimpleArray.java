/*  Program by Jessa K. West
    Concurrency Timer Program: Simple Array Class
    
    Concepts: applies multi-threading to compare execution time for different array sizes
*/

import java.util.Arrays;

public class SimpleArray {
    private final int[] array;
    private int writeIndex = 0;
    private int totalArrayValue = 0;

    public SimpleArray(int size) {
        array = new int[size];
    }

    public synchronized void add(int value) {
        if (writeIndex < array.length) {
            int position = writeIndex;
            array[position] = value;
            ++writeIndex;
        }
    }

    @Override
    public synchronized String toString() {
        return Arrays.toString(array);
    }

    public synchronized int totalArrayValue() {
        for (int value: array) {
            totalArrayValue += value;
        }
        return totalArrayValue;
    }
}
