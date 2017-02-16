
class MyTimer
{
public:
	MyTimer();
	~MyTimer() = default;

	void			MakeTimerFlag();
	FLOAT			GetElapsedTime();

private:
	LARGE_INTEGER	m_LastTime;
	LARGE_INTEGER	m_CurTime;
	LARGE_INTEGER	m_TickPerSec;
	BOOL			m_StandardFlag;

};