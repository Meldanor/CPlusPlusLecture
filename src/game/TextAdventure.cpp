/*
 * QuestionGame.cpp
 *
 *  Created on: 09.04.2013
 *      Author: Meldanor
 */

#include <iostream>
#include <cstdarg>
#include <stddef.h>
#include <list>
using namespace std;

class Tree {

public:
	Tree(const char*, bool);
	Tree(const char*, const char*, const char*, Tree*, bool);

	bool isLeave();

	void add(Tree*);

	const char* getStoryText(void);
	const char* getOptionText(void);
	const char* getActionText(void);

	list<Tree*>* getChilds(void);

	Tree* getRoot(void);

	bool isEnd(void);

private:
	list<Tree*> childs;
	Tree *root;
	const char *storyText;
	const char *optionText;
	const char *actionText;
	bool end;
};

// Beginning of the story node
Tree::Tree(const char* storyText, bool end = false) {
	this->storyText = storyText;
	this->optionText = NULL;
	this->actionText = NULL;
	this->end = end;
	this->root = NULL;
}

Tree::Tree(const char* storyText, const char* optionText,
		const char* actionText, Tree* root, bool end = false) {
	this->storyText = storyText;
	this->optionText = optionText;
	this->end = end;
	this->actionText = actionText;

	this->root = root;
	this->root->add(this);
}

bool Tree::isLeave() {
	return childs.empty();
}

void Tree::add(Tree *child) {
	child->root = this;
	childs.push_back(child);
}

Tree* Tree::getRoot() {
	return root;
}

const char* Tree::getStoryText() {
	return this->storyText;
}

const char* Tree::getOptionText() {
	return this->optionText;
}

const char* Tree::getActionText() {
	return this->actionText;
}

list<Tree*>* Tree::getChilds(void) {
	return &childs;
}

bool Tree::isEnd(void) {
	return this->end;
}

void printQuestion(const char* text) {
	cout << text << endl;
}

void printOptions(int n, const char* text[]) {
	for (int i = 0; i < n; ++i) {
		cout << '(' << (i + 1) << ')' << text[i] << "   ";
	}
	cout << endl;
}

int getOption() {
	int a;
	cin >> a;
	return a;
}

Tree story("");

void initGame() {
	Tree first("Sie gehen in einen Wald. Was nun?");

	{
		Tree *t = new Tree("Sie befinden sich im Norden.", "Nach Norden",
				"Gehe nach Norden...", &first);
		t = new Tree("Sie befinden sich im Osten.", "Nach Osten",
				"Gehe nach Osten...", &first);
		t = new Tree("Sie befinden sich im Sueden.", "Nach Sueden",
				"Gehe nach Sueden...", &first);
		t = new Tree("Sie befinden sich im Westen.", "Nach West",
				"Gehe nach Westen...", &first);
	}

	story = first;
}

void startGame() {

	Tree *current = &story;
	while (!current->isEnd()) {
		// Print out the beginning of the story
		cout << current->getStoryText() << endl;

		// Childs of the current node
		list<Tree*> *list = current->getChilds();
		if (list->size() == 0) {
			cout << "[Spiel vorbei]" << endl;
			break;
		}

		// optionindex
		int i = 1;
		// Current option
		Tree *option;
		// Iterate over childs of current node
		for (std::list<Tree*>::const_iterator iterator = list->begin(), end =
				list->end(); iterator != end; ++iterator, ++i) {
			option = *iterator;
			// Print node
			cout << '(' << (i) << ')' << option->getOptionText() << "   ";

		}
		cout << endl;

		int choose;
		cin >> choose;
		--choose;
		if (choose < 0 || choose >= list->size()) {
			cout << "Falsche Antwort!" << endl;
			continue;
		}
		std::list<Tree*>::const_iterator iterator =
				current->getChilds()->begin();
		while (choose != 0) {
			++iterator;
			--choose;
		}
		current = *iterator;
		cout << current->getActionText() << endl;
	}

}

