The `home` directory contains an executable called `level03`, which, when executed, displays "Exploit me". By decompiling it with **Ghidra**, we obtain the C source code which displays the following:

```c
v4 = getegid();
v5 = geteuid();
setresgid(v4, v4, v4);
setresuid(v5, v5, v5);
return system("/usr/bin/env echo Exploit me");
```
With an `ls -la` on the home directory, we can see that it is flag03 who owns the rights to the executable, i.e., the user we are trying to log into in order to make him execute getflag. The file is executed under his name. Ideally, we would manipulate it to make it execute `getflag`, but we cannot change the source code (which would cause us to lose the rights and would no longer be useful), nor can we pass it any arguments.

The solution is to modify the environment. Indeed, the code executes the following command: `env echo Exploit me`. It uses the environment to call echo and make it display "Exploit me". By changing the PATH, we can make it retrieve another echo: we recreate echo in the current directory, which is a fake file containing only the getflag command. We add the current directory to the PATH using:

```
export PATH=.:$PATH
```
This way, the command will first look in the current directory and find our fake `echo` (be sure to give execution rights to this file for all users first, with `chmod a+x`). It will then execute it instead of the real `echo`, and in fact, will execute `getflag`. This is how we obtain the flag for the next level.
