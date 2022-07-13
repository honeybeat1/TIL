22/07/13  
> food-court 환경설정 하면서, 데이터 프로젝트시 늘 신경써야 하는 세팅들

### direnv
- 사용자가 현재 위치한 디렉터리의 .envrc 파일을 추가로 읽어들여 해당 디렉토리에서만 필요한 설정을 로드함 (프로젝트 별로 가상환경 다르게 관리하기)
- [링크](https://www.44bits.io/ko/post/direnv_for_managing_directory_environment)
- shell의 설정파일에 추가해주기
  - ```
    ## ZSH -> ~/.zshrc에 아래 내용 추가
    ## direnv를 사용하겠다
    eval "$(direnv hook zsh)"
    ```
- direnv를 통해 특정 디렉토리에 적용되는 설정은 `.envrc` 파일에 쉘 스크립트로 작성함
  - ```
    touch .envrc
    direnv allow
    ```
  - direnv는 특정 디렉토리의 특정 컨텐츠를 가진 .envrc 파일에 대해서 명시적으로 사용을 허가하지 않은 경우 이 파일을 읽어들이지 않음. 의도치 않게 원하치 않는 쉘 스크립트가 실행되는 것을 방지하기 위해서임.
  - .envrc에 가상 환경 로드를 위한 환경 변수 추가하기
  - ```
    # .envrc 파일에 다음 내용 추가
    export PATH=".venv/bin:$PATH"
    ```
    - 해당 디렉토리에 있을 경우, PATH 경로가 .venv/bin 아래로 들어가게됨

### pyenv
- 여러 버젼의 python을 관리하고, 프로젝트 별로 (가상환경) 다르게 python 사용할 때 용이
- 버젼 관련한 이슈가 생기지 않도록 개발할 때의 파이썬 버젼을 별도로 설정하기
- python 환경변수(PATH)를 그때 그떄 변경
- 설치
  - `brew install pyenv`
  - `pyenv install 3.9.13` << 받고 싶은 python 버젼 지정
  - 이 때 pyenv가 없다는 에러가 뜬다면
    - `pyenv init` 을 입력해봄
    - interactive shell의 경우
      ```
      ~/.zshrc
      ```
      파일에 다음 세 줄 추가
      - ```
        export PATH="$HOME/.pyenv/bin:$PATH" 
        eval "$(pyenv init -)" 
        eval "$(pyenv virtualenv-init -)"
        ```
      - `exec $shell`로 쉘 재시작
  - 파이썬 버젼 설정해주기
  - 해당 shell을 사용하는 동안만
    - `pyenv shell 3.9.13`
  - 현재 directory에서만
    - `pyenv local 3.9.13`
  - 전체 (어디서든)
    - `pyenv global 3.9.13`
  - 이제 범위별로 다른 버젼의 파이썬을 사용할 수 있음
  - `which python` 입력하면 `/Users/lanachung/.pyenv/shims/python3` 이 위치의 python을 사용하고 있다는 것을 알 수 있음
