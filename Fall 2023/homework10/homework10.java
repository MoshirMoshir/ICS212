/*****************************************************************
//
//  NAME:        Alexander Moshir
//
//  HOMEWORK:    homework 10
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        9 December 2023
//
//  FILE:        homework10.java
//
//  DESCRIPTION: User interface to generate a table of numbers based on input
//               label them even or odd.
//
****************************************************************/

import java.util.Scanner;

public class homework10 {

    static 
    {
        System.loadLibrary("homework10");
    }

    public static native int is_even(int num);

/*****************************************************************
//
//  Function name: main();
//
//  DESCRIPTION:   runs the program
//
//  Parameters:    String[] args : command line arguments
//
****************************************************************/

    public static void main(String[] args) {
        int max = user_interface();
        print_table(max);
    }

/*****************************************************************
//
//  Function name: user_interface();
//
//  DESCRIPTION:   Describes the program and gets user input
//
//  Return values:  in : number to generate table up to
//
****************************************************************/

    private static int user_interface() 
    {
        int in = 0;
        Scanner scanner = new Scanner(System.in);

        System.out.println("This program will generate a table of numbers up to the number you enter and label them even or odd.");
        System.out.print("Enter maximum number to show: ");

        while (in <= 0) {
            try 
            {
                in = Integer.parseInt(scanner.nextLine());
                if (in <= 0) 
                {
                    System.out.print("Invalid input. Please enter a positive number: ");
                }
            } catch (NumberFormatException e) 
            {
                System.out.print("Invalid input. Please enter a valid number: ");
            }
        }

        return in;
    }

/*****************************************************************
//
//  Function name: print_table();
//
//  DESCRIPTION:   prints table of numbers and if they are even or odd
//
//  Parameters:    int end : number to generate table up to
//
****************************************************************/

    private static void print_table(int end) 
    {
        System.out.println("Number\tEven or Odd?");
        for (int i = 0; i <= end; i++) {
            if (is_even(i) == 1) 
            {
                System.out.printf("%6d\tEven\n", i);
            } else 
            {
                System.out.printf("%6d\tOdd\n", i);
            }
        }
    }
}