// Dear ImGui: standalone example application for DirectX 9
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs

#include "imgui.h"
#include "imgui_impl_dx9.h"
#include "imgui_impl_win32.h"
#include <d3d9.h>
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <tchar.h>
#include <stdio.h>
#include <iostream>
#include <dwmapi.h>
#include <d3dx9.h>
#include <chrono>
#include <conio.h>

#include <Psapi.h>
#include <sstream>
#include <Windows.h>
#include <string>
#pragma comment(lib, "d3dx9.lib")
// Data
int switchGun = 1;
int switchScope = 1;
int switchBarrel = 1;
static int X = 1;
static int Y = 1;
int switchHipFire = 1;
int switchUpgrade = 1;
char* weapon = "       assault rifle";
char* scope = "            none";
char* barrel = "           boost";
char* miniweapon = "       assault rifle";
char* miniscope = "            none";
char* minibarrel = "assault rifle";
char* upgradeMat = "assault rifle";
char* keyType = "weapons";
int switchKeyType = 1;

int randomisationStrength = 0;

char* hipfirechar = "           nigger";
bool scriptEnabled = false;
bool ttsEnabled = false;
int xComp = 100;
int yComp = 100;
const char* scriptEnabledChar = "f2";
bool showMenu = true;
const char* keyf = "none";
const char* keyFurnanceSplit = "none";
const char* keyLargeFurnanceSplit = "none";
const char* AutoUpgrade = "none";
const char* crosshairShowChar ="   always   ";
int controlCrosshairShow = 1;
const char* fastCodeChar = "none";
int fastCodeLockVKKey;
bool nextFastCode = false;
bool fastListeningtoKey = false;
int furnaceSplitKey;
int largefurnaceSplitKey;
int autoupgradeKey;
bool listentoKeyFurnace = false;
bool listentoKeyLargeFurnace = false;
bool listentoKeyAutoUpgrade = false;
bool islisteningScriptEnabled = false;
int scriptOnKey = VK_F2;
bool listeningtoKey = false;

bool listentokeyAk = false;
int akscripton;
bool nextOn = false;
bool nextAk = false;

bool nextFurncace = false;
bool nextLargeFurnace = false;
bool nextAutoup = false;
bool randomisation = false;
int randXPercent = 0;
int randYPercent = 0;

bool countAmmo = false;
bool forceFullAuto = false;
bool crosshair = false;
bool miniMenu = false;
bool highPerformance = true;
bool furnaceSplitter = false;
bool largeFurnaceSplitter = false;
bool autoUpgrade;
bool crosshairOnAds = false;
int firstDig = 0;
int secDig = 0;
int thirDig = 0;
int fourDig = 0;
bool fastcodelock = false;
bool antiafk = false;

float fov = 90;
float sensitivity = 0.5;



int akToggleKey = 14743;
int lrToggleKey = 14743;
int mp5ToggleKey = 14743;
int customToggleKey = 14743;
int thompsonToggleKey = 14743;
int m249ToggleKey = 14743;
int sarToggleKey = 14743;
int m39ToggleKey = 14743;
int pythonToggleKey = 14743;
int sapToggleKey = 14743;
int m92ToggleKey = 14743;
int revolverToggleKey = 14743;
int nailgunToggleKey = 14743;
int menuKey = VK_INSERT;
int exitKey = VK_END;
int eightXKey = 14743;
int sixteenXKey = 14743;
int holosightKey = 14743;
int simpleKey = 14743;
int ironsightKey = 14743;
int muzzzleBoostKey = 14743;
int silencerKey = 14743;
int nobarrelKey = 14743;
#include <sapi.h>

ISpVoice* pVoice = NULL;
HRESULT hr;
std::wstring voiceInput;

bool nextAK = false;
bool nextLR = false;
bool nextMP5 = false;
bool nextCustom = false;
bool nextThompson = false;
bool nextM249 = false;
bool nextSar = false;
bool nextM39 = false;
bool nextPython = false;
bool nextSAP = false;
bool nextM92 = false;
bool nextRevolver = false;
bool nextNailgun = false;
bool nextExit = false;
bool nextMenuKey = false;
bool isCursorShowing;
static int miniMenuNav = 0;
int reloadHotKey = 82;
const char* crosshairStyle = "dot";
int crosshairStyleNum = 1;
const char* akKeyChar = "none";
const char* lrKeyChar = "none";
const char* mp5KeyChar = "none";
const char* customKeyChar = "none";
const char* thompsonKeyChar = "none";
const char* m249KeyChar = "none";
const char* sarKeyChar = "none";
const char* m39KeyChar = "none";
const char* pythonKeyChar = "none";
const char* sapKeyChar = "none";
const  char* m92KeyChar = "none";
const char* revolverKeyChar = "none";
const char* nailgunKeyChar = "none";
const char* menuKeyChar = "ins";
const char* exitKeyChar = "end";
const char* eightXChar = "none";
const char* sixteenXChar = "none";
const char* ironsightChar = "none";
const char* holosightChar = "none";
const char* handmmadeChar = "none";
const char* muzzleBosstChar = "none";
const char* silencerChar = "none";
const char* noBarrelChar = "none";
const char* countAmmoChar = "r";
bool islisteningEightX = false;
bool islisteningSixteenX = false;
bool islisteningBoost = false;
bool islisteningSilencer = false;
bool islisteningCountAmmo = false;
bool islisteningHandmade = false;
bool islisteningHolosight = false;
bool islisteningNoSite = false;
bool islisteningNoBarrel = false;
bool islisteningExit = false;
bool islisteningMenu = false;
bool islisteningAK = false;
bool islisteningLR = false;
bool islisteningMP5 = false;
bool islisteningCUSTOM = false;
bool islisteningTHOMPSON = false;
bool islisteningM249 = false;
bool islisteningSAR = false;
bool islisteningM39 = false;
bool islisteningPYTHON = false;
bool islisteningSAP = false;
bool islisteningM92 = false;
bool islisteningREVOLVER = false;
bool islisteningNAILGUN = false;
int randomisationX = 0;
int randomisationY = 0;

int switchGunKey = 1;
LPDIRECT3DVERTEXBUFFER9 g_pVB;    // Buffer to hold vertices
LPDIRECT3DINDEXBUFFER9  g_pIB;
static LPDIRECT3D9              g_pD3D = NULL;
static LPDIRECT3DDEVICE9        g_pd3dDevice = NULL;
static D3DPRESENT_PARAMETERS    g_d3dpp = {};
int crosshairOpacity = 100;

// Forward declarations of helper functions
bool CreateDeviceD3D(HWND hWnd);
void CleanupDeviceD3D();
void ResetDevice();
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

float aids = 5.0f;
// Main code
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#pragma comment(lib, "Dwmapi.lib")

bool next = false;

IDirect3DDevice9* crosshairDevice;
D3DVIEWPORT9* pViewport;


void DrawRect(IDirect3DDevice9* dev, int x, int y, int w, int h, D3DCOLOR color)
{
    D3DRECT BarRect = { x, y, x + w, y + h };
    g_pd3dDevice->Clear(1, &BarRect, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, color, 0, 0);
}





ImVec4* colors;
void ImGui::StyleColorsDark(ImGuiStyle* dst)
{
    ImGuiStyle* style = dst ? dst : &ImGui::GetStyle();
    colors = style->Colors;

    colors[ImGuiCol_Text] = ImVec4(1, 1.00f, 1.00f, 1.00f);
    colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
    colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 0.94f);
    colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f); colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
    colors[ImGuiCol_Border] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
    colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    colors[ImGuiCol_FrameBg] = ImVec4(0.19, 0.19, 0.19, 1);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.3, 0.3, 0.3, 1);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.4, 0.4, 0.4, 1);
    colors[ImGuiCol_TitleBg] = ImVec4(0.1, 0.1, 0.1, 1.00f);
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.1, 0.1, 0.1, 1.00f);
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.62, 0.12, 0.94, 1.00f);
    colors[ImGuiCol_MenuBarBg] = ImVec4(0.62, 0.12, 0.94, 1.00f);
    colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
    colors[ImGuiCol_CheckMark] = ImVec4(1, 1, 1, 0.7);
    colors[ImGuiCol_SliderGrab] = ImVec4(1, 1, 1, 0.7);
    colors[ImGuiCol_SliderGrabActive] = ImVec4(1, 1, 1, 0.7);
    colors[ImGuiCol_Button] = ImVec4(0.19, 0.19, 0.19, 1);
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.3, 0.3, 0.3, 1);
    colors[ImGuiCol_ButtonActive] = ImVec4(0.19, 0.19, 0.19, 1);
    colors[ImGuiCol_Header] = ImVec4(0.26f, 0.59f, 0.98f, 0.31f);
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
    colors[ImGuiCol_HeaderActive] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_Separator] = ImVec4(0.1, 0.1, 0.1, 1.00f);
    colors[ImGuiCol_SeparatorHovered] = ImVec4(1, 1, 1, 1);
    colors[ImGuiCol_SeparatorActive] = ImVec4(1, 1, 1, 1);
    colors[ImGuiCol_ResizeGrip] = ImVec4(0.26f, 0.59f, 0.98f, 0.25f);
    colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
    colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);

    colors[ImGuiCol_TabHovered] = colors[ImGuiCol_HeaderHovered];

    colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
    colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
    colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
    colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
    colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
    colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
    colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
    colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
    colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
}
bool secRecoilCat = true;
bool secExtraCat = false;
bool secMiscCat = false;
bool secKeysCat = false;
IDirect3DDevice9* dev;
#include <vector>
#include <codecvt>
struct vertex
{
    FLOAT x, y, z, rhw;
    DWORD color;
};
enum circle_type { full, half, quarter };
enum text_alignment { lefted, centered, righted };

