#ifndef FILEEDITOR_H
#define FILEEDITOR_H

#include <iostream>
#include <fstream>

struct node {
    std::string data;
    node *next;
};

class FileEditor {
private:
    node *head = new node;
    node *tail = head;
    void _append(std::string data);
    std::string _fileName;
public:
    void open(std::string fileName);
    void removeFirst(std::string text);
    void removeLast(std::string text);
    void removeAll(std::string text);
    void replaceFirst(std::string text, std::string replace);
    void replaceLast(std::string text, std::string replace);
    void replaceAll(std::string text, std::string replace);
    void addToStart(std::string text);
    void addToEnd(std::string text);
    void close();
    ~FileEditor();
};

#endif
