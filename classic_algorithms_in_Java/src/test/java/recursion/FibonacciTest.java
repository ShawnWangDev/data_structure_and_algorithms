package recursion;

import org.junit.jupiter.api.Test;
import study.recursion.Fibonacci;

public class FibonacciTest {
    Fibonacci fibonacci = new Fibonacci();
    @Test
    void simpleFibonacci(){
        System.out.println(fibonacci.simpleFibonacci(36));
    }

    @Test
    void mappedFibonacci(){
        System.out.println(fibonacci.mappedFibonacci(36));
    }
}