#include <fstream>
#include <string>
bool midFunction = false;
std::string tchar_to_string(const TCHAR* tstr)
{
#ifdef _UNICODE
    std::wstring wstr = tstr;
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
    std::string str = converter.to_bytes(wstr);
#else
    std::string str = tstr;
#endif
    return str;
}
#include <locale>
std::string soom;
void updateSensFov() {
    for (;;) {


        TCHAR filename[128];
        HANDLE processHandle = NULL;

        HWND hwndd = FindWindowA(0, "Rust");
        DWORD IDd;
        GetWindowThreadProcessId(hwndd, &IDd);





        processHandle = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, IDd);
        if (processHandle != NULL) {


            if (GetModuleFileNameEx(processHandle, NULL, filename, MAX_PATH) != 0) {

                soom = tchar_to_string(filename);


            }


            std::string rest = "cfg\\client.cfg";

            for (int i = 0; i < 14; i++) {
                soom.pop_back();
            }
            std::ifstream file;
            std::string line;
            int lineSens = 0;
            int lineFOV = 0;
            file.open(soom + rest);

            if (!file) {

                exit(1);   // call system to stop
            }


            while (true) {
                std::getline(file, line);


                lineSens++;


                if (lineSens == 68) { // makes sure we read the correct line of the .cfg file
                    std::string fovString = line;
                    size_t pos = fovString.find(" ");
                    fovString = fovString.substr(pos + 2);


                    std::stringstream fovConv(fovString);

                    fovConv >> fov;



                }
                if (lineSens == 89) { // makes sure we read the correct line of the .cfg file

                    std::string sensString = line;
                    size_t pos = sensString.find(" ");

                    sensString = sensString.substr(pos + 2);
                    std::stringstream sensConv(sensString);

                    sensConv >> sensitivity;

                    break;


                }
                Sleep(10);

            }













            Sleep(10);
        }
        Sleep(200);
    }
}

D3DCOLOR ButtonHovered = D3DCOLOR_XRGB(230, 230, 230);

D3DCOLOR BarCol = D3DCOLOR_XRGB(15, 15, 15);
D3DCOLOR midBarCol = D3DCOLOR_XRGB(20, 20, 20);
D3DCOLOR Black = D3DCOLOR_XRGB(0, 1, 0);
bool recoilEnabled = false;
bool blatantEnabled = true;
bool autoDetection = false;

HFONT hFont = (HFONT)GetStockObject(SYSTEM_FONT);
LPD3DXFONT pFontSmall = NULL;

LPD3DXFONT pFontBig = NULL;

int menuX = 300;
int menuY = 10;
int menuNav = 1;

bool DrawMessage(LPD3DXFONT font, unsigned int x, unsigned int y, int alpha, LPCSTR Message)

{


    // Create a colour for the text
    D3DCOLOR fontColor = D3DCOLOR_ARGB(alpha, 240, 240, 240);
    RECT rct; //Font
    rct.left = x;
    rct.right = 1680;
    rct.top = y;
    rct.bottom = rct.top + 200;
    font->DrawTextA(NULL, Message, -1, &rct, 0, fontColor);
    return true;
}


void DrawRectA(int x, int y, int w, int h, D3DCOLOR color)
{
    D3DRECT BarRect = { x, y, x + w, y + h };
    g_pd3dDevice->Clear(1, &BarRect, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, color, 0, 0);

}
void DrawRect(int x, int y, int w, int h, D3DCOLOR color)
{
    DrawRectA(x - 1, y - 1, w + 2, h + 2, Black);
    D3DRECT BarRect = { x, y, x + w, y + h };
    g_pd3dDevice->Clear(1, &BarRect, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, color, 0, 0);


}

void DrawRectAA(int x, int y, int w, int h, D3DCOLOR color)
{
    DrawRectA(x - 1, y - 1, w + 1, h + 2, Black);
    D3DRECT BarRect = { x, y, x + w, y + h };
    g_pd3dDevice->Clear(1, &BarRect, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, color, 0, 0);


}
D3DCOLOR midBar = D3DCOLOR_XRGB(40, 40, 40);
void drawCharSwitchCat(const char* label, const char* switcher, int id,int x, int y, int& manage) {


    const char* onOff = "off";
    if (id == menuNav) {
        midFunction = true;
        DrawRect(x, y, 150, 15, midBar);
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
            manage++;
            Sleep(100);
        }
        if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
            manage--;
            Sleep(100);
        }
    }
    else {
        midFunction = false;
        DrawRect(x, y, 150, 15, midBarCol);
    }


    DrawMessage(pFontSmall, x +5, y + 1, 255, label);
    DrawMessage(pFontSmall,x+ 50, y + 1, 255, switcher);


}

void DrawBar(int x, int y, int w, int h, D3DCOLOR color) {


    DrawRect(X + x, Y + y, 198, h - 2, color);
}




D3DCOLOR switchBut = D3DCOLOR_XRGB(60, 60, 60);
D3DCOLOR but1Col = D3DCOLOR_XRGB(60, 60, 60);
D3DCOLOR but2Col = D3DCOLOR_XRGB(60, 60, 60);




int aidss;



void speak(std::wstring say) {
    if (FAILED(::CoInitialize(NULL)))
    {
    }


    HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void**)&pVoice);
    if (SUCCEEDED(hr))
    {



        hr = pVoice->Speak((L"<voice required='Gender = Female; Age != Child'> " + say).c_str(), SPF_IS_XML, NULL);
        pVoice->Release();
        pVoice = NULL;
    }
    ::CoUninitialize();
}
\
int spacing = 0;
D3DCOLOR ButtonColTicked = D3DCOLOR_XRGB(237, 36, 116);
D3DCOLOR ButtonColUnTicked = D3DCOLOR_XRGB(22, 22, 22);
D3DCOLOR a252525 = D3DCOLOR_XRGB(25, 25, 25);
D3DCOLOR a40 = D3DCOLOR_XRGB(40, 40, 40);
POINT cursorPos;
D3DCOLOR charSwitchButton = D3DCOLOR_XRGB(60, 60, 60);
D3DCOLOR charSwitch = D3DCOLOR_XRGB(50, 50, 50);

void CdrawCharSwitcher( int& manager) {
    if (manager > 9) manager = 9;
    if (manager < 1) manager = 1;
    std::string value_string(16, '\0');

    auto written = std::snprintf(&value_string[0], value_string.size(), "%d", manager);
    value_string.resize(written);
    spacing += 19;
    GetCursorPos(&cursorPos);
    if (cursorPos.x > X + 18 && cursorPos.x < X + 20 + 18 && cursorPos.y > Y + spacing + 16 && cursorPos.y < Y + spacing + 16 + 15) {
        DrawRect(X + 20, Y + spacing + 17, 15, 12, ButtonColTicked);
        if (GetAsyncKeyState(VK_LBUTTON)) {
            manager--;
            Sleep(100);
        }
    }
    else {
        DrawRect(X + 20, Y + spacing + 17, 15, 12, charSwitchButton);
    }


    DrawRect(X + 40, Y + spacing + 1 + 16, 138, 12, charSwitch);

    if (cursorPos.x > X + 178 && cursorPos.x < X + 178 + 18 && cursorPos.y > Y + spacing + 16 && cursorPos.y < Y + spacing + 16 + 15) {
        DrawRect(X + 183, Y + spacing + 17, 15, 12, ButtonColTicked);
        if (GetAsyncKeyState(VK_LBUTTON)) {
            manager++;
            Sleep(100);
        }
    }
    else {
        DrawRect(X + 183, Y + spacing + 17, 15, 12, charSwitchButton);
    }

    DrawMessage(pFontSmall, X + 110, Y + spacing + 16, 255, value_string.c_str());
    DrawMessage(pFontSmall, X + 23, Y + spacing + 16, 255, " -");
    DrawMessage(pFontSmall, X + 184, Y + spacing + 16, 255, " +");
}
void drawCharSwitcher(const char* switcher, int& manager) {
    spacing += 19;
    GetCursorPos(&cursorPos);
    if (cursorPos.x > X + 18 && cursorPos.x < X + 20 + 18 && cursorPos.y > Y + spacing + 16 && cursorPos.y < Y + spacing + 16 + 15) {
        DrawRect(X + 20, Y + spacing + 17, 15, 12, charSwitchButton);
        if (GetAsyncKeyState(VK_LBUTTON)) {
            manager--;
            Sleep(100);
        }
    }
    else {
        DrawRect(X + 20, Y + spacing + 17, 15, 12, charSwitchButton);
    }


    DrawRect(X + 40, Y + spacing + 1 + 16, 138, 12, charSwitch);

    if (cursorPos.x > X + 178 && cursorPos.x < X + 178 + 18 && cursorPos.y > Y + spacing + 16 && cursorPos.y < Y + spacing + 16 + 15) {
        DrawRect(X + 183, Y + spacing + 17, 15, 12, charSwitchButton);
        if (GetAsyncKeyState(VK_LBUTTON)) {
            manager++;
            Sleep(100);
        }
    }
    else {
        DrawRect(X + 183, Y + spacing + 17, 15, 12, charSwitchButton);
    }

    DrawMessage(pFontSmall, X + 55, Y + spacing + 16, 255, switcher);
    DrawMessage(pFontSmall, X + 23, Y + spacing + 16, 255, " -");
    DrawMessage(pFontSmall, X + 184, Y + spacing + 16, 255, " +");
}

void drawCharSwitcherKey(const char* switcher, int& manager, int y ) {
    spacing += 19;
    GetCursorPos(&cursorPos);
    if (cursorPos.x > X + 18 && cursorPos.x < X + 20 + 18 && cursorPos.y > Y + y + 16 && cursorPos.y < Y + y + 16 + 15) {
        DrawRect(X + 20, Y + y + 17, 15, 12, ButtonColTicked);
        if (GetAsyncKeyState(VK_LBUTTON)) {
            manager--;
            Sleep(100);
        }
    }
    else {
        DrawRect(X + 20, Y + y + 17, 15, 12, charSwitchButton);
    }


    DrawRect(X + 40, Y + y + 1 + 16, 138, 12, charSwitch);

    if (cursorPos.x > X + 178 && cursorPos.x < X + 178 + 18 && cursorPos.y > Y + y + 16 && cursorPos.y < Y + y + 16 + 15) {
        DrawRect(X + 183, Y + y + 17, 15, 12, ButtonColTicked);
        if (GetAsyncKeyState(VK_LBUTTON)) {
            manager++;
            Sleep(100);
        }
    }
    else {
        DrawRect(X + 183, Y + y + 17, 15, 12, charSwitchButton);
    }

    DrawMessage(pFontSmall, X + 55, Y + y + 16, 255, switcher);
    DrawMessage(pFontSmall, X + 23, Y + y + 16, 255, " -");
    DrawMessage(pFontSmall, X + 184, Y + y + 16, 255, " +");
}
void drawCheckBox(const char* label, bool& change) {

    GetCursorPos(&cursorPos);
    spacing += 15;


   
    if (change) {



        DrawRect(X + 20, Y + 21 + spacing, 8, 8, ButtonColTicked);
    }
    else {

        DrawRect(X + 20, Y + 21 + spacing, 8, 8, ButtonColUnTicked);

    }
    if (cursorPos.x > X + 20 && cursorPos.x < X + 80 && cursorPos.y > Y + 21 + spacing && cursorPos.y < Y + 22 + spacing + 10) {
        if (!change) {
            DrawRect(X + 20, Y + 21 + spacing, 8, 8, a40);
        }
      
        if (GetAsyncKeyState(VK_LBUTTON)) {
            change = !change;
            Sleep(100);
        }
    }
    DrawMessage(pFontSmall, X + 35, Y + spacing + 18, 255, label);



}

