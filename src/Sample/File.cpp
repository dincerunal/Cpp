#include "File.h"

File::File(const char *fname, const char *mode)
{
	if ((m_f = fopen(fname, mode)) == NULL) {
		std::cerr << "Can not open file:" << fname;
		exit(EXIT_FAILURE);
	}
}

void File::Type() const
{
	int ch;

	while ((ch = fgetc(m_f)) != EOF)
		putchar(ch);
}


#if 0

#include <iostream>

int main()
{
	File f("test.txt", "rt");

	f.Type();

	return 0 ;

}
#endif