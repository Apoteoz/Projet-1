# Interpréteur Logo en C++

Application console qui interprète un sous-ensemble du langage **Logo** et dessine le résultat dans un fichier HTML au format SVG, visualisable dans un navigateur.

Projet réalisé en binôme dans le cadre du module de Programmation Orientée Objet (Télécom Saint-Étienne, 2025-2026).

## Fonctionnalités

- Exécution de commandes simples : `AVANCE 100`, `TOURNE_DROITE 90`
- Enchaînement de plusieurs commandes saisies en console
- Répétitions : `REPETE 4 [AVANCE 100 TOURNE_DROITE 90]`
- Répétitions imbriquées : `REPETE 3 [AVANCE 100 REPETE 4 [AVANCE 50 TOURNE_DROITE 90] TOURNE_DROITE 120]`
- Affichage de la position et de l'état de la tortue dans la console
- Génération du dessin dans un fichier SVG

## Exemple

Pour dessiner un carré :

    REPETE 4 [AVANCE 100 TOURNE_DROITE 90]

## Compilation et exécution

    cd Code\ source/
    make
    ./main.exe
    
Ouvrir le fichier "draw.html" placé dans le dossier "Code Source" et le rafraîchir à chaque commande.

## Organisation du code

Le code est découpé en classes, avec un fichier `.h` et un fichier `.cpp` par classe. Il utilise l'agrégation, l'association, l'héritage et les structures de la STL (`string`, `vector`, `list`).

Un rapport complet du projet est disponible et décrit l'ensemble des classes ainsi que leurs fonctionnalités.

## Auteurs

- Vaïty Tayllamin
- Manon Weiss

La classe `SvgDrawer` a été fournie dans le cadre des travaux dirigés du cours.
