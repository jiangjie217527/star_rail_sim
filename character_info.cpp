#include "character_info.hpp"

std::unordered_map<int, std::array<double, 9>> attribute_dictionary::myDictionary = {
    {1006, {124.56,7.128,87.12,4.356,62.7,3.135,107,110,3}},  // 银狼
    {1004, {153.12,7.656,84.48,4.224,64.3,3.465,102,120,6}},  // 瓦尔特
    {1208, {200.64,10.032,63.36,3.168,82.5,4.125,100,135,3}},   // 符玄
    {1003, {142.56,7.128,102.96,5.148,54.4,2.97,96,120,0}},   // 姬子
    {1102, {126.72,6.336,87.12,4.356,49.5,2.475,115,120,3}},     // 希儿
    {1107, {168.96,8.448,100.32,5.016,66,3.3,90,110,4}},      // 克拉拉
    {1001, {144.0,7.2,69.6,3.48,78,3.9,101,120,1}},            // 三月七
    {1211, {179.52,8.976,76.56,3.828,66,3.3,98,100,5}}        // 白露
};
std::unordered_map<int, std::string> attribute_dictionary::myName = {
    {1006, "银狼"},
    {1004, "瓦尔特"},
    {1208, "符玄"},
    {1003, "姬子"},
    {1102, "希儿"},
    {1107, "克拉拉"},
    {1001, "三月七"},
    {1211, "白露"}
};

std::optional<std::string>attribute_dictionary::getName(int id) {
    auto it = myName.find(id);
    if (it != myName.end()) {
        return it->second;
    }else{
        return "";     // 返回一个空的可选对象
    }
}

std::optional<std::array<double, 9>> attribute_dictionary::getEntry(int id) {
    auto it = myDictionary.find(id);
    if (it != myDictionary.end()) {
        return it->second;
    } else {
        return {};     // 返回一个空的可选对象
    }
}

/*下面是OriginCharacter里面的函数*/
OriginCharacter::OriginCharacter(const std::vector<int>& level, std::optional<std::array<double, 9>> base_value,std::optional<std::string> CharacterName): crit_rate(0.05), crit_DMG(0.5), vulnerability({ 0,0,0,0,0,0,0 }){
    if (base_value.has_value())
    {
        hp = base_value.value()[0] + base_value.value()[1] * level[0];
        atk = base_value.value()[2] + base_value.value()[3] * level[0];
        def = base_value.value()[4] + base_value.value()[5] * level[0];
        spd = base_value.value()[6];
        element = int(base_value.value()[8]);
        energy_max = base_value.value()[7];
        hp_max = hp;
        energy_restore = 0.5 * energy_max;
        shield = 0;
        penetrate = 0;
        name=CharacterName.value();
    }
}

OriginCharacter::~OriginCharacter(){
    
}

// 调用函数
std::string OriginCharacter::name_get() const { 
    return name; 
}
double OriginCharacter::time_get() const {
    return time;
}
int OriginCharacter::id_get() const {
    return entity_id;
}
double OriginCharacter::spd_get() const { 
    return spd; 
}
double OriginCharacter::hp_get() const { 
    return hp; 
}
double OriginCharacter::hp_max_get() const { 
    return hp_max; 
}
double OriginCharacter::shield_get() const { 
    return shield; 
}
double OriginCharacter::atk_get() const { 
    return atk; 
}
double OriginCharacter::def_get() const { 
    return def; 
}
double OriginCharacter::energy_restore_get() const { 
    return energy_restore; 
}
double OriginCharacter::energy_max_get() const { 
    return energy_max; 
}
double OriginCharacter::effect_hit_rate_get() const {
    return effect_hit_rate;
}
double OriginCharacter::effect_resist_get() const { 
    return effect_resist; 
}
double OriginCharacter::crit_rate_get() const { 
    return crit_rate; 
}
double OriginCharacter::crit_DMG_get() const { 
    return crit_DMG; 
}
double OriginCharacter::vulnerability_get(int i) const { 
    return vulnerability[i]; 
}
double OriginCharacter::penetrate_get() const { 
    return penetrate; 
}
int OriginCharacter::element_get() const { 
    return element; 
}

