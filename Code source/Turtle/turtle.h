// Vaïty TAYLLAMIN Manon WEISS
#ifndef TURTLE_H
#define TURTLE_H

#include <string>

class Point{
    double x_; // Coordonnée x du point
    double y_; // Coordonnée y du point
    public:
    Point(double x = 0, double y = 0); // Constructeur de Point qui prend des coordonnées x et y, avec des valeurs par défaut de 0
    double x(){return x_;} // Retourne la coordonnée x du point
    double y(){return y_;} // Retourne la coordonnée y du point
    void print() const; // Affiche les coordonnées du point sous la forme "(x, y)"
    void setX(double x); // Modifie la coordonnée x du point
    void setY(double y); // Modifie la coordonnée y du point
};


class Turtle{
    Point position_; // Position actuelle de la tortue, représentée par un objet Point
    double direction_; // Direction actuelle de la tortue en degrés
    std::string color_; // Couleur du trait pour les dessins effectués par la tortue (par exemple, "blue", "red", "green", etc.)
    int strokewidth_; // Épaisseur du trait pour les dessins effectués par la tortue
    bool state_; // État du stylo de la tortue, true si le stylo est baissé, false si le stylo est levé 
    public :
        Turtle(Point position = {0,0}, double direction = 0, std::string color = "blue", int strokewidth = 3, bool state = true); // Constructeur de Turtle qui prend une position, une direction, une couleur, une épaisseur de trait et un état de stylo, avec des valeurs par défaut
        Point position() const; // Retourne la position actuelle de la tortue sous forme d'un objet Point
        double direction() const; // Retourne la direction actuelle de la tortue en degrés
        void print(); // Affiche les caractéristiques de la tortue
        std::string color() const; // Retourne la couleur du trait de la tortue
        int strokewidth() const; // Retourne l'épaisseur du trait de la tortue
        bool state() const; // Retourne l'état du stylo de la tortue, true si le stylo est baissé, false si le stylo est levé
        void setPosition(Point position); // Modifie la position de la tortue
        void setDirection(double direction); // Modifie la direction de la tortue
        void setColor(std::string color); // Modifie la couleur du trait de la tortue
        void setStrokewidth(int strokewidth); // Modifie l'épaisseur du trait de la tortue
        void setState(bool state); // Modifie l'état du stylo de la tortue, true pour baisser le stylo, false pour lever le stylo
};

#endif // TURTLE_H
