// ssdic_sample.h : PROJECT_NAME �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C���ł��B
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH �ɑ΂��Ă��̃t�@�C�����C���N���[�h����O�� 'stdafx.h' ���C���N���[�h���Ă�������"
#endif

#include "resource.h"		// ���C�� �V���{��


// Cssdic_sampleApp:
// ���̃N���X�̎����ɂ��ẮAssdic_sample.cpp ���Q�Ƃ��Ă��������B
//

class Cssdic_sampleApp : public CWinApp
{
public:
	Cssdic_sampleApp();

// �I�[�o�[���C�h
	public:
	virtual BOOL InitInstance();

// ����

	DECLARE_MESSAGE_MAP()
};

extern Cssdic_sampleApp theApp;