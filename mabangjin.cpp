#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main(){
  int size;
  cout << "Welcome to MabangZine!!" << endl;
  cout << "숫자를 입력해 주세요! " << endl;
  cin >> size;
  vector <vector<int> > mabang(size, vector<int>(size));
  int row = 0;
  int col = size / 2;
  mabang[row][col] = 1; // 맨 중앙에 1을 오기위해 1로 초기화 및 할당
  for(int num = 2; num <= size * size; num++){
    int new_row = row - 1;
    int new_col = col + 1; // 오른쪽 대각선 위로 보내야 하니 행은 -1 , 열은 +1
    if(new_row < 0 ) { // 오른쪽 대각선 위에 행이 없으면 밑에 행으로 보냄
      new_row = size - 1; 
    }
    if(new_col > size - 1){ // 오른쪽 대각선 위에 열이 없으면 다른 열로 보냄
      new_col = 0;
    }
    if(mabang[new_row][new_col] != 0) {
      row++;
      if(row > size - 1){
        row = 0;
      }
    } else {
      row = new_row;
      col = new_col;
    }
    mabang[row][col] = num;
  }
  for(vector<int> row : mabang){
    for(int element : row) {
      cout << setw(6) << element; // 입출력 조정자로 setw(숫자)는 숫자의 갯수만큼 출력시 칸수를 나타냄
    }
    cout << endl;
  }
}