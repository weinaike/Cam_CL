// ssdic_sample.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです。
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// Cssdic_sampleApp:
// このクラスの実装については、ssdic_sample.cpp を参照してください。
//

class Cssdic_sampleApp : public CWinApp
{
public:
	Cssdic_sampleApp();

// オーバーライド
	public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern Cssdic_sampleApp theApp;