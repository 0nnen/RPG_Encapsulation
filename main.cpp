#include <iostream>
#include <map>
#include <vector>
#include "Character.h"
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"
#include "Combat.h"
#include "Inventory.h"
#include <cstdlib>
#include <ctime>

int main() {
    srand(static_cast<unsigned>(time(0))); // Initialisation du générateur de nombres aléatoires

    // Création d'un inventaire
    Inventory inventory;

    // Armes spécifiques pour chaque classe (2 armes par classe) avec std::unique_ptr
    auto warriorSword = std::make_unique<Weapon>("Epee du Guerrier", 25, false, Element::None);
    auto warriorAxe = std::make_unique<Weapon>("Hache du Guerrier", 35, true, Element::Fire);
    auto mageStaff = std::make_unique<Weapon>("Baton du Mage", 20, true, Element::Ice);
    auto mageWand = std::make_unique<Weapon>("Baguette du Mage", 15, false, Element::Fire);
    auto knightSword = std::make_unique<Weapon>("Epee du Chevalier", 30, false, Element::None);
    auto knightLance = std::make_unique<Weapon>("Lance du Chevalier", 40, true, Element::Divine);
    auto assassinDagger = std::make_unique<Weapon>("Dague de l'Assassin", 18, false, Element::Poison);
    auto assassinBlade = std::make_unique<Weapon>("Lame de l'Assassin", 25, false, Element::Dark);
    auto berserkerAxe = std::make_unique<Weapon>("Hache du Berserker", 35, true, Element::Fire);
    auto berserkerClub = std::make_unique<Weapon>("Massue du Berserker", 30, false, Element::None);
    auto paladinMace = std::make_unique<Weapon>("Masse du Paladin", 30, false, Element::Divine);
    auto paladinHammer = std::make_unique<Weapon>("Marteau du Paladin", 40, true, Element::Divine);
    auto rangerBow = std::make_unique<Weapon>("Arc du Ranger", 20, true, Element::None);
    auto rangerCrossbow = std::make_unique<Weapon>("Arbalete du Ranger", 25, false, Element::Ice);
    auto necromancerStaff = std::make_unique<Weapon>("Baton du Necromancien", 20, true, Element::Dark);
    auto necromancerDagger = std::make_unique<Weapon>("Dague du Necromancien", 15, false, Element::Poison);

    // Ajouter les armes à l'inventaire avec std::move
    inventory.addItem(std::move(warriorSword));
    inventory.addItem(std::move(warriorAxe));
    inventory.addItem(std::move(mageStaff));
    inventory.addItem(std::move(mageWand));
    inventory.addItem(std::move(knightSword));
    inventory.addItem(std::move(knightLance));
    inventory.addItem(std::move(assassinDagger));
    inventory.addItem(std::move(assassinBlade));
    inventory.addItem(std::move(berserkerAxe));
    inventory.addItem(std::move(berserkerClub));
    inventory.addItem(std::move(paladinMace));
    inventory.addItem(std::move(paladinHammer));
    inventory.addItem(std::move(rangerBow));
    inventory.addItem(std::move(rangerCrossbow));
    inventory.addItem(std::move(necromancerStaff));
    inventory.addItem(std::move(necromancerDagger));

    // Armures spécifiques pour chaque classe (2 armures par classe)
    auto warriorArmor1 = std::make_unique<Armor>("Armure de Cuir", 10, Element::None);
    auto warriorArmor2 = std::make_unique<Armor>("Armure de Feu", 15, Element::Fire);
    auto mageArmor1 = std::make_unique<Armor>("Robe de Glace", 8, Element::Ice);
    auto mageArmor2 = std::make_unique<Armor>("Robe de Feu", 8, Element::Fire);
    auto knightArmor1 = std::make_unique<Armor>("Armure Lourde", 20, Element::None);
    auto knightArmor2 = std::make_unique<Armor>("Armure Divine", 25, Element::Divine);
    auto assassinArmor1 = std::make_unique<Armor>("Armure Legere", 10, Element::Dark);
    auto assassinArmor2 = std::make_unique<Armor>("Armure Empoisonnee", 12, Element::Poison);
    auto berserkerArmor1 = std::make_unique<Armor>("Armure de Rage", 12, Element::Fire);
    auto berserkerArmor2 = std::make_unique<Armor>("Armure de Cuir", 10, Element::None);
    auto paladinArmor1 = std::make_unique<Armor>("Armure Sacrée", 18, Element::Divine);
    auto paladinArmor2 = std::make_unique<Armor>("Armure Benie", 20, Element::Divine);
    auto rangerArmor1 = std::make_unique<Armor>("Armure de Cuir", 12, Element::None);
    auto rangerArmor2 = std::make_unique<Armor>("Armure de Glace", 14, Element::Ice);
    auto necromancerArmor1 = std::make_unique<Armor>("Robe des Ombres", 8, Element::Dark);
    auto necromancerArmor2 = std::make_unique<Armor>("Robe Empoisonne", 10, Element::Poison);

    // Ajouter les armures à l'inventaire avec std::move
    inventory.addItem(std::move(warriorArmor1));
    inventory.addItem(std::move(warriorArmor2));
    inventory.addItem(std::move(mageArmor1));
    inventory.addItem(std::move(mageArmor2));
    inventory.addItem(std::move(knightArmor1));
    inventory.addItem(std::move(knightArmor2));
    inventory.addItem(std::move(assassinArmor1));
    inventory.addItem(std::move(assassinArmor2));
    inventory.addItem(std::move(berserkerArmor1));
    inventory.addItem(std::move(berserkerArmor2));
    inventory.addItem(std::move(paladinArmor1));
    inventory.addItem(std::move(paladinArmor2));
    inventory.addItem(std::move(rangerArmor1));
    inventory.addItem(std::move(rangerArmor2));
    inventory.addItem(std::move(necromancerArmor1));
    inventory.addItem(std::move(necromancerArmor2));

    // Map pour associer les classes et leurs armes
    std::map<ClassType, std::vector<Weapon*>> classWeapons = {
        {ClassType::Warrior, {dynamic_cast<Weapon*>(inventory.getItem(0)), dynamic_cast<Weapon*>(inventory.getItem(1))}},
        {ClassType::Mage, {dynamic_cast<Weapon*>(inventory.getItem(2)), dynamic_cast<Weapon*>(inventory.getItem(3))}},
        {ClassType::Knight, {dynamic_cast<Weapon*>(inventory.getItem(4)), dynamic_cast<Weapon*>(inventory.getItem(5))}},
        {ClassType::Assassin, {dynamic_cast<Weapon*>(inventory.getItem(6)), dynamic_cast<Weapon*>(inventory.getItem(7))}},
        {ClassType::Berserker, {dynamic_cast<Weapon*>(inventory.getItem(8)), dynamic_cast<Weapon*>(inventory.getItem(9))}},
        {ClassType::Paladin, {dynamic_cast<Weapon*>(inventory.getItem(10)), dynamic_cast<Weapon*>(inventory.getItem(11))}},
        {ClassType::Ranger, {dynamic_cast<Weapon*>(inventory.getItem(12)), dynamic_cast<Weapon*>(inventory.getItem(13))}},
        {ClassType::Necromancer, {dynamic_cast<Weapon*>(inventory.getItem(14)), dynamic_cast<Weapon*>(inventory.getItem(15))}}
    };

    // Map pour associer les classes et leurs armures
    std::map<ClassType, std::vector<Armor*>> classArmors = {
        {ClassType::Warrior, {dynamic_cast<Armor*>(inventory.getItem(16)), dynamic_cast<Armor*>(inventory.getItem(17))}},
        {ClassType::Mage, {dynamic_cast<Armor*>(inventory.getItem(18)), dynamic_cast<Armor*>(inventory.getItem(19))}},
        {ClassType::Knight, {dynamic_cast<Armor*>(inventory.getItem(20)), dynamic_cast<Armor*>(inventory.getItem(21))}},
        {ClassType::Assassin, {dynamic_cast<Armor*>(inventory.getItem(22)), dynamic_cast<Armor*>(inventory.getItem(23))}},
        {ClassType::Berserker, {dynamic_cast<Armor*>(inventory.getItem(24)), dynamic_cast<Armor*>(inventory.getItem(25))}},
        {ClassType::Paladin, {dynamic_cast<Armor*>(inventory.getItem(26)), dynamic_cast<Armor*>(inventory.getItem(27))}},
        {ClassType::Ranger, {dynamic_cast<Armor*>(inventory.getItem(28)), dynamic_cast<Armor*>(inventory.getItem(29))}},
        {ClassType::Necromancer, {dynamic_cast<Armor*>(inventory.getItem(30)), dynamic_cast<Armor*>(inventory.getItem(31))}}
    };

    // Choisir deux classes aléatoirement
    ClassType classType1 = getRandomClassType();
    ClassType classType2 = getRandomClassType();

    // Créer les personnages
    Character character1("Personnage 1", classType1);
    Character character2("Personnage 2", classType2);

    // Associer les armes et armures aux personnages en fonction de leur classe
    character1.equipWeapon(classWeapons[classType1][0]);  // Première arme de la classe
    character1.equipArmor(classArmors[classType1][0]);    // Première armure de la classe
    character2.equipWeapon(classWeapons[classType2][1]);  // Deuxième arme de la classe
    character2.equipArmor(classArmors[classType2][1]);    // Deuxième armure de la classe

    // Afficher les informations des personnages avant le combat
    std::cout << "\n\t\tInformations du Personnage 1:\n";
    character1.displayCharacterInfo();
    std::cout << "\n\t\tInformations du Personnage 2:\n";
    character2.displayCharacterInfo();

    // Combat
    Combat::engage(character1, character2);

    return 0;
}
