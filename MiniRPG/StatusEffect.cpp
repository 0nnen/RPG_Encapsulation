#include "StatusEffect.h"

StatusEffect::StatusEffect(StatusEffectType effectType, int duration)
    : effectType(effectType), duration(duration) {}

StatusEffectType StatusEffect::getEffectType() const {
    return effectType;
}

int StatusEffect::getDuration() const {
    return duration;
}

void StatusEffect::applyEffect() {
    // Placeholder pour l'application d'effets (logique future)
    switch (effectType) {
    case StatusEffectType::Poisoned:
        std::cout << "Personnage empoisonne ! Subit des degats continus.\n";
        break;
    case StatusEffectType::Enflamme:
        std::cout << "Personnage enflamme ! Subit des degats de feu.\n";
        break;
    case StatusEffectType::Froid:
        std::cout << "Personnage gele ! Vitesse de mouvement reduite.\n";
        break;
    case StatusEffectType::Divin:
        std::cout << "Personnage blesse par une force divine !\n";
        break;
    case StatusEffectType::Tenebre:
        std::cout << "Personnage absorbe par les tenebres !\n";
        break;
    default:
        break;
    }
}

std::string StatusEffect::getEffectName() const {
    switch (effectType) {
    case StatusEffectType::Poisoned: return "Empoisonne";
    case StatusEffectType::Enflamme: return "Enflamme";
    case StatusEffectType::Froid: return "Gele";
    case StatusEffectType::Divin: return "Divin";
    case StatusEffectType::Tenebre: return "Tenebreux";
    default: return "Aucun";
    }
}
