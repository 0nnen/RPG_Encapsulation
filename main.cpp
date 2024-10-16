#include <iostream>
#include "Character.h"
#include "Menu.h"
#include "ParsingLib.h"
#include <cstdlib>
#include <ctime>
#include "Combat.h"

int main() {
    srand(static_cast<unsigned>(time(0)));  // Initialisation du générateur de nombres aléatoires

    // Charger tous les objets depuis le fichier InventoryList.txt à l'aide de ParsingLib
    std::vector<std::unique_ptr<Item>> allItems = ParsingLib::parseInventoryFile("InventoryList.txt");

    // Choisir deux classes aléatoirement
    ClassType classType1 = getRandomClassType();
    ClassType classType2 = getRandomClassType();

    // Créer les personnages
    Character character1("Personnage 1", classType1);
    Character character2("Personnage 2", classType2);

    // Ajouter des objets à leurs inventaires
    character1.getInventory().addItemsFromList(allItems);
    character2.getInventory().addItemsFromList(allItems);

    // Afficher le menu principal
    Menu::showMainMenu(character1, character2);

    return 0;
}
