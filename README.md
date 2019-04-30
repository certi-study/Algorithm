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

## 1. REGISTER 변수 사용    
그냥 안쓰면 손해...  
단, 사용할 수 있는 **register 변수 횟수가 제한**되어 있음  
```
register unsigned int varible = 1;
```
## 2. 전위 연산자 사용  
전위 연산자와 후위 연산자의 성능 차이는 미비하지만 **전자가 조금 빠르다고 한다**   
후위 연산자는 **복사 과정**을 거치기 때문에 약간 느릴 수 있다  
참고: `http://egloos.zum.com/indra207/v/4848273`
## 3. LOOP UNROLLING(반복문에 하드코딩)      
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
## 3. Delete IF statement in FOR statement  
blar blar  
  
## 4. No duplicate FOR statement  
blar blar  
  
## 5. Using POINTER instead of ARRAY(배열처럼 쓰면 효과는 동일하다는 거 쓰기)  
blar blar  
  
## 6. Using SWITCH statement instead of ELSE IF statement when there are many cases  
blar blar  
  
## 7. INT rather than CHAR or DOUBLE or BOOL  
blar blar  
  
## 8. TERNARY OPERATOR rather than IF ELSE  
blar blar  

## 9. Using REGISTER PARAMETER instead of GLOBAL variable  
blar blar  
  
## 10. There is no difference b/w BIT and NORMAL operator when no use compiler option(이거 차이 있다고 다시적기)    
blar blar    
  
## 11. CHAR ARRAY is faster than string  
blar blar   

## 매개변수 인트 제외는 &나 \*이용, 전위 연산자, 인자 4개 이상 넘길 때..., 곱하기를 비트연산자 + 덧셈으로, 나눗셈 및 나머지 연산 쓰기    

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

