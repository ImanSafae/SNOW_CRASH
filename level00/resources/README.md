### **Flag00 - Solution**

By executing `find / -user flag00`, we get a list of files owned by the user `flag00`. There are two files:

- `/usr/sbin/john`
- `rofs/usr/sbin/john`

Both files contain the same string: `cdiiddwpgswtgt`. Decoding this string using the Caesar cipher gives us: **"nottoohardhere"**. This password allows us to log into the intermediate level `flag00` and obtain the token to access level `level01`.
