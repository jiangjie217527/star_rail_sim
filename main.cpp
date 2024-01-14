#include "character_info.hpp"
#include "stream.hpp"
#include <typeinfo>

void readAndCheck(int& m, int& n){
    // 检测输入信息的合法性（各种非法输入，或者输入少于或大于6个值）
    int val = -1, cnt = 0;
    bool endlineflag = false;
    for (int i = 0; i < 1; ++i) {
        m = 0;
        n = 0;
        cnt = 0;
        endlineflag = 0;
        while (!endlineflag) {
            cnt++;
            std::cin >> val;
            if (std::cin.rdstate() != 0) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.sync();
                cnt = 0;
                break;
            }
            char c = std::cin.get();
            if (c == '\n') {
                endlineflag = true;
            } else if (c != ' ' && (c < '0' || c > '9')) {
                cnt = 0;
                break;
            }
            switch (cnt) {
                case 1:
                    m = val;
                    break;
                case 2:
                    n = val;
                    break;
            }
        }
        if (cnt != 2 || m <= 0 || m >= 9 || n <= 0 || n >= 9) {
            std::cerr << "角色数量输入有误，请重新输入: " << std::endl;
            std::cin.sync();
            i--;
        }
    }
}

int main() {
    /* 目前这一部分没什么大问题，就是需要加一个对输入非法数据的检验 */
    // 我方角色数量m，对方角色数量n
    int m = 0, n = 0;
    std::cout << "请输入m，n的值: ";
    // 输入敌我方角色数量
    readAndCheck(m, n);
    std::vector<FriendCharacter> friends = friends_init(m);
    std::vector<EnemyCharacter> enemies = enemies_init(n);
    initTime(friends, enemies);
    std::vector<std::pair<CombatCharacter*, bool>> waitingQueue = init_waitingQueue(friends, enemies);
    std::vector<CombatCharacter*> deathArray = init_death_positionArray();
    std::vector<FriendCharacter*> friend_positionArray = init_friend_positionArray(friends);
    std::vector<EnemyCharacter*> enemy_positionArray = init_enemy_positionArray(enemies);
    std::cout << "初始化成功啦！" << std::endl;
    bool flag = 0;
    while (mainGame(m, n, friends, enemies, friend_positionArray, enemy_positionArray, waitingQueue, deathArray, &flag) == 0);
}

