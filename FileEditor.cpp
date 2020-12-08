#include "FileEditor.h"

void FileEditor::_append(std::string data) {
    if (tail == head) {
        head->data = data;
        node *tmp = new node;
        head->next = tmp;
        tail = tmp;
    }
    else {
        tail->data = data;
        node *tmp = new node;
        tail->next = tmp;
        tail = tmp;
    }
}

void FileEditor::open(std::string fileName) {
    _fileName = fileName;
    std::fstream file;
    file.open(fileName.c_str(), std::ios::in);
    if (file.is_open()) {
        std::string line;
        while(getline(file, line)) {
            _append(line);
        }
        file.close();
    }
}

void FileEditor::removeFirst(std::string text) {
    node *pres;
    node *prev;
    pres = head;
    while (true) {
        if (pres->data == text) {
            prev->next = pres->next;
            break;
        }
        prev = pres;
        pres = pres->next;
        if (pres->next == NULL)
            break;
    }
}

void FileEditor::removeLast(std::string text) {
    int found = 0;
    node *pres;
    node *prev;
    node *last;
    pres = head;
    while (true) {
        if (pres->data == text) {
            last = prev;
            found = 1;
        }
        prev = pres;
        pres = pres->next;
        if (pres->next == NULL) {
            if (found == 1) {
                last->next = last->next->next;
            }
            break;
        }
    }
}

void FileEditor::removeAll(std::string text) {
    node *pres;
    node *prev;
    pres = head;
    while (true) {
        if (pres->data == text) {
            prev->next = pres->next;
        }
        prev = pres;
        pres = pres->next;
        if (pres->next == NULL)
            break;
    }
}

void FileEditor::replaceFirst(std::string text, std::string replace) {
    node *pres;
    pres = head;
    while (true) {
        if (pres->data == text) {
            pres->data = replace;
            break;
        }
        pres = pres->next;
        if (pres->next == NULL)
            break;
    }
}

void FileEditor::replaceLast(std::string text, std::string replace) {
    int found = 0;
    node *pres;
    node *last;
    pres = head;
    while (true) {
        if (pres->data == text) {
            last = pres;
            found = 1;
        }
        pres = pres->next;
        if (pres->next == NULL) {
            if (found == 1) {
                last->data = replace;
            }
            break;
        }
    }
}

void FileEditor::replaceAll(std::string text, std::string replace) {
    node *pres;
    pres = head;
    while (true) {
        if (pres->data == text) {
            pres->data = replace;
        }
        pres = pres->next;
        if (pres->next == NULL)
            break;
    }
}

void FileEditor::addToStart(std::string text) {
    node *tmp = new node;
    tmp->data = text;
    tmp->next = head;
    head = tmp;
}

void FileEditor::addToEnd(std::string text) {
    tail->data = text;
    node *tmp = new node;
    tail->next = tmp;
    tail = tmp;
}

FileEditor::~FileEditor() {
    node *del;
    node *tmp;
    tmp = head;
    while (true) {
        del = tmp;
        tmp = tmp->next;
        delete del;
        if (tmp->next == NULL) {
            delete tmp;
            break;
        }
    }
}

void FileEditor::close() {
    std::ofstream file;
    file.open(_fileName.c_str(), std::ios::out);
    if (!file.is_open())
        return;

    node *tmp;
    tmp = head;
    while (true) {
        file << tmp->data << std::endl;
        tmp = tmp->next;
        if (tmp->next == NULL)
            break;
    }
}
