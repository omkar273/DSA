package com;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int odd = 0, even = 0, n;
        int arr[];
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Enter the number of elements you want to enter: ");
        n = scanner.nextInt();
        arr = new int[n];

        for (int i = 0; i < n; i++) {
            System.out.println("Enter the element number " + (i + 1));
            arr[i] = scanner.nextInt();
        }

        for (int i = 0; i < arr.length; i++) {
            if (arr[i] % 2 == 0)
                even++;
            else
                odd++;
        }
        System.out.println("No of odd integers : " + odd);
        System.out.println("No of even integers : " + even);
        scanner.close();
    }

}
