#include "pch.h"
#include "Framework.h"

int main()
{
	Framework::GetInstance()->Initialize(540, 960, "SFML Framework");
	Framework::GetInstance()->Do();
	Framework::GetInstance()->Release();
	return 0;
}