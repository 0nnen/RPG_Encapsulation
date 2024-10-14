#pragma once
#include <string>
#include <iostream>

enum class StatusEffectType {
    None,
    Poisoned,
    Enflamme,
    Froid,
    Divin,
    Tenebre
};

class StatusEffect {
private:
    StatusEffectType effectType;
    int duration; // Durée en tours

public:
    StatusEffect(StatusEffectType effectType = StatusEffectType::None, int duration = 0);

    StatusEffectType getEffectType() const;
    std::string getEffectName() const;
    int getDuration() const;
	void applyEffect();
};
