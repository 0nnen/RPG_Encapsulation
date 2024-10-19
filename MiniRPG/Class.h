#pragma once
#include <string>
#include <vector>
#include "Skill.h"

class Class {
public:
    Class(const std::string& name) : name(name) {}

    const std::string& getName() const { return name; }
    void addSkill(const Skill& skill) { skills.push_back(skill); }
    const std::vector<Skill>& getSkills() const { return skills; }

private:
    std::string name;
    std::vector<Skill> skills;
};