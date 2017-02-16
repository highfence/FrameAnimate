#include "stdafx.h"
#include "MyTimer.h"


MyTimer::MyTimer()
	: m_StandardFlag(false)
{
	return;
}

void MyTimer::MakeTimerFlag()
{
	QueryPerformanceCounter(&m_LastTime);
	m_StandardFlag = true;
	return;
}

FLOAT MyTimer::GetElapsedTime()
{
	if (m_StandardFlag == false)
	{
		return -1.f;
	}

	QueryPerformanceCounter(&m_CurTime);
	FLOAT elapsedSeconds = ((FLOAT)m_CurTime.QuadPart - (FLOAT)m_LastTime.QuadPart) / (FLOAT)m_TickPerSec.QuadPart;
	m_StandardFlag = false;

	return elapsedSeconds;
}