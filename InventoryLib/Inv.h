#pragma once
#include <vector>
#include <iostream>
#include <memory>
#include <string>
#include "Item.h"

class InventoryLib {
private:
    std::vector<std::unique_ptr<Item>> items;

public:
    void addItem(std::unique_ptr<Item> item);
    Item* getItem(int index);
    void displayInventoryByType(const std::string& type) const;
    void displayInventory() const;
    void addItemsFromList(const std::vector<std::unique_ptr<Item>>& allItems);
    size_t getSize() const { return items.size(); }

    bool removeItem(const std::string& itemName);
    std::vector<Item*> searchByStat(int minStat, int maxStat) const;
    void sortByType();
    void sortByElement();
    size_t getItemCount() const;
    std::vector<Item*> getItems() const;
    void displayItems() const;
    std::vector<Item*> searchByCriteria(const std::string& name, const std::string& type,
        int minAttack, int maxAttack,
        int minDefense, int maxDefense,
        const std::string& element) const;
    void resetSearch();
};
