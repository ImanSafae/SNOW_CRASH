Le dossier home du level07 contient un fichier executable level07 qui affiche une fois execute... "level07".
En le decompilant, on decouvre que celui-ci recupere dans l'environnement la variable LOGNAME et la print. Le fichier est execute avec les privileges de flag07. Ainsi, il suffit de remplacer LOGNAME avec la commande suivante :
export LOGNAME='`getflag`'
Ceci pour le forcer a executer la commande lorsque getflag est affiche dans la sortie standard. On recupere ainsi le flag du niveau suivant en executant le binaire de nouveau.
