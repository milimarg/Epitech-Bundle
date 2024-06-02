/*
** EPITECH PROJECT, 2024
** Epitech-Jam-Flamme
** File description:
** Input
*/

#ifndef INPUT_HPP_
    #define INPUT_HPP_

    #include "GameObject2D.hpp"
    #include <functional>
    #include <string>
    #include <vector>

namespace plazza
{
    class Input : public GameObject2D {
        enum class ButtonState {
            None,
            Hover,
            Click,
            Released
        };

        public:
            Input(
                Vector2 position,
                Vector2 dimension,
                Color color,
                const std::string &authorizedChars,
                std::function<void(const std::string&)> onEnter,
                std::string &textReference,
                size_t maxSize,
                bool isFloat = false,
                std::function<void()> onFocus = nullptr,
                std::function<void()> onUnfocus = nullptr,
                const std::string &placeholderText = "",
                const std::string &textureName = "",
                const std::string &textureNameHover = ""
            );

            void event() override;
            void render() override;
            void update(const float deltaTime) override;

            bool isClicked();
            bool isHover();

            void checkClick();
            void handleInput();

        private:
            Color _color;
            ButtonState _status;
            std::function<void(const std::string&)> _onEnter;
            std::function<void()> _onFocus;
            std::function<void()> _onUnfocus;
            Rectangle _baseRectangle;
            Rectangle _currentRectangle;
            Texture2D _textureHover;
            bool _hasTextureHover;
            bool _isActive;
            std::string &_textReference;
            std::string _placeholderText;
            size_t _maxSize;
            std::string _authorizedChars;
            bool _isFloat;
            bool _focused;
            int _cursorPos;
            bool _cursorVisible;
            float _cursorTimer;

            bool isCharAuthorized(char c) const;
            bool isNumberChar(char c) const;
    };
}

#endif /* !INPUT_HPP_ */
