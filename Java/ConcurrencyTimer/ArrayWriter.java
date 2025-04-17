/*  Program by Jessa K. West
    Concurrency Timer Program: Array Writer Class
    
    Concepts: applies multi-threading to compare execution time for different array sizes
*/

import java.lang.Runnable;
import java.util.Random;


public class ArrayWriter implements Runnable {
    private final SimpleArray sharedSimpleArray;
    private final int startValue;

    public ArrayWriter(int value, SimpleArray array) {
        startValue = value;
        sharedSimpleArray = array;
    }

    @Override
    public void run() {
        Random random = new Random();
        for (int i = startValue; i < startValue + 7500000; i++) {
            int num = random.nextInt(20) + 1;
            sharedSimpleArray.add(num);
        }
    }
}


