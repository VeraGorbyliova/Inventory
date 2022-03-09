#pragma once
const enum RARENESS {
    COMMON = 1,
    RARE = 2,
    EPIC = 3,
    DEFAULT_RARENESS = -1
};
const enum ARMARY_TYPE {
    ARMOR = 4,
    MELEE = 5,
    RANGE = 6,
    DEFAULT_ARMARY_TYPE = -2
};
const enum BUFF_TYPE {
    DAMAGE_BUFF = 7,
    SPEED_BUFF = 8,
    PROTECTION_BUFF = 9,
    DEFAULT_BUFF_TYPE = -3
};
const enum BUFF_TEMPLATE_INDEX {
    INDEX_1 = 1,
    INDEX_2 = 2,
    INDEX_3 = 3,
    INDEX_4 = 4,
    INDEX_5 = 5,
    INDEX_6 = 6,
    INDEX_7 = 7,
    INDEX_8 = 8,
    INDEX_9 = 9,
    INDEX_10 = 10,
    INDEX_11 = 11,
    INDEX_12 = 12,
    INDEX_13 = 13,
    DEFAULT_BUFF_TEMPLATE_INDEX = -4
};

struct BT_INDEX {
    BUFF_TEMPLATE_INDEX  value;
    explicit  BT_INDEX(BUFF_TEMPLATE_INDEX new_value) {
        value = new_value;
    }
    BT_INDEX() { value = BUFF_TEMPLATE_INDEX::DEFAULT_BUFF_TEMPLATE_INDEX; }
};
struct A_TYPE {
    ARMARY_TYPE value;
    explicit A_TYPE(ARMARY_TYPE new_value) {
        value = new_value;
    }
    A_TYPE() { value = ARMARY_TYPE::DEFAULT_ARMARY_TYPE; }
};
struct B_TYPE {
    BUFF_TYPE value;
    explicit B_TYPE(BUFF_TYPE new_value) {
        value = new_value;
    }
    B_TYPE() { value = BUFF_TYPE::DEFAULT_BUFF_TYPE; }
};
struct RARITY {
    RARENESS value;
    explicit RARITY(RARENESS new_value) {
        value = new_value;
    }
    RARITY() { value = RARENESS::DEFAULT_RARENESS; }
};
struct IDENT {
    std::string value;
    explicit IDENT(std::string new_value) {
        value = new_value;
    }
    IDENT() { value = "\0"; }
};
struct LEVEL {
    int value;
    explicit LEVEL(int new_value) {
        value = new_value;
    }
    LEVEL() {
        value = 0;
    }
};
struct DAMAGE {
    double value;
    explicit DAMAGE(double new_value) {
        value = new_value;
    }
    DAMAGE() {
        value = 0;
    }
};
struct SPEED {
    double value;
    explicit SPEED(double new_value) {
        value = new_value;
    }
    SPEED() {
        value = 0;
    }
};
struct PROTECTION {
    double value;
    explicit PROTECTION(double new_value) {
        value = new_value;
    }
    PROTECTION() {
        value = 0;
    }
};

class ITEM {
protected:
    ITEM() {}
    ~ITEM() {}
};
class BASIC_CHARACTERISTICS {
protected:
    IDENT Ident;
    A_TYPE AR_Type;
    B_TYPE BF_Type;
public:
    BASIC_CHARACTERISTICS(IDENT ident, A_TYPE type) :Ident(ident.value), AR_Type(type) {}
    BASIC_CHARACTERISTICS(IDENT ident, B_TYPE type) :Ident(ident.value), BF_Type(type) {}
    BASIC_CHARACTERISTICS() {}

};
class ARMAMENT : protected BASIC_CHARACTERISTICS, ITEM{
protected:
    RARITY Rarity;
    DAMAGE Damage;
    SPEED Speed;
    PROTECTION Protection;
    LEVEL Level;
public:
    ARMAMENT(const IDENT& ident, const A_TYPE& type, const LEVEL& level, const  RARITY& rariry, const DAMAGE& damage, const SPEED& speed) : BASIC_CHARACTERISTICS(ident, type), Level(level.value),
        Rarity(rariry), Damage(damage.value), Speed(speed.value) {
    }
    ARMAMENT(const IDENT& ident, const A_TYPE& type, const LEVEL& level, const RARITY& rariry, const PROTECTION& protection) : BASIC_CHARACTERISTICS(ident, type), Level(level.value),
        Rarity(rariry), Protection(protection.value) {
    }
    ARMAMENT() {}
    ~ARMAMENT() {}
    const LEVEL& getLevel() const { return Level; }
    const RARITY& getRarity() const { return Rarity; }
    const DAMAGE& getDamage() const { return Damage; }
    const SPEED& getSpeed() const { return Speed; }
    const PROTECTION& getProtection() const { return Protection; }
    const IDENT& getIdent() const { return Ident; }
    const A_TYPE& getType() const { return AR_Type; }

