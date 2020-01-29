
#include "main.h"
#include "myDirect3D.h"
#include "scene.h"
#include "fade.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "sound.h"
#include <time.h>

#define _USE_MATH_DEFINES
#include <math.h>

#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dinput8.lib")


/*------------------------------------------------------------------------------
定数定義
------------------------------------------------------------------------------*/
#define CLASS_NAME     "GameWindow"       // ウインドウクラスの名前
#define WINDOW_CAPTION "ゲームウィンドウ" // ウィンドウの名前


/*------------------------------------------------------------------------------
   構造体宣言
------------------------------------------------------------------------------*/
// ２Dポリゴン頂点構造体
typedef struct Vertex2D_tag
{
    D3DXVECTOR4 position; // 頂点座標（座標変換済み頂点）
    D3DCOLOR	color;    // 頂点カラー(32Bit ARGB指定)
    D3DXVECTOR2 texcoord; // テクスチャ座標
} Vertex2D;
#define FVF_VERTEX2D (D3DFVF_XYZRHW|D3DFVF_DIFFUSE|D3DFVF_TEX1) // ２Dポリゴン頂点フォーマット


/*------------------------------------------------------------------------------
   グローバル変数宣言
------------------------------------------------------------------------------*/
static HWND g_hWnd;                           // ウィンドウハンドル


/*------------------------------------------------------------------------------
プロトタイプ宣言
------------------------------------------------------------------------------*/
// ウィンドウプロシージャ(コールバック関数)
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// ゲームの初期化
static bool Initialize(HINSTANCE hInst);
static void Finalize(void);

// ゲームの更新関数
static void Update(void);
// ゲームの描画関数
static void Draw(void);


/*------------------------------------------------------------------------------
メイン
------------------------------------------------------------------------------*/
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// 使用しない一時変数を明示
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// ウィンドウクラス構造体の設定
	WNDCLASS wc = {};
	wc.lpfnWndProc = WndProc;                          // ウィンドウプロシージャの指定
	wc.lpszClassName = CLASS_NAME;                     // クラス名の設定
	wc.hInstance = hInstance;                          // インスタンスハンドルの指定
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);          // マウスカーソルを指定
	wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND + 1); // ウインドウのクライアント領域の背景色を設定

	// クラス登録
	RegisterClass(&wc);


	// ウィンドウスタイル
	DWORD window_style = WS_OVERLAPPEDWINDOW & ~(WS_MAXIMIZEBOX | WS_THICKFRAME);

	// 基本矩形座標
	RECT window_rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

	// 指定したクライアント領域を確保するために新たな矩形座標を計算
	AdjustWindowRect(&window_rect, window_style, FALSE);

	// 新たなWindowの矩形座標から幅と高さを算出
	int window_width = window_rect.right - window_rect.left;
	int window_height = window_rect.bottom - window_rect.top;

	// プライマリモニターの画面解像度取得
	int desktop_width = GetSystemMetrics(SM_CXSCREEN);
	int desktop_height = GetSystemMetrics(SM_CYSCREEN);

	// デスクトップの真ん中にウィンドウが生成されるように座標を計算
	// ※ただし万が一、デスクトップよりウィンドウが大きい場合は左上に表示
	int window_x = max((desktop_width - window_width) / 2, 0);
	int window_y = max((desktop_height - window_height) / 2, 0);

	// ウィンドウの生成
	g_hWnd = CreateWindow(
		CLASS_NAME,     // ウィンドウクラス
		WINDOW_CAPTION, // ウィンドウテキスト
		window_style,   // ウィンドウスタイル
		window_x,       // ウィンドウ座標x
		window_y,       // ウィンドウ座標y
		window_width,   // ウィンドウの幅
		window_height,  // ウィンドウの高さ
		NULL,           // 親ウィンドウハンドル
		NULL,           // メニューハンドル
		hInstance,      // インスタンスハンドル
		NULL            // 追加のアプリケーションデータ
		);

	if (g_hWnd == NULL) {
		// ウィンドウハンドルが何らかの理由で生成出来なかった
		return -1;
	}

	// 指定のウィンドウハンドルのウィンドウを指定の方法で表示
	ShowWindow(g_hWnd, nCmdShow);
	UpdateWindow(g_hWnd);

	// ゲームの初期化
	Initialize(hInstance);

	// Windowsゲーム用メインループ
	MSG msg = {}; // msg.message == WM_NULL
	while (WM_QUIT != msg.message) {

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			// メッセージがある場合はメッセージ処理を優先
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			// ゲームの更新
			Update();
			// ゲームの描画
			Draw();
		}
	}

	// ゲームの終了処理
	Finalize();

	return (int)msg.wParam;
}

