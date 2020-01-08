#include <iostream>
using namespace std;
float croot(float x)
{
	short ex;
	float mx;

	float a = 0.15414095f, b = -0.5684319f, c = 1.413972f, d = 0.0012507216f;
	float a1 = 0.077506825f, b1 = 0.22652188f, c1 = 0.69580793f, d1 = 0.9999088f;

	__asm
	{
		mov eax, x
		shl eax, 1
		shr eax, 24
		sub ax, 01111111b
		mov ex, ax
	}
	mx = x - int(x);

	float ly = (ex + a * mx * mx * mx + b * mx * mx + c * mx + d) / 3;

	float y;

	if (int(ly))
		y = (2 << (int(ly) - 1)) * (a1*(ly - int(ly))*(ly - int(ly))*(ly - int(ly)) + b1 * (ly - int(ly))*(ly - int(ly)) + c1 * (ly - int(ly)) + d1);
	else
		y = a1 * ly * ly * ly + b1 * ly * ly + c1 * ly + d1;

	y = (2 * y * y * y + x) / (3 * y * y);
	y = (2 * y * y * y + x) / (3 * y * y);

	__asm
	{
		mov ebx, y
		mov eax, x
		shr eax, 31
		shl eax, 31
		add eax, ebx
		mov y, eax
	}
	return y;
}
__inline unsigned __int64 GetCycleCount()
{
	__asm _emit 0x0F
	__asm _emit 0x31
}
int main()
{
	__int64 ls, le;

	ls = GetCycleCount();
	cout << pow(10086, 1.0f / 3) << endl;;
	cout << croot(10086) << endl;;
	le = GetCycleCount();

	//system("cls");

	cout << le - ls << endl;
	return 0;
}
