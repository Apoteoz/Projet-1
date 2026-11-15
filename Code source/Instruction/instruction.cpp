// Vaïty TAYLLAMIN Manon WEISS
#include <iostream>
#include <cmath>
#include "instruction.h"


// Instruction
Instruction::Instruction(std::string command,double valeur)
{
    command_ = command;
    valeur_ = valeur;
}

std::string Instruction::command() const{
    return command_;
}

double Instruction::valeur() const{
    return valeur_;
}

void Instruction::print() const{
    std::cout << command_ << " " << valeur_;
}

// Avancer
Avancer::Avancer(double valeur)
{
    valeur_ = valeur;
}

void Avancer::setValeur(double valeur)
{
    valeur_ = valeur;
}

double Avancer::y_arrive(SvgDrawer* svgdraw)
{   
    double pi = 3.14159265358979323846;
    // Cette formule permet de retrouver le bon y selon la trigonométrie
    double y = std::sin(svgdraw->stylo()->direction()*pi/180)*valeur_ + svgdraw->stylo()->position().y();
    return y;
}

double Avancer::x_arrive(SvgDrawer* svgdraw)
{
    double pi = 3.14159265358979323846;
    // Cette formule permet de retrouver le bon x selon la trigonométrie
    double x = std::cos(svgdraw->stylo()->direction()*pi/180)*valeur_ + svgdraw->stylo()->position().x();
    return x;
}

void Avancer::execute(SvgDrawer* svgdraw)
{
    double x = Avancer::x_arrive(svgdraw);
    double y = Avancer::y_arrive(svgdraw);
    // on trace la ligne si le stylo est baissé
    if(svgdraw->stylo()->state()){
        svgdraw->drawLine(x ,y);
    }
    // on met a jour la position de turtle
    Point p(x,y);
    if(p.x()>svgdraw->drawingWidth()){
        p.setX(svgdraw->drawingWidth());
    }
    if(p.x()<0){
        p.setX(0);
    }
    if (p.y()>svgdraw->drawingHeight())
    {
        p.setY(svgdraw->drawingHeight());
    }
    if(p.y()<0){
        p.setY(0);
    };
    svgdraw->stylo()->setPosition(p);
}

void Avancer::print(){
    std::cout << "Avancer de " << valeur_<<" ";
}
// Tourner
Tourner::Tourner(double valeur)
{
    valeur_ = valeur;
}

void Tourner::setValeur(double valeur)
{
    valeur_ = valeur;
}

void Tourner::execute(SvgDrawer* svgdraw) 
{
    // on met a jour la direction de turtle 
    svgdraw->stylo()->setDirection(valeur_);
}

void Tourner::print(){
    std::cout << "Tourner de " << valeur_<<" ";
}

// Repete
Repete::Repete(double valeur, std::queue<Instruction*> contenu)
{
    valeur_ = valeur;
    contenu_ = contenu;
}

void Repete::setValeur(double valeur)
{
    valeur_ = valeur;
}

void Repete::setContenu(std::queue<Instruction*> contenu){
    contenu_ = contenu;
}

void Repete::execute(SvgDrawer* svgdraw) 
{
    for (int i = 0; i < valeur_; i++) {
        std::queue<Instruction*> copie = contenu_; 
        while (!copie.empty()) {
            Instruction* instr = copie.front();
            instr->execute(svgdraw);
            copie.pop();
        }
    }
}

void Repete::print(){
    std::cout << "Repeter " << valeur_<<"fois ( ";
    std::queue<Instruction*> copie = contenu_; 
        while (!copie.empty()) {
            Instruction* instr = copie.front();
            instr->print();
            copie.pop();
        }
}