    void setDamage(const DAMAGE& newDamage) { Damage = newDamage; }
    void setSpeed(const SPEED& newSpeed) { Speed = newSpeed; }
    void setProtection(const PROTECTION& newProtection) { Protection = newProtection; }
};

class BUFFS_FILTER {
protected:
    BT_INDEX fT;
    std::string Symbole;
    A_TYPE AR_TypeFirst;
    A_TYPE AR_TypeSecond;
    LEVEL Level;
    RARITY RarityFirst;
    RARITY RaritySecond;
    std::vector<std::string> FilterInfo;
public:
    BUFFS_FILTER(const RARITY& rarity) : RarityFirst(rarity) {
        FilterInfo.push_back(fillReraness(RarityFirst));
        fT = BT_INDEX(BUFF_TEMPLATE_INDEX::INDEX_1) ;
    }
    BUFFS_FILTER(const RARITY& rarity, const  A_TYPE& type1) : RarityFirst(rarity), AR_TypeFirst(type1) {
        FilterInfo.push_back(fillType(AR_TypeFirst));
        FilterInfo.push_back(fillReraness(RarityFirst));
        fT = BT_INDEX(BUFF_TEMPLATE_INDEX::INDEX_8);
    }
    BUFFS_FILTER(const A_TYPE& type1) : AR_TypeFirst(type1) {
        FilterInfo.push_back(fillType(AR_TypeFirst)); 
        fT = BT_INDEX(BUFF_TEMPLATE_INDEX::INDEX_3);
    }
    BUFFS_FILTER(const LEVEL& level, const  std::string& symbole) : Level(level), Symbole(symbole) {
        FilterInfo.push_back("level " + Symbole + " " + std::to_string(Level.value));
        fT = BT_INDEX(BUFF_TEMPLATE_INDEX::INDEX_2);
    }
    BUFFS_FILTER(const LEVEL& level, const  std::string& symbole, const  RARITY& rarity) : Level(level), Symbole(symbole), RarityFirst(rarity) {
        FilterInfo.push_back(fillReraness(RarityFirst));
        FilterInfo.push_back("level " + Symbole + " " + std::to_string(Level.value));
        fT = BT_INDEX(BUFF_TEMPLATE_INDEX::INDEX_4);
    }
    BUFFS_FILTER(const LEVEL& level, const  std::string& symbole, const  RARITY& rarity1, const  RARITY& rarity2) : Level(level), Symbole(symbole),
        RarityFirst(rarity1), RaritySecond(rarity2){
        FilterInfo.push_back(fillReraness(RarityFirst));
        FilterInfo.push_back(fillReraness(RaritySecond));
        FilterInfo.push_back("level " + Symbole + " " + std::to_string(Level.value));
        fT = BT_INDEX(BUFF_TEMPLATE_INDEX::INDEX_10);
    }
    BUFFS_FILTER(const LEVEL& level, const std::string& symbole, const A_TYPE& type) : Level(level), Symbole(symbole), AR_TypeFirst(type)  {
        FilterInfo.push_back(fillType(AR_TypeFirst));
        FilterInfo.push_back("level " + Symbole + " " + std::to_string(Level.value)); 
        fT = BT_INDEX(BUFF_TEMPLATE_INDEX::INDEX_5);
    }
    BUFFS_FILTER(const LEVEL& level, const  std::string& symbole, const  A_TYPE& type1, const  A_TYPE& type2) : Level(level), Symbole(symbole),
        AR_TypeFirst(type1), AR_TypeSecond(type2) {
        FilterInfo.push_back(fillType(AR_TypeFirst));
        FilterInfo.push_back(fillType(AR_TypeSecond));
        FilterInfo.push_back("level " + Symbole + " " + std::to_string(Level.value));
        fT = BT_INDEX(BUFF_TEMPLATE_INDEX::INDEX_9);
    }
    BUFFS_FILTER(const LEVEL& level, const  std::string& symbole, const A_TYPE& type1,
        const  A_TYPE& type2, const  RARITY& rarity) : Level(level), Symbole(symbole), RarityFirst(rarity),
        AR_TypeFirst(type1), AR_TypeSecond(type2) {
        FilterInfo.push_back(fillReraness(RarityFirst));
        FilterInfo.push_back(fillType(AR_TypeFirst));
        FilterInfo.push_back(fillType(AR_TypeSecond));
        FilterInfo.push_back("level " + Symbole + " " + std::to_string(Level.value));
        fT = BT_INDEX(BUFF_TEMPLATE_INDEX::INDEX_11);
    }
    BUFFS_FILTER(const LEVEL& level, const std::string& symbole, const  A_TYPE& type1, const  A_TYPE& type2,
        const RARITY& rarity1, const RARITY& rarity2) : Level(level), Symbole(symbole),
        RarityFirst(rarity1), RaritySecond(rarity2),
        AR_TypeFirst(type1), AR_TypeSecond(type2){
        FilterInfo.push_back(fillReraness(RarityFirst));
        FilterInfo.push_back(fillReraness(RaritySecond));
        FilterInfo.push_back(fillType(AR_TypeFirst));
        FilterInfo.push_back(fillType(AR_TypeSecond));
        FilterInfo.push_back("level " + Symbole + " " + std::to_string(Level.value));
        fT = BT_INDEX(BUFF_TEMPLATE_INDEX::INDEX_13);
    }
    BUFFS_FILTER(const A_TYPE& type1, const  A_TYPE& type2) : AR_TypeFirst(type1), AR_TypeSecond(type2){
        FilterInfo.push_back(fillType(AR_TypeFirst));
        FilterInfo.push_back(fillType(AR_TypeSecond));
        fT = BT_INDEX(BUFF_TEMPLATE_INDEX::INDEX_6);
    }
    BUFFS_FILTER(const RARITY& rarity1, const  RARITY& rarity2) : RarityFirst(rarity1), RaritySecond(rarity2) {
        FilterInfo.push_back(fillReraness(RarityFirst));
        FilterInfo.push_back(fillReraness(RaritySecond));
        fT = BT_INDEX(BUFF_TEMPLATE_INDEX::INDEX_7);
    }
    BUFFS_FILTER(const LEVEL& level, const std::string& symbole, const  RARITY& rarity1, const RARITY& rarity2, const A_TYPE& type) : Level(level), 
        Symbole(symbole), AR_TypeFirst(type),
        RarityFirst(rarity1), RaritySecond(rarity2) {
        FilterInfo.push_back(fillReraness(RarityFirst));
        FilterInfo.push_back(fillReraness(RaritySecond));
        FilterInfo.push_back(fillType(AR_TypeFirst));
        FilterInfo.push_back("level " + Symbole + " " + std::to_string(Level.value));
        fT = BT_INDEX(BUFF_TEMPLATE_INDEX::INDEX_12);
    }
    BUFFS_FILTER() {}
    ~BUFFS_FILTER() {}
     
private:
    std::string fillReraness(const RARITY& r) {
        if (r.value == RARENESS::COMMON) { return "rarity: Common"; }
        else if (r.value == RARENESS::RARE) { return "rarity: Rare"; }
        else { return "rarity: Epic"; }
    }
    std::string fillType(const A_TYPE& t) {
        if (t.value == ARMARY_TYPE::ARMOR) { return "type: Armour"; }
        else if (t.value == ARMARY_TYPE::MELEE) { return "type: Melee"; }
        else { return "type: Range"; }
    }
};
class BUFFS : public BASIC_CHARACTERISTICS, public BUFFS_FILTER, public ITEM {
    double Value;
public:
    BUFFS(const IDENT& ident, const B_TYPE& type, const BUFFS_FILTER& filters, const double& value) : BASIC_CHARACTERISTICS(ident,type), BUFFS_FILTER(filters), Value(value) {
    }
    BUFFS() {}
    const IDENT& getIdent() const { return Ident; }
    const  BT_INDEX& getBuffTemplate() const {return fT; }
    const B_TYPE& getBuffType() const { return BF_Type; }
    const  double& getValue() const { return Value; }
    const LEVEL& getLevel() const { return Level; }
    const std::string& getMathSymbole() const { return Symbole; };
    const A_TYPE& getFirstType() const { return   AR_TypeFirst; };
    const A_TYPE& getSecondType() const { return   AR_TypeSecond; };
    const RARITY& getRarityFirst() const { return  RarityFirst; };
    const RARITY& getRaritySecond() const { return RaritySecond; };
    const std::vector<std::string>& getFilterInfo() const { return FilterInfo; }
    ~BUFFS() {}
};
class INVENTORY {
   std::vector<std::shared_ptr<ARMAMENT>> LOOT;
   std::vector<std::shared_ptr<BUFFS>> MODIFIERS;
public:
    INVENTORY() {}
    void ADD_LOOT(ARMAMENT element) { LOOT.push_back(std::make_shared<ARMAMENT>(element)); }
    void ADD_MODIFIERS(BUFFS element) { MODIFIERS.push_back(std::make_shared<BUFFS>(element)); }
    const std::vector<std::shared_ptr<ARMAMENT>>& GET_LOOT() const { return LOOT; }
    const  std::vector<std::shared_ptr<BUFFS>>& GET_MODIFIERS() const { return MODIFIERS; }
    ~INVENTORY() {}
}; 

