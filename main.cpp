#include <iostream>
#include <map>
#include <vector>
#include "Character.h"
#include "Weapon.h"
#include "Armor.h"
#include "Combat.h"
#include "Inventory.h"
#include <cstdlib>
#include <ctime>

// Affiche le menu de gestion des personnages pour équiper ou afficher des informations
void showCharacterMenu(Character& character) {
    int choice = 0;
    do {
        std::cout << "\n=== MENU DU PERSONNAGE: " << character.getName() << " ===\n";
        std::cout << "1. Afficher l'inventaire\n";
        std::cout << "2. Afficher les informations du personnage\n";
        std::cout << "3. Equiper une arme\n";
        std::cout << "4. Equiper une armure\n";
        std::cout << "5. Retour\n";
        std::cout << "Choisissez une option: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            character.getInventory().displayInventory();
            break;
        case 2:
            character.displayCharacterInfo();
            break;
        case 3: {
            int itemIndex;
            std::cout << "Sélectionnez une arme dans l'inventaire (index): ";
            std::cin >> itemIndex;
            character.equipWeapon(dynamic_cast<Weapon*>(character.getInventory().getItem(itemIndex)));
            std::cout << "Arme équipée!\n";
            break;
        }
        case 4: {
            int itemIndex;
            std::cout << "Sélectionnez une armure dans l'inventaire (index): ";
            std::cin >> itemIndex;
            character.equipArmor(dynamic_cast<Armor*>(character.getInventory().getItem(itemIndex)));
            std::cout << "Armure équipée!\n";
            break;
        }
        case 5:
            std::cout << "Retour au menu précédent...\n";
            break;
        default:
            std::cout << "Option non valide. Veuillez choisir à nouveau.\n";
        }
    } while (choice != 5);
}

// Affiche le menu de gestion des personnages (choisir entre le personnage 1 et 2)
void showManageCharactersMenu(Character& character1, Character& character2) {
    int choice = 0;
    do {
        std::cout << "\n=== GESTION DES PERSONNAGES ===\n";
        std::cout << "1. Gérer le personnage 1\n";
        std::cout << "2. Gérer le personnage 2\n";
        std::cout << "3. Retour au menu principal\n";
        std::cout << "Choisissez une option: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            showCharacterMenu(character1);
            break;
        case 2:
            showCharacterMenu(character2);
            break;
        case 3:
            std::cout << "Retour au menu principal...\n";
            break;
        default:
            std::cout << "Option non valide. Veuillez choisir à nouveau.\n";
        }
    } while (choice != 3);
}

// Menu principal pour accéder à la gestion des personnages ou lancer le combat
void showMainMenu(Character& character1, Character& character2) {
    int choice = 0;
    do {
        std::cout << "\n=== MENU PRINCIPAL ===\n";
        std::cout << "1. Gestion des personnages\n";
        std::cout << "2. Lancer le combat\n";
        std::cout << "3. Quitter\n";
        std::cout << "Choisissez une option: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            showManageCharactersMenu(character1, character2);
            break;
        case 2:
            std::cout << "Lancement du combat...\n";
            Combat::engage(character1, character2);
            break;
        case 3:
            std::cout << "Au revoir!\n";
            break;
        default:
            std::cout << "Option non valide. Veuillez choisir à nouveau.\n";
        }
    } while (choice != 3);
}

int main() {
    srand(static_cast<unsigned>(time(0)));  // Initialisation du générateur de nombres aléatoires

    // Création d'un inventaire
    Inventory inventory;

    // Charger l'inventaire depuis le fichier InventoryList.txt
    inventory.loadInventoryFromFile("InventoryList.txt");

    // Choisir deux classes aléatoirement
    ClassType classType1 = getRandomClassType();
    ClassType classType2 = getRandomClassType();

    // Créer les personnages
    Character character1("Personnage 1", classType1);
    Character character2("Personnage 2", classType2);

    // Charger leurs inventaires
    character1.getInventory().loadInventoryFromFile("InventoryList.txt");
    character2.getInventory().loadInventoryFromFile("InventoryList.txt");

    // Afficher le menu principal
    showMainMenu(character1, character2);

    return 0;
}
