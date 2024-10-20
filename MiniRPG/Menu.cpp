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
        std::cout << "6. Ajouter ou supprimer un objet\n"; 
        std::cout << "7. Retour\n";
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

            int sortChoice;
            do {
                std::cout << "\n\tSouhaitez-vous trier l'inventaire ?\n";
                std::cout << "1. Trier par nom (ascendant)\n";
                std::cout << "2. Trier par nom (descendant)\n";
                std::cout << "3. Trier par type (ascendant)\n";
                std::cout << "4. Trier par type (descendant)\n";
                std::cout << "5. Trier par élément (ascendant)\n";
                std::cout << "6. Trier par élément (descendant)\n";
                std::cout << "7. Trier par attaque (ascendant)\n";
                std::cout << "8. Trier par attaque (descendant)\n";
                std::cout << "9. Trier par défense (ascendant)\n";
                std::cout << "10. Trier par défense (descendant)\n";
                std::cout << "11. Quitter\n";
                std::cout << "\n\t\tChoisissez une option: ";

                if (!(std::cin >> sortChoice)) {
                    std::cout << "\n\tErreur: Entrez un nombre valide.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }

                switch (sortChoice) {
                case 1: // Option pour trier par nom (ascendant)
                    character.getInventory().sortByName(true); // Tri ascendant
                    system("CLS");
                    std::cout << "\n\tInventaire trié par nom (ascendant) :\n";
                    character.getInventory().displayInventory();
                    break;
                case 2: // Option pour trier par nom (descendant)
                    character.getInventory().sortByName(false); // Tri descendant
                    system("CLS");
                    std::cout << "\n\tInventaire trié par nom (descendant) :\n";
                    character.getInventory().displayInventory();
                    break;
                case 3: // Option pour trier par type (ascendant)
                    character.getInventory().sortByType(true);
                    system("CLS");
                    std::cout << "\n\tInventaire trié par type (ascendant) :\n";
                    character.getInventory().displayInventory();
                    break;
                case 4: // Option pour trier par type (descendant)
                    character.getInventory().sortByType(false);
                    system("CLS");
                    std::cout << "\n\tInventaire trié par type (descendant) :\n";
                    character.getInventory().displayInventory();
                    break;
                case 5: // Option pour trier par élément (ascendant)
                    character.getInventory().sortByElement(true);
                    system("CLS");
                    std::cout << "\n\tInventaire trié par élément (ascendant) :\n";
                    character.getInventory().displayInventory();
                    break;
                case 6: // Option pour trier par élément (descendant)
                    character.getInventory().sortByElement(false);
                    system("CLS");
                    std::cout << "\n\tInventaire trié par élément (descendant) :\n";
                    character.getInventory().displayInventory();
                    break;
                case 7: // Option pour trier par attaque (ascendant)
                    character.getInventory().sortWeaponsByAttackAscending();
                    system("CLS");
                    std::cout << "\n\tInventaire trié par attaque (ascendant) :\n";
                    character.getInventory().displayInventory();
                    break;
                case 8: // Option pour trier par attaque (descendant)
                    character.getInventory().sortWeaponsByAttackDescending();
                    system("CLS");
                    std::cout << "\n\tInventaire trié par attaque (descendant) :\n";
                    character.getInventory().displayInventory();
                    break;
                case 9: // Option pour trier par défense (ascendant)
                    character.getInventory().sortArmorsByDefenseAscending();
                    system("CLS");
                    std::cout << "\n\tInventaire trié par défense (ascendant) :\n";
                    character.getInventory().displayInventory();
                    break;
                case 10: // Option pour trier par défense (descendant)
                    character.getInventory().sortArmorsByDefenseDescending();
                    system("CLS");
                    std::cout << "\n\tInventaire trié par défense (descendant) :\n";
                    character.getInventory().displayInventory();
                    break;
                case 11:
                    system("CLS");
                    std::cout << "\n\tQuitter l'affichage de l'inventaire.\n";
                    break;
                default:
                    std::cout << "\n\tOption non valide. Veuillez choisir à nouveau.\n";
                }

            } while (sortChoice != 11); // Continue until user chooses to quit


            waitForEnter();
            break;
        case 2:
            system("CLS");
            character.displayCharacterInfo();
            waitForEnter();
            break;
        case 3: {
            system("CLS");
            int sortOrder;
            std::cout << "\n\tChoisissez l'ordre de tri des armes :\n";
            std::cout << "1. Ordre alphabétique (A-Z)\n";
            std::cout << "2. Ordre alphabétique inversé (Z-A)\n";
            std::cin >> sortOrder;

            bool ascending = (sortOrder == 1);
            character.getInventory().sortWeaponsByName(ascending); // Tri par nom des armes

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
            manageInventory(character); 
            break;
        case 7:
            system("CLS");
            std::cout << "\n\t\tRetour au menu precedent...\n\n";
            break;
        default:
            system("CLS");
            std::cout << "\n\tOption non valide. Veuillez choisir a nouveau.\n";
        }
    } while (choice != 7);
}
void Menu::manageInventory(Character& character) {
    int choice = 0;
    do {
        std::cout << "\n\t\t=== GERER L'INVENTAIRE ===\n";
        std::cout << "1. Ajouter un objet par index\n";
        std::cout << "2. Supprimer un objet\n";
        std::cout << "3. Retour\n";
        std::cout << "\n\t\tChoisissez une option: ";

        std::cin >> choice;

        switch (choice) {
        case 1: {
            // Afficher les objets disponibles
            auto availableItems = character.getInventory().getAvailableItems();
            std::cout << "\nObjets disponibles :\n";
            for (size_t i = 0; i < availableItems.size(); ++i) {
                std::cout << i << ". " << availableItems[i]->getName() << "\n";
            }

            int itemIndex;
            std::cout << "\n\tEntrez l'index de l'objet à ajouter: ";
            std::cin >> itemIndex;

            if (character.getInventory().addItemByIndex(itemIndex, availableItems)) {
                std::cout << "\n\tObjet ajouté.\n";
            }
            else {
                std::cout << "\n\tÉchec de l'ajout de l'objet.\n";
            }
            break;
        }
        case 2:
            // Votre logique pour supprimer un objet
            break;
        case 3:
            std::cout << "\n\tRetour au menu précédent...\n";
            break;
        default:
            std::cout << "\n\tOption non valide. Veuillez choisir à nouveau.\n";
        }
    } while (choice != 3);
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

void Menu::showMainMenu(Character& character1, Character& character2, const std::vector<std::unique_ptr<Item>>& availableItems) {
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