// change 函数的实现
double OriginCharacter::calculateRemainingTime() const{
    double distance = 10000.0;
    return distance / spd;
}
void OriginCharacter::new_time(int time){
    this->time = time;
}
void OriginCharacter::hp_change(double value) {
    hp += value;
    if (hp > hp_max)
        hp = hp_max;
}
void OriginCharacter::hp_change_max(double value) { 
    hp_max += value; 
}
void OriginCharacter::energy_change(double value){   
    energy_restore += value;
    if (energy_restore > energy_max) energy_restore = energy_max;
}
void OriginCharacter::atk_change(double value) { 
    atk += value; 
}
void OriginCharacter::def_change(double value) { 
    def += value; 
}
void OriginCharacter::spd_add(double value) { 
    spd += value; 
}
void OriginCharacter::crit_rate_change(double value) { 
    crit_rate += value; 
}
void OriginCharacter::crit_DMG_change(double value) { 
    crit_DMG += value; 
}
void OriginCharacter::shield_change(double value) { 
    shield += value; 
}
void OriginCharacter::spd_change(double value) { 
    spd *= value; 
}
void OriginCharacter::shield_remove() {
    shield = 0;
}
void OriginCharacter::vulnerability_decrease(double value, int i) {
    vulnerability[i] -= value;
}
void OriginCharacter::penetrate_change(double value) {
    penetrate += value;
}
void OriginCharacter::hp_decrease(double damage){
    if (shield > damage) {shield -= damage;}
    else {
        damage -= shield;
        shield = 0;
        hp -= damage;
    }
}




/*下面是CombatCharacter里面的函数*/
CombatCharacter::CombatCharacter(int id, int character_level, int basic_level, int BPSkill_level, int ultra_level, int talent_level, int rank)
    : OriginCharacter({character_level, basic_level, BPSkill_level, ultra_level, talent_level, rank}, attribute_dictionary::getEntry(id),
    attribute_dictionary::getName(id)){
        entity_id = id;
        death = false;
        talent_active = false;
        Shengxi = 0;
        code = calculator++;
        this->character_level = character_level;
        this->basic_level = basic_level;
        this->BPSkill_level = BPSkill_level;
        this->ultra_level = ultra_level;
        this->talent_level = talent_level;
        this->rank = rank;
        status = std::vector<Status>();
        if(id==1208) talent_point = 1;
        else talent_point = 0;
}
CombatCharacter::~CombatCharacter(){
    
}
std::string CombatCharacter::NormalFun_name_get() const {
    return NormalFuncName;
}
int CombatCharacter::code_get() const{
    return code;
}
bool CombatCharacter::death_get() const{
    return death;
}
int CombatCharacter::basic_level_get() const { 
    return basic_level; 
}
int CombatCharacter::character_level_get() const { 
    return character_level; 
}
int CombatCharacter::entity_id_get() const { 
    return entity_id; 
}
int CombatCharacter::BPSkill_level_get() const { 
    return BPSkill_level; 
}
int CombatCharacter::ultra_level_get() const { 
    return ultra_level;
}
int CombatCharacter::talent_level_get() const{ 
    return talent_level; 
}
int CombatCharacter::rank_get() const { 
    return rank; 
}
int CombatCharacter::Shengxi_get() const { 
    return Shengxi; 
}
bool CombatCharacter::talent_active_get() const { 
    return talent_active; 
}
bool CombatCharacter::team_get() const{
    return team;
}
int CombatCharacter::talent_point_get() const {
    return talent_point; 
}
void CombatCharacter::updateStatus() {    // 在一回合结束后，skip执行


    for (auto it = status.begin(); it != status.end();) {
        it->duration_decrease();
        // 如果状态剩余回合数为0，删除状态
        if (it->duration_get() <= 0) {
            it->remove(*this, it->value_get());
            std::cout << name << "失去了状态：" << it->name_get() << "\n";
            it = status.erase(it);
        }
        else {
            ++it;
        }
    }
}
void CombatCharacter::death_change(){
    death = true;
};
void CombatCharacter::active_talent() {
    talent_active = true;
}
void CombatCharacter::passive_talent() {
    talent_active = false;
}
void CombatCharacter::talent_point_add(int a) {
    talent_point += a;
}
void CombatCharacter::Shengxi_add(int a) {
    Shengxi += a;
}

int CombatCharacter::calculator = 0;

FriendCharacter::FriendCharacter(int id, int character_level, int basic_level, int BPSkill_level, int ultra_level, int talent_level, int rank)
    : CombatCharacter(id, character_level, basic_level, BPSkill_level, ultra_level, talent_level, rank) {
    team = 0;
}

EnemyCharacter::EnemyCharacter(int id, int character_level, int basic_level, int BPSkill_level, int ultra_level, int talent_level, int rank)
    : CombatCharacter(id, character_level, basic_level, BPSkill_level, ultra_level, talent_level, rank) {
    team = 1;
}

int FriendCharacter::skillpoint = 3;
int EnemyCharacter::skillpoint = 3;
