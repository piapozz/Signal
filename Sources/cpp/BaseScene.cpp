#include "../header/BaseScene.h"

// �R���X�g���N�^
BaseScene::BaseScene() 
{

}

// �f�X�g���N�^
BaseScene::~BaseScene() 
{

}

// �t�H���g�T�C�Y�����Z�b�g���Ȃ��當���̕`��
void DrawString(string text, int fontSize, Vector2 position)
{
	// �w�肳�ꂽ�t�H���g�T�C�Y�ɕύX
	SetFontSize(fontSize);
	// �ύX���ꂽ�t�H���g�T�C�Y�ŕ�����`��
	DrawFormatString(position.x, position.y, COLOR_WHITE, text.c_str());
	// �f�t�H���g�ɖ߂�
	SetFontSize(FONT_DEFAULT);
}