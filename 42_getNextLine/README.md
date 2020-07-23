## Get_next_line
> 목적 : fd를 read하고 새로운 newline을 리턴하라.  
> code that returns a line ending with a newline, read from a file descriptor  
> allow you to read the text available **on a fd one line at a time**


### 배워야 할 것

1. `read` 함수
2. `static` variables 정적 변수
3. `libft`에서 어떤 함수를 갖고 와야 할까?

### prototype

```c
int get_next_line(int fd, char **line);
//첫번째 인자 : file descriptor for reading
//두번째 인자 : The value of what has been read
```

#### return value

1 : 성공적으로 읽음  
0 : EOF has been reached (end of file)  
-1 : error

