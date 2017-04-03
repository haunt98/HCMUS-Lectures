#include "xuly.h"

int main(int argc, char *argv[])
{
	uint32_t cutHeight = 1; uint32_t cutWidth = 1;
	if (argc == 4)
	{
		if (strcmp(argv[2], "-h") == 0)

			cutHeight = char_to_int(argv[3]);

		else if (strcmp(argv[2], "-w") == 0)

			cutWidth = char_to_int(argv[3]);

		else
		{
			cout << "Error" << endl;
			return 0;
		}
	}
	else if (argc == 6)
	{
		if (strcmp(argv[2], "-h") == 0 && strcmp(argv[4], "-w") == 0)
		{
			cutHeight = char_to_int(argv[3]);
			cutWidth = char_to_int(argv[5]);
		}
		else
		{
			cout << "Error" << endl;
			return 0;
		}
	}
	else
	{
		cout << "Error" << endl;
		return 0;
	}
	cutBMP(argv[1], cutHeight, cutWidth);

	return 0;
}