// ComputerForChildren.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "ComputerForChildren.h"
#include <string>
#include <math.h>
#include <vector>

using namespace std;

#define MAX_LOADSTRING 100
#define ID_ZERO_BUTTON 1000
#define ID_ONE_BUTTON 1001
#define ID_TWO_BUTTON 1002
#define ID_THREE_BUTTON 1003
#define ID_FOUR_BUTTON 1004
#define ID_FIVE_BUTTON 1005
#define ID_SIX_BUTTON 1006
#define ID_SEVEN_BUTTON 1007
#define ID_EIGHT_BUTTON 1008
#define ID_NINE_BUTTON 1009
#define ID_COMMA_BUTTON 1010
#define ID_EQUAL_BUTTON 1011
#define ID_DELETE_BUTTON 1012
#define ID_DIVIDED_BUTTON 1013
#define ID_MULTIPLIED_BUTTON 1014
#define ID_DECREASE_BUTTON 1015
#define ID_ADDITION_BUTTON 1016
#define ID_TIMER 1017
#define ID_STATIC_CALCUL 1018
#define ID_STATIC_TEXT 1018

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
HWND hs_calcul, hs_text, hb_zero, hb_one, hb_two, hb_three, hb_four, hb_five, hb_six, hb_seven, hb_eight, hb_nine, hb_comma, hb_equal, hb_delete, hb_divided, hb_multiplied, hb_decrease, hb_addition;
HWND hWnd;
HANDLE id_thread_write = 0, id_thread_calculate = 0;
HMODULE hdll;
int unghi = 0, cx, cy, i = 0, button_pressed = -1;
string calcul = "", text = "";
RECT rc;

typedef int(*t_get_zero_coords_dll)(void);
t_get_zero_coords_dll get_zero_coords_dll;

typedef int(*t_get_one_coords_dll)(void);
t_get_one_coords_dll get_one_coords_dll;

typedef int(*t_get_two_coords_dll)(void);
t_get_two_coords_dll get_two_coords_dll;

typedef int(*t_get_three_coords_dll)(void);
t_get_three_coords_dll get_three_coords_dll;

typedef int(*t_get_four_coords_dll)(void);
t_get_four_coords_dll get_four_coords_dll;

typedef int(*t_get_five_coords_dll)(void);
t_get_five_coords_dll get_five_coords_dll;

typedef int(*t_get_six_coords_dll)(void);
t_get_six_coords_dll get_six_coords_dll;

typedef int(*t_get_seven_coords_dll)(void);
t_get_seven_coords_dll get_seven_coords_dll;

typedef int(*t_get_eight_coords_dll)(void);
t_get_eight_coords_dll get_eight_coords_dll;

typedef int(*t_get_nine_coords_dll)(void);
t_get_nine_coords_dll get_nine_coords_dll;

typedef int(*t_get_addition_coords_dll)(void);
t_get_addition_coords_dll get_addition_coords_dll;

typedef int(*t_get_decrease_coords_dll)(void);
t_get_decrease_coords_dll get_decrease_coords_dll;

typedef int(*t_get_multiplied_coords_dll)(void);
t_get_multiplied_coords_dll get_multiplied_coords_dll;

typedef int(*t_get_divided_coords_dll)(void);
t_get_divided_coords_dll get_divided_coords_dll;

typedef int(*t_get_comma_coords_dll)(void);
t_get_comma_coords_dll get_comma_coords_dll;

typedef int(*t_get_equal_coords_dll)(void);
t_get_equal_coords_dll get_equal_coords_dll;

