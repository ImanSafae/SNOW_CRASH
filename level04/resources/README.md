Dans le dossier home, on retrouve un fichier Perl level04.pl qui semble correspondre a un serveur ecoute sur le port 4747.
Celui-ci recupere les parametres envoyes sur localhost:4747 et les print avec un echo, sans verification ni parsing. Ce manque de securite suggere que l'on peut injecter du code et le faire executer, d'autant plus que le fichier est possede et execute par flag04, c'est-a-dire l'utilisateur auquel on essaie d'acceder. Il suffit donc de faire un :
curl "http://localhost:4747/?x=`getflag`"
Les backticks sont necessaires a l'execution de la commande car sinon le code se contente de "echo" le nom de la commande. Si les backticks ne sont pas pris en compte, il suffit de les encoder avec %60.
