#include <iostream>
#include <ctime> // 랜덤한 숫자 사용
#include <vector>
using namespace std;

void result(vector<int> comNum, int resultNum) { // 결과 출력 함수
  cout << "당첨번호 공개!!" << endl;
  for(int c : comNum) { cout << c << " ";}
  cout << endl << " ====================================== " << endl;
  cout << "결과: " << resultNum << " 등 입니다!!" << endl;
}


int main(){
  srand(time(NULL)); // 난수생성
  int randomNum = 0;
  vector<int> comNum;
  vector<int> userNum;
  int count = 0;
  int resultNum = 7; // 7등부터 맞추면 등수 -1

  // 컴퓨터 숫자 6개 생성
  while (count != 6) // 랜덤숫자 생성, 중복안되게
  {
    int temp = 0;
    randomNum = (rand() % 25) + 1; // 1 ~ 25까지의 숫자생성
    if(comNum.size() != 0) {
      for(int j = 0; j < comNum.size(); j++){
        if(comNum[j] == randomNum) {
          temp = 1;
        }
      }
    }

    if( !temp ) {
      comNum.push_back(randomNum);
      count++;
    }
  }
  cout << "랜덤 숫자가 생성되었습니다! " << endl;

  // 사용자 숫자 생성
  count = 0;
  while (count != 6) 
  {
    int temp = 0;
    cout << count + 1 << " 번 숫자를 입력하세요: ";
    cin >> randomNum;
    if(randomNum >= 1 && randomNum <= 25) {
      for(int i = 0; i < userNum.size(); i++){
        if(userNum[i] == randomNum) {
          cout << "숫자가 중복입니다. 다시 입력해주세요." << endl;
          temp = 1;
        }
      }

      if(!temp) {
        userNum.push_back(randomNum);
        count++;
      }
    }
    else {
      cout << "범위를 벗어났습니다. 다시 입력" << endl;
    }
  }

  for(int i = 0; i < 6; i++){
    for(int j = 0; j < 6; j++){
      if(comNum[i] == userNum[j]) {
        --resultNum;
      }
    }
  }

  result(comNum, resultNum);
  

  
}