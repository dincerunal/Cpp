#ifndef FILE_H_
#define FILE_H_

#include <iostream>
#include <cstdio>
#include <cstdlib>

class File {
public:
	File(const char *fname, const char *mode);	
	~File() { fclose(m_f); }
	void Type() const;	
	//...
private:
	FILE *m_f;
};

#endif // FILE_H_
