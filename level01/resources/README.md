## **Level01 - Solution**

While searching the root directory and then the subdirectory `etc/`, we find a file named "passwd". It contains the following line:

`flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash`

This appears to be a flag, "42hDRfypTqqnw", but it doesn't work to move to the next level. By installing the software **John the Ripper**, configuring it with `./configure --without-openssl`, and then compiling it with `make -s clean && make -sj4`, we can use John by providing it with a file containing the string to decrypt. We obtain "abcdefg". This password allows us to proceed to the next level without any issues, with the following token: `f2av5il02puano7naaf6adaaf`.