bool Button(int x, int y, int w, int h, const char* name, bool check) {

    GetCursorPos(&cursorPos);

    if (cursorPos.x > X + x && cursorPos.x < X + x + w && cursorPos.y > Y + y && cursorPos.y < Y + y + h) {
        DrawRect(X + x, Y + y, w, h, a252525);
        if (GetAsyncKeyState(VK_LBUTTON)) {
            DrawRect(X + x, Y + y, w, h, a252525);
            return true;
        }
    }
    else {
        if (check) {
            DrawRect(X + x, Y + y, w, h, a40);
        }
        else {
            DrawRect(X + x, Y + y, w, h, a252525);
        }
       
    }
    DrawMessage(pFontSmall, X + x + 10, Y + y + 1, 255, name);
    return false;
}
bool ButtonA(int x, int y, int w, int h, const char* name, bool check, D3DCOLOR color) {

    GetCursorPos(&cursorPos);

    if (cursorPos.x > X + x && cursorPos.x < X + x + w && cursorPos.y > Y + y && cursorPos.y < Y + y + h) {
       
        DrawRectA(X + x, Y + y, w, h, color);
        if (GetAsyncKeyState(VK_LBUTTON)) {
           
            return true;
        }
    }
    else {
        if (check) {
            DrawRectA(X + x, Y + y, w, h, color);
        }
        else {
            DrawRectA(X + x, Y + y, w, h, color);
        }

    }
    DrawMessage(pFontSmall, X + x + 10, Y + y + 1, 255, name);
    return false;
}
void keyBindSwap(const char*& key, bool& listeningtoKey, int& scriptOnKey, int x, int y, int w, int h, const char* name, bool showname)
{

    if (showname) {
        DrawMessage(pFontSmall, X + x- 10, Y + y - 15, 255, name);
    }
    next = Button(x, y, w, h, key, NULL);

    if (next) {
        listeningtoKey = true;

    }

    if (listeningtoKey) {
        key = "   ...";
    }
    if (GetAsyncKeyState(VK_END) && listeningtoKey) {
        key = "end";
        scriptOnKey = VK_END;
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(VK_HOME) && listeningtoKey) {
        key = "home";
        scriptOnKey = VK_HOME;
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(VK_DELETE) && listeningtoKey) {
        key = "del";
        scriptOnKey = VK_DELETE;
        listeningtoKey = false; Sleep(100);
    }



    if (GetAsyncKeyState(81) && listeningtoKey) {
        key = "pdown";
        scriptOnKey = 81;
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(73) && listeningtoKey) {
        key = "pup";
        scriptOnKey = 81;
        listeningtoKey = false; Sleep(100);
    }




    if (GetAsyncKeyState(VK_ESCAPE) && listeningtoKey) {
        key = "none";
        scriptOnKey = 12386126162;
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(VK_F1) && listeningtoKey)
    {
        scriptOnKey = VK_F1;
        key = "f1";
        listeningtoKey = false; Sleep(100);



    }
    if (GetAsyncKeyState(VK_F2) && listeningtoKey)
    {
        scriptOnKey = VK_F2;
        key = "f2";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(VK_F3) && listeningtoKey)
    {
        scriptOnKey = VK_F3;
        key = "f3";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(VK_F4) && listeningtoKey)
    {
        scriptOnKey = VK_F4;
        key = "f4";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(VK_F5) && listeningtoKey)
    {
        scriptOnKey = VK_F5;
        key = "f5";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(VK_F6) && listeningtoKey)
    {
        scriptOnKey = VK_F6;
        key = "f6";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(VK_F7) && listeningtoKey)
    {
        scriptOnKey = VK_F7;
        key = "f7";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(VK_F8) && listeningtoKey)
    {
        scriptOnKey = VK_F8;
        key = "f8";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(VK_F9) && listeningtoKey)
    {
        scriptOnKey = VK_F9;
        key = "f9";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(VK_F10) && listeningtoKey)
    {
        scriptOnKey = VK_F10;
        key = "f10";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(VK_F11) && listeningtoKey)
    {
        scriptOnKey = VK_F11;
        key = "f11";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(VK_F12) && listeningtoKey)
    {
        scriptOnKey = VK_F12;
        key = "f12";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(65) && listeningtoKey)
    {
        scriptOnKey = 65;
        key = "a";
        listeningtoKey = false; Sleep(100);

    }
    if (GetAsyncKeyState(66) && listeningtoKey)
    {
        scriptOnKey = 66;
        key = "b";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(67) && listeningtoKey)
    {
        scriptOnKey = 67;
        key = "c";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(68) && listeningtoKey)
    {
        scriptOnKey = 68;
        key = "d";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(69) && listeningtoKey)
    {
        scriptOnKey = 69;
        key = "e";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(70) && listeningtoKey)
    {
        scriptOnKey = 70;
        key = "f";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(71) && listeningtoKey)
    {
        scriptOnKey = 71;
        key = "g";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(72) && listeningtoKey)
    {
        scriptOnKey = 72;
        key = "h";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(73) && listeningtoKey)
    {
        scriptOnKey = 73;
        key = "i";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(74) && listeningtoKey)
    {
        scriptOnKey = 74;
        key = "j";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(75) && listeningtoKey)
    {
        scriptOnKey = 75;
        key = "k";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(76) && listeningtoKey)
    {
        scriptOnKey = 76;
        key = "l";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(77) && listeningtoKey)
    {
        scriptOnKey = 77;
        key = "m";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(78) && listeningtoKey)
    {
        scriptOnKey = 78;
        key = "n";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(79) && listeningtoKey)
    {
        scriptOnKey = 79;
        key = "o";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(80) && listeningtoKey)
    {
        scriptOnKey = 80;
        key = "p";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(81) && listeningtoKey)
    {
        scriptOnKey = 81;
        key = "q";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(82) && listeningtoKey)
    {
        scriptOnKey = 82;
        key = "r";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(83) && listeningtoKey)
    {
        scriptOnKey = 83;
        key = "s";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(84) && listeningtoKey)
    {
        scriptOnKey = 84;
        key = "t";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(85) && listeningtoKey)
    {
        scriptOnKey = 85;
        key = "u";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(86) && listeningtoKey)
    {
        scriptOnKey = 86;
        key = "v";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(87) && listeningtoKey)
    {
        scriptOnKey = 87;
        key = "w";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(88) && listeningtoKey)
    {
        scriptOnKey = 88;
        key = "x";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(89) && listeningtoKey)
    {
        scriptOnKey = 89;
        key = "y";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(90) && listeningtoKey)
    {
        scriptOnKey = 90;
        key = "z";
        listeningtoKey = false; Sleep(100);
    }

    //---------------------------------------------------------

    if (GetAsyncKeyState(VK_NUMPAD0) && listeningtoKey)
    {
        scriptOnKey = VK_NUMPAD0;
        key = "num0";
        listeningtoKey = false; Sleep(100);
    }


    if (GetAsyncKeyState(VK_NUMPAD1) && listeningtoKey)
    {
        scriptOnKey = VK_NUMPAD1;
        key = "num1";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(VK_NUMPAD2) && listeningtoKey)
    {
        scriptOnKey = VK_NUMPAD2;
        key = "num2";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(VK_NUMPAD3) && listeningtoKey)
    {
        scriptOnKey = VK_NUMPAD3;
        key = "num3";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(VK_NUMPAD4) && listeningtoKey)
    {
        scriptOnKey = VK_NUMPAD4;
        key = "num4";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(VK_NUMPAD5) && listeningtoKey)
    {
        scriptOnKey = VK_NUMPAD5;
        key = "num5";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(VK_NUMPAD6) && listeningtoKey)
    {
        scriptOnKey = VK_NUMPAD6;
        key = "num6";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(VK_NUMPAD7) && listeningtoKey)
    {
        scriptOnKey = VK_NUMPAD7;
        key = "num7";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(VK_NUMPAD8) && listeningtoKey)
    {
        scriptOnKey = VK_NUMPAD8;
        key = "num8";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(VK_NUMPAD9) && listeningtoKey)
    {
        scriptOnKey = VK_NUMPAD9;
        key = "num9";
        listeningtoKey = false; Sleep(100);
    }
    //----------------------------------------------------------
    if (GetAsyncKeyState(48) && listeningtoKey)
    {
        scriptOnKey = 48;
        key = "0";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(49) && listeningtoKey)
    {
        scriptOnKey = 49;
        key = "1";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(50) && listeningtoKey)
    {
        scriptOnKey = 50;
        key = "2";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(51) && listeningtoKey)
    {
        scriptOnKey = 51;
        key = "3";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(52) && listeningtoKey)
    {
        scriptOnKey = 52;
        key = "4";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(53) && listeningtoKey)
    {
        scriptOnKey = 53;
        key = "5";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(54) && listeningtoKey)
    {
        scriptOnKey = 54;
        key = "6";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(55) && listeningtoKey)
    {
        scriptOnKey = 55;
        key = "7";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(56) && listeningtoKey)
    {
        scriptOnKey = 56;
        key = "8";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(57) && listeningtoKey)
    {
        scriptOnKey = 57;
        key = "9";
        listeningtoKey = false; Sleep(100);
    }

    //----------------------------------

    if (GetAsyncKeyState(VK_OEM_4) && listeningtoKey)
    {
        scriptOnKey = VK_OEM_4;
        key = "[";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(VK_OEM_6) && listeningtoKey)
    {
        scriptOnKey = VK_OEM_6;
        key = "]";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(VK_OEM_5) && listeningtoKey)
    {
        scriptOnKey = VK_OEM_5;
        key = "back";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(VK_OEM_1) && listeningtoKey)
    {
        scriptOnKey = VK_OEM_1;
        key = ";";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(VK_OEM_COMMA) && listeningtoKey)
    {
        scriptOnKey = VK_OEM_COMMA;
        key = ",";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(61) && listeningtoKey)
    {
        scriptOnKey = 61;
        key = "=";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(45) && listeningtoKey)
    {
        scriptOnKey = 45;
        key = "-";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(VK_LCONTROL) && listeningtoKey)
    {
        scriptOnKey = VK_LCONTROL;
        key = "lctrl";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(VK_RCONTROL) && listeningtoKey)
    {
        scriptOnKey = VK_RCONTROL;
        key = "rctrl";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(VK_RSHIFT) && listeningtoKey)
    {
        scriptOnKey = VK_RSHIFT;
        key = "rshift";
        listeningtoKey = false; Sleep(100);
    }







}
bool isHeld = false;
void drawSlider(const char* label, int& change, int min, int max) {


    spacing += 28;
    int sliderPosX = 50;
    std::string value_string(16, '\0');

    auto written = std::snprintf(&value_string[0], value_string.size(), "%d.0", change);

    if (((cursorPos.x >= X + 18 && cursorPos.x <= X + 23 + 178 && cursorPos.y >= Y + spacing + 20 && cursorPos.y <= Y + spacing + 24 + 8) && GetKeyState(VK_LBUTTON) < 0) || isHeld) {
        change = (cursorPos.x - X - 19) * (max - min) / 178;
      
    }
    if (!GetAsyncKeyState(VK_LBUTTON)) {
    
    }

    value_string.resize(written);
    if (change > max) change = max;
    if (change < min) change = min;
    int valueX = ((change - min) * 178 / (max - min));


    DrawMessage(pFontSmall, X + 23, Y + spacing + 6, 255, label);
    DrawMessage(pFontSmall, X + 173, Y + spacing + 6, 255, value_string.c_str());
    DrawRect(X + 20, Y + spacing + 21, 178, 8, ButtonColUnTicked);
    DrawRectA(X + 20, Y + spacing + 21, valueX, 7, ButtonColTicked);
}

