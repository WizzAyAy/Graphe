***NOTICE KRUSTKAL***

Description de l’algorithme :
  L’algorithme construit un arbre couvrant minimum en sélectionnant des arêtes
par poids croissant. Plus précisément, l’algorithme considère toutes les arêtes du graphe par poids croissant et pour
chacune d’elles, il la sélectionne si elle ne crée pas un cycle. (cf. Wikipedia)




Explication de Krustkal :
  Tout d'abord, je verifie si l'arbre est connexe. S'il l'est, il execute l'algorithme de Krustkal, sinon affiche un message d'erreur.

Pour commencer, il faut initialiser l'arbre couvrant minimum (qui est un vector) avec des inf.

Ensuite, il faut initialiser le tableau de structures _tabstruct qui comporte le noeud a, le noeud b ainsi que le poids de l'arc entre ces deux points.

Puis, il faut initialiser tous les noeuds du tableau de noeuds parcourus à false.

Après, il faut trier les arcs selon l'ordre croissant et rentrer les informations de ces arcs (noeud a, noeud b, poids) dans les structures du tableau de structures _tabstruct.

Par la suite, je commence à construire l'arbre couvrant minimum avec la première structure de _tabstruct. Ainsi le premier noeud de l'arbre est construit et les noeuds qui viennent d'être ajouté à _tabstruct viennent d'être parcourus.

Ensuite, tant que le nombre de noeuds parcourus est strictement inférieur au nombre de sommets, l'algorithme verifie si l'ajout du prochain arc (qui aura le plus petit poids parmis les arcs restants dans _tabstruct) créera un cycle dans l'arbre couvrant minimum.

S'il n'y aura pas de cycle alors, Krustkal ajoute l'arc dans l'arbre couvrant minimal, affiche les noeuds concernés par une branche et affiche les noeuds (sous forme de couple) parcourus par l'arbre couvrant minimal sur la sortie standard.

Actualise ensuite le tableau de noeuds parcourus avec les noeuds concernés ainsi que le nombre de noeuds parcourus.

S'il y aura un cycle, alors Krustkal passe a l'arc minimal suivant.

Enfin, il affiche sur la sortie standard les noeuds par couple de l'arbre couvrant minimal.




Compilation :
  Il faut compiler le projet avec CMAKE.




Execution :
  Pour executer le programme, il faut dors et déjà mettre le working directory dans le dossier du projet (krustkal) et ajouter dans la "command line arguments" les exemples à tester qui sont dans le répertoire "test".

Enfin dans le main, il faut instancier un krustkalalgo, y initialiser et afficher (pour plus de clarté) un graphe avec la lecture du fichier d'exemple et enfin appeler la fonction krustkal sur l'instance de krustkalalgo.


