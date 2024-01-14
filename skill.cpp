// Skill.cpp
#include "skill.hpp"
#include "character_info.hpp"
#include "Status.hpp"

short* CombatCharacter::check_normal(bool from, bool to) {
    
    // 通过函数指针容器调用对应ID的函数
    std::map<int, CombatCharacter::CheckFunction> checkNormalFunctions;
    checkNormalFunctions[1006] = &checkNormalFunction_1;
    checkNormalFunctions[1004] = &checkNormalFunction_1;
    checkNormalFunctions[1208] = &checkNormalFunction_2;
    checkNormalFunctions[1003] = &checkNormalFunction_1;
    checkNormalFunctions[1102] = &checkNormalFunction_1;
    checkNormalFunctions[1107] = &checkNormalFunction_1;
    checkNormalFunctions[1001] = &checkNormalFunction_1;
    checkNormalFunctions[1211] = &checkNormalFunction_1;
    CheckFunction func = checkNormalFunctions[this -> entity_id];
    if (func) {
        short result = func(from, to);
        short* ptr = new short(result);
        return ptr;
    } else {
        std::cerr << "初始化check_normal出现空指针" << std::endl;
        return nullptr; // 处理未找到函数的情况
    }
}
short* CombatCharacter::check_skill(bool from, bool to) {
  
    // 通过函数指针容器调用对应ID的函数
    std::map<int, CombatCharacter::CheckFunction> checkSkillFunctions;
    checkSkillFunctions[1006] = &checkSkillFunction_1006;
    checkSkillFunctions[1004] = &checkSkillFunction_1004;
    checkSkillFunctions[1208] = &checkSkillFunction_1208;
    checkSkillFunctions[1003] = &checkSkillFunction_1003;
    checkSkillFunctions[1102] = &checkSkillFunction_1102;
    checkSkillFunctions[1107] = &checkSkillFunction_1107;
    checkSkillFunctions[1001] = &checkSkillFunction_1001;
    checkSkillFunctions[1211] = &checkSkillFunction_1211;
    CheckFunction func = checkSkillFunctions[this -> entity_id];
    if (func) {
        short result = func(from, to);
        short* ptr = new short(result);
        return ptr;
    } else {
        std::cerr << "初始化check_normal出现空指针" << std::endl;
        return nullptr; // 处理未找到函数的情况
    }
}
short* CombatCharacter::check_ultra(bool from, bool to) {

    // 通过函数指针容器调用对应ID的函数
    std::map<int, CombatCharacter::CheckFunction> checkUltraFunctions;
    checkUltraFunctions[1006] = &checkUltraFunction_1006;
    checkUltraFunctions[1004] = &checkUltraFunction_1004;
    checkUltraFunctions[1208] = &checkUltraFunction_1208;
    checkUltraFunctions[1003] = &checkUltraFunction_1003;
    checkUltraFunctions[1102] = &checkUltraFunction_1102;
    checkUltraFunctions[1107] = &checkUltraFunction_1107;
    checkUltraFunctions[1001] = &checkUltraFunction_1001;
    checkUltraFunctions[1211] = &checkUltraFunction_1211;
    CheckFunction func = checkUltraFunctions[this -> entity_id];
    if (func) {
        short result = func(from, to);
        short* ptr = new short(result);
        return ptr;
    } else {
        std::cerr << "初始化check_normal出现空指针" << std::endl;
        return nullptr; // 处理未找到函数的情况
    }
}

short* CombatCharacter::normal(int from, int to, std::vector<CombatCharacter*>& friend_positionArray, std::vector<CombatCharacter*>& enemy_positionArray) {

    std::map<int, CombatCharacter::ExecuteFunction> normalFunctions;
    normalFunctions[1006] = &NormalFunction_1;
    normalFunctions[1004] = &NormalFunction_1;
    normalFunctions[1208] = &NormalFunction_2;
    normalFunctions[1003] = &NormalFunction_1;
    normalFunctions[1102] = &NormalFunction_1;
    normalFunctions[1107] = &NormalFunction_1;
    normalFunctions[1001] = &NormalFunction_1;
    normalFunctions[1211] = &NormalFunction_1;
    std::map<int, std::string> NormalName;
    NormalName[1006]= "|系统警告|";
    NormalName[1004]= "重力压制";
    NormalName[1003]="武装调律";
    NormalName[1102]= "强袭";
    NormalName[1107]= "我也想帮上忙";
    NormalName[1001]="极寒的弓矢";
    NormalName[1211]="望、闻、问…蹴！";
    NormalName[1208]="始击岁星";
    // 通过函数指针容器调用对应ID的函数
    ExecuteFunction func = normalFunctions[this -> entity_id];
    this->NormalFuncName = NormalName[this -> entity_id];
    if (func) {
        short result = func(from, to, friend_positionArray, enemy_positionArray);
        short* ptr = new short(result);
        return ptr;
    } else {
        std::cerr << "初始化check_normal出现空指针" << std::endl;
        return nullptr; // 处理未找到函数的情况
    }
}
short* CombatCharacter::skill(int from, int to, std::vector<CombatCharacter*>& friend_positionArray, std::vector<CombatCharacter*>& enemy_positionArray) {
          
    std::map<int, CombatCharacter::ExecuteFunction> skillFunctions;
    skillFunctions[1006] = &SkillFunction_1006;
    skillFunctions[1004] = &SkillFunction_1004;
    skillFunctions[1208] = &SkillFunction_1208;
    skillFunctions[1003] = &SkillFunction_1003;
    skillFunctions[1102] = &SkillFunction_1102;
    skillFunctions[1107] = &SkillFunction_1107;
    skillFunctions[1001] = &SkillFunction_1001;
    skillFunctions[1211] = &SkillFunction_1211;
    
    // 通过函数指针容器调用对应ID的函数
    ExecuteFunction func = skillFunctions[this -> entity_id];
    if (func) {
        short result = func(from, to, friend_positionArray, enemy_positionArray);
        short* ptr = new short(result);
        return ptr;
    } else {
        std::cerr << "初始化check_normal出现空指针" << std::endl;
        return nullptr; // 处理未找到函数的情况
    }
}
short* CombatCharacter::ultra(int from, int to, std::vector<CombatCharacter*>& friend_positionArray, std::vector<CombatCharacter*>& enemy_positionArray) {
    
    std::map<int, CombatCharacter::ExecuteFunction> ultraFunctions;
    ultraFunctions[1006] = &UltraFunction_1006;
    ultraFunctions[1004] = &UltraFunction_1004;
    ultraFunctions[1208] = &UltraFunction_1208;
    ultraFunctions[1003] = &UltraFunction_1003;
    ultraFunctions[1102] = &UltraFunction_1102;
    ultraFunctions[1107] = &UltraFunction_1107;
    ultraFunctions[1001] = &UltraFunction_1001;
    ultraFunctions[1211] = &UltraFunction_1211;
    
    // 通过函数指针容器调用对应ID的函数
    ExecuteFunction func = ultraFunctions[this -> entity_id];
    if (func) {
        short result = func(from, to, friend_positionArray, enemy_positionArray);
        short* ptr = new short(result);
        return ptr;
    } else {
        std::cerr << "初始化check_normal出现空指针" << std::endl;
        return nullptr; // 处理未找到函数的情况
    }
}


// check 函数实现
short checkNormalFunction_1(bool from,bool to){
    if (from!=to) {
        return 0;
    }
    else {
        return -3;
    }
}
short checkNormalFunction_2(bool from,bool to){
    if (from!= to) {
        return 0;
    }
    else {
        return -3;
    }
}
short checkSkillFunction_1006(bool from,bool to){
    if (from!= to) {
        return 0;
    }
    else {
        return -3;
    }
}
short checkSkillFunction_1004(bool from,bool to){
    if (from!= to) {
        return 0;
    }
    else {
        return -3;
    }
}
//符玄战技
short checkSkillFunction_1208(bool from,bool to){
    if (from==to) {
        return 0;
    }
    else {
        return -2;
    }
}
short checkSkillFunction_1003(bool from,bool to){
    if (from!= to) {
        return 0;
    }
    else {
        return -3;
    }
}
short checkSkillFunction_1102(bool from,bool to){
    if (from!= to) {
        return 0;
    }
    else {
        return -3;
    }
}
short checkSkillFunction_1107(bool from,bool to){
    if (from!= to) {
        return 0;
    }
    else {
        return -3;
    }
}
// 三月七战技
short checkSkillFunction_1001(bool from,bool to){
    if (from==to) {
        return 0;
    }
    else {
        return -2;
    }
}
//白露战技
short checkSkillFunction_1211(bool from,bool to){
    if (from==to) {
        return 0;
    }
    else {
        return -2;
    }
}
short checkUltraFunction_1006(bool from,bool to){
    if (from!= to) {
        return 0;
    }
    else {
        return -3;
    }
}
short checkUltraFunction_1004(bool from,bool to){
    if (from!= to) {
        return 0;
    }
    else {
        return -3;
    }
}
short checkUltraFunction_1208(bool from,bool to){
    if (from!= to) {
        return 0;
    }
    else {
        return -3;
    }
}
short checkUltraFunction_1003(bool from,bool to){
    if (from!= to) {
        return 0;
    }
    else {
        return -3;
    }
}
short checkUltraFunction_1102(bool from,bool to){
    if (from!= to) {
        return 0;
    }
    else {
        return -3;
    }
}
// 克拉拉大招
short checkUltraFunction_1107(bool from,bool to){
    if (from==to) {
        return 0;
    }
    else {
        return -2;
    }
}
short checkUltraFunction_1001(bool from,bool to){
    if (from!= to) {
        return 0;
    }
    else {
        return -3;
    }
}
//白露大招
short checkUltraFunction_1211(bool from,bool to){
    if (from==to) {
        return 0;
    }
    else {
        return -2;
    }
}

