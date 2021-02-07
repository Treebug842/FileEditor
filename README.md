# FileEditor
C++ Library to edit lines in a file. The file is opened in memory (in a linked list) and iterated over to edit the strings. The operations that can be done include:
```cpp
open(std::string)
removeFirst(std::string)
removeLast(std::string)
removeAll(std::string)
replaceFirst(std::string, std::string)
replaceLast(std::string, std::string)
replaceAll(std::string, std::string)
addToStart(std::string)
addToEnd(std::string)
close()
```

