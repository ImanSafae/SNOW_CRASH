## **Level08 - Solution**

In the home directory of level 08, there is an executable file called `level08` and a file named `token`. When the binary is executed without any arguments, it asks for a filename.

Upon decompiling the binary with Ghidra, we find a particularly interesting `main` function. This executable will read the contents of the file provided to it and display it. However, there is a check: if the file being read is named `token`, it will display an error indicating that you do not have permission to read this file. 

Of course, it would be easy to bypass this if we could rename the file, but its permissions are restricted, and we are unable to perform this action.

The solution is to create a symbolic link in one of the few locations where we have permission to do so (in this case, `/var/tmp`). To create the symbolic link, run the following command:

```bash
ln -sf ~/token /var/tmp/tok
```

Be careful not to include the string "token" in the name of the symbolic link.

Next, simply execute the level08 binary with the path to the symbolic link:
```
./level08 /var/tmp/tok
```
This will return the following token: quif5eloekouj29ke0vouxean.

This token allows you to connect to the intermediate level flag08 and retrieve the flag.
