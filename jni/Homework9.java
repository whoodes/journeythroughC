/************************************************************
//
//  NAME:        Wyatt Hoodes
//
//  HOMEWORK:    Homework 9
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        Nov 25, 2018
//
//  FILE:        Homework9.java
//
//  DESCRIPTION: A java implementation of Homework1, importing
//               the isDivisible function in the Homework9 lib.
//
*************************************************************/

import java.util.Scanner;
import java.util.*;

class Homework9
{
    public native int isDivisible(int factor, int num);

    static
    {
        System.loadLibrary("Homework9");
    }

    /**********************************************************
    //
    //  Function name: main
    //
    //  Description:   The main method to run the program.
    //
    //  Paramters:     args (String[]) : command line args
    //
    //  return values: void
    //
    ***********************************************************/

    public static void main(String[] args)
    {
        int userChoice = -1;
        int index = 1;
        int factor;
        boolean guard = false;
        Scanner input = new Scanner(System.in);
        Homework9 divisifier = new Homework9();

        System.out.println("\n~~~FACTOR CHECKER 3000~~~\n");
        System.out.println("Check the factors on any Natural number!");
        while (!guard)
        {
            try
            {
                System.out.print("\nPlease enter an integer: ");
                userChoice = input.nextInt();
                if (userChoice > 0)
                {
                    guard = true;
                }
                else
                {
                    System.out.println("\nHmm, I do not recognize the strange symbols...");
                }
            }
            catch(Exception ex)
            {
                System.out.println("\nPlease adhere to the rules, friend!");
                input.next();
            }
        }

        System.out.println("\n    Index    Factor");
        for (int i = userChoice; i > 0; i--)
        {
            if (divisifier.isDivisible(i, userChoice) == 1)
            {
                factor = userChoice / i;
                System.out.printf("%9d", index);
                System.out.printf("%10d", factor);
                System.out.println();
                index++;
            }
        }
        System.out.println();
    }
}
