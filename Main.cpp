#include "Header.h"
int main()
{
    std::cout << "Hi!\n";
    std::cout << "//////////----------MENUE----------//////////" << std::endl;
    std::cout << "Do you want to add new ARMAMENT?\tpress - 1\n";
    std::cout << "Do you want to add new BUFF?\tpress - 2\n";
    std::cout << "Do you want to CHECK DEFAULT TEST?\tpress - 3\n";
    std::cout << "Do you want to PRINT INVENTORY?\tpress - 4\n";
    std::cout << "Do you want to FINISH THE PROGRAMM?\tpress - 5\n";
    int Choice = 0;
    INVENTORY Inventory;
    while (Choice != 5) {
        std::cin >> Choice;
        if (Choice == 1) {
            Add_new_Armament(Inventory);
        }
        else if (Choice == 2) {
            Add_new_Buff(Inventory);
        }
        else if (Choice == 3) {
            test();
        }
        else if (Choice == 4) {
            printInventory(Inventory);
        }
        else if (Choice == 5) {
            std::cout << "\nBye!";
            break;
        }
        else { std::cout << "Try again!"; }
        std::cout << "........." << std::endl;
    }
}
void test() {
    INVENTORY myInventory;

    ARMAMENT axe_01{ IDENT("axe_01"), A_TYPE(ARMARY_TYPE::MELEE), LEVEL(3), RARITY(RARENESS::COMMON), DAMAGE(12.0), SPEED(0.9) };
    ARMAMENT revolver_01{ IDENT("revolver_01"), A_TYPE(ARMARY_TYPE::RANGE), LEVEL(5), RARITY(RARENESS::COMMON), DAMAGE(42.0), SPEED(2.0) };
    ARMAMENT revolver_02{ IDENT("revolver_02"), A_TYPE(ARMARY_TYPE::RANGE), LEVEL(3), RARITY(RARENESS::RARE), DAMAGE(50.0), SPEED(2.1) };
    ARMAMENT machinegun_01{ IDENT("machinegun_01"), A_TYPE(ARMARY_TYPE::RANGE), LEVEL(5), RARITY(RARENESS::EPIC), DAMAGE(83.0), SPEED(10.0) };
    ARMAMENT jacket_01{ IDENT("machinegun_01"), A_TYPE(ARMARY_TYPE::ARMOR), LEVEL(2), RARITY(RARENESS::COMMON), PROTECTION(2) };
    ARMAMENT bullproof_vest_01{ IDENT("machinegun_01"), A_TYPE(ARMARY_TYPE::ARMOR), LEVEL(5), RARITY(RARENESS::RARE), PROTECTION(30) };

    BUFFS eagle_eye{ IDENT("eagle_eye"), B_TYPE(BUFF_TYPE::DAMAGE_BUFF), BUFFS_FILTER(LEVEL(4), ">=", A_TYPE(ARMARY_TYPE::RANGE)), 10 };
    BUFFS donatium_steel{ IDENT("donatium_steel"), B_TYPE(BUFF_TYPE::PROTECTION_BUFF), BUFFS_FILTER(RARITY(RARENESS::RARE)), 15 };
    BUFFS rage_drink{ IDENT("rage_drink"), B_TYPE(BUFF_TYPE::SPEED_BUFF), BUFFS_FILTER(A_TYPE(ARMARY_TYPE::RANGE), A_TYPE(ARMARY_TYPE::MELEE)), 0.4 };

    myInventory.ADD_LOOT(axe_01);
    myInventory.ADD_LOOT(revolver_01);
    myInventory.ADD_LOOT(revolver_02);
    myInventory.ADD_LOOT(machinegun_01);
    myInventory.ADD_LOOT(jacket_01);
    myInventory.ADD_LOOT(bullproof_vest_01);

    myInventory.ADD_MODIFIERS(eagle_eye);
    myInventory.ADD_MODIFIERS(donatium_steel);
    myInventory.ADD_MODIFIERS(rage_drink);

    printInventory(myInventory);
}

