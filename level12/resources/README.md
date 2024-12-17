## **Level12 - Solution**

Our home directory contains a Perl file corresponding to a server that receives HTML requests sent to it on port 4646. It expects 2 parameters: `x` and `y`. It transforms the lowercase characters of `x` to uppercase and performs operations on it by looking for a key `x` with value `y` in a file `/tmp/xd`.

The important part here is that it's possible to inject code.

This code will be converted to uppercase, so we create a file `/tmp/TEST` containing `getflag | wall`.

We then give the parameter `x` the value: `/\*/TEST` (so that `tmp` is not replaced by `TMP`).

We put this command between backticks and send the request with:

`curl http://localhost:4646/?x='`/*/TEST`'`

This allows us to obtain the flag for the next level.
