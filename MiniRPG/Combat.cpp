#include "Combat.h"
#include <cstdlib>
#include <ctime>
#include "ParsingLib.h"

// Fonction pour obtenir une classe al�atoire
std::string getRandomClassName(const std::vector<Class>& classes) {
    int randomIndex = rand() % classes.size();
    return classes[randomIndex].getName();
}

void Combat::engage(Character& character1, Character& character2) {
    // Verification de la synergie elementaire pour chaque personnage
    if (character1.hasElementalSynergy()) {
        std::cout << character1.getName() << " poss�de une synergie entre son arme et son armure (" << character1.getWeaponElement() << ")!\n";
    }
    if (character2.hasElementalSynergy()) {
        std::cout << character2.getName() << " poss�de une synergie entre son arme et son armure (" << character2.getWeaponElement() << ")!\n";
    }

    std::cout << "\n\n\n\n\t\t- -- === ---�|COMMENCEMENT DU COMBAT|�--- === -- -\n\n";

    while (character1.isAlive() && character2.isAlive()) {
        // Tour du premier personnage
        if (rand() % 2 == 0) {
            // Attaque de base
            character1.attack(character2);
        }
        else {
            // Utiliser une competence aleatoire
            int skillIndex = rand() % character1.getSkills().size();
            character1.useSkill(character2, skillIndex);
        }

        if (!character2.isAlive()) {
            std::cout << "\n\t\t" << character2.getName() << " est vaincu ! | Classe : " << character1.getClassName() << "\n"
                << "\t\tVictoire de " << character1.getName() << "  | Classe : " << character1.getClassName() << "\n";
            break;
        }

        // Le tour du deuxieme personnage
        if (rand() % 2 == 0) {
            character2.attack(character1);
        }
        else {
            int skillIndex = rand() % character2.getSkills().size();
            character2.useSkill(character1, skillIndex);
        }

        // Afficher la sante des personnages apr�s le tour
        std::cout << "\t�Vie de " << character1.getName() << ": " << character1.getHealth() << "/" << character1.getMaxHealth() << "\n";
        std::cout << "\t�Vie de " << character2.getName() << ": " << character2.getHealth() << "/" << character2.getMaxHealth() << "\n\n";

        if (!character1.isAlive()) {
            std::cout << "\n\t\t" << character1.getName() << " est vaincu ! | Classe : " << character2.getClassName() << "\n"
                << "\t\tVictoire de " << character2.getName() << "  | Classe : " << character2.getClassName() << "\n";
            break;
        }
    }

    std::cout << "\n\t\t- -- === ---�|FIN DU COMBAT|�--- === -- -\n";
}