void ModifyArmament(const INVENTORY& myInventory) {
    std::vector<std::shared_ptr<BUFFS>> MOD = myInventory.GET_MODIFIERS();
    std::vector<std::shared_ptr<ARMAMENT>> ARM = myInventory.GET_LOOT();
    std::vector<std::shared_ptr<ARMAMENT>> MOD_ARM = ARM;
    for (int i = 0; i < MOD.size(); i++) {
        for (int j = 0; j < ARM.size(); j++) {
            switch ((*MOD[i]).getBuffTemplate().value)
            {
            case BUFF_TEMPLATE_INDEX::INDEX_1:
                filter_1_tamplate(MOD_ARM, MOD, ARM, i, j);
                break;
            case BUFF_TEMPLATE_INDEX::INDEX_2:
                filter_2_tamplate(MOD_ARM, MOD, ARM, i, j);
                break;
            case BUFF_TEMPLATE_INDEX::INDEX_3:
                filter_3_tamplate(MOD_ARM, MOD, ARM, i, j);
                break;
            case BUFF_TEMPLATE_INDEX::INDEX_4:
                filter_4_tamplate(MOD_ARM, MOD, ARM, i, j);
                break;
            case BUFF_TEMPLATE_INDEX::INDEX_5:
                filter_5_tamplate(MOD_ARM, MOD, ARM, i, j);
                break;
            case BUFF_TEMPLATE_INDEX::INDEX_6:
                filter_6_tamplate(MOD_ARM, MOD, ARM, i, j);
                break;
            case BUFF_TEMPLATE_INDEX::INDEX_7:
                filter_7_tamplate(MOD_ARM, MOD, ARM, i, j);
                break;
            case BUFF_TEMPLATE_INDEX::INDEX_8:
                filter_8_tamplate(MOD_ARM, MOD, ARM, i, j);
                break;
            case BUFF_TEMPLATE_INDEX::INDEX_9:
                filter_9_tamplate(MOD_ARM, MOD, ARM, i, j);
                break;
            case BUFF_TEMPLATE_INDEX::INDEX_10:
                filter_10_tamplate(MOD_ARM, MOD, ARM, i, j);
                break;
            case BUFF_TEMPLATE_INDEX::INDEX_11:
                filter_11_tamplate(MOD_ARM, MOD, ARM, i, j);
                break;
            case BUFF_TEMPLATE_INDEX::INDEX_12:
                filter_12_tamplate(MOD_ARM, MOD, ARM, i, j);
                break;
            case  BUFF_TEMPLATE_INDEX::INDEX_13:
                filter_13_tamplate(MOD_ARM, MOD, ARM, i, j);
                break;
            default:
                std::cout << "Unknown\n";
                break;
            }
        }
    }
    printModifArmament(MOD_ARM);
}
void add_modified_weapon(std::vector<std::shared_ptr<ARMAMENT>>& MOD_ARM, const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>>& ARM, const int& i, const int& j) {
    if ((*MOD[i]).getBuffType().value == BUFF_TYPE::DAMAGE_BUFF && (*MOD_ARM[j]).getType().value != ARMARY_TYPE::ARMOR) {
        (*MOD_ARM[j]).setDamage(DAMAGE((*ARM[j]).getDamage().value + (*MOD[i]).getValue()));
    }
    if ((*MOD[i]).getBuffType().value == BUFF_TYPE::SPEED_BUFF && (*MOD_ARM[j]).getType().value != ARMARY_TYPE::ARMOR) {
        (*MOD_ARM[j]).setSpeed(SPEED((*ARM[j]).getSpeed().value + (*MOD[i]).getValue()));
    }
    if ((*MOD[i]).getBuffType().value == BUFF_TYPE::PROTECTION_BUFF && (*MOD_ARM[j]).getType().value == ARMARY_TYPE::ARMOR) {
        (*MOD_ARM[j]).setProtection(PROTECTION((*ARM[j]).getProtection().value + (*MOD[i]).getValue()));
    }
}
bool checkSymbole(const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>>& ARM, const int& i, const int& j) {
    if ((*MOD[i]).getMathSymbole() == ">") {
        if ((*ARM[j]).getLevel().value > (*MOD[i]).getLevel().value) return true;
        else false;
    }
    else if ((*MOD[i]).getMathSymbole() == ">=") {
        if ((*ARM[j]).getLevel().value >= (*MOD[i]).getLevel().value) return true;
        else false;
    }
    else if ((*MOD[i]).getMathSymbole() == "<") {
        if ((*ARM[j]).getLevel().value < (*MOD[i]).getLevel().value) return true;
        else false;
    }
    else  if ((*MOD[i]).getMathSymbole() == "<=") {
        if ((*ARM[j]).getLevel().value <= (*MOD[i]).getLevel().value) return true;
        else false;
    }
    else if ((*MOD[i]).getMathSymbole() == "==") {
        if ((*ARM[j]).getLevel().value == (*MOD[i]).getLevel().value) return true;
        else false;
    }
    else if ((*MOD[i]).getMathSymbole() == "!=") {
        if ((*ARM[j]).getLevel().value != (*MOD[i]).getLevel().value) return true;
        else false;
    }
    else {
        std::cout << "Not right symbol" << std::endl;
        return false;
    }
}
RARENESS checkFirstRareness(const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>>& ARM, const int& i, const int& j) {
    if ((*MOD[i]).getRarityFirst().value == RARENESS::COMMON) {
        return RARENESS::COMMON;
    }
    else if ((*MOD[i]).getRarityFirst().value == RARENESS::EPIC) {
        return RARENESS::EPIC;
    }
    else if ((*MOD[i]).getRarityFirst().value == RARENESS::RARE) {
        return RARENESS::RARE;
    }
    else {
        return RARENESS::DEFAULT_RARENESS;
    }
}
RARENESS checkSecondRareness(const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>>& ARM, const int& i, const int& j) {
    if ((*MOD[i]).getRaritySecond().value == RARENESS::COMMON) {
        return RARENESS::COMMON;
    }
    else if ((*MOD[i]).getRaritySecond().value == RARENESS::EPIC) {
        return RARENESS::EPIC;
    }
    else if ((*MOD[i]).getRaritySecond().value == RARENESS::RARE) {
        return RARENESS::RARE;
    }
    else {
        return RARENESS::DEFAULT_RARENESS;
    }
}
ARMARY_TYPE checkFirstType(const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>>& ARM, const int& i, const int& j) {
    if ((*MOD[i]).getFirstType().value == ARMARY_TYPE::MELEE) {
        return ARMARY_TYPE::MELEE;
    }
    else if ((*MOD[i]).getFirstType().value == ARMARY_TYPE::RANGE) {
        return ARMARY_TYPE::RANGE;
    }
    else if ((*MOD[i]).getFirstType().value == ARMARY_TYPE::ARMOR) {
        return ARMARY_TYPE::ARMOR;
    }
    else {
        return ARMARY_TYPE::DEFAULT_ARMARY_TYPE;
    }
}
ARMARY_TYPE checkSecondType(const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>>& ARM, const int& i, const int& j) {
    if ((*MOD[i]).getSecondType().value == ARMARY_TYPE::MELEE) {
        return ARMARY_TYPE::MELEE;
    }
    else if ((*MOD[i]).getSecondType().value == ARMARY_TYPE::RANGE) {
        return ARMARY_TYPE::RANGE;
    }
    else if ((*MOD[i]).getSecondType().value == ARMARY_TYPE::ARMOR) {
        return  ARMARY_TYPE::ARMOR;
    }
    else {
        return ARMARY_TYPE::DEFAULT_ARMARY_TYPE;
    }
}

