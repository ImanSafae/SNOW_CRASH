In the `home` directory, we find a Perl file called `level04.pl` which seems to correspond to a server listening on port 4747. 

This script retrieves parameters sent to `localhost:4747` and prints them with an `echo`, without any validation or parsing. This lack of security suggests that we can inject code and have it executed, especially since the file is owned and executed by `flag04`, which is the user we are trying to access.

To exploit this, we simply need to run the following command:

```bash
curl "http://localhost:4747/?x=\`getflag\`"
```

The backticks are necessary for the execution of the command, as without them the code would just "echo" the name of the command. If the backticks are not taken into account, they can be encoded with %60.
