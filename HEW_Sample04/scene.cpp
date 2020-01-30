#include "scene.h"
#include "title.h"
#include "scene_tutorial.h"
#include "scene_playerselect.h"
#include "game.h"
#include "result.h"
#include "worldrecord.h"
#include "worldrecord_2.h"


static SCENE_INDEX g_SceneIndex;
static SCENE_INDEX g_SceneNextIndex;

typedef void (*SceneFunc)(void);

static const SceneFunc Initialize[] = {
	Title_Initialize,
	Tutorial_Initialize,
	P_Select_Initialize,
	Game_Initialize,
	Result_Initialize,
	WorldRecord_Initialize,
	WorldRecord_2_Initialize,
};


void Scene_Initialize(SCENE_INDEX index)
{
	g_SceneNextIndex = g_SceneIndex = index;
	
	Initialize[g_SceneIndex]();
}

void Scene_Finalize(void)
{
	switch( g_SceneIndex ) {

	case SCENE_INDEX_TITLE:
		Title_Finalize();
		break;

	case SCENE_INDEX_TUTORIAL:
		Tutorial_Finalize();
		break;

	case SCENE_INDEX_P_SELECT:
		P_Select_Finalize();
		break;

	case SCENE_INDEX_GAME:
		Game_Finalize();
		break;

	case SCENE_INDEX_RESULT:
		Result_Finalize();
		break;
	
	case SCENE_INDEX_WORLDRECORD:
		WorldRecord_Finalize();
		break;

	case SCENE_INDEX_WORLDRECORD_2:
		WorldRecord_2_Finalize();
		break;
	}
}

void Scene_Update(void)
{
	switch( g_SceneIndex ) {

	case SCENE_INDEX_TITLE:
		Title_Update();
		break;
	
	case SCENE_INDEX_TUTORIAL:
		Tutorial_Update();
		break;

	case SCENE_INDEX_P_SELECT:
		P_Select_Update();
		break;

	case SCENE_INDEX_GAME:
		Game_Update();
		break;

	case SCENE_INDEX_RESULT:
		Result_Update();
		break;
	
	case SCENE_INDEX_WORLDRECORD:
		WorldRecord_Update();
		break;

	case SCENE_INDEX_WORLDRECORD_2:
		WorldRecord_2_Update();
		break;
	}
}

void Scene_Draw(void)
{
	switch( g_SceneIndex ) {

	case SCENE_INDEX_TITLE:
		Title_Draw();
		break;

	case SCENE_INDEX_TUTORIAL:
		Tutorial_Draw();
		break;

	case SCENE_INDEX_P_SELECT:
		P_Select_Draw();
		break;

	case SCENE_INDEX_GAME:
		Game_Draw();
		break;

	case SCENE_INDEX_RESULT:
		Result_Draw();
		break;
	
	case SCENE_INDEX_WORLDRECORD:
		WorldRecord_Draw();
		break;

	case SCENE_INDEX_WORLDRECORD_2:
		WorldRecord_2_Draw();
		break;
	}
}

void Scene_Check(void)
{
	if( g_SceneIndex != g_SceneNextIndex ) {
		Scene_Finalize();
		Scene_Initialize(g_SceneNextIndex);
	}
}

void Scene_Change(SCENE_INDEX index)
{
	g_SceneNextIndex = index;
}

