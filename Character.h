#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Weapon.h"
#include "Armor.h"
#include "Skill.h"
#include "Inventory.h"
#include "StatusEffect.h"

enum class ClassType {
    Warrior,
    Mage,
    Knight,
    Assassin,
    Berserker,
    Paladin,
    Ranger,
    Necromancer
};

class Character {
private:
    std::string name;
    ClassType classType;
    int health;
    int maxHealth;
    int stamina;
    int maxStamina;
    bool synergyDetected;
    Weapon* mainWeapon;
    Armor* armor;
    std::vector<Skill> skills;
    Inventory inventory;

public:
    Character(std::string name, ClassType classType);

    // Encapsulation des stats
    int getHealth() const;
    void setHealth(int health);
    int getMaxHealth() const;
    int getStamina() const;
    void setStamina(int stamina);
    int getMaxStamina() const;

    // Méthodes d'équipement et de gestion
    void equipWeapon(Weapon* weapon);
    void equipArmor(Armor* armor);
    void addSkill(Skill skill);

    // Méthodes de combat
    void takeDamage(int damage);
    bool isAlive() const;
    void useSkill(Character& opponent, int skillIndex);
    void attack(Character& opponent);
    bool hasElementalSynergy() const;
    Element getWeaponElement() const;

    // Fonctions pour gérer les effets de statut
    StatusEffect getStatusEffectFromSynergy() const;
    void applyStatusEffect(StatusEffect statusEffect);

    std::vector<Skill> getSkills() const;

    // Fonction pour afficher les infos du personnage avant le combat
    void displayCharacterInfo() const;

    std::string getName() const { return name; }
    ClassType getClassType() const;
    static std::string getClassName(ClassType classType);
};
