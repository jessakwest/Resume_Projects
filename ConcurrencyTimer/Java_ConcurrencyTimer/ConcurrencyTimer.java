/*  Program by Jessa K. West
    Concurrency Timer Program: Main Code
    
    Concepts: applies multi-threading to compare execution time for different array sizes
*/
import java.util.concurrent.Executors;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.TimeUnit;
import java.util.Random;

public class ConcurrencyTimer {
    public static void main(String[] arg) {
        System.out.printf("%nMulti-Threaded Concurrency Timer Program by Jessa K. West%n");
        ConcurrencyTimer object = new ConcurrencyTimer();
        object.compareTimes();
        System.out.printf("%nEnd of Program.");

    }

    public void compareTimes() {
        long multithreadedStart = System.currentTimeMillis();
        multithreadedArray();
        long multithreadedEnd = System.currentTimeMillis();
        long multithreadedTime = multithreadedEnd - multithreadedStart;
        
        long singlethreadStart = System.currentTimeMillis();
        singlethreadedArray();
        long singlethreadedEnd = System.currentTimeMillis();
        long singlethreadedTime = singlethreadedEnd - singlethreadStart;

        System.out.printf("%nMulti-threaded array took %d milliseconds%n", multithreadedTime);
        System.out.printf("Single-threaded array took %d milliseconds%n", singlethreadedTime);
    }

    public int multithreadedArray() {
        SimpleArray sharedSimpleArray = new SimpleArray(15000000);

        ArrayWriter writer1 = new ArrayWriter(1, sharedSimpleArray);
        ArrayWriter writer2 = new ArrayWriter(7500000, sharedSimpleArray);

        int cores = Runtime.getRuntime().availableProcessors();
        ExecutorService executorService = Executors.newFixedThreadPool(cores);
        executorService.execute(writer1);
        executorService.execute(writer2);

        executorService.shutdown();

        try {
            boolean tasksEnded = executorService.awaitTermination(1,TimeUnit.MINUTES);

            if(tasksEnded) {
                System.out.printf("%nMulti-threaded array created.%nMulti-threaded total array sum: %,d%n", sharedSimpleArray.totalArrayValue());
            }
            else {
                System.out.printf("Timed out while waiting for tasks to finish.%n");
            }
        }
        catch (InterruptedException exception) { 
            exception.printStackTrace();
        }

        return sharedSimpleArray.totalArrayValue();
    }

    public int singlethreadedArray() {
        int[] array = new int[15000000];
        Random random = new Random();
        for (int i = 0; i < array.length; i++) {
            array[i] = random.nextInt(20) + 1;
        }

        int sum = 0;
        for (int value : array) {
            sum += value;
        }

        System.out.printf("%nSingle-threaded array created.%nSingle-threaded total array sum: %,d%n", sum);
        return sum;
    }
}
