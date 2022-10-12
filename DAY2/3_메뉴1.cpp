// 2_메뉴1.cpp  - 55 page
#include <iostream>

// 구조적(structural) programming - C언어
// 1. 프로그램은 main 함수의 첫번째 줄 부터 시작되는 실행흐름이다.
// 2. 실행흐름을 반복하려면 반복문을 사용하고
// 3. 실행흐름을 변경하려면 제어문을 사용한다.
// 4. 기능별로 분리하려면 함수를 사용한다.
// 5. 프로그램의 기본 구조는 "함수" 이다.
// => C, PASCAL, FORTRAN, COBOL 

// 아래 코드는 C 언어로 만든 메뉴 입니다.
// 장점 : 코드가 이해 하기 쉽습니다.
// 단점 : 변화에 유연하지 못합니다.
//       1. 메뉴가 추가되면 여러곳 변경
//       2. 하위 메뉴가 있다면 ?

int main()
{
	printf("1. 김밥\n");
	printf("2. 라면\n");
	printf("메뉴를 선택하세요 >> ");

	int cmd;
	std::cin >> cmd;

	switch (cmd)
	{
	case 1: break;
	case 2: break;
	}

}