void Add_new_Armament(INVENTORY& Inventory) {
    std::string ident;
    int choose = 0;
    int level = 0;
    double protection = 0;
    double damage = 0;
    double speed = 0;
    std::cout << "\nWrite ident ";
    std::cin >> ident;
    std::cout << "\nWrite level ";
    std::cin >> level;
    ARMAMENT newWeapon;
    ARMARY_TYPE ch = generateWeaponType();
    if (ch == ARMARY_TYPE::ARMOR) {
        std::cout << "\nWrite protection value ";
        std::cin >> protection;
        newWeapon = { IDENT(ident), A_TYPE(ch), LEVEL(level), RARITY(generateRarity()), PROTECTION(protection) };
    }
    else {
        std::cout << "\nWrite damage value";
        std::cin >> damage;

        std::cout << "\nWrite speed value ";
        std::cin >> speed;
        newWeapon = { IDENT(ident), A_TYPE(ch), LEVEL(level), RARITY(generateRarity()), DAMAGE(damage), SPEED(speed) };
    }
    Inventory.ADD_LOOT(newWeapon);
}
void Add_new_Buff(INVENTORY& Inventory) {
    BUFFS newBuff;
    std::string ident;
    int choose = 0;
    int level = 0;
    double value = 0;
    std::string symbole = "\0";
    BUFF_TYPE b_type;
    RARENESS rarity;
    BUFFS_FILTER filter;

    std::cout << "\nWrite ident ";
    std::cin >> ident;

    b_type = generateBuffType();

    std::cout << "\nChoose template of the filter" << std::endl;
    printTemplates();
    while (choose < 1 || choose>13) {
        std::cin >> choose;
        if (choose == 1) {
            filter = BUFFS_FILTER{ RARITY(generateRarity()) };
            break;
        }
        else if (choose == 2) {
            generateLevelFilter(level, symbole);
            filter = BUFFS_FILTER{ LEVEL(level),symbole };
            break;
        }
        else if (choose == 3) {
            filter = BUFFS_FILTER{ A_TYPE(generateWeaponType()) };
            break;
        }
        else if (choose == 4) {
            filter = BUFFS_FILTER{ LEVEL(level),symbole,  RARITY(generateRarity()) };
            break;
        }
        else if (choose == 5) {
            filter = BUFFS_FILTER{ LEVEL(level),symbole,  A_TYPE(generateWeaponType()) };
            break;
        }
        else if (choose == 6) {
            filter = BUFFS_FILTER{ A_TYPE(generateWeaponType()) , A_TYPE(generateWeaponType())
            };
            break;
        }
        else if (choose == 7) {
            filter = BUFFS_FILTER{ RARITY(generateRarity()) , RARITY(generateRarity()) };
            break;
        }
        else if (choose == 8) {
            filter = BUFFS_FILTER{ RARITY(generateRarity()) ,A_TYPE(generateWeaponType()) };
            break;
        }
        else if (choose == 9) {
            filter = BUFFS_FILTER{ LEVEL(level),symbole,A_TYPE(generateWeaponType()),A_TYPE(generateWeaponType()) };
            break;
        }
        else if (choose == 10) {
            filter = BUFFS_FILTER{ LEVEL(level),symbole,RARITY(generateRarity()) ,RARITY(generateRarity()) };
            break;
        }
        else if (choose == 11) {
            filter = BUFFS_FILTER{ LEVEL(level),symbole,A_TYPE(generateWeaponType()),A_TYPE(generateWeaponType()),
                RARITY(generateRarity())
            };
            break;
        }
        else if (choose == 12) {
            filter = BUFFS_FILTER{ LEVEL(level),symbole,RARITY(generateRarity()) ,RARITY(generateRarity()),
                A_TYPE(generateWeaponType()) }
            ;
            break;
        }
        else if (choose == 13) {
            filter = BUFFS_FILTER{ LEVEL(level),symbole,A_TYPE(generateWeaponType()),A_TYPE(generateWeaponType()),
                RARITY(generateRarity()) ,RARITY(generateRarity())
            };
            break;
        }
        else {
            std::cout << "Try again!\n";
        }
    }
    std::cout << "\nWrite value ";
    std::cin >> value;
    newBuff = { IDENT(ident),B_TYPE(b_type), filter, value };
    Inventory.ADD_MODIFIERS(newBuff);
}

