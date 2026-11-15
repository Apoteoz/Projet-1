// Vaïty TAYLLAMIN Manon WEISS
#ifndef MENUOPTION_H
#define MENUOPTION_H

#include <string>
#include <list>
#include "../Consigne/consigne.h"

class Menu;


class MenuOption
{
  std::string text_; // Texte de l'option de menu, utilisé pour afficher le menu et identifier les options
public:
  MenuOption(std::string text=""); // Constructeur de MenuOption qui prend une chaîne de caractères pour le texte de l'option
  virtual ~MenuOption(); // Destructeur de MenuOption, déclaré virtuel pour permettre la suppression correcte des objets dérivés à travers un pointeur de base
  std::string text() const {return text_;} // Accesseur pour le texte de l'option de menu
  virtual bool isValid() const {return false;} // Méthode virtuelle qui indique si cette option de menu est valide (par défaut, une option de menu n'est pas valide, les classes dérivées peuvent redéfinir cette méthode pour indiquer qu'elles sont valides)
  virtual bool isMenu() const {return false;} // Méthode virtuelle qui indique si cette option de menu est un sous-menu (par défaut, une option de menu n'est pas un menu, les classes dérivées peuvent redéfinir cette méthode pour indiquer qu'elles sont des menus)
  virtual bool execute(Menu *menu, int menuId)=0; // Méthode virtuelle pure qui exécute l'action associée à cette option de menu. Le paramètre menu est un pointeur vers le menu actuel, ce qui permet à l'option de menu d'accéder aux membres du menu si nécessaire (par exemple, pour accéder au SvgDrawer). Le paramètre menuId peut être utilisé pour identifier l'option de menu dans le cas de sous-menus.
};



#endif // MENUOPTION_H
