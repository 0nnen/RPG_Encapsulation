#include "Character.h"

Character::Character(std::string name, ClassType classType)
    : name(name), classType(classType), mainWeapon(nullptr), armor(nullptr), maxHealth(100), health(100), maxStamina(50), stamina(50), synergyDetected(false) {

    // Les competences sont definies selon la classe choisie
    switch (classType) {
    case ClassType::Warrior:
        addSkill(Skill("Trancher", 10, 20));
        addSkill(Skill("Charge", 15, 25));
        break;
    case ClassType::Mage:
        addSkill(Skill("Boule de Feu", 20, 30, true));
        addSkill(Skill("Explosion de Glace", 20, 30, true));
        break;
    case ClassType::Knight:
        addSkill(Skill("Coup de Bouclier", 10, 15));
        addSkill(Skill("Posture Defensive", 20, 0));
        break;
    case ClassType::Assassin:
        addSkill(Skill("Coup Mortel", 15, 35));
        addSkill(Skill("Pas de l'Ombre", 10, 0));
        break;
    case ClassType::Berserker:
        addSkill(Skill("Frappe de Rage", 20, 40));
        addSkill(Skill("Berserk", 10, 50));
        break;
    case ClassType::Paladin:
        addSkill(Skill("Coup Sacre", 15, 20, true));
        addSkill(Skill("Bouclier Divin", 20, 0));
        break;
    case ClassType::Ranger:
        addSkill(Skill("Tir de Fleche", 10, 20));
        addSkill(Skill("Piege", 15, 25));
        break;
    case ClassType::Necromancer:
        addSkill(Skill("Eclair Sombre", 20, 25, true));
        addSkill(Skill("Invocation Mort-Vivant", 25, 0));
        break;
    }
}

ClassType Character::getClassType() const {
    return classType;
}

std::string Character::getClassName(ClassType classType) {
    switch (classType) {
    case ClassType::Warrior: return "Guerrier";
    case ClassType::Mage: return "Mage";
    case ClassType::Knight: return "Chevalier";
    case ClassType::Assassin: return "Assassin";
    case ClassType::Berserker: return "Berserker";
    case ClassType::Paladin: return "Paladin";
    case ClassType::Ranger: return "Archer";
    case ClassType::Necromancer: return "Necromancien";
    default: return "Inconnu";
    }
}

int Character::getHealth() const {
    return health;
}
int Character::getMaxHealth() const {
    return maxHealth;
}

void Character::setHealth(int newHealth) {
    health = std::max(0, std::min(newHealth, maxHealth));
}

int Character::getStamina() const {
    return stamina;
}
int Character::getMaxStamina() const {
    return maxHealth;
}

void Character::setStamina(int newStamina) {
    stamina = std::max(0, std::min(newStamina, maxStamina));
}

std::vector<Skill> Character::getSkills() const {
    return skills;
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
    health -= damage;
    if (health < 0) health = 0;
}

bool Character::isAlive() const {
    return health > 0;
}

void Character::useSkill(Character& opponent, int skillIndex) {
    if (skillIndex >= 0 && skillIndex < skills.size()) {
        Skill& skill = skills[skillIndex];
        if (stamina >= skill.getStaminaCost()) {
            stamina -= skill.getStaminaCost();
            opponent.takeDamage(skill.getDamage());
            std::cout << getClassName(classType) << " utilise " << skill.getName() << " contre " << getClassName(opponent.getClassType()) << " et inflige " << skill.getDamage() << " degats.\n";
        }
        else {
            std::cout << "\n\t" << getClassName(classType) << " est trop fatigue pour utiliser " << skill.getName() << ".\n";
        }
    }
}

void Character::attack(Character& opponent) {
    if (mainWeapon) {
        int damage = mainWeapon->getDamage();
        std::cout << getClassName(classType) << " attaque " << opponent.getName() << " avec " << damage << " degats.\n";

        // Vérification de la synergie
        if (hasElementalSynergy() && !synergyDetected) {
            synergyDetected = true;  // Détection de la synergie une seule fois
            std::cout << "\n\t" << name << " / " << getClassName(classType) << " a une synergie elementaire avec son equipement (" << mainWeapon->getElement() << ")!\n";
        }

        // 30% de chance d'appliquer des dégâts élémentaires
        int chance = rand() % 100;
        if (hasElementalSynergy() && chance < 30) {
            std::cout << "Effet elementaire active pour " << name << " ! Degats supplementaires lies a l'element : " << mainWeapon->getElement() << "\n";
            damage += 10;  // Ajout des dégâts élémentaires
        }
        opponent.takeDamage(damage);
    }
}

StatusEffect Character::getStatusEffectFromSynergy() const {
    // Si l'élément de l'arme et de l'armure correspond, appliquer l'effet de statut
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
        std::cout << "!!! " << getClassName(classType) << " subit l'effet : " << effect.getEffectName() << " !!!\n";
        effect.applyEffect();
    }
}

bool Character::hasElementalSynergy() const {
    // Vérifie que les deux équipements existent et qu'ils ont le même élément
    if (mainWeapon && armor) {
        Element weaponElement = mainWeapon->getElement();
        Element armorElement = armor->getElement();

        // Assure que ni l'arme ni l'armure ne sont de l'élément "None"
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
    return Element::None;  // Aucun élément si pas d'arme
}

void Character::displayCharacterInfo() const {
    std::cout << "Classe: " << getClassName(classType) << "\n";
    std::cout << "Vie: " << health << "/" << maxHealth << "\n";
    std::cout << "Endurance: " << stamina << "/" << maxStamina << "\n";

    // Afficher l'arme équipée
    if (mainWeapon) {
        std::cout << "Arme: " << mainWeapon->getName() << " (Degats: " << mainWeapon->getDamage()
            << ", Element: " << mainWeapon->getElement() << ")\n";
    }
    else {
        std::cout << "Aucune arme equipee\n";
    }

    // Afficher l'armure équipée
    if (armor) {
        std::cout << "Armure: " << armor->getName() << " (Defense: " << armor->getDefense()
            << ", Element: " << armor->getElement() << ")\n";
    }
    else {
        std::cout << "Aucune armure equipee\n";
    }
    std::cout << "Competences:\n";
    for (const auto& skill : skills) {
        std::cout << "  - " << skill.getName() << " (degats: " << skill.getDamage() << ", cout en endurance: " << skill.getStaminaCost() << ")\n";
    }
    std::cout << "\n\n";
}