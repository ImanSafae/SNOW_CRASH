## **Level06 - Solution**

In this level, the `home` folder contains two files: a script `level06` and a PHP file `level06.php`.

### Step 1: Script behavior
The script sets the privileges of `flag06` and then calls the `level06.php` file with a file path as an argument.

### Step 2: PHP file behavior
The PHP file opens the specified file and reads its content. It uses a regex to retrieve any content in the format `[x {content}]`. It uses the deprecated `/e` modifier in `preg_replace`, which allows executing the parsed string as code (leading to a code injection vulnerability).

The function replaces `[x {content}]` with `y({content})`. The `y()` function replaces the periods (`.`) with " x " and the "@" symbols with " y", then returns the result and prints it. This part is not important for us, but the fact that the `/e` modifier allows code execution is key.

### Step 3: Code injection
We can exploit the `/e` modifier to execute arbitrary PHP code with the privileges of `flag06`. The final string that will be executed, `y({content})`, calls the `y` function. However, we can manipulate the order of operations to execute the code inside `{content}` before calling the `y` function.

To do this, we need to replace the content with a PHP variable using the syntax `{${variable}}`. This causes the code to first evaluate the variable, and then call the `y` function.

### Step 4: Final payload
We want to execute the `getflag` command and print the result. So, we create a file containing:

```
[x {${exec(getflag)}}]
```

The function will first execute `exec(getflag)`, then send the result to the `y` function for further processing, and finally print the result.

### Conclusion
By exploiting the vulnerable use of `preg_replace` with the `/e` modifier, we can execute commands with `flag06`'s privileges and obtain the flag.
