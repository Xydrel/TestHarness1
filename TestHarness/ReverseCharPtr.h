#pragma once

using namespace std;

char* ReverseStr(char* str)
{
	if (strlen(str) == 0)
	{
		return str;
	}

	int length = strlen(str) - 1;
	int start, end, buff;
	for (start = 0, end = length; start < end; start++, end--)
	{
		buff = str[start];
		str[start] = str[end];
		str[end] = buff;
	}

	return str;
}

bool IsPalendrome(char* str)
{
	if (strlen(str) == 0)
	{
		return true;
	}

	int length = strlen(str) - 1;
	int start = 0;
	int end = length;

	for (; start < end; start++, end--)
	{
		if (str[start] == str[end])
		{
			continue;
		}
		else
		{
			return false;
		}
	}

	return true;
}