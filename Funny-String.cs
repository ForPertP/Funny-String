using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Result
{

    /*
     * Complete the 'funnyString' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts STRING s as parameter.
     */

    public static string funnyString(string s)
    {
        int len = s.Length;

        for (int i = 1; i < len; i++)
        {
            if (Math.Abs(s[i] - s[i - 1]) != Math.Abs(s[len - i] - s[len - i - 1]))
            {
                return "Not Funny";
            }
        }

        return "Funny";
    }


    public static string funnyString2(string s)
    {
        string result = "Funny";
        string r = new string(s.Reverse().ToArray());

        bool isFunny = true;
        int len = s.Length;

        for (int i = 1; i < len; i++)
        {
            if (Math.Abs(s[i] - s[i - 1]) != Math.Abs(r[i] - r[i - 1]))
            {
                isFunny = false;
                break;
            }
        }

        if (!isFunny)
        {
            result = "Not " + result;
        }

        return result;
    }
}


class Solution
{
    public static void Main(string[] args)
    {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        int q = Convert.ToInt32(Console.ReadLine().Trim());

        for (int qItr = 0; qItr < q; qItr++)
        {
            string s = Console.ReadLine();

            string result = Result.funnyString(s);

            textWriter.WriteLine(result);
        }

        textWriter.Flush();
        textWriter.Close();
    }
}
