import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'funnyString' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts STRING s as parameter.
     */

    public static String funnyString1(String s) {
        int len = s.length();
        
        for (int i = 1; i < len; i++) {
            if (Math.abs(s.charAt(i) - s.charAt(i - 1)) != 
                Math.abs(s.charAt(len - i) - s.charAt(len - i - 1))) {
                return "Not Funny";
            }
        }
        
        return "Funny";
    }


    public static String funnyString(String s) {
        String result = "Funny";
        StringBuilder sb = new StringBuilder(s);
        String r = sb.reverse().toString();

        boolean isFunny = true;
        int len = s.length();

        for (int i = 1; i < len; i++) {
            if (Math.abs(s.charAt(i) - s.charAt(i - 1)) != Math.abs(r.charAt(i) - r.charAt(i - 1))) {
                isFunny = false;
                break;
            }
        }

        if (!isFunny) {
            result = "Not " + result;
        }

        return result;
    }
}

