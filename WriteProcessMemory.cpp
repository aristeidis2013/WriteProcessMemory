#include <Windows.h>
#include <iostream>

using namespace std;

int main() {
	DWORD pid = 0;
	cout << "PID: ";
	cin >> dec >> pid;

	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	if (hProcess == NULL) { 
		cout << "OpenProcess failed. GetLastError = " << dec << GetLastError() << endl;
		system("pause");
		return EXIT_FAILURE;
	}

	
	uintptr_t memoryAddress = 0x0;
	cout << "Memory address of the integer to overwrite (in hexadecimal): 0x";
	cin >> hex >> memoryAddress;


	int intToWrite = 0;
	cout << "Integer to write (in decimal): ";
	cin >> dec >> intToWrite;

	BOOL wpmReturn = WriteProcessMemory(hProcess, (LPVOID)memoryAddress, &intToWrite, sizeof(int), NULL);
	if (wpmReturn == FALSE) {
		cout << "WriteProcessMemory failed. GetLastError = " << dec << GetLastError() << endl;
		system("pause");
		return EXIT_FAILURE;
	}

	cout << "Overwritten successfully" << endl;

	cout << "Press ENTER to quit." << endl;
	system("pause > nul");

	return EXIT_SUCCESS;
}