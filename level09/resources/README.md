Dans ce niveau, on trouve dans le dossier home un nouveau binaire level09 et un fichier token. Cette fois-ci, on a des droits sur le fichier token qui nous permettent d'afficher son contenu. Celui-ci contient des caracteres non imprimables.
Quant a l'executable, on se rend compte assez vite que celui-ci requiert un argument de type string, et renvoie une string dont chaque caractere a subi un +index selon la table ascii.
Par exemple, "abc" devient "ace" : +0 sur le a, +1 sur le b, +2 sur le c.
On peut donc deduire que le token a subi un passage du script. En redigeant un programme en C qui effectue l'inverse sur la string, on peut ainsi recuperer le flag suivant : f3iji1ju5yuevaus41q1afiuq
