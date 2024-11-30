Notre dossier home contient un fichier Perl correspondant a un serveur qui recupere les requetes HTML qui lui sont envoyees sur le port 4646. Il attend 2 parametres : x et y, transforme les caracteres minuscules de x en majuscules, et effectue des operations dessus en cherchant une clé x de valeur y dans un fichier /tmp/xd.

L'important ici est qu'il est possible d'injecter du code.
Celui-ci sera converti en majuscules, donc nous créons un fichier /tmp/TEST qui contient getflag | wall.
On donne en paramètre x : /\*/TEST (afin que tmp ne soit pas remplacé par TMP).
On le met entre backticks et on envoie la requete avec :
curl http://localhost:4646/?x='`/*/TEST`'
Ce qui nous permet d'obtenir le flag pour le niveau suivant.
