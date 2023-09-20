#include <iostream>
using namespace std;

class Calculator{
  protected:
    static double resultNum;
    double x = 0;
    double y = 0;
  public:
    virtual void calculation() = 0; // 순수 가상함수
    static double getResult(){
      return resultNum;
    }
};

class Plus : public Calculator{
  public:
    Plus(double x, double y) : Calculator() {
      this -> x = x;
      this -> y = y;
    }

    void calculation(){
      resultNum = x + y;
      cout << " =============================================== " << endl ;
      cout << "* 결과: " << this -> resultNum << endl;
      cout << " =============================================== " << endl ;
    }
};

class Minus : public Calculator {
  public:
    Minus(double x, double y) : Calculator(){
      this -> x = x;
      this -> y = y;
    }

    void calculation(){
      resultNum = x - y;
      cout << " =============================================== " << endl ;
      cout << "* 결과: " << this -> resultNum << endl;
      cout << " =============================================== " << endl ;
    }
};

class Multiply : public Calculator{
  public:
    Multiply(double x, double y) : Calculator(){
      this -> x = x;
      this -> y = y;
    }

    void calculation(){
      resultNum = x * y;
      cout << " =============================================== " << endl ;
      cout << "* 결과: " << this -> resultNum << endl;
      cout << " =============================================== " << endl ;
    }
};

class Divide : public Calculator{
  public:
    Divide(double x, double y) : Calculator(){
      this -> x = x;
      this -> y = y;
    }

    void calculation(){
      resultNum = x / y;
      cout << " =============================================== " << endl ;
      cout << "* 결과: " << this -> resultNum << endl;
      cout << " =============================================== " << endl ;
    }
};

double Calculator :: resultNum = 0;

void function(double x, char oper, double y){
  Calculator *cal;
  switch (oper)
  {
  case '+' : {
    cal = new Plus(x,y);
    break;
  }
  case '-': {
    cal = new Minus(x,y);
    break;
  }
  case '*': {
    cal = new Multiply(x,y);
    break;
  }
  case '/': {
    cal = new Divide(x,y);
    break;
  }
  default: {
    cout << " 식을 정확히 입력해주세요. " << endl;
    break;
  }
  }
  cal -> calculation();
  delete cal;
}

int main(){
  double x = 0;
  double y = 0;

  cout << " 숫자를 입력하세요 " << endl;
  cin >> x;
  
  while(true) {
    char oper;
    cout << "연산자를 입력하세요: " << endl;
    cin >> oper;
    cout << "숫자를 입력하세요: " << endl;
    cin >> y;
    function(x,oper,y);

    string cont;
    cout << " 연산을 계속 진행하시겠습니까?" << endl;
    cin >> cont;
    while(true){
      if(cont == "Y") {
        x = Calculator::getResult();
        break;
      }
      else if(cont == "AC") {
        x = 0;
        break;
      } else if(cont == "EXIT") {
        cout << "Thank You~ ^.~";
        return -1;
      }
    }
  }
  return 0;
}