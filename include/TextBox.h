#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <raylib.h>

class TextBox {
private:
    Rectangle box;
    Color boxColor;
    Color textColor;
    int fontSize;
    bool isActive;
    char* text;
    int maxLength;
public:
    TextBox(float x, float y, float width, float height, int fontSize, int maxLength);
    void Draw();
    void SetText(const char* newText);
    void Update(char inputChar);
    const char* GetText() const;
    void SetActive(bool active);

    Rectangle GetBox() const { return box; }
};

#endif
