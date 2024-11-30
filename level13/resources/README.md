Ce niveau contient un binaire level13. Lorsqu'on l'exécute, il affiche :
UID 2013 started us but we we expect 4242
On peut décompiler ce binaire et voir que celui-ci vérifie en effet le UID de l'utilisateur : s'il ne vaut pas 4242, il affiche ce message et exit. Autrement, il appelle une fonction avec pour argument une string longue, effectue plusieurs opérations sur cette string en remplacant certains caractères. Il print ensuite le résultat final.
On peut donc récupérer ce code en enlevant la vérification initiale. Cela nous print un token qui permet d'accéder au niveau suivant.
