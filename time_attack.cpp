#include <iostream>
#include <ctime>
#include <string>
#include <Windows.h>
using namespace std;

/*
int input_second = 0;
double current_second = 0;

cout << "수를 입력하세요" << endl;
cin >> input_second;

for (current_second; current_second < input_second; current_second += 1) {
cout << input_second - current_second << " 초 남음\n";
Sleep(1000);
}

cout << "ㄲㅡㅌ";
*/
int main()
{
  clock_t startTime = clock(); // 타임어택 코드
  string input = "";
  //string output = "airplane";
  string output = "";
  int n = 0; // output 된 문자열 사이즈
  int timer = 0;
  int count = 0;       // 입력한 단어개수
  int count_check = 0; // 단어개수 체크
  const int inputTime = 30;
  double current_second = 0; // 현재시각

  // 23.09.15 15:44 테스트
  cout << "첫 단어를 입력해주세요." << endl;
  cin >> output;
  cout << "첫 단어는.." << output << " 입니다." << endl;

  while (true)
  {
    n = output.size();
    cout << output << endl;

    cout << "다음 단어를 입력하세요: " << endl;
    cin >> input;

    if (input[0] = output[n - 1])
    { // 입력한 첫글자와 전글자에 마지막글자가 같을때
      output += "-> " + input;
      count++;
    }
    else
    {
      cout << "잘못된 입력입니다." << endl;
    }

    clock_t endTime = clock();
    timer = (endTime - startTime) / CLOCKS_PER_SEC; // second로 변환하는 함수
    cout << "경과한 시간: " << timer << endl
         << endl;

    if (timer > 30)
    {
      if (count != count_check)
      { // 시간이 지나고 입력한 단어의 갯수 미포함
        count--;
      }
      cout << "Time Over..! Please, Try Again!" << endl;
      cout << "총 입력한 단어개수: " << count;
      break;
    }
    count_check = count;
  }
}