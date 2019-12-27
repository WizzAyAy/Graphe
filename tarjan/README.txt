***NOTICE TARJAN***

Description de l'algorithme : 
  Tarjan est un algorithme récursif qui cherche à isoler en partition les différentes
parties d’un graphe orienté dont les sommets sont connexes. L’algorithme garde une trace des sommets déjà visités
afin de ne parcourir qu’une seule fois chaque sommet. Lorsqu’un sommet est visité on le numérote et l’ajoute à
une pile. Tous les sommets sont parcourus en profondeur et numérotés. Lorsque l’on tombe à nouveau sur un
sommet déjà visité c’est qu’il existe un cycle. On cherche alors à définir quelle est la racine (sommet de départ de la
composante connexe) en recherchant le sommet du cycle avec la numérotation la plus petite. Une fois le parcours
terminé on ajoute les sommets par ensemble à notre partition. S’il reste des sommets non parcourus on recommence
l’opération à partir d’un des sommets non parcourus (c’est le cas lorsqu’il n’existe aucun chemin allant d’une partie
du graphe à une autre).




Explication de Tarjan : 
  Le noyau de l'algorithme se situe dans le parcoursProfondeur() et dans le explorer().
Les variables jointure_a et jointure_b permettent de garder en mémoire les sommets à relier pour rendre le graphe entièrement connexe.

Ensuite, sur chaque sommets non visités, j'execute la procédure explorer().

Dans la fonction explorer, j'indique que le sommet actuel est parcouru. Je vérifie si tous les sommet ont été parcouru ou non. 

Je fais un affichage au fur et à mesure de l'avancement de l'algorithme de recherche sur chaque sommet.

J'initialise la vecteur de structure d'information sur les sommets (sommet, vnum, vnumaccessible) avec les valeurs pour chaque sommet.

Ensuite pour chaque sommet, je regarde si dans la matrice d'adjacence il y un arc entre 2 sommets et que le second sommet n'est pas déjà parcouru.
Si oui, alors j'appelle récursivement la procédure explorer() sur ce second sommet. Sinon je fais un affichge en conséquence.

Sinon, je regarde aussi si tous les sommets ont déjà été parcouru. Si oui, je fais un affichage en conséquence et garde cette donnée en mémoire.

Sinon, je regarde s'il y a un cycle. Si oui, je fais un affichage en conséquence. Puis je décrois la valeur de vnum_accessible des sommets du cycle jusqu'à celui de la racine du cycle. 
Je garde en mémoire dans un vecteur ces sommets du cycle. Et je garde ensuite ce vecteur dans ma partition.
J'affiche ensuite les éléments de la partition que je viens de garder en mémoire.

J'effectue cette algorithme récursivement sur tous les sommets du graphe non parcourus (c'est à dire quand ce n'est pas connexe).

Enfin je relie les éléments de ma partition entre elles afin que le graphe entier soit connexe et dans la procédure tarjan() j'y affiche chaque éléments de ma partition.





Compilation :
  Il faut compiler le projet avec CMAKE.




Execution :
  Pour executer le programme, il faut dors et déjà mettre le working directory dans le dossier du projet (tarjan) et ajouter dans la "command line arguments" les exemples à tester qui sont dans le répertoire "test".

Enfin dans le main, il faut seulement appeler tarjan() sur l'instance et appeler affichageMatrice() sur la même instance afin de pouvoir afficher le graphe qui est désormais entièrement connexe.

