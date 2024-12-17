## **Level13 - Solution**

## UID Check and String Manipulation

This level contains a binary `level13`. When executed, it displays:

`UID 2013 started us but we expect 4242`

We can decompile the binary and observe that it checks the user's UID: if it isn't `4242`, the message is displayed and the program exits. Otherwise, it calls a function with a long string argument, performs several operations on the string by replacing certain characters, and then prints the final result.

We can bypass the initial UID check, and by doing so, we can retrieve a token that grants access to the next level.
