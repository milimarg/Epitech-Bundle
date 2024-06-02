/*
** EPITECH PROJECT, 2024
** Epitech-Jam-Flamme
** File description:
** Input
*/

#include "Input.hpp"
#include "GameObject.hpp"

namespace plazza
{
    Input::Input(
        Vector2 position,
        Vector2 dimension,
        Color color,
        const std::string &authorizedChars,
        std::function<void(const std::string&)> onEnter,
        std::string &textReference,
        size_t maxSize,
        bool isFloat,
        std::function<void()> onFocus,
        std::function<void()> onUnfocus,
        const std::string &placeholderText,
        const std::string &textureName,
        const std::string &textureNameHover
    ) :
        GameObject2D(textureName, position),
        _color(color),
        _onEnter(onEnter),
        _textReference(textReference),
        _maxSize(maxSize),
        _authorizedChars(authorizedChars),
        _isFloat(isFloat),
        _onFocus(onFocus),
        _onUnfocus(onUnfocus),
        _placeholderText(placeholderText),
        _focused(false),
        _cursorPos(textReference.size()),
        _isActive(false),
        _hasTextureHover(false),
        _textureHover{},
        _cursorVisible(false),
        _cursorTimer(0.0f)
    {
        _baseRectangle = { position.x, position.y, dimension.x, dimension.y };
        _currentRectangle = _baseRectangle;

        if (!textureName.empty())
            _texture = RaylibWrapper::getInstance().loadTexture(textureName.c_str());
        if (!textureNameHover.empty()) {
            _textureHover = RaylibWrapper::getInstance().loadTexture(textureNameHover.c_str());
            _hasTextureHover = true;
        }
    }

    void Input::event()
    {
        checkClick();
        if (_isActive)
            handleInput();
    }

    void Input::render()
    {
        RaylibWrapper &r = RaylibWrapper::getInstance();

        r.drawRectangle(_currentRectangle, _color);

        if (_hasTextureHover && _isActive)
            r.drawTextureOnRectangle(_baseRectangle, _textureHover, WHITE);
        else if (!_hasTextureHover)
            r.drawTextureOnRectangle(_baseRectangle, _texture, WHITE);

        std::string displayText = _textReference.empty() ? _placeholderText : _textReference;
        r.drawText(displayText.c_str(), _baseRectangle.x + 10, _baseRectangle.y + 10, 20, BLACK);

        if (_isActive && _cursorVisible) {
            float cursorX = _baseRectangle.x + 12 + r.measureText(_textReference.substr(0, _cursorPos), 20);
            r.drawLine(cursorX, _baseRectangle.y + 8, cursorX, _baseRectangle.y + 28, BLACK);
        }
    }

    void Input::update(const float deltaTime)
    {
        _cursorTimer += deltaTime;
        if (_cursorTimer >= 0.5f) {
            _cursorTimer = 0.0f;
            _cursorVisible = !_cursorVisible;
        }
    }

    bool Input::isClicked()
    {
        RaylibWrapper &r = RaylibWrapper::getInstance();

        return r.checkCollisionPointRec(r.getMousePosition(), _baseRectangle) && r.isMouseButtonPressed(MOUSE_LEFT_BUTTON);
    }

    bool Input::isHover()
    {
        RaylibWrapper &r = RaylibWrapper::getInstance();

        return r.checkCollisionPointRec(r.getMousePosition(), _baseRectangle);
    }

    void Input::checkClick()
    {
        RaylibWrapper &r = RaylibWrapper::getInstance();

        if (isClicked()) {
            if (!_focused && _onFocus)
                _onFocus();
            _isActive = true;
            _focused = true;
        } else if (r.isMouseButtonPressed(MOUSE_LEFT_BUTTON) && !isHover()) {
            _isActive = false;
            _focused = false;
            if (_onUnfocus)
                _onUnfocus();
        }
    }

    void Input::handleInput()
    {
        RaylibWrapper &r = RaylibWrapper::getInstance();

        static float delayTimer = 0.0f;
        const float initialDelay = 0.8f;
        const float repeatDelay = 0.1f;

        int key = GetKeyPressed();
        if (key >= 32 && key <= 125) {
            char c = static_cast<char>(key);
            if (isCharAuthorized(c)) {
                if (_textReference.size() < _maxSize) {
                    _textReference.insert(_cursorPos, 1, c);
                    _cursorPos++;
                }
            }
        }

        delayTimer += r.getDeltaTime();
        if (r.isKeyDown(KEY_BACKSPACE) && delayTimer >= initialDelay) {
            if (!_textReference.empty() && _cursorPos > 0) {
                _textReference.erase(_cursorPos - 1, 1);
                _cursorPos--;
            }
            delayTimer = initialDelay - repeatDelay;
        }

        if (r.isKeyDown(KEY_LEFT) && delayTimer >= initialDelay) {
            if (_cursorPos > 0)
                _cursorPos--;
            delayTimer = initialDelay - repeatDelay;
        }

        if (r.isKeyDown(KEY_RIGHT) && delayTimer >= initialDelay) {
            if (_cursorPos < _textReference.size())
                _cursorPos++;
            delayTimer = initialDelay - repeatDelay;
        }

        if (r.isKeyPressed(KEY_ENTER)) {
            _onEnter(_textReference);
            _isActive = false;
        }
    }

    bool Input::isCharAuthorized(char c) const
    {
        if (_isFloat && c == '.' && _textReference.find('.') != std::string::npos)
            return false;

        if (_authorizedChars.empty())
            return true;

        return std::find(_authorizedChars.begin(), _authorizedChars.end(), c) != _authorizedChars.end();
    }

    bool Input::isNumberChar(char c) const
    {
        return (c >= '0' && c <= '9') || c == '.';
    }
}
