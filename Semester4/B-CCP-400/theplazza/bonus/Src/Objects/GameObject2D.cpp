/*
** EPITECH PROJECT, 2024
** Epitech-Jam-Flamme
** File description:
** GameObject2D
*/

#include "GameObject2D.hpp"

namespace plazza
{
    GameObject2D::GameObject2D(const std::string &textureName, const Vector2 position)
    : GameObject(), _position(position)
    {
        if (textureName != "") {
            _isTextured = true;
            _texture = RaylibWrapper::getInstance().loadTexture(textureName);
        }
    }

    void GameObject2D::setTexture(const std::string &textureName)
    {
        _texture = LoadTexture(textureName.c_str());
    }

    void GameObject2D::setPosition(const Vector2 &position)
    {
        _position = position;
    }

    const Vector2 GameObject2D::getPosition() const
    {
        return _position;
    }
}
