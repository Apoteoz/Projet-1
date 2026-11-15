// Vaïty TAYLLAMIN Manon WEISS
#include <iostream>
#include <cmath>
#include "turtle.h"


// Classe Point
Point::Point(double x,double y)
{
    x_ = x;
    y_ = y;
}

void Point::print() const
{
    std::cout << "\nPosition : (" << x_ << "," << y_ << ")";
}

void Point::setX(double x){
    x_ = x;
}

void Point::setY(double y){
    y_ = y;
}


//Classe Turtle
Turtle::Turtle(Point position, double direction, std::string color, int strokewidth, bool state)
{
    position_ = position;
    direction_ = direction;
    color_ = color;
    strokewidth_ = strokewidth;
    state_ = state;
}

Point Turtle::position() const{
    return position_;
}
double Turtle::direction() const{
    return direction_;
}
void Turtle::print(){
    double x = position_.x();
    double y = position_.y();
    std::cout << "\nPosition : (" << x << "," << y << ")";
    std::cout << "\nDirection : " << std::abs(direction_) << "°";
    std::cout << "\nColor : " << color_;
    std::cout << "\nStrokewidth : " << strokewidth_;
    if(state_){
        std::cout << "\nStylo baissé\n";
    }
    else{
        std::cout << "\nStylo levé\n";
    }

}

std::string Turtle::color() const{
    return color_;
}

int Turtle::strokewidth() const{
    return strokewidth_;
}

bool Turtle::state() const{
    return state_;
}

void Turtle::setPosition(Point position){
    position_ = {position.x(),position.y()};
}

void Turtle::setDirection(double direction){
    direction_ = std::fmod(direction_ - direction, 360);
}
void Turtle::setColor(std::string color){
    color_ = color;
}

void Turtle::setStrokewidth(int strokewidth){
    strokewidth_ = strokewidth;
}

void Turtle::setState(bool state){
    state_ = state;
}