// execute 函数实现
// 在加上一个新状态前，清除原有的同一种状态，重新添加，重新apply：
// 亮点：这样子新加而不是直接延长原有时间，是因为两次施加时，施加者与被施加者的面板、具体状态都会改变，实际效果的数值可能会变化，故我们重新覆盖添加，更加严谨
bool IfUltraInvalid(int from, int to, std::vector<CombatCharacter*> FromChas, std::vector<CombatCharacter*> ToChas) {
    if (from<0 || from>FromChas.size() - 1 || to<0 || to>ToChas.size() - 1) {
        std::cout << "输入错误" << std::endl;
    }//检查输入是否合法
    bool IfEnergyMax = false;
    IfEnergyMax = (FromChas[from]->energy_restore_get() == FromChas[from]->energy_max_get());//能量判断
    if (IfEnergyMax == false) {
        std::cout << "无法使用终结技" << std::endl;
        return false;//输出不能释放的信号
    }
    return true;
};
//声明，下面会用到DamageResult
void DamageResult(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters, double damage);
void DamageResult_with_March7_talent(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters, double damage)
{
    int where_is_march7 = -1;
    //for循环寻找To队列中的三月七(因为是To队列中成员受伤要三月七反击)，得到她的位置，以获取其攻击力(反击伤害计算使用)
    for (auto i = 0; i < ToCharacters.size(); i++) {
        if (ToCharacters[i]->entity_id_get() == 1001) {
            where_is_march7 = i;
            break;
        }
    }
    //三月七在(不为-1)，并且目标有护盾，且三月七有点数
    if (where_is_march7 != -1 &&ToCharacters[to]->shield_get() > 0 && ToCharacters[where_is_march7]->talent_point_get() > 0&&ToCharacters[where_is_march7]->hp_get()>0)
    {
        double random_num = (double)rand() / RAND_MAX;
        double atk_result;
        double def_result;
        if (random_num < ToCharacters[where_is_march7]->crit_rate_get())//判断是否暴击
            //暴击时的攻击力效果，要用whereismarch7来调出三月七的攻击力等数据，尤其注意是To队列
            atk_result = (0.45 + ToCharacters[where_is_march7]->talent_level_get() * 0.05) * ToCharacters[where_is_march7]->atk_get()
            * (1 + ToCharacters[where_is_march7]->crit_DMG_get());
        else
            //不暴击的攻击力效果
            atk_result = (0.45 + ToCharacters[where_is_march7]->talent_level_get() * 0.05) * ToCharacters[where_is_march7]->atk_get();
            //防御力效果，注意是From队列中的from，也就是对三月七队友进行damage的人
        def_result = (ToCharacters[where_is_march7]->character_level_get() * 10 + 200)
            / (FromCharacters[from]->def_get() + (ToCharacters[where_is_march7]->character_level_get() * 10 + 200));
            //效果相乘，并加上攻击者(三月七)元素穿透与受击者(From[from])对应的元素抗性(也就是对三月七的冰元素的抗性)
        double damage_March7_talent = atk_result * def_result
            * (1 + ToCharacters[where_is_march7]->penetrate_get() - FromCharacters[from]->vulnerability_get(ToCharacters[where_is_march7]->element_get()));
            //调用DamageResult函数，结算伤害，反击攻击者三月七
            std::cout << "三月七触发天赋 少女的特权，对"<<FromCharacters[from]->name_get()<<"反击"<< std::endl;
        DamageResult(where_is_march7, from, ToCharacters, FromCharacters, damage_March7_talent);
        IfKill(where_is_march7, from, ToCharacters, FromCharacters);
            //三月七的反击天赋点数减一
        ToCharacters[where_is_march7]->talent_point_add(-1);
            //三月七的能量加10
        ToCharacters[where_is_march7]->energy_change(10);
        return;
    }
    else
        return;
}

//克拉拉反击天赋
void DamageResult_with_Clara_talent(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters, double damage)
{
    //亮点：这里的静态变量是为了在反击过程中暂时限制二次反击，尤其是克拉拉攻击克拉拉的时候，防止出现连续反击(即对反击伤害进行反击)
    static int callCount = 1;
    if (ToCharacters[to]->entity_id_get() == 1107 && callCount > 0&&ToCharacters[to]->hp_get()>0) {
        if (ToCharacters[to]->talent_point_get() <= 0)//判断大招点数，是否进行强化反击(这里是不)
        {
            ToCharacters[to]->talent_point_add(-ToCharacters[to]->talent_point_get());
            callCount--;//暂时抑制克拉拉在反击过程中反击能力，限制二次反击
            double random_num = (double)rand() / RAND_MAX;
            double atk_result;
            double def_result;
            if (random_num < ToCharacters[to]->crit_rate_get())
                //暴击的攻击力效果
                atk_result = (0.72 + ToCharacters[to]->talent_level_get() * 0.08) * ToCharacters[to]->atk_get()*(1 + ToCharacters[to]->crit_DMG_get());
            else
                //不暴击的攻击力效果
                atk_result = (0.72 + ToCharacters[to]->talent_level_get() * 0.08) * ToCharacters[to]->atk_get();
                //防御力效果，注意是From队列中的from，也就是对克拉拉队友进行damage的人
                def_result = (ToCharacters[to]->character_level_get() * 10 + 200)
                / (FromCharacters[from]->def_get() + (ToCharacters[to]->character_level_get() * 10 + 200));
                //效果相乘，并加上攻击者(克拉拉)元素穿透与受击者(From[from])对应的元素抗性(也就是对克拉拉的物理元素伤害的抗性)
            double damage_Clara_talent = atk_result * def_result
                * (1 + ToCharacters[to]->penetrate_get() - FromCharacters[from]->vulnerability_get(ToCharacters[to]->element_get()));
            std::cout << "触发克拉拉天赋 因为我们是家人"<<"(效果:对"<<FromCharacters[from]->name_get()<<"反击并施加\"反击标志\" ) "<< std::endl;
            DamageResult(to, from, ToCharacters, FromCharacters, damage_Clara_talent);
            //检查是否已经有了反击标志这一状态，有则清楚，重新添加
            status_clear(FromCharacters[from],std::string("反击标志"));
            //添加反击标志，这里反击标志无法自行随回合数消失，故加了1000的duration，理论上不会在战斗结束前消失
            Status Clara_StrikeBack_Figure(from, to, 0.0, std::string("反击标志"), 1000, [](CombatCharacter& from, double value) {}, [](CombatCharacter& from, double value) {});
            FromCharacters[from]->status.push_back(Clara_StrikeBack_Figure);
            //恢复克拉拉的反击能力
            callCount++;
            //克拉拉的能量加5
            FromCharacters[from]->energy_change(5);

        }

        else//进行强化反击
        {
            std::cout << "克拉拉触发天赋 因为我们是家人"<<"(触发效果:对"<<FromCharacters[from]->name_get()<<"及其相邻目标强化反击施加\"反击标志\" ) "<< std::endl;
            //克拉拉的大招点数减一
            ToCharacters[to]->talent_point_add(-1);
            //暂时抑制克拉拉在反击过程中的反击能力，限制二次反击
            callCount--;
            double random_num = (double)rand() / RAND_MAX;
            double atk_result;
            double def_result;
            //同样的，计算伤害，分为暴击不暴击两种，防御力是From[from]，攻击力是To[to](也就是克拉拉)
            if (random_num < ToCharacters[to]->crit_rate_get())
                atk_result = (0.72 + ToCharacters[to]->talent_level_get() * 0.08 + 0.896 + 0.064 * ToCharacters[to]->ultra_level_get()) * ToCharacters[to]->atk_get()
                * (1 + ToCharacters[to]->crit_DMG_get());
            else
                atk_result = (0.72 + ToCharacters[to]->talent_level_get() * 0.08) * ToCharacters[to]->atk_get();
            def_result = (ToCharacters[to]->character_level_get() * 10 + 200)
                / (FromCharacters[from]->def_get() + (ToCharacters[to]->character_level_get() * 10 + 200));
            double damage_Clara_talent = atk_result * def_result
                * (1 + ToCharacters[to]->penetrate_get() - FromCharacters[from]->vulnerability_get(ToCharacters[to]->element_get()));
            //对反击主目标造成伤害
            DamageResult(to, from, ToCharacters, FromCharacters, damage_Clara_talent);
            //对反击主目标添加(或者覆盖)反击标志
            status_clear(FromCharacters[from],std::string("反击标志"));
            Status Clara_StrikeBack_Figure(from, to, 0, std::string("反击标志"), 1000, [](CombatCharacter& from, double value) {}, [](CombatCharacter& from, double value) {});
            FromCharacters[from]->status.push_back(Clara_StrikeBack_Figure);
            if (from > 0)//判断反击主目标左侧是否有对象，有，则对左侧这一对象扩散50%对主目标的伤害
            {
                //对左侧这一对象扩散50%对主目标的伤害
                DamageResult(to, from - 1, ToCharacters, FromCharacters, 0.5*damage_Clara_talent);
                //对左侧这一对象添加(或者覆盖)反击标志
                status_clear(FromCharacters[from - 1],std::string("反击标志"));
                Status Clara_StrikeBack_Figure(from - 1, to, 0, std::string("反击标志"), 1000, [](CombatCharacter& from, double value) {}, [](CombatCharacter& from, double value) {});
                FromCharacters[from - 1]->status.push_back(Clara_StrikeBack_Figure);
            }
            if (from < FromCharacters.size() - 1)//判断反击主目标右侧是否有对象，有，则对右侧这一对象扩散50%对主目标的伤害
             {
                //对右侧这一对象扩散50%对主目标的伤害
                DamageResult(to, from + 1, ToCharacters, FromCharacters, 0.5*damage_Clara_talent);
                //对右侧这一对象添加(或者覆盖)反击标志
                status_clear(FromCharacters[from + 1],std::string("反击标志"));
                Status Clara_StrikeBack_Figure(from + 1, to, 0, std::string("反击标志"), 1000, [](CombatCharacter& from, double value) {}, [](CombatCharacter& from, double value) {});
                FromCharacters[from + 1]->status.push_back(Clara_StrikeBack_Figure);
            }

            //恢复克拉拉的反击能力
            callCount++;
            FromCharacters[from]->energy_change(5);
        }
    }
    else callCount = 1;
    return;
}

//生息效果的生效与白露复活天赋
void DamageResult_with_Bailu_talent(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters, double damage)
{
    int where_is_bailu = -1;
    //寻找白露，以后续获得她的数值进行计算
    for (auto i = 0; i < ToCharacters.size(); i++) {
        if (ToCharacters[i]->entity_id_get() == 1211) {
            where_is_bailu = i;
            break;
        }
    }

    //条件：被攻击对象列中有白露，自己具有生息状态(有生息点数)，还没死，则回复一定生命量(由白露决定)
    if (where_is_bailu != -1 && ToCharacters[to]->Shengxi_get() > 0 && ToCharacters[to]->hp_get() > 0&&ToCharacters[where_is_bailu]->hp_get()>0)
    {
            //计算白露天赋“生息”的回复量，这里使用了二次多项式拟合，回复数值来自白露的面板、技能等级
        double Shengxi_heal = (-0.3598 * ToCharacters[where_is_bailu]->talent_level_get() * ToCharacters[where_is_bailu]->talent_level_get()
            + 15.544 * ToCharacters[where_is_bailu]->talent_level_get() + 27.971)
            + ((0.0338 + 0.0022 * ToCharacters[where_is_bailu]->talent_level_get()) * ToCharacters[where_is_bailu]->hp_max_get());
            //被攻击角色To[to]回复生息回复量
        ToCharacters[to]->hp_change(Shengxi_heal);
            //被攻击角色的生息点数减一
        ToCharacters[to]->Shengxi_add(-1);
    }

    //白露复活 条件：队中有白露，被攻击角色被该次攻击致死，同时白露的复活天赋暂未使用(false)
    if((where_is_bailu != -1)&&(ToCharacters[to]->hp_get()<=0)&&(ToCharacters[where_is_bailu]->talent_active_get()==false)&&ToCharacters[where_is_bailu]->hp_get()>0)
    {
        //被攻击角色To[to]复活，复活的生命值由白露的面板与技能等级决定
        ToCharacters[to]->hp_change(
        (70+50*ToCharacters[where_is_bailu]->talent_level_get()
        +(0.12+0.01*ToCharacters[where_is_bailu]->talent_level_get())*ToCharacters[where_is_bailu]->hp_max_get())
        -ToCharacters[to]->hp_get());
        //白露复活是否使用变为true(已经使用)
        ToCharacters[where_is_bailu]->active_talent();
        std::cout << "白露触发天赋 奔走悬壶济世长(触发效果:使"<<ToCharacters[to]->name_get()<<"复活)"<< std::endl;
    }
};

