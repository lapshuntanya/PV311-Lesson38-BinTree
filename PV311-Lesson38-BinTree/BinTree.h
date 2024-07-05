#pragma once
#include <iostream>
using std::cout;
using std::endl;

namespace BinTree {

	template <typename T>
	class Node {
	public:
		T info;
		Node* left;
		Node* right;

		Node(T value) { info = value; left = right = nullptr; }
		void showNode() {
			cout << "INFO: " << info << endl;
			cout << "\t Left: " << left << " Right: " << right << endl;
		}
	};

	template <typename U>
	class Tree {
		Node<U>* root;
	public:
		Tree() {
			root = nullptr;
		}
		~Tree() {

		}

		void insert(U value) {
			Node<U>* el = new Node<U>(value);

			if (root == nullptr) {
				root = el;
			}
			else {
				Node<U>* p = root;
				Node<U>* place = root;
				//Шукаємо місце для створеного вузла
				while (p != nullptr)
				{
					/*if (el->info < p->info)
						p = p->left;
					else
						p = p->right;*/

					place = p;
					p = (el->info < p->info) ? p->left : p->right;
				}

				//Привязка нового вузла
				if (el->info < place->info)
					place->left = el;
				else
					place->right = el;
			}
		}

		Node<U>* search(U value) {
			//Знайти адресу вузла з заданним значенням value
			//Якщо такого вузла немає, то повернути nullptr

			Node<U>* p = root;
			while (p != nullptr) {
				if (p->info == value) return p;

				p = (value < p->info) ? p->left : p->right;
			}
			return nullptr;
		}
	};

}