#include "FileEditor.cpp"

int main() {
    FileEditor document;

    document.open("list.txt");
    document.replaceFirst("banquet", "country");
    document.replaceLast("flawed", "swallow");
    document.removeAll("miserable");
    document.addToEnd("rate");
    document.close();

    return 0;
}