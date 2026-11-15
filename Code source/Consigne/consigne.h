// Vaïty TAYLLAMIN Manon WEISS
#ifndef CONSIGNE_H
#define CONSIGNE_H

#include <queue>
#include <cstring>
#include "../Instruction/instruction.h"

class Consigne{
    std::queue<Instruction*> liste_; // Liste d'instructions à exécuter 
    SvgDrawer* drawer_; // Pointeur vers le SvgDrawer pour pouvoir exécuter les instructions
    public :
        Consigne(SvgDrawer* drawer = nullptr); // Constructeur de Consigne qui prend un pointeur vers un SvgDrawer
        void push(Instruction* inst); // Ajoute une instruction à la liste
        Instruction* pop(); // Retire et retourne la première instruction de la liste
        void print() const; // Affiche la liste des instructions dans l'ordre d'exécution
        std::string entree(); // Demande à l'utilisateur d'entrer une consigne et retourne la chaîne de caractères correspondante
        void lire_cons(std::string cons); // Parseur
        void execute(); // Exécute les instructions de la liste dans l'ordre
        ~Consigne(); // Destructeur de Consigne qui libère la mémoire allouée pour les instructions
};
std::queue<Instruction*> lire_cons_rec(std::string& cons, int repete_actif); // Fonction récursive qui parse une consigne et retourne une liste d'instructions. Le paramètre repete_actif indique si on est à l'intérieur d'une instruction REPETE pour gérer correctement les crochets.
#endif // CONSIGNE_H
