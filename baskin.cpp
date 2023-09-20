
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
  // 숫자 입력과 카운트숫자 초기화 및 선언
  int num = 0;
  int count = 1;

  // 사용자와 컴퓨터가 입력할때마다 체크
  bool turn = false;

  // 31을 말하면 지는 게임, 31까지 반복
  while (count < 32)
  {
    if (turn == true)
    {
      srand(time(NULL));        // 순서로 무작위 숫자 물러오기
      int com = rand() % 3 + 1; // 1 ~ 3까지 숫자 갯수 설정
      cout << "컴퓨터가 부른 숫자!!" << endl;
      num = com;
      turn = false;
    }
    // 사용자가 말하는 숫자
    else
    {
      cout << "갯수를 입력하세요!" << endl;
      cin >> num;
      if (num < 1 || num > 3)
      { // 1 ~ 3개의 숫자를 입력
        cout << "1 ~ 3 사이의 숫자로 다시 입력해주세요" << endl;
        num = 0;
      }
      else
      {
        cout << "사용자가 부른 숫자!" << endl;
        turn = true;
      }
    }
    for (int i = 0; i < num; i++)
    { // 입력한 숫자까지 +1 씩하여 숫자입력
      cout << count + i << endl;
    }
    count += num;
    cout << endl;
  }
  turn == true ? cout << "게임종료! 컴퓨터의 승리입니다! \n" : cout << "게임종료! 사용자의 승리입니다!\n";
}

