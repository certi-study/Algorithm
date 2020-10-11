# Algorithm
Prepare for level of expert in Samsung

---

# Member  

|                 Avartar                  |                   Name                   | Role  |
| :--------------------------------------: | :--------------------------------------: | :---: |
| <img src="https://avatars1.githubusercontent.com/u/7951335?v=4&s=100"> | <a href = "https://github.com/jaejunha"> **Jae Jun Ha** </a> | Maker |
| <img src="https://avatars1.githubusercontent.com/u/31812857?v=4&s=100"> | <a href = "https://github.com/Minseok-Hong"> **Min Seok Hong** </a> | Maker |

 **chart from : http://ghchart.rshah.org**  

# Method  

## 0. C vs CPP  
**기본적인 속도는 C**가 빠름  
하지만 함수를 어느 정도 사용할 경우, **INLINE화 할 수 있는 CPP**가 빠름  

## 1. REGISTER 변수 사용    
그냥 안쓰면 손해...  
단, 사용할 수 있는 **register 변수 횟수가 제한**되어 있음  
**연산이 많이 사용되는 변수**에 사용!  
```
register unsigned int varible = 1;
```
## 2. INLINE 함수 사용  
일반적으로 함수를 호출 할 때 특정 주소로 이동하고 되돌아오는 과정이 존재한다  
하지만 inline 키워드를 사용할 경우 위의 과정이 없어 **시간이 단축** 된다  
단점으로는 **메모리 크기가 커질 수** 있음!  
복잡한 함수에는 사용하지 말자!  
```
inline void test(){ blar }
```
참고: `https://blog.plorence.kr/483`  
## 3. 전위 연산자 사용  
전위 연산자와 후위 연산자의 성능 차이는 미비하지만 **전자가 조금 빠르다고 한다**   
후위 연산자는 **복사 과정**을 거치기 때문에 약간 느릴 수 있다  
참고: `http://egloos.zum.com/indra207/v/4848273`
## 4. LOOP UNROLLING(반복문에 하드코딩)      
어셈블할 때 **조건문의 갯수가 작아져** 속도가 빨라진다  
또한 파이프라인 효과와 캐시 히트 효과가 있다고 한다  
```
for (register unsigned int i = 0; i < 100; ++i) {
  a[i] = i;
}
```
를 아래와 같이 바꾸는 것을 의미한다
```
for (register unsigned int i = 0; i < 100; i += 5) {
  a[i] = i;
  a[i + 1] = i + 1;
  a[i + 2] = i + 2;
  a[i + 3] = i + 3;
  a[i + 4] = i + 4;
}
```  
참고: `http://pkban.blogspot.com/2017/08/loop-unrolling-optimization.html`  
## 5. INT형 사용하기   
컴퓨터는 기본적으로 **int형에 최적화** 되있다  
그래서 char형, bool형, double형을 쓰는 것보다 성능이 좋다   
## 6. 구조체 포인터 매개변수  
함수의 매개변수(int형 기준)가 **4개가 넘어가게 되면** 레지스터에서 **스택을 이용**하게 된다   
이 때 **구조체 포인터를 매개변수로** 사용하자  
```
int a(int x, int y, int z, int w, int u);
```
를
```
int a(struct name &x);
```
로 바꿔 사용하자  
참고: `http://ilovebird.egloos.com/v/10454689`   
## 7. FOR문을 거꾸로  
i < n 의 수식의 경우 컴퓨터는 i - n < 0 으로 변환하여 비교한다  
이를 최소화하기 위해 아래와 같은 for 문을 사용하자 
```
for (register int i = N; i--;){
  do something...
}
```
## 8. 배열의 초기화   
주기적으로 배열을 초기화해야할 때가 있는데  
이때는 루프를 사용하기 보다는 선언을 통한 초기화를 하자  
```
int a[N] = {0};
/*
int a[N];
for (int i = 0; i < N; ++i)
  a[i] = 0;
}
*/
```
## 9. 포인터로 배열 접근  
배열을 접근할 때 **포인터로 접근**하자  
배열을 포인터로 접근할 때 **두가지 방법**이 있다  
1. 순차적 접근  
```
int *p = array;
for(register unsigned int i = 0; i < N; ++i){
  cout << *p << endl;
  ++p;
}
```
2. 인덱스 접근
```
int *p = array;
for(register unsigned int i = 0; i < N; ++i){
  cout << p[i] << endl;
}
```
위 두가지 접근 방법 중 포인터의 **효과를 볼 수 있는 것은 순차적 접근**이다  
인덱스 접근은 단순히 배열을 쓰는 것과 차이점이 없다  
## 10. 빠른 연산을 할 때 전역 변수를 지양하자   
전역변수(데이터 영역)와 지역변수(스택 영역)가 **저장되는 위치는 다르다**   
일반적으로 **지역변수가 연산이 빠르다**  
함수 호출시 인수를 줄이기 위해 전역 변수를 사용하는 경우가 있는데  
연산은 매개변수로 받은 변수가 빠르니 잘 선택하자   
또한 전역 변수로 정의된 변수는 **register를 활용할 수 없다**  
## 11. BFS / DFS는 재귀함수 대신 Queue / Stack 으로  
**함수 호출은 시간을 많이 소모** 한다.
배열로 구성한 Queue / Stack을 사용하자  
## 12. Delete IF statement in FOR statement  
blar blar  
  
## 13. No duplicate FOR statement  
blar blar  
  
## 14. Using SWITCH statement instead of ELSE IF statement when there are many cases  
blar blar  
  
## 15. TERNARY OPERATOR rather than IF ELSE  
blar blar  
  
## 16. There is no difference b/w BIT and NORMAL operator when no use compiler option(이거 차이 있다고 다시적기)    
blar blar    
  
## 17. CHAR ARRAY is faster than string  
blar blar   

## 매개변수 인트 제외는 &나 \*이용, 전위 연산자, 곱하기를 비트연산자 + 덧셈으로, 나눗셈 및 나머지 연산 쓰기, 단순히 루프일 경우 i>0을 조건으로       

---
# Refer  
- Git chart  
```
http://ghchart.rshah.org    
```

- GCC Compiler Optimizing Sequence
~~~
http://egloos.zum.com/studyfoss/v/5276500
~~~

- Switch VS if
~~~
https://thinkpro.tistory.com/m/132
https://kldp.org/node/62262
~~~

- C Code Optimizing
~~~
https://kldp.org/node/79109
~~~

