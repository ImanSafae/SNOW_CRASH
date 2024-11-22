Le dossier home contient un executable intitule level03 qui, une fois, execute, affiche "Exploit me".
En le decompilant avec Ghidra, on obtient le code source en C qui affiche :
  v4 = getegid();
  v5 = geteuid();
  setresgid(v4, v4, v4);
  setresuid(v5, v5, v5);
  return system("/usr/bin/env echo Exploit me");

Avec un "ls -la" sur le dossier home, on constate que c'est flag03 qui possede les droits sur l'executable, c'est-a-dire l'utilisateur auquel on essaie de se connecter afin de lui faire executer un "getflag". Le fichier est execute en son nom. L'ideal serait donc de le manipuler pour lui faire executer getflag ; cependant on ne peut pas changer le code source (cela nous ferait perdre les droits et n'aurait plus d'interet) ni lui passer d'arguments.
La solution est donc de modifier l'environnement ; en effet le code execute la commande suivante :
env echo Exploit me
Il se sert donc de l'environnement pour recuperer echo et lui faire afficher Exploit me. En changeant le path, on peut lui faire recuperer un autre echo : on recree echo dans le dossier courant, il s'agit d'un faux fichier qui contient juste la commande getflag.
Om ajoute le dossier courant au PATH avec
export PATH=.:$PATH
De cette facon, la commande ira chercher dans le dossier courant en premier, et y trouvera notre faux echo (il faut veiller a donner les droits d'execution de ce fichier a tous les utilisateurs avant, avec un chmod a+x). Il l'executera a la place du vrai echo, et executera donc en realite getflag. C'est ainsi qu'on obtient le flag du niveau suivant.
