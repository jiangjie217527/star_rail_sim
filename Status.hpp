//
//  Status.hpp
//  Search_text
//
//  Created by 袁瑞翔 on 2024/1/5.
//

#ifndef Status_hpp
#define Status_hpp

#include <stdio.h>
#include "character_info.hpp"
#include "skill.hpp"

// 前向声明
class CombatCharacter;

class Status {
public:
    Status(int to_id, int from_id, double value, const std::string& name, int duration, std::function<void(CombatCharacter&, double)> applyFunc, std::function<void(CombatCharacter&, double)> removeFunc);
    std::string name_get() const;
    int to_get();
    double value_get();
    int duration_get();
    void apply(CombatCharacter& character,double value);
    void remove(CombatCharacter& character,double value);
    void duration_decrease();
private:
    std::string name;
    double value;
    int duration;
    std::function<void(CombatCharacter&, double)> applyFunction;
    std::function<void(CombatCharacter&, double)> removeFunction;
    int to;
    int from;
};

void status_clear(CombatCharacter* status_in_character,std::string status_name);

#endif /* Status_hpp */
