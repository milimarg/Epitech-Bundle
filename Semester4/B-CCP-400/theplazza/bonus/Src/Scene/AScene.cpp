/*
** EPITECH PROJECT, 2024
** Epitech-Jam-Flamme
** File description:
** AScene
*/

#include "AScene.hpp"

namespace plazza
{
    AScene::AScene()
    {}

    void AScene::addInput(
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
    )
    {
        std::unique_ptr<GameObject2D> input = std::make_unique<Input>(
            position,
            dimension,
            color,
            authorizedChars,
            onEnter,
            textReference,
            maxSize,
            isFloat,
            onFocus,
            onUnfocus,
            placeholderText,
            textureName,
            textureNameHover
        );

        _objects2D.push_back(std::move(input));
    }
}

bool operator==(const Vector2 &a, const Vector2 &b)
{
    return a.x == b.x && a.y == b.y;
}

bool operator==(const Vector3 &a, const Vector3 &b)
{
    return a.x == b.x && a.y == b.y && a.z == b.z;
}

bool operator!=(const Vector2 &a, const Vector2 &b)
{
    return !(a == b);
}

bool operator!=(const Vector3 &a, const Vector3 &b)
{
    return !(a == b);
}

Vector3 operator+(const Vector3 &a, const Vector3 &b)
{
    return Vector3(a.x + b.x, a.y + b.y, a.z + b.z);
}