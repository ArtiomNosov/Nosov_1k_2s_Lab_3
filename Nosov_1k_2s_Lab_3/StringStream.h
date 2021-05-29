 #pragma once
#include "Stream.hpp"
#include <string>
#include "DynamicArray.hpp"


class StringStream : StreamReader<std::string>, StreamWriter<std::string>
{
private:
	char* bufer;
	int count;
	int currentPosition;
public:
	StringStream(char* buffer, const int count) : buffer(buffer), count(count)
	{
		this->currentPosition = -1;
	}
public:
	virtual int GetPosition() const override = 0;
	virtual bool IsEof() const override = 0;
	virtual std::optional<long>* GetLenght() const override
	{
		throw new Exeption();
	}
	virtual bool IsReadOnly() const = 0;
public:
	virtual bool Open() override
	{
		if (buffer && count > 0) {
			this->currentPosition = -1;
			return true;
		}
		return false;
	}
	virtual std::string Read() override
	{
		int position = ;
		for (position = this->currentPosition; buffer[position] != '\n') position++)
			;
		char* tmp = new char[position - this->currentPosition + 1];
		memcpy(tmp, (void*)buffer[this->currentPosition], position - this->currentPosition + 1);
		std::string str(tmp);
	}
	virtual Sequence<std::string>* Read(int count) override = 0;
	virtual bool Seek(int position) override = 0;
	virtual Write(std::string item) override = 0;
	virtual void Write(Sequence<std::string>* items) override = 0;
	virtual void Close() override = 0;

};