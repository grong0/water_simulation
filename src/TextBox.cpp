#include "../include/TextBox.h"
#include <cstring>

TextBox::TextBox(float x, float y, float width, float height, int fontSize, int maxLength) {
    box = { x, y, width, height };
    boxColor = LIGHTGRAY;
    textColor = BLACK;
    this->fontSize = fontSize;
    isActive = false;
    this->maxLength = maxLength;
    text = new char[maxLength + 1];
    text[0] = '\0';
}

void TextBox::Draw() {
    DrawRectangleRec(box, boxColor);

    if (isActive)
    {
        DrawText(text, (int)box.x + 5, (int)box.y + (int)(box.height / 2) - (fontSize / 2), fontSize, RED);
    }
    else
    {
        DrawText(text, (int)box.x + 5, (int)box.y + (int)(box.height / 2) - (fontSize / 2), fontSize, textColor);
    }
}

void TextBox::Update(char inputChar) {
    if (isActive) {
        int len = strlen(text);
        if (inputChar == '\b') { // Backspace
            if (len > 0) {
                text[len - 1] = '\0';
            }
        } else if (len < maxLength && inputChar >= 32 && inputChar <= 126) { // Printable characters
            text[len] = inputChar;
            text[len + 1] = '\0';
        }
    }

}

void TextBox::SetText(const char* newText){
    strncpy(text, newText, maxLength);
    text[maxLength] = '\0'; // Ensure null-termination
}


const char* TextBox::GetText() const {
    return text;
}

void TextBox::SetActive(bool active) {
    isActive = active;
}
