#pragma once
#include <vector>
#include <iostream>
#include <memory>
#include <string>
#include <algorithm>
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include "Element.h"
#include "Rarity.h"

class InventoryLib {
private:
    std::vector<std::unique_ptr<Item>> items;

public:
    void addItem(std::unique_ptr<Item> item);
    Item* getItem(int index);
    void displayInventoryByType(const std::string& type) const;
    void displayInventory() const;
    void addItemsFromList(const std::vector<std::unique_ptr<Item>>& allItems);
    void addRandomItems(const std::vector<std::unique_ptr<Item>>& allItems, int itemCount);
    size_t getSize() const { return items.size(); }
    bool removeItem(int index); 
    std::vector<Item*> searchByStat(int minStat, int maxStat) const;

    void sortByName(bool ascending = true);  
    void sortByType(bool ascending = true);
    void sortByStat(bool ascending = true);  
    void sortByElement(bool ascending);
    void sortByRarity(bool ascending = true); 
    void sortWeaponsByName(bool ascending = true);

    void sortWeaponsByAttackAscending();
    void sortWeaponsByAttackDescending();
    void sortArmorsByDefenseAscending();
    void sortArmorsByDefenseDescending();

    size_t getItemCount() const;
    std::vector<Item*> getItems() const;
    void displayItems() const;
    std::vector<Item*> searchByCriteria(const std::string& name, const std::string& type,
        int minAttack, int maxAttack,
        int minDefense, int maxDefense,
        const std::string& element) const;

    std::vector<std::unique_ptr<Item>> getAvailableItems();
    bool addItemByIndex(int index, const std::vector<std::unique_ptr<Item>>& availableItems);
};
