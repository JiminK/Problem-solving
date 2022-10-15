#include <iostream>
#include <vector>
#include <stack>
#define MAXN 10000
using namespace std;

typedef long long int lli;

// GCD
lli gcd(lli a, lli b){
  return b ? gcd(b, a % b) : a;
}
// LCM
lli lcm(lli a, lli b){
  return a * b / gcd(a, b);
}

// 에라토스테네스의 체
vector<int> primes;
bool isPrime[MAXN + 1]; // 소수 담는 배열 (필수x)
bool visit[MAXN + 1];   // 방문 여부 체크 (필수o!!), 소수 판별할 때 사용 
void solve(){
  for(int v = 2; v <= MAXN; ++v){
    if(visit[v]) continue;  // 방문 했다 -> 소수 아님.
    isPrime[v] = true;
    primes.push_back(v);
    for(int j = v * 2; j <= MAXN; j += v){  // 배수 다 지우기(=배수 전부 방문 체크)
      visit[j] = true;
    }
  }
}

// 소수판별
bool isPrime2(int a){
  for(int j = 2; j * j <= a; ++j){
    if(a % j == 0)
      return false;
  }
  return true;
}

// 소인수 분해
void factorization(int x){
  vector<int> fact;
  for(int j = 2; j * j <= x && x > 1; ++j){
    while(x % j == 0){
      fact.push_back(j);
      x /= j;
    }
  }
  for(int j = 0; j < fact.size(); ++j)
    cout << fact[j] << ", ";
}

// digit진수인 문자열 num을 int로 변환
int stringToInt(string num, int digit){
  int ret = 0;
  for(int j = 0; j < num.size(); ++j){
    int n = num[j] - '0';
    if(num[j] >= 'a' && num[j] <= 'z')
      n = num[j] - 'a' + 10;
    ret = ret * digit + n;
  }
  return ret;
}
// int num을 digit진수인 문자열로 변환
string intToString(int num, int digit){
  string str = "";
  stack<int> stk;
  while(num){
    stk.push(num % digit);
    num /= digit;
  }
  while(!stk.empty()){
    char c = stk.top() + '0';
    if(stk.top() > 9)
      c = stk.top() - 10 + 'a';
    str += c;
    stk.pop();
  }
  return str;
}

// 파스칼의 삼각형을 이용한 조합 계산 (전처리)
int C[101][101], M = 100000;
void solveComb(){
  C[0][0] = 1;
  C[1][0] = 1;
  C[1][1] = 1;

  for(int j = 1; j <= 100; ++j){
    C[j][0] = 1;
    for(int i = 1; i <= j; ++i)
      C[j][i] = (C[j - 1][i - 1] % M + C[j - 1][i] % M) % M;
  }
}

int main(){
  solve();
  solveComb();
  cout << stringToInt("a", 16) << endl << intToString(10, 16) << endl;
  for(int j = 0; j <= 100; ++j){
    for(int i = 0; i <= j; ++i){
      cout << C[j][i] << " ";
    }
    cout << endl;
  }
  factorization(100);
}