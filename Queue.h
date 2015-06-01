#ifndef QUEUE_H
#define QUEUE_H

enum ErrorCode
{
	SUCCESS, OVERFLOW, UNDERFLOW
};


template<class EntryType, int maxLen>
class Queue
{
public:
	Queue ();
	Queue (const Queue &src);
	~Queue ();
	bool empty () const;
	bool full () const;
	int size () const;
	ErrorCode front (EntryType &item) const;
	ErrorCode push (const EntryType &item);
	ErrorCode pop ();
	ErrorCode clear ();
private:
	int count;
	int _front, _rear;
	EntryType entry[maxLen];
};

template<class EntryType, int maxLen>
Queue<EntryType, maxLen>::Queue ()
{
	count = 0;
	_front = maxLen - 1;
	_rear = maxLen - 1;
}

template<class EntryType, int maxLen>
Queue<EntryType, maxLen>::Queue (const Queue &src)
{
	count = src.count;
	_front = src._front;
	_rear = src._rear;
	for (int i = 0; i < maxLen; ++i)
		entry[i] = src.entry[i];
}

template<class EntryType, int maxLen>
Queue<EntryType, maxLen>::~Queue ()
{
}

template<class EntryType, int maxLen>
bool Queue<EntryType, maxLen>::empty () const
{
	return count <= 0;
}

template<class EntryType, int maxLen>
bool Queue<EntryType, maxLen>::full () const
{
	return count >= maxLen;
}

template<class EntryType, int maxLen>
int Queue<EntryType, maxLen>::size () const
{
	return count;
}

template<class EntryType, int maxLen>
ErrorCode Queue<EntryType, maxLen>::front (EntryType &item) const
{
	if (empty ())
		return UNDERFLOW;
	else {
		item = entry[_front];
		return SUCCESS;
	}
}

template<class EntryType, int maxLen>
ErrorCode Queue<EntryType, maxLen>::push (const EntryType &item)
{
	if (full ())
		return OVERFLOW;
	else {
		if (empty ())
			entry[_rear] = item;
		else {
			_rear = (_rear == 0) ? (maxLen - 1) : (_rear - 1);
			entry[_rear] = item;
		}
		++count;
		return SUCCESS;
	}
}

template<class EntryType, int maxLen>
ErrorCode Queue<EntryType, maxLen>::pop ()
{
	if (empty ())
		return UNDERFLOW;
	else {
		if (count == 1) {
		} else {
			--_front;
		}
		--count;
		return SUCCESS;
	}
}

template<class EntryType, int maxLen>
ErrorCode Queue<EntryType, maxLen>::clear ()
{
	count = 0;
	_front = _rear = maxLen - 1;
	return SUCCESS;
}

#endif