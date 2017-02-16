#include "stdafx.h"
#include "MyTimer.h"
#include "Animater.h"

const TCHAR* backgroundImg = TEXT("../Mermaid/Aquarium3.jpg");

Animator::Animator(HWND hWnd)
	: m_hWnd(hWnd)
{
	m_pTimer = new MyTimer;
	m_pBackgroundImg = new CImage;
	init();
}

Animator::~Animator()
{
	ReleaseDC(m_hWnd, m_hdc);
	delete m_pTimer;
	m_pBackgroundImg->Destroy();
	delete m_pBackgroundImg;
}

void Animator::init()
{
	m_hdc = GetDC(m_hWnd);
	m_pBackgroundImg->Load(backgroundImg);

	m_pTimer->MakeTimerFlag();
	return;
}

// ���ڷ� ���� DC�� ���ȭ���� �׷��ִ� �Լ�.
// ���ڰ� NULL�� ��� Animator ���� hdc�� ����� �׸���.
BOOL Animator::BackgroundDraw(HDC drawDC)
{
	if (drawDC == NULL)
	{
		m_pBackgroundImg->BitBlt(m_hdc, 0, 0, winWidth, winHeight, 0, 0, SRCCOPY);
	}
	else
	{
		m_pBackgroundImg->BitBlt(drawDC, 0, 0, winWidth, winHeight, 0, 0, SRCCOPY);
	}
	return true;
}
