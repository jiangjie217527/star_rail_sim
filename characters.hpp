#ifndef characters_h
#define characters_h
#include "skill.hpp"
#include <map>
#include <string>
#include <vector>
 
class StatusEffect{  // the effect of BUFF
    // How to deal with the status effect?
    public:
        StatusEffect();
        ~StatusEffect();
    private:
        std::map<std::string, double> status_effect;

};

class Status{   // A execuate some buff to B, and how long
    public:
        Status();
        ~Status();
        void set_status(std::string status_name, double status_value);
        double get_status(std::string status_name);
    private:
        int from, to;
        int duration;

};

class ElementValue{ // ice, fire, ...
    public:
        ElementValue();
        ~ElementValue();
        double get_value(std::string element);
        double get_fire(); // get fire related value for example
    private:
        std::map<std::string, double> element_value;
};

class OriginCharactor{
    public:
        OriginCharactor();
        ~OriginCharactor();
        double get_hp();
        void initDistance(){
            distance = 10000;
        }
        friend void initTime(std::vector<OriginCharactor>& characters);
    private:
        std::string name;
        // Here may be use a map to store all the properties
        double id;
        double value;
        double distance;
        double time;
        double hp;              // Health Points
        double atk;             // Attack
        double def;             // Defense
        double spd;             // Speed
        double crit_rate;       // Critical Rate
        double crit_DMG;        // Critical Damage
        // double break_effect
        double heal_boost;      // Outgoing Healing Boost
        double energy_restore;  // Energy Restoration Rate
        double effect_hit_rate; // Effect Hit Rate
        double effect_resist;   // Effect Resistance
        ElementValue dmg_boost; // Damage Boost
        ElementValue dmg_res;   // Damage Resistance Boost
        std::vector<Skill> skills;   // Skills
};

class CombatCharactor{
    public:
        CombatCharactor();
        CombatCharactor(int id, int character_level, int basic_level, int BPSkill_level, int ultra_level, int talent_level);
        ~CombatCharactor();
    private:
        OriginCharactor origin;
        int entity_id; // entity id
        std::vector<Status> status; // may be a map
};

std::map<std::string, int> myDictionary;

    // 添加键值对
    myDictionary["apple"] = 10;
    myDictionary["banana"] = 5;
    myDictionary["orange"] = 8;

#endif