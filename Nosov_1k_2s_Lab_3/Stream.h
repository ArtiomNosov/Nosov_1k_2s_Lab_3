#pragma once
#include "Sequence"
#include "Optional.h"

template <class T>
class StreamReader
{

public:
	virtual int GetPosition() const = 0;
	virtual bool IsEof() const = 0;
	virtual Optional<long>* GetLenght() const = 0;
public:
	virtual bool Open() = 0;
	virtual T Read() = 0;
	virtual Sequence<T>* Read(int count) = 0;
	virtual bool Seek(int position) = 0;
	virtual Close() = 0;
public:
	virtual ~StreamReader(){}
};

template <class T>
class StreamWriter
{

public:
	virtual int GetPosition() const = 0;
	virtual bool IsEof() const = 0;
	virtual Optional<long>* GetLenght() const = 0;
public:
	virtual bool Open() = 0;
	virtual bool Seek(int position) = 0;
	virtual void Write(T item) = 0;
	virtual void Write(Sequence<T>* items) = 0;
	virtual Close() = 0;
public:
	virtual ~StreamWriter() {}
};