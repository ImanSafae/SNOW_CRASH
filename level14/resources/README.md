Pour ce dernier niveau, le dossier home ne contient rien, pas plus qu'on ne trouve quelque chose d'exploitable à force de find et auters moyens d'explorations sur le dossier racine.

Il reste encore une chose qui n'a pas été exploitée mais qui aurait pu l'etre lors des précédents niveaux : la commande getflag elle-meme. Comment recupere-t-elle les flags à envoyer ?
Nous le saurons en récupérant l'exécutable de getflag, d'abord en le localisant :
whereis getflag

Puis en se l'envoyant sur la machine hote. En le décompilant grace à Ghidra (toujours sur decompiler explorer), on découvre une fonction main qui contient des tokens en fonction de l'UID de l'utilisateur. On récupère le UID de flag14, la string associee dans le code décompilé, et on le fait passer par la fonction appelée dans le code (ft_des). Cela nous donne le flag final.