D3DCOLOR Red = D3DCOLOR_XRGB(245, 4, 0);
D3DCOLOR Orange = D3DCOLOR_XRGB(248, 63, 2);
D3DCOLOR LightOrange = D3DCOLOR_XRGB(244, 128, 2);
D3DCOLOR Yellow = D3DCOLOR_XRGB(251, 184, 3);
D3DCOLOR WankYellow = D3DCOLOR_XRGB(248, 248, 0);
D3DCOLOR LightYellow = D3DCOLOR_XRGB(187, 247, 4);
D3DCOLOR GreenOne = D3DCOLOR_XRGB(122, 249, 1);
D3DCOLOR GreenTwo = D3DCOLOR_XRGB(125, 248, 0);
D3DCOLOR GreenThree = D3DCOLOR_XRGB(65, 249, 3);
D3DCOLOR GreenFour = D3DCOLOR_XRGB(4, 247, 5);
D3DCOLOR GreenFive = D3DCOLOR_XRGB(4, 249, 62);
D3DCOLOR Teal = D3DCOLOR_XRGB(1, 247, 191);

D3DCOLOR TealTwo = D3DCOLOR_XRGB(0, 250, 246);
D3DCOLOR Blue = D3DCOLOR_XRGB(0, 189, 247);
D3DCOLOR Blue2 = D3DCOLOR_XRGB(0, 125, 247);
D3DCOLOR DarkBlue = D3DCOLOR_XRGB(6, 62, 249);
D3DCOLOR DeepBlue = D3DCOLOR_XRGB(0, 1, 249);
D3DCOLOR LightPurple = D3DCOLOR_XRGB(126, 1, 248);

D3DCOLOR Purple = D3DCOLOR_XRGB(126, 1, 248);
D3DCOLOR SexPurple = D3DCOLOR_XRGB(187, 1, 250);
D3DCOLOR SexSexPurple = D3DCOLOR_XRGB(247, 1, 248);
D3DCOLOR UltraSexSexPurple = D3DCOLOR_XRGB(247, 2, 186);
D3DCOLOR AnalPurple = D3DCOLOR_XRGB(248, 2, 127);
D3DCOLOR DeepAnalPurple = D3DCOLOR_XRGB(248, 2, 65);


void drawColorPicker(D3DCOLOR& color) {
    spacing += 25;

    if (ButtonA( 20, spacing + 10, 8, 8, NULL, NULL, Red)) {
        color  = Red;
   }
    if (ButtonA( 28, spacing + 10, 8, 8, NULL, NULL, Orange)) {
        color =  Orange;
    }
    if (ButtonA( 36, spacing + 10, 8, 8, NULL, NULL, LightOrange)) {
        color =LightOrange;
    }
    if (ButtonA(44, spacing + 10, 8, 8, NULL, NULL, Yellow)) {
        color =Yellow;
    }
    if (ButtonA( 52, spacing + 10, 8, 8, NULL, NULL, WankYellow)) {
        color =WankYellow;
    }
    if (ButtonA( 60, spacing + 10, 8, 8, NULL, NULL, LightYellow)) {
        color =LightYellow;
   }
    if (ButtonA( 68, spacing + 10, 8, 8, NULL, NULL, GreenOne)) {
        color =GreenOne;
  }
    if (ButtonA( 76, spacing + 10, 8, 8, NULL, NULL, GreenTwo)) {
        color =GreenTwo;
  }
    if (ButtonA( 84, spacing + 10, 8, 8, NULL, NULL, GreenThree)) {
        color =GreenThree;
  }
    if (ButtonA( 92, spacing + 10, 8, 8, NULL, NULL, GreenFour)) {
        color =GreenFour;
   }
    if (ButtonA(100, spacing + 10, 8, 8, NULL, NULL, GreenFive)) {
        color =GreenFive;
   }

    if (ButtonA( 108, spacing + 10, 8, 8, NULL, NULL, Teal)) {
        color= Teal;
   }
    if (ButtonA(116, spacing + 10, 8, 8, NULL, NULL, TealTwo)) {
        color =TealTwo;
    }
    if (ButtonA( 124, spacing + 10, 8, 8, NULL, NULL, Blue)) {
        color= Blue;
   }
    if (ButtonA( 132, spacing + 10, 8, 8, NULL, NULL, Blue2)) {
        color =Blue2;
   }
    if (ButtonA( 140, spacing + 10, 8, 8, NULL, NULL, DarkBlue)) {
        color =DarkBlue;
   }

    if (ButtonA(148, spacing + 10, 8, 8, NULL, NULL, DeepBlue)) {
        color =DeepBlue;
   }
    if (ButtonA( 156, spacing + 10, 8, 8, NULL, NULL, LightPurple)) {
        color =GreenTwo;
  }
    if (ButtonA( 164, spacing + 10, 8, 8, NULL, NULL, Purple)) {
        color =Purple;
   }
    if (ButtonA(172, spacing + 10, 8, 8, NULL, NULL, SexPurple)) {
        color =SexPurple;
   }
    if (ButtonA(180, spacing + 10, 8, 8, NULL, NULL, SexSexPurple)) {
        color =SexSexPurple;
  }

    if (ButtonA(188, spacing + 10, 8, 8, NULL, NULL, AnalPurple)) {
        color= AnalPurple;
    }
    
 


}


void moveTitleBar();
D3DCOLOR crosshairColor = RGB(0, 100, 255);
void drawSeparator() {
    spacing += 30;
    DrawRect(X + 25, Y + spacing + 8, 170, 1, ButtonColTicked);
}





struct VERTEX_2D_DIF { // transformed colorized
    float x, y, z, rhw;
    D3DCOLOR color;
    static const DWORD FVF = D3DFVF_XYZRHW | D3DFVF_DIFFUSE;
};

