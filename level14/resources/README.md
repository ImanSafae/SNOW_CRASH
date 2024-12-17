## **Level14 - Solution**

For this last level, the home directory contains nothing, and no exploitable files are found through commands like `find` or other exploration methods in the root directory.

There is still one thing that hasn't been exploited, but could have been in previous levels: the `getflag` command itself. How does it retrieve the flags to send?

We can find out by retrieving the `getflag` executable. First, locate it:

`whereis getflag`

Then, send it to the host machine. By decompiling it with Ghidra (again using the decompile explorer), we discover a `main` function containing tokens based on the user's UID. We retrieve the UID of `flag14`, the associated string from the decompiled code, and pass it through the function defined in the code (`ft_des`). This gives us the final flag.

You can now copy and paste this into your Markdown file. Let me know if anything else is needed!