//符玄的生命回复天赋
void DamageResult_with_Fuxuan_talent(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters, double damage)
{
        //条件：被攻击对象为符玄，被攻击角色还没死，被攻击角色的生命值小于一半，符玄生命恢复天赋大于0
    if (ToCharacters[to]->entity_id_get() == 1208 && ToCharacters[to]->talent_point_get() > 0
        && ToCharacters[to]->hp_get() > 0 && ToCharacters[to]->hp_get() < (0.5 * ToCharacters[to]->hp_max_get()))
    {
        //生命恢复，恢复量取决于符玄已经损失的血量与技能等级
        ToCharacters[to]->hp_change((0.79 + 0.01 * ToCharacters[to]->talent_level_get()) * (ToCharacters[to]->hp_max_get() - ToCharacters[to]->hp_get()));
        //符玄生命恢复天赋点数减一
        ToCharacters[to]->talent_point_add(-1);
        std::cout << "符玄触发天赋 乾清坤夷，否极泰来(触发效果：符玄生命回复)" << std::endl;
        return;
    }
    else
        return;
};

//将所有类型的伤害结算可能写在同一个函数中，并让所有伤害的生效都通过这个函数；
//一是可以充分检查各种减伤效果、各种结算方式，二是保证所有的受击类天赋都能充分的、不遗漏的响应、触发，使被动检查能完全覆盖到所有的攻击之中
//细分了所有的伤害结算可能，同时对每个伤害，都在合适都时候检查了受击型天赋
//同时，在这里进行天赋判断，还实现了三月七反击天赋，克拉拉反击天赋，白露天赋(生息与复活)，符玄天赋这四个优先度极高、且强制执行的被动，
//进行了即时的、强制的插队执行效果，还原了游戏中的天赋优先度与天赋合适的触发时间，触发先后
//亮点!!!
void DamageResult(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters, double damage)
{
    //被攻击角色的能量加10
    ToCharacters[to]->energy_change(10);
    bool iffuxuan = false;
    bool iffuxuan_skill = false;
    int WhereIsFuxuan = -1;
    bool IfClara_ultraresult = false;

    //先判断三月七的天赋，是否反击(因为要看护盾，所以最早，在伤害执行前就判断)
    DamageResult_with_March7_talent(from, to, FromCharacters, ToCharacters, damage);

    //寻找符玄，判断穷观阵(符玄战技)是否打开，同时以便后续获得她的数值进行计算
    for (int i = 0; i < ToCharacters.size(); i++) {
        if (ToCharacters[i]->entity_id_get() == 1208) {
            iffuxuan = true;
            WhereIsFuxuan = i;
            break;}}
    
            if (WhereIsFuxuan != -1 && ToCharacters[WhereIsFuxuan]->talent_active_get() == true)
                iffuxuan_skill = true;

    if (iffuxuan_skill) //符玄战技开启
    {
        //伤害降低
        damage *= (1-(0.092+0.008*ToCharacters[WhereIsFuxuan]->talent_level_get()));
        //返回未经To[to]的防御力效果作用的原始攻击力伤害效果
        double origin_damage = damage /
            ((FromCharacters[from]->character_level_get() * 10 + 200) / (ToCharacters[to]->def_get() + (FromCharacters[from]->character_level_get() * 10 + 200)));
        //将原始攻击力伤害效果的65%作用于符玄，用符玄的防御力效果进行计算
        double damage_for_fuxuan = 0.65 * origin_damage * ((FromCharacters[from]->character_level_get() * 10 + 200) / (ToCharacters[WhereIsFuxuan]->def_get() + (FromCharacters[from]->character_level_get() * 10 + 200)));
        //将原始攻击力伤害效果的35%作用于To[to]，用To[to]的防御力效果进行计算
        double damage_for_to = 0.35 * origin_damage * ((FromCharacters[from]->character_level_get() * 10 + 200) / (ToCharacters[to]->def_get() + (FromCharacters[from]->character_level_get() * 10 + 200)));
        
        //判断受击角色是不是开启了 大招的克拉拉(有没有克拉拉大招的伤害降低状态)
        for (int j = 0; j < ToCharacters[to]->status.size(); j++)
        {
            if (ToCharacters[to]->status[j].name_get() == "克拉拉大招伤害降低")
            {
                IfClara_ultraresult = true;
                break;
            }
        }

        if (ToCharacters[to]->entity_id_get() == 1107 && IfClara_ultraresult)//受击角色To[to]是开启了大招的克拉拉
        {
            damage_for_to *= 1 - 0.1 - 0.14 - 0.01 * ToCharacters[to]->ultra_level_get();//大招的减伤效果
        }
        else if (ToCharacters[to]->entity_id_get() == 1107) { damage_for_to *= 0.9; }//受击角色是未开启大招的克拉拉，常驻减伤
        //伤害作用在To[to]身上(已考虑护盾)
        ToCharacters[to]->hp_decrease(damage_for_to);
        //伤害作用在符玄身上，已考虑护盾
        ToCharacters[WhereIsFuxuan]->hp_decrease(damage_for_fuxuan);
    }

    else //没有穷观阵，没有伤害分担
    {
        if (iffuxuan == true) {
            for (int j = 0; j < ToCharacters[to]->status.size(); j++) {
                if (ToCharacters[to]->status[j].name_get() == "克拉拉大招伤害降低")
                {
                    IfClara_ultraresult = true; break;
                }
            }
            if (ToCharacters[to]->entity_id_get() == 1107 && IfClara_ultraresult)//受击角色To[to]是开启了大招的克拉拉
            {
                damage *= 1 - 0.1 - 0.14 - 0.01 * ToCharacters[to]->ultra_level_get();//大招减伤
            }
            else if (ToCharacters[to]->entity_id_get() == 1107) { damage *= 0.9; } //受击角色To[to]是未开启了大招的克拉拉，常驻减伤
            damage *= (1-(0.092+0.008*ToCharacters[WhereIsFuxuan]->talent_level_get())); //队内有符玄，则触发符玄的常驻减伤效果
            //伤害作用在To[to]身上(已考虑护盾)
            ToCharacters[to]->hp_decrease(damage);
        }

        else //队内没有符玄
        {
            for (int j = 0; j < ToCharacters[to]->status.size(); j++) {
                if (ToCharacters[to]->status[j].name_get() == "克拉拉大招伤害降低")
                {
                    IfClara_ultraresult = true; break;
                }
            }
            if (ToCharacters[to]->entity_id_get() == 1107 && IfClara_ultraresult)//受击角色To[to]是开启了大招的克拉拉
            {
                damage *= 1 - 0.1 - 0.14 - 0.01 * ToCharacters[to]->ultra_level_get();
            }
            else if (ToCharacters[to]->entity_id_get() == 1107) { damage *= 0.9; }//受击角色To[to]是未开启了大招的克拉拉，常驻减伤
            //伤害作用在To[to]身上(已考虑护盾)
            ToCharacters[to]->hp_decrease(damage);
        }
    }
    //检查白露的天赋是否触发：1)是否进行生息回复；2)是否进行复活
    DamageResult_with_Bailu_talent(from, to, FromCharacters, ToCharacters, damage);
    //检查克拉拉天赋是否触发，是否克拉拉受击，触发反击/强化反击
    DamageResult_with_Clara_talent(from, to, FromCharacters, ToCharacters, damage);
    //检查符玄的天赋是否触发：是否进行生命恢复
    DamageResult_with_Fuxuan_talent(from, to, FromCharacters, ToCharacters, damage);
    }

//用于计算非目标的防御力
double Exact_def(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters)
{
    return  (FromCharacters[from]->character_level_get() * 10 + 200) / (ToCharacters[to]->def_get() + (FromCharacters[from]->character_level_get() * 10 + 200));
}

//判断受击对象是否被这次攻击击杀
short IfKill(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters)
{
    if (ToCharacters[to]->hp_get() <= 0)//击杀成功(白露复活天赋在此之前已经判断)
     {
        ToCharacters[to]->death_change();//标记一下死亡
        switch (ToCharacters[to]->entity_id_get())
        {
        case 1006:
            for (int i = 0; i < FromCharacters.size(); i++)
            {
                status_clear(FromCharacters[i], std::string("银狼全抗性下降"));
                status_clear(FromCharacters[i], std::string("银狼给的弱点抗性下降"));
                status_clear(FromCharacters[i], std::string("银狼给的大招防御力降低"));
                status_clear(FromCharacters[i], std::string("攻击缺陷"));
                status_clear(FromCharacters[i], std::string("防御缺陷"));
                status_clear(FromCharacters[i], std::string("速度缺陷"));
            }
            break;
        case 1004:
            for (int i = 0; i < FromCharacters.size(); i++)
            {
                status_clear(FromCharacters[i], std::string("瓦尔特战技减速"));
                status_clear(FromCharacters[i], std::string("禁锢减速"));
                status_clear(FromCharacters[i], std::string("禁锢延缓"));
            }
            break;
        case 1208:
            for (int i = 0; i < ToCharacters.size(); i++)
            {
                status_clear(ToCharacters[i], std::string("穷观阵"));
            }
            break;
            //希儿的buff都是自身触发的，死了之后就没用了,当然要想robust一点还是得加上(状态查询能查死人吗)
        case 1107:
            for (int i = 0; i < FromCharacters.size(); i++)
            {
                status_clear(ToCharacters[i], std::string("反击标志"));
            }
            break;
        case 1001:
            for (int i = 0; i < ToCharacters.size(); i++)
            {
                status_clear(ToCharacters[i], std::string("三月七的护盾"));
            }
        break;
        case 1211:
            for (int i = 0; i < ToCharacters.size(); i++)
            {
                status_clear(ToCharacters[i], std::string("生息"));
            }
            break;
        }
    KaiQiQiongguanDeFuXuan(ToCharacters);
         
    for (auto i = ToCharacters.begin(); i != ToCharacters.end();)//使用迭代器删除队列元素
         {
            if (*i == ToCharacters[to]) {
                i = ToCharacters.erase(i);//从操作队列中删除这一元素，用erase防止出现对空对象指针操作(对“尸体”操作的现象发生)
                break;
            }
            else
                i++;
        }
        //击杀回能10
        FromCharacters[from]->energy_change(10);
        if (FromCharacters[from]->entity_id_get() == 1102) {

            std::cout << "触发希儿天赋 因为再现"<<"(效果:希儿获得额外回合)"<< std::endl;
            //如果是希儿击杀，触发再动天赋，并输出2以表征
            return 2;
        }
        //正常输出1，表征成功的非希儿击杀
        return 1;
     }
    return 0;
}
// 普攻的第一种情况
short NormalFunction_1(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters){
    double atk_result;
    double def_result;
    //生成一个0-1的随机数，用来判断暴击与否
    //计算攻击力效果(暴击/不暴击)
    double random_num = (double)rand() / RAND_MAX;
    if (random_num < FromCharacters[from]->crit_rate_get())
        atk_result = FromCharacters[from]->atk_get() * (0.4 + 0.1 * (FromCharacters[from]->basic_level_get())) * (1 + FromCharacters[from]->crit_DMG_get());
    else
        atk_result = FromCharacters[from]->atk_get() * (0.4 + 0.1 * (FromCharacters[from]->basic_level_get()));
    std::cout<<"行动执行："<<FromCharacters[from]->name_get()<<"释放普攻 "<<FromCharacters[from]->NormalFun_name_get()<<std::endl;
    //如果是银狼攻击，判断天赋是否发生
    //这里先触发再结算是因为可能天赋先减防再进行伤害判断
    if(FromCharacters[from]->entity_id_get()==1006)
    TalentFunction_1006(from, to, FromCharacters, ToCharacters);
    //计算防御力效果
    def_result = (FromCharacters[from]->character_level_get() * 10 + 200) / (ToCharacters[to]->def_get() + (FromCharacters[from]->character_level_get() * 10 + 200));
    //计算伤害(包括元素穿透元素抗性)
    double damage = atk_result * def_result * (1 + FromCharacters[from]->penetrate_get() - ToCharacters[to]->vulnerability_get(FromCharacters[from]->element_get()));

    //如果是瓦尔特攻击，判断天赋是否发生，是否加上附加伤害
    if(FromCharacters[from]->entity_id_get()==1004)
    damage += TalentFunction_1004(from, to, FromCharacters, ToCharacters);
    //结算伤害，同时判断各个受击型天赋的触发
    DamageResult(from, to, FromCharacters, ToCharacters, damage);

    //如果是三月七攻击，恢复天赋的反击次数为2点(三月七的两个回合间能2次触发)
    if(FromCharacters[from]->entity_id_get()==1001)
    FromCharacters[from]->talent_point_add(2-FromCharacters[from]->talent_point_get());
    //普通攻击回20
    FromCharacters[from]->energy_change(20);
    //判断是否击杀了攻击对象并抹去击杀的对象，击杀有回能
    short killresult=IfKill(from, to, FromCharacters, ToCharacters);
    if(killresult>1)//大于1，即击杀成功，而且是希儿击杀
        {
        //为希儿添加/覆盖1回合的damage_increase增幅状态，伤害增加
        status_clear(FromCharacters[from],std::string("希儿增幅状态"));
        Status Seele_increase_damage(to,from,0.36+0.04*FromCharacters[from]->talent_level_get(), std::string("希儿增幅状态"),2,[](CombatCharacter& character, double value) {},[](CombatCharacter& character, double value) {});
        FromCharacters[from]->status.push_back(Seele_increase_damage);
        return 3;
        }
        //非希儿击杀的其他情况下，正常表征一下普攻成功
        return 1;
    }
    
