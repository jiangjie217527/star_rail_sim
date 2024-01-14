#pragma once
#include "skill.hpp"
#include "Status.hpp"
#include <cmath>
#include <array>
#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>
#include <vector>
#include <sstream>
#include <functional>
#include <optional>
#include <map>

class attribute_dictionary {
public:
    static std::unordered_map<int, std::array<double, 9>> myDictionary;
    static std::optional<std::array<double, 9>> getEntry(int id);
    static std::unordered_map<int, std::string> myName;
    static std::optional<std::string> getName(int id);
};

enum ELEMENT{
    Fire,
    Ice,
    Wind,
    Quantum,
    Physical,
    Thunder,
    Imaginary,
};

class OriginCharacter {
public:
    OriginCharacter(const std::vector<int>& level, std::optional<std::array<double, 9>> base_value,std::optional<std::string> CharacterName);
    ~OriginCharacter();

    // 调用函数
    std::string name_get() const;
    double time_get() const;
    int id_get() const;
    
    double spd_get() const;
    double hp_get() const;
    double hp_max_get() const;
    double energy_restore_get() const;
    double energy_max_get() const;
    double shield_get() const;
    double atk_get() const;
    double def_get() const;

    double effect_hit_rate_get() const;
    double effect_resist_get() const;

    double crit_rate_get() const;
    double crit_DMG_get() const;

    double vulnerability_get(int i) const;
    double penetrate_get() const;

    int element_get() const;
    
    // change 函数
    double calculateRemainingTime() const;
    void new_time(int time);
    void hp_change(double value);
    void hp_change_max(double value);
    void energy_change(double value);
    void atk_change(double value);
    void def_change(double value);
    void spd_add(double value);
    void crit_rate_change(double value);
    void crit_DMG_change(double value);
    void shield_change(double value);
    void spd_change(double value);
    void shield_remove();
    void vulnerability_decrease(double value, int i);
    void hp_decrease(double damage);
    void penetrate_change(double value);

protected:
    // 角色基础信息
    std::string name;       // Character Name
    int entity_id;          // Character Id
    double time;            // Remaining Time

    // 角色战斗面板属性
    double hp;              // Current Health Point
    double energy_restore;  // Current Energy Restoration
    double atk;             // Attack
    double def;             // Defense
    double spd;             // Speed
    double shield;          // shield

    // 伤害穿透和伤害抵抗
    double penetrate;       // Penetrate 穿透
    std::vector<double> vulnerability;  // Vulnerability 抗性

    // 效果命中率和效果抵抗（debuff的抵抗）
    double effect_hit_rate; // Effect Hit Rate
    double effect_resist;   // Effect Resistance

    // 能量与生命上限
    double energy_max;     // Maximum Energy Point
    double hp_max;         // Highest Health Point

    // 暴击与暴击效果
    double crit_rate;       // Critical Rate
    double crit_DMG;         // Critical Damage
    
    // 元素
    int element;
    //ElementValue dmg_boost; // Damage Boost
    //ElementValue dmg_res;   // Damage Resistance Boost
};

// 前向声明
class Status;

class CombatCharacter : public OriginCharacter{
public:
    CombatCharacter(int id, int character_level, int basic_level, int BPSkill_level, int ultra_level, int talent_level, int rank);
    ~CombatCharacter();
    std::vector<Status> status;
    using ExecuteFunction = short(*)(int, int, std::vector<CombatCharacter*>&, std::vector<CombatCharacter*>&);
    using CheckFunction = short(*)(bool, bool);

    // 调用函数（调用各种等级）
    int code_get() const;
    int basic_level_get() const;
    int character_level_get() const;
    int entity_id_get() const;
    int BPSkill_level_get() const;
    int ultra_level_get() const;
    int talent_level_get() const;
    int rank_get() const;
    int Shengxi_get() const;
    int talent_point_get() const;
    bool team_get() const;
    bool death_get() const;
    bool talent_active_get() const;
    void updateStatus();
    void active_talent();
    void passive_talent();
    void talent_point_add(int a);
    void Shengxi_add(int a);
    void death_change();
    std::string NormalFun_name_get() const;

    // 声明函数指针容器
    std::map<int, ExecuteFunction> normalFunctions;
    std::map<int, ExecuteFunction> skillFunctions;
    std::map<int, ExecuteFunction> ultraFunctions;
    std::map<int, CheckFunction> checkNormalFunctions;
    std::map<int, CheckFunction> checkSkillFunctions;
    std::map<int, CheckFunction> checkUltraFunctions;
    std::map<int, std::string> NormalName;
    
    // 每个角色的普攻、战技和大招
    short* normal(int from, int to, std::vector<CombatCharacter*>& friend_positionQueue, std::vector<CombatCharacter*>& enemy_positionQueue);
    short* skill(int from, int to, std::vector<CombatCharacter*>& friend_positionQueue, std::vector<CombatCharacter*>& enemy_positionQueue);
    short* ultra(int from, int to, std::vector<CombatCharacter*>& friend_positionQueue, std::vector<CombatCharacter*>& enemy_positionQueue);
    short* check_normal(bool from, bool to);
    short* check_skill(bool from, bool to);
    short* check_ultra(bool from, bool to);

protected:
    static int calculator; // 计数器
    int code;              // 角色代号
    int character_level;   // 角色等级
    int basic_level;       // 普攻等级
    int BPSkill_level;     // 战技等级
    int ultra_level;       // 终结等级
    int talent_level;      // 天赋等级
    int rank;              // 星魂等级（暂未开放）
    int talent_point;      // 天赋点（个别角色）
    int Shengxi;           // 生息（个别角色）
    bool talent_active;    // 天赋激活（个别角色）
    bool death;            // 判断角色是否死亡
    bool team;             // 阵营
    std::string NormalFuncName;      // 角色普攻名字
    ExecuteFunction normalFunc;
    ExecuteFunction skillFunc;
    ExecuteFunction ultraFunc;
    CheckFunction checknormalFunc;
    CheckFunction checkskillFunc;
    CheckFunction checkultraFunc;
};

class FriendCharacter : public CombatCharacter{
public:
    FriendCharacter(int id, int character_level, int basic_level, int BPSkill_level, int ultra_level, int talent_level, int rank);
    static int skillpoint;    // 我方角色类的战技点
};

class EnemyCharacter : public CombatCharacter{
public:
    EnemyCharacter(int id, int character_level, int basic_level, int BPSkill_level, int ultra_level, int talent_level, int rank);
    static int skillpoint;    // 敌方角色类的战技点
};