int* zero_coords;
int* one_coords;
int* two_coords;
int* three_coords;
int* four_coords;
int* five_coords;
int* six_coords;
int* seven_coords;
int* eight_coords;
int* nine_coords;
int* addition_coords;
int* decrease_coords;
int* multiplied_coords;
int* divided_coords;
int* comma_coords;
int* equal_coords;

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

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
    LoadStringW(hInstance, IDC_COMPUTERFORCHILDREN, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_COMPUTERFORCHILDREN));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_COMPUTERFORCHILDREN));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_COMPUTERFORCHILDREN);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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

   hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   hs_calcul = CreateWindowW(
	   L"STATIC",
	   L"Calcul",
	   WS_CHILD | WS_VISIBLE,
	   0, 180, 240, 20,
	   hWnd,
	   (HMENU)ID_STATIC_CALCUL,
	   hInstance,
	   NULL
   );

   hs_text = CreateWindowW(
	   L"STATIC",
	   L"Text",
	   WS_CHILD | WS_VISIBLE,
	   0, 200, 1000, 20,
	   hWnd,
	   (HMENU)ID_STATIC_TEXT,
	   hInstance,
	   NULL
   );

   hb_zero = CreateWindowW(
	   L"BUTTON",
	   L"0",
	   WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON,
	   0, 400, 60, 60,
	   hWnd,
	   (HMENU)ID_ZERO_BUTTON,
	   hInstance,
	   NULL
   );

   hb_one = CreateWindowW(
	   L"BUTTON",
	   L"1",
	   WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON,
	   0, 340, 60, 60,
	   hWnd,
	   (HMENU)ID_ONE_BUTTON,
	   hInstance,
	   NULL
   );

   hb_two = CreateWindowW(
	   L"BUTTON",
	   L"2",
	   WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON,
	   60, 340, 60, 60,
	   hWnd,
	   (HMENU)ID_TWO_BUTTON,
	   hInstance,
	   NULL
   );

   hb_three = CreateWindowW(
	   L"BUTTON",
	   L"3",
	   WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON,
	   120, 340, 60, 60,
	   hWnd,
	   (HMENU)ID_THREE_BUTTON,
	   hInstance,
	   NULL
   );

   hb_four = CreateWindowW(
	   L"BUTTON",
	   L"4",
	   WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON,
	   0, 280, 60, 60,
	   hWnd,
	   (HMENU)ID_FOUR_BUTTON,
	   hInstance,
	   NULL
   );

   hb_five = CreateWindowW(
	   L"BUTTON",
	   L"5",
	   WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON,
	   60, 280, 60, 60,
	   hWnd,
	   (HMENU)ID_FIVE_BUTTON,
	   hInstance,
	   NULL
   );

   hb_six = CreateWindowW(
	   L"BUTTON",
	   L"6",
	   WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON,
	   120, 280, 60, 60,
	   hWnd,
	   (HMENU)ID_SIX_BUTTON,
	   hInstance,
	   NULL
   );

   hb_seven = CreateWindowW(
	   L"BUTTON",
	   L"7",
	   WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON,
	   0, 220, 60, 60,
	   hWnd,
	   (HMENU)ID_SEVEN_BUTTON,
	   hInstance,
	   NULL
   );

   hb_eight = CreateWindowW(
	   L"BUTTON",
	   L"8",
	   WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON,
	   60, 220, 60, 60,
	   hWnd,
	   (HMENU)ID_EIGHT_BUTTON,
	   hInstance,
	   NULL
   );

   hb_nine = CreateWindowW(
	   L"BUTTON",
	   L"9",
	   WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON,
	   120, 220, 60, 60,
	   hWnd,
	   (HMENU)ID_NINE_BUTTON,
	   hInstance,
	   NULL
   );

   hb_comma = CreateWindowW(
	   L"BUTTON",
	   L",",
	   WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON,
	   60, 400, 60, 60,
	   hWnd,
	   (HMENU)ID_COMMA_BUTTON,
	   hInstance,
	   NULL
   );

   hb_equal = CreateWindowW(
	   L"BUTTON",
	   L"=",
	   WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON,
	   120, 400, 60, 60,
	   hWnd,
	   (HMENU)ID_EQUAL_BUTTON,
	   hInstance,
	   NULL
   );

   hb_delete = CreateWindowW(
	   L"BUTTON",
	   L"C",
	   WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON,
	   180, 220, 60, 60,
	   hWnd,
	   (HMENU)ID_DELETE_BUTTON,
	   hInstance,
	   NULL
   );

   hb_divided = CreateWindowW(
	   L"BUTTON",
	   L":",
	   WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON,
	   180, 280, 60, 60,
	   hWnd,
	   (HMENU)ID_DIVIDED_BUTTON,
	   hInstance,
	   NULL
   );

   hb_multiplied = CreateWindowW(
	   L"BUTTON",
	   L"*",
	   WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON,
	   180, 340, 60, 60,
	   hWnd,
	   (HMENU)ID_MULTIPLIED_BUTTON,
	   hInstance,
	   NULL
   );

   hb_decrease = CreateWindowW(
	   L"BUTTON",
	   L"-",
	   WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON,
	   180, 400, 60, 60,
	   hWnd,
	   (HMENU)ID_DECREASE_BUTTON,
	   hInstance,
	   NULL
   );

   hb_addition = CreateWindowW(
	   L"BUTTON",
	   L"+",
	   WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON,
	   180, 460, 60, 60,
	   hWnd,
	   (HMENU)ID_ADDITION_BUTTON,
	   hInstance,
	   NULL
   );

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