// 普攻的第二种情况，用于符玄普通攻击的
short NormalFunction_2(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters)
{
    std::cout << "行动执行：符玄" << "释放普攻 始击岁星" << std::endl;
    double hpatk_result;
    double def_result;
    //生成一个0-1的随机数
    double random_num = (double)rand() / RAND_MAX;
        //用生命值计算“攻击效果”
    if (random_num < FromCharacters[from]->crit_rate_get())
        hpatk_result = FromCharacters[from]->hp_max_get() * (0.2 + 0.05 * (FromCharacters[from]->basic_level_get())) * (1 + FromCharacters[from]->crit_DMG_get());
    else
        hpatk_result = FromCharacters[from]->hp_max_get() * (0.2 + 0.05 * (FromCharacters[from]->basic_level_get()));
    def_result = (FromCharacters[from]->character_level_get() * 10 + 200) / (ToCharacters[to]->def_get() + (FromCharacters[from]->character_level_get() * 10 + 200));
        //计算伤害(包括防御力效果，元素穿透与元素抗性)
    double damage = hpatk_result * def_result*(1+FromCharacters[from]->penetrate_get()-ToCharacters[to]->vulnerability_get(FromCharacters[from]->element_get()));
        //结算伤害，同时判断各个受击型天赋的触发
        //因为是符玄普攻，不需要判断瓦尔特、银狼天赋触发与三月七天赋恢复
    DamageResult(from, to, FromCharacters, ToCharacters, damage);
        //判断是否击杀了攻击对象并抹去击杀的对象，击杀有回能，显然不会是希儿击杀，不判断希儿
    IfKill(from, to, FromCharacters, ToCharacters);
        //普通攻击回20
    FromCharacters[from]->energy_change(20);
    KaiQiQiongguanDeFuXuan(FromCharacters);
    //检查穷观阵效果是否失效
    return 1;
}

//三月七

//护盾增加value
void SkillFunction_1001_addShield(CombatCharacter& character, double value) {
    character.shield_change(value);
}
 //护盾移除，变为0(无论还剩与否，都为0)
void SkillFunction_1001_removeShield(CombatCharacter& character, double value) {
    character.shield_remove();
}
short SkillFunction_1001(int from, int to, std::vector<CombatCharacter*>& FromCharacters,std::vector<CombatCharacter*>& ToCharacters) {
    //由三月七的面板与技能等级，获取护盾值ShieldValue，
    double ShieldValue = FromCharacters[from]->def_get() * (0.36 + 0.02 * FromCharacters[from]->BPSkill_level_get()) + 51.65625 * FromCharacters[from]->BPSkill_level_get() + 233.7;
    //添加/覆盖一个来自三月七的护盾状态，加入到statuses，其中包括施加者，被施加者，持续时间，
    //以及两个函数指针，分别实现护盾添加与护盾移除(状态到时或者被清除)的效果
    status_clear(FromCharacters[to],std::string("三月七的护盾"));
    Status Match7ShieldStatus(to, from, ShieldValue, std::string("三月七的护盾"), 3, SkillFunction_1001_addShield, SkillFunction_1001_removeShield);
    FromCharacters[to]->status.push_back(Match7ShieldStatus);
    Status* lastone = &FromCharacters[to]->status.back();
    //取出最新加入的状态，应用状态，调用SkillFunction_1001_addShield函数，进行护盾添加，添加值为之前的护盾值ShieldValue
    lastone->apply(*FromCharacters[to], ShieldValue);
    //三月七的战技回30能量
    FromCharacters[from]->energy_change(30);
    //三月七行动一次，她新的一回合开始，反击次数恢复为2
    FromCharacters[from]->talent_point_add(2-FromCharacters[from]->talent_point_get());
    //返回1，表示战技释放成功
    std::cout << "行动执行：三月七释放战技 " << "可爱即是正义" << std::endl;
    std::cout << "触发效果：为" << FromCharacters[to]->name_get() << "提供护盾" << std::endl;
    return 1;
}

void Frozen(int form, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters)
{
    double damage = FromCharacters[form]->atk_get() * (0.84 + 0.06 * FromCharacters[form]->BPSkill_level_get());
    Status Match7FrozenStatus(to, form,damage, std::string("冻结"), 1, [](CombatCharacter&, double){}, [](CombatCharacter&, double){});
    ToCharacters[to]->status.push_back(Match7FrozenStatus);
}
short UltraFunction_1001(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters) {
    if (!IfUltraInvalid(from, to, FromCharacters, ToCharacters))
         return -2;
    //计算攻击力效果(未考虑暴击)
    double Ice_Value = FromCharacters[from]->atk_get() * (0.84 + 0.06 * FromCharacters[from]->BPSkill_level_get());
    double atk_result;
    double random_num = (double)rand() / RAND_MAX;
    {
        //暴击的攻击力效果
        if (random_num < FromCharacters[from]->crit_rate_get())
        {
            atk_result = Ice_Value * (1 + FromCharacters[from]->crit_DMG_get());
        }
        //不暴击的攻击力效果
        else
        {
            atk_result = Ice_Value;
        }

        for (int i = 0; i < ToCharacters.size(); i++)//大招的全体伤害
        {
            DamageResult(from, i, FromCharacters, ToCharacters, atk_result * Exact_def(from, i, FromCharacters, ToCharacters));
     
        }//伤害效果damage为攻击力效果乘以(对应受击者防御力相关与元素抗性元素穿透的)复合属性
        std::cout << "行动执行：三月七释放终结技 " << "冰刻箭雨之时" << std::endl;
        std::cout << "触发效果：使";
        for (int j = 0; j < ToCharacters.size(); j++)//冰冻的判定
        {
            double random_frozen = (double)rand() / RAND_MAX;//随机数判断是否进行冰冻，
            
                //冰冻的实际概率=基础概率*(1+效果命中)*(1-效果抵抗)
                //当0~1均匀分布的随机数小于实际概率时，我们认为这次判定中，冰冻应该生效
                //亮点：利用0~1均匀分布的随机数，与实际概率比较，实现足够随机性，有实际概率意义的判断
                if (random_frozen < 0.5*(1+FromCharacters[from]->effect_hit_rate_get())*(1-ToCharacters[j]->effect_resist_get()))
                {
                    //施加冰冻状态
        Frozen(from, j, FromCharacters, ToCharacters);
        std::cout << ToCharacters[j]->name_get() << " ";
                }
        }
        std::cout << "陷入冰冻状态" << std::endl;
        for (int i = 0; i < ToCharacters.size(); i++)
        {
            //判断是否击杀了攻击对象并抹去击杀的对象(这里是对方全体的每一个)，击杀有回能
            short killresult = IfKill(from, i, FromCharacters, ToCharacters); }
        }
    //释放完终结技，能量清空
    FromCharacters[from]->energy_change(-FromCharacters[from]->energy_restore_get());
    //能量回5
    FromCharacters[from]->energy_change(5);
    //返回0，表示终结技释放成功
    return 0;
    }

