#include "pch.h"

// 'GetTickCount' hook
DWORD WINAPI CSpeedHack::hook_GetTickCount()
{
	return instance().set_tick_count();
}


// 'GetTickCount64' hook
ULONGLONG WINAPI CSpeedHack::hook_GetTickCount64()
{
	return instance().set_tick_count64();
}


// 'timeGetTime' hook
DWORD WINAPI CSpeedHack::hook_timeGetTime()
{
	return instance().set_time_get_time();
}


// 'QueryPerformanceCounter' hook
BOOL WINAPI CSpeedHack::hook_QueryPerformanceCounter( LARGE_INTEGER* lpPerformanceCount )
{
	instance().set_performance_counter( lpPerformanceCount );
	return TRUE;
}