#include "Header.h"

void printInventory(const INVENTORY& myInventory) {
    std::cout << "//////////----------INVENTORY----------//////////" << std::endl;
    std::cout << "--------------------Weapons--------------------" << std::endl;
    printArmament(myInventory);
    std::cout << std::endl;
    std::cout << "--------------------Buffs--------------------" << std::endl;
    printBuffs(myInventory);
    std::cout << std::endl;
    std::cout << "--------------------Weapons with Buffs--------------------" << std::endl;
    ModifyArmament(myInventory);
    std::cout << std::endl;
}
void printArmament(const INVENTORY& myInventory) {
    for (int i = 0; i < myInventory.GET_LOOT().size(); i++) {
        std::cout << "ident: ";
        std::cout << std::setw(15) << std::left;
        std::cout << (*myInventory.GET_LOOT()[i]).getIdent().value << "\t";

        std::cout << "type: ";
        if ((*myInventory.GET_LOOT()[i]).getType().value == ARMARY_TYPE::ARMOR) { std::cout << "Armour" << "\t"; }
        else if ((*myInventory.GET_LOOT()[i]).getType().value == ARMARY_TYPE::MELEE) { std::cout << "Melee" << "\t"; }
        else { std::cout << "Range" << "\t"; }

        std::cout << "rare: ";
        if ((*myInventory.GET_LOOT()[i]).getRarity().value == RARENESS::COMMON) { std::cout << "Common" << "\t"; }
        else if ((*myInventory.GET_LOOT()[i]).getRarity().value == RARENESS::RARE) { std::cout << "Rare" << "\t"; }
        else { std::cout << "Epic" << "\t"; }

        std::cout << "level: ";
        std::cout << (*myInventory.GET_LOOT()[i]).getLevel().value << "\t";


        if ((*myInventory.GET_LOOT()[i]).getType().value == ARMARY_TYPE::ARMOR) {
            std::cout << "protection: ";
            std::cout << (*myInventory.GET_LOOT()[i]).getProtection().value << "\t";
        }
        else {
            std::cout << "damage: ";
            std::cout << (*myInventory.GET_LOOT()[i]).getDamage().value << "\t";
            std::cout << "speed: ";
            std::cout << (*myInventory.GET_LOOT()[i]).getSpeed().value << "\t";
        }
        std::cout << std::endl;
    }
}
void printBuffs(const INVENTORY& myInventory) {
    for (int i = 0; i < myInventory.GET_MODIFIERS().size(); i++) {
        std::cout << "ident: ";
        std::cout << std::setw(10) << std::left;
        std::cout << (*myInventory.GET_MODIFIERS()[i]).getIdent().value << "\t";
        std::cout << "type: ";
        std::cout.width(20);
        if ((*myInventory.GET_MODIFIERS()[i]).getBuffType().value == BUFF_TYPE::DAMAGE_BUFF) { std::cout << "DamageBuff "; }
        else if ((*myInventory.GET_MODIFIERS()[i]).getBuffType().value == BUFF_TYPE::PROTECTION_BUFF) { std::cout << "ProtectionBuff "; }
        else { std::cout << "SpeedBuff "; }
        std::cout << "filters: [";
        for (int j = 0; j < (*myInventory.GET_MODIFIERS()[i]).getFilterInfo().size(); j++) {
            if (j == (*myInventory.GET_MODIFIERS()[i]).getFilterInfo().size() - 1) {
                std::cout << (*myInventory.GET_MODIFIERS()[i]).getFilterInfo()[j] << "]";
            }
            else std::cout << (*myInventory.GET_MODIFIERS()[i]).getFilterInfo()[j] << ", ";
        }
        std::cout.width(10);
        std::cout << std::setw(10) << std::left;
        std::cout << "\t";
        std::cout << "Value: ";
        std::cout << (*myInventory.GET_MODIFIERS()[i]).getValue() << "\t";
        std::cout << std::endl;
    }
}
void printTemplates() {
    std::cout << "\nTemplates" << std::endl;
    std::cout << "1)...rarity..." << std::endl;
    std::cout << "2)...level..." << std::endl;
    std::cout << "3)...type..." << std::endl;
    std::cout << "4)...level...rarity..." << std::endl;
    std::cout << "5)...level...type..." << std::endl;
    std::cout << "6)...type...type..." << std::endl;
    std::cout << "7)...rarity...rarity..." << std::endl;
    std::cout << "8)...rarity...type..." << std::endl;
    std::cout << "9)...level...type1...type2..." << std::endl;
    std::cout << "10)...level...rarity1...rarity2..." << std::endl;
    std::cout << "11)...level...type1...type2...rarity..." << std::endl;
    std::cout << "12)...level...rarity1...rarity2...type..." << std::endl;
    std::cout << "13)...level...type1...type2...rarity1...rarity2..." << std::endl;
}
void printModifArmament(const std::vector<std::shared_ptr<ARMAMENT>>& MOD_ARM) {
    for (int i = 0; i < MOD_ARM.size(); i++) {
        std::cout << "ident: ";
        std::cout << std::setw(15) << std::left;
        std::cout << (*MOD_ARM[i]).getIdent().value << "\t";

        std::cout << "type: ";
        if ((*MOD_ARM[i]).getType().value == ARMARY_TYPE::ARMOR) { std::cout << "Armour" << "\t"; }
        else if ((*MOD_ARM[i]).getType().value == ARMARY_TYPE::MELEE) { std::cout << "Melee" << "\t"; }
        else { std::cout << "Range" << "\t"; }

        std::cout << "rare: ";
        if ((*MOD_ARM[i]).getRarity().value == RARENESS::COMMON) { std::cout << "Common" << "\t"; }
        else if( (*MOD_ARM[i]).getRarity().value == RARENESS::RARE) { std::cout << "Rare" << "\t"; }
        else { std::cout << "Epic" << "\t"; }

        std::cout << "level: ";
        std::cout << (*MOD_ARM[i]).getLevel().value << "\t";

        if ((*MOD_ARM[i]).getType().value == ARMARY_TYPE::ARMOR) {
            std::cout << "protection: ";
            std::cout << (*MOD_ARM[i]).getProtection().value << "\t";
        }
        else {
            std::cout << "damage: ";
            std::cout << (*MOD_ARM[i]).getDamage().value << "\t";
            std::cout << "speed: ";
            std::cout << (*MOD_ARM[i]).getSpeed().value << "\t";
        }
        std::cout << std::endl;
    }
}