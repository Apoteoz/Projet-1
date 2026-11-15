// Vaïty TAYLLAMIN Manon WEISS
#include <iostream>
#include <iostream>
#include "Menu/menu.h"
#include "Menu/menuaction.h"


using namespace std;

class MainMenu : public Menu
{
public:
  MainMenu() : Menu("Menu principal") {

    addOption(new MenuAction<MainMenu>("Draw",&MainMenu::option1));
    addOption(new MenuAction<MainMenu>("Move to",&MainMenu::option2));
    addOption(new MenuAction<MainMenu>("Clear",&MainMenu::option3));
    Menu *subMenu=new Menu("Settings");
    subMenu->addOption(new MenuAction<MainMenu>("Color",&MainMenu::option41));
    subMenu->addOption(new MenuAction<MainMenu>("Strokewidth",&MainMenu::option42));
    subMenu->addOption(new MenuAction<MainMenu>("Retour au menu",&MainMenu::exitMenu));
    addOption(subMenu);
    addOption(new MenuAction<MainMenu>("Exit",&MainMenu::quit));
  }

  bool option1(int menuId) {
    cout<<"Option 1 choisie"<<endl;
    cout<<"MenuId: "<<menuId<<endl;
    drawer_->stylo()->setState(true); // on baisse le stylo pour dessiner
    drawer_->stylo()->print();
    Consigne cons(drawer_);
    cons.print();
    cons.execute();
    return false;
  }

  bool option2(int menuId) {
    cout<<"Option 2 choisie"<<endl;
    cout<<"MenuId: "<<menuId<<endl;
    drawer_->stylo()->setState(false); // on baisse le stylo pour dessiner
    drawer_->stylo()->print();
    Consigne cons(drawer_);
    cons.print();
    cons.execute();
    return false;
  }

  bool option3(int menuId) {
    cout<<"Option 3 choisie"<<endl;
    cout<<"MenuId: "<<menuId<<endl;
    drawer_->endDraw();
    drawer_->beginDraw("Turtle Graphics");
    return false;
  }

  bool option41(int menuId) {
    cout<<"Option 4.1 choisie"<<endl;
    cout<<"MenuId: "<<menuId<<endl;
    drawer_->setStrokeColor();
    return false;
  }

  bool option42(int menuId) {
    cout<<"Option 4.2 choisie"<<endl;
    cout<<"MenuId: "<<menuId<<endl;
    drawer_->setStrokeWidth();
    return false;
  }

  bool option411(int menuId) {
    cout<<"Option 4.1.1 choisie"<<endl;
    cout<<"MenuId: "<<menuId<<endl;
    return false;
  }
  
  bool option412(int menuId) {
    cout<<"Option 4.1.2 choisie"<<endl;
    cout<<"MenuId: "<<menuId<<endl;
    return false;
  }

  bool option413(int menuId) {
    cout<<"Option 4.1.3 choisie"<<endl;
    cout<<"MenuId: "<<menuId<<endl;
    return false;
  }

  bool quit(int) {
    cout<<"Au revoir!!"<<endl;
    clearConsole();
    return true;
  }
};

int main()
{
  MainMenu menu;
  menu.execute();
  return 0;
}