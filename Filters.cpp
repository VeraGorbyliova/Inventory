#include "Header.h"
void filter_1_tamplate(std::vector<std::shared_ptr<ARMAMENT>>& MOD_ARM, const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>>& ARM, const int& i, const int& j) {
    if ((*MOD[i]).getRarityFirst().value != RARENESS::DEFAULT_RARENESS) {
        if (checkFirstRareness(MOD, ARM, i, j) == (*ARM[j]).getRarity().value) {
            add_modified_weapon(MOD_ARM, MOD, ARM, i, j);
        }
    }
}
void filter_2_tamplate(std::vector<std::shared_ptr<ARMAMENT>>& MOD_ARM, const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>>& ARM, const int& i, const int& j) {
    if ((*MOD[i]).getLevel().value != 0) { // level filter
        if (true == checkSymbole(MOD, ARM, i, j)) {
            add_modified_weapon(MOD_ARM, MOD, ARM, i, j);
        }
    }
}
void filter_3_tamplate(std::vector<std::shared_ptr<ARMAMENT>>& MOD_ARM, const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>>& ARM, const int& i, const int& j) {
    if ((*MOD[i]).getFirstType().value != ARMARY_TYPE::DEFAULT_ARMARY_TYPE){
        if (checkFirstType(MOD, ARM, i, j) == (*ARM[j]).getType().value) {
            add_modified_weapon(MOD_ARM, MOD, ARM, i, j);
        }
    }
}
void filter_4_tamplate(std::vector<std::shared_ptr<ARMAMENT>>& MOD_ARM, const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>>& ARM, const int& i, const int& j) {
    if ((*MOD[i]).getLevel().value != 0 && (*MOD[i]).getRarityFirst().value != RARENESS::DEFAULT_RARENESS) { // level filter
        if (true == checkSymbole(MOD, ARM, i, j) && checkFirstRareness(MOD, ARM, i, j) == (*ARM[j]).getRarity().value) {
            add_modified_weapon(MOD_ARM, MOD, ARM, i, j);           
        }
    }
}
void filter_5_tamplate(std::vector<std::shared_ptr<ARMAMENT>>& MOD_ARM, const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>>& ARM, const int& i, const int& j) {
    if ((*MOD[i]).getLevel().value != 0 && (*MOD[i]).getFirstType().value != ARMARY_TYPE::DEFAULT_ARMARY_TYPE) { // level filter
        if (true == checkSymbole(MOD, ARM, i, j) && checkFirstType(MOD, ARM, i, j) == (*ARM[j]).getType().value) {
            add_modified_weapon(MOD_ARM, MOD, ARM, i, j);
        }
    }
}
void filter_6_tamplate(std::vector<std::shared_ptr<ARMAMENT>>& MOD_ARM, const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>>& ARM, const int& i, const int& j) {
    if ((*MOD[i]).getFirstType().value != ARMARY_TYPE::DEFAULT_ARMARY_TYPE || (*MOD[i]).getSecondType().value != ARMARY_TYPE::DEFAULT_ARMARY_TYPE) { //first type filer
        if (checkFirstType(MOD, ARM, i, j) == (*ARM[j]).getType().value || checkSecondType(MOD, ARM, i, j) == (*ARM[j]).getType().value) {
            add_modified_weapon(MOD_ARM, MOD, ARM, i, j);
        }
    }
}
void filter_7_tamplate(std::vector<std::shared_ptr<ARMAMENT>>& MOD_ARM, const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>>& ARM, const int& i, const int& j) {
    if ((*MOD[i]).getRarityFirst().value != RARENESS::DEFAULT_RARENESS || (*MOD[i]).getRaritySecond().value != RARENESS::DEFAULT_RARENESS) {//first rareness filter
        if (checkFirstRareness(MOD, ARM, i, j) == (*ARM[j]).getRarity().value || checkSecondRareness(MOD, ARM, i, j) == (*ARM[j]).getRarity().value) {
            add_modified_weapon(MOD_ARM, MOD, ARM, i, j);
        }
    }
}
void filter_8_tamplate(std::vector<std::shared_ptr<ARMAMENT>>& MOD_ARM, const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>>& ARM, const int& i, const int& j) {
    if ((*MOD[i]).getFirstType().value != ARMARY_TYPE::DEFAULT_ARMARY_TYPE && (*MOD[i]).getRarityFirst().value != RARENESS::DEFAULT_RARENESS) { //first type filer
        if (checkFirstType(MOD, ARM, i, j) == (*ARM[j]).getType().value && checkFirstRareness(MOD, ARM, i, j) == (*ARM[j]).getRarity().value) {
            add_modified_weapon(MOD_ARM, MOD, ARM, i, j);
        }
    }
}
void filter_9_tamplate(std::vector<std::shared_ptr<ARMAMENT>>& MOD_ARM, const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>>& ARM, const int& i, const int& j) {
    if ((*MOD[i]).getLevel().value != 0 && ((*MOD[i]).getFirstType().value != ARMARY_TYPE::DEFAULT_ARMARY_TYPE || (*MOD[i]).getSecondType().value != ARMARY_TYPE::DEFAULT_ARMARY_TYPE)) { // level filter
        if (true == checkSymbole(MOD, ARM, i, j) && (checkFirstType(MOD, ARM, i, j) == (*ARM[j]).getType().value || checkSecondType(MOD, ARM, i, j) == (*ARM[j]).getType().value)) {
            add_modified_weapon(MOD_ARM, MOD, ARM, i, j);
        }
    }
}
void filter_10_tamplate(std::vector<std::shared_ptr<ARMAMENT>>& MOD_ARM, const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>>& ARM, const int& i, const int& j) {
    if ((*MOD[i]).getLevel().value != 0 && ((*MOD[i]).getRarityFirst().value != RARENESS::DEFAULT_RARENESS || (*MOD[i]).getRaritySecond().value != RARENESS::DEFAULT_RARENESS)) { // level filter
        if (true == checkSymbole(MOD, ARM, i, j) && (checkFirstRareness(MOD, ARM, i, j) == (*ARM[j]).getRarity().value || checkSecondRareness(MOD, ARM, i, j) == (*ARM[j]).getRarity().value)) {
            add_modified_weapon(MOD_ARM, MOD, ARM, i, j);
        }
    }
}
void filter_11_tamplate(std::vector<std::shared_ptr<ARMAMENT>>& MOD_ARM, const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>>& ARM, const int& i, const int& j) {
    if ((*MOD[i]).getLevel().value != 0 && 
        ((*MOD[i]).getFirstType().value != ARMARY_TYPE::DEFAULT_ARMARY_TYPE || (*MOD[i]).getSecondType().value != ARMARY_TYPE::DEFAULT_ARMARY_TYPE) 
        && (*MOD[i]).getRarityFirst().value != RARENESS::DEFAULT_RARENESS) { // level filter
        if (true == checkSymbole(MOD, ARM, i, j)&&(checkFirstType(MOD, ARM, i, j) == (*ARM[j]).getType().value || 
            checkSecondType(MOD, ARM, i, j) == (*ARM[j]).getType().value)&& checkFirstRareness(MOD, ARM, i, j) == (*ARM[j]).getRarity().value) {
            add_modified_weapon(MOD_ARM, MOD, ARM, i, j);
        }
    }
}
void filter_12_tamplate(std::vector<std::shared_ptr<ARMAMENT>>& MOD_ARM, const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>>& ARM, const int& i, const int& j) {
    if ((*MOD[i]).getLevel().value != 0 && ((*MOD[i]).getRarityFirst().value != RARENESS::DEFAULT_RARENESS || (*MOD[i]).getRaritySecond().value != RARENESS::DEFAULT_RARENESS) 
        && (*MOD[i]).getFirstType().value != ARMARY_TYPE::DEFAULT_ARMARY_TYPE) { // level filter
        if (true == checkSymbole(MOD, ARM, i, j)&& (checkFirstRareness(MOD, ARM, i, j) == (*ARM[j]).getRarity().value 
            || checkSecondRareness(MOD, ARM, i, j) == (*ARM[j]).getRarity().value)&& checkFirstType(MOD, ARM, i, j) == (*ARM[j]).getType().value) {
            add_modified_weapon(MOD_ARM, MOD, ARM, i, j);
        }
    }
}
void filter_13_tamplate(std::vector<std::shared_ptr<ARMAMENT>>& MOD_ARM, const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>>& ARM, const int& i, const int& j) {
    if ((*MOD[i]).getLevel().value != 0 && ((*MOD[i]).getFirstType().value != ARMARY_TYPE::DEFAULT_ARMARY_TYPE 
        || (*MOD[i]).getSecondType().value != ARMARY_TYPE::DEFAULT_ARMARY_TYPE) && ((*MOD[i]).getRarityFirst().value != RARENESS::DEFAULT_RARENESS 
            || (*MOD[i]).getRaritySecond().value != RARENESS::DEFAULT_RARENESS)) { // level filter
        if (true == checkSymbole(MOD, ARM, i, j) && (checkFirstType(MOD, ARM, i, j) == (*ARM[j]).getType().value 
            || checkSecondType(MOD, ARM, i, j) == (*ARM[j]).getType().value) && (checkFirstRareness(MOD, ARM, i, j) == (*ARM[j]).getRarity().value 
                || checkSecondRareness(MOD, ARM, i, j) == (*ARM[j]).getRarity().value)) {
            add_modified_weapon(MOD_ARM, MOD, ARM, i, j);
        }
    }
}