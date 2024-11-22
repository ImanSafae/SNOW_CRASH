En fouillant dans le dossier racine, puis dans le sous-dossier etc/, on trouve un fichier intitule "passwd".
Celui-ci contient la ligne suivante : 
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash

Ce qui semble etre un flag, "42hDRfypTqqnw" ne fonctionne pas pour passer au level suivant.
En installant le logiciel John the Ripper, configure avec 
./configure --without-openssl
puis compile avec
make -s clean && make -sj4
nous pouvons utiliser John en lui donnant en argument un fichier qui contient la string a decrypter. Nous obtenons "abcdefg". Ce mot de passe nous permet de passer au niveau suivant sans probleme avec le token suivant : f2av5il02puano7naaf6adaaf
