//
//  Skill.hpp
//  Search_text
//
//  Created by 袁瑞翔 on 2024/1/4.
//

#ifndef Skill_hpp
#define Skill_hpp
#include <iostream>
#include <vector>
#include <stdio.h>
#include <unordered_map>
#include <functional>
#include <string>

class CombatCharacter;

short checkNormalFunction_1(bool from, bool to);
short checkNormalFunction_2(bool from, bool to);

short checkSkillFunction_1006(bool from, bool to);
short checkSkillFunction_1004(bool from, bool to);
short checkSkillFunction_1208(bool from, bool to);
short checkSkillFunction_1003(bool from, bool to);
short checkSkillFunction_1102(bool from, bool to);
short checkSkillFunction_1107(bool from, bool to);
short checkSkillFunction_1001(bool from, bool to);
short checkSkillFunction_1211(bool from, bool to);

short checkUltraFunction_1006(bool from, bool to);
short checkUltraFunction_1004(bool from, bool to);
short checkUltraFunction_1208(bool from, bool to);
short checkUltraFunction_1003(bool from, bool to);
short checkUltraFunction_1102(bool from, bool to);
short checkUltraFunction_1107(bool from, bool to);
short checkUltraFunction_1001(bool from, bool to);
short checkUltraFunction_1211(bool from, bool to);



short NormalFunction_1(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters);
short NormalFunction_2(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters);

short SkillFunction_1006(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters);
short SkillFunction_1004(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters);
short SkillFunction_1208(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters);
short SkillFunction_1003(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters);
short SkillFunction_1102(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters);
short SkillFunction_1107(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters);
short SkillFunction_1001(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters);
short SkillFunction_1211(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters);

short UltraFunction_1006(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters);
short UltraFunction_1004(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters);
short UltraFunction_1208(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters);
short UltraFunction_1003(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters);
short UltraFunction_1102(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters);
short UltraFunction_1107(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters);
short UltraFunction_1001(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters);
short UltraFunction_1211(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters);

void status_clear(CombatCharacter* status_in_character, std::string statu_name);
bool IfUltraInvalid(int from, int to, std::vector<CombatCharacter*> FromChas, std::vector<CombatCharacter*> ToChas);
void DamageResult(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters, double damage);
void DamageResult_with_March7_talent(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters, double damage);
void DamageResult_with_Clara_talent(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters, double damage);
void DamageResult_with_Bailu_talent(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters, double damage);
void DamageResult_with_Fuxuan_talent(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters, double damage);
double Exact_def(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters);
short IfKill(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters);
void SkillFunction_1001_addShield(CombatCharacter& character, double value);
void SkillFunction_1001_removeShield(CombatCharacter& character, double value);
bool Frozen_status(int form, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters);
double Exact_def(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters);
void SkillFunction_1004_addSlow(CombatCharacter& character, double value);
void SkillFunction_1004_removeSlow(CombatCharacter& character, double value);
void UltraFunction_1004_Trap(CombatCharacter& character, double value);
void UltraFunction_1004_removeTrap(CombatCharacter& character, double value);
double TalentFunction_1004(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters);
void SkillFunction_1006_1_addVulnerabilityDecrease(CombatCharacter& character, double value);
void SkillFunction_1006_1_removeVulnerabilityDecrease(CombatCharacter& character, double value);
void SkillFunction_1006_2_addWeak(CombatCharacter& character, double value);
void SkillFunction_1006_2_removeWeak(CombatCharacter& character, double value);
void UltraFunction_1006_Defensedrop(CombatCharacter& character, double value);
void UltraFunction_1006_removeDefensedrop(CombatCharacter& character, double value);
void TalentFunction_1006(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters);
void Attack_reduction(CombatCharacter& character, double value);
void Defense_reduction(CombatCharacter& character, double value);
void Speed_reduction(CombatCharacter& character, double value);
void Attack_recover(CombatCharacter& character, double value);
void Defense_recover(CombatCharacter& character, double value);
void Speed_recover(CombatCharacter& character, double value);
void KaiQiQiongguanDeFuXuan(std::vector<CombatCharacter*>& FromCharacters);
void SkillFunction_1208_addActiveQiongguan(CombatCharacter& character, double value);
void SkillFunction_1208_removeQiongguan(CombatCharacter& character, double value);
void UltraFunction_1211_applyShengxi(CombatCharacter& character, double value);
void UltraFunction_1211_removeShengxi(CombatCharacter& character, double value);
double Const_Heal(int from, std::vector<CombatCharacter*>& FromCharacters);
double Fire_def(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters);
void SkillFunction_1102_spd_raise(CombatCharacter& character, double);
void SkillFunction_1102_remove_spd_raise(CombatCharacter& character, double);
short SkillFunction_1102(int from, int to, std::vector<CombatCharacter*>& FromCharacters, std::vector<CombatCharacter*>& ToCharacters);
#endif /* Skill_hpp */
