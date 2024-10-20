#include "Menu.h"
#include <limits>
#include "Combat.h"

void Menu::searchItems(InventoryLib& inventory) {
    std::string name, type, element;
    int minAttack = 0, maxAttack = 0, minDefense = 0, maxDefense = 0;
    int choice = 0;

    system("CLS");
    std::cout << "\n\n\t\tRecherche d'objets:\n";

    while (true) {
        std::cout << "\n\tFaites votre choix:\n";
        std::cout << "1. Nom \n";
        std::cout << "2. Type \n";
        std::cout << "3. Statistiques d'attaque min \n";
        std::cout << "4. Statistiques d'attaque max \n";
        std::cout << "5. Statistiques de defense min \n";
        std::cout << "6. Statistiques de defense max \n";
        std::cout << "7. Element \n";
        std::cout << "8. Lancer la recherche\n";
        std::cout << "9. Reinitialiser la recherche\n";
        std::cout << "10. Quitter\n";
        std::cout << "\n\tEntrez votre choix: ";

        if (!(std::cin >> choice)) {
            system("CLS");
            std::cout << "\n\tErreur: Entrez un nombre valide.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore();

        switch (choice) {
        case 1:
            std::cout << "\t\tEntrez le nom: ";
            std::getline(std::cin, name);
            break;
        case 2:
            std::cout << "\t\tEntrez le type: ";
            std::getline(std::cin, type);
            break;
        case 3:
            std::cout << "\t\tEntrez les statistiques d'attaque min: ";
            while (!(std::cin >> minAttack)) {
                std::cout << "\n\tErreur: Entrez un nombre valide.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            break;
        case 4:
            std::cout << "\t\tEntrez les statistiques d'attaque max: ";
            while (!(std::cin >> maxAttack)) {
                std::cout << "\n\tErreur: Entrez un nombre valide.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            break;
        case 5:
            std::cout << "\t\tEntrez les statistiques de defense min: ";
            while (!(std::cin >> minDefense)) {
                std::cout << "\n\tErreur: Entrez un nombre valide.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            break;
        case 6:
            std::cout << "\t\tEntrez les statistiques de defense max: ";
            while (!(std::cin >> maxDefense)) {
                std::cout << "\n\tErreur: Entrez un nombre valide.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            break;
        case 7:
            std::cout << "\t\tEntrez l'element: ";
            std::getline(std::cin, element);
            break;
        case 8:
            std::cout << "Lancer la recherche...\n";
            {
                auto results = inventory.searchByCriteria(name, type, minAttack, maxAttack, minDefense, maxDefense, element);

                std::cout << "\n\n\t\tResultats de la recherche:\n";
                for (const auto& item : results) {
                    std::cout << item->getName() << " (" << item->getType() << ")\n";
                }
            }
            waitForEnter();
            break;
        case 9:
            name = type = element = "";
            minAttack = maxAttack = minDefense = maxDefense = 0;
            std::cout << "\n\tLes criteres de recherche ont ete reinitialises.\n";
            break;
        case 10:
            std::cout << "Quitter la recherche.\n";
            return;
        default:
            std::cout << "\n\n\t\tChoix invalide, veuillez reessayer.\n";
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

        if (!(std::cin >> choice)) {
            system("CLS");
            std::cout << "\n\tErreur: Entrez un nombre valide.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1:
            system("CLS");
            character.getInventory().displayInventory();
            waitForEnter();
            break;
        case 2:
            system("CLS");
            character.displayCharacterInfo();
            waitForEnter();
            break;
        case 3: {
            system("CLS");
            int itemIndex;
            character.getInventory().displayInventoryByType("Weapon");
            std::cout << "\n\n\tSelectionnez une arme dans l'inventaire (index, ou -1 pour annuler): ";
            while (true) {
                if (!(std::cin >> itemIndex)) {
                    std::cout << "\n\tErreur: Entrez un index valide (ou -1 pour annuler): \t";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                if (itemIndex == -1) {
                    std::cout << "\n\tRetour en arriere...\n\n";
                    break;
                }
                if (itemIndex >= 0 && itemIndex < character.getInventory().getItemCount()) {
                    character.equipWeapon(dynamic_cast<Weapon*>(character.getInventory().getItem(itemIndex)));
                    std::cout << "\n\t\tArme equipee!\n\n";
                    break;
                }
                else {
                    std::cout << "\n\tErreur: Entrez un index valide (ou -1 pour annuler): \t";
                }
            }
            waitForEnter();
            break;
        }
        case 4: {
            system("CLS");
            int itemIndex;
            character.getInventory().displayInventoryByType("Armor");
            std::cout << "\n\n\tSelectionnez une armure dans l'inventaire (index, ou -1 pour annuler): ";
            while (true) {
                if (!(std::cin >> itemIndex)) {
                    std::cout << "\n\tErreur: Entrez un index valide (ou -1 pour annuler): \t";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                if (itemIndex == -1) {
                    std::cout << "\n\tRetour en arriere...\n\n";
                    break;
                }
                if (itemIndex >= 0 && itemIndex < character.getInventory().getItemCount()) {
                    character.equipArmor(dynamic_cast<Armor*>(character.getInventory().getItem(itemIndex)));
                    std::cout << "\n\t\tArmure equipee!\n\n";
                    break;
                }
                else {
                    std::cout << "\n\tErreur: Entrez un index valide (ou -1 pour annuler): \t";
                }
            }
            waitForEnter();
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
            system("CLS");
            std::cout << "\n\tOption non valide. Veuillez choisir a nouveau.\n";
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
        if (!(std::cin >> choice)) {
            system("CLS");
            std::cout << "\n\tErreur: Entrez un nombre valide.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1:
            system("CLS");
            showCharacterMenu(character1);
            break;
        case 2:
            system("CLS");
            showCharacterMenu(character2);
            break;
        case 3:
            std::cout << "\n\t\tRetour au menu principal...\n";
            system("CLS");
            break;
        default:
            system("CLS");
            std::cout << "\n\tOption non valide. Veuillez choisir a nouveau.\n";
        }
    } while (choice != 3);
}

void Menu::showMainMenu(Character& character1, Character& character2) {
    int choice = 0;
    do {
        std::cout << "\n\t\t=== MENU PRINCIPAL ===\n";
        std::cout << "1. Gestion des personnages\n";
        std::cout << "2. Lancer le combat\n";
        std::cout << "3. Quitter\n";
        std::cout << "\n\t\tChoisissez une option: ";
        if (!(std::cin >> choice)) {
            system("CLS");
            std::cout << "\n\tErreur: Entrez un nombre valide.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

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
			system("CLS");
            std::cout << "\n\tOption non valide. Veuillez choisir a nouveau.\n";
        }
    } while (choice != 3);
}

void Menu::waitForEnter() {
    std::cout << "Appuyez sur Entree pour continuer...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}
