## **Level10 - Solution**

In this level, we find an executable called `level10` and a file named `token`, which we don't have access to.

The executable asks for an IP and connects to port 6969 to send a file. To proceed, we create a server that listens on port 6969. The executable checks file access with the `access` function and then opens the file later with the `open` function.

The idea is to replace the file between these two checks.

We proceed with a symbolic link: initially, it points to a target file that passes the access check. Then, the link points to the `token` file before the `open` function.

We create a C program that changes the symbolic link in a loop, along with the `level10` executable. 

With some luck, after several attempts, the access check will pass while the symbolic link points to an allowed file, and before the `open` function, the link will have been modified to point to `token`.

This results in: the first check is passed, the second check also succeeds, and the content of `token` is sent to the server. We obtain the flag: 

`woupa2yuojeeaaed06riuj63c`

This allows us to connect to the intermediate level `flag10` and retrieve the flag for level 11.


