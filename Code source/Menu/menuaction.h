// Vaïty TAYLLAMIN Manon WEISS
#ifndef MENUACTION_H
#define MENUACTION_H

#include <string>
#include "menuoption.h"


template <class T> class MenuAction : public MenuOption
{
  typedef bool (T::*ActionPtr)(int); // Type de pointeur vers une méthode membre de T qui prend un int en paramètre et retourne un bool
  ActionPtr actionFct_; // Pointeur vers la fonction membre de T à exécuter lorsque cette option de menu est choisie
public:
  MenuAction(std::string text="", ActionPtr actionFct=nullptr); // Constructeur de MenuAction qui prend une chaîne de caractères pour le texte de l'option et un pointeur vers la fonction membre de T à exécuter
  bool isValid() const {return actionFct_!=nullptr;} // Une option de menu est valide si elle a une fonction d'action associée
  bool execute(Menu *menu, int menuId); // Implémente la méthode execute pour exécuter la fonction d'action associée à cette option de menu, en utilisant un pointeur vers le menu actuel pour accéder à ses membres si nécessaire. Le paramètre menuId peut être utilisé pour identifier l'option de menu dans le cas de sous-menus.
};

template <class T> MenuAction<T>::MenuAction(std::string text, ActionPtr actionFct) : MenuOption(text)
{
  actionFct_=actionFct;
}


template <class T> bool MenuAction<T>::execute(Menu *menu, int menuId)
{
  bool quit=false;
  T* menuT = dynamic_cast<T*>(menu);            // it must be a T*
  if (actionFct_!=nullptr && menuT!=nullptr) {
      quit=(menuT->*actionFct_)(menuId);
    }
  return quit;
}




#endif // MENUACTION_H
