/*
  1. 공격력, 체력, 방어력을 설정
  2. 레벨업을 할 경우, 공격력과 방어력이 증가해 몬스터와 싸울때 더 강력하게 만듦, 공격력 +10
  3. 경험치를 설정, 몬스터를 사냥해 경험치 증가해 레벨업 가능하게 함, 경험치 200일 경우 레벨 +1, 몬스터 처치시 경험치 +100
  4. 체력 소모하도록 만듦, 몬스터 사냥시 체력 -20
  5. 포션 사용가능, 몬스터 잡았을시 골드획득후 골드 사용가능, 포션: 체력 +30
*/

/*
  캐릭터 직업선택
  거너 : 총, 공격력 30, 체력 100
  검사 : 검, 공격력 50, 체력 100
  마법사 : 마법, 공격력 80, 체력 70
*/

#include <iostream>
using namespace std;


// 무기 클래스
class Weapon{
  protected:
    static int offensive_power; // 공격력
    static int full_HP; // 체력

  public:
    Weapon(int offensive_power, int full_HP){
      this->offensive_power = offensive_power;
      this->full_HP = full_HP;
    }
    virtual void print() = 0; //순수가상함수
    static int getOffensive_power(){
      return offensive_power;
    }
    static int getFull_HP(){
      return full_HP;
    }
};

// 무기별 공격력 설정
// 총잡이
class Gunner : public Weapon{
  int offensive_power = 30;
  int full_HP = 100;

  public:
    Gunner() : Weapon(30, 100) {
      this-> offensive_power = offensive_power;
      this-> full_HP = full_HP;
    }

    void print(){
      cout << " ======================================== " << endl;
      cout << " Gunner 로 전직하였습니다!" << endl;
      cout << " * 무기: 수정화살 | 공격력: " << offensive_power << " | 체력: " << full_HP << endl;
      cout << " ======================================== " << endl; 
    }
};

// 무기별 공격력 설정
// 검사
class Sword : public Weapon{
  int offensive_power = 50;
  int full_HP = 100;

  public:
    Sword() : Weapon(50,100) {
      this->offensive_power = offensive_power;
      this->full_HP = full_HP;
    }

    void print(){
      cout << " ======================================== " << endl;
      cout << " Gladiator 로 전직하였습니다!" << endl;
      cout << " * 무기: 흑도:요루 | 공격력: " << offensive_power << " | 체력: " << full_HP << endl;
      cout << " ======================================== " << endl; 
    }
};

// 무기별 공격력 설정
// 법사
class Wizard : public Weapon{
  int offensive_power = 80;
  int full_HP = 70;

  public:
    Wizard() : Weapon(80, 70) {
      this -> offensive_power = offensive_power;
      this -> full_HP = full_HP;
    }

    void print(){
      cout << " ======================================== " << endl;
      cout << " Wizard 로 전직하였습니다!" << endl;
      cout << " * 무기: 마법 | 공격력: " << offensive_power << " | 체력: " << full_HP << endl;
      cout << " ======================================== " << endl; 
    }
};

// 캐릭터 설정
class Character{
  protected:
    string name;
    int level = 1;
    int monster_HP = 50;
    int exp = 0; // 경험치
    int offensive_power = 0;
    int full_HP = 0;
    int currrent_HP = 0;

  public:
    Character(string name){
      this->name = name;
      this->offensive_power = Weapon::getOffensive_power(); // static 으로 선언하여 offensive power 갖고 올 수 있음
      this->full_HP = Weapon::getFull_HP(); // static 으로 선언하여 full_hp 갖고 올 수 있음
      this->currrent_HP = Weapon::getFull_HP();
    }

