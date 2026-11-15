// Vaïty TAYLLAMIN Manon WEISS
#include <iostream>
#include "consigne.h"

Consigne::Consigne(SvgDrawer* drawer){
    drawer_ = drawer;
};

void Consigne::push(Instruction* inst){
    liste_.push(inst);
}

Instruction* Consigne::pop(){
    Instruction* temp = liste_.front();
    liste_.pop();
    return temp;
}

void Consigne::print() const{
    std::queue<Instruction*> temp = liste_;
    Instruction* i;
    while(!temp.empty()){
        i = temp.front();
        i->print();
        std::cout << " -> ";
        temp.pop();
    }
    std::cout << "\n";
}

std::string Consigne::entree(){
    std::cout << "\nEntrez vos instructions : ";
    std::string cons;
    std::getline(std::cin >> std::ws, cons);
    return cons;
}

void Consigne::lire_cons(std::string cons){
    liste_ =lire_cons_rec(cons,0);
}

std::queue<Instruction*> lire_cons_rec(std::string& cons, int repete_actif){
    std::queue<Instruction*> liste;
    while(!cons.empty() && (repete_actif == 0 || cons[0] != ']')){
        // la condition d'arret n'est pas la meme pour une consigne et un repete

        //lecture de l'instruction
        std::string mot;
        while(!cons.empty() && cons[0] != ' '){// action avancer tourner ou repete
            mot += cons[0];// on met la premiere lettre de la consigne
            cons.erase(0, 1);// on enleve la premiere lettre de la consigne
        }
        if(!cons.empty() && cons[0]==' '){
            cons.erase(0, 1); //on eneleve l'espace
        }

        //lecture de la valeur 
        std::string valeur;
        while(!cons.empty() && cons[0] != ' ' && cons[0] != '['){// on a 'v ' ou 'v]' ou 'v' 
            valeur += cons[0];//on repere la valeur chiffre par chiffre
            cons.erase(0, 1);
        }
        if(!cons.empty() && cons[0] == ' '){
            cons.erase(0, 1); //on eneleve l'espace
        }

        // on match avec le bon objet
        if (mot=="AVANCER" || mot=="AVANCE" || mot=="fd"){
            liste.push(new Avancer(std::stoi(valeur))); //on met l'instruction avancer dans liste 
        }else if (mot=="TOURNER" || mot=="TURN" || mot=="td" || mot=="TOURNE_GAUCHE" || mot=="TOURNER_GAUCHE"|| mot=="LEFT_TURN" || mot=="lt"){
            liste.push(new Tourner(std::stoi(valeur)));//on met l'instruction tourner dans liste 
        }else if (mot=="TOURNER_DROITE" || mot=="TOURNE_DROITE" || mot=="RIGHT_TURN" || mot=="rt"){
            liste.push(new Tourner(-std::stoi(valeur)));//on met l'instruction tourner dans liste     
        }else if (mot=="RECULER" || mot=="RECULE" || mot=="bd"){
            liste.push(new Avancer(-std::stoi(valeur))); //on met l'instruction avancer dans liste
        }else if (mot=="REPETER" || mot=="REPEAT" || mot=="rt"){
            if(cons[0]!='['){
                std::cout << "formule incorrecte";
            }
            if(!cons.empty() && cons[0]=='['){
                cons.erase(0,1);//on enleve le [
            }
            // on recupere l'interieur du repete
            std::queue<Instruction*> contenu = lire_cons_rec(cons, 1);
            if(!cons.empty() && cons[0] == ']') {
                cons.erase(0, 1);
            }
            if(!cons.empty() && cons[0] == ' ') {// si on met un espace apres le ] 
                cons.erase(0, 1);
            }
            liste.push(new Repete(std::stoi(valeur),contenu));//on met l'instruction repete dans liste 
        }
    }
    return  liste;
}

void Consigne::execute(){
    this->lire_cons(entree());
    while(!liste_.empty()){
        Instruction* i = this->pop();
        i->execute(drawer_);
        delete i;
    }
}

Consigne::~Consigne(){
    while(!liste_.empty()){
        Instruction* i = liste_.front();
        delete i;
        liste_.pop();
    }
}


