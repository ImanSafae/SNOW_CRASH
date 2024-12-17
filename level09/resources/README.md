## **Level09 - Solution**

## Level 09

In this level, we find a new binary called `level09` and a file named `token` in the home directory. This time, we have permission to read the `token` file and display its contents, which contain non-printable characters.

As for the executable, we quickly realize that it requires a string argument and returns a string where each character has been shifted by its index according to the ASCII table. 

For example, "abc" becomes "ace" (with +0 on 'a', +1 on 'b', +2 on 'c').

We can deduce that the token has been processed by this script. By writing a C program that reverses this transformation on the string, we can recover the following flag:

`f3iji1ju5yuevaus41q1afiuq`

