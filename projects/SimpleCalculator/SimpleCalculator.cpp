// SimpleCalculator.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "SimpleCalculator.h"
#include <string>
#include <sstream>
#include <regex>

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
    LoadStringW(hInstance, IDC_SIMPLECALCULATOR, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SIMPLECALCULATOR));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SIMPLECALCULATOR));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_SIMPLECALCULATOR);
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
   // Define the desired width and height of the window
   int windowWidth = 280; // Adjust as needed to fit the calculator layout
   int windowHeight = 310; // Adjust as needed to fit the calculator layout

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
      CW_USEDEFAULT, 0, windowWidth, windowHeight, nullptr, nullptr, hInstance, nullptr);

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
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static std::wstring input = L""; // Store the current input
    static double operand1 = 0, operand2 = 0; // Operands for calculations
    static wchar_t operation = 0; // Stores the current operation (+, -, *, /)
    static HWND hEdit; // Handle to the Edit Control
    WCHAR buffer[256]{};
    double result = 0;
    std::wstringstream wss;
    // Helper function to check if the input is a valid number
    auto isValidNumber = [](const std::wstring& str) -> bool
        {
            std::wregex regex(L"^-?\\d*(\\.\\d+)?$");
            return std::regex_match(str, regex);
        };
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam); // Extract the button ID

        // Parse the menu selections:
        switch (wmId)
        {
        case 2: // Button 0
            input += L"0";
            SetWindowText(hEdit, input.c_str());
            break;
        case 3: // Button 1
            input += L"1";
            SetWindowText(hEdit, input.c_str());
            break;
        case 4: // Button 2
            input += L"2";
            SetWindowText(hEdit, input.c_str());
            break;
        case 5: // Button 3
            input += L"3";
            SetWindowText(hEdit, input.c_str());
            break;
        case 6: // Button 4
            input += L"4";
            SetWindowText(hEdit, input.c_str());
            break;
        case 7: // Button 5
            input += L"5";
            SetWindowText(hEdit, input.c_str());
            break;
        case 8: // Button 6
            input += L"6";
            SetWindowText(hEdit, input.c_str());
            break;
        case 9: // Button 7
            input += L"7";
            SetWindowText(hEdit, input.c_str());
            break;
        case 10: // Button 8
            input += L"8";
            SetWindowText(hEdit, input.c_str());
            break;
        case 11: // Button 9
            input += L"9";
            SetWindowText(hEdit, input.c_str());
            break;
        case 12: // Button "+"
            if (isValidNumber(input))
            {
                operand1 = _wtof(input.c_str()); // Convert the input to a number
                operation = '+'; // Set the operation
                input = L""; // Clear the input
            }
            else
            {
                input = L"Error: Invalid number";
                SetWindowText(hEdit, input.c_str());
            }
            break;
        case 13: // Button "="
            if (isValidNumber(input))
            {
                operand2 = _wtof(input.c_str()); // Get the second operand
                if (operation == '+')
                {
                    result = operand1 + operand2;
                }
                else if (operation == '-')
                {
                    result = operand1 - operand2;
                }
                else if (operation == '*')
                {
                    result = operand1 * operand2;
                }
                else if (operation == '/')
                {
                    if (operand2 != 0)
                    {
                        result = operand1 / operand2;
                    }
                    else
                    {
                        input = L"Error: Division by zero";
                        SetWindowText(hEdit, input.c_str());
                        break;
                    }
                }
				else if (operation == '^')
				{
					result = pow(operand1, operand2);
				}
                // Format the result to remove extra zeros
				wss << result; // Convert the result to a string
                input = wss.str(); // Store the result in the input
				input.erase(input.find_last_not_of(L'0') + 1, std::wstring::npos); // Remove trailing zeros
				if (input.back() == L'.') input.pop_back(); // Remove trailing decimal point
                SetWindowText(hEdit, input.c_str());
            }
            else
            {
                input = L"Error: Invalid number";
                SetWindowText(hEdit, input.c_str());
            }
            break;
        case 14: // Button "C" (Clear)
            input = L""; // Reset everything
            operand1 = operand2 = 0;
            operation = 0;
            SetWindowText(hEdit, input.c_str());
            break;
        case 15: // Button "-"
            if (isValidNumber(input))
            {
                operand1 = _wtof(input.c_str());
                operation = '-';
                input = L"";
            }
            else
            {
                input = L"Error: Invalid number";
                SetWindowText(hEdit, input.c_str());
            }
            break;
        case 16: // Button "*"
            if (isValidNumber(input))
            {
                operand1 = _wtof(input.c_str());
                operation = '*';
                input = L"";
            }
            else
            {
                input = L"Error: Invalid number";
                SetWindowText(hEdit, input.c_str());
            }
            break;
        case 17: // Button "/"
            if (isValidNumber(input))
            {
                operand1 = _wtof(input.c_str());
                operation = '/';
                input = L"";
            }
            else
            {
                input = L"Error: Invalid number";
                SetWindowText(hEdit, input.c_str());
            }
            break;
        case 18: // Button "."
            if (input.find(L'.') == std::wstring::npos)
            {
                input += L".";
                SetWindowText(hEdit, input.c_str());
            }
            break;
        case 19: // Button "Backspace"
            if (!input.empty())
            {
                input.pop_back();
                SetWindowText(hEdit, input.c_str());
            }
            break;
        case 20: // Button "%" (Percentage)
            if (isValidNumber(input))
            {
                double value = _wtof(input.c_str());
                value /= 100;
                input = std::to_wstring(value);
                SetWindowText(hEdit, input.c_str());
            }
            else
            {
                input = L"Error: Invalid number";
                SetWindowText(hEdit, input.c_str());
            }
            break;
        case 21: // Button "^"
            if (isValidNumber(input))
            {
                operand1 = _wtof(input.c_str());
                operation = '^';
                input = L"";
            }
            else
            {
                input = L"Error: Invalid number";
                SetWindowText(hEdit, input.c_str());
            }
            break;
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;

    case WM_CREATE:
    {
        // Define constants for button dimensions and spacing
        const int buttonWidth = 50;
        const int buttonHeight = 30;
        const int buttonSpacing = 10;
        const int startX = 10;
        const int startY = 50;
        // Create the Edit Control for displaying the input/output
        hEdit = CreateWindowW(L"EDIT", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT,
            startX, 10, 4 * buttonWidth + 3 * buttonSpacing, buttonHeight, hWnd, (HMENU)1, hInst, NULL);
        if (!hEdit) return -1;
        // First row: Percent, Power, Clear, Backspace
        HWND hButtonPercent = CreateWindowW(L"BUTTON", L"%", WS_CHILD | WS_VISIBLE, startX, startY, buttonWidth, buttonHeight,
            hWnd, (HMENU)20, hInst, NULL);
        if (!hButtonPercent) return -1;
        HWND hButtonPower = CreateWindowW(L"BUTTON", L"^", WS_CHILD | WS_VISIBLE, startX + buttonWidth + buttonSpacing, startY, buttonWidth, buttonHeight,
            hWnd, (HMENU)21, hInst, NULL);
        if (!hButtonPower) return -1;
		HWND hButtonClear = CreateWindowW(L"BUTTON", L"C", WS_CHILD | WS_VISIBLE, startX + 2 * (buttonWidth + buttonSpacing), startY, buttonWidth, buttonHeight,
            hWnd, (HMENU)14, hInst, NULL);
        if (!hButtonClear) return -1;
		HWND hButtonBackspace = CreateWindowW(L"BUTTON", L"\u232B", WS_CHILD | WS_VISIBLE, startX + 3 * (buttonWidth + buttonSpacing), startY, buttonWidth, buttonHeight,
            hWnd, (HMENU)19, hInst, NULL);
        if (!hButtonBackspace) return -1;
        // Second row: 7, 8, 9, /
        HWND hButton7 = CreateWindowW(L"BUTTON", L"7", WS_CHILD | WS_VISIBLE, startX, startY + buttonHeight + buttonSpacing, buttonWidth, buttonHeight,
            hWnd, (HMENU)9, hInst, NULL);
        if (!hButton7) return -1;
        HWND hButton8 = CreateWindowW(L"BUTTON", L"8", WS_CHILD | WS_VISIBLE, startX + buttonWidth + buttonSpacing, startY + buttonHeight + buttonSpacing, buttonWidth, buttonHeight,
            hWnd, (HMENU)10, hInst, NULL);
        if (!hButton8) return -1;
        HWND hButton9 = CreateWindowW(L"BUTTON", L"9", WS_CHILD | WS_VISIBLE, startX + 2 * (buttonWidth + buttonSpacing), startY + buttonHeight + buttonSpacing, buttonWidth, buttonHeight,
            hWnd, (HMENU)11, hInst, NULL);
        if (!hButton9) return -1;
        HWND hButtonDivide = CreateWindowW(L"BUTTON", L"/", WS_CHILD | WS_VISIBLE, startX + 3 * (buttonWidth + buttonSpacing), startY + buttonHeight + buttonSpacing, buttonWidth, buttonHeight,
            hWnd, (HMENU)17, hInst, NULL);
        if (!hButtonDivide) return -1;
        // Third row: 4, 5, 6, *
        HWND hButton4 = CreateWindowW(L"BUTTON", L"4", WS_CHILD | WS_VISIBLE, startX, startY + 2 * (buttonHeight + buttonSpacing), buttonWidth, buttonHeight,
            hWnd, (HMENU)6, hInst, NULL);
        if (!hButton4) return -1;
        HWND hButton5 = CreateWindowW(L"BUTTON", L"5", WS_CHILD | WS_VISIBLE, startX + buttonWidth + buttonSpacing, startY + 2 * (buttonHeight + buttonSpacing), buttonWidth, buttonHeight,
            hWnd, (HMENU)7, hInst, NULL);
        if (!hButton5) return -1;
        HWND hButton6 = CreateWindowW(L"BUTTON", L"6", WS_CHILD | WS_VISIBLE, startX + 2 * (buttonWidth + buttonSpacing), startY + 2 * (buttonHeight + buttonSpacing), buttonWidth, buttonHeight,
            hWnd, (HMENU)8, hInst, NULL);
        if (!hButton6) return -1;
        HWND hButtonMultiply = CreateWindowW(L"BUTTON", L"*", WS_CHILD | WS_VISIBLE, startX + 3 * (buttonWidth + buttonSpacing), startY + 2 * (buttonHeight + buttonSpacing), buttonWidth, buttonHeight,
            hWnd, (HMENU)16, hInst, NULL);
        if (!hButtonMultiply) return -1;
        // Fourth row: 1, 2, 3, -
        HWND hButton1 = CreateWindowW(L"BUTTON", L"1", WS_CHILD | WS_VISIBLE, startX, startY + 3 * (buttonHeight + buttonSpacing), buttonWidth, buttonHeight,
            hWnd, (HMENU)3, hInst, NULL);
        if (!hButton1) return -1;
        HWND hButton2 = CreateWindowW(L"BUTTON", L"2", WS_CHILD | WS_VISIBLE, startX + buttonWidth + buttonSpacing, startY + 3 * (buttonHeight + buttonSpacing), buttonWidth, buttonHeight,
            hWnd, (HMENU)4, hInst, NULL);
        if (!hButton2) return -1;
        HWND hButton3 = CreateWindowW(L"BUTTON", L"3", WS_CHILD | WS_VISIBLE, startX + 2 * (buttonWidth + buttonSpacing), startY + 3 * (buttonHeight + buttonSpacing), buttonWidth, buttonHeight,
            hWnd, (HMENU)5, hInst, NULL);
        if (!hButton3) return -1;
        HWND hButtonMinus = CreateWindowW(L"BUTTON", L"-", WS_CHILD | WS_VISIBLE, startX + 3 * (buttonWidth + buttonSpacing), startY + 3 * (buttonHeight + buttonSpacing), buttonWidth, buttonHeight,
            hWnd, (HMENU)15, hInst, NULL);
        if (!hButtonMinus) return -1;
        // Fifth row: 0, ., =, +
        HWND hButton0 = CreateWindowW(L"BUTTON", L"0", WS_CHILD | WS_VISIBLE, startX, startY + 4 * (buttonHeight + buttonSpacing), buttonWidth, buttonHeight,
            hWnd, (HMENU)2, hInst, NULL);
        if (!hButton0) return -1;
        HWND hButtonDecimal = CreateWindowW(L"BUTTON", L".", WS_CHILD | WS_VISIBLE, startX + buttonWidth + buttonSpacing, startY + 4 * (buttonHeight + buttonSpacing), buttonWidth, buttonHeight,
            hWnd, (HMENU)18, hInst, NULL);
        if (!hButtonDecimal) return -1;
        HWND hButtonEquals = CreateWindowW(L"BUTTON", L"=", WS_CHILD | WS_VISIBLE, startX + 2 * (buttonWidth + buttonSpacing), startY + 4 * (buttonHeight + buttonSpacing), buttonWidth, buttonHeight,
            hWnd, (HMENU)13, hInst, NULL);
        if (!hButtonEquals) return -1;
        HWND hButtonPlus = CreateWindowW(L"BUTTON", L"+", WS_CHILD | WS_VISIBLE, startX + 3 * (buttonWidth + buttonSpacing), startY + 4 * (buttonHeight + buttonSpacing), buttonWidth, buttonHeight,
            hWnd, (HMENU)12, hInst, NULL);
        if (!hButtonPlus) return -1;
        return 0;
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
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
