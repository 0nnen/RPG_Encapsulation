#include "Menu.h"
#include <iostream>
#include "Combat.h"
#include "Inv.h"
#include <string>

void Menu::searchItems(InventoryLib& inventory) {
    std::string name, type, element;
    int minAttack = 0, maxAttack = 0, minDefense = 0, maxDefense = 0;
    int choice = 0;

    std::cout << "Recherche d'objets:\n";

    while (true) {
        std::cout << "\nFaites votre choix:\n";
        std::cout << "1. Nom \n";
        std::cout << "2. Type \n";
        std::cout << "3. Statistiques d'attaque min \n";
        std::cout << "4. Statistiques d'attaque max \n";
        std::cout << "5. Statistiques de défense min \n";
        std::cout << "6. Statistiques de défense max \n";
        std::cout << "7. Element \n";
        std::cout << "8. Lancer la recherche\n";
        std::cout << "9. Quitter\n";  
        std::cout << "Entrez votre choix: ";

        std::cin >> choice;
        std::cin.ignore(); 

        switch (choice) {
        case 1:
            std::cout << "Entrez le nom: ";
            std::getline(std::cin, name);
            break;
        case 2:
            std::cout << "Entrez le type: ";
            std::getline(std::cin, type);
            break;
        case 3:
            std::cout << "Entrez les statistiques d'attaque min: ";
            std::cin >> minAttack;
            break;
        case 4:
            std::cout << "Entrez les statistiques d'attaque max: ";
            std::cin >> maxAttack;
            break;
        case 5:
            std::cout << "Entrez les statistiques de défense min: ";
            std::cin >> minDefense;
            break;
        case 6:
            std::cout << "Entrez les statistiques de défense max: ";
            std::cin >> maxDefense;
            break;
        case 7:
            std::cout << "Entrez l'élément: ";
            std::getline(std::cin, element);
            break;
        case 8:
            std::cout << "Lancer la recherche...\n";
            {
                auto results = inventory.searchByCriteria(name, type, minAttack, maxAttack, minDefense, maxDefense, element);

                std::cout << "Résultats de la recherche:\n";
                for (const auto& item : results) {
                    std::cout << item->getName() << " (" << item->getType() << ")\n";
                }
            }
            break;
        case 9:
            std::cout << "Quitter la recherche.\n";
            return; 
        default:
            std::cout << "Choix invalide, veuillez réessayer.\n";
            break;
        }
    }
}

void Menu::showCharacterMenu(Character& character) {
    int choice = 0;
    do {
        std::cout << "\n\t\t=== MENU DU PERSONNAGE: " << character.getName() << " ===\n";
        std::cout << "1. Afficher l'inventaire\n";
        std::cout << "2. Afficher les informations du personnage\n";
        std::cout << "3. Equiper une arme\n";
        std::cout << "4. Equiper une armure\n";
        std::cout << "5. Rechercher des objets\n";
        std::cout << "6. Retour\n";
        std::cout << "\n\t\tChoisissez une option: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            system("CLS");
            character.getInventory().displayInventory();
            break;
        case 2:
            system("CLS");
            character.displayCharacterInfo();
            break;
        case 3: {
            system("CLS");
            int itemIndex;
            character.getInventory().displayInventoryByType("Weapon");
            std::cout << "\tSelectionnez une arme dans l'inventaire (index): ";
            std::cin >> itemIndex;
            character.equipWeapon(dynamic_cast<Weapon*>(character.getInventory().getItem(itemIndex)));
            std::cout << "\n\t\tArme equipee!\n";
            break;
        }
        case 4: {
            system("CLS");
            int itemIndex;
            character.getInventory().displayInventoryByType("Armor");
            std::cout << "\tSelectionnez une armure dans l'inventaire (index): ";
            std::cin >> itemIndex;
            character.equipArmor(dynamic_cast<Armor*>(character.getInventory().getItem(itemIndex)));
            std::cout << "\n\t\tArmure equipee!\n";
            break;
        }
        case 5:
            system("CLS");
            searchItems(character.getInventory());
            break;
        case 6:
            system("CLS");
            std::cout << "\n\t\tRetour au menu precedent...\n\n";
            break;
        default:
            std::cout << "\n\t\tOption non valide. Veuillez choisir a nouveau.\n";
        }
    } while (choice != 6);
}

void Menu::showManageCharactersMenu(Character& character1, Character& character2) {
    int choice = 0;
    do {
        system("CLS");
        std::cout << "\n\t\t=== GESTION DES PERSONNAGES ===\n";
        std::cout << "1. Gerer le personnage 1\n";
        std::cout << "2. Gerer le personnage 2\n";
        std::cout << "3. Retour au menu principal\n";
        std::cout << "\n\t\tChoisissez une option: ";
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
            std::cout << "Option non valide. Veuillez choisir a nouveau.\n";
        }
    } while (choice != 3);
}

void Menu::showMainMenu(Character& character1, Character& character2) {
    int choice = 0;
    do {
        system("CLS");
        std::cout << "\n\t\t=== MENU PRINCIPAL ===\n";
        std::cout << "1. Gestion des personnages\n";
        std::cout << "2. Lancer le combat\n";
        std::cout << "3. Quitter\n";
        std::cout << "\n\t\tChoisissez une option: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            showManageCharactersMenu(character1, character2);
            break;
        case 2:
            std::cout << "\n\t\tLancement du combat...\n\n\n";
            Combat::engage(character1, character2);
            break;
        case 3:
            std::cout << "\n\n\n\t\tAu revoir!\n";
            break;
        default:
            std::cout << "\n\t\tOption non valide. Veuillez choisir a nouveau.\n";
        }
    } while (choice != 3);
}
