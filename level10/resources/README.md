Dans ce niveau, on trouve un executable level10 ainsi qu'un fichier token sur lequel on n'a pas d'acces.
L'executable demande une IP et s'y connecte sur le port 6969 pour y envoyer un fichier. On cree donc un serveur qui ecoute sur le port 6969. L'executable teste l'acces au fichier donne avec la fonction access, ppuis l'ouvre un peu plus bas avec la fonction open.
L'idee est donc de remplacer le fichier entre ces 2 verifications.
On procede avec un lien symbolique : dans un premier temps, celui-ci pointe sur un fichier target que l'on a cree (et qui passe donc la verification d'access). Puis, ce lien pointe vers token avant d'arriver a open.
 
On cree donc un programme en C qui change le lien en boucle, ainsi que level10.
Avec de la chance nombre d'essais font le check d'access pendant que le lien symbolique pointe sur un fichier autorisé, et avant le open, le lien aura été modifié pour pointer sur token.
Cela resulte en : le premier check a ete validé, le deuxieme aussi et le contenu de token est envoyé au serveur. On obtient ce flag : woupa2yuojeeaaed06riuj63c , qui nous permet de nous connecter au niveau intermediaire flag10 et d'obtenir le flag du level11.