// 瓦尔特
short SkillFunction_1004(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters) {
    double atk_result;
    double def_result;
    double random_num = (double)rand() / RAND_MAX;    //生成一个0-1的随机数 暴击判断

    //暴击与非暴击情况下的攻击效果计算
    if (random_num < FromCharacters[from]->crit_rate_get())
        atk_result = FromCharacters[from]->atk_get() * (0.324 + 0.036 * (FromCharacters[from]->BPSkill_level_get())) * (1 + FromCharacters[from]->crit_DMG_get());
    else
        atk_result = FromCharacters[from]->atk_get() * (0.324 + 0.036 * (FromCharacters[from]->BPSkill_level_get()));
    //防御力效果
    def_result = (FromCharacters[from]->character_level_get() * 10 + 200) / (ToCharacters[to]->def_get() + (FromCharacters[from]->character_level_get() * 10 + 200));
    //伤害=攻击效果*防御效果*(1+元素穿透-元素抗性)而抗性取对应攻击元素属性的值，取时的定位依靠攻击者属性的元素序号获得
    double damage = atk_result * def_result * (1 + FromCharacters[from]->penetrate_get() - ToCharacters[to]->vulnerability_get(FromCharacters[from]->element_get()));
    //生成一个0-1的随机数 判断减速生效概率
    double random_numforSlow = (double)rand() / RAND_MAX;
    
    std::cout << "行动执行：瓦尔特释放战技 " << "虚空断界" << std::endl;
    
    //减速的实际概率=基础概率*(1+效果命中)*(1-效果抵抗)
    //当0~1均匀分布的随机数小于实际概率时，我们认为这次判定中，减速应该生效
    if (random_numforSlow < (0.64 + 0.01 * FromCharacters[from]->BPSkill_level_get()) * (1 + FromCharacters[from]->effect_hit_rate_get()) * (1 - ToCharacters[to]->effect_resist_get()))
    {
        //减速如果生效，添加/覆盖一个减速状态类实现减速与恢复(带计时)效果，加入对象的statuses
        status_clear(ToCharacters[to],std::string("瓦尔特战技减速"));
        Status WeltSkillEffect(to, from, 0.9, std::string("瓦尔特战技减速"), 2, [](CombatCharacter &, double){}, [](CombatCharacter &, double){});
        ToCharacters[to]->status.push_back(WeltSkillEffect);
        std::cout << "触发效果：使" << ToCharacters[to]->name_get() << "速度降低" << std::endl;
    }

    //结算伤害，同时判断各个受击型天赋的触发
    //触发瓦尔特天赋的附加伤害判断
    DamageResult(from, to, FromCharacters, ToCharacters,damage+TalentFunction_1004(from, to, FromCharacters, ToCharacters));
    //判断是否击杀了攻击对象并抹去击杀的对象，击杀有回能
    IfKill(from, to, FromCharacters, ToCharacters);

    for (int i = 0; i < 2; i++)
    //接下来是两次随机的攻击，对象换为随机，其他相同
    {
        //生成一个0-1的随机数 判断减速生效概率
        double random_numforSlow2 = (double)rand() / RAND_MAX;
        //生成0-(size-1)的随机数，即弹射目标序号
        int random_object = rand() % (ToCharacters.size());
        //伤害=攻击效果*防御效果*(1+元素穿透-元素抗性)而抗性取对应攻击元素属性的值，取时的定位依靠攻击者属性的元素序号获得
        double damage2 = atk_result * def_result * (1 + FromCharacters[from]->penetrate_get() - ToCharacters[random_object]->vulnerability_get(FromCharacters[from]->element_get()));

        //判断减速生效是否
        if (random_numforSlow2 < (0.64 + 0.01 * FromCharacters[from]->BPSkill_level_get()) * (1 + FromCharacters[from]->effect_hit_rate_get()) * (1 - ToCharacters[random_object]->effect_resist_get()))
        {
            //减速如果生效，添加/覆盖一个减速状态实现减速与恢复(带计时)效果
            status_clear(ToCharacters[to],std::string("瓦尔特战技减速"));
            Status WeltSkillEffect(to, from, 0.9, std::string("瓦尔特战技减速"), 2, [](CombatCharacter &, double){}, [](CombatCharacter &, double){});
            ToCharacters[random_object]->status.push_back(WeltSkillEffect);
            std::cout << "使" << ToCharacters[random_object]->name_get() << "速度降低，";
        }
        //结算伤害，同时判断各个受击型天赋的触发
        //触发瓦尔特天赋的附加伤害判断4
        DamageResult(from, random_object, FromCharacters, ToCharacters,
        damage2+TalentFunction_1004(from, random_object, FromCharacters, ToCharacters));

        //判断是否击杀了攻击对象并抹去击杀的对象，击杀有回能
        IfKill(from, random_object, FromCharacters, ToCharacters);
    }
    //战技回复能量30点
    FromCharacters[from]->energy_change(30);
    return 1;
}
short UltraFunction_1004(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters) {
    if (!IfUltraInvalid(from, to, FromCharacters, ToCharacters))
        return -2;
    double atk_result_origin = FromCharacters[from]->atk_get() * (0.84 + 0.06 * FromCharacters[from]->BPSkill_level_get());//伤害描述相关
    double atk_result;
    double random_num = (double)rand() / RAND_MAX;


    //判断暴击与否
    if (random_num < FromCharacters[from]->crit_rate_get())
        //暴击的攻击力效果
    {
        atk_result = atk_result_origin * (1 + FromCharacters[from]->crit_DMG_get());
    }
    else
        //不暴击的攻击力效果
    {
        atk_result = atk_result_origin;
    }

    std::cout << "行动执行：瓦尔特释放终结技 " << "拟似黑洞" << std::endl;
    std::cout << "触发效果：使";

    for (int i = 0; i < ToCharacters.size(); i++) {
        double p = 1;
        double random_Defensedrop = (double)rand() / RAND_MAX;
        
        //如果随机数小于实际概率，则造成禁锢效果
        if (random_Defensedrop < p * (1 + FromCharacters[from]->effect_hit_rate_get()) * (1 - ToCharacters[i]->effect_resist_get()))
        {
            //禁锢如果判断生效，则添加/覆盖“禁锢减速”“禁锢延缓”状态实现减速与恢复(带计时)效果，加入对象的statuses
            status_clear(ToCharacters[i], std::string("禁锢减速"));
            Status SpeeddropStatus(i, from, 0.9, std::string("禁锢减速"), 1, [](CombatCharacter&, double) {}, [](CombatCharacter&, double) {});
            ToCharacters[i]->status.push_back(SpeeddropStatus);
            status_clear(ToCharacters[i], std::string("禁锢延缓"));
            Status ActiondropStatus(i, from, 1 - (0.312 + 0.08 * FromCharacters[from]->ultra_level_get()), std::string("禁锢延缓"), 1, [](CombatCharacter&, double) {}, [](CombatCharacter&, double) {});
            ToCharacters[i]->status.push_back(ActiondropStatus);
            
            std::cout << ToCharacters[i]->name_get() << " ";

            //添加禁锢状态，使速度减缓，行动减缓
            //持续1回合后，使速度减缓，行动减缓的效果恢复
        }
        std::cout << "陷入禁锢状态 行动延后且速度延缓" << std::endl;
        //大招的全体伤害
        //对每个对象造成伤害，伤害效果为攻击力效果乘以(对应受击者i防御力相关与元素抗性元素穿透的)复合属性
        //触发瓦尔特天赋的附加伤害判断
        std::cout << "对另一方" << ToCharacters[i]->name_get() << "造成伤害" << std::endl;
        DamageResult(from, i, FromCharacters, ToCharacters, atk_result * Exact_def(from, i, FromCharacters, ToCharacters)
            + TalentFunction_1004(from, i, FromCharacters, ToCharacters));
        
    }
   //判断是否击杀了攻击对象并抹去击杀的对象，击杀有回能
    for(int i=0;i<ToCharacters.size();i++){
        IfKill(from, i, FromCharacters, ToCharacters);}
    //终结技耗费全部能量
    FromCharacters[from]->energy_change(-FromCharacters[from]->energy_restore_get());
    //终结技回复能量5点
    FromCharacters[from]->energy_change(5);
    //返回0表示终结技释放成功
    
    return 0;
}
double TalentFunction_1004(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters)
//这里有一个大改：附加伤害不应该单独结算一次，要在一次攻击中共同伤害结算掉，
//所以我改成了一个double，返回附加伤害量(没有就是0)，加在原来的技能伤害上面
//然后我把所有攻击的伤害结算放到了减速效果施加后再结算这一次攻击，这样就能正确的在状态添加之后，触发天赋判断
{    std::cout << "瓦尔特触发天赋 时空扭曲 (触发效果：对";
    double damage = 0.0;
    for (int i = 0; i < ToCharacters[to]->status.size(); i++) {
        //判断是否对象有减速类的状态
        if (ToCharacters[to]->status[i].name_get() == "瓦尔特战技减速"
            || ToCharacters[to]->status[i].name_get() == "禁锢减速"
            || ToCharacters[to]->status[i].name_get() == "速度缺陷")
        {
            double atk_result;
            double def_result;
            //生成一个0-1的随机数,判断暴击与否
            double random_num = (double)rand() / RAND_MAX;
            //伤害值计算
            if (random_num < FromCharacters[from]->crit_rate_get())
                atk_result = FromCharacters[from]->atk_get() * (0.27 + 0.03 * (FromCharacters[from]->talent_level_get())) * (1 + FromCharacters[from]->crit_DMG_get());
            else
                atk_result = FromCharacters[from]->atk_get() * (0.27 + 0.03 * (FromCharacters[from]->talent_level_get()));
            def_result = (FromCharacters[from]->character_level_get() * 10 + 200) / (ToCharacters[to]->def_get() + (FromCharacters[from]->character_level_get() * 10 + 200));
            damage = atk_result * def_result * (1 + FromCharacters[from]->penetrate_get() - ToCharacters[to]->vulnerability_get(FromCharacters[from]->element_get()));
            break;
        }
    }
    if(damage!=0) std::cout<<ToCharacters[to]->name_get();
    else std::cout<<"无人";
    std::cout <<"造成额外伤害)"<< std::endl;
    return damage;
}
// 银狼
void SkillFunction_1006_1_addVulnerabilityDecrease(CombatCharacter& character, double value) {
    //全抗性降低
    for (int i = 0; i < character.status.size(); i++)
        character.vulnerability_decrease(value, i);
}
void SkillFunction_1006_1_removeVulnerabilityDecrease(CombatCharacter& character, double value) {
    //用于移除全抗性降低
    for (int i = 0; i < character.status.size(); i++)
        character.vulnerability_decrease(-value, i);
}
void SkillFunction_1006_2_addWeak(CombatCharacter& character, double value) {
    //指定属性的抗性降低
    //value=weak(int)+0.2，0.2为削减值，int weak确认削减位置(抗性属性)
    int weak = int(value - 0.2);
    character.vulnerability_decrease(0.2, weak);
}
void SkillFunction_1006_2_removeWeak(CombatCharacter& character, double value) {
    //用于移除指定属性的抗性降低
    int weak = int(value - 0.2);
    character.vulnerability_decrease(-0.2, weak);
}
short SkillFunction_1006(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters) {
    double atk_result;
    double def_result;
    //随机选取我方队列中的目标
    int random_object = rand() % (FromCharacters.size());
    //选择一个我方队友，获得他的元素属性
    int random_weak = FromCharacters[random_object]->element_get();
    //第一个效果生效概率
    double random_numforskill_1 = (double)rand() / RAND_MAX;
    //第二个效果(植入弱点)生效概率
    double random_numforskill_2_weak = (double)rand() / RAND_MAX;
    //抗性下降如果生效，添加/覆盖一个抗性下降状态实现抗性下降与恢复(带计时)效果
    //应用状态生效的函数，使抗性下降
    //持续2回合后，使抗性下降的效果恢复
    //第一个效果的实现，将全抗性降低0.075
     std::cout << "行动执行：银狼" << "释放战技 是否允许更改？"<<std::endl<<"触发效果：";
    if (random_numforskill_1 < (1 + FromCharacters[from]->effect_hit_rate_get()) * (1 - ToCharacters[to]->effect_resist_get()))
    {
        status_clear(ToCharacters[to], std::string("银狼全抗性下降"));
        Status SliverWolfSkill_1(to, from, 0.075, std::string("银狼全抗性下降"), 2, SkillFunction_1006_1_addVulnerabilityDecrease, SkillFunction_1006_1_removeVulnerabilityDecrease);
        ToCharacters[to]->status.push_back(SliverWolfSkill_1);
        Status* lastone = &ToCharacters[to]->status.back();
        lastone->apply(*ToCharacters[to], 0.075);
        std::cout <<"使"<<ToCharacters[to]->name_get()<<"全抗性下降" << std::endl;
    }
    //抗性下降如果生效，添加/覆盖一个抗性下降状态实现抗性下降与恢复(带计时)效果
    //应用状态生效的函数，使抗性下降
    //持续2回合后，使抗性下降的效果恢复
    //第二个效果的实现，将value分为两个量，一个标志位置，一个是削减值0.2
    if (random_numforskill_2_weak < (0.74 + 0.01 * FromCharacters[from]->BPSkill_level_get()) * (1 + FromCharacters[from]->effect_hit_rate_get()) * (1 - ToCharacters[to]->effect_resist_get()))
    {
        status_clear(ToCharacters[to], std::string("银狼给的弱点抗性下降"));
        Status SliverWolfSkill_2_GiveWeak(to, from, double(random_weak + 0.2), std::string("银狼给的弱点抗性下降"), 2, SkillFunction_1006_2_addWeak, SkillFunction_1006_2_removeWeak);
        ToCharacters[to]->status.push_back(SliverWolfSkill_2_GiveWeak);
        Status* lastone = &ToCharacters[to]->status.back();
        lastone->apply(*ToCharacters[to], random_weak + 0.2);
        std::vector<std::string> Element = {"Fire","Ice","Wind","Quantum","Physical","Thunder","Imaginary"};
        std::cout <<"为"<<ToCharacters[to]->name_get()<<"施加"<<Element[random_weak]<<"弱点,降低对应抗性" << std::endl;
    }
    std::cout <<"对"<<ToCharacters[to]->name_get()<<"造成伤害"<<std::endl;
    //生成一个0-1的随机数 判断暴击与否
    double random_num = (double)rand() / RAND_MAX;
    if (random_num < FromCharacters[from]->crit_rate_get())
        atk_result = FromCharacters[from]->atk_get() * (0.882 + 0.098 * (FromCharacters[from]->basic_level_get())) * (1 + FromCharacters[from]->crit_DMG_get());
    else
        atk_result = FromCharacters[from]->atk_get() * (0.882 + 0.098 * (FromCharacters[from]->basic_level_get()));
    def_result = (FromCharacters[from]->character_level_get() * 10 + 200) / (ToCharacters[to]->def_get() + (FromCharacters[from]->character_level_get() * 10 + 200));
    double damage = atk_result * def_result * (1 + FromCharacters[from]->penetrate_get() - ToCharacters[to]->vulnerability_get(FromCharacters[from]->element_get()));
    //判断伤害
    DamageResult(from, to, FromCharacters, ToCharacters, damage);
    //银狼天赋，攻击后随机造成缺陷
    TalentFunction_1006(from, to, FromCharacters, ToCharacters);
    FromCharacters[from]->energy_change(30);
    IfKill(from, to, FromCharacters, ToCharacters);
    return 1;
};
void UltraFunction_1006_Defensedrop(CombatCharacter& character, double value) {
    // 实际的减少防御的逻辑
    character.def_change(-character.def_get() * (0.351 + 0.09 * character.BPSkill_level_get()));


};
void UltraFunction_1006_removeDefensedrop(CombatCharacter& character, double value) {
    // 用于移除减少防御的debuff
    character.def_change(character.def_get() * (0.351 + 0.09 * character.BPSkill_level_get()));


};
short UltraFunction_1006(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters) {
    std::cout << "行动执行：银狼释放终结技 " << "|账号已封禁|" << std::endl;
    if (!IfUltraInvalid(from, to, FromCharacters, ToCharacters))
        return -2;
    //防御与攻击的计算
    double atk_result_origin = FromCharacters[from]->atk_get() * (2.128 + 0.152 * FromCharacters[from]->ultra_level_get());
    double def = (FromCharacters[from]->character_level_get() * 10 + 200) / (ToCharacters[to]->def_get() + (FromCharacters[from]->character_level_get() * 10 + 200));
    double damage;
    double Dropvalue = 0.009 * FromCharacters[from]->ultra_level_get() + 0.351;
    double random_num = (double)rand() / RAND_MAX;
    //暴击的计算
    if (random_num < FromCharacters[from]->crit_rate_get())
    {
        damage = atk_result_origin * (1 + FromCharacters[from]->crit_DMG_get()) * def
            * (1 + FromCharacters[from]->penetrate_get() + ToCharacters[to]->vulnerability_get(FromCharacters[from]->element_get()));
    }
    else
    {
        damage = atk_result_origin * def
            * (1 + FromCharacters[from]->penetrate_get() + ToCharacters[to]->vulnerability_get(FromCharacters[from]->element_get()));
    }

    //防御力降低的概率
    double p = 0.835 + 0.015 * FromCharacters[from]->ultra_level_get();
    DamageResult(from, to, FromCharacters, ToCharacters, damage);
    TalentFunction_1006(from, to, FromCharacters, ToCharacters);
    double random_Defensedrop = (double)rand() / RAND_MAX;
    //随机的防御力降低
    if (random_Defensedrop < p)
        //防御力降低生效，即应用防御力降低函数
        //持续3回合后，使防御力下降的效果恢复
    {
        status_clear(ToCharacters[to], std::string("银狼大招防御力降低"));
        Status DefensedropStatus(to, from, 0, std::string("银狼大招防御力降低"), 3, UltraFunction_1006_Defensedrop, UltraFunction_1006_removeDefensedrop);
        ToCharacters[to]->status.push_back(DefensedropStatus);
        Status* lastone = &ToCharacters[to]->status.back();
        lastone->apply(*ToCharacters[to], Dropvalue);
        std::cout << "触发效果：使" << ToCharacters[to]->name_get() << "防御力降低" << std::endl;

    }

    IfKill(from, to, FromCharacters, ToCharacters);
    FromCharacters[from]->energy_change(-FromCharacters[from]->energy_restore_get());
    FromCharacters[from]->energy_change(5);


    return 0;
}
void TalentFunction_1006(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters)
{
    //在己方队列中寻找银狼，如果找到，返回银狼在队列中的位置
    int where_is_Siverwolf = -1;
    for (auto i = 0; i < FromCharacters.size(); i++)
    {
        if (FromCharacters[i]->entity_id_get() == 1006)
        {
            where_is_Siverwolf = i;
            break;
        }
    }

    double random_num = (double)rand() / RAND_MAX;
    double p = 0.588 + 0.012 * FromCharacters[where_is_Siverwolf]->talent_level_get();
    //随机生成0，1，2中一个数
    int random_object = rand() % (3);

    //银狼攻击下降

    //创建一个vector然后将三种缺陷状态塞到vector里，缺陷函数的定义见下
    std::vector<Status> Random_effect;
    Status AttackdropStatus(to, from, (0.045 + 0.005 * FromCharacters[where_is_Siverwolf]->talent_level_get()), std::string("攻击缺陷"), 3, Attack_reduction, Attack_recover);
    Status DefensedropStatus(to, from, (0.036 + 0.004 * FromCharacters[where_is_Siverwolf]->talent_level_get()), std::string("防御缺陷"), 3, Defense_reduction, Defense_recover);
    Status SpeeddropStatus(to, from, (1 - (0.027 + 0.003 * FromCharacters[where_is_Siverwolf]->talent_level_get())), std::string("速度缺陷"), 3, [](CombatCharacter&, double) {}, [](CombatCharacter&, double) {});
    Random_effect.push_back(AttackdropStatus);
    Random_effect.push_back(DefensedropStatus);
    Random_effect.push_back(SpeeddropStatus);
    //判断是否触发三种缺陷之一，如果触发，则先清除之前对应的状态然后再加上缺陷状态
    //缺陷状态过三回合恢复
    if (random_num < p && random_num > 0)
    {
        status_clear(ToCharacters[to], Random_effect[random_object].name_get());
        ToCharacters[to]->status.push_back(Random_effect[random_object]);
        Status* lastone = &ToCharacters[to]->status.back();
        lastone->apply(*ToCharacters[to], lastone->value_get());
        ToCharacters[to]->updateStatus();
        std::cout << "银狼触发天赋 " << "等待程序响应… (触发效果：使" << ToCharacters[to]->name_get() << "产生缺陷" << Random_effect[random_object].name_get() << ")" << std::endl;
    }
};
//以下是缺陷状态和恢复缺陷状态的函数
void Attack_reduction(CombatCharacter& character, double value)
{
    character.atk_change(-value * character.atk_get());
}
void Defense_reduction(CombatCharacter& character, double value)
{
    character.def_change(-value * character.def_get());
}
void Attack_recover(CombatCharacter& character, double value)
{
    character.atk_change(value * character.atk_get());
}
void Defense_recover(CombatCharacter& character, double value)
{
    character.def_change(value * character.def_get());
}