// ウィンドウプロシージャ(コールバック関数)
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE) {
			SendMessage(hWnd, WM_CLOSE, 0, 0); // WM_CLOSEメッセージの送信
		}
		break;

	case WM_CLOSE:
//		if (MessageBox(hWnd, "本当に終了してよろしいですか？", "確認", MB_OKCANCEL | MB_DEFBUTTON2) == IDOK) {
			DestroyWindow(hWnd); // 指定のウィンドウにWM_DESTROYメッセージを送る
//		}
		return 0; // DefWindowProc関数にメッセージを流さず終了することによって何もなかったことにする

	case WM_DESTROY: // ウィンドウの破棄メッセージ
		PostQuitMessage(0); // WM_QUITメッセージの送信
		return 0;
	};

	// 通常メッセージ処理はこの関数に任せる
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

bool Initialize(HINSTANCE hInst)
{
	//シードの初期化
	srand((unsigned int)time(NULL));

	// ゲームの初期化(Direct3Dの初期化)
	if (!D3D_Initialize(g_hWnd)){
		// ゲームの初期化に失敗した
		return false;
	}
	// DirectInputの初期化（キーボード）
	if (!Keyboard_Initialize(hInst, g_hWnd)){
		return false;
	}
	// DirectInputの初期化（ゲームパッド）
	if (!GamePad_Initialize(hInst, g_hWnd)){
		return false;
	}

	//全テクスチャファイルのロード
	Texture_Load();

	InitSound(g_hWnd);
	Fade_Initialize();
	Scene_Initialize(SCENE_INDEX_TITLE);

	return true;
}

void Finalize(void)
{
	// テクスチャの解放
	Texture_Release();

	// サウンドの終了処理
	UninitSound();

	// DirectInputの終了処理
	GamePad_Finalize();

	// DirectInputの終了処理
	Keyboard_Finalize();

	// ゲームの終了処理(Direct3Dの終了処理)
	D3D_Finalize();
}

// ゲームの更新関数
void Update(void)
{
	//キーボードの状態を更新する
	Keyboard_Update();

	//キーボードの状態を更新する
	GamePad_Update();

	//シーンの更新
	Scene_Update();

	//フェードの更新
	Fade_Update();
}

// ゲームの描画関数
void Draw(void)
{
	LPDIRECT3DDEVICE9 pD3DDevice = GetD3DDevice();

	// 画面のクリア
	pD3DDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_RGBA(50, 50, 50, 255), 1.0f, 0);

	// 描画バッチ命令の開始
	pD3DDevice->BeginScene();


	// シーンの描画
	Scene_Draw();

	// フェードの描画
	Fade_Draw();


	// 描画バッチ命令の終了
	pD3DDevice->EndScene();

	// バックバッファをフリップ（タイミングはD3DPRESENT_PARAMETERSの設定による）
	pD3DDevice->Present(NULL, NULL, NULL, NULL);


	// シーンのチェック
	Scene_Check();
}

//ウィンドウハンドルのゲッター
HWND GetHWND(){
	return g_hWnd;
}


double frand() {
	return (double)rand() / RAND_MAX;
}
