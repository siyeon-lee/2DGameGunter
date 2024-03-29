#pragma once
#include "syObject.h"
#include "syPlayer.h"
#include "syBitmapMgr.h"
#include "syScriptManager.h"
class sySprite : public syObject
{
public:
	syObjectInfo m_info;
	float		m_fDeltaTime;// = 3.0f / iNumSprite;
	bool		m_bDead;
	int			m_iSpriteID;
	int			m_iCurrentFrame;
	float       m_fTmpTime;
	bool		m_bSceneChange;

public:
	bool  Init();
	bool  Frame();
	bool  Render();
	bool  Release();

	void SetSpriteID(int spriteid)
	{
		m_iSpriteID = spriteid;
	};

	virtual bool  Set(syObjectInfo info, int bitmapid, int mask);
	void Set(syPoint pos, RECT rt, float fSpeed) 
	{
		m_info.m_pos = pos;
		syObject::Set(pos,rt,fSpeed);
		m_info.InitPos = pos;
		
	};
	virtual void  Draw(DWORD dwMode);
	void  Draw(int x, int y, DWORD dwMode);
	void  DrawCenter(DWORD dwMode);
	void  SetPos(float x, float y)
	{
		m_info.InitPos.x = x;
		m_info.InitPos.y = y;
		syObject::SetPos(x, y);
	}

	void  SetPos(syPoint pos)
	{
		m_info.InitPos.x = pos.x;
		m_info.InitPos.y = pos.y;
		syObject::SetPos(pos);
	}

	void  SetPos(POINT pos)
	{
		m_info.InitPos.x = pos.x;
		m_info.InitPos.y = pos.y;
		syObject::SetPos(pos);
	}
public:
	sySprite();
	virtual ~sySprite();
};

