#pragma once
#include "Stream.h"
#include "KeyValuePair.h"

template <class T>
class PriorityQueueStream : StreamReader<T>, StreamWriter<T>
{
private:
	char* buffer;
public:
	virtual int GetPosition() const override = 0;
	virtual bool IsEof() const override = 0;
	virtual Optional<long>* GetLenght() const override = 0;
public:
	virtual bool Open()  override
	{
		if (buffer && count > 0)
		{
			this->currentPosition
		}
	}
	virtual T Read() override = 0;
	virtual Sequence<T>* Read(int count) override = 0;
	virtual bool Seek(int position) override = 0;
	virtual Close() override = 0;
public:
	virtual void Write(KeyValuePair<int, T> item) = 0;
	virtual void Write(Sequence<KeyValuePair<int, T>>* items) = 0;
public:
	virtual ~PriorityQueueStream() {}
};

