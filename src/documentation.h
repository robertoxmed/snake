/** \mainpage Snake

\section Introduction
Projet Snake réalisé par Roberto Medina Bonilla (roberto.medina-bonilla@etu.univ-lyon1.fr) et Yoann Jouvent (yoann.jouvent@etu.univ-lyon1.fr).\n
Code écrit en C utilisant la librairie SDL pour l'affichage graphique.\n
Projet réalisé pour l'UE LIF7 à l'Université Lyon 1.\n
Page web du projet: http://lif7prosnake.codeplex.com/\n
Serveur svn: https://lif7prosnake.svn.codeplex.com/svn

\section Hiérarchie
Dans le répertoire <b>svn</b> il y a deux projets codeblocks: <i>Snake.cbp</i> (pour jouer) <i>Regression.cbp</i> (les tests de regression). Le <i>Makefile</i> est aussi inclus pour compiler depuis le terminal.\n
Une description brève se trouve dans le fichier <i>README.txt</i>\n\n
Dans le répertoire <b>svn/data</b> on retrouve les différents fichiers nécéssaires pour l'affichage, l'initialisation de quelques données.\n\n
Dans le répertoire <b>svn/src</b> on retrouve les différents fichiers <i>.h</i> et <i>.c</i> .\n\n
Dans le répertoire <b>svn/doc</b> on retrouve le doxyfile <i>snake.dox</i> qui permet de créer la documentation. La présentation (<i>.pdf</i> & <i>.odp</i>), le diagramme des modules et le cahier des charges sont inclus dans le répertoire.\n

\section Compiler
Projet réalisé sur Linux (Ubuntu 12.04 & 11.04).\n

Dépendance:\n
    - ncurses (libncurses5-dev)\n
    - SDL (libsdl1.2-dev & libsdl-ttf2.0-dev)\n

<b> /!\ La réalisation de l'affichage en mode texte (ncurses) a servi seulement pour le début du développement, le but final était d'utiliser SDL pour un rendu plus esthétique.</b>\n

Pour instaler les librairies:\n
...$ sudo apt-get install libncurses5-dev libsdl1.2-dev libsdl-ttf2.0-dev\n

Depuis le répertoire svn:\n
.../svn$ make\n

Ou ouvrir le projet Codeblocks <i>Snake.cbp</i> et appuyer sur <b><i>F9</i></b>:\n
.../svn$ codeblocks Snake.cbp &\n

\section Executer
Depuis le répertoire svn:\n
.../svn$ ./bin/snake_gfx

\section Regression
Pour lancer les tests de regression.\n\n
Ouvrir le Makefile:\n
.../svn$ gedit Makefile &\n

Mettre en commentaire la ligne JEU=graphique:\n
" #JEU=graphique "\n
Et décommenter la ligne #JEU=regression:\n
" JEU=regression "\n

Puis lancer depuis le terminal:\n
.../svn$ ./bin/regression\n

Sinon lancer le projet codeblocks <i>Regression.cbp</i> et appuyer sur <b><i>F9</i></b>:\n
.../svn$ codeblocks Regression.cbp &


\section Documentation

Pour générer la documentaion:\n
Depuis le fichier svn, sinon doxygen ne trouve pas les archives avec le code:

.../svn$ doxygen doc/snake.dox

Pour ouvrir la documentation:

.../svn$ firefox doc/html/index.html &

\section Fonctionnalités

La liste suivantes des fonctionnalitées a été implémentée:
    - Les modules Liste et Cellule on été dévellopés spécifiquement pour le snake.
    - Snake bouge automatiquement, change de taille, queue suit la tête, perd quand il rencontre un mur, la fin du terrain ou s'il se rencontre lui-même.\n
    - Terrain chargé depuis fichiers, en fonction des niveaux du jeu on charge d'autres fichiers avec des niveaux plus difficiles.\n
    - Nourriture positionnée aléatoirement dans une position valide (pas sur des murs).\n
    - On charge le max score depuis un fichier si on fait un score supérieur le fichier va être réecrit.\n
    - Un menu principal a été développé, l'utilisateur voit le max score et a différents choix, comme par exemple voir les instructions avant de jouer.\n
    - Images pour le snake, la nourriture et les murs développées sur GIMP.\n

*/
