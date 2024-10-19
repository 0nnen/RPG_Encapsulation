#include "Character.h"

Character::Character(std::string name, const std::string& className)
    : name(name), className(className), mainWeapon(nullptr), armor(nullptr),
    maxHealth(100), health(100), maxStamina(50), stamina(50), defense(0), defenseBuff(0),
    attackBuff(0), evadeChance(0), synergyDetected(false) {}

void Character::initializeSkills(const std::vector<Class>& classes) {
    for (const auto& characterClass : classes) {
        if (characterClass.getName() == className) {
            for (const auto& skill : characterClass.getSkills()) {
                addSkill(skill);
            }
            break;
        }
    }
}

void Character::setHealth(int newHealth) {
    health = std::max(0, std::min(newHealth, maxHealth));
}

void Character::setStamina(int newStamina) {
    stamina = std::max(0, std::min(newStamina, maxStamina));
}

void Character::addSkill(Skill skill) {
    skills.push_back(skill);
}

void Character::equipWeapon(Weapon* weapon) {
    if (weapon != nullptr) {
        mainWeapon = weapon;
    }
}

void Character::equipArmor(Armor* armor) {
    if (armor != nullptr) {
        this->armor = armor;
    }
}

void Character::takeDamage(int damage) {
    // Verifie si le personnage esquive l'attaque
    int chance = rand() % 100;
    if (chance < evadeChance) {
        std::cout << name << " a esquive l'attaque !\n";
        return;  // Aucun degat n'est subi
    }

    // Calcul de la defense totale avec le buff de defense
    int totalDefense = defense + defenseBuff;
    int damageReduced = std::max(0, damage - totalDefense);

    // Mise à jour de la vie apres reduction des degats
    health -= damageReduced;
    if (health < 0) health = 0;

    std::cout << name << " subit " << damageReduced << " degats (reduction de " << totalDefense << " points de defense).\n";
}

bool Character::isAlive() const {
    return health > 0;
}

void Character::useSkill(Character& opponent, int skillIndex) {
    if (skillIndex >= 0 && skillIndex < skills.size()) {
        Skill& skill = skills[skillIndex];

        if (stamina >= skill.getStaminaCost()) {
            stamina -= skill.getStaminaCost();

            if (skill.getIsHealing()) {
                setHealth(health + skill.getDamage()); // Soigner le personnage
                std::cout << className << " utilise " << skill.getName()
                    << " et se soigne de " << skill.getDamage() << " points de vie.\n";
            }
            else if (skill.getIsBuffDefense()) {
                increaseDefense(skill.getDamage()); // Buff de defense
                std::cout << className << " utilise " << skill.getName()
                    << " et augmente sa defense de " << skill.getDamage() << " points.\n";
            }
            else if (skill.getIsBuffAttack()) {
                increaseAttack(skill.getDamage()); // Buff d'attaque
                std::cout << className << " utilise " << skill.getName()
                    << " et augmente son attaque de " << skill.getDamage() << " points.\n";
            }
            else {
                opponent.takeDamage(skill.getDamage()); // Degats d'attaque
                std::cout << className << " utilise " << skill.getName()
                    << " contre " << opponent.getName() << " et inflige "
                    << skill.getDamage() << " points de degats.\n";
            }
        }
        else {
            std::cout << "\n\t" << className << " est trop fatigue pour utiliser " << skill.getName() << ".\n";
        }
    }
}

void Character::attack(Character& opponent) {
    if (mainWeapon) {
        int damage = mainWeapon->getAttack() + attackBuff;
        std::cout << className << " attaque " << opponent.getName() << " avec " << damage << " degats.\n";

        // Verification de la synergie
        if (hasElementalSynergy() && !synergyDetected) {
            synergyDetected = true;
            std::cout << "\n\t" << name << " / " << className << " a une synergie elementaire avec son equipement (" << mainWeapon->getElement() << ")!\n";
        }

        // 30% de chance d'appliquer des degats elementaires
        int chance = rand() % 100;
        if (hasElementalSynergy() && chance < 30) {
            std::cout << "Effet elementaire active pour " << name << " ! Degats supplementaires lies à l'element : " << mainWeapon->getElement() << "\n";
            damage += 10;
        }

        opponent.takeDamage(damage);
    }
}