string digits_vector[] = { "zero ", "unu ", "doi ", "trei ", "patru ", "cinci ", "sase ", "sapte ", "opt ", "noua ", "zece ", "unsprezece ", "doisprezece ", "treisprezece ", "paisprezece ", "cincisprezece ", "saisprezece ", "saptesprezece ", "optsprezece ", "nouasprezece " };

void digits_ten(int count) {
	text.append(digits_vector[count]);
}

void two_digits(int count) {
	if(count % 100 < 20) digits_ten(count);
	else {
		if (count / 10 == 6) text.append("sai");
		else digits_ten(count / 10);
		if (count % 10 == 0) text.append("zeci");
		else {
			text.append("zeci si ");
			digits_ten(count % 10);
		}
	}
}

void three_digits(int count) {
	if (count / 100 == 1) {
		text.append("o ");
		text.append("suta ");
	}
	else if (count / 100 == 2) {
		text.append("doua ");
		text.append("sute ");
	}
	else {
		digits_ten(count / 100);
		text.append("sute ");
	}
	if (count % 100 != 0) {
		if (count % 100 < 20) digits_ten(count % 100);
		else two_digits(count % 100);
	}
}

void four_digits(int count) {
	if (count / 1000 == 1) {
		text.append("o ");
		text.append("mie ");
	}
	else if (count / 1000 == 2) {
		text.append("doua ");
		text.append("mii ");
	}
	else {
		digits_ten(count / 1000);
		text.append("mii ");
	}
	if (count % 1000 != 0) {
		if (count % 1000 < 100) two_digits(count % 1000);
		else three_digits(count % 1000);
	}
}

void five_digits(int count) {
	if (count / 1000 != 0) {
		two_digits(count / 1000);
		text.append("mii ");
	}
	if (count % 1000 != 0) {
		if (count % 1000 < 100) two_digits(count % 1000);
		else three_digits(count % 1000);
	}
}

void six_digits(int count) {
	three_digits(count / 1000);
	text.append("mii ");
	if (count % 1000 != 0) {
		if (count % 1000 < 100) two_digits(count % 1000);
		else three_digits(count % 1000);
	}
}

void seven_digits(int count) {
	if (count / 1000000 == 1) {
		text.append("un ");
		text.append("milion ");
	}
	else if (count / 1000000 == 2) {
		text.append("doua ");
		text.append("milioane ");
	}
	else {
		digits_ten(count / 1000000);
		text.append("milioane ");
	}
	if (count % 1000000 != 0) {
		if (count % 1000000 < 100000) five_digits(count % 100000);
		else six_digits(count % 1000000);
	}
}

void eight_digits(int count) {
	if (count / 1000000 != 0) {
		two_digits(count / 1000000);
		text.append("milioane ");
	}
	if (count % 1000000 != 0) {
		if (count % 1000000 < 100000) five_digits(count % 100000);
		else six_digits(count % 1000000);
	}
}

void nine_digits(int count) {
	three_digits(count / 1000000);
	text.append("milioane ");
	if (count % 1000000 != 0) {
		if (count % 1000000 < 100000) five_digits(count % 100000);
		else six_digits(count % 1000000);
	}
}

void ten_digits(long long int count) {
	if (count / 1000000000 == 1) {
		text.append("un ");
		text.append("miliard ");
	}
	else if (count / 1000000000 == 2) {
		text.append("doua ");
		text.append("miliarde ");
	}
	else {
		digits_ten(count / 1000000000);
		text.append("miliarde ");
	}
	if (count % 1000000 != 0) {
		if (count % 1000000000 < 100000000) eight_digits(count % 100000000);
		else nine_digits(count % 1000000000);
	}
}

void eleven_digits(long long int count) {
	two_digits(count / 1000000000);
	text.append("miliarde ");
	if (count % 1000000 != 0) {
		if (count % 1000000000 < 100000000) eight_digits(count % 100000000);
		else nine_digits(count % 1000000000);
	}
}

