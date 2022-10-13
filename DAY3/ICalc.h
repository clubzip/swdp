// ICalc.h
#pragma once

// Proxy 객체의 수명을 "참조계수(reference counting)" 기술로 관리한다면
// 반드시 참조계수 관련 함수도 인터페이스에 있어야 합니다.

// 참조계수용 함수는 모든 종류의 Proxy interface에 필요 합니다.
struct IRefCount
{
	virtual void AddRef() = 0;
	virtual void Release() = 0;

	virtual ~IRefCount() {}
};

struct ICalc : public IRefCount
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};

// ISP : interface surrogate principle
//       "인터페이스는 기능별로 분리해서 만들어야 한다."
