# Get_next_line

> 목적 : fd로 read하고 새로운 newline을 리턴하라  
> code that returns a line ending with a newline, read from a file descriptor

배워야 할 것

1. `read` 함수
2. `static` variables 정적 변수
3. libft에서 어떤 함수를 갖고 와야 할까?

prototype

```c
int get_next_line(int fd, char **line);
//첫번째 인자 : file descriptor for reading
//두번째 인자 : The value of what has been read
```

return value

1 : 성공적으로 읽음

0 : `EOF` has been reached (end of file)

-1 : error

allow you to read the text available on a fd one line at a time 

EOF = end of file;


---
## Static Variable
> 참고 : 윤성우의 열혈 C 프로그래밍
### 지역 변수 (local variable)

- 해당 선언문이 실행될 때 메모리 공간에 할당 되었다가, 선언문이 존재하는 함수가 반환을 하면 (종료 되면) 메모리 공간에서 소멸된다
- 스택(stack)이라는 메모리 영역에 할당됨
- 초기화 하지 않으면 쓰레기값 초기화
- 중괄호 내에 선언되는 변수는 모두 지역변수
    - 조건문, 반복문에도 선언이 가능하다
    - for문, while문 안에서만 유효한 지역변수이므로 돌아갈 때마다 초기화가 된다
    - 외부에 선언된 동일한 이름의 변수를 가리게 된다
- 매개변수는 지역변수다

### 전역변수 (Global variable)

- 프로그램의 시작과 동시에 메모리 공간에 할당되어 종료 시까지 존재한다
- 기본 0으로 초기화 된다
- 프로그램 전체 영역 어디서든 접근이 가능하다
- 하지만 전역변수의 수가 증가하면 그만큼 프로그램은 복잡해진다


### Static 변수 🌟

- 지역변수에 static 선언이 붙게 되면
    1. 선언된 함수 내에서만 접근이 가능하다 (지역변수 특성)
    2. 딱 1회 초기화 되고 프로그램 종료 시까지 메모리 공간에 존재한다. (전역변수 특성)
        - 전역변수와 동일한 시기에 할당되고 소멸된다
    3. 초기화 하지 않으면 0 초기화 (전역변수 특성)

    ⇒ 전역변수와 특성이 같지만, **함수 내에 선언된** 이유는 접근 범위를 해당 함수로 제한하기 위해서

- static 지역변수는 전역변수보다 안정적이다.
- 함수에 static 선언을 할 수 있다
  - 파일 내에서만 접근이 가능하도록 함수를 제한 하는 것 (extern 선언을 하더라도 외부 파일에서 호출 불가능)