void twelve_digits(long long int count) {
	three_digits(count / 1000000000);
	text.append("miliarde ");
	if (count % 1000000 != 0) {
		if (count % 1000000000 < 100000000) eight_digits(count % 100000000);
		else nine_digits(count % 1000000000);
	}
}

void write_with_letters() {
	int i = calcul.length();
	string number = "";
	text = "";
	while (i >= 0 && calcul.substr(i, 1).compare("+") != 0 && calcul.substr(i, 1).compare("-") != 0 && calcul.substr(i, 1).compare("*") != 0 && calcul.substr(i, 1).compare(":") != 0 && calcul.substr(i, 1).compare(".") != 0 && calcul.substr(i, 1).compare("=") != 0) {
		number.insert(0, calcul.substr(i, 1));
		i--;
	}
	switch (number.length()) {
	case 1:
		digits_ten(stoi(number));
		break;
	case 2:
		if (stoi(number) < 20) digits_ten(stoi(number));
		else two_digits(stoi(number));
		break;
	case 3:
		three_digits(stoi(number));
		break;
	case 4:
		four_digits(stoi(number));
		break;
	case 5:
		five_digits(stoi(number));
		break;
	case 6:
		six_digits(stoi(number));
		break;
	case 7:
		seven_digits(stoi(number));
		break;
	case 8:
		eight_digits(stoi(number));
		break;
	case 9:
		nine_digits(stoi(number));
		break;
	case 10:
		ten_digits(stoll(number));
		break;
	case 11:
		eleven_digits(stoll(number));
		break;
	case 12:
		twelve_digits(stoll(number));
		break;
	default:
		if(number.length() > 12) text = "Ai pace! Oricum n-ai intelege!";
		else if (calcul.substr(i, 1).compare("+") == 0) text.append("plus");
		else if (calcul.substr(i, 1).compare("-") == 0) text.append("minus");
		else if (calcul.substr(i, 1).compare("*") == 0) text.append("ori");
		else if (calcul.substr(i, 1).compare(":") == 0) text.append("impartit");
		else if (calcul.substr(i, 1).compare(".") == 0) text.append("virgula");
		else if (calcul.substr(i, 1).compare("=") == 0) text.append("egal");
		break;
	}
	SetWindowTextA(hs_text, text.c_str());
}

void draw_digit(PAINTSTRUCT *ps, HDC hdc, int size_vect, int *coords) {
	Rectangle(hdc, coords[i + 1], coords[i], coords[i + 1] + 2, coords[i] + 2);
	if (i == size_vect - 2) {
		KillTimer(hWnd, ID_TIMER);
		i = 0;
	}
}

void update_expresion(string s) {
	calcul.append(s);
	SetWindowTextA(hs_calcul, calcul.c_str());
}

void calculate() {
	vector<string> numbers;
	vector<string> operators;
	int start = 0;
	for (int j = 0; j < calcul.length(); j++) {
		if (calcul.substr(j, 1).compare("+") == 0 || calcul.substr(j, 1).compare("-") == 0 || calcul.substr(j, 1).compare("*") == 0 || calcul.substr(j, 1).compare(":") == 0) {
			numbers.push_back(calcul.substr(start, j - start));
			operators.push_back(calcul.substr(j, 1));
			start = j + 1;
		}
		if ((j + 1) == calcul.length()) {
			numbers.push_back(calcul.substr(start, j - start + 1));
		}
	}

	int flag = 1;
	while (flag == 1 && operators.size() != 0) {
		for (int j = 0; j < operators.size(); j++) {
			if (operators[j].compare("*") == 0) {
				numbers[j] = to_string(stof(numbers[j]) * stof(numbers[j + 1]));
				numbers.erase(numbers.begin() + (j + 1));
				operators.erase(operators.begin() + j);
				flag = 1;
				break;
			}
			if (operators[j].compare(":") == 0) {
				numbers[j] = to_string(stof(numbers[j]) / stof(numbers[j + 1]));
				numbers.erase(numbers.begin() + (j + 1));
				operators.erase(operators.begin() + j);
				flag = 1;
				break;
			}
			flag = 0;
		}
	}
	while (operators.size() != 0) {
		if (operators[0].compare("+") == 0) {
			numbers[0] = to_string(stof(numbers[0]) + stof(numbers[1]));
			numbers.erase(numbers.begin() + 1);
			operators.erase(operators.begin());
		}
		if (operators[0].compare("-") == 0) {
			numbers[0] = to_string(stof(numbers[0]) - stof(numbers[1]));
			numbers.erase(numbers.begin() + 1);
			operators.erase(operators.begin());
		}
	}
	calcul.append(numbers[0]);
	SetWindowTextA(hs_calcul, calcul.c_str());
	calcul = "";
}

