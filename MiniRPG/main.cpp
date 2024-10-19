#include <iostream>
#include "Character.h"
#include "Menu.h"
#include "ParsingLib.h"
#include <cstdlib>
#include <ctime>
#include "Combat.h"

int main() {
    srand(static_cast<unsigned>(time(0)));

    // Recuperer tous les objets du fichier d'inventaire
    std::vector<std::unique_ptr<Item>> allItems = ParsingLib::parseInventoryFile("InventoryList.txt");

    // Charger les classes disponibles depuis le fichier ClassList.txt
    std::vector<Class> allClasses = ParsingLib::parseClassFile("ClassList.txt");

    // Choisir deux classes aleatoirement
    std::string className1 = allClasses[rand() % allClasses.size()].getName();
    std::string className2 = allClasses[rand() % allClasses.size()].getName();

    // Creer les personnages
    Character character1("Personnage 1", className1);
    Character character2("Personnage 2", className2);

    // Initialiser les competences des personnages
    character1.initializeSkills(allClasses);
    character2.initializeSkills(allClasses);

    // Ajouter des objets à leurs inventaires
    //character1.getInventory().addRandomItems(allItems, 6);
    character1.getInventory().addItemsFromList(allItems);
    character2.getInventory().addRandomItems(allItems, 6);

    // Afficher le menu principal
    Menu::showMainMenu(character1, character2);

    return 0;
}