// Augmenter l'attaque temporaire
void Character::increaseAttack(int amount) {
    attackBuff += amount;
    std::cout << name << " augmente son attaque de " << amount << " points.\n";
}

// Augmenter la defense temporaire
void Character::increaseDefense(int amount) {
    defenseBuff += amount;
    std::cout << name << " augmente sa defense de " << amount << " points.\n";
}

// Augmenter la chance d'esquiver
void Character::increaseEvadeChance(int amount) {
    evadeChance += amount;
    std::cout << name << " augmente sa chance d'esquiver de " << amount << "%.\n";
}

StatusEffect Character::getStatusEffectFromSynergy() const {
    // Si l'element de l'arme et de l'armure correspond, appliquer l'effet de statut
    if (mainWeapon && armor && mainWeapon->getElement() == armor->getElement()) {
        switch (mainWeapon->getElement()) {
        case Element::Fire: return StatusEffect(StatusEffectType::Enflamme, 3);
        case Element::Ice: return StatusEffect(StatusEffectType::Froid, 3);
        case Element::Poison: return StatusEffect(StatusEffectType::Poisoned, 3);
        case Element::Divine: return StatusEffect(StatusEffectType::Divin, 3);
        case Element::Dark: return StatusEffect(StatusEffectType::Tenebre, 3);
        default: return StatusEffect(StatusEffectType::None, 0);
        }
    }
    // Si pas de synergie, pas d'effet
    return StatusEffect(StatusEffectType::None, 0);
}

void Character::applyStatusEffect(StatusEffect effect) {
    if (effect.getEffectType() != StatusEffectType::None) {
        std::cout << "!!! " << className << " subit l'effet : " << effect.getEffectName() << " !!!\n";
        effect.applyEffect();
    }
}

bool Character::hasElementalSynergy() const {
    // Verifie que les deux equipements existent et qu'ils ont le même element
    if (mainWeapon && armor) {
        Element weaponElement = mainWeapon->getElement();
        Element armorElement = armor->getElement();

        // Assure que ni l'arme ni l'armure ne sont de l'element "None"
        if (weaponElement != Element::None && armorElement != Element::None) {
            return weaponElement == armorElement;
        }
    }
    return false;
}

Element Character::getWeaponElement() const {
    if (mainWeapon) {
        return mainWeapon->getElement();
    }
    return Element::None;  // Aucun element si pas d'arme
}

void Character::displayCharacterInfo() const {
    std::cout << "Classe: " << className << "\n";
    std::cout << "Vie: " << health << "/" << maxHealth << "\n";
    std::cout << "Endurance: " << stamina << "/" << maxStamina << "\n";

    // Afficher l'arme equipee
    if (mainWeapon) {
        std::cout << "Arme: " << mainWeapon->getName() << " (Degats: " << mainWeapon->getAttack()
            << ", Element: " << mainWeapon->getElement() << ")\n";
    }
    else {
        std::cout << "Aucune arme equipee\n";
    }

    // Afficher l'armure et la defense avec le buff
    if (armor) {
        std::cout << "Armure: " << armor->getName() << " (Defense: " << armor->getDefense()
            << ", Element: " << armor->getElement() << ")\n";
    }
    else {
        std::cout << "Aucune armure equipee\n";
    }
    std::cout << "Defense totale (incluant le buff): " << defense + defenseBuff << "\n";
    std::cout << "Competences:\n";
    for (const auto& skill : skills) {
        std::cout << "  - " << skill.getName() << " (degats: " << skill.getDamage() << ", cout en endurance: " << skill.getStaminaCost() << ")\n";
    }
    std::cout << "\n\n";
}