//符玄
void KaiQiQiongguanDeFuXuan(std::vector<CombatCharacter*>& FromCharacters)
//这个函数用来判断穷观阵是否已经生效，要不要生效以及是否到时了要失效
{

    bool iffuxuan = false;
    //首先寻找队列中的符玄，得到位置
    int WhereIsFuxuan2 = -1;
    for (int i = 0; i < FromCharacters.size(); i++) {
        if (FromCharacters[i]->entity_id_get() == 1208) {
            iffuxuan = true;
            WhereIsFuxuan2 = i;
            break;
        }
    }
    //用状态名的遍历判断符玄是否具有穷观阵状态，有，则ifQiongguan = true
    bool ifQiongguan = false;
    if (iffuxuan && WhereIsFuxuan2 != -1) {
        for (int i = 0; i < FromCharacters[WhereIsFuxuan2]->status.size(); i++) {
            if (FromCharacters[WhereIsFuxuan2]->status[i].name_get() == "穷观阵"&&FromCharacters[WhereIsFuxuan2]->status[i].duration_get()>1) {
                ifQiongguan = true;
                break;
            }
        }
    }
    if (ifQiongguan && WhereIsFuxuan2 != -1 && FromCharacters[WhereIsFuxuan2]->talent_active_get() == false)
        //当有符玄存在，符玄具有穷观阵但是穷观阵效果还没生效(talent_active_get()==false)时，
        //执行下面的效果，并且把符玄的talent_active_get()改为true，标记已经生效了
    {
        for (int i = 0; i < FromCharacters.size(); i++) {
            FromCharacters[i]->hp_change_max(
                ((0.027 + 0.003 * FromCharacters[WhereIsFuxuan2]->BPSkill_level_get()) * FromCharacters[WhereIsFuxuan2]->hp_max_get()));
            FromCharacters[i]->hp_change(
                ((0.027 + 0.003 * FromCharacters[WhereIsFuxuan2]->BPSkill_level_get()) * FromCharacters[WhereIsFuxuan2]->hp_max_get()));
            FromCharacters[i]->crit_rate_change(0.054 + 0.006 * FromCharacters[WhereIsFuxuan2]->BPSkill_level_get());
        }
        //标记已经生效了，避免穷观阵重复生效，重复加暴击与生命
        FromCharacters[WhereIsFuxuan2]->active_talent();
    }
    else if (ifQiongguan == false && WhereIsFuxuan2 !=-1 && FromCharacters[WhereIsFuxuan2]->talent_active_get() == true)
        //当有符玄存在，符玄不具有穷观阵但是穷观阵还在生效，效果没有移除(talent_active_get()==true)时，
        //执行下面的效果，并且把符玄的talent_active_get()改为false，标记已经失效了下一个穷观阵释放后可以再生效

    {   //失去效果
        for (int i = 0; i < FromCharacters.size(); i++) {
            FromCharacters[i]->hp_change_max((
                -((0.027 + 0.003 * FromCharacters[WhereIsFuxuan2]->BPSkill_level_get()) * FromCharacters[WhereIsFuxuan2]->hp_max_get())));
            if (FromCharacters[i]->hp_get() > FromCharacters[i]->hp_max_get())
                FromCharacters[i]->hp_decrease(FromCharacters[i]->hp_get() - FromCharacters[i]->hp_max_get());
            FromCharacters[i]->crit_rate_change(-(0.054 + 0.006 * FromCharacters[WhereIsFuxuan2]->BPSkill_level_get()));
        }
        //标记已经失效了，避免穷观阵重复失效，重复减暴击与生命
        FromCharacters[WhereIsFuxuan2]->passive_talent();
    }
    else return;
}
short SkillFunction_1208(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters) {
    status_clear(FromCharacters[from], std::string("穷观阵"));
    Status FuxuanQiongguanzhen(to, from, 0.0, std::string("穷观阵"), 4, [](CombatCharacter&, double) {}, [](CombatCharacter&, double) {});
    FromCharacters[from]->status.push_back(FuxuanQiongguanzhen);
    Status* lastone = &FromCharacters[from]->status.back();
    lastone->apply(*FromCharacters[from], 0.00);
    KaiQiQiongguanDeFuXuan(FromCharacters);
    FromCharacters[from]->energy_change(30);
    std::cout << "行动执行：符玄释放战技 " << "太微行棋，灵台示影" << std::endl;
    std::cout << "触发效果：开启穷观阵，分摊伤害，提升全队生命上限、暴击率" << std::endl;

    return 1;
}
short UltraFunction_1208(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters) {
    std::cout << "行动执行：符玄释放终结技 " << "天律大衍，历劫归一" << std::endl;
    std::cout << "触发效果：获得1次触发符玄天赋生命回复的机会" << std::endl;
    if (!IfUltraInvalid(from, to, FromCharacters, FromCharacters)) { return -2; }
    double hp_max_result;
    double def_result;
    //生成一个0-1的随机数
    double random_num = (double)rand() / RAND_MAX;
    if (random_num < FromCharacters[from]->crit_rate_get())
        hp_max_result = FromCharacters[from]->hp_max_get() * (0.56 + 0.04 * (FromCharacters[from]->ultra_level_get())) * (1 + FromCharacters[from]->crit_DMG_get());
    else
        hp_max_result = FromCharacters[from]->hp_max_get() * (0.56 + 0.04 * (FromCharacters[from]->ultra_level_get()));

    //对敌方全体造成伤害
    for (int i = 0; i < ToCharacters.size(); i++) {
        def_result = (FromCharacters[from]->character_level_get() * 10 + 200) / (ToCharacters[i]->def_get() + (FromCharacters[from]->character_level_get() * 10 + 200));
        double damage = hp_max_result * def_result * (1 + FromCharacters[from]->penetrate_get() - ToCharacters[i]->vulnerability_get(FromCharacters[from]->element_get()));
        DamageResult(from, i, FromCharacters, ToCharacters, damage);
    }
    for(int i=0;i<ToCharacters.size();i++){
        IfKill(from, i, FromCharacters, ToCharacters);
    }
    //增加一点天赋触发次数
    FromCharacters[from]->talent_point_add(1);
    //触发次数最大为二，如果超过了就减掉
    if (FromCharacters[from]->talent_point_get() > 2) {
        FromCharacters[from]->talent_point_add(2 - FromCharacters[from]->talent_point_get());
    };
    FromCharacters[from]->energy_change(-FromCharacters[from]->energy_restore_get());
    FromCharacters[from]->energy_change(5);



    return 0;
}


