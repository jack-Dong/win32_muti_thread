#include<iostream>
#include <windows.h>
using namespace std;
#define mit 1
HANDLE hMutex;
HANDLE event1;
HANDLE event2;
HANDLE event3;
DWORD WINAPI Fun1(LPVOID lpParamter)
{
        
       int i = 0;
	   while(i < mit)
	   { 
                 //WaitForSingleObject(hMutex, INFINITE);
                 cout<<"Fun1 display!"<<endl; 
                // Sleep(1000);
                // ReleaseMutex(hMutex);
				 SetEvent(event1);
				 i++;
       }
	   return 0;
}

DWORD WINAPI Fun2(LPVOID lpParamter)
{
        
       int i = 0;
       while(i < mit)
	   { 
                 //WaitForSingleObject(hMutex, INFINITE);
                 cout<<"Fun2 display!"<<endl; 
                // Sleep(1000);
                // ReleaseMutex(hMutex);
				  SetEvent(event2);
				 i++;
       }
	   return 0;
}
DWORD WINAPI Fun3(LPVOID lpParamter)
{
       int i = 0;
       while(i < mit)
	   { 
                 //WaitForSingleObject(hMutex, INFINITE);
                 cout<<"Fun3 display!"<<endl; 
                // Sleep(1000);
                // ReleaseMutex(hMutex);
				 SetEvent(event3);
				 i++;
       }
	   return 0;
}



int main()
{
      HANDLE hThread1 = CreateThread(NULL, 0, Fun1, NULL, 0, NULL);
	  HANDLE hThread2 = CreateThread(NULL, 0, Fun2, NULL, 0, NULL);
	  HANDLE hThread3 = CreateThread(NULL, 0, Fun3, NULL, 0, NULL);

	  LPCWSTR name  = TEXT("screen");
      hMutex = CreateMutex(NULL, FALSE, name);

	  event1 = CreateEvent(NULL,TRUE,FALSE,NULL);
	  event2 = CreateEvent(NULL,TRUE,FALSE,NULL);
	  event3 = CreateEvent(NULL,TRUE,FALSE,NULL);

      CloseHandle(hThread1);
	  CloseHandle(hThread2);    
	  CloseHandle(hThread3);

	  
	  int i = 0;
      while(i < mit)
	  {
				WaitForSingleObject(event1,INFINITE);
				WaitForSingleObject(event2,INFINITE);
				WaitForSingleObject(event3,INFINITE);
		
               // WaitForSingleObject(hMutex, INFINITE);
               cout <<"main display!\n"<<"================================"<<endl;; 
	           Sleep(100);
              // ReleaseMutex(hMutex);
				ResetEvent(event1);
				ResetEvent(event2);
				ResetEvent(event3);
			   i++;
      }
      return 0;
}

/*
HANDLE CreateEvent(
��LPSECURITY_ATTRIBUTES lpEventAttributes,
��// SECURITY_ATTRIBUTES�ṹָ�룬��ΪNULL
��BOOL bManualReset, 
��// �ֶ�/�Զ�
��// TRUE����WaitForSingleObject������ֶ�����ResetEvent����ź�
��// FALSE����WaitForSingleObject��ϵͳ�Զ�����¼��ź�
��BOOL bInitialState, //��ʼ״̬
��LPCTSTR lpName //�¼�������
);

�����̵߳ĺ���
HANDLE CreateThread( 
    LPSECURITY_ATTRIBUTES lpThreadAttributes, // SD
    SIZE_T dwStackSize,                       // initial stack size
    LPTHREAD_START_ROUTINE lpStartAddress,    // thread function
    LPVOID lpParameter,                       // thread argument
    DWORD dwCreationFlags,                    // creation option
    LPDWORD lpThreadId                        // thread identifier
);
����������ֻ�õ��˵������͵��ĸ�����������������������һ�������ĵ�ַ��Ҳ������Ҫָ�����µ��̣߳����ĸ������Ǵ������̵߳Ĳ���ָ�롣
*/


//typedef byte BYTE;
//
//typedef unsigned short WORD;
//
//typedef unsigned int UINT;
//
//typedef int INT;
//
//typedef long BOOL;
//
//typedef long LONG;
//
//typedef unsigned long DWORD;
//
//typedef void *HANDLE;
//
//typedef WORD *LPWORD;
//
//typedef DWORD *LPDWORD;
//
//typedef char CHAR;
//
//typedef /* [string] */  __RPC_string CHAR *LPSTR;
//
//typedef /* [string] */  __RPC_string const CHAR *LPCSTR;
//
//typedef wchar_t WCHAR;
//
//typedef WCHAR TCHAR;
//
//typedef /* [string] */  __RPC_string WCHAR *LPWSTR;
//
//typedef /* [string] */  __RPC_string TCHAR *LPTSTR;
//
//typedef /* [string] */  __RPC_string const WCHAR *LPCWSTR;
//
//typedef /* [string] */  __RPC_string const TCHAR *LPCTSTR;
//
//typedef HANDLE *LPHANDLE;
//typedef void * HANDLE;
//typedef HANDLE *PHANDLE;
//
////
//// Flag (bit) fields
////
//
//typedef BYTE   FCHAR;
//typedef WORD   FSHORT;
//typedef DWORD  FLONG;

