//
//  stream.hpp
//  Search_text
//
//  Created by 袁瑞翔 on 2024/1/5.
//

#ifndef stream_hpp
#define stream_hpp
#include "character_info.hpp"
#include "skill.hpp"

std::vector<FriendCharacter> friends_init(int m);
std::vector<EnemyCharacter> enemies_init(int n);
bool isFriendInDictionary(int id, std::vector<FriendCharacter> vector);
bool isEnemyInDictionary(int id, std::vector<EnemyCharacter> vector);
bool isValidCharacterValue(int value);
bool isValidBasicValue(int value);
bool isValidLevel(int value);
bool isValidRank(int value);
void initTime(std::vector<FriendCharacter>& friends, std::vector<EnemyCharacter>& enemies);
std::vector<std::pair<CombatCharacter*, bool>> init_waitingQueue(std::vector<FriendCharacter>& friends, std::vector<EnemyCharacter>& enemies);
std::vector<CombatCharacter*> init_death_positionArray();
std::vector<std::pair<CombatCharacter*, bool>> new_waitingQueue(std::vector<std::pair<CombatCharacter*, bool>>& waitingQueue);
bool getRoundAttribute(const std::vector<std::pair<CombatCharacter*, bool>>& waitingQueue, CombatCharacter* characterPtr);
void insertExtraRound(std::vector<std::pair<CombatCharacter*, bool>>& waitingQueue, CombatCharacter* characterPtr);
void removeExtraRound(std::vector<std::pair<CombatCharacter*, bool>>& waitingQueue);
std::vector<FriendCharacter*> init_friend_positionArray(std::vector<FriendCharacter>& friends);
std::vector<EnemyCharacter*> init_enemy_positionArray(std::vector<EnemyCharacter>& enemies);
double calculateSpeed (CombatCharacter* character);
void changeTime(CombatCharacter* characterPtr);
void passTime(std::vector<CombatCharacter*> waitingQueue);
void check_skill(int from, int turn, int m, int n, std::vector<FriendCharacter*> friend_positionArray, std::vector<EnemyCharacter*> enemy_positionArray, std::vector<std::pair<CombatCharacter*, bool>>& waitingQueue, bool* flag);
double roundAndAdjust(double value);
void check_attribute(CombatCharacter* characterPtr, std::string keywords, int skillpoint);
void check_combatInfo(std::vector<FriendCharacter*>& friend_positionArray, std::vector<EnemyCharacter*>& enemy_positionArray, std::vector<CombatCharacter*>& deathArray);
void check_status(CombatCharacter* characterPtr);
bool check_frozen(CombatCharacter* characterPtr);
void Query(std::string input, int turn, int m, int n, std::vector<FriendCharacter*> friend_positionArray, std::vector<EnemyCharacter*> enemy_positionArray, std::vector<std::pair<CombatCharacter*, bool>>& waitingQueue, bool* flag);
bool Skip(std::vector<std::pair<CombatCharacter*, bool>>& waitingQueue, bool flag);
bool Execute(std::string input, int m, int n, bool team, int turn, std::vector<FriendCharacter*>& friend_positionArray, std::vector<EnemyCharacter*>& enemy_positionArray, std::vector<std::pair<CombatCharacter*, bool>>& waitingQueue, bool* flag);
bool isGameFinish(std::vector<FriendCharacter*> friend_positionArray, std::vector<EnemyCharacter*> enemy_positionArray);
bool mainGame(int m, int n, std::vector<FriendCharacter> friends, std::vector<EnemyCharacter> enemies, std::vector<FriendCharacter*>& friend_positionArray, std::vector<EnemyCharacter*>& enemy_positionArray, std::vector<std::pair<CombatCharacter*, bool>>& waitingQueue, std::vector<CombatCharacter*>& deathArray, bool* flag);

#endif /* stream_hpp */