//白露
void UltraFunction_1211_applyShengxi(CombatCharacter& character, double value) {
    bool ifShengxi = false;
    //检测队列中有没有白露
    for (int i = 0; i < character.status.size(); i++) {
        if (character.status[i].name_get() == "生息") {
            ifShengxi = true;
            break;
        }
    }
    if (ifShengxi == true) { character.Shengxi_add(2 - character.Shengxi_get()); }
    else { character.Shengxi_add(-character.Shengxi_get()); }
}
void UltraFunction_1211_removeShengxi(CombatCharacter& character, double value) {
    //生息的效果移除
    character.Shengxi_add(-character.Shengxi_get());
}
short UltraFunction_1211(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters) {
    if (!IfUltraInvalid(from, to, FromCharacters, FromCharacters)) { return -2; }
    // 治疗效果
    double heal_value = (0.0844 + FromCharacters[from]->ultra_level_get() * 0.0056) * FromCharacters[from]->hp_max_get()
        + (-0.8994 * FromCharacters[from]->ultra_level_get() * FromCharacters[from]->ultra_level_get() + 38.859 * FromCharacters[from]->ultra_level_get() + 69.928);
    //全体治疗
    for (int i = 0; i < FromCharacters.size(); i++) {
        FromCharacters[i]->hp_change(heal_value);
        int Shengxibuff_Remaining_rounds = 0;
        //寻找生息剩余回合数
        for (int j = 0; j < FromCharacters[i]->status.size(); j++) {
            if (FromCharacters[i]->status[j].name_get() == "生息") {
                Shengxibuff_Remaining_rounds = FromCharacters[i]->status[j].duration_get();
                FromCharacters[i]->status.erase(FromCharacters[i]->status.begin() + j);
                break;
            }}
            
            //生息的叠加计数
            int Shengxibuff_rounds = Shengxibuff_Remaining_rounds + int(Shengxibuff_Remaining_rounds == 0) + 1;
            
            //生息效果的应用和移除
            status_clear(FromCharacters[i], std::string("生息"));
            Status UltraHeal(to, from, 0.1, std::string("生息"), Shengxibuff_rounds, UltraFunction_1211_applyShengxi, UltraFunction_1211_removeShengxi);
            FromCharacters[i]->status.push_back(UltraHeal);
            Status* lastone = &FromCharacters[i]->status.back();
            lastone->apply(*FromCharacters[i], 0);
        }
    FromCharacters[from]->energy_change(-FromCharacters[from]->energy_restore_get());
    FromCharacters[from]->energy_change(5);
    std::cout << "行动执行：白露释放终结技 " << "匏蛟跃渊先雷音" << std::endl;
    std::cout << "触发效果：为白露方全体回复生命值、附加\"生息\"状态";
    
    return 0;
}
double Const_Heal(int from, std::vector<CombatCharacter*>& FromCharacters)
{
    //白露战技的固定治疗量，方便在战技里面调用
    double Const_HealValue = 0;
    switch (FromCharacters[from]->BPSkill_level_get())
    {
    case 1:
        Const_HealValue = 78;
    case 2:
        Const_HealValue = 124.8;
    case 3:
        Const_HealValue = 159.9;
    case 4:
        Const_HealValue = 195;
    case 5:
        Const_HealValue = 218.4;
    case 6:
        Const_HealValue = 241.8;
    case 7:
        Const_HealValue = 259.35;
    case 8:
        Const_HealValue = 276.9;
    case 9:
        Const_HealValue = 294.45;
    case 10:
        Const_HealValue = 312;
    case 11:
        Const_HealValue = 329.55;
    case 12:
        Const_HealValue = 347.1;
    case 13:
        Const_HealValue = 364.65;
    case 14:
        Const_HealValue = 382.2;
    case 15:
        Const_HealValue = 399.75;

    }
    return Const_HealValue;
}
short SkillFunction_1211(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters) {
    double Bailu_heal_Value = FromCharacters[from]->hp_max_get() * (0.0731 + 0.0049 * FromCharacters[from]->hp_max_get()) + Const_Heal(from, FromCharacters);
   
    FromCharacters[to]->hp_change(Bailu_heal_Value);
    //生成0-(size-1)的随机数，即弹射目标序号
    int random_object1 = rand() % (FromCharacters.size());
    //第一次随机治疗
    FromCharacters[random_object1]->hp_change(Bailu_heal_Value * 0.85);
    //第二次随机治疗
    int random_object2 = rand() % (FromCharacters.size());
    FromCharacters[random_object2]->hp_change(Bailu_heal_Value * 0.85 * 0.85);
    FromCharacters[from]->energy_change(30);

    std::cout << "行动执行：白露释放战技 " << "云吟乍涌坠珠露" << std::endl;
    std::cout << "触发效果：为" << FromCharacters[to] << "、";
    std::cout << FromCharacters[random_object1]->name_get() << "、" << FromCharacters[random_object2]->name_get() << "进行治疗" << std::endl;

    return 1;
}

// 克拉拉
short SkillFunction_1107(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters) {
    double atk_result;
    double def_result;
    double damage;
    double random_num = (double)rand() / RAND_MAX;
    if (random_num < FromCharacters[from]->crit_rate_get())
        //暴击的计算
        atk_result = FromCharacters[from]->atk_get() * (0.54 + 0.06 * (FromCharacters[from]->BPSkill_level_get())) * (1 + FromCharacters[from]->crit_DMG_get());
    else
        atk_result = FromCharacters[from]->atk_get() * (0.54 + 0.06 * (FromCharacters[from]->BPSkill_level_get()));
    std::cout << "行动执行：克拉拉" << "释放战技 史瓦罗在看着你"<< std::endl;
    std::cout <<"触发效果：对有反击标记的"<<std::endl;
    //伤害的计算
    int num_exact_attckback=0;
    for (int i = 0; i < ToCharacters.size(); i++) {
        def_result = (FromCharacters[from]->character_level_get() * 10 + 200) / (ToCharacters[i]->def_get() + (FromCharacters[from]->character_level_get() * 10 + 200));
        damage = atk_result * def_result * (1 + FromCharacters[from]->penetrate_get() - ToCharacters[i]->vulnerability_get(FromCharacters[from]->element_get()));
        bool ifClara_StrikeBack_Figure = false;
        int Status_Position_of_Clara_StrikeBack = -1;
        //查询对方队列中对象的反击标志和有反击标志的对象位置
        for (int j = 0; j < ToCharacters[i]->status.size(); j++) {
            if (ToCharacters[i]->status[j].name_get() == "反击标志") {
                ifClara_StrikeBack_Figure = true;
                Status_Position_of_Clara_StrikeBack = j;
                break;
            }
        }
        //如果对方有反击标志，造成两倍伤害，并且使得反击标志失效
        if (ifClara_StrikeBack_Figure == true && Status_Position_of_Clara_StrikeBack != -1) {
            DamageResult(from, i, FromCharacters, ToCharacters, damage * 2);
            ToCharacters[i]->status.erase(ToCharacters[i]->status.begin() + Status_Position_of_Clara_StrikeBack);
            std::cout<<ToCharacters[i]->name_get()<<" "<<std::endl;
            num_exact_attckback++;
        }
        else {
            //如果没有反击标志则造成正常伤害
            DamageResult(from, i, FromCharacters, ToCharacters, damage);
        }
    }
    for(int j = 0; j < ToCharacters.size(); j++){
            IfKill(from, j, FromCharacters, ToCharacters);
        }
    std::cout <<"共计"<<num_exact_attckback<<"个对象造成额外伤害" << std::endl;
    FromCharacters[from]->energy_change(30);

    return 1;
}
short UltraFunction_1107(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters) {
    if (!IfUltraInvalid(from, to, FromCharacters, FromCharacters)) { return -2; }
    //克拉拉天赋得到强化
    FromCharacters[from]->talent_point_add(2 - FromCharacters[from]->talent_point_get());
    //克拉拉大招减伤效果的应用和移除
    status_clear(FromCharacters[from], std::string("克拉拉大招伤害降低"));
    Status Ultra_1107(to, from, 0.14 + 0.01 * FromCharacters[from]->ultra_level_get(), std::string("克拉拉大招伤害降低"), 3, [](CombatCharacter& from, double value) {}, [](CombatCharacter& from, double value) {});
    FromCharacters[from]->status.push_back(Ultra_1107);
    Status* lastone = &FromCharacters[from]->status.back();
    lastone->apply(*FromCharacters[from], 0);
    FromCharacters[from]->energy_change(-FromCharacters[from]->energy_restore_get());
    FromCharacters[from]->energy_change(5);

    std::cout << "行动执行：克拉拉释放终结技 " << "是约定不是命令" << std::endl;
    std::cout << "触发效果：使克拉拉受到的伤害额外降低，获得两次强化反击" << std::endl;

    return 0;
}

