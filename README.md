Le projet Pipex a pour objectif de reproduire le fonctionnement de l'opérateur pipe (|) du shell Unix en C. Ce projet permet de se familiariser avec les concepts de programmation système, notamment la manipulation des File Descriptors, la création de processus avec fork, et la communication inter-processus via pipe.

L'exécution du programme simule la commande shell suivante : < file1 cmd1 | cmd2 > file2

Le programme s'exécute de la manière suivante : ./pipex file1 cmd1 cmd2 file2
Objectifs techniques

    Compréhension des appels systèmes Unix (access, open, unlink, close, read, write).

    Gestion des processus (fork, waitpid).

    Manipulation des pipes (pipe, dup, dup2).

    Exécution de programmes (execve).

Instructions
Prérequis

Ce projet a été développé et testé sous Linux/macOS. Vous devez disposer d'un compilateur gcc et de l'utilitaire make.
Installation

Pour compiler le projet, clonez le dépôt et lancez la commande make à la racine :
Bash

git clone <url_du_repo> pipex
cd pipex
make

Cela générera l'exécutable pipex.
Exécution

La syntaxe d'exécution est la suivante :
Bash

./pipex <infile> <cmd1> <cmd2> <outfile>

    infile : Fichier d'entrée dont le contenu sera envoyé à cmd1.

    cmd1 : Première commande shell (avec ses paramètres).

    cmd2 : Seconde commande shell (avec ses paramètres).

    outfile : Fichier de sortie où le résultat final sera écrit (créé ou écrasé).

Exemples

Exemple 1 : Compter les lignes d'un fichier
Bash

./pipex input.txt "ls -l" "wc -l" output.txt

Équivalent shell : < input.txt ls -l | wc -l > output.txt

Exemple 2 : Recherche de texte
Bash

./pipex input.txt "grep a1" "wc -w" result.txt

Équivalent shell : < input.txt grep a1 | wc -w > result.txt
Nettoyage

    make clean : Supprime les fichiers objets (.o).

    make fclean : Supprime les fichiers objets et l'exécutable.

    make re : Recompile le projet à zéro.
