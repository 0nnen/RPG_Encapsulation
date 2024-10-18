#pragma once
#include <vector>
#include <memory>
#include <string>
#include "Item.h"

class InventoryLib {
public:
    // Ajouter un objet à l'inventaire
    void addItem(std::unique_ptr<Item> item);

    // Supprimer un objet de l'inventaire par nom
    bool removeItem(const std::string& itemName);

    // Rechercher des objets par statistiques (ex: meilleure attaque)
    std::vector<Item*> searchByStat(int minStat, int maxStat) const;

    // Trier les objets par type (ex: Weapon, Armor)
    void sortByType();

    // Obtenir tous les objets (par exemple, pour les ajouter à Inventory)
    std::vector<Item*> getItems() const;  

    // Afficher les objets
    void displayItems() const;

private:
    std::vector<std::unique_ptr<Item>> items;
};
