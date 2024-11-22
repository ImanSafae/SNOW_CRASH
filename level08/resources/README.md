Ce nouveau home contient encore un executable intitule level08 et un fichier "token". Lorsqu'on execute le binaire sans argument, il demande un nom de fichier.
En le decompilant avec Ghidra, on obtient un code source avec un main particulierement interessant : cet executable lira dans le fichier qui lui est envoye et affichera le contenu, mais il contient une verification. Si le fichier qui lu iest envoye s'appelle "token", il affiche une erreur indiquant qu'on n'a pas le droit de lire ce fichier. Evidemment, cela serait simple si l'on pouvait renommer le fichier, mais ses droits sont restreints et ne nous permettent pas cette action.
Il suffit donc de creer un lien symbolique dans l'un des rares fichiers de la machine ou nous avons le droit de le faire (j'ai choisi ici /var/tmp) et d'y creer ce lien avec la commande
ln -sf ~/token /var/tmp/tok
On prend bien garde a ne pas inclure la chaine "token" dans le nom du lien symbolique.
On execute ensuite simplement le binaire level08 avec le chemin du lien symbolique :
./level08 /var/tmp/tok
On obtient le token suivant : quif5eloekouj29ke0vouxean
Celui-ci permet de se connecter au level intermediaire flag08 et d'y recuperer le flag.

