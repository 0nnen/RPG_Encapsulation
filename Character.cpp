#include "Character.h"

Character::Character(std::string name, ClassType classType)
    : name(name), classType(classType), mainWeapon(nullptr), armor(nullptr),
    maxHealth(100), health(100), maxStamina(50), stamina(50), defense(0), defenseBuff(0),
    attackBuff(0), evadeChance(0), synergyDetected(false) {

    // Les compétences sont définies selon la classe choisie
    switch (classType) {
    case ClassType::Warrior:
        addSkill(Skill("Trancher", 10, 20));                     // Attaque de base
        addSkill(Skill("Charge", 15, 25));                       // Attaque avec bonus de force
        addSkill(Skill("Coup Puissant", 20, 30));                // Attaque forte
        addSkill(Skill("Cri de Guerre", 0, 10, false, false, false, true));  // Buff défense (valeur remplacée par 10)
        addSkill(Skill("Frappe Eclair", 25, 35));                // Attaque rapide
        addSkill(Skill("Tourbillon", 18, 20));                   // Attaque multiple
        break;

    case ClassType::Mage:
        addSkill(Skill("Boule de Feu", 20, 30, true));           // Attaque élémentaire Feu
        addSkill(Skill("Explosion de Glace", 20, 30, true));     // Attaque élémentaire Glace
        addSkill(Skill("Choc Electrique", 15, 20, true));        // Attaque élémentaire Foudre
        addSkill(Skill("Soin Magique", 25, 0, true, true));      // Soin (25 points de soins, remplacé dans "dégâts")
        addSkill(Skill("Tempete Arcane", 30, 40, true));         // Dégâts en zone
        addSkill(Skill("Mur de Glace", 15, 0, false, false, false, true));  // Buff défense (15 points de buff, remplacé dans "dégâts")
        break;

    case ClassType::Knight:
        addSkill(Skill("Coup de Bouclier", 10, 15));             // Attaque avec bonus de défense
        addSkill(Skill("Posture Defensive", 20, 0, false, false, false, true));  // Buff défense (20 points)
        addSkill(Skill("Lame Divine", 25, 35, true));            // Attaque divine
        addSkill(Skill("Charge Du Chevalier", 25, 0, false, false, true, false)); // Buff attaque (25 points)
        addSkill(Skill("Barriere Divine", 25, 0, false, false, false, true));  // Buff défense (25 points)
        addSkill(Skill("Frappe Juste", 30, 40));                 // Attaque critique
        break;

    case ClassType::Assassin:
        addSkill(Skill("Coup Mortel", 15, 35));                  // Attaque critique
        addSkill(Skill("Pas de l'Ombre", 10, 0, false, false, false, true));   // Esquive (buff esquive de 10%)
        addSkill(Skill("Coup Rapide", 12, 15));                  // Attaque rapide
        addSkill(Skill("Lame Empoisonnee", 10, 20, true));       // Attaque avec poison
        addSkill(Skill("Attaque Sournoise", 25, 35));            // Attaque surprise
        addSkill(Skill("Frappe Furtive", 20, 30));               // Attaque furtive
        break;

    case ClassType::Berserker:
        addSkill(Skill("Frappe de Rage", 20, 40));               // Attaque forte
        addSkill(Skill("Berserk", 50, 0, false, false, true, false));  // Buff attaque (50 points)
        addSkill(Skill("Coup Frontal", 15, 25));                 // Attaque directe
        addSkill(Skill("Cri Sauvage", 10, 0, false, false, false, true));  // Buff vitesse (10 points)
        addSkill(Skill("Attaque Devastatrice", 30, 45));         // Attaque lourde
        addSkill(Skill("Sanguinaire", 25, 35, true, true));      // Attaque avec gain de vie
        break;

    case ClassType::Paladin:
        addSkill(Skill("Coup Sacre", 15, 20, true));             // Attaque élémentaire divine
        addSkill(Skill("Bouclier Divin", 20, 0, false, false, false, true));   // Buff défense (20 points)
        addSkill(Skill("Soin Divin", 25, 0, true, true));        // Soin (25 points)
        addSkill(Skill("Frappe Celeste", 25, 30, true));         // Attaque élémentaire
        addSkill(Skill("Protection Divine", 30, 0, false, false, false, true)); // Bouclier (30 points de défense)
        addSkill(Skill("Jugement Divin", 35, 45, true));         // Attaque divine puissante
        break;

    case ClassType::Ranger:
        addSkill(Skill("Tir de Fleche", 10, 20));                // Attaque à distance
        addSkill(Skill("Piege", 15, 25));                        // Piège qui blesse
        addSkill(Skill("Fleche Empoisonnee", 10, 20, true));     // Poison
        addSkill(Skill("Tir Precis", 20, 30));                   // Attaque critique
        addSkill(Skill("Tir Explosif", 25, 35));                 // Attaque en zone
        addSkill(Skill("Furtivite", 10, 0, false, false, false, true)); // Buff esquive (10 points)
        break;

    case ClassType::Necromancer:
        addSkill(Skill("Eclair Sombre", 20, 25, true));          // Attaque élémentaire
        addSkill(Skill("Drain de Vie", 30, 0, true, true));      // Vol de vie (30 points)
        addSkill(Skill("Explosion de Cadavres", 30, 40, true));  // Attaque en zone
        addSkill(Skill("Siphon d'Ame", 20, 0, true, true));      // Buff de vie (20 points)
        addSkill(Skill("Fleau Sombre", 35, 45, true));           // Attaque puissante avec debuff
        break;
    }
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
    // Vérifie si le personnage esquive l'attaque
    int chance = rand() % 100;
    if (chance < evadeChance) {
        std::cout << name << " a esquive l'attaque !\n";
        return;  // Aucun dégât n'est subi
    }

    // Calcul de la défense totale avec le buff de défense
    int totalDefense = defense + defenseBuff;
    int damageReduced = std::max(0, damage - totalDefense);

    // Mise à jour de la vie après réduction des dégâts
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
                std::cout << getClassName(classType) << " utilise " << skill.getName()
                    << " et se soigne de " << skill.getDamage() << " points de vie.\n";
            }
            else if (skill.getIsBuffDefense()) {
                increaseDefense(skill.getDamage()); // Buff de défense
                std::cout << getClassName(classType) << " utilise " << skill.getName()
                    << " et augmente sa defense de " << skill.getDamage() << " points.\n";
            }
            else if (skill.getIsBuffAttack()) {
                increaseAttack(skill.getDamage()); // Buff d'attaque
                std::cout << getClassName(classType) << " utilise " << skill.getName()
                    << " et augmente son attaque de " << skill.getDamage() << " points.\n";
            }
            else {
                opponent.takeDamage(skill.getDamage()); // Dégâts d'attaque
                std::cout << getClassName(classType) << " utilise " << skill.getName()
                    << " contre " << opponent.getName() << " et inflige "
                    << skill.getDamage() << " points de degats.\n";
            }
        }
        else {
            std::cout << "\n\t" << getClassName(classType) << " est trop fatigue pour utiliser " << skill.getName() << ".\n";
        }
    }
}


void Character::attack(Character& opponent) {
    if (mainWeapon) {
        int damage = mainWeapon->getDamage() + attackBuff;
        std::cout << getClassName(classType) << " attaque " << opponent.getName() << " avec " << damage << " degats.\n";

        // Vérification de la synergie
        if (hasElementalSynergy() && !synergyDetected) {
            synergyDetected = true;
            std::cout << "\n\t" << name << " / " << getClassName(classType) << " a une synergie elementaire avec son equipement (" << mainWeapon->getElement() << ")!\n";
        }

        // 30% de chance d'appliquer des dégâts élémentaires
        int chance = rand() % 100;
        if (hasElementalSynergy() && chance < 30) {
            std::cout << "Effet elementaire active pour " << name << " ! Degats supplementaires lies a l'element : " << mainWeapon->getElement() << "\n";
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

    // Afficher l'armure et la défense avec le buff
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
