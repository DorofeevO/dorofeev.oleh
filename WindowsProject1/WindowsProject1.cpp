// WindowsProject1.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "WindowsProject1.h"
#include <iostream>
#include <cmath>

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

HWND hLab, hEdit, h1, h2, h3, h4, h5, h6, h7, h8, h9, h0, hP, hM, hMul, hDiv, hEqul, hC, hc, hj, hSq, hSqu, hSin, hCos, hTan;

using namespace std;


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPROJECT1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT1));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}

//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    static TCHAR szWindowClass[] = _T("DesktopApp");
    static TCHAR szTitle[] = _T("Windows Desktop Guided Tour Application");

    // The parameters to CreateWindowEx explained:
    // WS_EX_OVERLAPPEDWINDOW : An optional extended window style.
    // szWindowClass: the name of the application
    // szTitle: the text that appears in the title bar
    // WS_OVERLAPPEDWINDOW: the type of window to create
    // CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
    // 500, 100: initial size (width, length)
    // NULL: the parent of this window
    // NULL: this application does not have a menu bar
    // hInstance: the first parameter from WinMain
    // NULL: not used in this application

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, CW_USEDEFAULT, 212, 410, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//

//LPCWSTR num[] = {L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9"};

char buff[32];
int asci = 48;
int in, counter, cF;
float a, b, c;
bool isA, isP, isM, isMul, isDiv, isNEG, isSin, isCos, isTan, isPow, isSqr;

//int con(int num[]) {
//
//    int res = 0;
//    
//    int temp = in;
//
//    for (int i = 0; i <= in; i++) {
//        res += num[i] * (10^temp);
//        temp--;
//    }
//
//    return res;
//}

void n(int nu) {
    buff[in] = (char)asci+nu;
    in+=2;
    if (!isA) {
        a = a * 10 + nu;
    }
    else {
        b = b * 10 + nu;
    }
    SetWindowTextW(hLab, (LPCWSTR)buff);
}
void clear() {
    for (int i = 0; i < 32; i++) {
        buff[i] = NULL;
    }
    in = 0;
    SetWindowTextW(hLab, (LPCWSTR)buff);
}

int count(int num) {
    int count = 0;
    while (num != 0) {
        count++;
        num = num / 10;
    }

    return max(count, 1);
}

int count_float(float num) {
    int count = 0;
    while (fmod(num, 1.f) != 0.0) {
        count++;
        num = num * 10;
    }
    return count;
}

