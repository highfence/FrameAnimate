#include "stdafx.h"
#include "MyTimer.h"
#include "Animator.h"
#include "Blip.h"

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

	DeleteDC(m_MemoryDC);
}

void Animator::init()
{
	m_hdc = GetDC(m_hWnd);
	m_pBackgroundImg->Load(backgroundImg);
	m_pBlip = new Blip(m_hdc);
	m_MemoryDC = CreateCompatibleDC(m_hdc);

	m_pTimer->MakeTimerFlag();
	return;
}

// 인자로 받은 DC에 배경화면을 그려주는 함수.
// 인자가 NULL일 경우 Animator 안의 hdc에 배경을 그린다.
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

BOOL Animator::CharacterDraw(HDC drawDC)
{
	if (drawDC == NULL)
	{
		drawDC = m_hdc;
	}

	m_pBlip->Draw(drawDC);

	return true;
}

BOOL Animator::Draw()
{
	//BackgroundDraw(m_hdc);
	CharacterDraw(m_hdc);

	//BitBlt(m_hdc, 0, 0, winWidth, winHeight, m_MemoryDC, 0, 0, SRCCOPY);

	return true;
}