Dans ce niveau, le dossier home contiemt un script level06 et un fichier level06.php.
Le script etablit les privileges de flag06 et appelle le fichier level06.php avec en argument un nom de chemin vers un fichier.
Le fichier PHP quant a lui, ouvre ce fichier et lit son contenu, et recupere grace a une regex toute expression de la forme [x {contenu}]. Il utilise la fonction preg_replace avec le modificateur /e ; celui-ci est deprecie pour des raisons de securite, car il permet d'executer la string parsee comme du code (et permet donc une injection de code, ce que nous allons exploiter ici).
La fonction remplace le donc [x {contenu}] par y({contenu}), y etant une fonction definie dans le fichier qui remplace les "." par des " x " et les "@" par des " y" avant de renvoyer le resultat et de le print. Le remplacement nous importe peu : l'important ici est que le modificateur /e permet d'executer du code, le tout avec les privileges de flag06.
La string finale qui sera executee, donc y({contenu}), appellera la fonction y mais nous pourrons faire en sorte de jouer des priorites afin de faire executer le code dans {contenu} avant l'appel a la fonction y ; il faut pour cela remplacer le contenu par une variable avec la syntaxe PHP : {${variable}}
Le code gerera d'abord la variable puis l'appel a la fonction. Ici, la variable sera donc le resultat de getflag, que nous souhaitons finir par print.
Donc nous creons un fichier qui contient :
[x {${exec(getflag)}}]
La fonction va executer en priorite exec(getflag) puis envoyer son resultat a la fonction y pour y remplacer ce qui doit etre remplace, le renvoyer puis le print.
