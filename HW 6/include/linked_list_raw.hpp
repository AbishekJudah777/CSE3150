#include<iostream>

#pragma once

class LinkedListRaw 
{
	private:
		struct Node 
		{
			int value;
			Node* next;

			Node(int value) : value(value), next(nullptr) {}
		};
	
		Node* head_;
		Node* tail_;
	
	public:
		LinkedListRaw() : head_(nullptr), tail_(nullptr) {}

		~LinkedListRaw()
		{
			Node* current = head_;
			while(current != nullptr)
			{
				Node* next_node = current->next;
				delete current;
				current = next_node;
			}
		}

		LinkedListRaw(const LinkedListRaw&) = delete;
		LinkedListRaw& operator=(const LinkedListRaw&) = delete;
		
		void push_back(int value)
		{
			Node* newNode = new Node(value);

			if(!head_)
				head_ = tail_ = newNode;
			else
			{
				tail_->next = newNode;
				tail_ = newNode;
			}
		}

		void print(std::ostream& os) const
		{
			Node* current = head_;
			while(current)
			{
				os << current->value << (current->next ? "->" : "");
				current = current->next;
			}
			os << std::endl;
		}
};











