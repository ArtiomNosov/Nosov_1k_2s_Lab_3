#pragma once
#include "Stream.hpp"
#include <string>
#include "DynamicArray.hpp"

class StringStream : StreamReader<std::string>, StreamWriter<std::string>
{
private:
	char* bufer;
	int count;
public:
	StringStream(char* buffer, const int count) : buffer(buffer), count(count)
	{

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
	virtual bool Open() override = 0;
	virtula std::string Read() override = 0;
	virtual Sequence<std::string>* Read(int count) override = 0;
	virtual bool Seek(int position) override = 0;
	virtual Write(std::string item) override = 0;
	virtual void Write(Sequence<std::string>* items) override = 0;
	virtual void Close() override = 0;

};