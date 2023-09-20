#include <iostream>
using namespace std;

int main()
{
  cout << "Play Ball~!!" << endl;

  // 1 ~ 9 까지의 수를 할당
  int iNum[9] = {};
  for (int i = 0; i < 9; i++)
  {
    iNum[i] += 1;
  }

  //랜덤으로 숫자 뽑기
  int temp, num1, num2;
  srand(time(NULL));
  for (int i = 0; i < 100; i++)
  {                        // 100번 한 이유는 별다른 이유없이 숫자를 많이 섞기 위한것
    int num1 = rand() % 9; // 1 ~ 9 까지의 숫자
    int num2 = rand() % 9;
    // 숫자 섞기
    temp = iNum[num1];
    iNum[num1] = iNum[num2];
    iNum[num2] = temp;
  }

  // strike 와 ball 횟수 변수 선언
  int strike = 0;
  int ball = 0;
  int input[3] = {}; // 사용자가 입력하는 숫자
  int count = 0;     // 정답맞출때 까지의 count

  while (true)
  {
    cout << "1 ~ 9 까지의 숫자를 입력하세요. (그 외의 숫자 종!료!)" << endl;
    cin >> input[0] >> input[1] >> input[2];

    // 1 ~9 외의 숫자 입력시 종료
    if (input[0] < 1 || input[0] > 9 || input[1] < 1 || input[1] > 9 || input[2] < 1 || input[2] > 9)
      break;

    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      { // 사용자가 입력한 숫자가 컴퓨터의 숫자의 모두 포함되는지 확인
        //com의 숫자와 사용자의 숫자가 같은지 확인
        if (iNum[i] == input[j])
        {
          if (i == j)
          { // 자릿수 까지 똑같은지 확인
            strike++;
          }
          else
          { // 자릿수는 다르지만 값은 같음
            ball++;
          }
        }
      }
    }
    count++; // 횟수 증가

    if (strike == 3)
    {
      cout << count << " 번 만에 맞췄습니다!" << endl;
      break;
    }
    else
    {
      cout << "Strike: " << strike << " Ball: " << ball << endl;
      // 다시 초기화
      strike = 0;
      ball = 0;
    }
  }
}