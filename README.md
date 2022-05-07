# 42-llibasm

## 어셈블리 코드에 대해서 알아보기
- C언어의 컴파일 과정은 아래와 같다.
   - `.c -> .i -> .s -> .o -> a.out(실행파일)`
- `test.c`를 `test.s`로 만들어 열어보면 어셈블리 코드를 볼 수 있다.
- C언어 코드로 짠 프로그램을 어셈블리 코드로 컴파일 하는 명령어 : `gcc -S {filename}.c`

## 관련 블로그 게시글
- [서브젝트 파악하기](https://humonnom.tistory.com/entry/libasm-%EC%96%B4%EC%85%88%EB%B8%94%EB%A6%AC-about-1-week?category=910757)
- [상태 레지스터와 시스템 콜 번호](https://humonnom.tistory.com/entry/libasm-%EC%96%B4%EC%85%88%EB%B8%94%EB%A6%AC-about-1-week-2%EC%9D%BC%EC%B0%A8ftwrite-ftread?category=910757)
- [몇가지 명령어와 범용 레지스터](https://humonnom.tistory.com/entry/libasm-%EC%96%B4%EC%85%88%EB%B8%94%EB%A6%AC-about-1-week-2%EC%9D%BC%EC%B0%A8ftstrlen?category=910757)
