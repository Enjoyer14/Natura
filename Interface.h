#pragma once

class IDataProcessing
{
public:
	virtual void PrintInfo() = 0;
	virtual void AddInfo() = 0;
	virtual void ChangeInfo() = 0;

};