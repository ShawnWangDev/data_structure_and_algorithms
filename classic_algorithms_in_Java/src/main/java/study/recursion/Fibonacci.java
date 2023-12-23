package study.recursion;

import java.util.HashMap;
import java.util.Map;

public class Fibonacci {
    public int simpleFibonacci(int n) {
        if (n < 2) {
            return n;
        }
        return simpleFibonacci(n - 1) + simpleFibonacci(n - 2);
    }

    static Map<Integer, Integer> memo = new HashMap<>(Map.of(0, 0, 1, 1));

    public int mappedFibonacci(int n) {
        if (!memo.containsKey(n)) {
            memo.put(n, mappedFibonacci(n - 1) + mappedFibonacci(n - 2));
        }
        return memo.get(n);
    }
}
