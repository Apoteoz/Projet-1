// Vaïty TAYLLAMIN Manon WEISS
#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <string>
#include <queue>
#include "../SvgDrawer/svgdrawer.h"
#include "../Turtle/turtle.h"

class Instruction{
    std::string command_; // "avancer", "tourner" ou "repete"
    double valeur_; // pour "avancer" et "tourner", c'est la valeur numérique de l'instruction, pour "repete", c'est le nombre de répétitions
    public : 
        Instruction(std::string command = "", double valeur = 0); // Constructeur de Instruction qui prend une chaîne de caractères pour le type d'instruction et une valeur numérique
        std::string command() const; // Retourne le type d'instruction ("avancer", "tourner" ou "repete")
        double valeur() const; // Retourne la valeur numérique de l'instruction (distance pour "avancer", angle pour "tourner", nombre de répétitions pour "repete")
        void print() const; // Affiche l'instruction sous la forme "commande valeur" (ex: "avancer de,100", "tourner de 90", "repete 4")
        virtual void execute(SvgDrawer* draw) = 0; // Méthode virtuelle pure qui exécute l'instruction en utilisant un pointeur vers un SvgDrawer
        virtual ~Instruction() {} // Destructeur virtuel pour permettre la suppression correcte des objets dérivés à travers un pointeur de base
        virtual void print() = 0; // Méthode virtuelle pure pour afficher l'instruction de manière spécifique à chaque type d'instruction
};

// Avancer : sous classe de Instruction
class Avancer : public Instruction{
    double valeur_; // distance à avancer
    public : 
        Avancer(double valeur = 0); // Constructeur de Avancer qui prend une valeur numérique pour la distance à avancer
        double valeur(){return valeur_;} // Retourne la distance à avancer
        void setValeur(double valeur); // Modifie la distance à avancer
        double x_arrive(SvgDrawer* svgdraw); // Calcule la coordonnée x d'arrivée en fonction de la position et de la direction actuelles de la tortue
        double y_arrive(SvgDrawer* svgdraw); // Calcule la coordonnée y d'arrivée en fonction de la position et de la direction actuelles de la tortue
        void execute(SvgDrawer* svgdraw) override; // Implémente la méthode execute pour avancer la tortue de la distance spécifiée, en traçant une ligne si le stylo est baissé
        void print() override; // Implémente la méthode print pour afficher l'instruction de manière spécifique à Avancer (ex: "Avancer de 100")
};
// Tourner : sous classe de Instruction
class Tourner : public Instruction{
    double valeur_; // angle de rotation en degrés (positif pour tourner à droite, négatif pour tourner à gauche)
    public : 
        Tourner(double valeur = 0); // Constructeur de Tourner qui prend une valeur numérique pour l'angle de rotation
        double valeur(){return valeur_;} // Retourne l'angle de rotation
        void setValeur(double valeur); // Modifie l'angle de rotation
        void execute(SvgDrawer* svgdraw) override; // Implémente la méthode execute pour tourner la tortue de l'angle spécifié
        void print() override; // Implémente la méthode print pour afficher l'instruction de manière spécifique à Tourner (ex: "Tourner de 90")
};
// Repete sous classe de Instruction
class Repete : public Instruction{
    double valeur_; // nombre de répétitions
    std::queue<Instruction*> contenu_; // liste d'instructions à répéter, stockée dans une file d'attente pour garantir l'ordre d'exécution
    public : 
        Repete(double valeur = 0,std::queue<Instruction*> contenu = std::queue<Instruction*>() ); // Constructeur de Repete qui prend une valeur numérique pour le nombre de répétitions et une liste d'instructions à répéter
        double valeur(){return valeur_;} // Retourne le nombre de répétitions
        std::queue<Instruction*> contenu(){return contenu_;} // Retourne la liste d'instructions à répéter
        void setValeur(double valeur); // Modifie le nombre de répétitions
        void setContenu(std::queue<Instruction*> contenu); // Modifie la liste d'instructions à répéter
        void execute(SvgDrawer* svgdraw) override; // Implémente la méthode execute pour répéter les instructions contenues le nombre de fois spécifié
        void print() override; // Implémente la méthode print pour afficher l'instruction de manière spécifique à Repete (ex: "Repeter 4 fois ( ... )" avec les instructions à répéter affichées entre parenthèses)
};

#endif // INSTRUCTION_H