ARMARY_TYPE generateWeaponType() {
    int chooseType = 0;
    std::cout << "\nChoose the type: armour - 1, melee - 2, range - 3" << std::endl;
    while (chooseType < 1 || chooseType > 3) {
        std::cin >> chooseType;
        if (chooseType == 1) {
            return ARMARY_TYPE::ARMOR;
        }
        else if (chooseType == 2) {
            return ARMARY_TYPE::MELEE;
        }
        else if (chooseType == 3) {
            return ARMARY_TYPE::RANGE;
        }
        else {
            std::cout << "Try again!\n";
        }
    }
}
RARENESS generateRarity() {
    int chooseRarity = 0;
    std::cout << "\nChoose the rarity: rare - 1, common - 2, epic - 3" << std::endl;
    while (chooseRarity < 1 || chooseRarity > 3) {
        std::cin >> chooseRarity;
        if (chooseRarity == 1) {
            return RARENESS::RARE;
        }
        else if (chooseRarity == 2) {
            return RARENESS::COMMON;
        }
        else if (chooseRarity == 3) {
            return RARENESS::EPIC;
        }
        else {
            std::cout << "Try again!\n";
        }
    }

}
BUFF_TYPE generateBuffType() {
    int chooseBuffType = 0;
    std::cout << "\nChoose the type: damage buff - 1, protaction buff - 2, speed buff - 3" << std::endl;
    while (chooseBuffType < 1 || chooseBuffType > 3) {
        std::cin >> chooseBuffType;
        if (chooseBuffType == 1) {
            return BUFF_TYPE::DAMAGE_BUFF;
        }
        else if (chooseBuffType == 2) {
            return BUFF_TYPE::PROTECTION_BUFF;
        }
        else if (chooseBuffType == 3) {
            return BUFF_TYPE::SPEED_BUFF;
        }
        else {
            std::cout << "Try again!\n";
        }
    }
}
void generateLevelFilter(int& level, std::string& symbole) {
    std::cout << "\nWrite level: ";
    std::cin >> level;
    std::cout << "\nWrite symbole: ";
    std::cin >> symbole;
}