void command(int id_command, string s) {
	button_pressed = id_command;
	rc.left = 0; rc.top = 10; rc.right = 230; rc.bottom = 180;
	InvalidateRect(hWnd, &rc, true);
	i = 0;
	SetTimer(hWnd, ID_TIMER, 1, NULL);
	update_expresion(s);
	id_thread_write = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)write_with_letters, NULL, 0, NULL);
	if (id_command == 15) id_thread_calculate = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)calculate, NULL, 0, NULL);
	//CloseHandle(id_thread_write);
	//CloseHandle(id_thread_calculate);
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
				rc.left = 0; rc.top = 0; rc.right = 240; rc.bottom = 190;
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
			case ID_ZERO_BUTTON:
				command(0, "0");
				break;
			case ID_ONE_BUTTON:
				command(1, "1");
				break;
			case ID_TWO_BUTTON:
				command(2, "2");
				break;
			case ID_THREE_BUTTON:
				command(3, "3");
				break;
			case ID_FOUR_BUTTON:
				command(4, "4");
				break;
			case ID_FIVE_BUTTON:
				command(5, "5");
				break;
			case ID_SIX_BUTTON:
				command(6, "6");
				break;
			case ID_SEVEN_BUTTON:
				command(7, "7");
				break;
			case ID_EIGHT_BUTTON:
				command(8, "8");
				break;
			case ID_NINE_BUTTON:
				command(9, "9");
				break;
			case ID_ADDITION_BUTTON:
				command(10, "+");
				break;
			case ID_DECREASE_BUTTON:
				command(11, "-");
				break;
			case ID_MULTIPLIED_BUTTON:
				command(12, "*");
				break;
			case ID_DIVIDED_BUTTON:
				command(13, ":");
				break;
			case ID_COMMA_BUTTON:
				command(14, ".");
				break;
			case ID_EQUAL_BUTTON:
				command(15, "=");
				
				break;
			case ID_DELETE_BUTTON:
				KillTimer(hWnd, ID_TIMER);
				InvalidateRect(hWnd, &rc, true);
				if (calcul != "") {
					calcul.pop_back();
					id_thread_write = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)write_with_letters, NULL, 0, NULL);
					CloseHandle(id_thread_write);
				}
				SetWindowTextA(hs_calcul, calcul.c_str());
				break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);
			switch (button_pressed) {
			case 0:
				hdll = LoadLibrary(L"coords.dll");
				get_zero_coords_dll = (t_get_zero_coords_dll)GetProcAddress(hdll, "getZeroCoords");
				zero_coords = (int*)get_zero_coords_dll();
				draw_digit(&ps, hdc, 432, zero_coords);
				FreeLibrary(hdll);
				break;
			case 1:
				hdll = LoadLibrary(L"coords.dll");
				get_one_coords_dll = (t_get_one_coords_dll)GetProcAddress(hdll, "getOneCoords");
				one_coords = (int*)get_one_coords_dll();
				draw_digit(&ps, hdc, 202, one_coords);
				FreeLibrary(hdll);
				break;
			case 2:
				hdll = LoadLibrary(L"coords.dll");
				get_two_coords_dll = (t_get_two_coords_dll)GetProcAddress(hdll, "getTwoCoords");
				two_coords = (int*)get_two_coords_dll();
				draw_digit(&ps, hdc, 342, two_coords);
				FreeLibrary(hdll);
				break;
			case 3:
				hdll = LoadLibrary(L"coords.dll");
				get_three_coords_dll = (t_get_three_coords_dll)GetProcAddress(hdll, "getThreeCoords");
				three_coords = (int*)get_three_coords_dll();
				draw_digit(&ps, hdc, 324, three_coords);
				FreeLibrary(hdll);
				break;
			case 4:
				hdll = LoadLibrary(L"coords.dll");
				get_four_coords_dll = (t_get_four_coords_dll)GetProcAddress(hdll, "getFourCoords");
				four_coords = (int*)get_four_coords_dll();
				draw_digit(&ps, hdc, 386, four_coords);
				FreeLibrary(hdll);
				break;
			case 5:
				hdll = LoadLibrary(L"coords.dll");
				get_five_coords_dll = (t_get_five_coords_dll)GetProcAddress(hdll, "getFiveCoords");
				five_coords = (int*)get_five_coords_dll();
				draw_digit(&ps, hdc, 336, five_coords);
				FreeLibrary(hdll);
				break;
			case 6:
				hdll = LoadLibrary(L"coords.dll");
				get_six_coords_dll = (t_get_six_coords_dll)GetProcAddress(hdll, "getSixCoords");
				six_coords = (int*)get_six_coords_dll();
				draw_digit(&ps, hdc, 394, six_coords);
				FreeLibrary(hdll);
				break;
			case 7:
				hdll = LoadLibrary(L"coords.dll");
				get_seven_coords_dll = (t_get_seven_coords_dll)GetProcAddress(hdll, "getSevenCoords");
				seven_coords = (int*)get_seven_coords_dll();
				draw_digit(&ps, hdc, 258, seven_coords);
				FreeLibrary(hdll);
				break;
			case 8:
				hdll = LoadLibrary(L"coords.dll");
				get_eight_coords_dll = (t_get_eight_coords_dll)GetProcAddress(hdll, "getEightCoords");
				eight_coords = (int*)get_eight_coords_dll();
				draw_digit(&ps, hdc, 464, eight_coords);
				FreeLibrary(hdll);
				break;
			case 9:
				hdll = LoadLibrary(L"coords.dll");
				get_nine_coords_dll = (t_get_nine_coords_dll)GetProcAddress(hdll, "getNineCoords");
				nine_coords = (int*)get_nine_coords_dll();
				draw_digit(&ps, hdc, 396, nine_coords);
				FreeLibrary(hdll);
				break;
			case 10:
				hdll = LoadLibrary(L"coords.dll");
				get_addition_coords_dll = (t_get_addition_coords_dll)GetProcAddress(hdll, "getAdditionCoords");
				addition_coords = (int*)get_addition_coords_dll();
				draw_digit(&ps, hdc, 404, addition_coords);
				FreeLibrary(hdll);
				break;
			case 11:
				hdll = LoadLibrary(L"coords.dll");
				get_decrease_coords_dll = (t_get_decrease_coords_dll)GetProcAddress(hdll, "getDecreaseCoords");
				decrease_coords = (int*)get_decrease_coords_dll();
				draw_digit(&ps, hdc, 202, decrease_coords);
				FreeLibrary(hdll);
				break;
			case 12:
				hdll = LoadLibrary(L"coords.dll");
				get_multiplied_coords_dll = (t_get_multiplied_coords_dll)GetProcAddress(hdll, "getMultipliedCoords");
				multiplied_coords = (int*)get_multiplied_coords_dll();
				draw_digit(&ps, hdc, 606, multiplied_coords);
				FreeLibrary(hdll);
				break;
			case 13:
				hdll = LoadLibrary(L"coords.dll");
				get_divided_coords_dll = (t_get_divided_coords_dll)GetProcAddress(hdll, "getDividedCoords");
				divided_coords = (int*)get_divided_coords_dll();
				draw_digit(&ps, hdc, 324, divided_coords);
				FreeLibrary(hdll);
				break;
			case 14:
				hdll = LoadLibrary(L"coords.dll");
				get_comma_coords_dll = (t_get_comma_coords_dll)GetProcAddress(hdll, "getCommaCoords");
				comma_coords = (int*)get_comma_coords_dll();
				draw_digit(&ps, hdc, 206, comma_coords);
				FreeLibrary(hdll);
				break;
			case 15:
				hdll = LoadLibrary(L"coords.dll");
				get_equal_coords_dll = (t_get_equal_coords_dll)GetProcAddress(hdll, "getEqualCoords");
				equal_coords = (int*)get_equal_coords_dll();
				draw_digit(&ps, hdc, 404, equal_coords);
				FreeLibrary(hdll);
				break;
			}
            EndPaint(hWnd, &ps);
        }
        break;
	case WM_TIMER:
	{
		int wmId = LOWORD(wParam);
		switch (wmId) {
		case ID_TIMER:
			InvalidateRect(hWnd, &rc, false);
			i += 2;
		}
		break;
	}
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