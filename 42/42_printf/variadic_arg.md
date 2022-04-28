## variadic arguments

- `printf`, `scanf` 같이 매개변수의 개수가 정해지지 않은 함수처럼
- 매번 함수에 들어가는 인수의 개수가 변하는 것

    ```c
    int num = 0;
    while(num++ < 3) 
    	printf("%d : %s", num, str);
    ```

- 가변 인자 함수 만들기
    - 함수에서 가변 인자를 정의할 때는 고정 매개변수가 한 개 이상 있어야 됨
    - 고정 매개 변수 뒤에 `...`을 붙여 매개변수의 개수가 정해지지 않았다는 표시를 해준다.

        보통 고정 매개변수는 가변 인자의 개수를 받을 수 있도록 지정하는 듯..?

        ```c
        void ft_printf(int args, ...)
        // 고정 매개변수 args
        ```

    - 가변 인자를 사용하려면 `stdarg.h` 헤더 파일에 정의된 **가변 인자 처리 매크로**를 이용해야 함
        - `va_list` : 가변 인자 목록. 가변 인자의 메모리 주소를 저장하는 포인터 (자료형 type 같이)

            ```c
            #include <stdarg.h>
            va_list ap;
            ```

        - `va_start` : 가변 인자를 가져올 수 있도록 포인터 설정 함수 (매크로?)

            ```c
            va_start(ap, args);
            ```

        - `va_arg` : 가변 인자 포인터에서 특정 자료형 크기만큼 값을 가져오고 포인터 이동하는 함수

            ```c
            int num = va_arg(ap, int);
            //리턴값은 ap가 가르키는 값
            ```

            - va_arg를 실행하면 현재 ap에서 int크기(4byte)만큼 역참조하여 값을 가져온 뒤
            - ap를 int 크기만큼 >> 이동
        - `va_end` : 가변 인자 처리가 끝났을 때 포인터를 NULL로 초기화하는 함수

            ```c
            va_end(ap);
            ```

- 출처

[C 언어 코딩 도장](https://dojang.io/mod/page/view.php?id=577)