void DrawCircleFilled(float mx, float my, float r, D3DCOLOR color)
{
    static const int CIRCLE_RESOLUTION = 40;
    VERTEX_2D_DIF verts[CIRCLE_RESOLUTION + 1];

    for (int i = 0; i < CIRCLE_RESOLUTION + 1; i++)
    {
        verts[i].x = mx + r * cos(D3DX_PI * (i / (CIRCLE_RESOLUTION / 2.0f)));
        verts[i].y = my + r * sin(D3DX_PI * (i / (CIRCLE_RESOLUTION / 2.0f)));
        verts[i].z = 0;
        verts[i].rhw = 1;
        verts[i].color = color;
    }

    g_pd3dDevice->SetFVF(VERTEX_2D_DIF::FVF);
    g_pd3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, CIRCLE_RESOLUTION - 1, &verts, sizeof(VERTEX_2D_DIF));
}
void drawBoolCat(const char* label, bool& change, int id, int y, int x) {


    const char* onOff = "off";
    if (id == menuNav) {
        midFunction = true;
        DrawRect(x, y, 150, 15, midBar);
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
            change = !change;
            Sleep(100);
        }
        if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
            change = !change;
            Sleep(100);
        }
    }
    else {
        midFunction = false;
        DrawRect(x, y, 150, 15, midBarCol);
    }
    if (change) {
        onOff = "enabled";
    }
    else {
        onOff = "disabled";
    }



    DrawMessage(pFontSmall, x + 5, y + 1, 255, label);
    DrawMessage(pFontSmall, x + 50, y + 1, 255, onOff);


}
void largeFurnacesplittera() {


    int firstSlot = 1305, secondSlot = 1395, thirdSlot = 1485, fourthslot = 1575, fifthSlot = 1665, sixthSlot = 1755;
    int firstRowY = 520;
    int secondRowY = 610;
    int thirdRowY = 700;


    int firstSplit = 695;
    int secondSplit = 695;
    int thirdSplit = 700;
    int fourthSplit = 703;
    int fifthSplit = 707;
    int sixthSplit = 710;
    int seventhSplit = 716;
    int eighthSplit = 723;
    int ninethSplit = 731;
    int tenthSplit = 741;
    int eleventhSplit = 758;
    int twelthSplit = 780;
    int thirteenthSplit = 820;
    int fourteenthSplit = 893;
    int fifteenthSplit = 1148;
    int PickUpSlot = 1165;


    HWND hwnd = FindWindowA(0, "Rust");
    if (isCursorShowing) {



        SetCursorPos(firstSplit, 520);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);
        SetCursorPos(PickUpSlot, firstRowY);
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
        Sleep(70);
        SetCursorPos(secondSlot, firstRowY);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);


        SetCursorPos(secondSplit, 520);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);
        SetCursorPos(PickUpSlot, firstRowY);
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
        Sleep(70);
        SetCursorPos(thirdSlot, firstRowY);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);


        SetCursorPos(thirdSplit, 520);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);
        SetCursorPos(PickUpSlot, firstRowY);
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
        Sleep(70);
        SetCursorPos(fourthslot, firstRowY);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);



        SetCursorPos(fourthSplit, 520);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);
        SetCursorPos(PickUpSlot, firstRowY);
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
        Sleep(70);
        SetCursorPos(fifthSlot, firstRowY);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);



        SetCursorPos(fifthSplit, 520);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);
        SetCursorPos(PickUpSlot, firstRowY);
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
        Sleep(70);
        SetCursorPos(sixthSlot, firstRowY);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);






        SetCursorPos(sixthSplit, 520);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);
        SetCursorPos(PickUpSlot, firstRowY);
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
        Sleep(70);
        SetCursorPos(firstSlot, secondRowY);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);


        SetCursorPos(seventhSplit, 520);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);
        SetCursorPos(PickUpSlot, firstRowY);
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
        Sleep(70);
        SetCursorPos(secondSlot, secondRowY);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);


        SetCursorPos(eighthSplit, 520);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);
        SetCursorPos(PickUpSlot, firstRowY);
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
        Sleep(70);
        SetCursorPos(thirdSlot, secondRowY);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);



        SetCursorPos(ninethSplit, 520);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);
        SetCursorPos(PickUpSlot, firstRowY);
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
        Sleep(70);
        SetCursorPos(fourthslot, secondRowY);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);



        SetCursorPos(tenthSplit, 520);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);
        SetCursorPos(PickUpSlot, firstRowY);
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
        Sleep(70);
        SetCursorPos(fifthSlot, secondRowY);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);


        SetCursorPos(eleventhSplit, 520);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);
        SetCursorPos(PickUpSlot, firstRowY);
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
        Sleep(70);
        SetCursorPos(sixthSlot, secondRowY);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);






        SetCursorPos(twelthSplit, 520);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);
        SetCursorPos(PickUpSlot, firstRowY);
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
        Sleep(70);
        SetCursorPos(firstSlot, thirdRowY);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);


        SetCursorPos(thirteenthSplit, 520);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);
        SetCursorPos(PickUpSlot, firstRowY);
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
        Sleep(70);
        SetCursorPos(secondSlot, thirdRowY);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);


        SetCursorPos(fourteenthSplit, 520);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);
        SetCursorPos(PickUpSlot, firstRowY);
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
        Sleep(70);
        SetCursorPos(thirdSlot, thirdRowY);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);



        SetCursorPos(fifteenthSplit, 520);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);
        SetCursorPos(PickUpSlot, firstRowY);
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
        Sleep(70);
        SetCursorPos(fourthslot, thirdRowY);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);




    }




}
void miniFurnaceSplit() {


    int mfirstSlot = 1390, msecondSlot = 1490, mthirdSlot = 1590;
    int firstRowY = 725;

    int mPickUpSlot = 1165;
    int mfirstSplit = 827;
    int msecondSplit = 909;
    int mthirdSplit = 1156;
    HWND hwnd = FindWindowA(0, "Rust");
    {
        SetCursorPos(mfirstSplit, 520);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);
        SetCursorPos(mPickUpSlot, 520);
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
        Sleep(70);
        SetCursorPos(mfirstSlot, firstRowY);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);


        SetCursorPos(msecondSplit, 520);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);
        SetCursorPos(mPickUpSlot, 520);
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
        Sleep(70);
        SetCursorPos(msecondSlot, firstRowY);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);


        SetCursorPos(mthirdSplit, 520);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);
        SetCursorPos(mPickUpSlot, 520);
        SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);
        Sleep(70);
        SetCursorPos(mthirdSlot, firstRowY);
        Sleep(70);
        SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);



    }

    Sleep(50);
}
void doAutoUpgrade() {


    HWND hwnd = FindWindowA(0, "Rust");

    ImGui::SetNextItemWidth(165);
    if (switchUpgrade == 1) upgradeMat = "         wood";
    if (switchUpgrade == 2) upgradeMat = "         stone";
    if (switchUpgrade == 3) upgradeMat = "       sheet metal";
    if (switchUpgrade == 4) upgradeMat = "        armoured";

    if (!isCursorShowing) {


        if (upgradeMat == "         wood") {
            SendMessage(hwnd, WM_RBUTTONDOWN, MK_RBUTTON, NULL);
            Sleep(50);
            SetCursorPos(1135, 340);
            Sleep(50);
            SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);

            SendMessage(hwnd, WM_RBUTTONUP, MK_RBUTTON, NULL);
            SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);
        }


        if (upgradeMat == "         stone") {
            SendMessage(hwnd, WM_RBUTTONDOWN, MK_RBUTTON, NULL);
            Sleep(20);
            SetCursorPos(1230, 640);
            Sleep(70);
            SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);

            Sleep(30);
            SendMessage(hwnd, WM_RBUTTONUP, MK_RBUTTON, NULL);
            SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);
        }

        if (upgradeMat == "       sheet metal") {
            SendMessage(hwnd, WM_RBUTTONDOWN, MK_RBUTTON, NULL);
            Sleep(50);
            SetCursorPos(935, 825);
            Sleep(50);
            SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);

            SendMessage(hwnd, WM_RBUTTONUP, MK_RBUTTON, NULL);
            SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);
        }

        if (upgradeMat == "        armoured") {
            SendMessage(hwnd, WM_RBUTTONDOWN, MK_RBUTTON, NULL);
            Sleep(50);
            SetCursorPos(630, 590);
            Sleep(50);
            SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, NULL);

            SendMessage(hwnd, WM_RBUTTONUP, MK_RBUTTON, NULL);
            SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, NULL);
        }

    }


}
void updateGunWithKeybinds() {

    for (;;) {
        if (GetAsyncKeyState(akToggleKey) & 1) {
            switchGun = 1;
            if (ttsEnabled) {
                speak(L"AK Enabled");
            }

        }


        if (GetAsyncKeyState(lrToggleKey) & 1) {
            switchGun = 2;
            if (ttsEnabled) {
                speak(L"LR-300 Enabled");
            }
        }

        if (GetAsyncKeyState(autoupgradeKey) & 1) {
            doAutoUpgrade();
        }
        if (GetAsyncKeyState(customToggleKey) & 1) {
            switchGun = 3;
            if (ttsEnabled) {
                speak(L"Custom SMG Enabled");
            }
        }

        if (GetAsyncKeyState(mp5ToggleKey) & 1) {

            switchGun = 4;
            if (ttsEnabled) {
                speak(L"MP5 Enabled");
            }
        }
        if (GetAsyncKeyState(thompsonToggleKey) & 1) {
            switchGun = 5;
            if (ttsEnabled) {
                speak(L"Thompson Enabled");
            }
        }
        if (GetAsyncKeyState(m249ToggleKey) & 1) {
            switchGun = 6;
            if (ttsEnabled) {
                speak(L"m249 Enabled");
            }
        }
        if (GetAsyncKeyState(sarToggleKey) & 1) {
            switchGun = 7;
            if (ttsEnabled) {
                speak(L"SAR Enabled");
            }
        }

        if (GetAsyncKeyState(m39ToggleKey) & 1) {
            switchGun = 8;
            if (ttsEnabled) {
                speak(L"m39 Enabled");
            }
        }

        if (GetAsyncKeyState(pythonToggleKey) & 1) {
            switchGun = 9;
            if (ttsEnabled) {
                speak(L"SAR Enabled");
            }
        }
        if (GetAsyncKeyState(sapToggleKey) & 1) {
            switchGun = 10;
            if (ttsEnabled) {
                speak(L"SAR Enabled");
            }
        }
        if (GetAsyncKeyState(m92ToggleKey) & 1) {
            switchGun = 11;
            if (ttsEnabled) {
                speak(L"SAR Enabled");
            }
        }
        if (GetAsyncKeyState(revolverToggleKey) & 1) {
            switchGun = 8;
            if (ttsEnabled) {
                speak(L"revolver Enabled");
            }
        }
       


        if (GetAsyncKeyState(ironsightKey) & 1) {
            switchScope = 1;

        }
        if (GetAsyncKeyState(eightXKey) & 1) {
            switchScope = 2;
        }
        if (GetAsyncKeyState(sixteenXKey) & 1) {
            switchScope = 3;
        }
        if (GetAsyncKeyState(holosightKey) & 1) {
            switchScope = 4;
        }
        if (GetAsyncKeyState(simpleKey) & 1) {
            switchScope = 5;
        }

        if (GetAsyncKeyState(nobarrelKey) & 1) {
            switchBarrel = 1;
        }
        if (GetAsyncKeyState(muzzzleBoostKey) & 1) {
            switchBarrel = 2;
        }
        if (GetAsyncKeyState(silencerKey) & 1) {
            switchBarrel = 3;
        }

        if (GetAsyncKeyState(furnaceSplitKey) && furnaceSplitter) {
            miniFurnaceSplit();
        }
        if (GetAsyncKeyState(largefurnaceSplitKey) && largeFurnaceSplitter) {
            largeFurnacesplittera();
        }
        Sleep(5);

    }
}
void keyBindSwapA(const char*& key, bool& listeningtoKey, int& scriptOnKey)
{

    next = Button(X + 168, spacing + 20, 28, 12, key, NULL);

    if (next) {
        listeningtoKey = true;

    }

    if (listeningtoKey) {
        key = "...";
    }

    if (GetAsyncKeyState(VK_END) && listeningtoKey) {
        key = "end";
        scriptOnKey = VK_END;
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(VK_HOME) && listeningtoKey) {
        key = "home";
        scriptOnKey = VK_HOME;
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(VK_DELETE) && listeningtoKey) {
        key = "del";
        scriptOnKey = VK_DELETE;
        listeningtoKey = false; Sleep(100);
    }



    if (GetAsyncKeyState(81) && listeningtoKey) {
        key = "pdown";
        scriptOnKey = 81;
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(73) && listeningtoKey) {
        key = "pup";
        scriptOnKey = 81;
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(VK_ESCAPE) && listeningtoKey) {
        key = "none";
        scriptOnKey = 12386126162;
        listeningtoKey = false; Sleep(100);

    }

    if (GetAsyncKeyState(VK_INSERT) && listeningtoKey) {
        key = "   ins";
        scriptOnKey = VK_INSERT;
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(VK_F1) && listeningtoKey)
    {
        scriptOnKey = VK_F1;
        key = "   f1";
        listeningtoKey = false; Sleep(100);

    }
    if (GetAsyncKeyState(VK_F2) && listeningtoKey)
    {
        scriptOnKey = VK_F2;
        key = "   f2";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(VK_F3) && listeningtoKey)
    {
        scriptOnKey = VK_F3;
        key = "   f3";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(VK_F4) && listeningtoKey)
    {
        scriptOnKey = VK_F4;
        key = "f4";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(VK_F5) && listeningtoKey)
    {
        scriptOnKey = VK_F5;
        key = "f5";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(VK_F6) && listeningtoKey)
    {
        scriptOnKey = VK_F6;
        key = "f6";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(VK_F7) && listeningtoKey)
    {
        scriptOnKey = VK_F7;
        key = "f7";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(VK_F8) && listeningtoKey)
    {
        scriptOnKey = VK_F8;
        key = "f8";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(VK_F9) && listeningtoKey)
    {
        scriptOnKey = VK_F9;
        key = "f9";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(VK_F10) && listeningtoKey)
    {
        scriptOnKey = VK_F10;
        key = "f10";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(VK_F11) && listeningtoKey)
    {
        scriptOnKey = VK_F11;
        key = "f11";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(VK_F12) && listeningtoKey)
    {
        scriptOnKey = VK_F12;
        key = "f12";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(65) && listeningtoKey)
    {
        scriptOnKey = 65;
        key = "a";
        listeningtoKey = false; Sleep(100);

    }
    if (GetAsyncKeyState(66) && listeningtoKey)
    {
        scriptOnKey = 66;
        key = "b";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(67) && listeningtoKey)
    {
        scriptOnKey = 67;
        key = "c";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(68) && listeningtoKey)
    {
        scriptOnKey = 68;
        key = "d";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(69) && listeningtoKey)
    {
        scriptOnKey = 69;
        key = "e";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(70) && listeningtoKey)
    {
        scriptOnKey = 70;
        key = "f";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(71) && listeningtoKey)
    {
        scriptOnKey = 71;
        key = "g";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(72) && listeningtoKey)
    {
        scriptOnKey = 72;
        key = "h";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(73) && listeningtoKey)
    {
        scriptOnKey = 73;
        key = "i";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(74) && listeningtoKey)
    {
        scriptOnKey = 74;
        key = "j";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(75) && listeningtoKey)
    {
        scriptOnKey = 75;
        key = "k";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(76) && listeningtoKey)
    {
        scriptOnKey = 76;
        key = "l";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(77) && listeningtoKey)
    {
        scriptOnKey = 77;
        key = "m";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(78) && listeningtoKey)
    {
        scriptOnKey = 78;
        key = "n";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(79) && listeningtoKey)
    {
        scriptOnKey = 79;
        key = "o";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(80) && listeningtoKey)
    {
        scriptOnKey = 80;
        key = "p";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(81) && listeningtoKey)
    {
        scriptOnKey = 81;
        key = "q";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(82) && listeningtoKey)
    {
        scriptOnKey = 82;
        key = "r";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(83) && listeningtoKey)
    {
        scriptOnKey = 83;
        key = "s";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(84) && listeningtoKey)
    {
        scriptOnKey = 84;
        key = "t";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(85) && listeningtoKey)
    {
        scriptOnKey = 85;
        key = "u";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(86) && listeningtoKey)
    {
        scriptOnKey = 86;
        key = "v";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(87) && listeningtoKey)
    {
        scriptOnKey = 87;
        key = "w";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(88) && listeningtoKey)
    {
        scriptOnKey = 88;
        key = "x";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(89) && listeningtoKey)
    {
        scriptOnKey = 89;
        key = "y";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(90) && listeningtoKey)
    {
        scriptOnKey = 90;
        key = "z";
        listeningtoKey = false; Sleep(100);
    }

    //---------------------------------------------------------

    if (GetAsyncKeyState(VK_NUMPAD0) && listeningtoKey)
    {
        scriptOnKey = VK_NUMPAD0;
        key = "num0";
        listeningtoKey = false; Sleep(100);
    }


    if (GetAsyncKeyState(VK_NUMPAD1) && listeningtoKey)
    {
        scriptOnKey = VK_NUMPAD1;
        key = "num1";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(VK_NUMPAD2) && listeningtoKey)
    {
        scriptOnKey = VK_NUMPAD2;
        key = "num2";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(VK_NUMPAD3) && listeningtoKey)
    {
        scriptOnKey = VK_NUMPAD3;
        key = "num3";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(VK_NUMPAD4) && listeningtoKey)
    {
        scriptOnKey = VK_NUMPAD4;
        key = "num4";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(VK_NUMPAD5) && listeningtoKey)
    {
        scriptOnKey = VK_NUMPAD5;
        key = "num5";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(VK_NUMPAD6) && listeningtoKey)
    {
        scriptOnKey = VK_NUMPAD6;
        key = "num6";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(VK_NUMPAD7) && listeningtoKey)
    {
        scriptOnKey = VK_NUMPAD7;
        key = "num7";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(VK_NUMPAD8) && listeningtoKey)
    {
        scriptOnKey = VK_NUMPAD8;
        key = "num8";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(VK_NUMPAD9) && listeningtoKey)
    {
        scriptOnKey = VK_NUMPAD9;
        key = "num9";
        listeningtoKey = false; Sleep(100);
    }
    //----------------------------------------------------------
    if (GetAsyncKeyState(48) && listeningtoKey)
    {
        scriptOnKey = 48;
        key = "0";
        listeningtoKey = false; Sleep(100);
    }


    if (GetAsyncKeyState(49) && listeningtoKey)
    {
        scriptOnKey = 49;
        key = "1";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(50) && listeningtoKey)
    {
        scriptOnKey = 50;
        key = "2";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(51) && listeningtoKey)
    {
        scriptOnKey = 51;
        key = "3";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(52) && listeningtoKey)
    {
        scriptOnKey = 52;
        key = "4";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(53) && listeningtoKey)
    {
        scriptOnKey = 53;
        key = "5";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(54) && listeningtoKey)
    {
        scriptOnKey = 54;
        key = "6";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(55) && listeningtoKey)
    {
        scriptOnKey = 55;
        key = "7";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(56) && listeningtoKey)
    {
        scriptOnKey = 56;
        key = "8";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(57) && listeningtoKey)
    {
        scriptOnKey = 57;
        key = "9";
        listeningtoKey = false; Sleep(100);
    }

    //----------------------------------

    if (GetAsyncKeyState(VK_OEM_4) && listeningtoKey)
    {
        scriptOnKey = VK_OEM_4;
        key = "[";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(VK_OEM_6) && listeningtoKey)
    {
        scriptOnKey = VK_OEM_6;
        key = "]";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(VK_OEM_5) && listeningtoKey)
    {
        scriptOnKey = VK_OEM_5;
        key = "back";
        listeningtoKey = false; Sleep(100);
    }
    if (GetAsyncKeyState(VK_OEM_1) && listeningtoKey)
    {
        scriptOnKey = VK_OEM_1;
        key = ";";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(VK_OEM_COMMA) && listeningtoKey)
    {
        scriptOnKey = VK_OEM_COMMA;
        key = ",";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(61) && listeningtoKey)
    {
        scriptOnKey = 61;
        key = "=";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(45) && listeningtoKey)
    {
        scriptOnKey = 45;
        key = "-";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(VK_LCONTROL) && listeningtoKey)
    {
        scriptOnKey = VK_LCONTROL;
        key = "lctrl";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(VK_RCONTROL) && listeningtoKey)
    {
        scriptOnKey = VK_RCONTROL;
        key = "rctrl";
        listeningtoKey = false; Sleep(100);
    }

    if (GetAsyncKeyState(VK_RSHIFT) && listeningtoKey)
    {
        scriptOnKey = VK_RSHIFT;
        key = "rshift";
        listeningtoKey = false; Sleep(100);
    }




}

