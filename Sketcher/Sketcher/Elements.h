#pragma once

// CElement ÃüÁîÄ¿±ê

class CElement : public CObject
{
public:
	virtual ~CElement();
	virtual void Draw(CDC* pDC);
	CRect GetBoundRect() const;
protected:
	CElement();
	int m_PenWidth;
	COLORREF m_Color;
};

class CLine :
	public CElement
{
public:
	CLine(void);
	virtual ~CLine(void);
};

class CRectangle :
	public CElement
{
public:
	CRectangle(void);
	virtual ~CRectangle(void);
};

class CCircle :
	public CElement
{
public:
	CCircle(void);
	virtual ~CCircle(void);
};

class CCurve :
	public CElement
{
public:
	CCurve(void);
	virtual ~CCurve(void);
};


