## **Level07 - Solution**

In this level, the home directory contains an executable file called `level07` which, when executed, displays the text "level07". 

By decompiling the binary, we discover that it retrieves the `LOGNAME` environment variable and prints its value. The file is executed with the privileges of `flag07`. Therefore, to exploit this, we simply need to modify the `LOGNAME` environment variable to run the `getflag` command.

To do this, we can execute the following command:

```bash
export LOGNAME='`getflag`'
```

This forces the program to execute the `getflag` command when it prints the `LOGNAME` variable to the standard output.

By running the binary again after setting the environment variable, we will retrieve the flag for the next level.
