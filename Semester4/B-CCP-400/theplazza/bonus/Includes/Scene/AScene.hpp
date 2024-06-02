/*
** EPITECH PROJECT, 2024
** Epitech-Jam-Flamme
** File description:
** AScene
*/

#ifndef ASCENE_HPP_
    #define ASCENE_HPP_
    #include "IScene.hpp"
    #include <vector>
    #include "GameObject2D.hpp"
    #include "GameObject3D.hpp"
    #include "Input.hpp"

namespace plazza
{
    class AScene : public IScene {
        public:
            AScene();
            ~AScene() = default;

            void addButton(
                Vector2 position,
                Vector2 dimension,
                Color color,
                std::function<void()> onClick,
                const std::string &textureName = "",
                const std::string &textureNameHover = ""
            );

            void addInput(
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
                const std::string &textureName = "",
                const std::string &textureNameHover = ""
            );

        protected:
            std::vector<std::unique_ptr<GameObject2D>> _objects2D;
            std::vector<std::unique_ptr<GameObject3D>> _objects3D;
    };
}

bool operator==(const Vector2 &a, const Vector2 &b);
bool operator==(const Vector3 &a, const Vector3 &b);
bool operator!=(const Vector2 &a, const Vector2 &b);
bool operator!=(const Vector3 &a, const Vector3 &b);
Vector3 operator+(const Vector3 &a, const Vector3 &b);

#endif /* !ASCENE_HPP_ */
