#pragma once
#define BLOCK_H
union Block_64b
{
	unsigned long long Full_Block; 
	struct
	{
		unsigned int LowPartOfBlock; // Младшие 32 байта
		unsigned int HighPartOfBlock; // Старшие 32 байта
	};
};