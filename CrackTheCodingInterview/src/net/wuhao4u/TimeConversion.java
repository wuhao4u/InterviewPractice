package net.wuhao4u;

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;


public class TimeConversion {
    static String timeConversion(String s12) {
        StringBuilder sb24 = new StringBuilder();

        // process s12
        boolean pm = false;
        String ampm = s12.substring(s12.length()-2, s12.length());
        if (ampm.equals("PM")) {
            pm = true;
        }

        String s12Time = s12.substring(0, s12.length()-2);
        String[] s12Split = s12Time.split(":");

        int s12Hour = Integer.valueOf(s12Split[0]);
        int s12Min = Integer.valueOf(s12Split[1]);
        int s12Sec = Integer.valueOf(s12Split[2]);

        if (pm) {

        } else {
            // am
        }

        return sb24.toString();
    }

    public static void main(String[] args) {
        String input = "07:05:45PM";
        String input1 = "12:00:00AM";
        String input2 = "12:00:00PM";
        System.out.println(TimeConversion.timeConversion(input));
    }
}