// Himeko 姬子
short SkillFunction_1003(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters) {
    //伤害描述相关
    double Fire_Value = FromCharacters[from]->atk_get() * (0.9 + 0.1 * FromCharacters[from]->BPSkill_level_get());
    double atk_result;
    double random_num = (double)rand() / RAND_MAX;
    {
        if (random_num < FromCharacters[from]->crit_rate_get())
            //暴击
        {
            atk_result = Fire_Value * (1 + FromCharacters[from]->crit_DMG_get()) *
                (1 + FromCharacters[from]->penetrate_get() - (ToCharacters[to]->vulnerability_get(FromCharacters[from]->element_get())));
        }
        else
        {
            atk_result = Fire_Value * (1 + FromCharacters[from]->penetrate_get() - (ToCharacters[to]->vulnerability_get(FromCharacters[from]->element_get())));
        }
    }
    std::cout << "行动执行：姬子释放战技 " << "熔核爆裂" << std::endl;
    std::cout << "触发效果：对" << ToCharacters[to] << "及其相邻对象造成伤害" << std::endl;
    {
        //扩散伤害，需要计算与目标相邻的对象的防御力，同时要防止虚空索敌(即to==0时打到-1的对象)，因此分类讨论
        if (to < 0 || to >= ToCharacters.size())
        {}
        else if (to == 0)
        {
            DamageResult(from, to, FromCharacters, ToCharacters, atk_result * Exact_def(from, to, FromCharacters, ToCharacters));
            IfKill(from, to, FromCharacters, ToCharacters);
            if (ToCharacters.size() != 1)
            {
                DamageResult(from, 1, FromCharacters, ToCharacters, 0.4 * atk_result * Exact_def(from, 1, FromCharacters, ToCharacters));
                IfKill(from, 1, FromCharacters, ToCharacters);
            }
        }
        else if (to == ToCharacters.size() - 1)
        {
            DamageResult(from, to, FromCharacters, ToCharacters, atk_result * Exact_def(from, to, FromCharacters, ToCharacters));
            DamageResult(from, to - 1, FromCharacters, ToCharacters, 0.4 * atk_result * Exact_def(from, to - 1, FromCharacters, ToCharacters));
            IfKill(from, to, FromCharacters, ToCharacters);
            IfKill(from, to - 1, FromCharacters, ToCharacters);
        }
        else if (to > 0 && to < ToCharacters.size() - 1)
        {
            DamageResult(from, to, FromCharacters, ToCharacters, atk_result * Exact_def(from, to, FromCharacters, ToCharacters));
            DamageResult(from, to - 1, FromCharacters, ToCharacters, 0.4 * atk_result * Exact_def(from, to - 1, FromCharacters, ToCharacters));
            DamageResult(from, to + 1, FromCharacters, ToCharacters, 0.4 * atk_result * Exact_def(from, to + 1, FromCharacters, ToCharacters));
            IfKill(from, to, FromCharacters, ToCharacters);
            IfKill(from, to - 1, FromCharacters, ToCharacters);
            IfKill(from, to + 1, FromCharacters, ToCharacters);
        }
    }
    FromCharacters[from]->energy_change(30);


    return 1;
}
short UltraFunction_1003(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters) {
    std::cout << "行动执行：姬子释放终结技 " << "天坠之火" << std::endl;
    std::cout << "触发效果：每消灭1个敌方目标额外恢复姬子能量" << std::endl;
    if (!IfUltraInvalid(from, to, FromCharacters, FromCharacters)) { return -2; }
    double atk_result;
    double def_result;
    //生成一个0-1的随机数
    double random_num = (double)rand() / RAND_MAX;
    if (random_num < FromCharacters[from]->crit_rate_get())
        //计算暴击
        atk_result = FromCharacters[from]->atk_get() * (1.288 + 0.092 * (FromCharacters[from]->ultra_level_get())) * (1 + FromCharacters[from]->crit_DMG_get());
    else
        atk_result = FromCharacters[from]->atk_get() * (1.288 + 0.092 * (FromCharacters[from]->ultra_level_get()));
    for (int i = 0; i < ToCharacters.size() - 1; i++) {
        def_result = (FromCharacters[from]->character_level_get() * 10 + 200) / (ToCharacters[i]->def_get() + (FromCharacters[from]->character_level_get() * 10 + 200));
        double damage = atk_result * def_result * (1 + FromCharacters[from]->penetrate_get() - ToCharacters[i]->vulnerability_get(FromCharacters[from]->element_get()));
        DamageResult(from, i, FromCharacters, ToCharacters, damage);
        //姬子大招：每消灭一个敌方目标恢复五点能量
        if (ToCharacters[i]->hp_get() <= 0) {
            FromCharacters[from]->energy_change(5);
        }
    }
    for (int i = 0; i < ToCharacters.size() - 1; i++) {
    IfKill(from, i, FromCharacters, ToCharacters);}

    //放完大招清空
    FromCharacters[from]->energy_change(-FromCharacters[from]->energy_restore_get());
    FromCharacters[from]->energy_change(5);


    return 0;

}
//Seele 希儿
short SkillFunction_1102(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters) {
    //先移除自身同类型加速
    status_clear(FromCharacters[from], std::string("希儿自身速度增加"));
    Status SeeleSpdRaiseStatus(to, from, 1.25, std::string("希儿自身速度增加"), 3, [](CombatCharacter&, double) {}, [](CombatCharacter&, double) {});
    FromCharacters[from]->status.push_back(SeeleSpdRaiseStatus);
    Status* lastone = &FromCharacters[from]->status.back();
    lastone->apply(*FromCharacters[from], FromCharacters[from]->spd_get());
    //加速效果的添加，附带计时

    double atk_result;
    double def_result;
    //生成一个0-1的随机数
    double random_num = (double)rand() / RAND_MAX;
    if (random_num < FromCharacters[from]->crit_rate_get())
        //暴击计算
        atk_result = FromCharacters[from]->atk_get() * (0.99 + 0.11 * (FromCharacters[from]->BPSkill_level_get())) * (1 + FromCharacters[from]->crit_DMG_get());
    else
        atk_result = FromCharacters[from]->atk_get() * (0.99 + 0.11 * (FromCharacters[from]->BPSkill_level_get()));
    def_result = (FromCharacters[from]->character_level_get() * 10 + 200) / (ToCharacters[to]->def_get() + (FromCharacters[from]->character_level_get() * 10 + 200));
    double damage = atk_result * def_result * (1 + FromCharacters[from]->penetrate_get() - ToCharacters[to]->vulnerability_get(FromCharacters[from]->element_get()));
    std::cout << "行动执行：希儿" << "释放战技 归刃"<< std::endl;
    std::cout <<"触发效果：使希儿速度提高";    
    DamageResult(from, to, FromCharacters, ToCharacters, damage);
    FromCharacters[from]->energy_change(30);
    //之前写了Ifkill，如果是希儿击杀目标，则killresult>1
    short killresult = IfKill(from, to, FromCharacters, ToCharacters);
    if (killresult > 1)
    {
        //希儿击杀目标进入增幅状态，伤害增加，持续1回合
        status_clear(FromCharacters[from], std::string("希儿增幅状态"));
        Status Seele_increase_damage(to, from, 0.36 + 0.04 * FromCharacters[from]->talent_level_get(), std::string("希儿增幅状态"), 2, [](CombatCharacter& character, double value) {}, [](CombatCharacter& character, double value) {});
        FromCharacters[from]->status.push_back(Seele_increase_damage);
        return 3;
    }
    return 1;
}
short UltraFunction_1102(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters) {
    if (!IfUltraInvalid(from, to, FromCharacters, FromCharacters)) { return -2; }
    //放大招立刻增伤
    status_clear(FromCharacters[from], std::string("希儿增幅状态"));
    Status Seele_increase_damage(to, from, 0.36 + 0.04 * FromCharacters[from]->talent_level_get(), std::string("希儿增幅状态"), 1, [](CombatCharacter& character, double value) {}, [](CombatCharacter& character, double value) {});
    FromCharacters[from]->status.push_back(Seele_increase_damage);
    double atk_result;
    double def_result;
    //生成一个0-1的随机数
    double random_num = (double)rand() / RAND_MAX;
    if (random_num < FromCharacters[from]->crit_rate_get())
        atk_result = FromCharacters[from]->atk_get() * (2.38 + 0.17 * (FromCharacters[from]->ultra_level_get())) * (1 + FromCharacters[from]->crit_DMG_get());
    else
        atk_result = FromCharacters[from]->atk_get() * (2.38 + 0.17 * (FromCharacters[from]->ultra_level_get()));
    def_result = (FromCharacters[from]->character_level_get() * 10 + 200) / (ToCharacters[to]->def_get() + (FromCharacters[from]->character_level_get() * 10 + 200));
    double damage = atk_result * def_result * (1 + FromCharacters[from]->penetrate_get() - ToCharacters[to]->vulnerability_get(FromCharacters[from]->element_get()));
    std::cout << "行动执行：希儿" << "释放终结技 乱蝶"<< std::endl;
    std::cout <<"触发效果：使希儿立刻进入增幅状态";
    bool if_Seele_increase_damage = false;
    //增伤状态判定
    for (auto i : FromCharacters[from]->status) {
        if (i.name_get() == "希儿增幅状态") {
            if_Seele_increase_damage = true;
            break;
        }
    };
    if (if_Seele_increase_damage)
        //增伤状态下的输出
        DamageResult(from, to, FromCharacters, ToCharacters, damage * (1 + 0.36 + 0.04 * FromCharacters[from]->talent_level_get()));
    else
        DamageResult(from, to, FromCharacters, ToCharacters, damage);
    FromCharacters[from]->energy_change(-FromCharacters[from]->energy_restore_get());
    FromCharacters[from]->energy_change(5);

    short killresult = IfKill(from, to, FromCharacters, ToCharacters);
    if (killresult > 1) { return 2; }
    return 0;
}


