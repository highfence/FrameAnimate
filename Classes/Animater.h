
class MyTimer;

class Animator
{
public :
	Animator(HWND);
	~Animator();

	void init();
	BOOL BackgroundDraw(HDC);
	BOOL BackgroundDraw();

private :
	MyTimer* m_pTimer;
	HWND m_hWnd;
	HDC m_hdc;
	CImage* m_pBackgroundImg;
};