#pragma once
class LinkNode 
{
public:
	LinkNode(int data) : 
		Data(data), 
		mNext(nullptr) 
	{ }
	~LinkNode();

	int Data;
	LinkNode* mNext;
};

LinkNode::~LinkNode()
{
	if (nullptr != mNext)
	{
		delete mNext;
		mNext = nullptr;
	}
}

class LinkedList
{
public:
	LinkedList() : 
		mRoot(nullptr) 
	{  }
	~LinkedList();

	// sorted insert method
	void Insert(LinkNode* node);

	bool Remove(int data);

	LinkNode* mRoot;
};

LinkedList::~LinkedList()
{
	if (nullptr != mRoot) 
	{
		delete mRoot;
		mRoot = nullptr;
	}
}

// Takes a caller supplied node ptr and inserts to the list in order
void LinkedList::Insert(LinkNode* node)
{
	if (nullptr != node && nullptr == mRoot)
	{
		mRoot = node;
		mRoot->Data = node->Data;
		mRoot->mNext = nullptr;
	}

	if (nullptr != node && mRoot->Data != node->Data)
	{
		if (mRoot->Data > node->Data)
		{
			mRoot->mNext = node;
		}
		if (mRoot->Data < node->Data)
		{
			LinkNode* bufferNode = new LinkNode(node->Data);
			node->Data = mRoot->Data;
			node->mNext = mRoot;
			mRoot->Data = bufferNode->Data;
		}
	}
}

bool LinkedList::Remove(int data)
{
	return false;
}