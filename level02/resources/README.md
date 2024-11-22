Dans le dossier level02 se trouve un fichier level02.pcap. On peut transferer celui-ci en ssh avec la commande scp, sur la machine hote.
Ce fichier correspond a une capture de paquets reseau et contient des donnees echangees entre deux machines.
En le transferant sur la machine hote avec scp, on peut l'analyser grace a Wireshark, et y decouvrir une tentative de login rate ainsi qu'un mot de passe :
Password: 
ft_wandr...NDRel.L0L
En affichant ceci en hexadecimal, on peut voir que les petits points correspondent en fait a DEL pour indiquer la suppression d'un caractere.
L'utilisateur a donc voulu taper ft_waNDReLOL. Ce mot de passe nous permet d'acceder au niveau intermediaire flag03 et de recuperer le flag qui s'y trouve.  
