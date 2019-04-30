#include <stdio.h>
#include <tchar.h> 
#include <windows.h>

#define SOCKET_IOCTL CTL_CODE(FILE_DEVICE_UNKNOWN,0x800,METHOD_BUFFERED,FILE_ANY_ACCESS)

// ������
int _tmain(int argc, _TCHAR* argv[])
{
	// �򿪷��ţ��豸�����
	HANDLE hDevice = CreateFile(L"\\\\.\\SocketSYM", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hDevice == INVALID_HANDLE_VALUE)
	{	
		DWORD err = GetLastError();
		printf("Failed To Obtain Device Handle! GetLastError:%u", err);
		getchar();
		return -1;
	}

	DWORD len = 0;
	CHAR buffer[20];
	memset(buffer, 0x00, 20);
	UCHAR in ;

	// �����û�����
	printf("User input : ");
	gets_s(buffer);
	//scanf_s("%d", buffer);
	
	// ���͸�����
	BOOL status = DeviceIoControl(hDevice, SOCKET_IOCTL, buffer, 20 , buffer , 20, &len, NULL);

	CloseHandle(hDevice);

	printf("Input AnyKey To Exit\r\n");
	getchar();
	return 0;
}