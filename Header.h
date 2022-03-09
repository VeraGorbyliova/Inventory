#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <compare>
#include <tuple> 
#include <memory> 
#include "Items.h"

void printArmament(const INVENTORY& myInventory);
void printBuffs(const INVENTORY& myInventory);
void ModifyArmament(const INVENTORY& myInventory);
void printInventory(const INVENTORY& myInventory);
void printTemplates();
void printModifArmament(const std::vector<std::shared_ptr<ARMAMENT>>& MOD_ARM);
void test();
void Add_new_Armament(INVENTORY& myInventory);
void Add_new_Buff(INVENTORY& myInventory);
void add_modified_weapon(std::vector<std::shared_ptr<ARMAMENT>>& MOD_ARM, const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>>& ARM, const int& i, const int& j);
ARMARY_TYPE generateWeaponType();
RARENESS generateRarity();
BUFF_TYPE generateBuffType();
void generateLevelFilter(int& level, std::string& symbole);
bool checkSymbole(const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>>& ARM, const int& i, const int& j);
ARMARY_TYPE checkSecondType(const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>>& ARM, const int& i, const int& j);
ARMARY_TYPE checkFirstType(const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>>& ARM, const int& i, const int& j);
RARENESS checkFirstRareness(const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>>& ARM, const int& i, const int& j);
RARENESS checkSecondRareness(const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>>& ARM, const int& i, const int& j);

void filter_1_tamplate(std::vector<std::shared_ptr<ARMAMENT>>& MOD_ARM, const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>>& ARM, const int& i, const int& j);
void filter_2_tamplate(std::vector<std::shared_ptr<ARMAMENT>>& MOD_ARM, const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>>& ARM, const int& i, const int& j);
void filter_3_tamplate(std::vector<std::shared_ptr<ARMAMENT>>& MOD_ARM, const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>>& ARM, const int& i, const int& j);
void filter_4_tamplate(std::vector<std::shared_ptr<ARMAMENT>>& MOD_ARM, const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>>& ARM, const int& i, const int& j);
void filter_5_tamplate(std::vector<std::shared_ptr<ARMAMENT>>& MOD_ARM, const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>>& ARM, const int& i, const int& j);
void filter_6_tamplate(std::vector<std::shared_ptr<ARMAMENT>>& MOD_ARM, const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>> & ARM, const int& i, const int& j);
void filter_7_tamplate(std::vector<std::shared_ptr<ARMAMENT>>& MOD_ARM, const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>> & ARM, const int& i, const int& j);
void filter_8_tamplate(std::vector<std::shared_ptr<ARMAMENT>>& MOD_ARM, const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>>& ARM, const int& i, const int& j);
void filter_9_tamplate(std::vector<std::shared_ptr<ARMAMENT>>& MOD_ARM, const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>> & ARM, const int& i, const int& j);
void filter_10_tamplate(std::vector<std::shared_ptr<ARMAMENT>>& MOD_ARM, const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>>& ARM, const int& i, const int& j);
void filter_11_tamplate(std::vector<std::shared_ptr<ARMAMENT>>& MOD_ARM, const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>>& ARM, const int& i, const int& j);
void filter_12_tamplate(std::vector<std::shared_ptr<ARMAMENT>>& MOD_ARM, const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>>& ARM, const int& i, const int& j);
void filter_13_tamplate(std::vector<std::shared_ptr<ARMAMENT>>& MOD_ARM, const std::vector<std::shared_ptr<BUFFS>>& MOD, const std::vector<std::shared_ptr<ARMAMENT>>& ARM, const int& i, const int& j);

