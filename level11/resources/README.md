## **Level11 - Solution**

Le dossier home de ce niveau contient un fichier appelé `level11.lua`. Nous avons également constaté précédemment, grâce à des commandes `ps -aux`, qu'un processus tourne en fond correspondant à un serveur en Lua. Il s'agit bien du fichier que nous avons ici.

Le serveur écoute sur le port 5151, donc nous pouvons nous y connecter avec netcat en utilisant la commande :

`nc localhost 5151`

Le serveur demande ensuite un mot de passe. En observant le code du fichier Lua, nous voyons que le serveur récupère l'input donné après la demande de mot de passe, le print, puis le code en SHA1, et le compare à un hash présent en dur dans le code. Si ces hashes sont égaux, le serveur renvoie `"Gz, you dumb*"`. Sinon, il renvoie `"Erm, nope..."`. En décodant la string présente dans le code, nous obtenons le mot de passe `NotSoEasy`, qui est donc celui attendu.

Cependant, entrer ce mot de passe ne fonctionne pas : le serveur renvoie toujours `"Erm, nope..."`, probablement parce qu'un `\n` doit être ajouté automatiquement.

À ce stade, entrer simplement le bon mot de passe ne nous aide pas beaucoup dans notre quête du flag, il n'est donc pas intéressant d'essayer de rentrer `NotSoEasy` pour obtenir le bon message du serveur.

Le code contient un print qui affiche le mot de passe qui lui est envoyé. Nous pouvons donc injecter du code et tester si cette piste marche.

En envoyant la commande suivante :

`getflag > /tmp/test`

Ensuite, en vérifiant le contenu du fichier `/tmp/test`, on récupère le flag qui permet de passer au niveau suivant.

