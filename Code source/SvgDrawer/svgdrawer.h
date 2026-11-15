// Vaïty TAYLLAMIN Manon WEISS
#ifndef SVGDRAWER_H
#define SVGDRAWER_H

#include <string>
#include <fstream>
#include "../Turtle/turtle.h"

class SvgDrawer
{
  // Private fields
  std::string htmlFile_; // Nom du fichier HTML dans lequel le dessin SVG sera généré
  int drawingWidth_; // Largeur de la zone de dessin SVG
  int drawingHeight_; // Hauteur de la zone de dessin SVG
  std::ofstream htmlStream_; // Flux de sortie pour écrire dans le fichier HTML
  std::string strokeColor_; // Couleur du trait pour les éléments dessinés (par exemple, "navy", "red", "green", etc.)
  float strokeWidth_; // Épaisseur du trait pour les éléments dessinés
  std::string fillColor_; // Couleur de remplissage pour les éléments dessinés (par exemple, "none" pour pas de remplissage, ou une couleur comme "yellow", "lightblue", etc.)
  Turtle* stylo_; // Pointeur vers un objet Turtle qui représente le stylo utilisé pour dessiner, permettant de suivre la position et la direction du dessin
  // Private methods
  // Méthodes pour générer les balises SVG dans le fichier HTML
  void openTag(std::string tagName,std::string attribute="");
  void closeTag(std::string tagName);
  void emptyTag(std::string tagName,std::string attribute="");
  void tag(std::string tagName,std::string attribute="",std::string content="");
  std::string setAttribStyle() const;
  void jscriptRefreshTag();

public:

  //! Constructor
  SvgDrawer(std::string htmlFile, int dWidth=400, int dHeight=400);

  //! Set the drawing area size
  void setDrawingSize(int dWidth,int dHeight);

  //! Get the turtle
  Turtle* stylo(){return stylo_;}
  
  //! Get the stroke color
  std::string strokeColor() const
    {return strokeColor_;}

  //! Set the stroke color
  void setStrokeColor();

  //! Get the stroke width
  float strokeWidth() const
    {return strokeWidth_;}

  //! Set the stroke width
  void setStrokeWidth();

  //! Get the fill color
  std::string fillColor() const
    {return fillColor_;}

  //! Set the fill color
  void setFillColor(std::string fColor)
    {fillColor_=fColor;}

  //! Get the drawing width
  int drawingWidth() const
    {return drawingWidth_;}

  //! Get the drawing height
  int drawingHeight() const
    {return drawingHeight_;}

  //! Call to start the drawing
  void beginDraw(std::string title);

  //! Call to end the drawing
  void endDraw();

  //! Draw a line
  void drawLine(double x2,double y2);

  //! Draw a circle
  void drawCircle(double centerX,double centerY,double radius);

};

std::string setAttrib(std::string name, double value);
std::string setAttrib(std::string name, std::string value);

#endif // SVGDRAWER_H
