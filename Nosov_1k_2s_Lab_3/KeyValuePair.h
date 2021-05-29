#pragma once

template <class TKey, class TValue>
class KeyValuePair
{
public:
	KeyValuePair(TKey key, TValue value) {}
public:
	TKey GetKey() const { throw new Exeption(); }
	TValue GetValue() const { throw new Exeption(); }
};