void t(float c, int counter) {
    while (counter != 0) {
        b = (int)c % 10;
        c /= 10;
        buff[in] = (char)(asci + b);
        in -= 2;
        counter--;
    }
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            // case when client press 0-9 on program
            case 0:
                n(0);
                break;
            case 1:
                n(1);
                break;
            case 2:
                n(2);
                break;
            case 3:
                n(3);
                break;
            case 4:
                n(4);
                break;
            case 5:
                n(5);
                break;
            case 6:
                n(6);
                break;
            case 7:
                n(7);
                break;
            case 8:
                n(8);
                break;
            case 9:
                n(9);
                break;
            // it's +
            case 10:
                isA = true;
                isP = true;
                clear();
                break;
            // it's -
            case 11:
                isA = true;
                isM = true;
                clear();
                break;
            // it's *
            case 12:
                isA = true;
                isMul = true;
                clear();
                break;
            // it's /
            case 13:
                isA = true;
                isDiv = true;
                clear();
                break;
            // it's =
            case 14:
                
                // if press +, -, *, / calculation result
                if (isP) {
                    c = a + b;
                }
                if (isM) {
                    c = a - b;
                }
                if (isMul) {
                    c = a * b;
                }
                if (isDiv) {
                    c = a / b;
                }

                // if press sin, cos, tan calculation
                if (isSin) {
                    c = sin(a);
                }
                if (isCos) {
                    c = cos(a);
                }
                if (isTan) {
                    c = tan(a);
                }

                // powered number like 2^3=8
                if (isPow) {
                    c = pow(a, b);
                }
                // sqrt like sqrt(16)=4
                if (isSqr) {
                    c = sqrt(a);
                }

                // clear display
                clear();

                // if number is negetive add -
                if (std::abs(c) != c){
                    buff[in] = '-';
                    c *= -1;
                    in += 2;
                }

                // counter it's a number which shown lenght number
                counter = count(c);
                // cF it's a number which shown lenght number after ,
                cF = count_float(c);
                a = c;

                in += 2 * (counter - 1);

                if ( cF != 0 ) {
                    
                    int f = c;
                    in += 2 * (cF+1);
                    t(fmod(c, 1.f) * pow(10, cF), cF);
                    buff[in] = ',';
                    in -= 2;
                    if (counter == 0) buff[in] == '0';
                    t(f, counter);
                    
                }
                else {
                    t(c, counter);
                }
                // show a buffer
                SetWindowTextW(hLab, (LPCWSTR)buff);
                b = 0;

                // turn false bool value

                isA = false;
                isP = false;
                isM = false;
                isMul = false;
                isDiv = false;
                isNEG = false;
                isSin = false;
                isCos = false;
                isTan = false;
                isPow = false;
                isSqr = false;
                break;
            case 15:
                // clear all. C button
                a = 0;
                b = 0;
                clear();
                break;
            case 16:
                isSqr = true;
                buff[in] = 's';
                in += 2;
                buff[in] = 'q';
                in += 2;
                buff[in] = 'r';
                in += 2;
                buff[in] = 't';
                in += 2;
                buff[in] = ' ';
                in += 2;
                SetWindowTextW(hLab, (LPCWSTR)buff);
                break;
            case 17:
                isA = true;
                isPow = true;
                buff[in] = '^';
                in += 2;
                SetWindowTextW(hLab, (LPCWSTR)buff);
                break;
            case 18:
                // sin
                isSin = true;
                buff[in] = 's';
                in += 2;
                buff[in] = 'i';
                in += 2;
                buff[in] = 'n';
                in += 2;
                buff[in] = ' ';
                in += 2;
                SetWindowTextW(hLab, (LPCWSTR)buff);
                break;
            case 19:
                // cos
                isCos = true;
                buff[in] = 'c';
                in += 2;
                buff[in] = 'o';
                in += 2;
                buff[in] = 's';
                in += 2;
                buff[in] = ' ';
                in += 2;
                SetWindowTextW(hLab, (LPCWSTR)buff);
                break;
            case 20:
                // tan
                isTan = true;
                buff[in] = 't';
                in += 2;
                buff[in] = 'a';
                in += 2;
                buff[in] = 'n';
                in += 2;
                buff[in] = ' ';
                in += 2;
                SetWindowTextW(hLab, (LPCWSTR)buff);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            int step = 50;
            hLab = CreateWindowW(L"static", L"0", WS_VISIBLE| WS_CHILD | WS_BORDER, 0, 0, 200, step, hWnd, nullptr, nullptr, nullptr);
            h0 = CreateWindowW(L"button", L"0", WS_VISIBLE | WS_CHILD | WS_BORDER, 0 * step, 6 * step, step, step, hWnd, (HMENU)0, nullptr, nullptr);
            h1 = CreateWindowW(L"button", L"1", WS_VISIBLE | WS_CHILD | WS_BORDER, 0*step, 5*step, step, step, hWnd, (HMENU)1, nullptr, nullptr);
            h2 = CreateWindowW(L"button", L"2", WS_VISIBLE | WS_CHILD | WS_BORDER, 1*step, 5*step, step, step, hWnd, (HMENU)2, nullptr, nullptr);
            h3 = CreateWindowW(L"button", L"3", WS_VISIBLE | WS_CHILD | WS_BORDER, 2*step, 5*step, step, step, hWnd, (HMENU)3, nullptr, nullptr);
            h4 = CreateWindowW(L"button", L"4", WS_VISIBLE | WS_CHILD | WS_BORDER, 0*step, 4*step, step, step, hWnd, (HMENU)4, nullptr, nullptr);
            h5 = CreateWindowW(L"button", L"5", WS_VISIBLE | WS_CHILD | WS_BORDER, 1*step, 4*step, step, step, hWnd, (HMENU)5, nullptr, nullptr);
            h6 = CreateWindowW(L"button", L"6", WS_VISIBLE | WS_CHILD | WS_BORDER, 2*step, 4*step, step, step, hWnd, (HMENU)6, nullptr, nullptr);
            h7 = CreateWindowW(L"button", L"7", WS_VISIBLE | WS_CHILD | WS_BORDER, 0*step, 3*step, step, step, hWnd, (HMENU)7, nullptr, nullptr);
            h8 = CreateWindowW(L"button", L"8", WS_VISIBLE | WS_CHILD | WS_BORDER, 1*step, 3*step, step, step, hWnd, (HMENU)8, nullptr, nullptr);
            h9 = CreateWindowW(L"button", L"9", WS_VISIBLE | WS_CHILD | WS_BORDER, 2*step, 3*step, step, step, hWnd, (HMENU)9, nullptr, nullptr);
            hP = CreateWindowW(L"button", L"+", WS_VISIBLE | WS_CHILD | WS_BORDER, 3*step, 2*step, step, step, hWnd, (HMENU)10, nullptr, nullptr);
            hM = CreateWindowW(L"button", L"-", WS_VISIBLE | WS_CHILD | WS_BORDER, 3*step, 3*step, step, step, hWnd, (HMENU)11, nullptr, nullptr);
            hMul = CreateWindowW(L"button", L"*", WS_VISIBLE | WS_CHILD | WS_BORDER, 3*step, 4*step, step, step, hWnd, (HMENU)12, nullptr, nullptr);
            hDiv = CreateWindowW(L"button", L"/", WS_VISIBLE | WS_CHILD | WS_BORDER, 3*step, 5*step, step, step, hWnd, (HMENU)13, nullptr, nullptr);
            hEqul = CreateWindowW(L"button", L"=", WS_VISIBLE | WS_CHILD | WS_BORDER, 3*step, 6*step, step, step, hWnd, (HMENU)14, nullptr, nullptr);
            hC = CreateWindowW(L"button", L"C", WS_VISIBLE | WS_CHILD | WS_BORDER, 3*step, 1*step, step, step, hWnd, (HMENU)15, nullptr, nullptr);
            hSq = CreateWindowW(L"button", L"Sqrt", WS_VISIBLE | WS_CHILD | WS_BORDER, 1*step, 2*step, step, step, hWnd, (HMENU)16, nullptr, nullptr);
            hSqu = CreateWindowW(L"button", L"^", WS_VISIBLE | WS_CHILD | WS_BORDER, 0*step, 2*step, step, step, hWnd, (HMENU)17, nullptr, nullptr);
            hSin = CreateWindowW(L"button", L"Sin", WS_VISIBLE | WS_CHILD | WS_BORDER, 0*step, 1*step, step, step, hWnd, (HMENU)18, nullptr, nullptr);
            hCos = CreateWindowW(L"button", L"Cos", WS_VISIBLE | WS_CHILD | WS_BORDER, 1*step, 1*step, step, step, hWnd, (HMENU)19, nullptr, nullptr);
            hTan = CreateWindowW(L"button", L"Tan", WS_VISIBLE | WS_CHILD | WS_BORDER, 2*step, 1*step, step, step, hWnd, (HMENU)20, nullptr, nullptr);


            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
