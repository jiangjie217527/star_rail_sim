//
//  Status.cpp
//  Search_text
//
//  Created by 袁瑞翔 on 2024/1/5.
//

#include "Status.hpp"
#include "character_info.hpp"

Status::Status(int to_id, int from_id, double value, const std::string& name, int duration, std::function<void(CombatCharacter&, double)> applyFunc, std::function<void(CombatCharacter&, double)> removeFunc)
        : name(name), value(value), duration(duration), applyFunction(applyFunc), removeFunction(removeFunc), to(to_id), from(from_id){}

std::string Status::name_get() const{
    return name;
}     
double Status::value_get()
{
    return value;
} 
int Status::duration_get()
{
    return duration;
}
int Status::to_get()
{
    return to;
}
void Status::duration_decrease()
{
    duration--;
}
// 应用状态效果
void Status::apply(CombatCharacter& character,double value)
{
    applyFunction(character,value);
}
// 移除状态效果
void Status::remove(CombatCharacter& character,double value)
{
    removeFunction(character,value);
}
void status_clear(CombatCharacter* status_in_character,std::string status_name){
                for(int i=0;i<status_in_character->status.size();i++){
                if(status_in_character->status[i].name_get()==status_name){
                //寻找有无原有的同一种状态
                status_in_character->status[i].remove(*status_in_character,status_in_character->status[i].value_get());
                //调用remove函数，对象为该Status所在的角色，目的为失去该状态的效果（因为要重新apply，所以要remove清一下防止效果多叠了一次）
                status_in_character->status.erase(status_in_character->status.begin()+i);
                //使用erase函数，删除该状态（实际上类似于提前结束该状态，以方便上新的）
                break;
            }
        }
}

