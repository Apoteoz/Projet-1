// Vaïty TAYLLAMIN Manon WEISS
#ifndef MENU_H
#define MENU_H

#include <list>
#include <string>
#include "menuoption.h"
#include "../SvgDrawer/svgdrawer.h"
#include "../Consigne/consigne.h"

void clearConsole(); // Fonction pour nettoyer la console
void pauseConsole(std::string text="Press <Enter> to continue..."); // Fonction pour faire une pause dans la console en affichant un message personnalisé

class Menu : public MenuOption
{
  std::string prompt_; // Message d'invite pour demander à l'utilisateur de faire un choix
  std::string errorMessage_; // Message d'erreur affiché lorsque l'utilisateur fait un choix invalide
  std::list<MenuOption *> options_; // Liste d'options disponibles dans le menu, chaque option est un pointeur vers un MenuOption (qui peut être une action ou un sous-menu)
public:
  SvgDrawer *drawer_; // Pointeur vers un SvgDrawer pour permettre aux options du menu d'accéder au dessin SVG si nécessaire (par exemple, pour exécuter des actions liées au dessin)
  Menu(std::string title, // Titre du menu affiché en haut du menu
       std::string prompt="Votre choix ", // Message d'invite pour demander à l'utilisateur de faire un choix
       std::string errorMessage="Option invalide"); // Message d'erreur affiché lorsque l'utilisateur fait un choix invalide
  ~Menu(); // Destructeur de Menu qui libère la mémoire allouée pour les options du menu et le SvgDrawer
  bool isValid() const {return true;} // Vérifie si le menu est valide
  bool isMenu() const {return true;} // Vérifie si l'objet est un menu
  void addOption(MenuOption *option) // Ajoute une option au menu en l'ajoutant à la liste d'options
    {options_.push_back(option);} // Ajoute une option au menu
  virtual void print() const; // Affiche le menu en affichant le titre, les options disponibles et les messages d'invite et d'erreur
  MenuOption *findOption(int choice) const; // Trouve une option dans la liste d'options en fonction du choix de l'utilisateur (par exemple, en utilisant un index pour identifier les options)
  MenuOption *promptUser(int &menuId) const; // Affiche le message d'invite et attend que l'utilisateur entre un choix, puis trouve et retourne l'option correspondante en utilisant findOption. Le paramètre menuId peut être utilisé pour identifier l'option de menu dans le cas de sous-menus.
  bool execute(Menu *menu=nullptr,int menuId=0); // Exécute le menu en affichant les options et en traitant les choix de l'utilisateur. Si une option est choisie, elle est exécutée en utilisant son propre execute. Si une option de sous-menu est choisie, le sous-menu est exécuté récursivement. Le paramètre menu peut être utilisé pour passer un pointeur vers le menu actuel, ce qui permet aux options de menu d'accéder à ses membres si nécessaire (par exemple, pour accéder au SvgDrawer). Le paramètre menuId peut être utilisé pour identifier l'option de menu dans le cas de sous-menus.
  bool exitMenu(int) {return true;} // Méthode pour quitter le menu, peut être utilisée comme action pour une option de menu qui permet de revenir au menu précédent
};

#endif // MENU_H
