#include "ParsingLib.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include "Weapon.h"
#include "Armor.h"

std::vector<std::unique_ptr<Item>> ParsingLib::parseInventoryFile(const std::string& filePath) {
    std::vector<std::unique_ptr<Item>> items;
    std::ifstream file(filePath);

    if (!file.is_open()) {
        throw std::runtime_error("Erreur: Impossible d'ouvrir le fichier " + filePath);
    }

    std::string line;
    int lineNumber = 0;
    while (std::getline(file, line)) {
        lineNumber++;
        try {
            if (line.empty() || line[0] == '#') continue;  // Ignorer les lignes vides ou les commentaires

            std::stringstream ss(line);
            std::string name, type, statStr, elementStr, classStr;

            if (!std::getline(ss, name, ';') || !std::getline(ss, type, ';') ||
                !std::getline(ss, statStr, ';') || !std::getline(ss, elementStr, ';') ||
                !std::getline(ss, classStr, ';')) {
                throw std::runtime_error("Format invalide de la ligne " + std::to_string(lineNumber));
            }

            int stat;
            try {
                stat = std::stoi(statStr);
            }
            catch (const std::invalid_argument&) {
                throw std::runtime_error("Erreur de conversion en entier pour 'stat' a la ligne " + std::to_string(lineNumber));
            }
            catch (const std::out_of_range&) {
                throw std::runtime_error("Valeur hors limite pour 'stat' a la ligne " + std::to_string(lineNumber));
            }

            Element element = Element::None;
            if (elementStr == "Fire") element = Element::Fire;
            else if (elementStr == "Ice") element = Element::Ice;
            else if (elementStr == "Divine") element = Element::Divine;
            else if (elementStr == "Poison") element = Element::Poison;
            else if (elementStr == "Dark") element = Element::Dark;
            else {
                throw std::runtime_error("Element inconnu a la ligne " + std::to_string(lineNumber));
            }

            if (type == "Weapon") {
                // Passe uniquement 4 arguments au constructeur de Weapon
                items.push_back(std::make_unique<Weapon>(name, stat, false, element));
            }
            else if (type == "Armor") {
                // Passe uniquement 3 arguments au constructeur de Armor
                items.push_back(std::make_unique<Armor>(name, stat, element));
            }
            else {
                throw std::runtime_error("Type inconnu a la ligne " + std::to_string(lineNumber));
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Erreur lors du traitement de la ligne " << lineNumber << ": " << e.what() << std::endl;
        }
    }

    file.close();
    return items;
}
