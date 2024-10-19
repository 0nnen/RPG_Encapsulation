#include "Combat.h"
#include <cstdlib>
#include <ctime>

// Fonction pour obtenir une classe aleatoire
ClassType getRandomClassType() {
    return static_cast<ClassType>(rand() % 8); // Il y a 8 classes dans l'enum ClassType
}

void Combat::engage(Character& character1, Character& character2) {
    // Verification de la synergie elementaire pour chaque personnage
    if (character1.hasElementalSynergy()) {
        std::cout << character1.getName() << " possede une synergie entre son arme et son armure (" << character1.getWeaponElement() << ")!\n";
    }
    if (character2.hasElementalSynergy()) {
        std::cout << character2.getName() << " possede une synergie entre son arme et son armure (" << character2.getWeaponElement() << ")!\n";
    }

    std::cout << "\n\n\n\n\t\t- -- === ---º|COMMENCEMENT DU COMBAT|º--- === -- -\n\n";

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
            std::cout << "\n\t\t" << character2.getName() << " est vaincu ! | Classe : " << Character::getClassName(character1.getClassType()) << "\n"
                << "\t\tVictoire de " << character1.getName() << "  | Classe : " << Character::getClassName(character2.getClassType()) << "\n";
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

        // Afficher la sante des personnages après le tour
        std::cout << "\tºVie de " << character1.getName() << ": " << character1.getHealth() << "/" << character1.getMaxHealth() << "\n";
        std::cout << "\tºVie de " << character2.getName() << ": " << character2.getHealth() << "/" << character2.getMaxHealth() << "\n\n";

        if (!character1.isAlive()) {
            std::cout << "\n\t\t" << character1.getName() << " est vaincu ! | Classe : " << Character::getClassName(character2.getClassType()) << "\n"
				<< "\t\tVictoire de " << character2.getName() << "  | Classe : " << Character::getClassName(character1.getClassType()) << "\n";
            break;
        }
    }

    std::cout << "\n\t\t- -- === ---º|FIN DU COMBAT|º--- === -- -\n";
}