    void attack(){
      cout << " 몬스터 공격!! ATTACK!! attaque!!" << endl;
      cout << " 공격력: " << offensive_power << endl;
      monster_HP -= offensive_power;
      if(monster_HP <= 0) {
        exp += 100;
        cout << "몬스터를 처치했습니다!! (exp: "<< exp << " /200 )" << endl;
        if(exp >= 200 ) {
          level_up();
          cout << "Level UP! 현재 레벨: " << level << ")" << endl;
          exp = 0;
        }
      } else {
        cout << " 몬스터 체력 (" << monster_HP << " / 50 )" << endl;
        currrent_HP -= 10;
        cout << " 몬스터에게 공격당했습니다 (" << currrent_HP << " / " << full_HP << ")" << endl;
      }
    }

    // 포션 사용
    void HP_portion(){
      if(currrent_HP == full_HP ) {
        cout << "체력이 꽉 찼습니다!" << endl;
      }
      else if(currrent_HP > full_HP - 20 ){
        currrent_HP += 20;
        cout << " HP가 회복되었습니다. ( 현재 HP: " << currrent_HP << " )" << endl;
      } 
      else {
        currrent_HP += 20;
        cout << "HP가 회복되었습니다. ( 현재 HP: " << currrent_HP << " )" << endl;
      }
    }

    void setName(string name) {
      this->name = name;
      cout << " 캐릭터의 이름이 " << this->name << " 으로 변경되었습니다." << endl;
    } 

    void level_up(){
      level++;
      cout << "LEVEL UP!! -> 공격력 +10 ( 레벨: " << level << ")" << endl;
      offensive_power += 10;
      exp = 0;
    }

    void information(){
      cout << "* Name: " << name << endl;
      cout << "* Level: " << level << endl;
      cout << "* Power: " << offensive_power << endl;
      cout << "* HP: " << currrent_HP << endl;
      cout << "* Exp: " << exp << endl;
    }
};

// 게임 첫 캐릭터 초기화
int Weapon::offensive_power = 0;
int Weapon::full_HP = 0;

void createJob(int job, string name) {
  switch (job)
  {
  case 1: {
    Weapon *w1 = new Gunner(); // 업캐스팅, Weapon의 포인터로 Gunner의 인스턴스를 가리킴
    w1 -> print();
    delete w1;
    break;
  }
  case 2: {
    Weapon *w2 = new Sword();
    w2 -> print();
    delete w2;
    break;
  }
  case 3: {
    Weapon *w3 = new Wizard();
    w3 -> print();
    delete w3;
    break;
  }
  }
}

int main(){
  string name;
  int job;
  
  while(true) {
    cout << " ================================================== " << endl;
    cout << " Please, Enter Your Name: ";
    cin >> name;
    cout << endl;
    cout << "1. Gunner ( 공격력: 30 | 체력: 100) " << endl;
    cout << "2. Gladiator ( 공격력: 50 | 체력: 100) " << endl;
    cout << "3. Wizard ( 공격력: 80 | 체력: 70) " << endl;
    cout << " 0 : EXIT" << endl;
    cout << "Choice you JOB " << endl;

    while(true){
      cin >> job;
      if(job > 0 && job < 4) {
        createJob(job, name);
        break;
      }
      cout << " 1 - 3 중에 선택하여 주세요.";
    }

    cout << " ************************************************************ " << endl;
    cout << endl;
    cout << " Select Your Next Step!! " << endl;
    cout << " 1. Rename " << endl;
    cout << " 2. Attacking a Monster " << endl;
    cout << " 3. Level Up " << endl;
    cout << " 4. HP Recover " << endl;
    cout << " 5. Information " << endl;

    Character c(name);

    while(true) {
      int behaviour; 
      cout << " Choice a Number what You want to do. ( 0 : EXIT )" << endl;
      cin >> behaviour;
      switch (behaviour)
      {
      case 0: {
        cout << " Game Over.." << endl;
        return 0;
      }
      case 1: {
        cout << " Enter you New Name " << endl;
        cin >> name;
        c.setName(name);
        break;
      }
      case 2: {
        c.attack();
        break;
      }
      case 3: {
        c.level_up();
        break;
      }
      case 4: {
        c.HP_portion();
        break;
      }
      case 5: {
        c.information();
        break;
      }
      default: {
        cout << " Select NO. 0 ~ 4 ";
        break;
      }
        
      }
    }
  }
}