int main(int, char**)
{





    std::fstream checkFile("virginsetttings.ini");
    if (checkFile.fail()) {
        std::ofstream createFile("virginsettings.ini");
    }




    // Create application window
    //ImGui_ImplWin32_EnableDpiAwareness();
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, _T("ImGui Example"), NULL };
    ::RegisterClassEx(&wc);

    HWND hwnd = ::CreateWindow(wc.lpszClassName, _T("Menu"), WS_EX_TOPMOST | WS_POPUP, 0, 0, GetSystemMetrics(SM_CXSCREEN) / 2 + 100, GetSystemMetrics(SM_CYSCREEN), NULL, NULL, wc.hInstance, NULL);
    SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED);

    SetLayeredWindowAttributes(hwnd, 0, 0, LWA_ALPHA);
    SetLayeredWindowAttributes(hwnd, 0, RGB(233, 255, 255), LWA_COLORKEY);

    MARGINS Margin = { -1, -1, -1, -1 };
    DwmExtendFrameIntoClientArea(hwnd, &Margin);


    ISpVoice* pVoice = NULL;


    SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
    // Initialize Direct3D
    if (!CreateDeviceD3D(hwnd))
    {
        CleanupDeviceD3D();
        ::UnregisterClass(wc.lpszClassName, wc.hInstance);
        return 1;
    }

    // Show the window

    ::ShowWindow(hwnd, SW_SHOWDEFAULT);
    ::UpdateWindow(hwnd);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();

    // Setup Platform/Renderer backends
    ImGui_ImplWin32_Init(hwnd);
    ImGui_ImplDX9_Init(g_pd3dDevice);

    // Load Fonts
    // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
    // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
    // - If the file cannot be loaded, the function will return NULL. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
    // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
    // - Read 'docs/FONTS.md' for more instructions and details.
    // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
    //io.Fonts->AddFontDefault();
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/ProggyTiny.ttf", 10.0f);
    //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
    //IM_ASSERT(font != NULL);

    // Our state
    D3DCOLOR Red = D3DCOLOR_RGBA(0, 0, 255, 255);
    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    // Main loop
    MSG msg;
    ZeroMemory(&msg, sizeof(msg));


    bool mainMenu = true;

    //CreateThread(0, 0, (LPTHREAD_START_ROUTINE)updateSensFov, 0, 0, 0);



    while (msg.message != WM_QUIT)
    {

        if (switchHipFire == 1) hipfirechar = "        never hipfire";
        if (switchHipFire == 2) hipfirechar = "       un-ads hipfire";
        if (switchHipFire == 3) hipfirechar = "       always hipfire";

        if (switchHipFire < 0) switchHipFire = 0;
        if (switchHipFire > 3) switchHipFire = 3;
  

        if (switchGun == 1) {
            weapon = "          assault rifle";
            miniweapon = "assault rifle";
        }
        if (switchGun == 2)
        {
            weapon = "      lr-300 assault rifle";
            miniweapon = "lr-300";
        }
        if (switchGun == 3)
        {
            weapon = "          custom smg";
            miniweapon = "custom";
        }
        if (switchGun == 4)
        {
            weapon = "              mp5a4";
            miniweapon = "mp5";
        }
        if (switchGun == 5)
        {
            weapon = "           thompson";
            miniweapon = "thompson";
        }
        if (switchGun == 6)
        {
            weapon = "              m249";
            miniweapon = "m249";
        }
        if (switchGun == 7)
        {
            weapon = "         semi-auto rifle";
            miniweapon = "sar";
        }
        if (switchGun == 8)
        {
            weapon = "             revolver";
            miniweapon = "revolver";
        }
        if (switchGun == 9)
        {
            weapon = "        semi-auto pistol";
            miniweapon = "semi pistol";
        }
        if (switchGun == 10)
        {
            weapon = "        python revolver";
            miniweapon = "python";
        }
        if (switchGun == 11)
        {
            weapon = "            m39 rifle";
            miniweapon = "m39";
        }
        if (switchGun == 12)
        {
            weapon = "            m92 pistol";
            miniweapon = "m92";
        }
        if (switchGun == 13)
        {
            weapon = "             nailgun";
            miniweapon = "nailgun";
        }

        if (switchScope == 1)
        {
            scope = "            no scope";
            miniscope = "none";
        }
        if (switchScope == 2)
        {
            scope = "             8x scope";
            miniscope = "8x scope";
        }
        if (switchScope == 3) {
            scope = "            16x scope";
            miniscope = "16x scope";
        }
        if (switchScope == 4) {
            scope = "            holosight";
            miniscope = "holosight";
        }
        if (switchScope == 5) {
            scope = "            handmade";
            miniscope = "hand made";
        }
        if (switchKeyType == 1) {
            keyType = "        weapon keys";
        }
        if (switchKeyType == 2) {
            keyType = "       attachment keys";
        }
        if (switchKeyType == 3) {
            keyType = "   weapons";
        }
        if (crosshairStyleNum == 1) {
            crosshairStyle = "             recticle";
         
        }
        if (crosshairStyleNum == 2) {
            crosshairStyle = "                dot";
        }

        if (controlCrosshairShow == 1) {
            crosshairShowChar = "           never hide";
        }
        if (controlCrosshairShow == 2) {
            crosshairShowChar = "       hide while ads";
        }
        if (crosshairStyleNum > 2) crosshairStyleNum = 2;
        if (crosshairStyleNum < 1) crosshairStyleNum = 1;
        if (switchKeyType > 2) switchKeyType = 2;
        if (switchKeyType < 1) switchKeyType = 1;
        if (switchUpgrade == 1) upgradeMat = "         wood";
        if (switchUpgrade == 2) upgradeMat = "         stone";
        if (switchUpgrade == 3) upgradeMat = "       sheet metal";
        if (switchUpgrade == 4) upgradeMat = "        armoured";

        if (switchUpgrade > 4) switchUpgrade = 4;
        if (switchUpgrade < 1) switchUpgrade = 1;
        if (switchScope < 1) switchScope = 1;
        if (switchScope > 5) switchScope = 5;

        if (switchBarrel == 1) {
            barrel = "            no barrel";
            minibarrel = "none";
        }
        if (switchBarrel == 2) {
            barrel = "              boost";
            minibarrel = "muzzle boost";
        }
        if (switchBarrel == 3) {
            barrel = "            silencer";
            minibarrel = "silencer";
        }
        if (switchGun < 1) switchGun = 1;
        if (switchGun > 13) switchGun = 13;

        if (switchBarrel > 3) switchBarrel = 3;
        if (switchBarrel < 1) switchBarrel = 1;
        // Poll and handle messages (inputs, window resize, etc.)
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.

        auto t1 = std::chrono::high_resolution_clock::now();






        if (::PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
            continue;
        }

        // Start the Dear ImGui frame
        ImGui_ImplDX9_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).

        // 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
        {


            static float f = 0.0f;
            static int counter = 0;


            int CenterX = 1920 / 2;
            int  CenterY = 1080 / 2;

            CURSORINFO ci = { sizeof(CURSORINFO) };
            char* scriptEnabledChar = " hm";
            if (scriptEnabled) {
                scriptEnabledChar = "enabled";
            }
            else
            {
                scriptEnabledChar = "disabled";
            }
            if (GetCursorInfo(&ci))
            {


            }



            if (ci.flags != 0 && (GetForegroundWindow() == FindWindowA(0, "Rust") || GetForegroundWindow() == FindWindowA(0, "Menu"))) {
                isCursorShowing = true;

            }
            if (ci.flags == 0) {
                isCursorShowing = false;

                if (GetAsyncKeyState(scriptOnKey) & (0x8000 != 0)) {
                    scriptEnabled = !scriptEnabled;
                    if (ttsEnabled) {
                        speak(L"Script Toggled");
                    }
                    Sleep(100);
                }
            }




            

            if (GetAsyncKeyState(menuKey)) {
                showMenu = !showMenu;
                if (ttsEnabled) {
                    speak(L"Menu Toggled");
                }
                Sleep(100);
                
            }

            if (!showMenu) {
                ShowWindow(hwnd, 0);
            }
            else
            {
                ShowWindow(hwnd, 5);
            }
            if (GetAsyncKeyState(exitKey)) {
                exit(0);

            }


        }
        DWORD dwColor = 0xAABBCCFF;


        ImGui::EndFrame();
        g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
        g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
        g_pd3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, FALSE);
        D3DCOLOR clear_col_dx = D3DCOLOR_RGBA(0, 0, 0, 0);
        g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, clear_col_dx, 1.0f, 0);
        if (g_pd3dDevice->BeginScene() >= 0)
        {
            Red = D3DCOLOR_ARGB(crosshairOpacity * 2, 255, 0, 0);
            static bool hitTabBottom = false;
         
            ImGui::Render();
            HWND hAwnd = FindWindowA(0, "Menu");
            SetWindowPos(hAwnd, HWND_TOPMOST, 0, 0, GetSystemMetrics(SM_CXSCREEN) / 2 + 100, GetSystemMetrics(SM_CYSCREEN), NULL);

            static bool pressed = false;

            static bool hit = false;
            POINT cursorPos;
            POINT delta;

            POINT oldPos;
            POINT newPos;


            GetCursorPos(&cursorPos);
       
            if ((cursorPos.x > X + 5 && cursorPos.x < X + 10 + 190 && cursorPos.y > Y && cursorPos.y < Y + 7 + 25) || pressed) {
                int aidsX ;
                int aidsY ;
                if (GetAsyncKeyState(VK_LBUTTON)) {

                    GetCursorPos(&newPos);

                    X =  aidsX +  newPos.x - oldPos.x;
                    Y =  aidsY +  newPos.y - oldPos.y;


         
                   
                   
                   
                    pressed = true;

                }
                else {
                    aidsX = X;
                    aidsY = Y;
                    GetCursorPos(&oldPos);
                    pressed = false;
                }
            }


            

            if (X > GetSystemMetrics(SM_CXSCREEN) / 2 - 100) {
                X = GetSystemMetrics(SM_CXSCREEN) / 2 - 100;
            }


            if (miniMenu) {

                drawBoolCat("recoil: ", scriptEnabled, 1, menuY, menuX);
                drawCharSwitchCat("weapon: ", miniweapon, 2, menuX, menuY + 16, switchGun);
                drawCharSwitchCat("scope: ", miniscope, 3, menuX, menuY + 32, switchScope);
                drawCharSwitchCat("barrel: ", minibarrel, 4, menuX, menuY + 48, switchBarrel);
               

                if (menuNav > 4) menuNav = 4;
                if (menuNav < 1)menuNav = 1;
                if (GetAsyncKeyState(VK_DOWN)) {
                    menuNav++;

                    Sleep(100);
                }
                if (GetAsyncKeyState(VK_UP)) {
                    menuNav--;
                    Sleep(100);
                }
             }

            DrawBar(10, 7, 0, 17, BarCol); // fisrt bar

            DrawMessage(pFontSmall, X + 15, Y + 8, 255, "diablo");




            DrawRect(X + 10, Y + 26, 198, 198, midBarCol);// mid bar shit


            static bool customizeColor = false;
            if (crosshair) {

               
            }
            if (secRecoilCat) {

       
               
            drawCheckBox("recoil", scriptEnabled);
            keyBindSwap(scriptEnabledChar,islisteningScriptEnabled , scriptOnKey, 170,  20 +spacing, 28, 10, "sdf", false);
            drawCheckBox("blatant mode", highPerformance);
            drawCheckBox("auto detection [beta]", autoDetection);
            drawCharSwitcher(weapon, switchGun);
            drawCharSwitcher(scope, switchScope);
            drawCharSwitcher(barrel, switchBarrel);
            drawCharSwitcher(hipfirechar, switchHipFire);
            drawSlider("control percentage x", xComp, 0, 100);
            drawSlider("control percentage y", yComp, 0, 100);
            }


            if (secExtraCat) {

                drawCheckBox("movement exaggeration", randomisation);
                if (randomisation) {
                    drawSlider("exaggeration amount", randomisationStrength, 0, 100);
                   
                }
              
                drawCheckBox("count ammo", countAmmo);
                drawCheckBox("force full auto", forceFullAuto);
                drawCheckBox("crosshair", crosshair);
                if (crosshair) {
                    drawCharSwitcher(crosshairStyle, crosshairStyleNum);
                    drawCharSwitcher(crosshairShowChar, controlCrosshairShow);
                    drawColorPicker(crosshairColor);
                    spacing -= 15;
                }
                drawSeparator();
                spacing -= 20;
                drawCheckBox("mini menu", miniMenu);
                drawCheckBox("customize color", customizeColor);
                    if (customizeColor) {
                        drawColorPicker(ButtonColTicked);
                    }
                    else {
                        ButtonColTicked = D3DCOLOR_XRGB(237, 36, 116);
                    }
            
            }

            if (secMiscCat) {
                drawCheckBox("furnace splitter", furnaceSplitter);
                keyBindSwapA(keyFurnanceSplit, listentoKeyFurnace, furnaceSplitKey);
                drawCheckBox("large furnace splitter", largeFurnaceSplitter);
                keyBindSwapA(keyLargeFurnanceSplit, listentoKeyLargeFurnace, largefurnaceSplitKey);
                drawSeparator();
                spacing -= 21;
                drawCheckBox("auto upgrade", autoUpgrade);
                keyBindSwapA(AutoUpgrade, listentoKeyAutoUpgrade, autoupgradeKey);
                drawCharSwitcher(upgradeMat, switchUpgrade);
                drawSeparator();
                spacing -= 21;
                drawCheckBox("fast code lock", fastcodelock);
                keyBindSwapA(fastCodeChar,fastListeningtoKey, fastCodeLockVKKey);
                CdrawCharSwitcher( firstDig);
                CdrawCharSwitcher( secDig);
                CdrawCharSwitcher( thirDig);
                CdrawCharSwitcher( fourDig);
                drawCheckBox("anti afk", antiafk);


                


            }

            if ((controlCrosshairShow == 2 && GetAsyncKeyState(VK_RBUTTON))) {

            }
            else {
                if (crosshair) {

            
                if (crosshairStyleNum == 1) {



                    DrawRect(GetSystemMetrics(SM_CXSCREEN) / 2 - 6, GetSystemMetrics(SM_CYSCREEN) / 2, 4, 1, crosshairColor);
                    DrawRect(GetSystemMetrics(SM_CXSCREEN) / 2 + 3, GetSystemMetrics(SM_CYSCREEN) / 2, 4, 1, crosshairColor);
                    DrawRect(GetSystemMetrics(SM_CXSCREEN) / 2, GetSystemMetrics(SM_CYSCREEN) / 2 - 6, 1, 4, crosshairColor);
                    DrawRect(GetSystemMetrics(SM_CXSCREEN) / 2, GetSystemMetrics(SM_CYSCREEN) / 2 + 3, 1, 4, crosshairColor);
                }
                if (crosshairStyleNum == 2) {
                    DrawCircleFilled(GetSystemMetrics(SM_CXSCREEN) / 2 - 4, GetSystemMetrics(SM_CYSCREEN) / 2 + 1, 3, crosshairColor);
                }
                }
            }
           
                
            if (secKeysCat) {
                keyBindSwap(menuKeyChar, islisteningMenu, menuKey, 50, 50, 46, 13, "    menu key", true);
                keyBindSwap(exitKeyChar, islisteningExit, exitKey, 115, 50, 46, 13, "     exit key", true);
                if (switchKeyType == 1) {
                 
                    keyBindSwap(akKeyChar, islisteningAK, akToggleKey, 25, 95, 46, 13, "   assault rifle", true);
                    keyBindSwap(customKeyChar, islisteningCUSTOM, customToggleKey, 25, 125, 46, 13, "      custom", true);
                    keyBindSwap(sarKeyChar, islisteningSAR, sarToggleKey, 25, 155, 46, 13, "         sar", true);
                    keyBindSwap(sapKeyChar, islisteningSAP, sapToggleKey, 25, 185, 46, 13, "         sap", true);

                    keyBindSwap(lrKeyChar, islisteningLR, lrToggleKey, 85, 95, 46, 13, "       lr-300", true);
                    keyBindSwap(thompsonKeyChar, islisteningTHOMPSON, thompsonToggleKey, 85, 125, 46, 13, "   thompson", true);
                    keyBindSwap(m39KeyChar, islisteningM39, m39ToggleKey, 85, 155, 46, 13, "     m39 rifle", true);
                    keyBindSwap(m92KeyChar, islisteningM92, m92ToggleKey, 85, 185, 46, 13, "        m92", true);

                    keyBindSwap(mp5KeyChar, islisteningMP5, mp5ToggleKey, 145, 95, 46, 13, "      mp5a4", true);
                    keyBindSwap(m249KeyChar, islisteningM249,  m249ToggleKey, 145, 125, 46, 13, "       m249", true);
                    keyBindSwap(pythonKeyChar, islisteningPYTHON, pythonToggleKey, 145, 155, 46, 13, "      python", true);
                    keyBindSwap(revolverKeyChar, islisteningREVOLVER, revolverToggleKey, 145, 185, 46, 13, "     revolver", true);




                 
                 
                    spacing += 35;
                    drawSeparator();

                }
                if (switchKeyType == 2) {
                    spacing += 35;
                    drawSeparator();
                    keyBindSwap(akKeyChar, islisteningAK, akToggleKey, 25, 95, 46, 13, "   assault rifle", true);
                    keyBindSwap(customKeyChar, islisteningCUSTOM, customToggleKey, 25, 125, 46, 13, "      custom", true);

                    keyBindSwap(lrKeyChar, islisteningLR, lrToggleKey, 85, 95, 46, 13, "       lr-300", true);
                    keyBindSwap(thompsonKeyChar, islisteningTHOMPSON, thompsonToggleKey, 85, 125, 46, 13, "   thompson", true);

                    keyBindSwap(mp5KeyChar, islisteningMP5, mp5ToggleKey, 145, 95, 46, 13, "      mp5a4", true);
                    keyBindSwap(m249KeyChar, islisteningM249, m249ToggleKey, 145, 125, 46, 13, "       m249", true);
                    spacing += 45;
                    drawSeparator();
                    keyBindSwap(akKeyChar, islisteningAK, akToggleKey, 25, 170, 46, 13, "   assault rifle", true);
                    keyBindSwap(lrKeyChar, islisteningLR, lrToggleKey, 85, 170, 46, 13, "       lr-300", true);
                    keyBindSwap(mp5KeyChar, islisteningMP5, mp5ToggleKey, 145, 170, 46, 13, "      mp5a4", true);

                }
                drawCharSwitcherKey(keyType, switchKeyType, 190);
            
            }

      


            DrawBar(10, 228, 0, 21, midBarCol); // end bar
           bool recoilCat = Button(12, 230, 46, 15, "recoil", secRecoilCat);
            bool extraCat = Button(61, 230, 46, 15, " extra", secExtraCat);
            bool miscCat = Button(110, 230, 46, 15, " misc", secMiscCat);
            bool keysCat = Button(159, 230, 47, 15, " keys", secKeysCat);
          
            
            if (recoilCat) {
                secRecoilCat = true;
                secExtraCat = false;
                secKeysCat = false;
                secMiscCat = false;
            }
            if (extraCat) {
                secRecoilCat = false;
                secExtraCat = true;
                secKeysCat = false;
                secMiscCat = false;

            }
            if (miscCat) {
                secRecoilCat = false;
                secExtraCat = false;
                secKeysCat = false;
                secMiscCat = true;
            }
            if (keysCat) {
                secRecoilCat = false;
                secExtraCat = false;
                secKeysCat = true;
                secMiscCat = false;
            }
            
            spacing = 0;





            // DrawRect(g_pd3dDevice, 1920 / 2 - 20, 1080 / 2, 40, 2, Red);
             //DrawRect(g_pd3dDevice, 1920 / 2, 1080 / 2 - 20, 2, 40, Red);
            ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
            g_pd3dDevice->EndScene();
        }
        HRESULT result = g_pd3dDevice->Present(NULL, NULL, NULL, NULL);

        // Handle loss of D3D9 device
        if (result == D3DERR_DEVICELOST && g_pd3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET)
            ResetDevice();
        Sleep(5);
    }

    ImGui_ImplDX9_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    CleanupDeviceD3D();
    ::DestroyWindow(hwnd);
    ::UnregisterClass(wc.lpszClassName, wc.hInstance);
    Sleep(2);

    return 0;
}

