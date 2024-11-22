En executant "find / -user flag00", on obtient une liste des fichiers possedes par l'utilisateur flag00.
Ceux-ci sont au nombre de 2 :
- /usr/sbin/john
- rofs/usr/sbin/john
Ces 2 fichiers contiennent la même string : cdiiddwpgswtgt
En decodant cette string avec le code Cesar, on obtient : "nottoohardhere" qui permet de se connecter au niveau intermediaire flag00 et d'obtenir le token qui permet d'acceder au niveau level01.
