#pragma once
#define BLOCK_H
union Block_64b
{
	unsigned long long Full_Block; 
	struct
	{
		unsigned int LowPartOfBlock; // ������� 32 �����
		unsigned int HighPartOfBlock; // ������� 32 �����
	};
};