// Helper functions

bool CreateDeviceD3D(HWND hWnd)
{
    

    if ((g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
        return false;

    // Create the D3DDevice
    ZeroMemory(&g_d3dpp, sizeof(g_d3dpp));
    g_d3dpp.Windowed = TRUE;
    g_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    g_d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
    g_d3dpp.EnableAutoDepthStencil = TRUE;
    g_d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
    g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;           // Present with vsync
    //g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;   // Present without vsync, maximum unthrottled framerate
    if (g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &g_d3dpp, &g_pd3dDevice) < 0)
        return false;

    D3DXCreateFont(g_pd3dDevice, 12.5, 0, 0, 0, false, DEFAULT_CHARSET, OUT_CHARACTER_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, "Tahoma", &pFontSmall);
    return true;

}

void moveTitleBar() {



}
void CleanupDeviceD3D()
{
    if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = NULL; }
    if (g_pD3D) { g_pD3D->Release(); g_pD3D = NULL; }
}

void ResetDevice()
{
    ImGui_ImplDX9_InvalidateDeviceObjects();
    HRESULT hr = g_pd3dDevice->Reset(&g_d3dpp);
    if (hr == D3DERR_INVALIDCALL)
        IM_ASSERT(0);
    ImGui_ImplDX9_CreateDeviceObjects();
}

// Forward declare message handler from imgui_impl_win32.cpp
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Win32 message handler
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
        {
            g_d3dpp.BackBufferWidth = LOWORD(lParam);
            g_d3dpp.BackBufferHeight = HIWORD(lParam);
            ResetDevice();
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
            return 0;
        break;

    case WM_DESTROY:
        ::PostQuitMessage(0);
        return 0;
    }
    return ::DefWindowProc(hWnd, msg, wParam, lParam);
}
