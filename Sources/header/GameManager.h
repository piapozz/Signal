#pragma once

// �Q�[���̐i�s�N���X
// 
// ��Ȗ���
// �@�v���C���[�̈ړ����͂��m�F			����
// �A�v���C���[�̈ړ��ɉ������G�̈ړ�	����
// �B�v���C���[�̍U�����͂��m�F			
// �C�v���C���[�̉����͂��m�F
// �D�G�l�~�[�̍U�������m�F
// �E�v���C���[�̉񕜓��͂��m�F
// �F���݂��̓����蔻����m�F
// �G(�������Ă�����_���[�W����)
// �H�Q�[���I�������m�F
// �I���W�X�V
// �J�`��
// 

class GameManager
{							
public:

	GameManager();												// �R���X�g���N�^
	~GameManager();												// �f�X�g���N�^

	void Init();												// ������
	void Proc();												// ����
	void Draw();												// �`��
};

